#!/bin/sh
mkdir -p "$1"/assets
find "$(dirname $0)" -iname '*.png' |
    while read asset; do
        out=$(echo "$asset" | sed "s/$(dirname "$0" | sed 's/\//\\\//g')\///g")
        mkdir -p "$1"/assets/"$(dirname "$out")"
        convert "${asset}" "$1"/assets/"${out%.png}".qoi
    done
