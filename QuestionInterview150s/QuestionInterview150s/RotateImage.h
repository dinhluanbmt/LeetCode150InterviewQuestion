#pragma once
#include <iostream>
#include <vector>
using namespace std;

//48. Rotate Image
/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row, col;
        int size = matrix.size();
        //swap items between diagonal (up left to down right)
        for (row = 1; row < size; ++row)
        {
            for (col = 0; col < row; ++col)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
        int r_col = size - 1;
        //swap left right items      
        for (col = 0; col < size / 2; ++col)
        {
            for (row = 0; row < size; ++row)
            {
                swap(matrix[row][col], matrix[row][r_col]);
            }
            r_col--;
        }
    }
};