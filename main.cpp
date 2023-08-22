#include <iostream>
#include <string>
#include "Trie.h"
#include "Dictionary.h"

using namespace std;

int main()
{
    string res;
    char buf[100]{};
    
    TrieNode* dict = createDict();
    findMinPrefixes(dict, buf, 0, res);
    string serch = "he";
    findPrefix(dict, serch);
    return 0;
}