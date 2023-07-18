#pragma once
#include <iostream>
using namespace std;

//69. Sqrt(x)

/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. 
The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.*/

class Solution {
public:
    int mySqrt(int x) {
        long long s = 0, e = x, ans, mid;   //long long due to some of test cases overflows integer limit.
        while (s <= e) {
            mid = (s + e) / 2;
            if (mid * mid == x) return mid;     //if the 'mid' value ever gives the result, we simply return it.
            else if (mid * mid < x) {
                s = mid + 1;        //if 'mid' value encounterted gives lower result, we simply discard all the values lower than mid.
                ans = mid;        //an extra pointer 'ans' is maintained to keep track of only lowest 'mid' value. 
            }
            else e = mid - 1;       //if 'mid' value encountered gives greater result, we simply discard all the values greater than mid. 
        }
        return ans;
    }
};
