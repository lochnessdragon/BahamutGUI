#include "catch_amalgamated.hpp"

#include <UI/UILabel.h>

/**
 * @brief Check that inner text updates properly for the UILabel
 * 
 */
TEST_CASE("UILabel text updates properly", "[UILabel sizing]") {
    bGUI::UILabel testLabel;

    const char* testStr = "Test string 1234";

    testLabel.setText(testStr);

    REQUIRE(testLabel.getString().compare(testStr) == 0);
}