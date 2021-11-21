-- initial includes 
include "premake_scripts/dep_downloader"

workspace "Launcher"
	configurations { "Debug", "Release" }
	platforms { "x86", "x86_64", "arm", "arm64" }
	
	targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
	objdir "bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
	
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
include "LauncherApp/deps/glad"
include "LauncherApp/deps/GLFW.lua"
include "LauncherApp/deps/spdlog.lua"

project "LauncherApp"
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
		optimize "On"