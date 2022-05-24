//
//  UIComponent.h
//  bahamutGUI
//
//  Created by lochnessdragon on 11/23/21.
//

#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <yoga/YGNode.h>
#include <yoga/Yoga.h>
//#include <Renderer/GUIRenderer.h>
#include <nanovg.h>

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

    enum class PositionType {
        Absolute = YGPositionTypeAbsolute,
        Relative = YGPositionTypeRelative,
        Static = YGPositionTypeStatic,
    };

    enum class JustifyType {
        Center = YGJustifyCenter,
        FlexEnd = YGJustifyFlexEnd,
        FlexStart = YGJustifyFlexStart,
        SpaceAround = YGJustifySpaceAround,
        SpaceBetween = YGJustifySpaceBetween,
        SpaceEvenly = YGJustifySpaceEvenly,
    };

    enum class AlignmentType {
        Auto = YGAlignAuto,
        Center = YGAlignCenter,
        Baseline = YGAlignBaseline,
        FlexStart = YGAlignFlexStart,
        FlexEnd = YGAlignFlexEnd,
        SpaceAround = YGAlignSpaceAround,
        SpaceBetween = YGAlignSpaceBetween,
        Stretch = YGAlignStretch,
    };

    enum class FlexWrapType {
        NoWrap = YGWrapNoWrap,
        Wrap = YGWrapWrap,
        WrapReverse = YGWrapWrapReverse,
    };

    enum class FlexDirection {
        Column = YGFlexDirectionColumn,
        ColumnReverse = YGFlexDirectionColumnReverse,
        Row = YGFlexDirectionRow,
        RowReverse = YGFlexDirectionRowReverse,
    };

    enum class Direction {
        LTR = YGDirectionLTR,
        RTL = YGDirectionRTL,
        Inherit = YGDirectionInherit,
    };


    /**
     * UIComponent:
     *  - Manages and maintains children.
     *  - Base class for any and all UI elements.
     *  - UIView is the base class for graphical elements (e.g. sliders, labels, buttons, etc.)
     * - This class just manages YogaLayout basics.
     */
    class UIComponent {
		private:
			UIComponent* parent;
    protected:
    	YGNodeRef layoutBox;

			// parenting methods 
			void setParent(UIComponent* component) { this->parent = component; };
			UIComponent* getParent() { return parent; };
			
			std::vector<UIComponent*> children;

			YGValue convertSizeStr(const char* sizeStr);

			// compute values (run by the rendering system)
			void computeLayout(float width, float height);
			// returns a rectangle represented as 2 vector2f to respresent the position and size
			std::tuple<glm::vec2, glm::vec2> getLayout();
        
    public:
        UIComponent();
        
        void appendChild(UIComponent* component);

        // layout methods
        void setJustification(JustifyType type);
        JustifyType getJustification();

        // alignment methods
        void setAlignContent(AlignmentType type);
        AlignmentType getAlignContent();

        void setAlignSelf(AlignmentType type);
        AlignmentType getAlignSelf();

        void setAlignItems(AlignmentType type);
        AlignmentType getAlignItems();

        // flex methods
        void setFlexWrap(FlexWrapType type);
        FlexWrapType getFlexWrap();

        void setFlexDirection(FlexDirection direction) { YGNodeStyleSetFlexDirection(this->layoutBox, (YGFlexDirection) direction); };
        FlexDirection getFlexDirection() { return (FlexDirection) YGNodeStyleGetFlexDirection(this->layoutBox); };

        // layout direction
        void setLayoutDirection();
        Direction getLayoutDirection();

        // flex grow
        void setFlexGrow(float grow) { YGNodeStyleSetFlexGrow(this->layoutBox, grow); };
        float getFlexGrow() { return YGNodeStyleGetFlexGrow(this->layoutBox); };

        // flex shrink
        void setFlexShrink(float shrink) { YGNodeStyleSetFlexShrink(this->layoutBox, shrink); };
        float getFlexShrink() { return YGNodeStyleGetFlexShrink(this->layoutBox); };

        // flex basis
        void setFlexBasis(const char* basis);
        YGValue getFlexBasis() { return YGNodeStyleGetFlexBasis(this->layoutBox); };

        // position methods
        void setPositionType(PositionType type);
        PositionType getPositionType();
        void setPositionFromEdge(EdgeType type, const char* position);
        YGValue getPositionFromEdge(EdgeType type);

        // aspect ratio
        void setAspectRatio(float ratio);
        float getAspectRatio();

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

        void setMinSize(const char* widthStr, const char* heightStr);
        std::tuple<YGValue, YGValue> getMinSize();

        void setMaxSize(const char* widthStr, const char* heightStr);
        std::tuple<YGValue, YGValue> getMaxSize();

        // padding methods
        void setPadding(EdgeType edgeType, const char* paddingStr);
        YGValue getPadding(EdgeType edgeType);

        // margin methods
        void setMargin(EdgeType edgeType, const char* borderStr);
        YGValue getMargin(EdgeType edgeType);

        // border methods
        void setBorderSize(EdgeType edgeType, float borderSize);
        float getBorderSize(EdgeType edgeType);

		// returns the proper offset from 0,0 for window positioning.
		glm::vec2 getParentPosition() { 
			if(parent != NULL) {
				return parent->getParentPosition() + std::get<0>(parent->getLayout());
			} else {
				return glm::vec2(0, 0); // default position is 0, 0. 
			}
		};

        // render the component using nano vg and a rendercontext
        virtual void render(NVGcontext* renderContext);
    };
}
