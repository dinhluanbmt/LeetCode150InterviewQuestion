#pragma once
#include <iostream>
using namespace std;
//160. Intersection of Two Linked Lists
/*Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.*/


 //Definition for singly-linked list.
 struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode* getTail(ListNode* head, int& size) {
        if (!head) return head;
        ListNode* node = head;
        size = 1;
        while (node->next) {
            size++;
            node = node->next;
        }
        return node;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int sa = 0;
        int sb = 0;
        ListNode* tailA = getTail(headA, sa);
        ListNode* tailB = getTail(headB, sb);
        if (tailA != tailB) return nullptr;
        // becareful ..........in case of sa = sb
        //ListNode* longer = sa > sb ? headA : headB;      ==> longer = headB  
        //ListNode* shorter = sa < sb ? headA : headB;   ==> shorter = headB

        ListNode* longer = sa < sb ? headB : headA;
        ListNode* shorter = sa < sb ? headA : headB;

        int dif = abs(sa - sb);
        while (longer && dif > 0) {
            dif--;
            longer = longer->next;
        }
        while (longer  && shorter ) {
            if (longer == shorter) {
                return longer;
            }
            longer = longer->next;
            shorter = shorter->next;
        }
        return nullptr;
    }
};