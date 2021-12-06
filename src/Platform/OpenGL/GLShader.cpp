#include <Platform/OpenGL/GLShader.h>

#include <memory>
#include <iostream>
#include <stdlib.h>

namespace bGUI {
    namespace GLBackend {
        void GLShader::checkShaderErrors(uint32_t shaderHandle) {
            int success;
            char infoLog[512];

            glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &success);

            if(!success)
            {
                glGetShaderInfoLog(shaderHandle, 512, NULL, infoLog);
                std::cout << "GLBackend: Shader Creation Failed. Error Log: \n \t" << infoLog << std::endl;
                exit(-1);
            }
        }

        void GLShader::checkProgramErrors(uint32_t programHandle) {
            int success;
            char infoLog[512];

            glGetProgramiv(programHandle, GL_LINK_STATUS, &success);

            if(!success)
            {
                glGetShaderInfoLog(programHandle, 512, NULL, infoLog);
                std::cout << "GLBackend: Shader Linking Failed. Error Log: \n \t" << infoLog << std::endl;
                exit(-1);
            }
        }

        GLShader::GLShader(const char* vertexSrc, const char* fragmentSrc) {
            uint32_t vertexShader;
            vertexShader = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertexShader, 1, &vertexSrc, NULL);
            glCompileShader(vertexShader);
            checkShaderErrors(vertexShader);

            uint32_t fragmentShader;
            fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragmentShader, 1, &fragmentSrc, NULL);
            glCompileShader(fragmentShader);
            checkShaderErrors(fragmentShader);

            handle = glCreateProgram();
            glAttachShader(handle, vertexShader);
            glAttachShader(handle, fragmentShader);
            glLinkProgram(handle);
            checkProgramErrors(handle);

            glDeleteShader(vertexShader);
            glDeleteShader(fragmentShader);
        }
    }
}