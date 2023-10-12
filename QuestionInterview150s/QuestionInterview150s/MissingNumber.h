#pragma once
#include <iostream>
#include <vector>
using namespace std;
//268. Missing Number

/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        int size = nums.size();
        int ans = size;
        for (i = 0; i < size; ++i)
        {
            ans = (ans ^ i) ^ nums[i];
        }
        return ans;
    }
};