#include <UI/UIWindow.h>

#include <stdlib.h>
#include <stdarg.h>
#include <iostream>
#include <functional>
#include <Renderer/Backend.h>

static void error_callback(int ecode, const char* desc) {
	std::cout << "GLFW Error: " << ecode << " Description: " << desc << std::endl;
}

namespace bGUI {
	int UIWindow::__windowCount = 0;
	GLFWwindow* UIWindow::first_window = NULL;

    UIWindow::UIWindow(const char* title, int width, int height, int hintCount, ...) : UIComponent(), resizeEvent()
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
        
		// configure window renderer flags
		int size = 0;
		const WindowHint* rendererHints = Backend::getBackend()->getWindowInitFlags(&size);

		for(int i = 0; i < size; i++) {
			glfwWindowHint(rendererHints[i].hint, rendererHints[i].value);
		}

		windowHandle = glfwCreateWindow(width, height, title, NULL, first_window);

		if (windowHandle == NULL) {
			//LOG_CRITICAL("Failed to create the window! Aborting!");
			std::cout << "Failed to create a window! Aborting!" << std::endl;
			glfwTerminate();
			exit(1);
		}

		glfwMakeContextCurrent(windowHandle);

		// context is current? alright, load opengl functions
		this->renderer = Backend::getBackend()->getRenderer(this);

		// add a window data pointer that points to this class for ease of access in the future
		glfwSetWindowUserPointer(windowHandle, this);

		// set callbacks
		// auto resizeCallback = std::bind(UIWindow::resizeCallback, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		setResizeCallback([](GLFWwindow* windowHandle, int width, int height) -> void {
			UIWindow* window = (UIWindow*) glfwGetWindowUserPointer(windowHandle);

			WindowResizeData eventData;
			eventData.windowHandle = window;
			eventData.height = height;
			eventData.width = width;

			window->resizeEvent.dispatch(eventData);
		});
		
		setKeyCallback([](GLFWwindow* windowHandle, int key, int scancode, int action, int mods) -> void {
			UIWindow* window = (UIWindow*) glfwGetWindowUserPointer(windowHandle);
			
			KeyEventData eventData;
			eventData.keycode = key;
			eventData.status = action;

			window->keyEvent.dispatch(eventData);
		});

		this->resizeEvent.subscribe(EVENT_CLASS_FUNCTION(resizeCallback)); // using c++14
        
        // Custom yoga layout stuff
        YGNodeStyleSetWidth(this->layoutBox, (float) width);
        YGNodeStyleSetHeight(this->layoutBox, (float) height);
		
		renderer->resizeFrame(width, height);

		__windowCount += 1;

		// finally, set the first window
		if (first_window == NULL) {
			first_window = windowHandle;
		}
	}

	UIWindow::~UIWindow()
	{
		glfwDestroyWindow(windowHandle);
		__windowCount -= 1;
		
		if(__windowCount == 0)
			glfwTerminate();
	}

	void UIWindow::render()
	{
		// get the size and compute the layout for it.
		glm::ivec2 size = getSize();
		computeLayout(-1, -1); // calculate for infinity (ish)
		
		// render
		// to deal with multiple windows, make the context current before calling any render methods
		glfwMakeContextCurrent(windowHandle);

		// prepare the scene with nvg
		renderer->beginFrame();

		this->UIComponent::render(Backend::getBackend()->getRenderContext());

		renderer->endFrame();

		swapBuffers();	
		glFinish(); // make sure to flush all data when run so that multiple files can be queued.
	}

	// potential redundancy (of data.windowHandle ptr and this ptr) is potentially stupid, 
	// but this also serves as an example of how one might use a resize callback. 
	// Idk.
	bool UIWindow::resizeCallback(const WindowResizeData& data)
	{
		glfwMakeContextCurrent(windowHandle);
		this->renderer->resizeFrame(data.width, data.height);
		YGNodeStyleSetWidth(this->layoutBox, (float) data.width);
		YGNodeStyleSetHeight(this->layoutBox, (float) data.height);

		return true; // keep calling other functions
	}

	float UIWindow::getDPI() {
		int frameWidth, frameHeight = 0;
		glfwGetFramebufferSize(this->windowHandle, &frameWidth, &frameHeight);

		glm::ivec2 windowSize = getSize();

		return (float) frameWidth / (float) windowSize.x;
	}
}
