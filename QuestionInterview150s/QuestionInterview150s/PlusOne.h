#pragma once
#include <vector>
using namespace std;

//66. Plus One
/*You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.*/

vector<int> plusOne(vector<int>& digits) {
    size_t size = digits.size() - 1;
    int carry = 0;
    int tem;
    tem = digits[size] + 1;
    if (tem > 9) {
        digits[size] = tem % 10;
        carry = 1;
    }
    else {
        digits[size] = tem;
        carry = 0;
    }
    for (int i = size - 1; i >= 0; i--) {
        tem = digits[i] + carry;
        if (tem > 9) {
            digits[i] = tem % 10;
            carry = 1;
        }
        else {
            carry = 0;
            digits[i] = tem;
        }
    }
    if (carry > 0) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}