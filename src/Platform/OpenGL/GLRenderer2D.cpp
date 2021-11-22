#include <Platform/OpenGL/GLRenderer2D.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdlib.h>

namespace bGUI {
	bool GLRenderer2D::__initialized = false;

	GLRenderer2D::GLRenderer2D(Window* window) {
		glfwMakeContextCurrent(window->getHandle());
		
		if (!__initialized) {
			init();
		}

		glClearColor(1.0, 1.0, 1.0, 1.0);
	}

	// private methods

	void GLRenderer2D::init()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Initializing opengl functions failed!" << std::endl;
			exit(1);
		}

		__initialized = true;
	}
}