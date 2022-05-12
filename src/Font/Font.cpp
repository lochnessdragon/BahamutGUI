#include "Font/Font.h"
#include <iostream>

namespace bGUI {
	Font Font::DEFAULT_FONT;

	Font::Font(NVGcontext* context, std::string id, std::string filename) : name(id) {
		handle = nvgCreateFont(context, id.c_str(), filename.c_str());
		if (handle == -1) {
			std::cout << "Failed to load font file: " << filename << std::endl;

			exit(1);
		}
	}

	void Font::loadDefaultFont(NVGcontext* context) {
		DEFAULT_FONT = Font(context, "arial", "C:/Windows/Fonts/arial.ttf");
	}
}