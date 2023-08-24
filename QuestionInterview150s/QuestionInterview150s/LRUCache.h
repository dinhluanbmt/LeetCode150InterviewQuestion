#pragma once
#include <iostream>
#include <memory>
#include <unordered_map>
using namespace std;

//146. LRU Cache
/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:
LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. 
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.*/

// original pointer give better peformance but just practice to use shared_ptr 
struct Node {
    int key;
    int val;
    shared_ptr<Node> next;
    shared_ptr<Node> prev;
    Node(int k = -1, int v = -1) {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache
{
    int capacity;
    unordered_map<int, shared_ptr<Node>> um;
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = shared_ptr<Node>(new Node());
        tail = shared_ptr<Node>(new Node());
        head->next = tail;
        tail->prev = head;
    }
    void addFront(shared_ptr<Node> node) {
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }
    void move2Front(shared_ptr<Node> node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        head->next->prev = node;
        node->next = head->next;
        head->next = node;
        node->prev = head;
    }
    void removeLast() {
        um.erase(tail->prev->key);
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
    }
    int get(int key) {
        auto it = um.find(key);
        if (it != um.end()) {
            //update the LRU 
            move2Front(it->second);
            return it->second->val;
        }
        return -1;
    }
    void put(int key, int val) {
        auto it = um.find(key);
        if (it != um.end()) {
            it->second->val = val;
            move2Front(it->second);
        }
        else {
            if (um.size() == capacity) {
                removeLast();
            }
            shared_ptr<Node> tn(new Node(key, val));
            um[key] = tn;
            addFront(tn);
        }
    }

};
