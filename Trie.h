#pragma once
#include <string>

#define ALPHABET_SIZE 26

struct TrieNode         //префиксное дерево
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    int count;
};

//char rus = 'а';                 //символ кириллицы
//char* buf[100];                 //массив чаров для сохранения ключей
TrieNode *getNewNode(void);                                 //создать дерево
void insert(TrieNode* root, std::string key);               //вставка по ключу
bool search(struct TrieNode *root, std::string key);        //поиск по ключу
bool isEmpty(TrieNode* root);                               //проверка на пустоту
TrieNode* remove(TrieNode* root, std::string key, int depth);
//TrieNode* remove(TrieNode* root, std::string& key, int depth = 0);       //удаление значения
void findMinPrefixes(TrieNode* root, char buf[], int ind, std::string& res);    //кротчайшие префиксы
void findPrefix(TrieNode* root, std::string prefix);
int printAutoFillWords(TrieNode* root, const std::string query);