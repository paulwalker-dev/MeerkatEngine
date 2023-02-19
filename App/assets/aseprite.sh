#!/bin/sh

cd "$(dirname "$0")"

find . -iname '*.png' |
    while read asset; do
        rm "${asset}"
    done

find . -iname '*.aseprite' |
    while read asset; do
        aseprite -b "${asset}" --save-as "${asset%.aseprite}".png
    done
