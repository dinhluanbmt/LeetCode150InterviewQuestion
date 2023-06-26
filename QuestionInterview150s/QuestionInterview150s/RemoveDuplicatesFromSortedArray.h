#pragma once
#include <vector>
using namespace std;

/*Given an integer array nums sorted in non-decreasing order, 
remove the duplicates in-place such that each unique element appears only once.T
he relative order of the elements should be kept the same. Then return the number of unique elements in nums.
Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:
Change the array nums such that the first k elements of nums contain the unique elements in the order 
they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int pos = 0;
        int i;
        for (i = 1; i < size; i++) {
            if (nums[i] != nums[pos]) {
                pos++;
                nums[pos] = nums[i];
            }
        }
        // even  we can really erase it
        //nums.erase(nums.begin() + pos + 1, nums.end());
        return pos + 1;
    }
};
