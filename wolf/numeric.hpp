#pragma once
#include<cmath>
#include "utils.hpp"

namespace wolf::numeric {
    using namespace std;

    template<typename T>
    bool isPrime(T x) {
        if(x < 2)
            return false;
        T lim = sqrt(x);

        for(T i = 2 ; i <= lim ; ++i)
            if(x % i == 0)
                return false;
        return true;
    }

    struct EratosthenesSieve {
        EratosthenesSieve(int size):prime(size + 1, true), jump(size + 1) {
            auto lim = sqrt(size) + 1;
            for(int i = 2 ; i <= lim ; ++i) {
                if(prime[i]) {
                    for(int j = i * i ; j <= size ; j += i) {
                        prime[j] = false;
                        jump[j] = i;
                    }
                }
            }
            for(int i = 1 ; i <= size ; ++i)
                if(prime[i])
                    jump[i] = i;

            prime[1] = false;
        }

        template<typename F>
        void forAllIngredients(int num, F f) {
            // be aware of one
            do {
                f(jump[num]);
                num /= jump[num];
            }
            while(num != 1);
        }
        vector<bool> prime;
        vector<int> jump;
    };
}
