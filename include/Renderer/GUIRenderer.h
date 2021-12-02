#pragma once

#include <UI/UIWindow.h>
#include <UI/UIComponent.h>
#include "Commands/RenderCommand.h"

namespace bGUI {
	enum class BackendAPI {
		OpenGL
	};

	class GUIRenderer {
	public:
		static GUIRenderer* get(UIWindow* window);

		static BackendAPI backendAPI;
        
        virtual void renderUI(std::vector<RenderCommand> &commands) = 0;
	};
}
