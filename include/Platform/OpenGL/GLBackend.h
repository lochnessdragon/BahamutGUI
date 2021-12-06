#pragma once

#include <Renderer/Backend.h>

namespace bGUI {
    namespace GLBackend {
        class GLBackend : public Backend {
        private:
			static const WindowHint hints[];
            static bool __initialized;

        public:
            const WindowHint* getWindowInitFlags(int* size);
            GUIRenderer* makeRenderer();
        };
    }
}