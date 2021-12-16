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
            GLVBO textureCoordsBuffer;
        public:
            GLVAO(size_t vertices_size, float* vertices, size_t indices_size, int* indices, size_t texture_coords_size, float* texture_coords);
            ~GLVAO();

            void bind() { glBindVertexArray(handle); }
            void unbind() { glBindVertexArray(0); }
        };
    }
}