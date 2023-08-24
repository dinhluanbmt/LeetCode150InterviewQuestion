#pragma once
#include <vector>
using namespace std;
//134. Gas Station
/*There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. 
If there exists a solution, it is guaranteed to be unique*/

class Solution {
public:

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i;
        int t_cost = 0;
        int t_gas = 0;
        int cur_gas = 0;
        int pos = 0;
        for (i = 0; i < gas.size(); i++) {
            t_cost += cost[i];
            t_gas += gas[i];
            cur_gas += (gas[i] - cost[i]);
            if (cur_gas < 0) {
                cur_gas = 0;
                pos = i + 1;
            }
        }
        return t_cost > t_gas ? -1 : pos;

    }
};
