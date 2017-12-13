#pragma once
#include<cmath>
#include "utils.hpp"

namespace wolf::numeric {
    using namespace std;

    template<typename T>
    bool isPrimeNumber(T x) {
        if(x < 2)
            return false;
        T lim = sqrt(x);
        
        for(T i = 2 ; i <= lim ; ++i)
            if(x % i == 0)
                return false;
        return true;
    }

    struct EratosthenesSieve {
        ErathosthenesSieve(int size):isPrime(size + 1, true), jump(size + 1) {
            auto lim = sqrt(size);
            for(int i = 2 ; i <= lim ; ++i) {
                if(isPrime[i]) {
                    for(int j = i * i ; j <= size ; j += i) {
                        isPrime[j] = true;
                        jump[j] = i;
                    }
                }
            }
            for(int i = 1 ; i <= size ; ++i)
                if(isPrime[i])
                    jump[i] = i;

            isPrime[1] = false;
        }
        
        template<typename F>
        void forAllInds(int num, F f) {
            // be aware of one
            do {
                f(jump[num]);
                num /= jump[num];
            }
            while(num != 1);
        }
        vector<bool> isPrime;
        vector<int> jump;
    }
}
