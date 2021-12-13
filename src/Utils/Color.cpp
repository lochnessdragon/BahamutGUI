#include <Utils/Color.h>

#include <string>
#include <math.h>
#include <functional>

namespace bGUI {
	/*
	* Formula:
	*  https://en.wikipedia.org/wiki/HSL_and_HSV#HSL_to_RGB_alternative
	*/
	glm::vec3 ColorUtils::convertHSLtoRGB(float h, float s, float l)
	{
		float r, g, b; // needs to be between 0.0 and 1.0

		auto special_func = [] (float n, float a, float hue, float lightness ) -> float {
			float k = ((int) (n + (hue/30))) % 12;
			
			return lightness - (a * (std::max(-1.0f, std::min(k - 3, std::min(9 - k, 1.0f)))));
		};

		float a = s * std::min(l, 1 - l);

		r = special_func(0, a, h, l);
		g = special_func(8, a, h, l);
		b = special_func(4, a, h, l);

		return {r, g, b};
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