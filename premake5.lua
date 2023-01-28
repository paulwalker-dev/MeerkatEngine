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
        defines { "NDEBUG" }
        optimize "On"

function makeLib()
    kind "SharedLib"
    language "C"

    filter "configurations:Web"
        kind "StaticLib"

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

project "EngineApp"
    kind "ConsoleApp"
    language "C"

    files {
        "App/**.c",
        "App/**.h"
    }

    useEngineCore()
    useEngineMantle()

    filter "configurations:Web"
        targetsuffix ".html"
        linkoptions { "-sWASM=0" }
