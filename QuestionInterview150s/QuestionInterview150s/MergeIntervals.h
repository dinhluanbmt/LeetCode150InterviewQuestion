#pragma once
#include <vector>
#include <algorithm>
using namespace std;

// 56. Merge Intervals
/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        vector<vector<int>> retV;
        int tem;
        for (auto inter : intervals) {
            if (retV.size() > 0) {
                if (inter[0] > retV[retV.size() - 1][1]) {
                    retV.push_back(inter);
                }
                else {
                    tem = max(retV[retV.size() - 1][1], inter[1]);
                    retV[retV.size() - 1][1] = tem;
                }
            }
            else {
                retV.push_back(inter);
            }
        }
        return retV;
    }
};