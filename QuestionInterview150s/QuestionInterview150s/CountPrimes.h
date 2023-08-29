#pragma once
#include <vector>
using namespace std;

//204. Count Primes

/*Given an integer n, return the number of prime numbers that are strictly less than n.*/

class Solution {
public:

    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> pVec(n, true);
        int start = 2;
        int i;
        int tem;
        int count = n - 2;
        for (i = 2; i <= sqrt(n - 1); i++) {
            if (pVec[i]) {
                tem = i + i;
                while (tem <= n - 1) {
                    if (pVec[tem]) {
                        pVec[tem] = false;
                        count--;
                    }
                    tem += i;
                }
            }
        }
        return count;

    }
};
