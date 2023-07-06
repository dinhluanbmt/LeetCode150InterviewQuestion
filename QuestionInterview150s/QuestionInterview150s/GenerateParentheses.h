#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//22. Generate Parentheses
/*
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

// recursive solution
class Solution {
public:
    vector<string> ret;
    void generate(int n, int open, int close, string str) {
        if (open == close && n == open) {
            ret.push_back(str);
            return;
        }
        if (open < n) {
            generate(n, open + 1, close, str + '(');
        }
        if (open > close) {
            generate(n, open, close + 1, str + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        generate(n, 1, 0, "(");
        return ret;
    }
};

// no recursive
struct info {
    int open;
    int close;
    string cur;
    info(int op, int cl, string  str) {
        open = op;
        close = cl;
        cur = str;
    }
};
class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> retV;
        queue<info> mq;
        info q1(1, 0, "(");
        mq.push(q1);
        while (!mq.empty())
        {
            info t_if = mq.front();
            mq.pop();
            if (t_if.open == t_if.close && t_if.open == n) {
                retV.push_back(t_if.cur);
            }
            else {
                if (t_if.open < n) {
                    mq.push({ t_if.open + 1,t_if.close,t_if.cur + "(" });
                }
                if (t_if.close < t_if.open) {
                    mq.push({ t_if.open, t_if.close + 1, t_if.cur + ")" });
                }
            }
        }
        return retV;
    }
};