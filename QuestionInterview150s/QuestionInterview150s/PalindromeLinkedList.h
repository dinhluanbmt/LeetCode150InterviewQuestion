#pragma once
#include <iostream>
#include <vector>
using namespace std;

//234. Palindrome Linked List


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return false;
        vector<int> iVec;
        ListNode* node = head;
        while (node) {
            iVec.push_back(node->val);
            node = node->next;
        }
        int l = 0;
        int r = iVec.size() - 1;
        while (l < r) {
            if (iVec[l] != iVec[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};

//===========
class Solution_reverseList {
public:
    ListNode* copyReverse(ListNode* head) {
        if (!head) return head;
        ListNode* rhead = nullptr;
        ListNode* it = head;
        while (it) {
            ListNode* nn = new ListNode(it->val);
            nn->next = rhead;
            rhead = nn;
            it = it->next;

        }
        return rhead;
    }
    bool isPalindrome(ListNode* head) {
        if (!head) return false;
        ListNode* rhead = copyReverse(head);
        ListNode* rn = rhead;
        ListNode* n = head;
        while (rn && n) {
            if (rn->val != n->val) return false;
            rn = rn->next;
            n = n->next;
        }
        return true;

    }
};