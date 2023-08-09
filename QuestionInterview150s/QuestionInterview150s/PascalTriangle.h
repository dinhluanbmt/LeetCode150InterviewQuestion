#pragma once
#include <vector>
using namespace std;
//118. Pascal's Triangle
/*Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
      1
     1 1
    1 2 1
   1 3 3 1 
  1 4 6 4 1
     */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> PT;
        vector<int> tv(1, 1);
        PT.push_back(tv);
        if (numRows == 1) return PT;
        tv.push_back(1);
        PT.push_back(tv);
        if (numRows == 2)
            return PT;
        int i;
        int j;
        for (i = 2; i < numRows; i++) {
            vector<int> prv = PT[i - 1];
            prv.push_back(1);
            for (j = 1; j < prv.size() - 1; j++)
            {
                prv[j] = PT[i - 1][j] + PT[i - 1][j - 1];
            }
            PT.push_back(prv);
        }
        return PT;
    }
};