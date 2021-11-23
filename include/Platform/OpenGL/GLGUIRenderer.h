#pragma once

#include <Renderer/GUIRenderer.h>

namespace bGUI {
	class GLGUIRenderer : public GUIRenderer {
	public:
		GLGUIRenderer(Window* window);

        void renderUI(UIComponent& component);
        
	private:
		static bool __initialized;
		static void init();
        
        static void resizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height);}
        
        void prepareScene();
	};
}
