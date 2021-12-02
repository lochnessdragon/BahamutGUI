// UI View tests
#include "catch_amalgamated.hpp"

#include <UI/UIView.h>

/**
 * Check that the sizes properly update in UIView
 */
TEST_CASE("UIView sizing updates properly", "[UIView sizing]") {
    bGUI::UIView testingView = bGUI::UIView();
    
    testingView.setSize("auto", "auto");
    std::tuple<YGValue, YGValue> sizes = testingView.getSize();
    
    REQUIRE(std::get<0>(sizes).unit == YGUnitAuto);
    REQUIRE(std::get<1>(sizes).unit == YGUnitAuto);
    
    testingView.setSize("100.5px", "45.6%");
    sizes = testingView.getSize();
    
    REQUIRE(std::get<0>(sizes).value == 100.5f);
    REQUIRE(std::get<0>(sizes).unit == YGUnitPoint);
    REQUIRE(std::get<1>(sizes).value == 45.6f);
    REQUIRE(std::get<1>(sizes).unit == YGUnitPercent);
    
    testingView.setSize("93.7%", "245px");
    sizes = testingView.getSize();
    
    REQUIRE(std::get<0>(sizes).value == 93.7f);
    REQUIRE(std::get<0>(sizes).unit == YGUnitPercent);
    REQUIRE(std::get<1>(sizes).value == (float) 245);
    REQUIRE(std::get<1>(sizes).unit == YGUnitPoint);

    // invalid sizes should fail to update the view
    testingView.setSize("patuo", "98123^");
    sizes = testingView.getSize();
    REQUIRE(std::get<0>(sizes).value == 93.7f);
    REQUIRE(std::get<0>(sizes).unit == YGUnitPercent);
    REQUIRE(std::get<1>(sizes).value == (float)245);
    REQUIRE(std::get<1>(sizes).unit == YGUnitPoint);
}
