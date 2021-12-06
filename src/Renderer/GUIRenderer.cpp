#include <Renderer/GUIRenderer.h>

#include <Platform/OpenGL/GLGUIRenderer.h>

namespace bGUI {
	static std::function<GUIRenderer*()> defaultBuilder = []() { return new GLGUIRenderer(); };
	
	std::function<GUIRenderer* ()>& GUIRenderer::builder = defaultBuilder;
}
