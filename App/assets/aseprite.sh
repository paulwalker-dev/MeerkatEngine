#!/bin/sh
find . -iname '*.aseprite' |
    while read asset; do
        aseprite -b ${asset} --save-as ${asset%.aseprite}.png
    done
