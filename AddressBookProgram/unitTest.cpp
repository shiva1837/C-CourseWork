#define CATCH_CONFIG_MAIN  

#include <string>
#include "/export/home/public/zhang/catch.hpp"
#include "extPersonType.h"



TEST_CASE("Test extPersonType class", "[extPersonType]")
{
    // Create an extPersonType object and set its information
    extPersonType person;
    person.setInfo("John", "Doe", 5, 10, 1990, "123 Main St", "City", "State", "12345", "555-1234", "Student");


    SECTION("Test isLastName() function")
    {
        // Check if last name matches
        REQUIRE(person.isLastName("Doe") == true);
        REQUIRE(person.isLastName("Smith") == false);
    }

    SECTION("Test getAddress() function")
    {
        // Check if address information matches
        string street, city, state, zip;
        person.getAddress(street, city, state, zip);
        REQUIRE(street == "123 Main St");
        REQUIRE(city == "City");
        REQUIRE(state == "State");
        REQUIRE(zip == "12345");
    }

    SECTION("Test isStatus() function")
    {
        // Check if person status matches
        REQUIRE(person.isStatus("Student") == true);
        REQUIRE(person.isStatus("Teacher") == false);
    }

    SECTION("Test getPhoneNumber() function")
    {
        // Check if phone number matches
        REQUIRE(person.getPhoneNumber() == "555-1234");
    }

    SECTION("Test isDOB() function")
    {
        // Check if date of birth matches
        REQUIRE(person.isDOB(5, 10, 1990) == true);
        REQUIRE(person.isDOB(1, 1, 2000) == false);
    }

    SECTION("Test getDOB() function")
    {
        // Check if date of birth information matches
        int month, day, year;
        person.getDOB(month, day, year);
        REQUIRE(month == 5);
        REQUIRE(day == 10);
        REQUIRE(year == 1990);
    }

    SECTION("Test isMonth() function")
    {
        // Check if birth month matches
        REQUIRE(person.isMonth(5) == true);
        REQUIRE(person.isMonth(1) == false);
    }

}





