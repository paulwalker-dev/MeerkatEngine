project "SDL2_image"
    kind "Makefile"

    location "../build"

    buildcommands {
        "mkdir -p %{cfg.objdir}",
        "cd %{cfg.objdir} && ../../../../libs/SDL2_image/configure",
        "make -C %{cfg.objdir}",
        "mkdir -p %{cfg.buildtarget.directory}",
        "cp %{cfg.objdir}/libSDL2_image.la %{cfg.buildtarget.directory}"
    }
