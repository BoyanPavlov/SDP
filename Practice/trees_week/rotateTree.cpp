#include <iostream>
#include "tree_utils.h"
#include <assert.h>
using std::string;

template <class T>
void rotateLeft(Tree<T> *&root)
{
    Tree<T> *originalRight = root->right;
    root->right = originalRight->left;
    originalRight->left = root;
    root = originalRight;
}

template <class T>
void rotateRight(Tree<T> *&root)
{
    Tree<T> *originalLeft = root->left;
    root->left = originalLeft->right;
    originalLeft->right = root;
    root = originalLeft;
}


int main()
{
    Tree<string>* root = new Tree<string>("X", new Tree<string>("T1", nullptr, nullptr),
                      new Tree<string>("Y", new Tree<string>("T2", nullptr, nullptr),
                                       new Tree<string>("T3", nullptr, nullptr)));
    printTree(root);
    rotateLeft(root);
    printTree(root);
    rotateRight(root);
    printTree(root);
    freeTree(root);
    return 0;
}
