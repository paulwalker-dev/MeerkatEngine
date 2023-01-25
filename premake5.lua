workspace "MeerkatEngine"
    configurations { "Debug", "Release", "Testing" }
    location "build"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

project "EngineCore"
    kind "SharedLib"
    language "C"

    files {
        "Core/**.c", "Core/**.h"
    }

    function useEngineCore()
        includedirs "Core/includes"
        links "EngineCore"
    end

project "EngineApp"
    kind "ConsoleApp"
    language "C"

    files {
        "App/**.c", "App/**.h"
    }

    useEngineCore()
