#pragma once
#include <iostream>
#include <vector>
using namespace std;

//46. Permutations
/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/
class Solution {
    vector<vector<int>> ans;
public:
    void solve(vector<int>& nums, int n, int s) {
        if (s == n - 1) {
            ans.push_back(nums);
            return;
        }
        for (int i = s; i < n; i++) {
            swap(nums[s], nums[i]);
            solve(nums, n, s + 1);
            swap(nums[s], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {

        solve(nums, nums.size(), 0);
        return ans;
    }
};

//other solution
class Solution1 {
    vector<vector<int>> ans;
    vector<int> cur;
    vector<bool> visited;
public:
    void solve(vector<int>& nums, int n) {
        if (cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                cur.push_back(nums[i]);
                visited[i] = true;
                solve(nums, n);
                cur.pop_back();
                visited[i] = false;
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool>(nums.size(), false);
        solve(nums, nums.size());
        return ans;
    }
};