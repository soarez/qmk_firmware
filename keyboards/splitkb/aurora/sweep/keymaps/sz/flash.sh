#!/usr/bin/env bash
# Build and flash both halves: ./flash.sh
#
# Both halves take the same firmware (each reads its side from a pin), so the
# order does not matter. Flashes with dfu-programmer directly: QMK's own
# :dfu target can stall waiting for a board that is already in DFU mode.

set -euo pipefail
here="$(cd "$(dirname "$0")" && pwd)"
"${here}/build.sh"
source "${here}/setup.sh"
hex="${qmk_home}/.build/splitkb_aurora_sweep_rev1_sz.hex"

in_dfu() {
    dfu-programmer atmega32u4 get bootloader-version > /dev/null 2>&1
}

for half in first second; do
    echo "==> Plug the USB cable into the ${half} half and press its reset button once ..."
    until in_dfu; do sleep 0.5; done
    dfu-programmer atmega32u4 erase
    dfu-programmer atmega32u4 flash "$hex"
    dfu-programmer atmega32u4 reset || true
    while in_dfu; do sleep 0.5; done
    echo "==> Flashed the ${half} half."
done
