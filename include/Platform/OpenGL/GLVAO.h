#pragma once

#include <stdint.h>
#include "GLVBO.h"

namespace bGUI {
    namespace GLBackend {
        struct GLVAO {
        private:
            uint32_t handle;
        public:
            GLVAO();
        };
    }
}