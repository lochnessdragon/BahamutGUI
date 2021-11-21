-- initial includes 
include "premake_scripts/dep_downloader"

workspace "Launcher"
	configurations { "Debug", "Release" }
	filter "system:windows"
		platforms { "x86", "x86_64" }
		
	filter "system:linux or macosx"
		platforms { "x86", "x86_64", "arm", "arm64" }
	
	filter {}
	
	targetdir "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
	objdir "%{wks.location}/bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
	
	startproject "example"
	
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

IncludeDir["bahamutGUI"] = "%{wks.location}/include/"

-- compiled library (named after dnd gold dragon guy)
project "bahamutGUI"
	kind "StaticLib"
	language "C++"
	
	files {
		"src/**.cpp",
		"src/**.h",
		"include/**.h"
	}
	
	includedirs {
		"include/",
		"src/",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLFW}"
	}
	
	links {
		"GLFW",
		"Glad"
	}
	
	filter "system:windows"
		systemversion "latest"
		links { "opengl32.lib" }
	
	filter "configurations:Debug"
		defines { "LIB_DEBUG" }
		symbols "On"
		
	filter "configurations:Release"
		defines { "LIB_NDEBUG" }
		optimize "On"

include "example"

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