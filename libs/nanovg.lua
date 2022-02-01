addPackage("gh:memononen/nanovg")

-- include("nanovg/premake4.lua") Faulty build, broke full solution
project "nanovg"
	language "C"
	kind "StaticLib"
	includedirs { "nanovg/src" }
	files { "nanovg/src/*.c" }

	IncludeDir["NanoVG"] = "%{wks.location}/libs/nanovg/src"
	
	defines { "_CRT_SECURE_NO_WARNINGS" } --,"FONS_USE_FREETYPE" } Uncomment to compile with FreeType support

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "on"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "on"