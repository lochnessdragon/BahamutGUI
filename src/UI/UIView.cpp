#include <UI/UIView.h>

#include <cstring>
#include <iostream>

namespace bGUI {
    UIView::UIView() : renderBorder(false), backgroundColor({ 1.0f, 1.0f, 1.0f, 1.0f }), borderColor(0.0f) {};
    
    UIView::~UIView() {};

    void UIView::render(NVGcontext* context) {
        auto layout = this->getLayout();
		glm::vec2 position = std::get<0>(layout) + getParentPosition();
        glm::vec2 size = std::get<1>(layout);
        
        nvgBeginPath(context);

        nvgRect(context, position.x, position.y, size.x, size.y);
        nvgFillColor(context, backgroundColor);
        nvgFill(context);

        // render border
        //float borderTop = this->getBorder(bGUI::EdgeType::All);
        //std::cout << "Border Top: " << borderTop << std::endl;
        //renderer->renderRect(position - glm::vec2(borderTop, borderTop), glm::vec2(size.x + (2 * borderTop), borderTop), this->style.border.color);
        

        UIComponent::render(context);
    }
}
