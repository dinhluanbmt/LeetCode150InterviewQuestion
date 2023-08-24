#pragma once
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// a function to merge 2 sorted list
ListNode* merge2SortedList(ListNode* left, ListNode* right) {
    ListNode dummy = ListNode(0);
    ListNode* node = &dummy;
    ListNode* ret = &dummy;
    while (left && right) {
        if (left->val < right->val) {
            node->next = left;
            left = left->next;
        }
        else {
            node->next = right;
            right = right->next;
        }
        node = node->next;
    }
    if (left) node->next = left;
    else node->next = right;

    return ret->next;
}
// example of sort function with lambda expression
class Solution {
public:
    vector<ListNode*> sVec;
    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        ListNode* it = head;
        while (it)
        {
            sVec.push_back(it);
            it = it->next;
        }
        sort(sVec.begin(), sVec.end(), [](const ListNode* n1, const ListNode* n2) {return n1->val < n2->val; });
        for (int i = 1; i < sVec.size(); ++i)
        {
            sVec[i - 1]->next = sVec[i];
        }
        sVec.back()->next = NULL;
        return sVec[0];

    }
};