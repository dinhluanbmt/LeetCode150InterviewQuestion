#pragma once
#include <vector>
#include <queue>
using namespace std;

//103. Binary Tree Zigzag Level Order Traversal
/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ======= Non Recursive (using queue)===
class Solution_non_recursive {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> retVec;
        if (!root) return retVec;
        queue<TreeNode*> mq;
        mq.push(root);
        bool l2r = true;
        TreeNode* tn = nullptr;
        int count = 0;
        int i;
        while (!mq.empty()) {
            count = mq.size();
            vector<int> tv;
            for (i = 0; i < count; i++) {
                tn = mq.front();
                mq.pop();
                if (l2r) {
                    tv.push_back(tn->val);
                }
                else {
                    tv.insert(tv.begin(), tn->val);
                }
                if (tn->left) mq.push(tn->left);
                if (tn->right) mq.push(tn->right);
            }
            l2r = !l2r;
            retVec.push_back(tv);
        }
        return retVec;
    }
};

//======= recursive ===========

class Solution {
public:
    void visit(TreeNode* root, int level, vector<vector<int>>& ret) {
        if (!root) return;
        while (ret.size() < level + 1) {
            vector<int> v;
            ret.push_back(v);
        }
        if (level % 2 == 0) {
            ret[level].push_back(root->val);
            visit(root->left, level + 1, ret);
            visit(root->right, level + 1, ret);
        }
        else {
            ret[level].insert(ret[level].begin(), root->val);
            visit(root->left, level + 1, ret);
            visit(root->right, level + 1, ret);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> retVec;
        visit(root, 0, retVec);
        return retVec;
    }
};