#include <Platform/OpenGL/GLBackend.h>

#include <iostream>

#include <stdlib.h>
#include <iostream>

// need function pointers to resize the window, maybe begin and end frames? and handle NVGContext
namespace bGUI {
    namespace GLBackend {
        const WindowHint GLBackend::hints[] = {
            {GLFW_CLIENT_API, GLFW_OPENGL_API},
            {GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE},
            {GLFW_CONTEXT_VERSION_MAJOR, 3},
            {GLFW_CONTEXT_VERSION_MINOR, 2}
        };

        bool GLBackend::__initialized = false;

        GLBackend* GLBackend::instance = 0;

        GLBackend::GLBackend() {
            instance = this;
        }

        GLBackend::~GLBackend() {
        }

        const WindowHint* GLBackend::getWindowInitFlags(int* size) {
            (*size) = sizeof(hints) / sizeof(hints[0]);
            return hints;
        }

        GUIRenderer* GLBackend::getRenderer(UIWindow* window) {
            // load gl functions
            if(!__initialized) {
                if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                    std::cout << "Failed to load opengl functions!" << std::endl;
                    exit(-1);
                }
                __initialized = true;
            }

            glm::ivec2 windowSize = window->getSize();

            return new GLGUIRenderer(windowSize);
        }

        /*UIImage* GLBackend::createImage(int width, int height, int channels, const uint8_t* data) {
            if(!__initialized) {
                std::cout << "To create an image using the opengl backend, you must create a window and context first!" << std::endl;
                exit(-1);
            }

            return new GLUIImage(width, height, channels, data);
        }*/
    }
}