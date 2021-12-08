#include "catch_amalgamated.hpp"

#include <Utils/Color.h>

TEST_CASE("Color conversion from hsl returns proper rgb values", "[Color HSV to RGB test]") {
    
    Vector3i color = bGUI::ColorUtils::convertHSLtoRGB(1, 1, 1);

}