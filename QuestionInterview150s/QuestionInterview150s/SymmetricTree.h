#pragma once
#include <iostream>
#include <stack>
using namespace std;

//101. Symmetric Tree
/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).*/

//======Recursive====

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//=====Non Recursive ====
class Solution_NonRecursive {
public:
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        TreeNode* ln = nullptr;
        TreeNode* rn = nullptr;
        while (!st.empty()) {
            rn = st.top();
            st.pop();
            ln = st.top();
            st.pop();
            if (!rn && !ln) continue;
            if (rn && ln) {
                if (rn->val != ln->val) return false;
                else {
                    st.push(ln->left);
                    st.push(rn->right);
                    st.push(ln->right);
                    st.push(rn->left);
                }
            }
            else return false;
        }
        return true;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution_Recursive {
public:
    bool valid(TreeNode* lroot, TreeNode* rroot) {
        if (!lroot && !rroot) return true;
        if (lroot && rroot) {
            if (lroot->val == rroot->val) {
                bool ret = valid(lroot->right, rroot->left);
                if (ret) return valid(lroot->left, rroot->right);
                else return false;
            }
            else return false;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return true;
        return valid(root->left, root->right);
    }
};