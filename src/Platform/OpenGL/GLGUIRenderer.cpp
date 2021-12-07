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
    0.0f,

    1.0f,
    -1.0f,
    0.0f,

    -1.0f,
    -1.0f,
    0.0f,

    -1.0f,
    1.0f,
    0.0f,
};

static int rectIndices[] = {
    0, 1, 2,
    0, 2, 3};

namespace bGUI
{
    namespace GLBackend
    {

        GLGUIRenderer::GLGUIRenderer(UIWindow* window) : rectShader(), rectangleObj(sizeof(rectCoords), rectCoords, sizeof(rectIndices), rectIndices)
        {
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

            window->resizeEvent.subscribe(EVENT_CLASS_FUNCTION(windowResizeCallback));
            window->keyEvent.subscribe(EVENT_CLASS_FUNCTION(keyCallback));
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
            //std::cout << "Rendering rectangle with position: " << position << " size: " << size << " and color: " << color.x << ", " << color.y << ", " << color.z << ", " << color.w << "." << std::endl;
            rectShader.use();
            checkGLErrors();
            rectShader.loadColor(color);
            checkGLErrors();
            rectangleObj.bind();

            // draw
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            rectangleObj.unbind();
            rectShader.unbind();
        }

        void GLGUIRenderer::endScene()
        {
            //window->swapBuffers();
        }

        // private methods

        bool GLGUIRenderer::windowResizeCallback(const ::bGUI::WindowResizeData& data) {
            resizeFrame(data.width, data.height);
            return true;
        }

        bool GLGUIRenderer::keyCallback(const ::bGUI::KeyEventData& data) {
            if(data.keycode == GLFW_KEY_Z && data.status == GLFW_PRESS) {
                toggleWireframe();
            }
            return true;
        }

        // static methods
        void GLGUIRenderer::checkGLErrors() {
            int error = glGetError();
            if(error != GL_NO_ERROR) {
                switch(error) {
                    case GL_INVALID_ENUM:
                        std::cout << "GL Error: Invalid Enum!" << std::endl;
                        break;
                    case GL_INVALID_INDEX:
                        std::cout << "GL Error: Invalid Index!" << std::endl;
                        break;
                    case GL_INVALID_OPERATION:
                        std::cout << "GL Error: Invalid Operation" << std::endl;
                        break;
                    case GL_INVALID_FRAMEBUFFER_OPERATION:
                        std::cout << "GL Error: Invalid Framebuffer Operation" << std::endl;
                        break;
                    case GL_INVALID_VALUE:
                        std::cout << "GL Error: Invalid Value!" << std::endl;
                    case GL_STACK_OVERFLOW:
                        std::cout << "GL Error: Stack Overflow! (On a side note, you should probably check stackoverflow.com about this one.)" << std::endl;
                        break;
                    case GL_STACK_UNDERFLOW:
                        std::cout << "GL Error: Stack Underflow? (Does this site have a welcoming community? Idk.)" << std::endl;
                        break;
                    case GL_OUT_OF_MEMORY:
                        std::cout << "GL Error: Out of Memory. (Oops, looks like Dave ran wild with malloc again, my b)" << std::endl;
                        break;
                    default:
                        std::cout << "Unknown GL error!" << std::endl;
                        break;
                }
            }
        }
    }
}
