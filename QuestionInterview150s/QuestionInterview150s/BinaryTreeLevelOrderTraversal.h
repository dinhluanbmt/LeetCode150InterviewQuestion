#pragma once
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//102. Binary Tree Level Order Traversal

/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//=====Non Recursive======
class Solution_non_recursive {
public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> retVec;
        if (!root)
            return retVec;
        queue<TreeNode*> q;
        q.push(root);
        int i, size;
        TreeNode* tN;
        while (!q.empty())
        {
            vector<int> tv;
            size = q.size();
            for (i = 0; i < size; ++i)
            {
                tN = q.front();
                q.pop();
                tv.push_back(tN->val);
                if (tN->left) q.push(tN->left);
                if (tN->right) q.push(tN->right);
            }
            retVec.push_back(tv);
        }
        return retVec;
    }
};

//===== Recursive =======
class Solution {
public:
    void visit(TreeNode* root, vector<vector<int>>& ret, int level) {
        if (!root) return;
        while (ret.size() < level + 1) {
            vector<int> v;
            ret.push_back(v);
        }
        ret[level].push_back(root->val);
        visit(root->left, ret, level + 1);
        visit(root->right, ret, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> tree;
        visit(root, tree, 0);
        return tree;
    }
};
