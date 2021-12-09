#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Renderer/GUIRenderer.h>
#include <UI/UIWindow.h>
#include "GLShader.h"
#include "GLRectDefaultShader.h"
#include "GLVAO.h"

namespace bGUI
{
	namespace GLBackend
	{
		class GLGUIRenderer : public GUIRenderer
		{
		public:
			GLGUIRenderer(::bGUI::UIWindow* window);

			void resizeFrame(int width, int height);

			void prepareScene();

			void renderRect(const Vector2f &position, const Vector2f &size, const Vector4f &color);

			void endScene();

			bool windowResizeCallback(const ::bGUI::WindowResizeData& data);
			bool keyCallback(const ::bGUI::KeyEventData& data); 

			void toggleWireframe()
			{
				if (!wireframe)
				{
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
					wireframe = true;
				}
				else
				{
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
					wireframe = false;
				}
			};

			static void checkGLErrors();

		private:
			GLRectDefaultShader rectShader;
			GLVAO rectangleObj;

			bool wireframe = false;

			void draw();

			//static void resizeCallback(GLFWwindow* window, int width, int height) { glViewport(0, 0, width, height); }
		};
	}
}
