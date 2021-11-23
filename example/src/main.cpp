#include <iostream>

#include <Window/Window.h>
#include <Renderer/GUIRenderer.h>
#include <UI/UIComponent.h>

#include <Utils/Log.h>
#include <math.h>

//bool window_drag_active = false;
//
//double cursorDragStartXPos = 0;
//double cursorDragStartYPos = 0;
//
//void cursorPosCallback(GLFWwindow* window, double x, double y) {
//    if (window_drag_active) {
//        double delta_x = x - cursorDragStartXPos;
//        double delta_y = y - cursorDragStartYPos;
//        int winX, winY;
//        //LOG_INFO("Window X: {} Y: {} Cursor: X: {} Y: {}", winX, winY, x, y);
//        glfwGetWindowPos(window, &winX, &winY);
//        glfwSetWindowPos(window, winX + delta_x, winY + delta_y);
//    }
//}

int main(int argc, char * argv[]) {
	Log::initialize();

	LOG_INFO("Starting Application!");

	LOG_INFO("Creating Window...");
	bGUI::Window window("Launcher", 800, 500, 1, GLFW_DECORATED, GLFW_TRUE);
	auto renderer = bGUI::GUIRenderer::get(&window);

	window.setWindowSizeLimits(500, 400);
//    window.setCursorPosCallback(cursorPosCallback);

	glfwSwapInterval(0);

	glViewport(0, 0, 800, 600);
    
    // UI Component Initialization
    bGUI::UIComponent component(0, 0, 100, 100);

	double startTime = glfwGetTime();

	while (!window.shouldClose()) {
		
		// app logic
		double elapsedTime = glfwGetTime() - startTime;
		//LOG_INFO("ElapsedTime: {0}", elapsedTime);

		// custom window moving code.
//        if (window.getMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
//            if (!window_drag_active) {
//                window.getMousePosition(&cursorDragStartXPos, &cursorDragStartYPos);
//            }
//
//            window_drag_active = true;
//        }
//        else {
//            window_drag_active = false;
//        }

		// render
        renderer->renderUI(component);
//        glClear(GL_COLOR_BUFFER_BIT);

		glfwPollEvents();
	}

	LOG_INFO("Quit requested!");
	glfwTerminate();

	return 0;
}
