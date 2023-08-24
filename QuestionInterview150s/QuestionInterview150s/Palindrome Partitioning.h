#pragma once
#include <vector>
#include <string>
using namespace std;

//131. Palindrome Partitioning
/*Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.*/

class Solution {
public:
    bool isP(string& s, int first, int last) {
        if (first < 0 || last >= s.length()) return false;
        if (first == last) return true;
        while (first <= last) {
            if (s[first] != s[last]) return false;
            first++;
            last--;
        }
        return true;
    }
    void make(string& s, int start, vector<string>& cur, vector<vector<string>>& data) {
        int len = s.length();
        if (start == len) {
            data.push_back(cur);
            return;
        }
        int i;
        for (i = start; i < len; i++) {
            if (isP(s, start, i)) {
                cur.push_back(s.substr(start, i - start + 1));
                make(s, i + 1, cur, data);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> retVec;
        vector<string> tv;
        make(s, 0, tv, retVec);
        return retVec;
    }
};
