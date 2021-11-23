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
    class UIComponent {
    private:
        Vector2f position;
        Vector2f size;
        
        std::vector<UIComponent*> children;
        
    public:
        UIComponent(int x, int y, int width, int height);
        
        Vector2f getPosition() { return position; }
        Vector2f getSize() { return size; }
        
        void addChild(UIComponent* component) { children.push_back(component); }
    };
}
