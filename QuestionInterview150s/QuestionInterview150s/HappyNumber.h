#pragma once
#include <iostream>
#include <unordered_set>
using namespace std;

//202. Happy Number
/*Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.*/

class Solution {
public:
    bool isHappy(int n) {
        int val = 0;
        int ret = 0;
        int next = n;
        if (n == 1) return true;
        unordered_set<int> ms;
        while (next != 1) {
            ret = 0;
            while (next != 0) {
                val = next % 10;
                ret += val * val;
                next = next / 10;
            }
            if (ret == 1) return true;
            next = ret;
            if (ms.insert(next).second == false) return false;
        }
        return true;
    }
};