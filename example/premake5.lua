include "deps/spdlog.lua"
include "deps/stb_image.lua"
include "deps/libCurl.lua"
include "deps/json.lua"

project "example"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++14"
	
	files { "src/**.h", "src/**.cpp"}
	
	includedirs 
	{
		"include/",
		"src/",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.bahamutGUI}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.YogaLayout}",
		"%{IncludeDir.LibEvent}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb}",
		"%{IncludeDir.json}",
		"%{IncludeDir.libCurl}"
	}
	
	links
	{
		"bahamutGUI",
		"YogaLayout",
		"spdlog"
	}

  	filter "system:linux"
    	links { "Glad", "GLFW", "pthread", "m", "dl" }
	
    filter "system:macosx"
		sysincludedirs 
		{
			"./include",
			"./src/",
			"%{IncludeDir.spdlog}",
			"%{IncludeDir.bahamutGUI}",
			"%{IncludeDir.Glad}",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.YogaLayout}",
			"%{IncludeDir.LibEvent}",
			"%{IncludeDir.glm}",
			"%{IncludeDir.stb}",
			"%{IncludeDir.json}",
			"%{IncludeDir.libCurl}"
		}

		links {
			"Cocoa.framework",
			"IOKit.framework",
			"CoreFoundation.framework"
		}

	-- code coverage (gcc only)
	filter { "system:linux", "options:code-coverage", "configurations:Debug" }
		buildoptions { 
			"-ftest-coverage",
    		"-fprofile-arcs",
    		"-fprofile-abs-path" 
    	}

    	links {
    		"gcov"
    	}

	filter "configurations:Debug"
		defines { "APP_DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "APP_NDEBUG" }
		optimize "On"
