#include "Window.h"

#include <stdlib.h>
#include <stdarg.h>
#include <Utils/Log.h>

Window::Window(const char* title, int width, int height, int hintCount, ...)
{
	if (!glfwInit()) {
		LOG_CRITICAL("Failed to initialize glfw! Aborting!");
		exit(1);
	}

	glfwDefaultWindowHints();

	// va args time
	va_list valist;

	va_start(valist, hintCount);
	for (int i = 0; i < hintCount; i++) {
		WindowHint hint = va_arg(valist, WindowHint);
		glfwWindowHint(hint.hint, hint.value);
	}
	va_end(valist);

	windowHandle = glfwCreateWindow(width, height, title, NULL, NULL);
	if (windowHandle == NULL) {
		LOG_CRITICAL("Failed to create the window! Aborting!");
		glfwTerminate();
		exit(1);
	}

	glfwMakeContextCurrent(windowHandle);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		LOG_CRITICAL("Failed to initialize glad, aborting!");
		exit(1);
	}
}

Window::~Window()
{
}
