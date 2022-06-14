workspace "Image2CArray"
    platforms { "x64", "x86" }
    configurations {
        "Debug",
        "Release"
    }
    startproject "im2c"

cwd = os.getcwd()
outputdir = "/BIN/%{cfg.buildcfg}/%{cfg.architecture}/"
targetdir(cwd .. outputdir .. "%{prj.name}/bin")
-- get current working directory
objdir(cwd .. outputdir .. "%{prj.name}/bin-int")

filter { "configurations:Debug" }
    runtime "Debug"
    symbols "on"

filter { "configurations:Release" }
    runtime "Release"
    symbols "off"
    optimize "Full"
filter {}
staticruntime "on"

include "utility"
project "im2c"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

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