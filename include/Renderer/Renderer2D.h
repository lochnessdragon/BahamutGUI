#pragma once

#include <Window/Window.h>

namespace bGUI {
	enum class BackendAPI {
		OpenGL
	};

	class Renderer2D {
	public:
		static Renderer2D* get(Window* window);

		static BackendAPI backendAPI;
	};
}