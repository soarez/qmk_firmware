# Sourced by build.sh and flash.sh. Puts the AVR toolchain on PATH and
# activates a Python environment with what this QMK checkout's build needs,
# installing whatever is missing the first time.

keymap_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
qmk_home="$(git -C "$keymap_dir" rev-parse --show-toplevel)"

brew_ensure() {
    brew list --formula "$1" > /dev/null 2>&1 || brew install "$1"
}

brew_ensure osx-cross/avr/avr-gcc@8
brew_ensure dfu-programmer
export PATH="$(brew --prefix avr-gcc@8)/bin:${PATH}"

# avr-gcc@8 links against libraries that Homebrew can remove as unused
if ! echo 'int main(void) { return 0; }' | avr-gcc -x c -c -o /dev/null - 2> /dev/null; then
    brew install gmp isl libmpc mpfr
fi

# The QMK CLI from Homebrew lacks this (2022) checkout's Python dependencies
venv="${keymap_dir}/.venv"
if [[ ! -x "${venv}/bin/qmk" ]]; then
    command -v uv > /dev/null || { >&2 echo "ERROR: uv is needed to create ${venv}"; exit 1; }
    uv venv -q -p 3.11 "$venv"
    uv pip install -q -p "${venv}/bin/python" qmk -r "${qmk_home}/requirements.txt"
fi
export PATH="${venv}/bin:${PATH}"

# Submodules an AVR build needs
for module in lib/lufa lib/printf; do
    if [[ -z "$(ls -A "${qmk_home}/${module}" 2> /dev/null)" ]]; then
        git -C "$qmk_home" submodule update --init "$module"
    fi
done
