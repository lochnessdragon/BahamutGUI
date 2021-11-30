#include <Renderer/GUIRenderer.h>

#include <Platform/OpenGL/GLGUIRenderer.h>

namespace bGUI {
	BackendAPI GUIRenderer::backendAPI = BackendAPI::OpenGL;

	GUIRenderer* GUIRenderer::get(UIWindow* window) {
		switch (GUIRenderer::backendAPI) {
		case BackendAPI::OpenGL:
			return new GLGUIRenderer(window);
			break;
    default:
      return new GLGUIRenderer(window);
      break;
		}
	}
}
