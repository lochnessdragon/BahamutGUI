project "GLAD"
	kind "StaticLib"
	language "C"
	
	files { "src/glad.c" }
	
	includedirs { "include/" }
	
	IncludeDir["Glad"] = "%{wks.location}/LauncherApp/deps/glad/include/"
	
	filter "configurations:Debug"
		symbols "on"

	filter "configurations:Release"
		optimize "on"