#pragma once

// todo setup proper platform management
#include <Platform/PlatformDetection.h>

#ifdef bGUI_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace bGUI {
	struct WindowHint {
		int hint, value;

		WindowHint(int hint, int value) : hint(hint), value(value) {};
	};

	class Window {
	private:
		GLFWwindow* windowHandle;

	public:
		Window(const char* title = "Window!", int width = 800, int height = 600, int hintCount = 0, ...);
		~Window();

		bool shouldClose() { return glfwWindowShouldClose(windowHandle); };

		void swapBuffers() { return glfwSwapBuffers(windowHandle); };

		GLFWwindow* getHandle() { return windowHandle; };

		void setWindowSizeLimits(int minwidth = 0, int minheight = 0, int maxwidth = GLFW_DONT_CARE, int maxheight = GLFW_DONT_CARE) { glfwSetWindowSizeLimits(windowHandle, minwidth, minheight, maxwidth, maxheight); }

		void resize(int width, int height) { glfwSetWindowSize(windowHandle, width, height); };

		void getPosition(int* x, int* y) { glfwGetWindowPos(windowHandle, x, y); };
		void setPosition(int x, int y) { glfwSetWindowPos(windowHandle, x, y); };

		// input (todo: move input actions to another class)
		int getMouseButton(int button) { return glfwGetMouseButton(windowHandle, button); };
		void getMousePosition(double* x, double* y) { glfwGetCursorPos(windowHandle, x, y); };

		void setCursorPosCallback(GLFWcursorposfun callback) { glfwSetCursorPosCallback(windowHandle, callback); };
	};
}