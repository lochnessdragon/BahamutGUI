#include <Platform/OpenGL/GLVBO.h>

#include <glad/glad.h>

namespace bGUI {
    namespace GLBackend {
        GLVBO::GLVBO() {
            glGenBuffers(1, &handle);
        }
    }
}