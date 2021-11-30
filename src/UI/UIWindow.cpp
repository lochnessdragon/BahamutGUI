#include <UI/UIWindow.h>

#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

static void error_callback(int ecode, const char* desc) {
	std::cout << "GLFW Error: " << ecode << " Description: " << desc << std::endl;
}
namespace bGUI {
    UIWindow::UIWindow(const char* title, int width, int height, int hintCount, ...) : UIComponent()
	{
		//std::cout << "Hint Count: " << hintCount << std::endl;

		glfwSetErrorCallback(error_callback);

		if (!glfwInit()) {
			//LOG_CRITICAL("Failed to initialize glfw! Aborting!");
			std::cout << "Failed" << std::endl;

			exit(1);
		}

		glfwDefaultWindowHints();

		// va args time
		va_list valist;

		va_start(valist, hintCount);
		for (int i = 0; i < hintCount; i++) {
			//std::cout << "1 loop!" << std::endl;
			int hint = va_arg(valist, int);
            int value = va_arg(valist, int);
			glfwWindowHint(hint, value);
		}
		va_end(valist);
        
#ifdef bGUI_PLATFORM_MACOSX
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
#endif

		windowHandle = glfwCreateWindow(width, height, title, NULL, NULL);
		if (windowHandle == NULL) {
			//LOG_CRITICAL("Failed to create the window! Aborting!");
			std::cout << "Failed" << std::endl;
			glfwTerminate();
			exit(1);
		}

		glfwMakeContextCurrent(windowHandle);
        
        // Custom yoga layout stuff
        YGNodeStyleSetWidth(this->layoutBox, width);
        YGNodeStyleSetHeight(this->layoutBox, height);
	}

	UIWindow::~UIWindow()
	{}
}
