#include <Platform/OpenGL/GLBackend.h>
#include <Platform/OpenGL/GLGUIRenderer.h>

#include <iostream>

#include <stdlib.h>
#include <Platform/OpenGL/GLUIImage.h>

namespace bGUI {
    namespace GLBackend {
        const WindowHint GLBackend::hints[] = {
            {GLFW_CLIENT_API, GLFW_OPENGL_API},
            {GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE},
            {GLFW_CONTEXT_VERSION_MAJOR, 3},
            {GLFW_CONTEXT_VERSION_MINOR, 3}
        };

        bool GLBackend::__initialized = false;

        const WindowHint* GLBackend::getWindowInitFlags(int* size) {
            (*size) = sizeof(hints) / sizeof(hints[0]);
            return hints;
        }

        GUIRenderer* GLBackend::makeRenderer(UIWindow* window) {
            // load gl functions
            if(!__initialized) {
                if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                    std::cout << "Failed to load opengl functions!" << std::endl;
                    exit(-1);
                }
                __initialized = true;
            }

            return new GLGUIRenderer(window);
        }

        UIImage* GLBackend::createImage(int width, int height, int channels, const uint8_t* data) {
            if(!__initialized) {
                std::cout << "To create an image using the opengl backend, you must create a window and renderer first!" << std::endl;
                exit(-1);
            }

            return new GLUIImage(width, height, channels, data);
        }
    }
}