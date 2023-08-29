#pragma once
#include <string>
using namespace std;

//171. Excel Sheet Column Number
/*Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28

ZY -> 701
...*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        //char c = '@' is 64. 
        // A -> 65
        int len = columnTitle.length();
        char c64 = '@';
        if (len == 1) return columnTitle[0] - c64;
        int result = 0;
        int i;
        for (i = 0; i < len; i++) {
            result = result * 26 + (columnTitle[i] - c64);
        }
        return result;

    }
};