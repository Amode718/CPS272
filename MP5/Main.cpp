// Andrei Modiga
// CPS-272
// 07/24/2022
// Machine Problem 5
// Binary Trees. Tokenize words and store in a binary tree.

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include "BST.h"
using namespace std;

void printWords(vector<string> words);
void insertIntoBst(BST *t, vector<string> words);

int main()
{
    BST T1;
    BST T2, T3;
    vector<string> post_order_result, pre_order_result, in_order_result;
    string text;
    cout << "\nInsert the text : ";
    getline(cin, text);

    vector<string> words;

    string word = "";
    string delimitters = "\"' .,/?:;\\{}[]()-+=*&^%$#@!`~\n";
    for (auto x : text)
    {
        if (delimitters.find(x) < delimitters.length())
        {
            if (word != "")
                words.push_back(word);
            word = "";
        }
        else
        {
            word.push_back(tolower(x));
        }
    }
    if (word != "")
        words.push_back(word);

    cout << "\n\n - List of tokenized words" << endl;
    printWords(words);

    cout << "\n\n - Inserting words to T1" << endl;
    insertIntoBst(&T1, words);
    cout << "\n -- Retrieving postorder traversal results" << endl;
    post_order_result = T1.traverse_postorder();
    printWords(post_order_result);

    cout << "\n\n - Inserting results to T2" << endl;
    insertIntoBst(&T2, post_order_result);
    cout << "\n - Retrieving preorder traversal results" << endl;
    pre_order_result = T2.traverse_preorder();
    printWords(pre_order_result);

    cout << "\n\n - Inserting results into T3" << endl;
    insertIntoBst(&T3, pre_order_result);
    cout << "\n - Retrieving inorder traversal results" << endl;
    in_order_result = T3.traverse_inorder();
    printWords(in_order_result);

    cout << "\n\n\n";
    cout << "T1\tLeaves count : " << T1.get_leaves_count() << "\tHeight : " << T1.get_height() << endl;
    cout << "T2\tLeaves count : " << T2.get_leaves_count() << "\tHeight : " << T1.get_height() << endl;
    cout << "T3\tLeaves count : " << T3.get_leaves_count() << "\tHeight : " << T1.get_height() << endl;

    return 0;
}

void printWords(vector<string> words)
{
    cout << endl;
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        cout << *i;
        if (i != words.end() - 1)
            cout << ", ";
    }
    cout << endl;
}

void insertIntoBst(BST *t, vector<string> words)
{
    for (auto i = words.begin(); i != words.end(); ++i)
    {
        t->insert(*i, t->root);
    }
}
