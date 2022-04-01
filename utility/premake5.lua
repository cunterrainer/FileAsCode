project "utility"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    files {
        "**.cpp",
        "**.h"
    }

    includedirs {
        "include/utility",
        "include/utility/Vector"
    }

    defines "UTIL_USE_CPP_17"

    filter { "configurations:Debug" }
        runtime "Debug"
        symbols "on"

    filter { "configurations:Release" }
        runtime "Release"
        optimize "Full"