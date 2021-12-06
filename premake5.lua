-- initial includes 
include "premake_scripts/dep_downloader"

workspace "BahamutGUI"
	configurations { "Debug", "Release" }
	filter "system:windows"
		platforms { "x86", "x86_64" }
		
	filter "system:linux or macosx"
		platforms { "x86", "x86_64", "arm", "arm64" }
	
	filter {}
	
	targetdir "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
	objdir "%{wks.location}/bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
	
	startproject "example"

	-- options
	filter "system:linux"
		newoption {   
			trigger = "code-coverage",   
			description = "Build the project with code coverage (linux w/ gcc only)"
		}
	
	filter "platforms:x86"
		architecture "x86"
		
	filter "platforms:x86_64"
		architecture "x86_64"
	
	filter "platforms:arm"
		architecture "ARM"
	
	filter "platforms:ARM64"
		architecture "ARM64"

group ""
IncludeDir = {}
include "libs/glad"
include "libs/GLFW.lua"
include "libs/YogaLayout.lua"

IncludeDir["bahamutGUI"] = "%{wks.location}/include/"

-- compiled library (named after dnd gold dragon guy)
project "bahamutGUI"
	kind "StaticLib"
	language "C++"
	cppdialect "C++14"
	
	files {
		"src/**.cpp",
		"src/**.h",
		"include/**.h"
	}
	
	includedirs {
		"include/",
		"src/",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.YogaLayout}"
	}
	
	links {
		"GLFW",
		"Glad",
		"YogaLayout"
	}
	
	filter "system:windows"
		systemversion "latest"
		links { "opengl32.lib" }

	filter "system:macosx"
		sysincludedirs {
			"./include/",
			"./src/",
			"./%{IncludeDir.Glad}",
			"./%{IncludeDir.GLFW}",
			"./%{IncludeDir.YogaLayout}"
		}

	-- code coverage
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
		defines { "LIB_DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "LIB_NDEBUG" }
		optimize "On"

include "example"
include "tests"

--[[project "LauncherApp"
	kind "ConsoleApp"
	language "C++"
	
	files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
	
	includedirs 
	{
		"%{prj.name}/include",
		"%{prj.name}/src",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.spdlog}"
	}
	
	links
	{
		"GLFW",
		"Glad",
		"spdlog"
	}
	
	defines 
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	filter "system:windows"
		systemversion "latest"
		links { "opengl32.lib" }
	
	filter "configurations:Debug"
		defines { "APP_DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "APP_NDEBUG" }
		optimize "On"]]--