#pragma once
#include <vector>
#include <stack>
#include <string>
using namespace std;

//150. Evaluate Reverse Polish Notation
/*You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mst;
        int val1, val2;
        for (auto s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                if (mst.size() < 2) return 0;
                val1 = mst.top();
                mst.pop();
                val2 = mst.top();
                mst.pop();
                if (s == "+") {
                    mst.push(val1 + val2);
                }
                else
                    if (s == "-") {
                        mst.push(val2 - val1);
                    }
                    else
                        if (s == "*") {
                            mst.push(val1 * val2);
                        }
                        else {
                            mst.push(val2 / val1);
                        }
            }
            else {
                mst.push(stoi(s));
            }

        }
        return mst.top();

    }
};