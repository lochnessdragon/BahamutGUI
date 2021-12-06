#pragma once

#include <functional>
#include <Utils/Vector.h>
#include <UI/Window/WindowHint.h>

namespace bGUI {
	class GUIRenderer;

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

		virtual const WindowHint* getWindowInitFlags(int* size) = 0;
		virtual void postInit() = 0;

		// callback methods (for window updates)
		virtual void resizeFrame(int width, int height) = 0;
        
		/// --- Render Methods ---

		virtual void prepareScene() = 0;

		virtual void renderRect(const Vector2f& position, const Vector2f& size, const Vector4f& color) = 0;

		virtual void endScene() = 0;
	};
}
