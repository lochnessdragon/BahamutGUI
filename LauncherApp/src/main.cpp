#include <iostream>

#include "Window/Window.h"

#include <Utils/Log.h>
#include <math.h>

int main(int argc, char * argv[]) {
	Log::initialize();

	LOG_INFO("Starting Application!");

	LOG_INFO("Creating Window...");
	WindowHint hints[] = { {GLFW_DECORATED, GLFW_FALSE} };
	Window window("Launcher", 800, 500, sizeof(hints) * sizeof(hints[0]), hints);

	window.setWindowSizeLimits(500, 400);

	glfwSwapInterval(1);

	glViewport(0, 0, 800, 600);

	float r, g, b;
	r = 0.0;
	g = 0.0;
	b = 1.0;

	float speed = 0.5;

	double startTime = glfwGetTime();

	bool isMousePressed = false;
	double mouseXFirstPressed = 0;
	double mouseYFirstPressed = 0;
	while (!window.shouldClose()) {
		
		// app logic
		double elapsedTime = glfwGetTime() - startTime;
		//LOG_INFO("ElapsedTime: {0}", elapsedTime);

		r = sin(elapsedTime * speed);
		g = cos(elapsedTime * speed);

		// custom window moving code.
		if (window.getMouseButton(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
			if (!isMousePressed) {
				window.getMousePosition(&mouseXFirstPressed, &mouseYFirstPressed);
			}
			isMousePressed = true;
			double mouseX = 0;
			double mouseY = 0;

			int winX = 0;
			int winY = 0;

			window.getMousePosition(&mouseX, &mouseY);
			window.getPosition(&winX, &winY);

			window.setPosition((double)winX + (mouseX - mouseXFirstPressed), (double)winY + (mouseY - mouseYFirstPressed));
		}
		else {
			isMousePressed = false;
		}

		// render

		glClearColor(r, g, b, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		window.swapBuffers();

		glfwPollEvents();
	}

	LOG_INFO("Quit requested!");
	glfwTerminate();

	return 0;
}