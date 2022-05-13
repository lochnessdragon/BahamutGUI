#pragma once

#include <stdint.h>
#include <string>

#include <nanovg.h>
#include <Renderer/GUIRenderer.h>

namespace bGUI {
    class UIImage {
    protected:
        int width;
        int height;
        int handle;

    public:
        UIImage(std::string& filename);
        UIImage(const char* filename);
        ~UIImage();

        // todo: implement setData()
        // unfortunately, the nano vg backend doesn't allow us to simply "set the data" to whatever we want
        // it needs to be the exact same sized image as before, so idk what to do.
        /*void setData(std::string& filename);
        void setData(int width, int height, int channels, const uint8_t* data);*/

        int getWidth() { return width; };
        int getHeight() { return height; };
        int getHandle() { return handle; };
    };
}