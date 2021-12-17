#pragma once

#include <stdint.h>

namespace bGUI {
    class UIImage {
    protected:
        int width;
        int height;
    public:
        virtual void setData(int width, int height, int channels, const uint8_t* data) = 0;
        virtual const void bind() const = 0;
        virtual const void unbind() const = 0;

        int getWidth() { return width; };
        int getHeight() { return height; };
    };
}