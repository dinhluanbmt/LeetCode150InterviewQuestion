#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//179. Largest Number
/*Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.*/

bool cmpFunc(string& a, string& b) {
    return a + b > b + a;
}
class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string> sV;
        for (auto num : nums) {
            sV.push_back(to_string(num));
        }
        sort(sV.begin(), sV.end(), cmpFunc);
        string result = "";
        for (auto s : sV) {
            result += s;
        }
        if (result[0] == '0') return "0";
        return result;
    }
};
