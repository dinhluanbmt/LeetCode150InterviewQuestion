#pragma once
#include <vector>
#include <stack>
using namespace std;

//Term: visiting graph/tree
//*********  Inorder (Traversal):  left - root - right
//*********  Preorder(Traversal):  root - left - right
//*********  Postorder(Traversal): left - right - root

//98. Validate Binary Search Tree
/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree  of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.*/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Recursive solution
class Recursive_Solution {
public:
    bool g_ret = true;
    TreeNode* prv = nullptr;
    void check(TreeNode* root) {
        if (!root) return;
        if (root->left) check(root->left);
        if (prv) {
            if (prv->val >= root->val) { g_ret = false; return; }
        }
        prv = root;
        check(root->right);
    }
    bool isValidBST(TreeNode* root) {
        check(root);
        return g_ret;
    }
};

// Non Recursive 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* tn = root;
        TreeNode* prv = nullptr;
        while (tn || !st.empty()) {
            while (tn) {
                st.push(tn);
                tn = tn->left;
            }
            tn = st.top();
            st.pop();
            if (prv) {
                if (prv->val >= tn->val) return false;
            }
            prv = tn;
            tn = tn->right;
        }
        return true;
    }
};
