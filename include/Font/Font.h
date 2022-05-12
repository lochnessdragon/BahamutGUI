#pragma once

#include <string>
#include <nanovg.h>

namespace bGUI {
	class Font {
	private:
		int handle;
		std::string name;

		Font(): handle(-1), name("INVALID") {} // used for default font initialization
	public:
		Font(NVGcontext* context, std::string id, std::string filename);

		static Font DEFAULT_FONT;

		static void loadDefaultFont(NVGcontext* context);

		int getHandle() { return handle; }
		std::string getName() { return name; }
	};
}