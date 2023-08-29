#pragma once
#include <iostream>
using namespace std;

//206. Reverse Linked List
/*Given the head of a singly linked list, reverse the list, and return the reversed list.*/



//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode* cur, * next;
        ListNode* prv = head;
        cur = head->next;
        next = cur->next;
        cur->next = prv;
        prv->next = nullptr;
        while (next) {
            prv = cur;
            cur = next;
            next = next->next;
            cur->next = prv;

        }
        return cur;

    }
};