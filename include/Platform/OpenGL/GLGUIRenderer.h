#pragma once

#include <Renderer/GUIRenderer.h>

#include <glm/glm.hpp>

namespace bGUI {
	namespace GLBackend {
		class GLGUIRenderer : public GUIRenderer {
		private:
			glm::ivec2 currentSize;
			static NVGcontext* renderContext;

			static int instanceCount;
		public:
			GLGUIRenderer(glm::ivec2 windowSize);
			~GLGUIRenderer();

			void beginFrame() override;
			void resizeFrame(int width, int height) override;
			void endFrame() override;
			NVGcontext* getRenderContext() override;
		};
	}
}