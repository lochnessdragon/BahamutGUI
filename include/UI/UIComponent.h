//
//  UIComponent.h
//  bahamutGUI
//
//  Created by lochnessdragon on 11/23/21.
//

#pragma once

#include <vector>
#include <Utils/Vector.h>
#include <yoga/Yoga.h>

namespace bGUI {
    /**
     * UIComponent:
     *  - Manages and maintains children.
     *  - Base class for any and all UI elements.
     *  - UIView is the base class for graphical elements (e.g. sliders, labels, buttons, etc.)
     * - This class just manages YogaLayout basics.
     */
    class UIComponent {
    protected:
        YGNodeRef layoutBox;
        
        std::vector<UIComponent*> children;
        
    public:
        UIComponent();
        
        void appendChild(UIComponent* component);
        //void addChild(int index, UIComponent* component) { children.insert(index, component); }
    };
}
