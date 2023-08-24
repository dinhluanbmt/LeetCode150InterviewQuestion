#pragma once
#include <vector>
#include <queue>
using namespace std;

//130. Surrounded Regions

/*Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.*/
struct pos {
    int r, c;
    pos() { r = c = -1; }
    pos(int a, int b) { r = a; c = b; }
};
class Solution {
public:
    void visit(vector<vector<char>>& board, int r, int c) {
        if (r< 0 || r > board.size() - 1) return;
        if (c< 0 || c> board[0].size() - 1) return;
        if (board[r][c] != 'O') return;
        board[r][c] = '1';
        visit(board, r - 1, c);
        visit(board, r + 1, c);
        visit(board, r, c - 1);
        visit(board, r, c + 1);
    }
    //visit non recursive (queue)
    void visit_qeue(vector<vector<char>>& board, int r, int c) {
        if (r< 0 || r > board.size() - 1) return;
        if (c< 0 || c> board[0].size() - 1) return;
        if (board[r][c] != 'O') return;
        queue<pos> mq;
        mq.push(pos(r, c));
        pos tem;
        int size, i;
        while (!mq.empty()) {
            size = mq.size();
            for (i = 0; i < size; i++) {
                tem = mq.front();
                mq.pop();
                if (tem.r < 0 || tem.c < 0 || tem.r > board.size() - 1 || tem.c > board[0].size() - 1) continue;
                if (board[tem.r][tem.c] == 'O') {
                    board[tem.r][tem.c] = '1';
                    if (tem.r > 0 && board[tem.r - 1][tem.c] == 'O') mq.push(pos(tem.r - 1, tem.c));
                    if (tem.r < board.size() - 1 && board[tem.r + 1][tem.c] == 'O') mq.push(pos(tem.r + 1, tem.c));
                    if (tem.c > 0 && board[tem.r][tem.c - 1] == 'O') mq.push(pos(tem.r, tem.c - 1));
                    if (tem.c < board[0].size() - 1 && board[tem.r][tem.c + 1] == 'O') mq.push(pos(tem.r, tem.c + 1));
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return;
        int r, c;
        // r = 0 vs r = board.size() -1;
        int first = 0;
        int last = board.size() - 1;
        for (c = 0; c < board[0].size(); c++) {
            if (board[first][c] == 'O') visit(board, first, c);
            if (board[last][c] == 'O') visit(board, last, c);
        }
        last = board[0].size() - 1;
        for (r = 1; r < board.size() - 1; r++) {
            if (board[r][first] == 'O') visit(board, r, first);
            if (board[r][last] == 'O') visit(board, r, last);
        }
        for (r = 0; r < board.size(); r++) {
            for (c = 0; c < board[0].size(); c++) {
                if (board[r][c] != '1') board[r][c] = 'X';
                if (board[r][c] == '1') board[r][c] = 'O';
            }
        }

    }
};