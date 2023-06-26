#pragma once
#include <iostream>
using namespace std;

// 21. Merge Two Sorted Lists
/*You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.*/


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return list1;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* p1 = list1;
        ListNode* prev_1 = list1;// last inserted pos;
        ListNode* p2 = list2; // item to insert

        //insert list2 val into list1 one by one
        while (p2 != nullptr) {
            p1 = prev_1;
            list2 = list2->next;// move to next item
            p2->next = nullptr;// isolate p2 to prevent affect to list2
            //inset to head
            if (p2->val <= list1->val) { //p2 become head of list1.
                p2->next = list1;
                list1 = p2;
                prev_1 = list1;
            }
            else { //find pos in list1 to insert
                while (p1 != nullptr && p1->val <= p2->val) {
                    prev_1 = p1;
                    p1 = p1->next;
                }
                if (p1 == nullptr) {
                    prev_1->next = p2;
                    p2->next = nullptr;
                    prev_1 = p2;
                }
                else {
                    p2->next = p1;
                    prev_1->next = p2;
                    prev_1 = p2;
                }
            }
            p2 = list2;//get next item
        }
        return list1;
    }
};