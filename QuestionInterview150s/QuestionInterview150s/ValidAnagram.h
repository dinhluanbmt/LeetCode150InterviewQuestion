#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//242. Valid Anagram
/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> vec(27, 0);
        int i;
        for (i = 0; i < s.size(); i++) {
            vec[s[i] - 'a']++;
            vec[t[i] - 'a']--;
        }
        for (auto& v : vec)
        {
            if (v != 0) return false;
        }
        return true;

    }
};

// unordered_map
class Solution_umap {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> ums;

        int i;
        for (i = 0; i < s.size(); i++) {
            ums[s[i]]++;
            ums[t[i]]--;
        }
        for (auto it = ums.begin(); it != ums.end(); it++)
        {
            if (it->second) return false;
        }
        return true;

    }
};