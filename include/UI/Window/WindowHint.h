# pragma once

// this splintered out of the uiwindow.h file so that I can include it in renderers without having to include the full uiwindow file

namespace bGUI {
    struct WindowHint {
		int hint, value;

		WindowHint(int hint, int value) : hint(hint), value(value) {};
	};
}