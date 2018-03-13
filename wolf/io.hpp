#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <list>
#include <map>
#include <unordered_map>
#include <set>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& other) {
    for(const auto& el : other) os << el << ' ';
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& other) {
    for(const auto& el : other) os << el << ' ';
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::list<T>& other) {
    for(const auto& el : other) os << el << ' ';
    return os;
}

template<typename Key, typename Val>
std::ostream& operator<<(std::ostream& os, const std::map<Key, Val>& other) {
    for(const auto& [key, val] : other) os << key << " -> " << val << ' ';
    return os;
}

template<typename Key, typename Val>
std::ostream& operator<<(std::ostream& os, const std::unordered_map<Key, Val>& other) {
    for(const auto& [key, val] : other) os << key << " -> " << val << ' ';
    return os;
}

namespace wolf::io {

    inline void boost() {
        std::ios_base::sync_with_stdio(false);
        #ifndef _GLIBCXX_DEBUG
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        #endif
    }

    template<typename T, std::istream& in = std::cin> inline T load() { T x; in >> x; return x; }
    template<typename ... Ts, std::istream& in = std::cin> inline void read(Ts&... args) { ((args = load<Ts, in>()),...); }
    template<std::ostream& out = std::cout, typename... Ts> inline void writeln(const Ts&... args) { ((out << args << ' '), ...) << '\n'; }
    template<std::ostream& out = std::cout, typename... Ts>inline void write(const Ts&... args) { ((out << args << ' '), ...); }
    template<typename ... Ts> inline void log(Ts&&... args) { ((std::clog << args << ' '), ...) << std::endl; }
    template<typename ... Ts> inline void error(Ts&&... args) { ((std::cerr << args << ' '), ...) << '\n'; }

    template<int places, std::ostream& out = std::cout> inline void precision() { out.precision(places); out << std::fixed; }


    template<typename T, std::istream& in = std::cin>
    inline std::vector<T> loadN(const int n) {
        std::vector<T> vt(n);
        std::generate(vt.begin(), vt.end(), load<T, in>);
        return vt;
    }

    template<typename... Ts, std::istream& in = std::cin> inline auto loadMany() { return std::tuple{load<Ts, in>()...}; }

}
