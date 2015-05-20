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
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        s.push_back(0);
        TrieNode *p2,*p1=root;
        unsigned int i;
        for(i=0;i<s.size();i++)
        {
            p2=this->FindChar(p1,s[i]);
            if(p2==NULL) break;
            p1=p2;
        }
        while(i<s.size())
        {
            p1=this->AddChar(p1,s[i++]);
        }
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        key.push_back(0);
        TrieNode *p=root;
        for(unsigned int i=0;i<key.size();i++)
        {
            p=this->FindChar(p,key[i]);
            if(p==NULL) return false;
        }
        return true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        TrieNode *p=root;
        for(unsigned int i=0;i<prefix.size();i++)
        {
            p=this->FindChar(p,prefix[i]);
            if(p==NULL) return false;
        }
        return true;
    }

private:
    TrieNode* FindChar(TrieNode *parent ,char c)
    {
        if(parent==NULL) return NULL;
        for(unsigned int i=0;i<parent->children.size();i++)
        {
            if(parent->children[i]->c==c) return parent->children[i];
        }
        return NULL;
    }
    TrieNode* AddChar(TrieNode *parent ,char c)
    {
        if(parent==NULL) return NULL;
        TrieNode *p=new TrieNode(c);
        parent->children.push_back(p);
        return p;
    }
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

#endif // TRIE_H
