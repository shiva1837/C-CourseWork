#define CATCH_CONFIG_MAIN
#include "/export/home/public/zhang/catch.hpp"
#include "complexType.h"
#include <sstream>
using namespace std;

TEST_CASE("Arithmetic Operators", "[complexType]") {
    complexType a(3, 2);
    complexType b(1, 7);

    SECTION("Addition") {
        complexType result = a + b;
        REQUIRE(result == complexType(4, 9));
    }

    SECTION("Subtraction") {
        complexType result = a - b;
        REQUIRE(result == complexType(2, -5));
    }

    SECTION("Multiplication") {
        complexType result = a * b;
        REQUIRE(result == complexType(-11, 23));
    }

    SECTION("Division") {
        complexType result = a / b;
        complexType expected(0.34, -0.38);
        REQUIRE(result == expected); // Depends on exact == behavior
    }

    SECTION("Division by zero") {
        complexType zero(0, 0);
        complexType result = a / zero;
        REQUIRE(result == a);
    }
}

TEST_CASE("Equality and Inequality", "[complexType]") {
    complexType a(3, 4);
    complexType b(3, 4);
    complexType c(4, 3);

    REQUIRE(a == b);
    REQUIRE_FALSE(a == c);
    REQUIRE(a != c);
    REQUIRE_FALSE(a != b);
}

TEST_CASE("Relational Operators (Magnitude-Based)", "[complexType]") {
    complexType a(3, 4);   // |a| = 5
    complexType b(6, 8);   // |b| = 10
    complexType c(3, 4);   // |c| = 5

    SECTION("< operator") {
        REQUIRE(a < b);
        REQUIRE_FALSE(b < a);
        REQUIRE_FALSE(a < c);
    }

    SECTION("<= operator") {
        REQUIRE(a <= b);
        REQUIRE(a <= c);
        REQUIRE_FALSE(b <= a);
    }

    SECTION("> operator") {
        REQUIRE(b > a);
        REQUIRE_FALSE(a > b);
        REQUIRE_FALSE(a > c);
    }

    SECTION(">= operator") {
        REQUIRE(b >= a);
        REQUIRE(a >= c);
        REQUIRE_FALSE(a >= b);
    }
}

TEST_CASE("Increment and Decrement Operators", "[complexType]") {
    SECTION("Pre-increment") {
        complexType c(2, 3);
        c = ++c;
        REQUIRE(c == complexType(3, 3));
    }

    SECTION("Post-increment") {
        complexType c(2, 3);
        complexType d = c++;
        REQUIRE(c == complexType(3, 3));
        REQUIRE(d == complexType(2, 3));
    }

    SECTION("Pre-decrement") {
        complexType c(2, 3);
        c = --c;
        REQUIRE(c == complexType(1, 3));
    }

    SECTION("Post-decrement") {
        complexType c(2, 3);
        complexType d = c--;
        REQUIRE(c == complexType(1, 3));
        REQUIRE(d == complexType(2, 3));
    }
}
