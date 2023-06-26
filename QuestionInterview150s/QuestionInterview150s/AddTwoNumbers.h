#pragma once
#include <iostream>
/* 2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/



// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 // Time complexity Max(M,N) where M is lenght of l1, N is length of l2
 class Solution {
 public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* head = nullptr;
         ListNode* prev = nullptr;
         int  v = 0;
         int carry = 0;
         while (l1 || l2) {
             v = 0;
             if (l1) {
                 v += l1->val;
                 l1 = l1->next;
             }
             if (l2) {
                 v += l2->val;
                 l2 = l2->next;
             }
             v += carry;
             carry = v / 10;
             v = v % 10;
             ListNode* tn = new ListNode(v);
             if (head == nullptr) {
                 head = tn;
                 prev = tn;
             }
             else {
                 prev->next = tn;
                 prev = tn;
             }

         }
         if (carry > 0)
         {
             ListNode* n1 = new ListNode(1);
             prev->next = n1;
         }
         return head;

     }
 };