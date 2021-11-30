#pragma once

#include <UI/UIWindow.h>
#include <UI/UIComponent.h>

namespace bGUI {
	enum class BackendAPI {
		OpenGL
	};

	class GUIRenderer {
	public:
		static GUIRenderer* get(UIWindow* window);

		static BackendAPI backendAPI;
        
        virtual void renderUI(UIComponent& component) = 0;
	};
}
