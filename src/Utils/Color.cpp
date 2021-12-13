#include <Utils/Color.h>

#include <string>
#include <math.h>
#include <functional>
#include <iostream>
#include <glm/gtx/string_cast.hpp>

namespace bGUI {
	/*
	* Formula:
	*  https://en.wikipedia.org/wiki/HSL_and_HSV#HSL_to_RGB_alternative
	*/
	glm::vec3 ColorUtils::convertHSLtoRGB(float h, float s, float l)
	{
		glm::vec3 color; // needs to be between 0.0 and 1.0

		auto special_func = [] (float n, float a, float hue, float lightness ) -> float {
			float k = ((int) (n + (hue/30))) % 12;
			
			return lightness - (a * (std::max(-1.0f, std::min(k - 3, std::min(9 - k, 1.0f)))));
		};

		float a = s * std::min(l, 1 - l);

		color.r = special_func(0, a, h, l);
		color.g = special_func(8, a, h, l);
		color.b = special_func(4, a, h, l);

		std::cout << "HSL: " << h << ", " << s << ", " << l << " was converted to: " << glm::to_string(color) << std::endl;

		return color;
	}

	glm::vec3 ColorUtils::convertHEXtoRGB(const char* hexcode)
	{
		float r, g, b;

		return {r, g, b};
	}

	glm::ivec3 ColorUtils::convertHEXtoRGB(const int hexcode)
	{
		return glm::ivec3();
	}
}