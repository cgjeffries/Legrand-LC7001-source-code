#!/bin/bash
# Zips the current working directory, omitting macOS metadata (.DS_Store,
# AppleDouble ._* forks, __MACOSX, Spotlight/Trash indexes).
#
# Usage: cleanArchive.sh [output.zip]
# Default output is ../<dirname>.zip, so the archive never lands inside itself.

set -euo pipefail

src="$PWD"
name="$(basename "$src")"

if [ "$src" = "/" ]; then
	echo "Refusing to archive /" >&2
	exit 1
fi

out="${1:-$(dirname "$src")/${name}.zip}"
mkdir -p "$(dirname "$out")"
out="$(cd "$(dirname "$out")" && pwd)/$(basename "$out")"

case "$out" in
"$src" | "$src"/*)
	echo "Refusing to write the archive inside the directory being archived:" >&2
	echo "  $out" >&2
	exit 1
	;;
esac

if [ -e "$out" ]; then
	echo "Output already exists: $out" >&2
	exit 1
fi

# -X drops uid/gid and extended attributes, which is what generates ._* entries.
zip -r -X -q "$out" . \
	-x '*.DS_Store' \
	'._*' '*/._*' \
	'__MACOSX/*' '*/__MACOSX/*' \
	'.Spotlight-V100/*' '*/.Spotlight-V100/*' \
	'.DocumentRevisions-V100/*' '*/.DocumentRevisions-V100/*' \
	'.TemporaryItems/*' '*/.TemporaryItems/*' \
	'.Trashes/*' '*/.Trashes/*' \
	'.fseventsd/*' '*/.fseventsd/*' \
	'.VolumeIcon.icns' '*/.VolumeIcon.icns' \
	'.apdisk' '*/.apdisk' \
	$'Icon\r' $'*/Icon\r'

leaked="$(unzip -Z1 "$out" | grep -E '(^|/)(\.DS_Store|\._|__MACOSX/|\.Spotlight-V100/|\.Trashes/|\.fseventsd/)' || true)"
if [ -n "$leaked" ]; then
	echo "macOS metadata survived the exclude patterns:" >&2
	printf '%s\n' "$leaked" >&2
	exit 1
fi

echo "Created $out ($(unzip -Z1 "$out" | wc -l | tr -d ' ') entries)"
