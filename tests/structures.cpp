#include "catch.hpp"
#include <wolf/quickfill.hpp>

TEST_CASE("quick fill vector", "Structs") {
    auto storage = wolf::structs::QuickFill<int>(10, 5);
    REQUIRE(storage[5] == 5);
    storage[3] = 4;
    storage[9] = 1;
    REQUIRE(storage[3] == 4);
    storage.fill(9);
    REQUIRE(storage[9] == 9);
}
