#include <Window/Window.h>

#include <stdlib.h>
#include <stdarg.h>
#include <iostream>

static void error_callback(int ecode, const char* desc) {
	std::cout << "GLFW Error: " << ecode << " Description: " << desc << std::endl;
}
namespace bGUI {
	Window::Window(const char* title, int width, int height, int hintCount, ...)
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
			WindowHint hint = va_arg(valist, WindowHint);
			glfwWindowHint(hint.hint, hint.value);
		}
		va_end(valist);

		windowHandle = glfwCreateWindow(width, height, title, NULL, NULL);
		if (windowHandle == NULL) {
			//LOG_CRITICAL("Failed to create the window! Aborting!");
			std::cout << "Failed" << std::endl;
			glfwTerminate();
			exit(1);
		}

		glfwMakeContextCurrent(windowHandle);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			//LOG_CRITICAL("Failed to initialize glad, aborting!");
			std::cout << "Failed" << std::endl;
			exit(1);
		}
	}

	Window::~Window()
	{
	}
}
