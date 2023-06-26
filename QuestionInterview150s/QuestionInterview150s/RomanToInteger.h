#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//13. Roman To Integer
/*Roman numerals are represented by seven different symbols : I, V, X, L, C, Dand M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II.
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right.
However, the numeral for four is not IIII.Instead, the number four is written as IV.
Because the one is before the five we subtract it making four.
The same principle applies to the number nine, which is written as IX.There are six instances where subtraction is used :

I can be placed before V(5) and X(10) to make 4 and 9.
X can be placed before L(50) and C(100) to make 40 and 90.
C can be placed before D(500) and M(1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/

unordered_map<char, int> m{ {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} };
class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int len1 = len - 1;
        int ret = 0;
        int i;
        for (i = 0; i < len; i++) {
            switch (s[i]) {
            case 'I': {
                if (i < len1 && s[i + 1] == 'V') { ret += 4; i++; }
                else if (i < len1 && s[i + 1] == 'X') { ret += 9; i++; }
                else ret += m[s[i]];
                break;
            }
            case 'X': {
                if (i < len1 && s[i + 1] == 'L') { ret += 40; i++; }
                else if (i < len1 && s[i + 1] == 'C') { ret += 90; i++; }
                else ret += m[s[i]];
                break;
            }
            case 'C': {
                if (i < len1 && s[i + 1] == 'D') { ret += 400; i++; }
                else if (i < len1 && s[i + 1] == 'M') { ret += 900; i++; }
                else ret += m[s[i]];
                break;
            }
            default:
                ret += m[s[i]];
            }
        }
        return ret;

    }
};