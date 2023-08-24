#pragma once
#include <stack>
using namespace std;

//155. Min Stack
/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.*/

class MinStack {
    stack<int> mst;
    int min;
public:
    MinStack() {
        min = INT_MAX;
    }

    void push(int val) {
        if (val < min) min = val;
        mst.push(val);
    }
    void updateMin() {
        stack<int> tst;
        int v;
        min = INT_MAX;
        while (mst.size() > 0) {
            v = mst.top();
            if (v < min) min = v;
            tst.push(v);
            mst.pop();
        }
        while (tst.size() > 0)
        {
            mst.push(tst.top());
            tst.pop();
        }
    }
    void pop() {
        int val = mst.top();
        mst.pop();
        if (val == min) {
            //update min
            updateMin();
        }
    }

    int top() {
        return mst.top();
    }

    int getMin() {
        return min;
    }
};