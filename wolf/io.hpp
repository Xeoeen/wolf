#pragma once

#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>

namespace wolf::io {
    inline void boost() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }

    template<typename T, std::istream& in = std::cin>
    inline T load() { T x; in >> x; return x; }

    template<typename ... Ts, std::istream& in = std::cin>
    inline void read(Ts&... args) {
        ((args = load<Ts, in>()),...);
    }

    template<std::ostream& out = std::cout, typename ... Ts>
    inline void writeln(const Ts&... args) {
        ((out << args << " "), ...) << "\n";
    }

    template<std::ostream& out = std::cout, typename ... Ts>
    inline void write(const Ts&... args) {
        ((out << args << " "), ...);
    }

    template<int places, std::ostream& out = std::cout>
    inline void precision() {
        out.precision(places);
        out << std::fixed;
    }

    template<typename ... Ts>
    inline void log(Ts&&... args) {
        ((std::clog << args << " "), ...) << std::endl;
    }

    template<typename T, std::istream& in = std::cin>
    inline std::vector<T> loadN(const int n) {
        std::vector<T> vt(n);
        std::generate(vt.begin(), vt.end(), load<T, in>);
        return vt;
    }

    template<typename ... Ts, std::istream& in = std::cin>
    inline auto loadMany() {
        return std::make_tuple(load<Ts, in>()...);
    }

}
