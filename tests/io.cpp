#include "catch.hpp"
#include <wolf/io.hpp>
#include <string>
#include <sstream>

template<std::istream& in = std::cin>
struct FakeInput {
    FakeInput(std::string s):buffer(s) { old = in.rdbuf(buffer.rdbuf()); }
    ~FakeInput() { in.rdbuf(old); }

    std::stringstream buffer;
    decltype(in.rdbuf()) old;
};

template<std::ostream& out = std::cout>
struct FakeOutput {
    FakeOutput(std::string s = ""):buffer(s) { old = out.rdbuf(buffer.rdbuf()); }
    ~FakeOutput() { out.rdbuf(old); }

    std::stringstream buffer;
    decltype(out.rdbuf()) old;
};

TEST_CASE("load","[io]") {
    {
        FakeInput redirector("5 wolf wolves 0.6");
        auto a = wolf::io::load<int>();
        auto b = wolf::io::load<std::string>();
        auto c = wolf::io::load<std::string>();
        auto d = wolf::io::load<double>();
        REQUIRE(a == 5);
        REQUIRE(b == "wolf");
        REQUIRE(c == "wolves");
        REQUIRE(d == 0.6);
    }
}
TEST_CASE("loadMany","[io]") {
    {
        FakeInput redirector("5 wolf wolves 0.6");
        auto [a, b, c ,d] = wolf::io::loadMany<int, std::string, std::string, double>();
        REQUIRE(a == 5);
        REQUIRE(b == "wolf");
        REQUIRE(c == "wolves");
        REQUIRE(d == 0.6);
    }
}
TEST_CASE("loadN","[io]") {
    {
        FakeInput redirector("1 2 3 4 5 6 7 8 9");
        auto get = wolf::io::loadN<int>(9) ;
        auto expected = std::vector<int>{1, 2, 3, 4, 5,6, 7, 8, 9};
        REQUIRE(get == expected);
    }
}
TEST_CASE("read","[io]") {
    {
        FakeInput redirector("5 wolf wolves 0.6");
        std::string b, c;
        int a;
        double d;
        wolf::io::read(a, b, c ,d);
        REQUIRE(a == 5);
        REQUIRE(b == "wolf");
        REQUIRE(c == "wolves");
        REQUIRE(d == 0.6);
    }
}
TEST_CASE("write","[io]") {
    {
        int a = 4;
        FakeOutput redirector;

        wolf::io::write(a, "wolf");
        wolf::io::precision<5>();
        wolf::io::writeln(0.5);

        REQUIRE(redirector.buffer.str() =="4 wolf 0.50000 \n");
    }
}
