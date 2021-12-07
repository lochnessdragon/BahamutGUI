//
//  UIComponent.cpp
//  bahamutGUI
//
//  Created by lochnessdragon on 11/23/21.
//

#include <UI/UIComponent.h>

#include <iostream>
#include <string.h>

namespace bGUI {
    UIComponent::UIComponent() {
        layoutBox = YGNodeNew();
    }
    
    void UIComponent::appendChild(UIComponent *component) {
        YGNodeInsertChild(this->layoutBox, component->layoutBox, YGNodeGetChildCount(this->layoutBox));
        children.push_back(component);
    }

    void UIComponent::setSize(const char* widthStr, const char* heightStr) {
        YGValue width = convertSizeStr(widthStr);

        switch (width.unit) {
        case YGUnitAuto:
            YGNodeStyleSetWidthAuto(this->layoutBox);
            break;
        case YGUnitPoint:
            YGNodeStyleSetWidth(this->layoutBox, width.value);
            break;
        case YGUnitPercent:
            YGNodeStyleSetWidthPercent(this->layoutBox, width.value);
            break;
        case YGUnitUndefined:
            std::cout << "Error: UIComponent::setSize failed, the width string was invalid." << std::endl;
            return;
            break;
        }
        
        YGValue height = convertSizeStr(heightStr);
        switch (height.unit) {
        case YGUnitAuto:
            YGNodeStyleSetHeightAuto(this->layoutBox);
            break;
        case YGUnitPoint:
            YGNodeStyleSetHeight(this->layoutBox, height.value);
            break;
        case YGUnitPercent:
            YGNodeStyleSetHeightPercent(this->layoutBox, height.value);
            break;
        case YGUnitUndefined:
            std::cout << "Error: UIComponent::setSize failed, the height string was invalid." << std::endl;
            return;
            break;
        }
    }
    
    std::tuple<YGValue, YGValue> UIComponent::getSize() {
        YGValue width = YGNodeStyleGetWidth(this->layoutBox);
        YGValue height = YGNodeStyleGetHeight(this->layoutBox);
        
        return std::make_tuple(width, height);
    }

    // padding 
    void UIComponent::setPadding(EdgeType border, const char* paddingStr) {
        YGValue paddingVal = convertSizeStr(paddingStr);

        switch(paddingVal.unit) {
        case YGUnitPoint:
            YGNodeStyleSetPadding(this->layoutBox, (YGEdge) border, paddingVal.value);
            break;
        case YGUnitPercent:
            YGNodeStyleSetPaddingPercent(this->layoutBox, (YGEdge) border, paddingVal.value);
            break;
        default:
            std::cout << "Parsing the value passed to function UIComponent::setPadding failed. Value: " << paddingStr << std::endl; 
            break;
        }
    }

    YGValue UIComponent::getPadding(EdgeType border) {
        return YGNodeStyleGetPadding(this->layoutBox, (YGEdge) border);
    }

    void UIComponent::setMargin(EdgeType border, const char* marginStr) {
        YGValue marginVal = convertSizeStr(marginStr);

        switch(marginVal.unit) {
        case YGUnitPoint:
            YGNodeStyleSetMargin(this->layoutBox, (YGEdge) border, marginVal.value);
            break;
        case YGUnitPercent:
            YGNodeStyleSetMarginPercent(this->layoutBox, (YGEdge) border, marginVal.value);
            break;
        default:
            std::cout << "Parsing the value passed to function UIComponent::setMargin failed. Value: " << marginStr << std::endl; 
            break;
        }
    }

    YGValue UIComponent::getMargin(EdgeType border) {
        return YGNodeStyleGetMargin(this->layoutBox, (YGEdge) border);
    }

    void UIComponent::setBorder(EdgeType edgeType, float borderSize)
    {
      YGNodeStyleSetBorder(this->layoutBox, (YGEdge) edgeType, borderSize);
    }
    
    float UIComponent::getBorder(EdgeType edgeType)
    {
      return YGNodeStyleGetBorder(this->layoutBox, (YGEdge) edgeType);
    }

    void UIComponent::computeLayout(float width, float height) {
        YGNodeCalculateLayout(this->layoutBox, width, height, YGDirectionLTR);
    }

    std::tuple<Vector2f, Vector2f> UIComponent::getLayout() {
        float posX, posY, width, height = 0;

        posX = YGNodeLayoutGetLeft(this->layoutBox);
        posY = YGNodeLayoutGetTop(this->layoutBox);
        width = YGNodeLayoutGetWidth(this->layoutBox);
        height = YGNodeLayoutGetHeight(this->layoutBox);

        return std::make_tuple<Vector2f, Vector2f>({posX, posY}, {width, height});
    }

    void UIComponent::render(GUIRenderer* renderer) {
        for(auto component : this->children) {
            component->render(renderer);
        }
    }

    YGValue UIComponent::convertSizeStr(const char* sizeStr)
    {
        YGUnit unit;
        float value = 0;

        size_t sizeStrLen = strlen(sizeStr);

        if (strncmp(sizeStr, "auto", 4) == 0) {
            // auto keyword
            unit = YGUnitAuto;
        }
        else if (sizeStr[sizeStrLen - 1] == '%') {
            // percentage string
            unit = YGUnitPercent;

            value = strtof(sizeStr, NULL);
        }
        else if (sizeStr[sizeStrLen - 2] == 'p' && sizeStr[sizeStrLen - 1] == 'x') {
            // px string
            unit = YGUnitPoint;
            value = strtof(sizeStr, NULL);
        }
        else {
            unit = YGUnitUndefined;
        }

        return {value, unit};
    }
}
