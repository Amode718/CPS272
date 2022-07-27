#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

node::node()
{
    word = "";
    left = NULL;
    right = NULL;
}

BST::BST()
{
    root = (node *)malloc(sizeof(node));
    count = 0;
}

void BST::insert(string w, node *parent)
{

    if (parent->word == "")
    {
        parent->word = w;
        count++;
        return;
    }
    else
    {
        if (parent->word.compare(w) > 0)
        {
            if (parent->left == NULL)
                parent->left = (node *)malloc(sizeof(node));
            insert(w, parent->left);
        }
        else if (parent->word.compare(w) < 0)
        {
            if (parent->right == NULL)
                parent->right = (node *)malloc(sizeof(node));
            insert(w, parent->right);
        }
    }
}

void BST::inorder(node *parent)
{
    if (parent->left != NULL)
    {
        inorder(parent->left);
    }
    if (parent != NULL)
        words_inorder.push_back(parent->word);
    if (parent->right != NULL)
    {
        inorder(parent->right);
    }
    return;
}

void BST::postorder(node *parent)
{
    if (parent->left != NULL)
    {
        postorder(parent->left);
    }
    if (parent->right != NULL)
    {
        postorder(parent->right);
    }
    if (parent != NULL)
        words_postorder.push_back(parent->word);
}

void BST::preorder(node *parent)
{
    if (parent != NULL)
        words_preorder.push_back(parent->word);
    if (parent->left != NULL)
    {
        preorder(parent->left);
    }
    if (parent->right != NULL)
    {
        preorder(parent->right);
    }
}

int BST::count_leaves(node *parent, int n){
    if (parent->left != NULL)
    {   
        n = count_leaves(parent->left, n);
    }
    if (parent->right != NULL)
    {
        n = count_leaves(parent->right, n);
    }
    if(parent->left == NULL && parent->right == NULL)
        return n+1;
    else
        return n;
}

int BST::count_height(node *parent, int n){
    int x,y;
    if (parent->left != NULL)
    {   
        x = count_leaves(parent->left, n+1);
    }
    if (parent->right != NULL)
    {
        y = count_leaves(parent->right, n+1);
    }
    if(x > y)
        return x;
    else
        return y;
}

vector<string> BST::traverse_inorder()
{
    inorder(root);
    return words_inorder;
}

vector<string> BST::traverse_postorder()
{
    postorder(root);
    return words_postorder;
}

vector<string> BST::traverse_preorder(){
    preorder(root);
    return words_preorder;
}

int BST::get_leaves_count(){
    return count_leaves(root, 0);
}

int BST::get_height(){
    return count_height(root, 0);
}