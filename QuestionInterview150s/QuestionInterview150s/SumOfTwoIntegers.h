#pragma once
#include <vector>
using namespace std;

//371. Sum of Two Integers
/*Given two integers a and b, return the sum of the two integers without using the operators + and - .*/
class Solution {
public:
    int getSum(int a, int b) {
        int sum, carry;
        while (b != 0) {
            sum = a ^ b;
            carry = (a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};

//==========
/* Main idea
*  log2(a*b) = log2(a) + log2(b).
* and log2(pow(2,a)) = a , log2(pow(2,b)) = b ==> a + b = log2(pow(2,a)) + log2(pow(2,b))
* ==>  a + b = log2(pow(2,a) * pow(2,b));
*/
class Solution_logarit {
public:
    int getSum(int a, int b) {
        return (int)log2(pow(2, a) * pow(2, b));
    }
};