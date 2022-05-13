#include "Font/Font.h"
#include <iostream>

#include <Renderer/Backend.h>

namespace bGUI {
	Font::Font(std::string id, std::string filename) : name(id) {
		handle = nvgCreateFont(Backend::getBackend()->getOrCreateContext(), id.c_str(), filename.c_str());
		if (handle == -1) {
			std::cout << "Failed to load font file: " << filename << std::endl;

			exit(1);
		}
	}
}