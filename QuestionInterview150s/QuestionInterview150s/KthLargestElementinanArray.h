#pragma once
#include <vector>
#include <queue> // queue and priority_queue
using namespace std;

//215. Kth Largest Element in an Array

/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> mpq;
        for (auto& num : nums) mpq.push(num);
        while (k != 1) {
            mpq.pop();
            k--;
        }
        return mpq.top();
    }
};