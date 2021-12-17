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
        parent = NULL;
    }
    
    void UIComponent::appendChild(UIComponent *component) {
        // YGNodeInsertChild(this->layoutBox, component->layoutBox, YGNodeGetChildCount(this->layoutBox));
        YGNodeInsertChild(this->layoutBox, component->layoutBox, YGNodeGetChildCount(this->layoutBox)); // should we move over to object oriented programming?
        children.push_back(component);
				component->setParent(this);
    }

    void UIComponent::setJustification(JustifyType type) {
        YGNodeStyleSetJustifyContent(this->layoutBox, (YGJustify) type);
    }

    JustifyType UIComponent::getJustification() {
        return (JustifyType) YGNodeStyleGetJustifyContent(this->layoutBox);
    }

    void UIComponent::setPositionType(PositionType type) {
        YGNodeStyleSetPositionType(this->layoutBox, (YGPositionType) type);
    }

    void UIComponent::setPositionFromEdge(EdgeType type, const char* position) {
        YGValue posValue = convertSizeStr(position);

        switch(posValue.unit) {
            case YGUnitPoint:
                YGNodeStyleSetPosition(this->layoutBox, (YGEdge) type, posValue.value);
                break;
            case YGUnitPercent:
                YGNodeStyleSetPositionPercent(this->layoutBox, (YGEdge) type, posValue.value);
                break;
            default:
                std::cout << "UIComponent::setPositionFromEdge failed to parse position str: " << position << std::endl; 
                break;
        }
    }

    YGValue UIComponent::getPositionFromEdge(EdgeType type) {
        return YGNodeStyleGetPosition(this->layoutBox, (YGEdge) type);
    }

    PositionType UIComponent::getPositionType() {
        return (PositionType) YGNodeStyleGetPositionType(this->layoutBox);
    }

    void UIComponent::setAspectRatio(float ratio) {
        YGNodeStyleSetAspectRatio(this->layoutBox, ratio);
    }

    float UIComponent::getAspectRatio() {
        return YGNodeStyleGetAspectRatio(this->layoutBox);
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

    void UIComponent::setMinSize(const char* widthStr, const char* heightStr) {
        YGValue width = convertSizeStr(widthStr);

        switch (width.unit) {
        case YGUnitPoint:
            YGNodeStyleSetMinWidth(this->layoutBox, width.value);
            break;
        case YGUnitPercent:
            YGNodeStyleSetMinWidthPercent(this->layoutBox, width.value);
            break;
        case YGUnitUndefined:
            std::cout << "Error: UIComponent::setMinSize failed, the width string was invalid: " << widthStr << std::endl;
            return;
            break;
        }
        
        YGValue height = convertSizeStr(heightStr);
        switch (height.unit) {
        case YGUnitPoint:
            YGNodeStyleSetMinHeight(this->layoutBox, height.value);
            break;
        case YGUnitPercent:
            YGNodeStyleSetMinHeightPercent(this->layoutBox, height.value);
            break;
        case YGUnitUndefined:
            std::cout << "Error: UIComponent::setMinSize failed, the height string was invalid: " << heightStr << std::endl;
            return;
            break;
        }
    }

    std::tuple<YGValue, YGValue> UIComponent::getMinSize() {
        YGValue width = YGNodeStyleGetMinWidth(this->layoutBox);
        YGValue height = YGNodeStyleGetMinHeight(this->layoutBox);

        return std::make_tuple(width, height);
    }

    void UIComponent::setMaxSize(const char* widthStr, const char* heightStr) {
        YGValue width = convertSizeStr(widthStr);

        switch (width.unit) {
        case YGUnitPoint:
            YGNodeStyleSetMaxWidth(this->layoutBox, width.value);
            break;
        case YGUnitPercent:
            YGNodeStyleSetMaxWidthPercent(this->layoutBox, width.value);
            break;
        case YGUnitUndefined:
            std::cout << "Error: UIComponent::setMaxSize failed, the width string was invalid: " << widthStr << std::endl;
            return;
            break;
        }
        
        YGValue height = convertSizeStr(heightStr);
        switch (height.unit) {
        case YGUnitPoint:
            YGNodeStyleSetMaxHeight(this->layoutBox, height.value);
            break;
        case YGUnitPercent:
            YGNodeStyleSetMaxHeightPercent(this->layoutBox, height.value);
            break;
        case YGUnitUndefined:
            std::cout << "Error: UIComponent::setMaxSize failed, the height string was invalid: " << heightStr << std::endl;
            return;
            break;
        }
    }

    std::tuple<YGValue, YGValue> UIComponent::getMaxSize() {
        YGValue width = YGNodeStyleGetMaxWidth(this->layoutBox);
        YGValue height = YGNodeStyleGetMaxHeight(this->layoutBox);

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

    void UIComponent::setBorderSize(EdgeType edgeType, float borderSize)
    {
      YGNodeStyleSetBorder(this->layoutBox, (YGEdge) edgeType, borderSize);
    }
    
    float UIComponent::getBorderSize(EdgeType edgeType)
    {
      return YGNodeStyleGetBorder(this->layoutBox, (YGEdge) edgeType);
    }

    void UIComponent::computeLayout(float width, float height) {
				if(width > 0 && height > 0) {
        	YGNodeCalculateLayout(this->layoutBox, width, height, YGDirectionLTR);
				} else {
					YGNodeCalculateLayout(this->layoutBox, YGUndefined, YGUndefined, YGDirectionLTR);
				}
    }

    std::tuple<glm::vec2, glm::vec2> UIComponent::getLayout() {
        float posX, posY, width, height = 0;

        posX = YGNodeLayoutGetLeft(this->layoutBox);
        posY = YGNodeLayoutGetTop(this->layoutBox);
        width = YGNodeLayoutGetWidth(this->layoutBox);
        height = YGNodeLayoutGetHeight(this->layoutBox);

        return std::make_tuple<glm::vec2, glm::vec2>({posX, posY}, {width, height});
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
