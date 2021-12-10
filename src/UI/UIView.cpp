#include <UI/UIView.h>

#include <cstring>
#include <iostream>

namespace bGUI {
    UIView::UIView() {};
    
    UIView::~UIView() {};

    void UIView::render(GUIRenderer* renderer) {
        auto layout = this->getLayout();
				glm::vec2 position = std::get<0>(layout) + getParentPosition();
        
        renderer->renderRect(position, std::get<1>(layout), this->color);

        UIComponent::render(renderer);
    }
}
