workspace "MeerkatEngine"
    configurations { "Debug", "Release" }
    location "build"

    buildoptions { "-ansi" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

function useSDL2()
    buildoptions {
        "$(shell sdl2-config --cflags)"
    }
    links { "SDL2", "SDL2_image", "m" }
end

project "EngineCore"
    kind "SharedLib"
    language "C"

    files {
        "Core/**.c",
        "Core/**.h"
    }

    function useEngineCore()
        includedirs "Core/includes"
        links "EngineCore"
    end

project "EngineMantle"
    kind "SharedLib"
    language "C"

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
    kind "SharedLib"
    language "C"

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
        "../App/assets/convert.sh %{cfg.buildtarget.directory}"
    }
