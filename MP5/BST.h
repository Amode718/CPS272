#include <iostream>
#include <string>
#include <vector>
using namespace std;

class node
{
public:
    string word;
    node *left, *right;

    node();

};

class BST
{

private:
    int count;
    vector<string> words_inorder;
    vector<string> words_postorder;
    vector<string> words_preorder;
    void inorder(node *parent);
    void postorder(node *parent);
    void preorder(node *parent);
    int count_leaves(node *parent, int n);
    int count_height(node *parent, int n);

public:
    node *root;
    BST();
    void insert(string w, node *parent);
    vector<string> traverse_inorder();
    vector<string> traverse_postorder();
    vector<string> traverse_preorder();
    int get_leaves_count();
    int get_height();
    

};

