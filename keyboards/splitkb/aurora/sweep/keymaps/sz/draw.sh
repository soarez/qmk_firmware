#!/usr/bin/env bash
# Draw the keymap to keymap-drawer/sweep.svg, like gil's draw.sh

set -euo pipefail
source "$(cd "$(dirname "$0")" && pwd)/setup.sh"
drawer_dir="${keymap_dir}/keymap-drawer"
json="$(mktemp -t sweep-keymap).json"
trap 'rm -f "$json"' EXIT

layer_names=(Base Symbols Brackets Navigation Numbers Keypad Macros Media System)

echo "==> qmk c2json"
(cd "$qmk_home" && qmk c2json -q -kb splitkb/aurora/sweep/rev1 -km sz "${keymap_dir}/keymap.c" -o "$json")

echo "==> keymap-drawer: parse"
uvx --from keymap-drawer keymap -c "${drawer_dir}/config.yaml" \
  parse -q "$json" -l "${layer_names[@]}" \
  > "${drawer_dir}/sweep.yaml"

# Draw on the same 34-key split grid as gil. The right outer thumb (L4_F20)
# holds Numbers, but keymap-drawer only spots MO/LT as layer keys: mark it
# held on Numbers and on Macros (Numbers + the right inner thumb)
python3 - "${drawer_dir}/sweep.yaml" <<'PY'
import re, sys
path = sys.argv[1]
lines, layer, index = open(path).read().splitlines(), None, 0
for i, line in enumerate(lines):
    if line.startswith('layout:'):
        lines[i] = 'layout: {ortho_layout: {split: true, rows: 3, columns: 5, thumbs: 2}}'
    elif m := re.fullmatch(r'  (\S.*):', line):
        layer, index = m.group(1), 0
    elif line.startswith('  - '):
        if layer in ('Numbers', 'Macros') and index == 33:
            lines[i] = "  - {type: held}"
        index += 1
open(path, 'w').write('\n'.join(lines) + '\n')
PY

echo "==> keymap-drawer: draw"
uvx --from keymap-drawer keymap -c "${drawer_dir}/config.yaml" \
  draw "${drawer_dir}/sweep.yaml" \
  > "${drawer_dir}/sweep.svg"
