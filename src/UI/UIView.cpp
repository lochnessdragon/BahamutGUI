#include <UI/UIView.h>

#include <cstring>
#include <iostream>

namespace bGUI {
    UIView::UIView() {};
    
    UIView::~UIView() {};
    
    void UIView::setSize(const char* widthStr, const char* heightStr) {
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
            std::cout << "Error: UIView::setSize failed, the width string was invalid." << std::endl;
            return;
            break;
        }
        
        YGValue height = convertSizeStr(heightStr);
        switch (height.unit) {
        case YGUnitAuto:
            YGNodeStyleSetWidthAuto(this->layoutBox);
            break;
        case YGUnitPoint:
            YGNodeStyleSetWidth(this->layoutBox, height.value);
            break;
        case YGUnitPercent:
            YGNodeStyleSetWidthPercent(this->layoutBox, height.value);
            break;
        case YGUnitUndefined:
            std::cout << "Error: UIView::setSize failed, the height string was invalid." << std::endl;
            return;
            break;
        }
    }
    
    std::tuple<YGValue, YGValue> UIView::getSize() {
        YGValue width = YGNodeStyleGetWidth(this->layoutBox);
        YGValue height = YGNodeStyleGetHeight(this->layoutBox);
        
        return std::make_tuple(width, height);
    }

    YGValue UIView::convertSizeStr(const char* sizeStr)
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
