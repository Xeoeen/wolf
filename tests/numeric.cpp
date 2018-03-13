#include "catch.hpp"
#include <wolf/numeric.hpp>

using namespace wolf::numeric;

TEST_CASE("prime", "[numeric]") {
    REQUIRE(isPrime(2));
    REQUIRE(isPrime(11));
    REQUIRE(isPrime(13));
    REQUIRE(isPrime(17));
    REQUIRE(!isPrime(21));
    REQUIRE(!isPrime(1));
    REQUIRE(!isPrime(36));
    REQUIRE(isPrime(2));
}

TEST_CASE("EratosthenesSieve ", "[numeric]") {
    auto sieve = EratosthenesSieve(100);
    REQUIRE(sieve.prime[2] == true);
    REQUIRE(sieve.prime[1] == false);
    REQUIRE(sieve.prime[7] == true);
    REQUIRE(sieve.prime[9] == false);
    auto collector = vector<int>();
    sieve.forAllIngredients(28, [&](int v) { collector.push_back(v); });
    auto good = vector<int>{2, 2, 7};
    REQUIRE(collector == good);
}
