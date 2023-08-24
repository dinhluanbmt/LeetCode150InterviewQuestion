#pragma once
#include <iostream>
#include <string>
using namespace std;

//125. Valid Palindrome
/*A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.*/

class Solution {
public:
    bool isvalid(char c) {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= 'A' && c <= 'Z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
    bool isPalindrome(string s) {
        int size = s.length();
        if (size == 0) return false;
        if (size == 1) return true;
        int l = 0;
        int r = size - 1;
        while (l < r) {
            if (!isvalid(s[l])) {
                l++;
                continue;
            }
            if (!isvalid(s[r])) {
                r--;
                continue;
            }
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;

    }
};