#include <Platform/OpenGL/GLGUIRenderer.h>

#include <Platform/OpenGL/GLBackend.h>

namespace bGUI {
	namespace GLBackend {
		GLGUIRenderer::GLGUIRenderer(glm::ivec2 windowSize) : currentSize(windowSize) {
			glViewport(0, 0, currentSize.x, currentSize.y);
			glClearColor(1, 1, 1, 1);
		}

		GLGUIRenderer::~GLGUIRenderer() {
		}

		const char* GLGUIRenderer::getErrorStr(GLenum error) {
			switch (error) {
				case GL_NO_ERROR:          return "No error";
				case GL_INVALID_ENUM:      return "Invalid enum";
				case GL_INVALID_VALUE:     return "Invalid value";
				case GL_INVALID_OPERATION: return "Invalid operation";
				case GL_STACK_OVERFLOW:    return "Stack overflow";
				case GL_STACK_UNDERFLOW:   return "Stack underflow";
				case GL_OUT_OF_MEMORY:     return "Out of memory";
				default:                   return "Unknown error";
			}
		}

		void GLGUIRenderer::checkError(const char* filename, const char* function) {
			while (true) {
				const GLenum error = glGetError();
				if (error == GL_NO_ERROR)
					break;

				std::cout << "GL Error in " << filename << " at " << function << ": " << getErrorStr(error) << std::endl;
			}
		}

		// todo: add high DPI support!
		void GLGUIRenderer::beginFrame(NVGcontext* renderContext) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			checkError("GLGUIRenderer", "beginFrame");
			nvgBeginFrame(renderContext, (float) currentSize.x, (float) currentSize.y, 1); // DPI is set to 1, i.e. one pixel translates to one actual pixel
		}

		void GLGUIRenderer::resizeFrame(int width, int height) {
			glViewport(0, 0, width, height);
			currentSize = glm::ivec2(width, height);
		}
		
		void GLGUIRenderer::endFrame(NVGcontext* renderContext) {
			checkError("GLGUIRenderer", "endFrame");
			nvgEndFrame(renderContext);
		}
	}
}