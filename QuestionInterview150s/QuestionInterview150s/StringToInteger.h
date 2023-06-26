#pragma once
#include <iostream>
#include <string>
using namespace std;

//8. String to Integer(atoi)
/*Implement the myAtoi(string s) function, which converts a string to a 32 - bit signed integer(similar to C / C++'s atoi function).

	The algorithm for myAtoi(string s) is as follows :

Read inand ignore any leading whitespace.
Check if the next character(if not already at the end of the string) is '-' or '+'.Read this character in if it is either.
This determines if the final result is negative or positive respectively.Assume the result is positive if neither is present.
Read in next the characters until the next non - digit character or the end of the input is reached.
The rest of the string is ignored.
Convert these digits into an integer(i.e. "123" -> 123, "0032" -> 32).If no digits were read, then the integer is 0. 
Change the sign as necessary(from step 2).
If the integer is out of the 32 - bit signed integer range[-231, 231 - 1], then clamp the integer so that it remains in the range.
Specifically, integers less than - 231 should be clamped to - 231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:
Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
*/

#define M_V INT_MAX/10
class Solution {
public:
    int myAtoi(string s) {
        unsigned len = s.length();
        if (len == 0) return 0;
        unsigned idx = 0;
        while (s[idx] == ' ')
            idx++;
        bool minus = false;
        if (s[idx] == '-') {
            minus = true;
            idx++;
            if (s[idx] < '0' || s[idx] >'9') return 0;
        }
        if (s[idx] == '+') {
            idx++;
            if (s[idx] < '0' || s[idx] >'9') return 0;
        }
        int ret = 0;
        int tem;
        while (s[idx] >= '0' && s[idx] <= '9') {
            tem = s[idx] - '0';
            if (ret > M_V) {
                if (minus) return INT_MIN;
                return INT_MAX;
            }
            if (ret == M_V && minus && tem >= 8) {
                return INT_MIN;
            }
            if (ret == M_V && !minus && tem >= 7) {
                return INT_MAX;
            }

            ret = ret * 10 + tem;
            idx++;
        }
        if (minus) return -ret;
        return ret;
    }
};

