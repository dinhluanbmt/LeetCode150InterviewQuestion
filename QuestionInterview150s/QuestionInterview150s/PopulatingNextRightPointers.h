#pragma once
#include <queue>
using namespace std;

//116. Populating Next Right Pointers in Each Node
//You are given a perfect binary tree where all leaves are on the same level, and every parent has two children.The binary tree has the following definition :
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//Populate each next pointer to point to its next right node.If there is no next right node, the next pointer should be set to NULL.
//Initially, all next pointers are set to NULL.

//Recursive Solution
class Solution_Recursive {
public:
    void visit(Node* root) {
        if (!root) return;
        if (root->left && root->right) {
            root->left->next = root->right;
            if (root->next) {
                root->right->next = root->next->left;
            }
        }
        visit(root->left);
        visit(root->right);

    }
    Node* connect(Node* root) {
        if (!root) return root;
        visit(root);
        return root;
    }
};

//Iterative
class Solution_Iterative {
public:

    Node* connect(Node* root) {
        if (!root) return root;
        Node* prv = root;
        Node* cur = nullptr;
        while (prv) {
            cur = prv;
            while (cur && cur->left) {
                cur->left->next = cur->right;
                if (cur->next) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            prv = prv->left;
        }
        return root;
    }
};

// Queue
class Solution_Queue {
public:

    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> mq;
        mq.push(root);
        Node* tn = nullptr;
        int i, size;
        Node* prv = nullptr;
        while (!mq.empty()) {
            size = mq.size();
            prv = nullptr;
            for (i = 0; i < size; i++) {
                tn = mq.front();
                mq.pop();
                if (prv) prv->next = tn;
                if (tn->left) {
                    mq.push(tn->left);
                }
                if (tn->right) mq.push(tn->right);
                if (size > 1) {
                    prv = tn;
                }
            }
        }
        return root;
    }
};