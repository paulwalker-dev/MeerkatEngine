#!/bin/sh

ASSETS="$(dirname $0)"
OBJ_DIR="$1"
BIN_DIR="$2"

rm -rf "${OBJ_DIR}"/assets
deno run --allow-net=deno.land \
    --allow-read --allow-write \
    "${ASSETS}"/tileset2assets.ts \
    -m "${ASSETS}"/tileset.json \
    "${ASSETS}"/tileset.png \
    "${OBJ_DIR}"/assets

mkdir -p ${BIN_DIR}/assets
for i in "${OBJ_DIR}"/assets/*.png; do
	convert $i "${BIN_DIR}"/assets/"$(basename $i .png)".qoi
done
