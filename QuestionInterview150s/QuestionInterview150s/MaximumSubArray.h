#pragma once
#include <vector>
using namespace std;

//53. Maximum Subarray
/*Given an integer array nums, find the subarray with the largest sum, and return its sum.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int smax = INT_MIN;
        for (auto num : nums) {
            sum += num;
            smax = max(sum, smax);
            if (sum < 0) sum = 0;
        }
        return smax;

    }
};