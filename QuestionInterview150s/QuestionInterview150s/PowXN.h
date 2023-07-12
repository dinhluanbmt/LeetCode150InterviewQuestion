#pragma once
#include <iostream>
using namespace std;
// 50. Pow(x, n)
/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/
// recursive solution
class Recursive_Solution {
public:
    double calc(double x, int n) {
        if (n <= 2) return x * x;
        if (n % 2 != 0) return x * calc(x, n - 1);
        else {
            double tem = calc(x, n / 2);
            return tem * tem;
        }
    }
    double myPow(double x, int n) {

        if (n < 0)
        {
            x = 1.0 / x;
            if (n == -1) return x;
            if (n == INT_MIN) {
                n = n + 1;
                return calc(x, abs(n)) * x;
            }
            n = abs(n);
        }
        if (x == 1) return 1;
        if (n == 0) return 1;
        if (n == 1) return x;
        double result = calc(x, n);
        return result;

    }
};

//Non recursive
class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0)
        {
            x = 1.0 / x;
        }

        double result = 1.0;
        double power = x;

        while (n != 0)
        {
            if (n % 2 != 0)
            {
                result *= power;
            }
            n /= 2;
            power = power * power;
        }

        return result;

    }
};