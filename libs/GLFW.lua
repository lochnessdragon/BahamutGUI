addPackage("gh:glfw/glfw")

project "GLFW"
	kind "StaticLib"
	language "C"
	pic "On"
	cdialect "C99"
	
	files 
	{
		"glfw/include/GLFW/glfw3.h",
		"glfw/include/GLFW/glfw3native.h",
		"glfw/src/internal.h",
		"glfw/src/platform.h",
		"glfw/src/mappings.h",
		--"glfw/src/glfw_config.h",
		"glfw/src/context.c",
		"glfw/src/init.c",
		"glfw/src/input.c",
		"glfw/src/monitor.c",
		"glfw/src/platform.c",
		"glfw/src/vulkan.c",
		"glfw/src/window.c",
		"glfw/src/egl_context.c",
		"glfw/src/osmesa_context.c",
		"glfw/src/null_platform.h",
		"glfw/src/null_joystick.h",
		"glfw/src/null_init.c",
		"glfw/src/null_monitor.c",
		"glfw/src/null_window.c",
		"glfw/src/null_joystick.c"
	}
	
	IncludeDir["GLFW"] = "%{wks.location}/libs/glfw/include"
	
	filter "system:linux"
		systemversion "latest"
		
		files
		{
			-- X11 files
			"glfw/src/x11_platform.h",
			"glfw/src/xkb_unicode.h",
			"glfw/src/x11_init.c",
			"glfw/src/x11_monitor.c",
			"glfw/src/x11_window.c",
			"glfw/src/xkb_unicode.c",
			"glfw/src/glx_context.c",
			"glfw/src/posix_time.h",
			"glfw/src/posix_thread.h",
			"glfw/src/posix_module.c",
			"glfw/src/posix_time.c",
			"glfw/src/posix_thread.c",
			-- Joystick 
			"glfw/src/linux_joystick.h",
			"glfw/src/linux_joystick.c"
		}

		defines
		{
			"_GLFW_X11",
			"_DEFAULT_SOURCE"
		}

		links 
		{
			"pthread"
		}
		
	filter "system:windows"
		systemversion "latest"

		files
		{
			"glfw/src/win32_time.h",
			"glfw/src/win32_thread.h",
			"glfw/src/win32_module.c",
			"glfw/src/win32_time.c",
			"glfw/src/win32_thread.c",
			-- win32 specific stuff
			"glfw/src/win32_platofmr.h",
			"glfw/src/win32_joystick.h",
			"glfw/src/win32_init.c",
			"glfw/src/win32_joystick.c",
			"glfw/src/win32_monitor.c",
			"glfw/src/win32_window.c",
			"glfw/src/wgl_context.c"
		}

		defines 
		{ 
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

		links {
			"gdi32"
		}

	filter "system:macosx"
		sysincludedirs 
		{
			"./glfw/include"
		}

		files {
			"glfw/src/cocoa_time.h",
			"glfw/src/cocoa_time.c",
			"glfw/src/posix_thread.h",
			"glfw/src/posix_module.c", 
			"glfw/src/posix_thread.c",
			-- Apple specific stuff
			--"glfw/src/glx_context.c",
			"glfw/src/cocoa_platform.h",
			"glfw/src/cocoa_joystick.h",
			"glfw/src/cocoa_init.m",
            "glfw/src/cocoa_joystick.m", 
            "glfw/src/cocoa_monitor.m", 
            "glfw/src/cocoa_window.m",
            "glfw/src/nsgl_context.m"
		}

		defines {
			"_GLFW_COCOA"
		}

		links {
			"Cocoa.framework",
			"IOKit.framework",
			"CoreFoundation.framework"
		}

	filter "configurations:Debug"
		symbols "on"

	filter "configurations:Release"
		optimize "on"