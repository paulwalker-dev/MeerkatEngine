import { ensureDir } from "https://deno.land/std@0.175.0/fs/mod.ts"
import {
    basename,
    dirname,
    extname,
} from "https://deno.land/std@0.175.0/path/mod.ts"
import { decode, GIF } from "https://deno.land/x/imagescript@1.2.15/mod.ts"
import { Command } from "https://deno.land/x/cliffy@v0.25.7/command/mod.ts"

await new Command()
    .name("tileset2assets")
    .description(
        "MeerkatEngine internal tool:\nConverts one large tileset image to multiple different files"
    )
    .option(
        "-m, --map <path:string>",
        "JSON file for setting names on tiles via index"
    )
    .arguments("<tileset:file> [output:file]")
    .action(async ({ map: mapfile }, tileset: string, output?: string) => {
        if (!output)
            output = `${dirname(tileset)}/${basename(
                tileset,
                extname(tileset)
            )}`
        await ensureDir(output)

        const image = await decode(Deno.readFileSync(tileset))
        if (image instanceof GIF) {
            console.log("Input is a GIF")
            Deno.exit(1)
        }

        const w = image.width
        const h = image.height
        let tilemap

        if (mapfile) {
            const decoder = new TextDecoder("utf-8")
            const mapdata = Deno.readFileSync(mapfile)
            const map = decoder.decode(mapdata)
            tilemap = JSON.parse(map)
        }

        for (let i = 0; i < w / h; i++) {
            const tile = await image
                .clone()
                .crop(h * i, 0, h, h)
                .encode(3)

            const tilename: string = tilemap ? tilemap[i] : `${i}`
            Deno.writeFileSync(`${output}/${tilename}.png`, tile)
        }
    })
    .parse(Deno.args)
