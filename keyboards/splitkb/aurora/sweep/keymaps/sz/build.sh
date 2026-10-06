#!/usr/bin/env bash
# Build the firmware: ./build.sh (extra arguments go to make)

set -euo pipefail
source "$(cd "$(dirname "$0")" && pwd)/setup.sh"

cd "$qmk_home"
make splitkb/aurora/sweep/rev1:sz SKIP_GIT=yes "$@"
echo "Firmware: ${qmk_home}/.build/splitkb_aurora_sweep_rev1_sz.hex"
