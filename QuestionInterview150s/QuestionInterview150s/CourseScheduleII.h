#pragma once
#include <vector>
#include <queue>
using namespace std;

//210. Course Schedule II

/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. 
If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegrees(numCourses, 0);
        for (auto& ed : prerequisites) {
            graph[ed[1]].push_back(ed[0]);
            indegrees[ed[0]]++;
        }
        int i;
        vector<int> result;
        queue<int> mq;
        for (i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0) {
                mq.push(i);
            }
        }
        if (mq.empty()) return result;
        int vertex;
        while (!mq.empty()) {
            vertex = mq.front();
            mq.pop();
            result.push_back(vertex);
            for (i = 0; i < graph[vertex].size(); i++) {
                indegrees[graph[vertex][i]]--;
                if (indegrees[graph[vertex][i]] == 0)
                    mq.push(graph[vertex][i]);
            }
        }
        if (result.size() != numCourses) return vector<int>();

        return result;

    }
};
