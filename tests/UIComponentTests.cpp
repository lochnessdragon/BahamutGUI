#include "catch_amalgamated.hpp"

#include <UI/UIComponent.h>

/**
 * Check that the sizes properly update in UIView
 */
TEST_CASE("UIComponent sizing updates properly", "[UIComponent sizing]") {
    bGUI::UIComponent testingComponent = bGUI::UIComponent();
    
    testingComponent.setSize("auto", "auto");
    std::tuple<YGValue, YGValue> sizes = testingComponent.getSize();
    
    REQUIRE(std::get<0>(sizes).unit == YGUnitAuto);
    REQUIRE(std::get<1>(sizes).unit == YGUnitAuto);
    
    testingComponent.setSize("100.5px", "45.6%");
    sizes = testingComponent.getSize();
    
    REQUIRE(std::get<0>(sizes).value == 100.5f);
    REQUIRE(std::get<0>(sizes).unit == YGUnitPoint);
    REQUIRE(std::get<1>(sizes).value == 45.6f);
    REQUIRE(std::get<1>(sizes).unit == YGUnitPercent);
    
    testingComponent.setSize("93.7%", "245px");
    sizes = testingComponent.getSize();
    
    REQUIRE(std::get<0>(sizes).value == 93.7f);
    REQUIRE(std::get<0>(sizes).unit == YGUnitPercent);
    REQUIRE(std::get<1>(sizes).value == (float) 245);
    REQUIRE(std::get<1>(sizes).unit == YGUnitPoint);

    // invalid sizes should fail to update the view
    testingComponent.setSize("patuo", "98123^");
    sizes = testingComponent.getSize();
    REQUIRE(std::get<0>(sizes).value == 93.7f);
    REQUIRE(std::get<0>(sizes).unit == YGUnitPercent);
    REQUIRE(std::get<1>(sizes).value == (float)245);
    REQUIRE(std::get<1>(sizes).unit == YGUnitPoint);
}

/**
 * Test to check that the padding updates properly. 
 * 
 */
TEST_CASE("UIComponent padding updates properly", "[UIComponent Padding]") {
    bGUI::UIComponent testComponent = bGUI::UIComponent();

    testComponent.setPadding(bGUI::Border::Top, "20px");    

    REQUIRE(testComponent.getPadding(bGUI::Border::Top).unit == YGUnitPoint);
    REQUIRE(testComponent.getPadding(bGUI::Border::Top).value == 20);

    testComponent.setPadding(bGUI::Border::Left, "45%");
    REQUIRE(testComponent.getPadding(bGUI::Border::Top).unit == YGUnitPercent);
    REQUIRE(testComponent.getPadding(bGUI::Border::Top).value == 45);
}