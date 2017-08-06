#include <wolf/io.hpp>
#include <cstdio>
#include <string>
#include <sstream>

TEST_CASE("load","[io]") {
    freopen("tests/inputs/load.txt", "r", stdin);
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
    freopen("tests/inputs/load.txt", "r", stdin);
    auto [a, b, c ,d] = wolf::io::loadMany<int, std::string, std::string, double>();
    REQUIRE(a == 5);
    REQUIRE(b == "wolf");
    REQUIRE(c == "wolves");
    REQUIRE(d == 0.6);
}
TEST_CASE("loadN","[io]") {
    freopen("tests/inputs/loadN.txt", "r", stdin);
    auto get = wolf::io::loadN<int>(9) ;
    auto expected = std::vector<int>{1, 2, 3, 4, 5,6, 7, 8, 9};
    REQUIRE(get == expected);
}
TEST_CASE("read","[io]") {
    freopen("tests/inputs/load.txt", "r", stdin);
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
    std::cout.rdbuf(buffer.rdbuf());
    wolf::io::write(a, "wolf");
    wolf::io::precision<5>();
    wolf::io::writeln(0.5);
    REQUIRE(buffer.str() =="4 wolf 0.50000 \n");

}
