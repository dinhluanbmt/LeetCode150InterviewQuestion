#pragma once
#include <vector>
using namespace std;

//34. Find First and Last Position of Element in Sorted Array

/*
* Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    int lower_range(vector<int>& nums, int target) {
        int l, r, mid;
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_range(nums, target);
        if (start < nums.size() && nums[start] == target) {
            int end = lower_range(nums, target + 1) - 1;
            return { start,end };
        }
        return { -1,-1 };
    }
};