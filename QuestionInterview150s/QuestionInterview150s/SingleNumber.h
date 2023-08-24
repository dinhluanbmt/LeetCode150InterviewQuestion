#pragma once
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

//136. Single Number
/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/

//Bitwise solution
// XOR operation : a^a = 0, 
class Solution_bitwise {
public:
    int singleNumber(vector<int>& nums) {
        int ret = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            ret = ret ^ nums[i];
        }
        return ret;

    }
};

//Sort solution : std::sort --> average and best case time complexity O(nlog n)
class Solution_sort {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i += 2)
        {
            if (nums[i] != nums[i + 1]) return nums[i];
        }
        return nums.back();
    }
};

//unordered_map --> build unordered_map --> O(N)
// O(N + N) = O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto num : nums) {
            um[num]++;
        }
        for (auto it = um.begin(); it != um.end(); it++) {
            if (it->second == 1) return it->first;
        }
        return -1;

    }
};
