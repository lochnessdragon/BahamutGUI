addPackage("gh:curl/curl")

IncludeDir["libCurl"] = "%{wks.location}/example/deps/curl/include"

project "libCurl"
	kind "Makefile"

	rebuildcommands {
		"cd curl && make"
	}

	cleancommands {
		"cd curl && make clean"
	}
	filter "system:linux or macosx"
		buildcommands {
			"cd curl && autoreconf -fi && ./configure && make"
		}
	
	filter "system:windows"
		buildcommands {
			"cd curl && buildconf.bat && make"
		}