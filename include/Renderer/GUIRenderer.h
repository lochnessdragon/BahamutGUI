#pragma once

#include <UI/UIWindow.h>
#include <UI/UIComponent.h>
#include "Commands/RenderCommand.h"
#include <functional>

namespace bGUI {
	class GUIRenderer {
	private:
		static std::function<GUIRenderer* ()>& builder;

	public:
		//static GUIRenderer* get(UIWindow* window);
        
		/// <summary>
		/// Sets the GUI Renderer that'll be used for new windows.
		/// </summary>
		static void setRendererBuilder(std::function<GUIRenderer* ()>& builder) { GUIRenderer::builder = builder; };
		static GUIRenderer* makeRenderer() { return builder(); };

		virtual void getWindowInitFlags() = 0;
        virtual void renderUI(std::vector<RenderCommand> &commands) = 0;
	};
}
