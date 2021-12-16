#include <Platform/OpenGL/GLVBO.h>

#include <iostream>

namespace bGUI {
    namespace GLBackend {
        GLVBO::GLVBO(int location, GLenum type) : type(type), location(location) {
            glGenBuffers(1, &handle);
        }

        GLVBO::~GLVBO()
        {
            glDeleteBuffers(1, &handle);
        }

        void GLVBO::bind() {
            glBindBuffer(type, handle);
        }

        void GLVBO::loadData(size_t size, void* data) {
            glBufferData(type, size, data, GL_STATIC_DRAW); 
        }

        void GLVBO::setupData() {
            if(type == GL_ELEMENT_ARRAY_BUFFER) {
                std::cout << "GLBackend Error: cannot call setupData() on indices buffer!" << std::endl;
                return;
            }

            glVertexAttribPointer(location, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(location); 
        }
    }
}