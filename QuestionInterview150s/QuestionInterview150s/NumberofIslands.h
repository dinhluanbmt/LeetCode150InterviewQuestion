#pragma once
#include <vector>
using namespace std;

//200. Number of Islands

/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.*/

class Solution {
public:
    void clearCell(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();
        if (r < 0 || c < 0 || r >= nr || c >= nc) return;
        if (grid[r][c] != '1') return;
        grid[r][c] = '0';
        clearCell(grid, r, c - 1);
        clearCell(grid, r, c + 1);
        clearCell(grid, r - 1, c);
        clearCell(grid, r + 1, c);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int row, col;
        for (row = 0; row < grid.size(); ++row)
        {
            for (col = 0; col < grid[0].size(); ++col)
            {
                if (grid[row][col] == '1')
                {
                    count++;
                    clearCell(grid, row, col);
                }
            }
        }
        return count;
    }
};