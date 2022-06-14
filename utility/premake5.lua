project "utility"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    
    defines "UTIL_USE_CPP_17"

    files {
        "**.cpp",
        "**.h"
    }

    includedirs {
        "include/utility",
        "include/utility/Vector"
    }
