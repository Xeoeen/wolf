#include <wolf/logic.hpp>


TEST_CASE("all of binary operation","[logic]") {
    REQUIRE_FALSE(wolf::logic::allOf(true, true, false));
    REQUIRE(wolf::logic::allOf(true, true));
    REQUIRE(wolf::logic::allOf(true));
}

TEST_CASE("one of binary operation","[logic]") {
    REQUIRE_FALSE(wolf::logic::oneOf(false, false, false));
    REQUIRE(wolf::logic::oneOf(true, false));
}

TEST_CASE("none of binary operation","[logic]") {
    REQUIRE_FALSE(wolf::logic::noneOf(true, true, false));
    REQUIRE(wolf::logic::noneOf(false, false));
}
