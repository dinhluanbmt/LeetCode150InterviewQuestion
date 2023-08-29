#pragma once
#include <vector>
using namespace std;
//189. Rotate Array
/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.*/

class Solution {
public:

    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;
        int size = nums.size();
        if (k % size == 0) return;
        vector<int> tVec;
        for (auto num : nums) tVec.push_back(num);
        int i, pos;
        int val;
        for (i = 0; i < size; i++) {
            nums[(i + k) % size] = tVec[i];
        }

    }
};