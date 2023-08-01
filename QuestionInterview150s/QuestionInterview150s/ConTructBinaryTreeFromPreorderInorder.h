#pragma once
#include <vector>
using namespace std;

//105. Construct Binary Tree from Preorder and Inorder Traversal
/*Given two integer arrays preorder and inorder 
where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, 
construct and return the binary tree.*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& ridx, int start, int end) {
        if (ridx >= preorder.size()) return nullptr;
        if (start > end) return nullptr;
        int idx = start;
        while (inorder[idx] != preorder[ridx]) idx++;
        TreeNode* tn = new TreeNode(inorder[idx]);
        ridx++;
        tn->left = build(preorder, inorder, ridx, start, idx - 1);
        tn->right = build(preorder, inorder, ridx, idx + 1, end);
        return tn;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ridx = 0;
        TreeNode* root = build(preorder, inorder, ridx, 0, inorder.size() - 1);
        return root;
    }
};