#include <iostream>
#include <string>
#include "Trie.h"
#include "Dictionary.h"
#include "Functions.h"

using namespace std;

int main()
{   
    bool isWork{true};
    TrieNode* dict = createDict();

    while(isWork)
    {
        isWork = inputMess(dict);
    }

    return 0;
}