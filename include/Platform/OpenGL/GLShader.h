#pragma once

#include <glad/glad.h>

namespace bGUI {
    namespace GLBackend {
        class GLShader {
        private:
            uint32_t handle;

            static void checkShaderErrors(uint32_t shaderHandle);
            static void checkProgramErrors(uint32_t programHandle);
        public:
            GLShader(const char* vertexSrc, const char* fragmentSrc);

            void use() { glUseProgram(handle); }
        };
    }
}