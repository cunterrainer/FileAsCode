workspace "Image2CArray"
    platforms { "x64", "x86" }
    configurations {
        "Debug",
        "Release"
    }
    startproject "Utilities"

cwd = os.getcwd()
outputdir = "/BIN/%{cfg.buildcfg}/%{cfg.architecture}/"
targetdir(cwd .. outputdir .. "%{prj.name}/bin")
-- get current working directory
objdir(cwd .. outputdir .. "%{prj.name}/bin-int")

include "utility"
project "im2c"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    files {
        "**.cpp",
        "**.h"
    }

    removefiles {
        "utility/**"
    }

    includedirs {
        "utility/include",
        "vendor"
    }

    links {
        "utility"
    }

    filter { "configurations:Debug" }
        runtime "Debug"
        symbols "on"

    filter { "configurations:Release" }
        runtime "Release"
        optimize "Full"
