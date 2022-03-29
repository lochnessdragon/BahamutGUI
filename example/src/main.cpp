#include <iostream>

#include <Renderer/GUIRenderer.h>
#include <UI/UIWindow.h>
#include <Renderer/Backend.h>
#include <UI/UIView.h>
#include <UI/UIImageView.h>

#include <Utils/Log.h>

#include <ctype.h>
#include <math.h>
#include <WeatherAPI/WeatherProvider.h>

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

// working on weather data api 
//int main() {
//	Log::initialize();
//
//	float latitude = 37.7749f;
//	float longitude = -122.4194f; // west of prime meridian, so negative
//
//	LOG_INFO("Getting weather for {}, {}", latitude, longitude);
//	WeatherProvider weatherAPI;
//
//	WeatherData weatherData = weatherAPI.getWeatherInfo(latitude, longitude);
//
//	LOG_INFO("Retreieved Weather Data! Temperature: {}", weatherData.temperature);
//}

int main(int argc, char* argv[]) {
	Log::initialize();

	LOG_INFO("Starting Application!");

	LOG_INFO("Creating Window...");

	// with window creation, the backend should be determined.
	bGUI::UIWindow window("Example Application", 500, 275, 1, GLFW_DECORATED, GLFW_TRUE);

	//window.setWindowSizeLimits(500, 300);

	// UI Component Initialization
	bGUI::UIView rootView = bGUI::UIView();
	rootView.setSize("100%", "100%");
	//rootView.setMargin(bGUI::EdgeType::All, "20px");
	rootView.backgroundColor = { 0.0f, 0.6f, 0.9f, 1.0f };
	rootView.setFlexDirection(bGUI::FlexDirection::Row);

	// load image

	/*bGUI::UIImage image1("assets/images/test_image.jpg");
	bGUI::UIImageView imageView(&image1);
	imageView.setSize("100px", "100px");*/

	bGUI::UIView subView;
	subView.setSize("100px", "100px");
	subView.setBorderSize(bGUI::EdgeType::All, 10.0f);
	//subView.setFlexGrow(1);
	subView.backgroundColor = { 1.0f, 1.0f, 0.0f, 1.0f };

bGUI::UIView subView2;
	subView2.setSize("100%", "100px");
	subView2.setBorderSize(bGUI::EdgeType::All, 10.0f);
	//subView.setFlexGrow(1);
	subView2.backgroundColor = { 0.0f, 1.0f, 0.0f, 1.0f };
	//subView.renderBorder = true;
	//subView.borderColor = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

	rootView.appendChild(&subView);
	rootView.appendChild(&subView2);
	//rootView.appendChild(&subView2);
	/*rootView.appendChild(&imageView);*/

	window.appendChild(&rootView);

	bGUI::UIWindow window2("Second window!", 300, 100, 1, GLFW_DECORATED, GLFW_TRUE);
	bGUI::UIView window2Root;
	window2Root.setSize("100%", "100%");
	window2Root.backgroundColor = {1.0f, 0.5f, 0.2f, 1.0f};
	window2Root.setFlexDirection(bGUI::FlexDirection::Column);

	bGUI::UIView window2Content;
	window2Content.backgroundColor = { 0.5f, 0.5f, 0.1f, 1.0f };
	window2Content.setSize("50px", "50%");
	window2Root.appendChild(&window2Content);

	//window2.appendChild(&window2Root);

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

		window2.render();

		glfwPollEvents();
	}

	LOG_INFO("Quitting!");
	//glfwTerminate();

	return 0;
}
