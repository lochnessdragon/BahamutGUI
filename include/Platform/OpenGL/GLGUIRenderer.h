#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Renderer/GUIRenderer.h>

namespace bGUI {
	class GLGUIRenderer : public GUIRenderer {
	private:
		static const WindowHint hints[];
	
	public:
		GLGUIRenderer();

        const WindowHint* getWindowInitFlags(int* size);
		void postInit();

		void resizeFrame(int width, int height);

		void prepareScene();

		void renderRect(const Vector2f& position, const Vector2f& size, const Vector4f& color);

        void endScene();
        
	private:
        
        //static void resizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
	};
}
