#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <glad/glad.h>

namespace bGUI {
    namespace GLBackend {
        struct GLVBO {
        private:
            uint32_t handle;
            GLenum type;
            int location;
            int unitSize; // corresponds to the amount of data (e.g. 3 floats) that this vbo contains

        public:
            GLVBO(int location, GLenum type, int unitSize);
            ~GLVBO();

            void bind();
            void unbind() { glBindBuffer(type, 0); }
            // assumes that the buffer has been bound.
            void loadData(size_t size, void* data);
            // assumes that the buffer has been bound
            void setupData();
        };
    }
}