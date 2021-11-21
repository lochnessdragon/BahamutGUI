#pragma once

namespace bGUI {
	enum BackendAPI {
		OpenGL
	};

	class Renderer2D {
	public:
		static Renderer2D get();
	};
}