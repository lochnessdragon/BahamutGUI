#pragma once

#include <UI/Window/WindowHint.h>
#include "GUIRenderer.h"

namespace bGUI {
    class Backend;

    class Backend {
    private:
        static Backend* backend;
    public:
        virtual const WindowHint* getWindowInitFlags(int* size) = 0;
        virtual GUIRenderer* makeRenderer() = 0;

        static Backend* getBackend() { return backend; };
    };
}