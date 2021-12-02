// UI View tests
#include "catch_amalgamated.hpp"

#include <Utils/Vector.h>

/**
 * Check that the sizes properly update in UIView
 */
TEST_CASE("Vectors working properly", "[Vector data]") {
	bGUI::Vector2f vector2fTest = {2.5f, 3.7f};

	REQUIRE(vector2fTest.x == 2.5f);
	REQUIRE(vector2fTest.y == 3.7f);

	bGUI::Vector2i vector2iTest = { 7, 211 };

	REQUIRE(vector2iTest.x == 7);
	REQUIRE(vector2iTest.y == 211);

	bGUI::Vector3f vector3fTest = { 102.67f, 6.25f, 10.11f };

	REQUIRE(vector3fTest.x == 102.67f);
	REQUIRE(vector3fTest.y == 6.25f);
	REQUIRE(vector3fTest.z == 10.11f);

	bGUI::Vector3i vector3iTest = { 1412, 123, 678 };

	REQUIRE(vector3iTest.x == 1412);
	REQUIRE(vector3iTest.y == 123);
	REQUIRE(vector3iTest.z == 678);

	bGUI::Vector4f vector4fTest = { 907.24f, 789.12f, 67.1f, 9.3f };

	REQUIRE(vector4fTest.x == 907.24f);
	REQUIRE(vector4fTest.y == 789.12f);
	REQUIRE(vector4fTest.z == 67.1f);
	REQUIRE(vector4fTest.w == 9.3f);

	bGUI::Vector4i vector4iTest = { 54, 5678, 1245, 907};

	REQUIRE(vector4iTest.x == 54);
	REQUIRE(vector4iTest.y == 5678);
	REQUIRE(vector4iTest.z == 1245);
	REQUIRE(vector4iTest.w == 907);
}