#pragma once
#include <vector>
using namespace std;

//326. Power of Three
/*Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.
Follow up: Could you solve it without loops/recursion?
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 1 || n == 3) return true;
        if (n < 9) return false;
        long long ret = 3;
        int b = 3;
        while (ret < n) {
            ret = ret * b;
            if (ret == n) return true;
            if (ret > n) break;
            if (ret * ret < n) b = ret;
            else b = 3;
        }
        return false;

    }
};

//===========without loop - logarit 
/* 
Main idea:
if( n = pow(3,x)) => log10(n) = log10(pow(3,x)).
we know that log10(pow(a,x)) = x* log10(a).
==> log10(n) = x * log10(3) --> x = log10(n)/ log10(3).
if x is integer --> n is a power of 3
*/
// Need to check why failed when use log with base 2. ???????
class Solution_logarit {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double val = log10(n) / log10(3);
        if (val == (int)val) return true;
        return false;

    }
};