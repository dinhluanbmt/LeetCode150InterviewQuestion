#pragma once
#include <vector>
using namespace std;

//55. Jump Game
/*You are given an integer array nums. You are initially positioned at the array's first index, 
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.*/

class Solution {
public:
    bool jump(vector<int>& nums, int pos) {
        if (pos == nums.size() - 1) return true;
        if (nums[pos] + pos >= nums.size() - 1) return true;
        if (nums[pos] == 0) return false;
        for (int i = nums[pos]; i >= 1; i--) {
            bool ret = jump(nums, pos + i);
            if (ret) return ret;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        bool ret = jump(nums, 0);
        return ret;
    }
};