#include <Platform/OpenGL/GLBackend.h>

#include <iostream>

#include <stdlib.h>
#include <iostream>

#define NANOVG_GL3_IMPLEMENTATION
#include <nanovg_gl.h>

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

        void GLBackend::createContext()
        {
            context = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);
            if (!context) {
                std::cout << "Failed to load NanoVG context!" << std::endl;
                exit(-1);
            }
        }

        GLBackend::GLBackend() {
        }

        GLBackend::~GLBackend() {
            nvgDeleteGL3(context);
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

        
    }
}