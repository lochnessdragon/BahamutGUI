#pragma once

#include <Renderer/Renderer2D.h>

namespace bGUI {
	class GLRenderer2D : public Renderer2D {
	public:
		GLRenderer2D(Window* window);

	private:
		static bool __initialized;
		static void init();
	};
}