#include "catch.hpp"
#include <wolf/quickfill.hpp>

TEST_CASE("quick fill vector", "[structs]") {
    auto storage = wolf::structs::QuickFill<int>(10, 5);
    REQUIRE(storage[5] == 5);
    storage[3] = 4;
    storage[9] = 1;
    REQUIRE(storage[3] == 4);
    storage.fill(9);
    REQUIRE(storage[9] == 9);
}

TEST_CASE("quick fill vector of bool", "[structs]") {
    auto storage = wolf::structs::QuickFill<bool>(10, false);
    REQUIRE(storage[5] == false);
    storage[3] = true;
    storage[9] = true;
    REQUIRE(storage[3] == true);
    storage.fill(false);
    REQUIRE(storage[9] == false);
}
