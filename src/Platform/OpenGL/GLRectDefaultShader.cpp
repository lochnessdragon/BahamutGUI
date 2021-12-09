#include <Platform/OpenGL/GLRectDefaultShader.h>

#include <Platform/OpenGL/GLCommonShaders.h>

namespace bGUI {
    namespace GLBackend {
        GLRectDefaultShader::GLRectDefaultShader() : GLShader(rectShaderVertexSrc, rectShaderFragmentSrc) {
            colorLocation = getUniformLocation("color");
						modelMatLoc = getUniformLocation("model");
						projMatLoc = getUniformLocation("projection");
						viewMatLoc = getUniformLocation("view");
        }
    }
}