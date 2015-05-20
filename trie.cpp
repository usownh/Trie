#include "trie.h"

Trie::Trie()
{
    root = new TrieNode();
}

void Trie::insert(string s)
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
bool Trie::search(string key)
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

bool Trie::startsWith(string prefix)
{
    TrieNode *p=root;
    for(unsigned int i=0;i<prefix.size();i++)
    {
        p=this->FindChar(p,prefix[i]);
        if(p==NULL) return false;
    }
    return true;
}
TrieNode* Trie::FindChar(TrieNode *parent ,char c)
{
    if(parent==NULL) return NULL;
    for(unsigned int i=0;i<parent->children.size();i++)
    {
        if(parent->children[i]->c==c) return parent->children[i];
    }
    return NULL;
}
TrieNode* Trie::AddChar(TrieNode *parent ,char c)
{
    if(parent==NULL) return NULL;
    TrieNode *p=new TrieNode(c);
    parent->children.push_back(p);
    return p;
}
