#pragma once
#include <vector>
using namespace std;

//78. Subsets

/*Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.*/
class Solution {
public:
    void getsub(vector<vector<int>>& retSub, vector<int>& nums, vector<int>& cur, int pos) {
        retSub.push_back(cur);
        for (int i = pos; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            getsub(retSub, nums, cur, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        getsub(ret, nums, cur, 0);
        return ret;
    }
};