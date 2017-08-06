#include "catch.hpp"
#include <wolf/io.hpp>
#include <string>
#include <sstream>

TEST_CASE("load","[io]") {
    std::stringstream buffer("5 wolf wolves 0.6");
    std::cin.rdbuf(buffer.rdbuf());
    auto a = wolf::io::load<int>();
    auto b = wolf::io::load<std::string>();
    auto c = wolf::io::load<std::string>();
    auto d = wolf::io::load<double>();
    REQUIRE(a == 5);
    REQUIRE(b == "wolf");
    REQUIRE(c == "wolves");
    REQUIRE(d == 0.6);
}
TEST_CASE("loadMany","[io]") {
    std::stringstream buffer("5 wolf wolves 0.6");
    std::cin.rdbuf(buffer.rdbuf());
    auto [a, b, c ,d] = wolf::io::loadMany<int, std::string, std::string, double>();
    REQUIRE(a == 5);
    REQUIRE(b == "wolf");
    REQUIRE(c == "wolves");
    REQUIRE(d == 0.6);
}
TEST_CASE("loadN","[io]") {
    std::stringstream buffer("1 2 3 4 5 6 7 8 9");
    std::cin.rdbuf(buffer.rdbuf());
    auto get = wolf::io::loadN<int>(9) ;
    auto expected = std::vector<int>{1, 2, 3, 4, 5,6, 7, 8, 9};
    REQUIRE(get == expected);
}
TEST_CASE("read","[io]") {
    std::stringstream buffer("5 wolf wolves 0.6");
    std::cin.rdbuf(buffer.rdbuf());
    std::string b, c;
    int a;
    double d;
    wolf::io::read(a, b, c ,d);
    REQUIRE(a == 5);
    REQUIRE(b == "wolf");
    REQUIRE(c == "wolves");
    REQUIRE(d == 0.6);
}
TEST_CASE("write","[io]") {
    int a = 4;
    std::stringstream buffer;
    
    auto old = std::cout.rdbuf(buffer.rdbuf());
    
    wolf::io::write(a, "wolf");
    wolf::io::precision<5>();
    wolf::io::writeln(0.5);

    std::cout.rdbuf(old);

    REQUIRE(buffer.str() =="4 wolf 0.50000 \n");

}
