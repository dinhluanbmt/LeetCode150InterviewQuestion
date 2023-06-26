#pragma once
#include <iostream>
#include <vector>
using namespace std;

//14. Longest Common Prefix
//Write a function to find the longest common prefix string amongst an array of strings.
//If there is no common prefix, return an empty string "".

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if (size <= 1) return strs[0];
        int size0 = strs[0].length();
        string ret = "";
        int i0, i;
        // bool flag = false;
        for (i0 = 0; i0 < size0; i0++) {
            // flag = true;
            for (i = 1; i < size; i++) {
                if (i0 >= strs[i].length() || strs[0][i0] != strs[i][i0]) {
                    // flag = false;
                    // break;
                    return ret;
                }
            }
            ret.push_back(strs[0][i0]);
            //else return ret;
        }
        return ret;
    }
};