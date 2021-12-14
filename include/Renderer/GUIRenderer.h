#pragma once

#include <functional>
#include <glm/glm.hpp>
#include <UI/Window/WindowHint.h>
#include <UI/UIImage.h>

namespace bGUI {
	class GUIRenderer;

	class GUIRenderer {
	public:
		//static GUIRenderer* get(UIWindow* window);

		// callback methods (for window updates)
		virtual void resizeFrame(int width, int height) = 0;
        
		/// --- Render Methods ---

		virtual void prepareScene() = 0;

		/// Rectangles
		virtual void renderRect(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color) = 0;
		virtual void renderImage(const glm::vec2& position, const glm::vec2& size, const UIImage* image, const glm::vec4& overlayColor = glm::vec4(1.0f, 1.0f, 1.0f, 0.0f)) = 0;

		virtual void endScene() = 0;
	};
}
