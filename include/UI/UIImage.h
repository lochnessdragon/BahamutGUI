#pragma once

#include <stdint.h>

namespace bGUI {
    class UIImage {
    public:
        virtual void setData(int width, int height, int channels, const uint8_t* data) = 0;
    };
}