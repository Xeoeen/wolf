#pragma once

namespace wolf::types {
    using i8 = char;
    using i16 = short;
    using i32 = int;
    using i64 = long long;

    using u8 = unsigned char;
    using u16 = unsigned short;
    using u32 = unsigned int;
    using u64 = unsigned long long;
    using f32 = float;
    using f64 = double;
    using f80 = long double;
}

namespace wolf {
    struct neutral {
        template<typename... Ts>
        void operator() (Ts&&...) {}
    };
    namespace iterator {
        template<typename T>
        struct range {
            T begin() { return b; }
            T end() { return e; }
            T b, e;
        };
    }

    namespace numeric {
    template<typename T>
        struct range {
            range(const T& val, const T& jump = 1):jump(jump) {
                assert(jump != 0);
                if(jump > 0)
                    b = 0, e = val;
                else
                    b = val, e = 0;
            }
            range(const T& start, const T& end, const T& jump = 1):b(start), e(end), jump(jump) {
                assert(jump != 0);
                if(jump > 0)
                    assert(start <= end);
                else
                    assert(start >= end);
            }
            struct iterator {
                T val;
                T jump;
                
                T& operator*() { return val; }
                iterator& operator++() { val += jump; return *this; }
                bool operator!=(const iterator& el) const { return jump > 0 ? val < el.val : val > el.val; }
            };

            iterator begin() { return iterator{b, jump}; }
            iterator end() { return iterator{e, jump}; }
            T b, e, jump;
        };
    }
}
