#pragma once
#include <iostream>
#include <string>
using namespace std;

//5. Longest Palindromic Substring
//Given a string s, return the longest palindromic substring in s.

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 1) return s;
        string ret = "";
        int i, left, right, mid;
        int idx = 0;
        int t_right;
        int t_left;
        bool found;
        for (i = 0; i < len; i++) {
            string tem = "";
            right = len - 1;
            left = i;
            // found = true;
             // check from left to right 
            while (right > left) {
                found = true;
                mid = (right + left) / 2;
                t_right = right;
                t_left = left;
                while (t_left <= mid) {
                    if (s[t_left] != s[t_right]) {
                        found = false;
                        break;
                    }
                    t_left++;
                    t_right--;
                }
                if (found) {
                    // tem = s.substr(i,(right-i)+1);
                    // if(tem.length()> ret.length()){
                    if ((right - i) + 1 > ret.length()) {
                        ret = s.substr(i, (right - i) + 1);
                    }
                    break;
                }
                right--;
            }

        }
        if (ret == "") ret.push_back(s[0]);
        return ret;

    }
};
