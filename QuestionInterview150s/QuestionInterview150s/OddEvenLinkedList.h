#pragma once
#include <iostream>
//328. Odd Even Linked List
/*Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity*/

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even_head = head->next;
        ListNode* even = even_head;
        ListNode* last_o = odd;
        ListNode* last_e = even;
        ListNode* runner = even->next;
        while (runner) {
            odd->next = runner;
            odd = odd->next;
            if (odd) last_o = odd;
            even->next = runner->next;
            even = even->next;
            if (even) last_e = even;
            if (runner->next) {
                runner = runner->next->next;
            }
            else break;
        }
        last_o->next = even_head;
        last_e->next = nullptr;
        return head;

    }
};