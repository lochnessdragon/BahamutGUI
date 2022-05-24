#pragma once

#include <Renderer/Backend.h>
#include "GLGUIRenderer.h"

namespace bGUI {
    namespace GLBackend {

        class GLBackend : public Backend {
        private:
			static const WindowHint hints[];
            static bool __initialized;

        protected:
            void createContext() override;
        public:
            GLBackend();
            ~GLBackend();

            const WindowHint* getWindowInitFlags(int* size);
            GUIRenderer* getRenderer(::bGUI::UIWindow* window);
        };
    }
}