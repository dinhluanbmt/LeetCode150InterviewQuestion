#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* 1. Two Sum.
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m; //Time complexity to build unordered_map is log N
        //map<int,int> m --> will be N log N
        int i = 0;
        vector<int> ret;
        int val;
        for (i = 0; i < nums.size(); i++)
        {
            val = target - nums[i];
            if (m.find(val) == m.end())
                m[nums[i]] = i;
            else {
                ret.push_back(i);
                ret.push_back(m[val]);
                return ret;
            }
        }

        return ret;
    }
};