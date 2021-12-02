#include <Platform/OpenGL/GLGUIRenderer.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdlib.h>
#include <iostream>

namespace bGUI {
	bool GLGUIRenderer::__initialized = false;

    GLGUIRenderer::GLGUIRenderer(UIWindow* window) : window(window) {
		glfwMakeContextCurrent(window->getHandle());
		
		if (!__initialized) {
			init();
		}
        
        // maintain proper opengl size
        Vector2i windowSize = window->getSize();
        glViewport(0, 0, windowSize.x, windowSize.y);
        
        window->setResizeCallback(GLGUIRenderer::resizeCallback);

		glClearColor(1.0, 1.0, 1.0, 1.0);
	}

    // public methods
    
    void GLGUIRenderer::renderUI(std::vector<RenderCommand> &commands) {
        prepareScene();
        
        //std::cout << "Rendering Component" << std::endl;
        
        endScene();
    }
    
	// private methods
    
    void GLGUIRenderer::prepareScene()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
    void GLGUIRenderer::endScene()
    {
        window->swapBuffers();
    }

	void GLGUIRenderer::init()
	{
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cout << "Initializing opengl functions failed!" << std::endl;
			exit(1);
		}

		__initialized = true;
	}
}
