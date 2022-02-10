#pragma once

#include <Renderer/Backend.h>
#include "GLGUIRenderer.h"

namespace bGUI {
    namespace GLBackend {

        class GLBackend : public Backend {
        private:
			static const WindowHint hints[];
            static bool __initialized;
            static GLBackend* instance;

            NVGcontext* context;

        public:
            GLBackend();
            ~GLBackend();

            static GLBackend* singleton() {
                if (!instance)
                    instance = new GLBackend();
                return instance;
            }

            const WindowHint* getWindowInitFlags(int* size);
            GUIRenderer* getRenderer(::bGUI::UIWindow* window);
            NVGcontext* getRenderContext() { return context; }
            //UIImage* createImage(int width, int height, int channels, const uint8_t* data);
        };
    }
}