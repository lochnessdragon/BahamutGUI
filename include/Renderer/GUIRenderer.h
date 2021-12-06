#pragma once

#include <functional>
#include <Utils/Vector.h>
#include <UI/Window/WindowHint.h>

namespace bGUI {
	class GUIRenderer;

	class GUIRenderer {
	public:
		//static GUIRenderer* get(UIWindow* window);

		// callback methods (for window updates)
		virtual void resizeFrame(int width, int height) = 0;
        
		/// --- Render Methods ---

		virtual void prepareScene() = 0;

		virtual void renderRect(const Vector2f& position, const Vector2f& size, const Vector4f& color) = 0;

		virtual void endScene() = 0;
	};
}
