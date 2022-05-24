#pragma once

#include "UIComponent.h"

namespace bGUI {

    /**
     * UIView:
     *  - Base class for all graphical components. (i.e. not windows or other "speciality" cases)
     * - Controls color, shading, looks, stuff like that
     */
    class UIView : public UIComponent {   
    public:
        NVGcolor backgroundColor;

        // border styling
        bool renderBorder;
        glm::vec4 borderColor;
        
        UIView();
        ~UIView();

        void render(NVGcontext* context) override;
    };
}
