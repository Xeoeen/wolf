#include "catch.hpp"
#include <wolf/math.hpp>

TEST_CASE("sum","[math]") {
    REQUIRE(wolf::math::sum(1, 2, 3) == 6);
    REQUIRE(wolf::math::sum(-1,1 ,0 ) == 0);
}

TEST_CASE("mul","[math]") {
    REQUIRE(wolf::math::product(1, 2, 3) == 6);
    REQUIRE(wolf::math::sum(-1,1 ,0 ) == 0);
}

TEST_CASE("gcd","[math]") {
    REQUIRE(wolf::math::gcd(21, 14) == 7);
    REQUIRE(wolf::math::gcd(8, 2 ) == 2);
    REQUIRE(wolf::math::gcd(180, 90, 36) == 18);
}

TEST_CASE("lcm","[math]") {
    REQUIRE(wolf::math::lcm(15, 6) == 30);
    REQUIRE(wolf::math::lcm(8, 2 ) == 8);
    REQUIRE(wolf::math::lcm(8, 2, 7 ) == 56);
}

TEST_CASE("min","[math]") {
    REQUIRE(wolf::math::min(15, 6, 302) == 6);
    REQUIRE(wolf::math::min(8, 8) == 8);
}
