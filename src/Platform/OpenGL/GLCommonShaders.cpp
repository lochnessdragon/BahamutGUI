#include <Platform/OpenGL/GLCommonShaders.h>

namespace bGUI {
    namespace GLBackend {
        const char* rectShaderVertexSrc = 
            "#version 330 core \n"
            "layout(location = 0) in vec3 position;\n"
            "layout(location = 1) in vec2 texCoord;\n"
            "\n"
            "uniform mat4 model;\n"
			"uniform mat4 projection;\n"
			"uniform mat4 view;"
            "\n"
            "out vec2 textureCoord;\n"
            "\n"
            "void main() {\n"
            "   gl_Position = projection * view * model * vec4(position, 1.0);\n"
            "   textureCoord = texCoord;\n"
            "}\n"; 

        const char* rectShaderFragmentSrc = 
            "#version 330 core\n"
            "in vec2 textureCoord;\n"
            "\n"
            "uniform vec4 color;\n"
            "uniform sampler2D image;\n"
            "\n"
            "out vec4 fragmentColor;\n"
            "\n"
            "void main()\n"
            "{\n"
            "    fragmentColor = texture(image, textureCoord) * color;\n"
            "}\n";
    }
}