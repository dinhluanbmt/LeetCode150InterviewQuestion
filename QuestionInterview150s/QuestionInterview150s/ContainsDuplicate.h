#pragma once
#include<unordered_set>
using namespace std;

//217. Contains Duplicate
/*Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (auto& n : nums) {
            if (us.insert(n).second == false) return true;
        }
        return false;
    }
};