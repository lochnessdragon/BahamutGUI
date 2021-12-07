#pragma once

#include <stdint.h>
#include <stdlib.h>
#include "GLVBO.h"

#include <glad/glad.h>

namespace bGUI {
    namespace GLBackend {
        struct GLVAO {
        private:
            uint32_t handle;

            GLVBO verticesBuffer;
            GLVBO indicesBuffer;
        public:
            GLVAO(size_t vertices_size, float* vertices, size_t indices_size, int* indices);

            void bind() { glBindVertexArray(handle); }
            void unbind() { glBindVertexArray(0); }
        };
    }
}