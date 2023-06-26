#pragma once
#include <iostream>

//7. Reverse Integer
//Given a signed 32 - bit integer x, return x with its digits reversed.
//If reversing x causes the value to go outside the signed 32 - bit integer range[-231, 231 - 1], then return 0.
//Assume the environment does not allow you to store 64 - bit integers(signed or unsigned).

#define M_VAL INT_MAX/10
#define MM_VAL INT_MIN/10
class Solution {
public:
    int reverse(int x) {
        int val;
        int ret = 0;
        while (x != 0) {
            val = x % 10;
            x = x / 10;
            if (ret > M_VAL || ret < MM_VAL) return 0;
            if (ret == M_VAL && val > 7) return 0;
            if (ret == MM_VAL && val < -8) return 0;
            ret = ret * 10 + val;
        }
        return ret;
    }
};
