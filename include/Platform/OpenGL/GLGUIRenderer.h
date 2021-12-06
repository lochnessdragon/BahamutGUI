#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Renderer/GUIRenderer.h>
#include "GLShader.h"

namespace bGUI
{
	namespace GLBackend
	{
		class GLGUIRenderer : public GUIRenderer
		{
		public:
			GLGUIRenderer();

			void resizeFrame(int width, int height);

			void prepareScene();

			void renderRect(const Vector2f &position, const Vector2f &size, const Vector4f &color);

			void endScene();

		private:
			GLShader rectShader;

			//static void resizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
		};
	}
}
