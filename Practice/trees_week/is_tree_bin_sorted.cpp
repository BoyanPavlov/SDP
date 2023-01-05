#include <iostream>
#include "tree_utils.h"

template <class T>
bool isBinTreeSorted(Tree<T> *node)
{
    if (!node)
    {
        return true;
    }
    if (node->left)
    {
        if (node->left->data > node->data)
        {
            return false;
        }
    }
    if (node->right)
    {
        if (node->right->data < node->data)
        {
            return false;
        }
    }

    return isBinTreeSorted(node->left) && isBinTreeSorted(node->right);
}