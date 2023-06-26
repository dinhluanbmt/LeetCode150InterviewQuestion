#pragma once
#include <iostream>
#include <vector>
using namespace std;

//11. Container With Most Water
/*You are given an integer array height of length n.
There are n vertical lines drawn such that the two endpoints of the ith line are(i, 0) and (i, height[i]).
Find two lines that together with the x - axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int h;
        int vol;
        int mV = 0;
        while (left < right) {
            vol = min(height[left], height[right]) * (right - left);
            if (vol > mV) {
                mV = vol;
            }
            if (height[left] < height[right]) left++;
            else right--;
        }
        return mV;

    }
};
