    #pragma once
#include <cassert>
#include <algorithm>

namespace wolf::math {
    namespace details {
        template<typename T>
        T gcd(T x, T y) {
            T r = x % y;
            while(r != 0) {
                x = y;
                y = r;
                r = x % y;
            }
            return y;
        }

        template<typename T> inline T lcm(const T& x, const T& y) { return x * y / gcd(x, y); }
    }
    template<typename T>
    inline T fastPow(const T& val, int n) {
        assert(n != 0);
        T result = val;
        T acc = val;;
        --n;
        while(n > 0) {
            if(n & 1) result *= acc;
            acc *= acc;
            n >>= 1;
        }
        return result;
    }

    template<typename... Ts> inline auto sum(Ts&&... args) { return (... + args); }
    template<typename... Ts> inline auto product(Ts&&... args) { return (... * args); }

    template<typename T, typename... Ts>
    inline T gcd(const T& f, const Ts&... args) {
        T retval = f;
        (( retval = details::gcd(retval, args)), ...);
        return retval;
    }

    template<typename T, typename... Ts>
    inline T lcm(const T& f, const Ts&... args) {
        T retval = f;
        (( retval = details::lcm(retval, args)), ...);
        return retval;
    }

    template<typename T, typename... Ts>
    inline T min(const T& f, const Ts&... args) {
        const T *retval = &f;
        (( retval = &std::min(*retval, args)), ...);
        return *retval;
    }

    template<typename T, typename... Ts>
    inline T max(const T& f, const Ts&... args) {
        const T *retval = &f;
        (( retval = &std::max(*retval, args)), ...);
        return *retval;
    }
}
