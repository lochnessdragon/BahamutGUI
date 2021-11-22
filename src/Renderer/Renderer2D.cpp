#include <Renderer/Renderer2D.h>

#include <Platform/OpenGL/GLRenderer2D.h>

namespace bGUI {
	BackendAPI Renderer2D::backendAPI = BackendAPI::OpenGL;

	Renderer2D* Renderer2D::get(Window* window) {
		switch (Renderer2D::backendAPI) {
		case BackendAPI::OpenGL:
			return new GLRenderer2D(window);
			break;
    default:
      return new GLRenderer2D(window);
      break;
		}
	}
}