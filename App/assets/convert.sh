#!/bin/sh
mkdir -p "$1"/assets
find "$(dirname $0)" -iname '*.png' |
    while read asset; do
        convert ${asset} "$1"/assets/$(basename ${asset} .png).qoi
    done
