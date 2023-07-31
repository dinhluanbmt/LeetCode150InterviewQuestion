#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//91. Decode Ways
/*A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). 
For example, "11106" can be mapped into:

"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

Given a string s containing only digits, return the number of ways to decode it.

The test cases are generated so that the answer fits in a 32-bit integer.

 */

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if (len == 0) return 0;
        if (s[0] == '0') return 0;
        if (len == 1) return 1;
        vector<int> dp(len,0);
        dp[0] = 1;
        //dp[1]
        if (s[1] == '0') {
            if (s[0] < '3') dp[1] = 1;
            else return 0;
        }
        else {
            if (s[0] == '1') dp[1] = 2;
            else
                if (s[0] == '2' && s[1] < '7') dp[1] = 2;
                else
                    dp[1] = 1;
        }
        for (int i = 2; i < len; i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '0' || s[i - 1] > '2') return 0;
            }
            dp[i] = s[i] != '0' ? dp[i - 1] : 0;
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
                dp[i] += dp[i - 2];
        }
        return dp[len - 1];
    }
};