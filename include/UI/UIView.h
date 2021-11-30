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
        UIView();
        ~UIView();
        
        void setSize(const char* widthStr, const char* heightStr);
        std::tuple<YGValue, YGValue> getSize();
    };
}
