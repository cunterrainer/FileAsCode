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
    optimize "off"

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
    flags "FatalWarnings"

    filter { "toolset:gcc* or toolset:clang*" }
    enablewarnings {
        "pedantic",
        "cast-align",
        "cast-qual",
        "ctor-dtor-privacy",
        "disabled-optimization",
        "format=2",
        "init-self",
        "missing-declarations",
        "missing-include-dirs",
        "old-style-cast",
        "overloaded-virtual",
        "redundant-decls",
        "shadow",
        "sign-conversion",
        "sign-promo",
        --"strict-overflow=5",
        "switch-default",
        "undef",
        "uninitialized",
        "unreachable-code",
        "unused",
        "alloca",
        "conversion",
        "deprecated",
        "format-security",
        "null-dereference",
        "stack-protector",
        "vla",
        "shift-overflow"
    }

    filter "toolset:gcc*"
        warnings "Extra"
        externalwarnings "Off"
        linkgroups "on" -- activate position independent linking
        enablewarnings {
            "noexcept",
            "strict-null-sentinel",
            "array-bounds=2",
            "duplicated-branches",
            "duplicated-cond",
            "logical-op",
            "arith-conversion",
            "stringop-overflow=4",
            "implicit-fallthrough=3",
            "trampolines"
        }

    filter "toolset:clang*"
        warnings "Extra"
        externalwarnings "Everything"
        enablewarnings {
            "array-bounds",
            "long-long",
            "implicit-fallthrough", 
        }
    filter {}


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

    externalincludedirs {
        "utility/include",
        "vendor"
    }

    links {
        "utility"
    }