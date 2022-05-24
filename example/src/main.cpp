#include <iostream>
#include <vector>

#include <UI/UIKit.h>

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

/*
 * Font/Asset loading
 *  - Ideally, we want to be able to do this:
 *  - Font fnt = LoadFont('Arial.ttf');
 *  - However, that seems difficult with the current impl.
 *  - bc we can't share data between nano vg contexts.
 *  - Lets try to though.
 */

int main(int argc, char* argv[]) {
	Log::initialize();

	LOG_INFO("Starting Application!");

	LOG_INFO("Spawning Windows...");

	std::vector<std::shared_ptr<bGUI::UIWindow>> windows;

	// should windows be split between threads? NO!
	// or should they (and rendering) be handled on the main thread? Yes (or a separate render thread...) 
	windows.push_back(std::make_shared<bGUI::UIWindow>("Window 1", 400, 300));
	bGUI::UIView windowRoot1;
	windowRoot1.setSize("100%", "100%");
	windowRoot1.backgroundColor = {1.0f, 1.0f, 1.0f, 1.0f};
	windows[0]->appendChild(&windowRoot1);

	// you have to have 1 window before you can create fonts
	LOG_INFO("Creating font");
	bGUI::Font arial = bGUI::Font("opensans", "assets/fonts/Open_Sans/static/OpenSans/OpenSans-Regular.ttf");
	
	bGUI::UILabel lbl("Example GUI App.", arial, 16.0f, nvgRGBA(0, 0, 0, 255));
	windowRoot1.appendChild(&lbl);

	bGUI::UIView view;
	view.setSize("100px", "100px");
	view.backgroundColor = nvgRGBA(111, 214, 199, 255);
	windowRoot1.appendChild(&view);
	
	bGUI::UILabel lbl2("Today's weather is sunny!", arial, 16.0f, nvgRGBA(0,0,0,255));
	windowRoot1.appendChild(&lbl);

	//bGUI::UIImage image("assets/images/test_image.jpg");

	//bGUI::UIImageView imageView = bGUI::UIImageView(&image);
	//imageView.setSize("100px", "100px");
	//windowRoot1.appendChild(&imageView);

	while (windows.size() > 0) {

		for (std::shared_ptr<bGUI::UIWindow> window : windows) {
			window->render();
		}

		bGUI::UIWindow::pollEvents();
		
		// just to scope the variables and keep the namespace clean
		// deallocate all windows that have been closed
		{
			auto it = windows.begin();

			while (it < windows.end()) {
				if ((*it)->shouldClose()) {
					it = windows.erase(it);
				}
				else {
					it++;
				}
			}
		}
	}

	LOG_INFO("Quitting!");

	return 0;
}
