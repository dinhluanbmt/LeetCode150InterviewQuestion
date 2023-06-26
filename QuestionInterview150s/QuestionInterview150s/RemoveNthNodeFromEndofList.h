#pragma once
#include <iostream>
using namespace std;

//19. Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* it = head;       
        int count = 1;
        while (it != nullptr) {
            if (count == n)break;
            count++;
            it = it->next;
        }
        if (count < n) return head;
        ListNode* prev;
        ListNode* cur = head;
        if (it->next == nullptr) {
            head = head->next;
            delete cur;
            return head;
        }
        while (it->next != nullptr) {
            it = it->next;
            prev = cur;
            cur = cur->next;

        }
        prev->next = cur->next;
        delete cur;
        return head;

    }
};