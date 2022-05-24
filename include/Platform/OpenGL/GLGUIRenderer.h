#pragma once

#include <Renderer/GUIRenderer.h>

#include <glm/glm.hpp>

namespace bGUI {
	namespace GLBackend {
		class GLGUIRenderer : public GUIRenderer {
		private:
			glm::ivec2 currentSize;

			const char* getErrorStr(GLenum error);
			void checkError(const char* filename, const char* function);
		public:
			GLGUIRenderer(glm::ivec2 windowSize);
			~GLGUIRenderer();

			void beginFrame(NVGcontext* renderContext) override;
			void resizeFrame(int width, int height) override;
			void endFrame(NVGcontext* renderContext) override;
		};
	}
}