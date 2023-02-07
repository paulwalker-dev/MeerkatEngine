workspace "MeerkatEngine"
    configurations { "Debug", "Release" }
    location "build"

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

newoption {
    trigger = "install",
    description = "Install MeerkatEngine",
}

function useSDL2()
    filter "system:Windows"
        linkoptions {
            "-lmingw32", "-lSDL2main"
        }

    filter "*"
        linkoptions {
            "-lSDL2", "-lSDL2_image", "-lm"
        }
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

project "EnginePhysics"
    kind "SharedLib"
    language "C"

    files {
        "Physics/**.c",
        "Physics/**.h"
    }

    useEngineCore()
    useEngineMantle()

    function useEnginePhysics()
        includedirs "Physics/includes"
        links "EnginePhysics"
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
    useEnginePhysics()
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
    useEnginePhysics()
    useEngineGraphics()

    prelinkcommands {
        "../App/assets/convert.sh %{cfg.objdir} %{cfg.buildtarget.directory}"
    }

    filter "options:install"
        postbuildcommands {
            "{MKDIR} $(PREFIX)/bin",
            "{MKDIR} $(PREFIX)/share",
            "{RMDIR} $(PREFIX)/share/MeerkatEngine",
            "{COPYDIR} %{cfg.buildtarget.directory} $(PREFIX)/share/MeerkatEngine",
            "{DELETE} $(PREFIX)/bin/MeerkatEngine",
            "{COPYFILE} ../App/script/MeerkatEngine $(PREFIX)/bin/MeerkatEngine",
        }

    filter "system:Windows"
        linkoptions {
            "-mwindows"
        }
