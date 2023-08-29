#pragma once
#include <string>
#include <unordered_map>
using namespace std;

//166. Fraction to Recurring Decimal

/*Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
If multiple answers are possible, return any of them.
It is guaranteed that the length of the answer string is less than 104 for all the given inputs.*/


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string ans = "";
        if ((numerator >= 0) != (denominator >= 0)) ans += "-";
        long num = labs(numerator);
        long deno = labs(denominator);
        long div = num / deno;
        ans += to_string(div);
        long mod = num % deno;
        if (mod == 0) return ans;
        ans += ".";
        unordered_map<long, int> um;
        while (mod != 0) {
            if (um.find(mod) != um.end()) {
                int pos = um[mod];
                ans.insert(pos, "(");
                ans += ")";
                break;
            }
            else {
                um[mod] = ans.length();
                mod *= 10;
                div = mod / deno;
                ans += to_string(div);
                mod = mod % deno;
            }
        }
        return ans;

    }
};