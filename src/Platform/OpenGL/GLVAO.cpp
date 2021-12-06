#include <Platform/OpenGL/GLVAO.h>

#include <glad/glad.h>

namespace bGUI {
    namespace GLBackend {
        GLVAO::GLVAO() {
            glGenVertexArrays(1, &handle);
        }
    }
}