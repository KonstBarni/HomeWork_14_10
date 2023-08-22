#include <iostream>
#include <string>
#include "Functions.h"
#include "Trie.h"

using namespace std;

bool inputMess(TrieNode* dict)
{
    string message;

    cout << "\x1B[33mYour word (type '/' to eqit; '.' to clean word):\033[0m" << endl;

    if (!message.empty()) 
        cout << message;

    std::string add_word;
    cin >> add_word;

    if (add_word.find('/') != std::string::npos) 
    {
        return false;
    }

    if (add_word.find('.') != std::string::npos) {message.clear();}
        message += add_word;

    cout << "\x1B[35mSuggestions:\033[0m" << endl;

    int comp = printAutoFillWords(dict, message);

    if (comp == -1) 
    {
        cout << "\x1B[31mNo other strings found with this prefix\041" << endl;
        message.clear();
    }
    else if (comp == 0) 
    {
        cout << "\x1B[31mNo string found with this prefix\041" << endl;
        message.clear();
    }
    return true;
}