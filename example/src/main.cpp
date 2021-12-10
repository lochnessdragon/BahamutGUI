#include <iostream>

#include <Renderer/GUIRenderer.h>
#include <UI/UIWindow.h>
#include <UI/UIView.h>

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

  // with window creation, the backend should be determined.
	bGUI::UIWindow window("Launcher", 500, 275, 1, GLFW_DECORATED, GLFW_TRUE);
	window.setPadding(bGUI::EdgeType::All, "10px");

	//window.setWindowSizeLimits(500, 300);
    
    // UI Component Initialization
    bGUI::UIView rootView = bGUI::UIView();
	rootView.setSize("100%", "100%");
	//rootView.setMargin(bGUI::EdgeType::All, "20px");
	rootView.getColor().x = 1.0f;
	rootView.getColor().y = 0.0f;
	rootView.getColor().z = 0.0f;
	rootView.getColor().w = 1.0f;
    
    window.appendChild(&rootView);
		LOG_INFO("Finished loading.");

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
		window.render();

		glfwPollEvents();
	}

	LOG_INFO("Quitting!");
	//glfwTerminate();

	return 0;
}
