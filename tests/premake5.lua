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
	
  filter {"system:not linux", "configurations:not Debug"}
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

  filter {"configurations:Debug", "system:linux"}
		linkoptions { 
      "-Wl,--whole-archive %{cfg.targetdir}/../bahamutGUI/libbahamutGUI.a -Wl,--no-whole-archive" 
    } -- required for gcov
		buildoptions { 
      "-ftest-coverage",
      "-fprofile-arcs",
      "-fprofile-abs-path" 
    }

    links {
      "gcov"
    }

	filter "configurations:Debug"
		defines { "TESTS_DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "TESTS_NDEBUG" }
		optimize "On"
