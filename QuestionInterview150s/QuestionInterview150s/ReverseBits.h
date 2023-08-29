#pragma once
#include <iostream>
using namespace std;

//190. Reverse Bits

/*Reverse bits of a given 32 bits unsigned integer.*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int i;
        for (i = 0; i < 32; i++) {
            result = result | (n & 1);
            if (i == 31) break;
            result = result << 1;
            n = n >> 1;
        }
        return result;
    }
};