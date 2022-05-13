#pragma once

#include <string>
#include <nanovg.h>

namespace bGUI {
	class Font {
	private:
		int handle;
		std::string name;
	public:
		Font(std::string id, std::string filename);

		int getHandle() { return handle; }
		std::string getName() { return name; }
	};
}