#pragma once
#include <bitset>
using namespace std;

// 191. Number of 1 Bits

/*Write a function that takes the binary representation of an unsigned integer and returns the number of '1' bits 
it has (also known as the Hamming weight).*/

class Solution_bs {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> bs(n);
        return bs.count();
    }
};

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            count += n & 1;
            n = n >> 1;
        }
        return count;
    }
};