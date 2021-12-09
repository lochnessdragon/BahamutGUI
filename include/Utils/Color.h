#pragma once

#include <glm/glm.hpp>

namespace bGUI {
	class ColorUtils {
	public:
		// assumes hsl values are between 0.0 and 1.0
		static glm::ivec3 convertHSLtoRGB(float h, float s, float l);
		// takes in a hexadecimal number expressed as a string and converts it to rgb.
		static glm::ivec3 convertHEXtoRGB(const char* hexcode);
		static glm::ivec3 convertHEXtoRGB(const int hexcode);
	};
}