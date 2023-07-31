#pragma once
#include <vector>
#include <stack>
using namespace std;

//Term: visiting graph/tree
//*********  Inorder (Traversal):  left - root - right
//*********  Preorder(Traversal):  root - left - right
//*********  Postorder(Traversal): left - right - root

  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

//94. Binary Tree Inorder Traversal
/*Given the root of a binary tree, return the inorder traversal of its nodes' values.*/



//Recursive Solution
class Recursive_Solution {
public:
    void travel(vector<int>& tree, TreeNode* root) {
        if (!root) return;
        travel(tree, root->left);
        tree.push_back(root->val);
        travel(tree, root->right);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        travel(ret, root);
        return ret;
    }
};

//Non Recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> mst;
        vector<int> ret;
        TreeNode* tn = root;
        while (tn || !mst.empty()) {
            while (tn) {
                mst.push(tn);
                tn = tn->left;
            }
            tn = mst.top();
            ret.push_back(tn->val);
            mst.pop();
            tn = tn->right;
        }
        return ret;
    }
};