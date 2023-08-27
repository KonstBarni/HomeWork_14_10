#include <iostream>
#include <string>
#include <vector>
#include "Functions.h"
#include "Trie.h"

using namespace std;
const string& choiceWord(vector<string> words)        //выбор слова из вектора
{
    int messIndex = 0;
    
    cin >> messIndex;
    if(cin.bad())
    {
        cin.clear();
        cout << "Its not a number!" << endl;
    }

    if(messIndex < 0 || messIndex > words.size())
    {
        cout << "Incorrect number of word!" << endl;
        cin.clear();
    }
    return words[messIndex];
}

bool inputMess(TrieNode* dict)
{
    string message;     //  конечное сообщение
    string inpWord;     // вводимое слово

    cout << "Enter the message (input '/' to quit, ore '*' to show available words)" << endl;

    cin >> inpWord;

    if (!inpWord.empty()) 
        cout << message;

    if (inpWord.find('/') != std::string::npos) 
    {
        return false;
    }

    if (inpWord.find('*') != std::string::npos) 
    {
        inpWord.pop_back();
        cout << "Choose the right word and press the corresponding number" << endl;
    
        int comp = printAutoFillWords(dict, inpWord);

        if (comp == -1) 
        {
            cout << "No other strings found with this prefix" << endl;
            inpWord.clear();
        }
        else if (comp == 0) 
        {
            cout << "No string found with this prefix" << endl;
            inpWord.clear();
        }

        TrieNode* pNode = dict;
        for (char s : inpWord) 
        {
            int ind = ((int) s) - (int)'a';
            pNode = pNode->children[ind];
        }

        vector<string> vtr;
        vector<string> words = findWords(pNode, inpWord, vtr);
        inpWord.clear();
        inpWord = choiceWord(words);
    }
    message += inpWord;
    cout <<"Yuor message: "<< message <<endl;
    return true;
}