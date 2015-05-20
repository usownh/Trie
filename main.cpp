#include <iostream>
#include <trie.h>
using namespace std;

int main()
{
    Trie tree;
    tree.insert("sports");
    tree.insert("slice");
    cout << tree.search("slice")<<endl;
    cout << tree.search("sl")<<endl;
    cout << tree.startsWith("sl")<<endl;
    cout << tree.startsWith("slice")<<endl;

    cout << "Hello World!" << endl;
    return 0;
}

