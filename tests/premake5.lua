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
		"%{IncludeDir.YogaLayout}",
		"%{IncludeDir.LibEvent}",
		"%{IncludeDir.glm}"
	}
	
	-- if we're not trying to do code coverage, then straight up link it.
	-- else, see code coverage below
	filter "system:not linux or configurations:not Debug or options:not code-coverage"
		links {
			"BahamutGUI"
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
			"%{IncludeDir.YogaLayout}",
			"%{IncludeDir.LibEvent}",
			"%{IncludeDir.glm}"
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

		-- link bahamutGUI the fun way
		linkoptions {
			"-Wl,--whole-archive %{cfg.targetdir}/../bahamutGUI/libbahamutGUI.a -Wl,--no-whole-archive"
		}

	filter "configurations:Debug"
		defines { "TESTS_DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "TESTS_NDEBUG" }
		optimize "On"
