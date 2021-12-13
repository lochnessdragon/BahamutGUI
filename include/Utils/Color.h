#pragma once

#include <glm/glm.hpp>

namespace bGUI {
	class ColorUtils {
	public:
		// assumes h is an angle between 0 and 360
		// s is between 0.0 and 1.0
		// l is between 0.0 and 1.0
		static glm::vec3 convertHSLtoRGB(float h, float s, float l);
		// takes in a hexadecimal number expressed as a string and converts it to rgb. (not rgba)
		static glm::vec3 convertHEXtoRGB(const char* hexcode);
		static glm::ivec3 convertHEXtoRGB(const int hexcode);
	};
}