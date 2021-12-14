#pragma once

#include "UIView.h"
#include "UIImage.h"

namespace bGUI {
    class UIImageView : public UIView {
    private:
        UIImage* image;
    public:
        UIImageView(UIImage* image);

        void setImage(UIImage* image) { this->image = image; };
    };
}