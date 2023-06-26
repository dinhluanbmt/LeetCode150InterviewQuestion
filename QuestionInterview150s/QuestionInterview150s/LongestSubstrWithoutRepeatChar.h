#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//3. Longest Substring Without Repeating Characters
//Given a string s, find the length of the longest substring without repeating characters.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        int i;
        unordered_map<char, int> m;
        int s_idx = 0;// start index        
        int mv = 0;// max value
        for (i = 0; i < size; i++) {
            if (m[s[i]] > 0) {
                s_idx = max(m[s[i]], s_idx);
            }
            mv = max(mv, i - s_idx + 1);
            m[s[i]] = i + 1;
        }
        return mv;
    }
};