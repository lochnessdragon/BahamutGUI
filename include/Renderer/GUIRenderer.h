#pragma once

#include <nanovg.h>
#include <UI/UIWindow.h>

namespace bGUI {
	struct WindowResizeData;

	class GUIRenderer {
	public:
		virtual void beginFrame(NVGcontext* renderContext) = 0;
		virtual void resizeFrame(int width, int height) = 0;
		virtual void endFrame(NVGcontext* renderContext) = 0;
	};
}