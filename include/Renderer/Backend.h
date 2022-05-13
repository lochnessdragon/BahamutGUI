#pragma once

#include <nanovg.h>

#include <UI/Window/WindowHint.h>
#include <UI/UIWindow.h>
#include <UI/UIImage.h>
#include "GUIRenderer.h"

namespace bGUI {
    class Backend;

    class Backend {
    private:
        static Backend* backend; // i.e. Vulkan, OpenGL or DirectX

    protected:
        NVGcontext* context = NULL;

        virtual void createContext() = 0;
    public:
        virtual const WindowHint* getWindowInitFlags(int* size) = 0;
        virtual GUIRenderer* getRenderer(::bGUI::UIWindow* window) = 0;
        
        NVGcontext* getOrCreateContext() { if (context == NULL) { createContext(); } return context; };

        static Backend* getBackend() { return backend; };
    };
}