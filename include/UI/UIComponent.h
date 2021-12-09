//
//  UIComponent.h
//  bahamutGUI
//
//  Created by lochnessdragon on 11/23/21.
//

#pragma once

#include <vector>
#include <Utils/Vector.h>
#include <yoga/YGNode.h>
#include <yoga/Yoga.h>
#include <Renderer/GUIRenderer.h>

namespace bGUI {
    /**
     * @brief Contains all the different edge options.
     * 
     */
    enum class EdgeType {
        All = YGEdgeAll,
        Top = YGEdgeTop,
        Bottom = YGEdgeBottom,
        Left = YGEdgeLeft,
        Right = YGEdgeRight,
    };


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
        //YGNode layoutBox;
        
        std::vector<UIComponent*> children;

        YGValue convertSizeStr(const char* sizeStr);

        // compute values (run by the rendering system)
        void computeLayout(float width, float height);
        // returns a rectangle represented as 2 vector2f to respresent the position and size
        std::tuple<Vector2f, Vector2f> getLayout();
        
    public:
        UIComponent();
        
        void appendChild(UIComponent* component);

        // sizing methods

        /// <summary>
        /// sets the size given two strings that are either auto, [number]px or [number]%
        /// For example:
        /// UIView view;
        /// view.setSize("100px", "50%");
        /// </summary>
        /// <param name="widthStr">A css like width style property, one of auto or [number]px or [number]%</param>
        /// <param name="heightStr">A css like height style property, one of auto or [number]px or [number]%</param>
        void setSize(const char* widthStr, const char* heightStr);
        std::tuple<YGValue, YGValue> getSize();

        // padding methods
        void setPadding(EdgeType edgeType, const char* paddingStr);
        YGValue getPadding(EdgeType edgeType);

        // margin methods
        void setMargin(EdgeType edgeType, const char* borderStr);
        YGValue getMargin(EdgeType edgeType);

        // border methods
        void setBorder(EdgeType edgeType, float borderSize);
        float getBorder(EdgeType edgeType);

        // renders the component by returning a list of render commands.
        virtual void render(GUIRenderer* renderer);
    };
}
