#pragma once

#include "UIView.h"

#include <Font/Font.h>
#include <string>

namespace bGUI {
    class UILabel : public UIView {
    private:
        std::string text;
    public:
        UILabel(std::string text, Font& font, float fontSize, NVGcolor fontColor);
        ~UILabel();

        float fontSize;
        NVGcolor fontColor;
        Font& font;

        void setText(const char* text) { this->text.assign(text);};
        const std::string& getString() { return text; };

        void render(NVGcontext* context) override;
    };
}