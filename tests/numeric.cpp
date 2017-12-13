#include "catch.hpp"
#include <wolf/numeric.hpp>

TEST_CASE("prime","[numeric]") {
    using isPrime = wolf::numeric::isPrimeNumber;

    REQUIRE(isPrime(2));
    REQUIRE(isPrime(11));
    REQUIRE(isPrime(13));
    REQUIRE(isPrime(17));
    REQUIRE(!isPrime(21));
    REQUIRE(!isPrime(1));
    REQUIRE(!isPrime(36));
    REQUIRE(isPrime(2));

}

