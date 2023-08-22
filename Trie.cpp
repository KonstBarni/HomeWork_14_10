#include <string>
#include <iostream>
#include "Trie.h"

using namespace std;

//TrieNode* poc = getNewNode();
// Возвращает новый узел с пустыми детьми
TrieNode *getNewNode(void)
{
   // Выделяем память под новый узел
   struct TrieNode *pNode =  new TrieNode;

   // устанавливаем флаг конца слова в false
   pNode->isEndOfWord = false;
   pNode->count = 0;

   // инициализируем детей нулевым указателем
   for (int i = 0; i < ALPHABET_SIZE; i++)
       pNode->children[i] = nullptr;

   return pNode;
}

// Вставляет ключ в дерево, если его нет, 
// иначе если ключ явлется префксом узла дерева 
// помечает вкачестве литового т.е. конец слова
void insert(TrieNode* root, string key) 
{
    struct TrieNode* pNode = root;

    for(int i = 0; i < key.length(); i++)
    {
        if(!root)
            root = getNewNode();

        int index = key[i] - 'a';

        if(!pNode->children[index])
        {
            pNode->children[index] = getNewNode();
            pNode->count++;
        }
        pNode = pNode->children[index];
    }
    root->isEndOfWord = true;
}

// Возвращает true если ключ есть в дереве, иначе false
bool search(struct TrieNode *root, string key)
{
   TrieNode *node = root;

   for (int i = 0; i < key.length(); i++)
   {
       int index = key[i] - 'a';  
       if (!node->children[index])
           return false;

       node = node->children[index];
   }

   return (node != nullptr && node->isEndOfWord);
}

// Возвращает true если root имеет лист, иначе false
bool isEmpty(TrieNode* root)
{
   for (int i = 0; i < ALPHABET_SIZE; i++)
       if (root->children[i])
           return false;
   return true;
}

// Рекурсивная функция удаления ключа из дерева
TrieNode* remove(TrieNode* root, string key, int depth = 0)
{
   // Если дерево пустое
   if (!root)
       return nullptr;
    // Если дошли до конца ключа
   if (depth == key.size()) {
        // Этот узел больше не конец слова
        // поэтому снимаем метку
       if (root->isEndOfWord)
           root->isEndOfWord = false;
        // Если ключ не является префиксом, удаляем его
       if (isEmpty(root)) {
           delete (root);
           root = nullptr;
       }

       return root;
   }

   // Пока не дошли до конца ключа или определили, 
   // что его нет в дереве, рекурсивно вызываем для ребенка
   // соответствующего символа
   int index = key[depth] - 'a';        //символ на кириллице
   root->children[index] = remove(root->children[index], key, depth + 1);
   // Если у корня нет дочернего слова
   // (удален только один его дочерний элемент),
   // и он не заканчивается другим словом.
   if (isEmpty(root) && root->isEndOfWord == false) {
       delete (root);
       root = nullptr;
   }
    // возвращаем новый корень
   return root;
}

//поиск префикса
void findPrefix(TrieNode* root, string prefix)
{
    if (root->isEndOfWord)
        cout << prefix << endl;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) 
        {
            char child = 'a' + i;
            findPrefix(root->children[i], prefix + child);
        }
}

//поиск и вывод всех минимальных префиксов
void findMinPrefixes(TrieNode* root, char buf[], int ind, string& res)
{
    if (!root)
        return;
        
    if (root->count == 1)
    {
       buf[ind] = '\0';
       res += buf;
       res +=' ';
       std::cout<< res << std::endl;
       return;  
    }
 
    for (int i=0; i<ALPHABET_SIZE; i++)
    {
        if (root->children[i] != nullptr)
        {        
           buf[ind] = i + 'a'; 
           findMinPrefixes(root->children[i], buf, ind+1, res);
           buf[ind] = '\0';
        }       
    }
}

//вывод всех слов для автозаплонения
int printAutoFillWords(TrieNode* root, const string query)
{
    struct TrieNode* pNode = root;
    for (int i = 0; i < query.length(); i++) 
    {
        int ind = i - 'a';
        //если слово по префиксу не найдено
        if (!pNode->children[ind])
            return 0;
 
        pNode = pNode->children[ind];
    }
    //если префикс является словом
    if (isEmpty(pNode)) {
        cout << query << endl;
        return -1;
    }
    findPrefix(pNode, query);
    return 1;
}