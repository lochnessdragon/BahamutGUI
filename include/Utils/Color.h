#pragma once

#include "Vector.h"

namespace bGUI {
	class ColorUtils {
	public:
		// assumes hsl values are between 0.0 and 1.0
		static Vector3f convertHSLtoRGB(float h, float s, float l);
		// takes in a hexadecimal number expressed as a string and converts it to rgb.
		static Vector3f convertHEXtoRGB(const char* hexcode);
		static Vector3f convertHEXtoRGB(const int hexcode);
	};
}