#pragma once

#include "UIComponent.h"

namespace bGUI {
    /**
     * UIView:
     *  - Base class for all graphical components. (i.e. not windows or other "speciality" cases)
     * - Controls color, shading, looks, stuff like that
     */
    class UIView : public UIComponent {
    protected:
        YGValue convertSizeStr(const char* sizeStr);

    public:
        UIView();
        ~UIView();
        
        // sizing methods
        /// <summary>
        /// sets the size given two strings that are either auto, [number]px or [number]%
        /// For example:
        /// UIView view;
        /// view.setSize("100px", "50%");
        /// </summary>
        /// <param name="widthStr"></param>
        /// <param name="heightStr"></param>
        void setSize(const char* widthStr, const char* heightStr);
        std::tuple<YGValue, YGValue> getSize();
    };
}
