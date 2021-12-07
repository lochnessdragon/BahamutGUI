#include <Platform/OpenGL/GLCommonShaders.h>

namespace bGUI {
    namespace GLBackend {
        const char* rectShaderVertexSrc = 
            "#version 330 core \n"
            "layout(location = 0) in vec3 position;\n"
            "\n"
            "\n"
            "\n"
            "void main() {\n"
            "   gl_Position = vec4(position, 1.0);\n"
            "}\n"; 

        const char* rectShaderFragmentSrc = 
            "#version 330 core\n"
            "uniform vec4 color;\n"
            "out vec4 fragmentColor;\n"
            "\n"
            "void main()\n"
            "{\n"
            "    fragmentColor = color;\n"
            "}\n";
    }
}