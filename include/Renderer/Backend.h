#pragma once

#include <UI/Window/WindowHint.h>
#include <UI/UIWindow.h>
#include <UI/UIImage.h>
#include "GUIRenderer.h"

namespace bGUI {
    class Backend;

    class Backend {
    private:
        static Backend* backend;
    public:
        virtual const WindowHint* getWindowInitFlags(int* size) = 0;
        virtual GUIRenderer* makeRenderer(UIWindow* window) = 0;
        virtual UIImage* createImage(int width, int height, int channels, const uint8_t* data) = 0;

        static Backend* getBackend() { return backend; };
    };
}