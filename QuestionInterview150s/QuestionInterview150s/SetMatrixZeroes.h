#pragma once
#include <vector>
using namespace std;
//73. Set Matrix Zeroes
/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place ( no extra memory).*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nr = matrix.size();
        int nc = matrix[0].size();
        int i, j;
        bool col0 = matrix[0][0] == 0;
        for (i = 0; i < nr; i++) {
            if (matrix[i][0] == 0) col0 = true;
            for (j = 1; j < nc; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (i = nr - 1; i >= 0; i--)
        {
            for (j = nc - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
            if (col0) matrix[i][0] = 0;
        }

    }
};