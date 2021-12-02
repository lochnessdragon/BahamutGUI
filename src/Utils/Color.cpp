#include <Utils/Color.h>

#include <string>
#include <math.h>

namespace bGUI {
	Vector3i ColorUtils::convertHSLtoRGB(float h, float s, float l)
	{
		int r, g, b;

		float chroma = (1 - abs((2 * l) - 1)) * s;



		return {r, g, b};
	}

	Vector3i ColorUtils::convertHEXtoRGB(const char* hexcode)
	{
		int r, g, b;
		return {r, g, b};
	}
}