#pragma once

#include<algorithm>

namespace wolf::math {
    namespace details {
        template<typename T>
        T gcd(T x, T y)
        {
            T r = x % y;
            while(r != 0){
                x = y;
                y = r;
                r = x % y;
            }
            return y;
        }

        template<typename T>
        inline T lcm(const T& x, const T& y)
        {
            return x * y / gcd(x, y);
        }
    }

    template<typename... Ts>
    inline auto sum(Ts&& ... args)
    {
        return (... + args);
    }

    template<typename... Ts>
    inline auto mult(Ts&& ... args)
    {
        return (... * args);
    }


    template<typename First, typename ... Ts>
    First gcd(const First& f, const Ts & ... args)
    {
        First retval = f;
        ( ( retval = details::gcd(retval, args)), ...);
        return retval;
    }



    template<typename First, typename ... Ts>
    First lcm(const First& f, const Ts & ... args)
    {
        First retval = f;
        ( ( retval = details::lcm(retval, args)), ...);
        return retval;
    }

    template<typename First, typename ... Ts>
    First min(const First& f, const Ts & ... args)
    {
        const First *retval = &f;
        ( ( retval = &std::min(*retval, args)), ...);
        return *retval;
    }

    template<typename First, typename ... Ts>
    First max(const First& f, const Ts & ... args)
    {
        const First *retval = &f;
        ( ( retval = &std::max(*retval, args)), ...);
        return *retval;
    }





}
