#pragma once
#include <iostream>
#include <vector>
using namespace std;

//36. Valid Sudoku
/*
* Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int cols[9][9];
        int boxes[9][9];
        memset(rows, 0x00, sizeof(rows));
        memset(cols, 0x00, sizeof(cols));
        memset(boxes, 0x00, sizeof(boxes));
        int i, j;
        int val;
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    val = board[i][j] - '1';
                    if (++rows[i][val] > 1 || ++cols[j][val] > 1 || ++boxes[(i / 3) * 3 + j / 3][val] > 1) return false;
                }
            }
        }
        return true;
    }
};