#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

//49. Group Anagrams
/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unsigned size = strs.size();
        if (size <= 1)
        {
            ret.push_back(strs);
            return ret;
        }
        unordered_map<string, size_t> m_map;
        size_t i;
        string tem;
        for (i = 0; i < size; i++) {
            tem = strs[i];
            sort(tem.begin(), tem.end());
            if (m_map.find(tem) != m_map.end()) {
                ret[m_map[tem]].push_back(strs[i]);
            }
            else {
                vector<string> tv;
                tv.push_back(strs[i]);
                ret.push_back(tv);
                m_map[tem] = ret.size() - 1;
            }
        }
        return ret;
    }
};