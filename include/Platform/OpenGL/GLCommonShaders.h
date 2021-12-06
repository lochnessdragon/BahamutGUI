#pragma once

namespace bGUI {
    namespace GLBackend {
        const char* rectShaderVertexSrc = 
            "#version 330 core \n"
            "layout(location = 0) in vec3 position;\n"
            "uniform vec4 color;\n"
            "out vec4 colorOut;\n"
            "\n"
            "void main() {\n"
            "   colorOut = color;\n"
            "   gl_Position = vec4(position, 1.0);\n"
            "}\n"; 

        const char* rectShaderFragmentSrc = 
            "#version 330 core\n"
            "in vec4 colorOut;\n"
            "out vec4 fragmentColor;\n"
            "\n"
            "void main()\n"
            "{\n"
            "    fragmentColor = colorOut;\n"
            "}\n";
    }
}