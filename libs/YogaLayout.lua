addPackage("gh:facebook/yoga")

project "YogaLayout"
	language "C++"
	kind "StaticLib"
	cppdialect "C++11"

	files {
		"yoga/yoga/**.cpp"
	}

	includedirs {
		"yoga/"
	}

	IncludeDir["YogaLayout"] = "%{wks.location}/libs/yoga"

	filter "system:macosx"
		sysincludedirs {
			"./yoga/"
		}

	filter "configurations:Debug"
		symbols "on"

	filter "configurations:Release"
		optimize "on"