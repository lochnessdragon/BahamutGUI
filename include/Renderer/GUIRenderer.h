#pragma once

#include <nanovg.h>
#include <UI/UIWindow.h>

namespace bGUI {
	struct WindowResizeData;

	class GUIRenderer {
	public:
		virtual void beginFrame() = 0;
		virtual void resizeFrame(int width, int height) = 0;
		virtual void endFrame() = 0;

		virtual NVGcontext* getRenderContext() = 0;
	};
}