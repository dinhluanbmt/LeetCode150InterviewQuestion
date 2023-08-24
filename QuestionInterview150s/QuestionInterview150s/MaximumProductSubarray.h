#pragma once
#include <vector>
using namespace std;

//152. Maximum Product Subarray
/*Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int result = INT_MIN;
        int i;
        int cur_p = 1;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cur_p = 1;
            }
            else {
                cur_p *= nums[i];
                result = max(cur_p, result);
            }

        }
        cur_p = 1;
        for (i = nums.size() - 1; i >= 0; i--) {
            cur_p *= nums[i];
            result = max(result, cur_p);
            if (nums[i] == 0) cur_p = 1;
        }

        return result;

    }
};