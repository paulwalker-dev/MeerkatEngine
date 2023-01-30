workspace "MeerkatEngine"
    configurations { "Debug", "Release", "Web" }
    location "build"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter "configurations:Web"
        defines { "NDEBUG", "WEB" }
        optimize "On"

function makeLib()
    kind "SharedLib"
    language "C"

    filter "configurations:Web"
        kind "StaticLib"

    filter "*"
end

function useSDL2()
    links { "SDL2", "SDL2_image" }

    filter "configurations:Web"
    	removelinks { "SDL2_image" }
        buildoptions {
            "-sUSE_SDL=2",
            "-sUSE_SDL_IMAGE=2",
            "-sSDL2_IMAGE_FORMATS='[\"qoi\"]'"
        }

    filter "*"
end

project "EngineCore"
    makeLib()

    files {
        "Core/**.c",
        "Core/**.h"
    }

    function useEngineCore()
        includedirs "Core/includes"
        links "EngineCore"
    end

project "EngineMantle"
    makeLib()

    files {
        "Mantle/**.c",
        "Mantle/**.h"
    }

    useEngineCore()

    function useEngineMantle()
        includedirs "Mantle/includes"
        links "EngineMantle"
    end

project "EngineGraphics"
    makeLib()

    files {
        "Graphics/**.c",
        "Graphics/**.h"
    }

    useEngineCore()
    useEngineMantle()
    useSDL2()

    function useEngineGraphics()
        includedirs "Graphics/includes"
        links "EngineGraphics"
        useSDL2()
    end

project "EngineApp"
    kind "ConsoleApp"
    language "C"

    files {
        "App/**.c",
        "App/**.h"
    }

    useEngineCore()
    useEngineMantle()
    useEngineGraphics()

    prelinkcommands {
        "../App/assets/convert.sh %{cfg.objdir}/png %{cfg.objdir}"
    }

    filter "configurations:Web"
        targetsuffix ".html"
        linkoptions {
            "--use-preload-plugins",
            "--embed-file", "%{cfg.objdir}/assets@/"
        }
