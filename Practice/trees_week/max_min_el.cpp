#include <iostream>
#include "tree_utils.h"

template <class T>
const T &maxElemBST(Tree<T> *node, const T &elem)
{
    while (node->right)
    {
        node = node->right;
    }
    return node->data;
}

template <class T>
const T &minElemBST(Tree<T> *node, const T &elem)
{
    while (node->left)
    {
        node = node->left;
    }
    return node->data;
}

template <class T>
const T minElem(Tree<T> *node, const T &elem)
{
    if (!node)
    {
        throw std::logic_error("give me a tree, man!\n");
    }

    T result = (elem < node->data ? elem : node->data);

    if (node->left)
    {
        result = minElem(node->left, result);
    }
    if (node->right)
    {
        result = minElem(node->right, result);
    }
    return result;
}

template <class T>
const T maxElem(Tree<T> *node, const T &elem)
{
    if (!node)
    {
        throw std::logic_error("give me a tree, man!\n");
    }

    T result = (elem > node->data ? elem : node->data);

    if (node->left)
    {
        result = maxElem(node->left, result);
    }
    if (node->right)
    {
        result = maxElem(node->right, result);
    }
    return result;
}

int main()
{
    Tree<int> *tree_bst = new Tree<int>(4, new Tree<int>(2), new Tree<int>(6));
    insertInBST(tree_bst, 7);

    std::cout << maxElemBST(tree_bst, tree_bst->data) << std::endl;
    std::cout << minElemBST(tree_bst, tree_bst->data) << std::endl;

    Tree<int> *regularTree = new Tree<int>(2, new Tree<int>(3, new Tree<int>(4), new Tree<int>(5)), new Tree<int>(13, new Tree<int>(7), new Tree<int>(8)));
    printTree(regularTree);
    std::cout << "Maximum element in regular binary tree: " << maxElem(regularTree, regularTree->data) << '\n';
    std::cout << "Minimum element in regular binary tree: " << minElem(regularTree, regularTree->data) << '\n';

    return 0;
}
