#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace bGUI
{
    namespace GLBackend
    {
        class GLShader
        {
        private:
            uint32_t handle;

            static void checkShaderErrors(uint32_t shaderHandle);
            static void checkProgramErrors(uint32_t programHandle);

        public:
            GLShader(const char *vertexSrc, const char *fragmentSrc);
            ~GLShader();

            void use() { glUseProgram(handle); }
            void unbind() { glUseProgram(0); }

            int getUniformLocation(const char *name);
            void loadVec4f(int location, const glm::vec4 &vec4f) { glUniform4f(location, vec4f.x, vec4f.y, vec4f.z, vec4f.w); }
						void loadMat4f(int location, const glm::mat4& matrix) { glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix)); }
        };
    }
}