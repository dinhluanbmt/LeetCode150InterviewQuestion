#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//104. Maximum Depth of Binary Tree
/*Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//====Recursive =========
class Solution {
public:
    int getmax(TreeNode* root, int cur) {
        if (!root) return cur;
        return max(getmax(root->left, cur + 1), getmax(root->right, cur + 1));
    }
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return getmax(root, 1) - 1;
    }
};

//=== Non Recursive ======
class Solution_non_recursive {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (!root) return depth;
        queue<TreeNode*> mq;
        mq.push(root);
        int size, i;
        TreeNode* tn;
        while (!mq.empty()) {
            size = mq.size();
            depth++;
            for (i = 0; i < size; i++) {
                tn = mq.front();
                mq.pop();
                if (tn->left) mq.push(tn->left);
                if (tn->right) mq.push(tn->right);
            }
        }
        return depth;
    }
};