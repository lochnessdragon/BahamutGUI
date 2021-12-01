#include <UI/UIView.h>

#include <cstring>
#include <iostream>

namespace bGUI {
    UIView::UIView() {};
    
    UIView::~UIView() {};
    
    void UIView::setSize(const char* widthStr, const char* heightStr) {
        int widthStrLen = strlen(widthStr);
        
        if(strncmp(widthStr, "auto", 4) == 0) {
            // auto keyword
            YGNodeStyleSetWidthAuto(this->layoutBox);
//            std::cout << "Set width to auto!" << std::endl;
        } else if(widthStr[widthStrLen - 1] == '%') {
            // percentage string
            float computedWidth = strtof(widthStr, NULL);
            
            YGNodeStyleSetWidthPercent(this->layoutBox, computedWidth);
//            std::cout << "Set width to: " << computedWidth << "%" << std::endl;
        } else if(widthStr[widthStrLen - 2] == 'p' && widthStr[widthStrLen - 1] == 'x') {
            // px string
            float computedWidth = strtof(widthStr, NULL);
            
            YGNodeStyleSetWidth(this->layoutBox, computedWidth);
//            std::cout << "Set width to: " << computedWidth << "px" << std::endl;
        }
        
        // height stuff (literally copied; could potentially shorten with va_args, but idk)
        int heightStrLen = strlen(heightStr);
        if(strncmp(heightStr, "auto", 4) == 0) {
            // auto keyword
            YGNodeStyleSetHeightAuto(this->layoutBox);
//            std::cout << "Set height to auto!" << std::endl;
        } else if(heightStr[heightStrLen - 1] == '%') {
            // percentage string
            float computedHeight = strtof(heightStr, NULL);
            
            YGNodeStyleSetHeightPercent(this->layoutBox, computedHeight + 20);
            
//            std::cout << "Set height to: " << computedHeight << "%" << std::endl;
        } else if(heightStr[heightStrLen - 2] == 'p' && heightStr[heightStrLen - 1] == 'x') {
            // px string
            float computedHeight = strtof(heightStr, NULL);
            
            YGNodeStyleSetHeight(this->layoutBox, computedHeight);
            
//            std::cout << "Set height to: " << computedHeight << "px" << std::endl;
        }
    }
    
    std::tuple<YGValue, YGValue> UIView::getSize() {
        YGValue width = YGNodeStyleGetWidth(this->layoutBox);
        YGValue height = YGNodeStyleGetHeight(this->layoutBox);
        
        return std::make_tuple(width, height);
    }
}
