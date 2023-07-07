#pragma once
#include <iostream>

//29. DivideTwoIntegers
/*
* Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. 
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.
Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer 
range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, 
and if the quotient is strictly less than -2^31, then return -2^31.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (dividend == divisor) return 1;
        if (divisor == INT_MIN) return 0;
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
        unsigned int a_div = abs(dividend);
        unsigned int a_ds = abs(divisor);
        if (a_div < a_ds) return 0;
        int count = 0;
        int tem;
        for (int i = 31; i >= 0; i--)
        {
            tem = (a_div >> i) - a_ds;

            if (tem >= 0)
            {
                count += 1 << i;
                a_div = a_div - (a_ds << i);
            }
            if (a_div < 0) break;
        }
        //check whether two integers are same sign (plus or minus)
        return ((dividend > 0) == (divisor > 0)) ? count : -count;
    }
};
