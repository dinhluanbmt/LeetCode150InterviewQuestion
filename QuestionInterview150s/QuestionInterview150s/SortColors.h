#pragma once
#include <vector>
using namespace std;
//75. Sort Colors
/*Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return;
        int l = 0;
        int r = size - 1;
        while (l < size && nums[l] == 0) l++;
        if (l == size - 1) return;
        while (r >= 0 && nums[r] == 2) r--;
        if (r <= 0) return;
        int i = l;
        while (i <= r) {
            if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                while (r >= 0 && nums[r] == 2) r--;
            }
            else
                if (nums[i] == 0) {
                    swap(nums[i], nums[l]);
                    while (l < size && nums[l] == 0) l++;
                    i = l;
                }
                else i++;

        }
    }
};
