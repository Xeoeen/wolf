#pragma once

#include<vector>

namespace wolf::structs::trees {

    //unimplemented!()
    template<typename T>
    struct SegTree {
        SegTree(int size):size(size), base(1) {
            while(base < size)
                base *= 2;
            data.resize(2 * base);
        }

        std::vector<T> data;
        int base;
        int size;
    };
}
