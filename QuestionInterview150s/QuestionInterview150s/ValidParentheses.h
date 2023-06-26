#pragma once
#include <iostream>
#include <stack>
#include <string>
using namespace std;

//20. Valid Parentheses

/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/

class Solution {
public:
    bool isValid(string s) {
        unsigned size = s.length();
        if (size <= 1 || s == "") return false;
        if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
        stack<char> st;
        st.push(s[0]);
        int i;
        for (i = 1; i < size; i++) {
            switch (s[i]) {
            case ')': {
                if (st.size() == 0) return false;
                if (st.top() == '(') st.pop();
                else return false;
                break;
            }
            case '}': {
                if (st.size() == 0) return false;
                if (st.top() == '{') st.pop();
                else return false;
                break;
            }
            case ']': {
                if (st.size() == 0) return false;
                if (st.top() == '[') st.pop();
                else return false;
                break;
            }
            default:
                st.push(s[i]);
            }
        }
        if (st.size() == 0) return true;
        return false;
    }
};
