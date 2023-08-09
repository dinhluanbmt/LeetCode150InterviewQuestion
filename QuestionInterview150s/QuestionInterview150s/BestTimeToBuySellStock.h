#pragma once
#include <vector>
using namespace std;

//121. Best Time to Buy and Sell Stock
/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i;
        int size = prices.size();
        if (size == 0 || size == 1) return 0;
        int op = 0;
        int tem;
        int min = prices[0];
        for (i = 1; i < size; i++) {
            if (prices[i] < min) min = prices[i];
            tem = prices[i] - min;
            if (tem > op) op = tem;
        }
        return op;
    }
};
