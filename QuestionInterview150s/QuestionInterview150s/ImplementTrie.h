#pragma once
#include <string>
using namespace std;

//208. Implement Trie (Prefix Tree)

/*A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.*/

class Node {
public:
    bool isword;
    Node* nList[26];

    Node(bool w = false) {
        isword = w;
        for (auto& n : nList) n = nullptr;
    }
    ~Node() {
        for (auto n : nList) delete n;
    }
};
class Trie {
    Node root;
public:
    Trie() {

    }
    void insert(string s) {
        Node* cur = &root;
        for (char& c : s) {
            if (!cur->nList[c - 'a']) {
                cur->nList[c - 'a'] = new Node();
            }
            cur = cur->nList[c - 'a'];
        }
        cur->isword = true;
    }
    bool search(string key, bool prefix = false) {
        Node* cur = &root;
        for (char& c : key) {
            if (!cur) return false;
            cur = cur->nList[c - 'a'];
        }
        if (!cur) return false;
        if (prefix) return true;
        if (cur->isword) return true;
        return false;
    }
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};