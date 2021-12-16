#include <UI/UIImageView.h>

namespace bGUI {
    UIImageView::UIImageView(UIImage* image) : image(image) {}

    void UIImageView::render(GUIRenderer* renderer)
    {
        auto layout = getLayout();
        glm::vec2 position = std::get<0>(layout) + getParentPosition();
        glm::vec2 size = std::get<1>(layout);

        renderer->renderImage(position, size, this->image, this->style.color);

        // render border
        //float borderTop = this->getBorder(bGUI::EdgeType::All);
        //std::cout << "Border Top: " << borderTop << std::endl;
        //renderer->renderRect(position - glm::vec2(borderTop, borderTop), glm::vec2(size.x + (2 * borderTop), borderTop), this->style.border.color);

        UIComponent::render(renderer);
    }
}