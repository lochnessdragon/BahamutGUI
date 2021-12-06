#pragma once

#include <stdint.h>

namespace bGUI {
    namespace GLBackend {
        struct GLVBO {
        private:
            uint32_t handle;
        public:
            GLVBO();
        };
    }
}