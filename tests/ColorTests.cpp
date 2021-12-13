#include "catch_amalgamated.hpp"

#include <Utils/Color.h>

TEST_CASE("Color conversion from hsl returns proper rgb values", "[Color HSV to RGB test]") {
    
    float r = (float) 135 / (float) 255;
    float g = (float) 43 / (float) 255;
    float b = (float) 255 / (float) 255;
    glm::vec3 color = bGUI::ColorUtils::convertHSLtoRGB(266, 1.0, 0.584);

    REQUIRE(r == color.r);
    REQUIRE(g == color.g);
    REQUIRE(b == color.b);
}