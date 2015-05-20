#ifndef TRIE_H
#define TRIE_H
#include <vector>
#include <string>
using std::vector;
using std::string;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {}
    TrieNode(char c) {this->c=c;}
    char c;
    vector<TrieNode*> children;
};
class Trie
{
public:
    Trie();


    // Inserts a word into the trie.
    void insert(string s);

    // Returns if the word is in the trie.
    bool search(string key);


    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix);


private:
    TrieNode* FindChar(TrieNode *parent ,char c);

    TrieNode* AddChar(TrieNode *parent ,char c);

    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

#endif // TRIE_H
