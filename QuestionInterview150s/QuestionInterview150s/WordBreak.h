#pragma once
#include <vector>
#include <string>
using namespace std;

//139. Word Break

/*Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length(), false);
        dp[0] = true;
        int i;
        int size;
        for (i = 0; i < s.length(); i++) {
            for (auto w : wordDict) {
                if (dp[i]) {
                    if (s.substr(i, w.length()) == w) {
                        dp[i + w.length()] = true;
                    }
                }
            }
        }
        return dp[s.length()];
    }
};