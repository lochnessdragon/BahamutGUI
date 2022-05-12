#include <Platform/OpenGL/GLGUIRenderer.h>

#include <Platform/OpenGL/GLBackend.h>

#define NANOVG_GL3_IMPLEMENTATION
#include <nanovg_gl.h>

namespace bGUI {
	namespace GLBackend {
		int GLGUIRenderer::instanceCount = 0;
		NVGcontext* GLGUIRenderer::renderContext = NULL;

		GLGUIRenderer::GLGUIRenderer(glm::ivec2 windowSize) : currentSize(windowSize) {
			glViewport(0, 0, currentSize.x, currentSize.y);
			glClearColor(1, 1, 1, 1);

			if (instanceCount == 0) {
				puts("Creating NanoVG context");
				renderContext = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);
				if (!renderContext) {
					std::cout << "Failed to load NanoVG context!" << std::endl;
					exit(-1);
				}
			}

			instanceCount++;
		}

		GLGUIRenderer::~GLGUIRenderer() {
			instanceCount--;
			if(instanceCount == 0)
				nvgDeleteGL3(renderContext);
		}

		// todo: add high DPI support!
		void GLGUIRenderer::beginFrame() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			nvgBeginFrame(renderContext, (float) currentSize.x, (float) currentSize.y, 1); // DPI is set to 1, i.e. one pixel translates to one actual pixel
		}

		void GLGUIRenderer::resizeFrame(int width, int height) {
			glViewport(0, 0, width, height);
			currentSize = glm::ivec2(width, height);
		}
		
		void GLGUIRenderer::endFrame() {
			nvgEndFrame(renderContext);
		}

		NVGcontext* GLGUIRenderer::getRenderContext() {
			return renderContext;
		}
	}
}