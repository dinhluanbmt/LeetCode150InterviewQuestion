#pragma once
#include <vector>
#include <algorithm>
using namespace std;

//15. 3Sum
/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, l, r;
        int size = nums.size();
        int size1 = size - 1;
        int val, tem;
        vector<vector<int>> ret;

        for (i = 0; i < size - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            l = i + 1;
            r = size1;
            while (l < r) {
                tem = nums[i] + nums[l] + nums[r];
                if (tem == 0) {
                    ret.push_back({ nums[i],nums[l],nums[r] });
                }
                if (tem > 0) {
                    r--;
                    while (r > l && nums[r] == nums[r + 1]) r--;
                }
                else
                {
                    l++;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                }
            }
        }

        return ret;
    }
};
