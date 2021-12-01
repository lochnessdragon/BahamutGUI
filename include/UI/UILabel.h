#pragma once

#include "UIView.h"

namespace bGUI {
    class UILabel : public UIView {
    private:
        std::string text;
    public:
        UILabel();
        ~UILabel();

        void setText(const char* text) { this->text.assign(text);};
        const std::string& getString() { return text; };
    };
}