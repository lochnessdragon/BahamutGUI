#pragma once

#include <Renderer/GUIRenderer.h>

namespace bGUI {
	class GLGUIRenderer : public GUIRenderer {
	public:
		GLGUIRenderer(UIWindow* window);

        void renderUI(std::vector<RenderCommand>& commands);
        
	private:
		static bool __initialized;
		static void init();
        
        static void resizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height);}
        
        void prepareScene();
        void endScene();
        
        UIWindow* window;
	};
}
