include "deps/spdlog.lua"

project "example"
	kind "ConsoleApp"
	language "C++"
	
	files { "src/**.h", "src/**.cpp"}
	
	includedirs 
	{
		"include/",
		"src/",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.bahamutGUI}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLFW}"
	}
	
	links
	{
		"bahamutGUI",
		"spdlog"
	}
	
	filter "configurations:Debug"
		defines { "APP_DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "APP_NDEBUG" }
		optimize "On"