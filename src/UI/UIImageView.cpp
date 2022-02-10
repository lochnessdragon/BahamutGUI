#include <UI/UIImageView.h>

namespace bGUI {
    UIImageView::UIImageView(UIImage* image) : image(image) {}

    void UIImageView::render(NVGcontext* context)
    {
        auto layout = getLayout();
        glm::vec2 position = std::get<0>(layout) + getParentPosition();
        glm::vec2 size = std::get<1>(layout);

        // images are broken right now, pls fix.
        //renderer->renderImage(position, size, this->image, this->backgroundColor);
        nvgBeginPath(context);
        // define the path
        nvgRect(context, position.x, position.y, size.x, size.y);
        
        // setup image for rendering
        NVGpaint imgPaint = nvgImagePattern(context, 0, 0, image->getWidth(), image->getHeight(), 0.0f, image->getHandle(), 1.0f);
        nvgFillPaint(context, imgPaint);
        // finally, fill the path
        nvgFill(context);
        // render border
        //float borderTop = this->getBorder(bGUI::EdgeType::All);
        //std::cout << "Border Top: " << borderTop << std::endl;
        //renderer->renderRect(position - glm::vec2(borderTop, borderTop), glm::vec2(size.x + (2 * borderTop), borderTop), this->style.border.color);

        //UIComponent::render(context);
    }
}