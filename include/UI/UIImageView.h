#pragma once

#include "UIView.h"
#include "UIImage.h"

namespace bGUI {

    enum class ImageFit {
        Fill,
        PreserveAspectRatio,
    };

    class UIImageView : public UIView {
    public:
        UIImage* image;


        UIImageView(UIImage* image);

        void render(NVGcontext* context);
    };
}