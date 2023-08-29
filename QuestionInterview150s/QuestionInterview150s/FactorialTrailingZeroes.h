#pragma once
#include <iostream>
using namespace std;

//172. Factorial Trailing Zeroes
/*Given an integer n, return the number of trailing zeroes in n!.
Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1. 

Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.

Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.*/

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        long long s = 5;
        while (n / s > 0) {
            count += n / s;
            s *= 5;
        }
        return count;
    }
};