project "tests"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++14"
	
	files { 
		"**.hpp", 
		"**.cpp"
	}
	
	includedirs 
	{
		"include/",
		"src/",
		"%{IncludeDir.bahamutGUI}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.YogaLayout}"
	}
	
	links
	{
		"bahamutGUI"
	}

  	filter "system:linux"
    	links { "Glad", "GLFW", "pthread", "m", "dl" }
	
	filter "system:macosx"
		sysincludedirs 
		{
			"./include",
			"./src/",
			"%{IncludeDir.bahamutGUI}",
			"%{IncludeDir.Glad}",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.YogaLayout}"
		}

		links {
			"Cocoa.framework",
			"IOKit.framework",
			"CoreFoundation.framework"
		}

	filter "system:linux"
		links {
			"YogaLayout"
		}

		linkoptions { "--whole-archive --coverage" } -- required for gcov
		buildoptions { "--coverage" }

	filter "configurations:Debug"
		defines { "TESTS_DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "TESTS_NDEBUG" }
		optimize "On"
