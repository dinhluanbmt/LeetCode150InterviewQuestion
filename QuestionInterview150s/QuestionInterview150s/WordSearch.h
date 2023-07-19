#pragma once
#include <vector>
#include <string>
using namespace std;
//79. Word Search
/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, 
where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.*/

class Solution {
public:
    bool search(vector<vector<char>>& board, int row, int col, int pos, string word) {
        int nr = board.size();
        int nc = board[0].size();
        if (row < 0 || col < 0 || row >= nr || col >= nc || pos >= word.length()) return false;
        if (pos == word.length() - 1 && board[row][col] == word[pos]) return true;
        if (board[row][col] == word[pos])
        {
            char bk_c = board[row][col];
            board[row][col] = '*';
            bool ret1 = search(board, row, col + 1, pos + 1, word);
            if (ret1) return ret1;
            bool ret2 = search(board, row, col - 1, pos + 1, word);
            if (ret2) return ret2;
            bool ret3 = search(board, row - 1, col, pos + 1, word);
            if (ret3) return ret3;
            bool ret4 = search(board, row + 1, col, pos + 1, word);
            if (ret4) return ret4;
            board[row][col] = bk_c;
            return false;
        }
        else
            return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        int i, j;
        bool ret = false;
        for (i = 0; i < row; ++i)
        {
            for (j = 0; j < col; ++j)
            {
                if (board[i][j] == word[0])
                {
                    ret = search(board, i, j, 0, word);
                    if (ret)
                        return ret;
                }
            }
        }
        return ret;

    }
};
