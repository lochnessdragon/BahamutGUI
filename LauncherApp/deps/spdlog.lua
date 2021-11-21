addPackage("gh:gabime/spdlog")

project "spdlog"
	kind "StaticLib"
	language "C++"
	
	files 
	{
		"spdlog/src/spdlog.cpp",
		"spdlog/src/stdout_sinks.cpp",
		"spdlog/src/color_sinks.cpp",
		"spdlog/src/file_sinks.cpp",
		"spdlog/src/async.cpp",
		"spdlog/src/cfg.cpp"
	}
	
	includedirs 
	{
		"spdlog/include"
	}
	
	defines 
	{
		"SPDLOG_COMPILED_LIB"
	}
	
	IncludeDir["spdlog"] = "%{wks.location}/LauncherApp/deps/spdlog/include"
	
	filter "configurations:Debug"
		symbols "on"

	filter "configurations:Release"
		optimize "on"