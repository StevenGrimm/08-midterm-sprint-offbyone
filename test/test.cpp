#include <iostream>
#include "catch_amalgamated.hpp"
#include "../src/class_roster.h"

#define CONFIG_CATCH_MAIN

// vector<std::string> test_roster = {};

TEST_CASE("Roster functionality test", "[autograding]")
{

	SECTION("Valid Input")
	{
		auto [is_valid, validation_message] = ctch1330::ValidateUserInputWithinIntegerRange(1, 6, 3);
		REQUIRE(is_valid == true);
		REQUIRE(validation_message == "");
	}

	SECTION("Invalid Input")
	{
		auto [is_valid, validation_message] = ctch1330::ValidateUserInputWithinIntegerRange(1, 6, 9);
		REQUIRE(is_valid == false);
		REQUIRE(validation_message == "Please enter integer within the range of current roster");
	}

	

   
}	