#pragma once
#include <iostream>
#include <vector>
#include <string> // to_string, stoi, stod....
using namespace std;

//38. Count and Say

/*
* The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), 
which is then converted into a different digit string.
To determine how you "say" a digit string, 
split it into the minimal number of substrings such that each substring contains exactly one unique digit. 
Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.
*/

class Solution {
public:
    string sayStr(string s)
    {
        if (s.length() == 1) {
            return "1" + s;
        }
        string ret = "";
        int i;
        int count = 1;
        char c = s[0];
        for (i = 1; i < s.length(); i++) {
            if (s[i] != s[i - 1]) {
                string count_str = to_string(count);
                ret += count_str;
                ret.push_back(c);
                c = s[i];
                count = 1;
            }
            else {
                count++;
            }
        }
        string c_s = to_string(count);
        ret += c_s;
        ret.push_back(c);
        return ret;
    }
    string countAndSay(int n) {
        vector<string> data;
        data.push_back("1");
        data.push_back("1");
        data.push_back("11");
        for (int i = 3; i <= n; i++) {
            data.push_back(sayStr(data[i - 1]));
        }
        return data[n];

    }
};