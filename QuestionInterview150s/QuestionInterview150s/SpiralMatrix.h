#pragma once
#include <vector>
using namespace std;

/*Given an m x n matrix, return all elements of the matrix in spiral order.*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        if (nrow == 1) return matrix[0];
        int i;
        vector<int> retV;
        if (ncol == 1) {
            for (i = 0; i < nrow; i++) retV.push_back(matrix[i][0]);
            return retV;
        }
        int sr = 0;//start row
        int sc = 0;//start col
        int endr = nrow - 1;
        int endc = ncol - 1;

        while (sr <= endr && sc <= endc) {
            //get first row lef to right
            for (i = sc; i <= endc; i++) retV.push_back(matrix[sr][i]);
            //get right col, top to bottom
            for (i = sr + 1; i <= endr; i++) retV.push_back(matrix[i][endc]);
            //get bottom row right to left
            if (endr > sr)
                for (i = endc - 1; i >= sc; i--) retV.push_back(matrix[endr][i]);
            //get left col bottom to top
            if (endc > sc)
                for (i = endr - 1; i > sr; i--) retV.push_back(matrix[i][sc]);

            sr++;
            sc++;
            endr--;
            endc--;

        }
        return retV;
    }
};