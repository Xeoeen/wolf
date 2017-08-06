#pragma once

namespace wolf::logic{

    template<typename... Ts>
    inline bool allOf(Ts&&... args)
    {
        return (... && args);
    }

    template<typename... Ts>
    inline bool oneOf(Ts&&... args)
    {
        return (... || args);
    }

    template<typename... Ts>
    inline bool noneOf(Ts&&... args)
    {
        return !oneOf(args...);
    }
}
