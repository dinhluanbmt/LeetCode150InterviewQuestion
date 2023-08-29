#pragma once
#include <vector>
#include <unordered_map>
using namespace std;

//169.Majority Element

/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than (n / 2) times. You may assume that the majority element always exists in the array.*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        for (auto num : nums) {
            if (++um[num] > nums.size() / 2) return num;
        }
        return 0;
    }
};