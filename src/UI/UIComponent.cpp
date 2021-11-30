//
//  UIComponent.cpp
//  bahamutGUI
//
//  Created by lochnessdragon on 11/23/21.
//

#include <UI/UIComponent.h>

namespace bGUI {
    UIComponent::UIComponent() {
        layoutBox = YGNodeNew();
    }
    
    void UIComponent::appendChild(UIComponent *component) {
        YGNodeInsertChild(this->layoutBox, component->layoutBox, YGNodeGetChildCount(this->layoutBox));
        children.push_back(component);
    }
}
