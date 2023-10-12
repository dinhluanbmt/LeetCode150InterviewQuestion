#pragma once
#include <iostream>
#include <vector>
using namespace std;

//283. Move Zeroes
/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i;
        int size = nums.size();
        int pos = 0;
        for (i = 0; i < size; i++) {
            if (nums[i] != 0) continue;
            if (pos <= i) pos = i + 1;
            while (pos < size && nums[pos] == 0) pos++;
            if (pos < size) {
                swap(nums[i], nums[pos]);
                pos++;
            }
        }


    }
};