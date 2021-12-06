#include <Renderer/GUIRenderer.h>

#include <Platform/OpenGL/GLBackend.h>

namespace bGUI {
	Backend* Backend::backend = new GLBackend::GLBackend();
}
