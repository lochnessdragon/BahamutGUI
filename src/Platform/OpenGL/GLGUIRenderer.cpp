#include <Platform/OpenGL/GLGUIRenderer.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdlib.h>
#include <iostream>

namespace bGUI {
    const WindowHint GLGUIRenderer::hints[] = {
        {GLFW_CLIENT_API, GLFW_OPENGL_API},
        {GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE},
        {GLFW_CONTEXT_VERSION_MAJOR, 3},
        {GLFW_CONTEXT_VERSION_MINOR, 3}
    };

    GLGUIRenderer::GLGUIRenderer() {}

    // public methods

    void GLGUIRenderer::postInit() {
        if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Failed to initialized OpenGL functions required for the backend: OPENGL." << std::endl;
            exit(-1);
        }

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }

    const WindowHint* GLGUIRenderer::getWindowInitFlags(int* size) {

		(*size) = sizeof(hints) / sizeof(hints[0]);

		return hints;
	}

    void GLGUIRenderer::resizeFrame(int width, int height) {
        glViewport(0, 0, width, height);
    }

    void GLGUIRenderer::prepareScene()
    {
        glClear(GL_COLOR_BUFFER_BIT);

    }
    
    void GLGUIRenderer::renderRect(const Vector2f& position, const Vector2f& size, const Vector4f& color) 
    {
        std::cout << "Rendering rectangle with position: (" << position.x << ", " << position.y << "), size: (" << size.x << ", " << size.y << ") and color: " << color.x << ", " << color.y << ", " << color.z << ", " << color.w << "." << std::endl; 
    }

    void GLGUIRenderer::endScene()
    {
        //window->swapBuffers();
    }

	// private methods
}
