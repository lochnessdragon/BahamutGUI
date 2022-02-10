#include <Platform/OpenGL/GLGUIRenderer.h>

#include <Platform/OpenGL/GLBackend.h>

namespace bGUI {
	namespace GLBackend {
		GLGUIRenderer::GLGUIRenderer(glm::ivec2 windowSize) : currentSize(windowSize) {
			glViewport(0, 0, currentSize.x, currentSize.y);
			glClearColor(1, 1, 1, 1);
		}

		// todo: add high DPI support!
		void GLGUIRenderer::beginFrame() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			nvgBeginFrame(GLBackend::singleton()->getRenderContext(), (float) currentSize.x, (float) currentSize.y, 1); // DPI is set to 1, i.e. one pixel translates to one actual pixel
		}

		void GLGUIRenderer::resizeFrame(int width, int height) {
			glViewport(0, 0, width, height);
			currentSize = glm::ivec2(width, height);
		}
		
		void GLGUIRenderer::endFrame() {
			nvgEndFrame(GLBackend::singleton()->getRenderContext());
		}
	}
}