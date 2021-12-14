#include <iostream>

#include <Renderer/GUIRenderer.h>
#include <UI/UIWindow.h>
#include <Renderer/Backend.h>
#include <UI/UIView.h>
#include <UI/UIImageView.h>

#include <Utils/Log.h>
#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include <stb_image.h>
#include <ctype.h>
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

uint8_t* loadImage(const char* filename, int* width, int* height, int* channels) {
	LOG_TRACE("Loading image: {}", filename);

	uint8_t* data = stbi_load(filename, width, height, channels, 0);

	if(!data) {
		LOG_ERROR("Failed to load: {}", filename);
		LOG_ERROR("STBImage loading failed with error: {}", stbi_failure_reason());
	}

	return data;
}

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
	rootView.setPadding(bGUI::EdgeType::All, "20px");
	//rootView.setMargin(bGUI::EdgeType::All, "20px");
	rootView.style.color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	rootView.setFlexDirection(bGUI::FlexDirection::Row);

	// load image
	int width, height, channels;
	// potentially add image cloning to build step
	uint8_t* imageData = loadImage("example/assets/images/test_image.jpg", &width, &height, &channels);

	// consider moving image creation methods to window (or directly with UI image itself).
	bGUI::UIImage* image = bGUI::Backend::getBackend()->createImage(width, height, channels, imageData); // load image

	bGUI::UIImageView subView(image);
	subView.setSize("100px", "100px");
	// with images, color is like an overlay
	//subView.setImage(&image); // set the image.

	bGUI::UIView subView2;
	subView2.setSize("100px", "100px");
	subView2.setBorder(bGUI::EdgeType::All, 10.0f);
	subView2.setFlexGrow(1);
	subView2.style.color = glm::vec4(1.0f);
	subView2.style.border.color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);

	rootView.appendChild(&subView);
	rootView.appendChild(&subView2);
    
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
