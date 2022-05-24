#include <UI/UILabel.h>

#include <iostream>
#include <glm/gtx/string_cast.hpp>

namespace bGUI {
    UILabel::UILabel(std::string inText, Font& inFont, float inFontSize, NVGcolor inFontColor) : text(inText), font(inFont), fontSize(inFontSize), fontColor(inFontColor) {}

    UILabel::~UILabel() {}

    void UILabel::render(NVGcontext* context) {
        auto layout = this->getLayout();
        glm::vec2 position = std::get<0>(layout) + getParentPosition();
        glm::vec2 size = std::get<1>(layout);

        nvgBeginPath(context);
        nvgFontFaceId(context, font.getHandle());
        nvgFontSize(context, fontSize);
        nvgFillColor(context, fontColor);
        nvgText(context, position.x, position.y + fontSize, this->text.c_str(), NULL);
        nvgFill(context);
    }
}