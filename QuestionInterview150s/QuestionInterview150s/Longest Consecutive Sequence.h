#pragma once
#include <unordered_set>
#include <vector>
using namespace std;
//128. Longest Consecutive Sequence
/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ms;
        for (int num : nums) ms.insert(num);
        int tem;
        int max_seq = 0;
        int cur_seq;
        for (auto it = ms.begin(); it != ms.end(); ++it) {
            if (ms.find(*it - 1) != ms.end()) continue;
            tem = *it + 1;
            cur_seq = 1;
            while (ms.find(tem) != ms.end()) {
                cur_seq++;
                tem++;
            }
            max_seq = max(max_seq, cur_seq);
        }
        return max_seq;
    }
};