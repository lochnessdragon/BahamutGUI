#include <Platform/OpenGL/GLVBO.h>

#include <iostream>

namespace bGUI {
    namespace GLBackend {
        GLVBO::GLVBO(int location, GLenum type, int unitSize) : type(type), location(location), unitSize(unitSize) {
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

            glVertexAttribPointer(location, unitSize, GL_FLOAT, GL_FALSE, unitSize * sizeof(float), (void*)0);
            glEnableVertexAttribArray(location); 
        }
    }
}