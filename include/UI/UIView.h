#pragma once

#include "UIComponent.h"

namespace bGUI {
    /**
     * UIView:
     *  - Base class for all graphical components. (i.e. not windows or other "speciality" cases)
     * - Controls color, shading, looks, stuff like that
     */
    class UIView : public UIComponent {
    private:
        Vector4f color;
    
    public:
        UIView();
        ~UIView();

        void render(GUIRenderer* renderer) override;

        Vector4f& getColor() { return color; }
    };
}
