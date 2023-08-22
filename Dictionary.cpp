#include "Dictionary.h"

TrieNode* createDict()
{
    TrieNode* dict = getNewNode();

    insert(dict, "hi");
    insert(dict, "hello");
    insert(dict, "how");
    insert(dict, "are");
    insert(dict, "you");
    insert(dict, "amazing");
    insert(dict, "yang");
    insert(dict, "old");
    insert(dict, "wonderful");
    insert(dict, "when");
    insert(dict, "am");
    insert(dict, "anower");
    insert(dict, "my");
    insert(dict, "friend");
    insert(dict, "best");
    insert(dict, "heve");
    insert(dict, "bonus");

    return dict;
}