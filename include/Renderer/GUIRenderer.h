#pragma once

#include <Window/Window.h>
#include <UI/UIComponent.h>

namespace bGUI {
	enum class BackendAPI {
		OpenGL
	};

	class GUIRenderer {
	public:
		static GUIRenderer* get(Window* window);

		static BackendAPI backendAPI;
        
        virtual void renderUI(UIComponent& component) = 0;
	};
}
