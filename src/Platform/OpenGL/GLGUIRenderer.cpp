#include <Platform/OpenGL/GLGUIRenderer.h>
#include <Platform/OpenGL/GLCommonShaders.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdlib.h>
#include <iostream>

static float rectCoords[] = {
    1.0f,
    1.0f,
    0.1f,
    1.0f,
    -1.0f,
    0.1f,
    -1.0f,
    -1.0f,
    0.1f,
    -1.0f,
    1.0f,
    0.1f,
};

static int rectIndices[] = {
    1, 2, 3,
    1, 3, 4};

namespace bGUI
{
    namespace GLBackend
    {

        GLGUIRenderer::GLGUIRenderer() : rectShader(rectShaderVertexSrc, rectShaderFragmentSrc) {
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        }

        // public methods

        void GLGUIRenderer::resizeFrame(int width, int height)
        {
            glViewport(0, 0, width, height);
        }

        void GLGUIRenderer::prepareScene()
        {
            glClear(GL_COLOR_BUFFER_BIT);
        }

        void GLGUIRenderer::renderRect(const Vector2f &position, const Vector2f &size, const Vector4f &color)
        {
            std::cout << "Rendering rectangle with position: " << position << " size: " << size << " and color: " << color.x << ", " << color.y << ", " << color.z << ", " << color.w << "." << std::endl;
        }

        void GLGUIRenderer::endScene()
        {
            //window->swapBuffers();
        }

        // private methods
    }
}
