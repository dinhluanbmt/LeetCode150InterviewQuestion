#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//17. Letter Combinations of a Phone Number
/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/

vector<string> pad{ "","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() <= 0) return vector<string>();
        deque<string> q;
        q.push_back("");
        int i;
        for (char num : digits) {
            for (i = q.size(); i > 0; i--) {
                string tem = q.front();
                q.pop_front();
                for (char c : pad[num - '0']) {
                    q.push_back(tem + c);
                }
            }
        }

        return vector<string>(q.begin(), q.end());

    }
};

// Recursive Solution..
/*
unordered_map<char,string> m{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
vector<string> gRet;
string gStr="";
class Solution {
public:
   void combine(string nums,int idx){
       if(gStr.length() == nums.length()){
           gRet.push_back(gStr);
           return;
       }
       for(int i = 0; i< m[nums[idx]].length();i++){
           gStr.push_back(m[nums[idx]][i]);
           combine(nums,idx+1);
           gStr.pop_back();
       }
   }    
    vector<string> letterCombinations(string digits) {
        gRet.clear();
       if(digits.length() <= 0) return gRet;       
combine(digits, 0);
return gRet;

    }
};
*/
