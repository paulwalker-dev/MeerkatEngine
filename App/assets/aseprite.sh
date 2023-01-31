#!/bin/sh

alias aseprite="'${ASEPRITE}'"

aseprite -b --export-tileset tileset.aseprite --sheet-type horizontal --sheet tileset.png
aseprite -b logo.aseprite --scale 5 --save-as logo.png
