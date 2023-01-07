#ifndef _TREE_UTILS_
#define _TREE_UTILS_

#include <iostream>
using std::cout;
using std::endl;

template <class T>
struct Tree
{
    T data;
    Tree<T> *left;
    Tree<T> *right;

    Tree(const T &elem, Tree<T> *l = nullptr, Tree<T> *r = nullptr)
        : left(l), right(r), data(elem){};
};

template <class T>
void freeTree(Tree<T> *&tr)
{
    if (!tr)
    {
        return;
    }
    freeTree(tr->left);
    freeTree(tr->right);
    delete tr;
}

template <class T>
bool containsBST(const Tree<T> *t, const T &elem)
{
    if (t == nullptr)
    {
        return false;
    }
    if (t->data == elem)
    {
        return true;
    }
    if (t->data < elem)
    {
        return containsBST(t->right, elem);
    }
    // else t->data > elem
    return containsBST(t->left, elem);
}

template <class T> // same in logic as insertInBST in new_branch_sorted.cpp ?!?
void insertInBST(Tree<T> *&node, const T &elem, bool hasDublicate = true)
{
    if (!node)
    {
        node = new Tree(elem);
        return;
    }
    else if (node->data < elem)
    {
        insertInBST(node->right, elem, hasDublicate);
    }
    else if (node->data > elem || hasDublicate)
    {
        insertInBST(node->left, elem, hasDublicate);
    }
}

template <class T>
void printBT(const std::string &prefix, const Tree<T> *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "`--");

        std::cout << node->data << std::endl;

        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

template <class T>
void printTree(const Tree<T> *node)
{
    printBT("", node, false);
}

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

template <class T>
Tree<T> *clone(const Tree<T> *t)
{
    if (!t)
        return nullptr;

    return new Tree<T>(t->data, clone(t->left), clone(t->right));
}


#endif // _TREE_UTILS_