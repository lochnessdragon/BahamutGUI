#include <Renderer/GUIRenderer.h>

#include <Platform/OpenGL/GLGUIRenderer.h>

namespace bGUI {
	static std::function<GUIRenderer*(UIWindow*)> defaultBuilder = [](UIWindow* window) { return new GLGUIRenderer(window); };
	
	std::function<GUIRenderer* (UIWindow*)>& GUIRenderer::builder = defaultBuilder;
}
