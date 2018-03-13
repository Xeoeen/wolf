#pragma once

#include<vector>

namespace wolf::structs{
    template<typename T, typename G = int>
    struct QuickFill {
        QuickFill(int s, const T& fillWith):storage(s, fillWith), updateTime(s, 0), fillVal(fillWith), fillTime(0) {}

        void fill(const T& val) {
            fillVal = val;
            ++fillTime;
        }

        typename std::vector<T>::reference; operator[] (int index) {
            if(updateTime[index] != fillTime) {
                updateTime[index] = fillTime;
                storage[index] = fillVal;
            }

            return storage[index];
        }

        std::vector<T> storage;
        std::vector<G> updateTime;
        T fillVal;
        G fillTime;
    };

}
