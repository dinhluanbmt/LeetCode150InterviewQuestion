#pragma once
#include <vector>
using namespace std;

//162. Find Peak Element
/*A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -¡Ä. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 0;
        if (size == 2)
        {
            if (nums[0] < nums[1]) return 1;
            return 0;
        }
        int l, r;
        l = 0;
        r = size - 1;
        int mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};