#pragma once

#include "UIComponent.h"

namespace bGUI {
    struct BorderStyle {
        glm::vec4 color;
        float corner_radius;
    };

    struct UIViewStyle {
        glm::vec4 color;
        BorderStyle border;
    };

    /**
     * UIView:
     *  - Base class for all graphical components. (i.e. not windows or other "speciality" cases)
     * - Controls color, shading, looks, stuff like that
     */
    class UIView : public UIComponent {   
    public:
        UIViewStyle style;

        UIView();
        ~UIView();

        void render(GUIRenderer* renderer) override;
    };
}
