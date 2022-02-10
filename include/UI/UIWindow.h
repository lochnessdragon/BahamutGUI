#pragma once

// todo setup proper platform management
#include <Platform/PlatformDetection.h>
#include <glm/glm.hpp>

#ifdef bGUI_PLATFORM_WINDOWS
#include <Windows.h>
#endif

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Window/WindowHint.h"
#include <LibEvent.h>

#include <Renderer/GUIRenderer.h>

#include "UIComponent.h"

namespace bGUI {
	class UIWindow;
	class GUIRenderer;

	struct WindowResizeData {
		UIWindow* windowHandle;
		int width;
		int height;
	};

	struct KeyEventData {
		int keycode;
		int status;
	};

    class UIWindow : public UIComponent {
	private:
		GLFWwindow* windowHandle;
		GUIRenderer* renderer;

		static GLFWwindow* first_window;

		static int __windowCount;

		// all callbacks should be handled by this window and dispatched through the appropriate event dispatcher.
		void setResizeCallback(GLFWwindowsizefun callback) { glfwSetWindowSizeCallback(windowHandle, callback);};
		void setKeyCallback(GLFWkeyfun callback) { glfwSetKeyCallback(this->windowHandle, callback); };
		void setCursorPosCallback(GLFWcursorposfun callback) { glfwSetCursorPosCallback(windowHandle, callback); };

		bool resizeCallback(const WindowResizeData& data);
	public:
		UIWindow(const char* title = "Window!", int width = 800, int height = 600, int hintCount = 0, ...);
		~UIWindow();

		bool shouldClose() { return glfwWindowShouldClose(windowHandle); };

		void swapBuffers() { return glfwSwapBuffers(windowHandle); };

		GLFWwindow* getHandle() { return windowHandle; };

		void setWindowSizeLimits(int minwidth = 0, int minheight = 0, int maxwidth = GLFW_DONT_CARE, int maxheight = GLFW_DONT_CARE) { glfwSetWindowSizeLimits(windowHandle, minwidth, minheight, maxwidth, maxheight); }
        
        // size methods
		glm::ivec2 getSize() {
            glm::ivec2 size;
            glfwGetWindowSize(windowHandle, &size.x, &size.y);
            return size;
        };

		// DPI methods
		float getDPI();
        
		void resize(int width, int height) { glfwSetWindowSize(windowHandle, width, height); };
        
		void getPosition(int* x, int* y) { glfwGetWindowPos(windowHandle, x, y); };
		void setPosition(int x, int y) { glfwSetWindowPos(windowHandle, x, y); };

		// input (todo: move input actions to another class)
		int getMouseButton(int button) { return glfwGetMouseButton(windowHandle, button); };
		void getMousePosition(double* x, double* y) { glfwGetCursorPos(windowHandle, x, y); };

		void render();

		// Event Dispatchers
		LibEvent::EventDispatcher<WindowResizeData> resizeEvent;
		LibEvent::EventDispatcher<KeyEventData> keyEvent;
	};
}
