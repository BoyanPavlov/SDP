#include <iostream>
#include "tree_utils.h"
// We may have repeating elements here
// template <class T>
// void insertInBST(Tree<T> *&node, const T &elem)
// {
//     if (!node)
//     {
//         node = new Tree(elem);
//         return;
//     }
//     else if (node->data < elem)
//     {
//         insertInBST(node->right, elem);
//     }
//     else
//     {
//         insertInBST(node->left, elem);
//     }
// }

int main(int argc, char const *argv[])
{
    Tree<int> *example = new Tree<int>(4, new Tree<int>(2), new Tree<int>(6));
    printTree(example);

    insertInBST(example, 7);
    printTree(example);

    // insertInBST(example, 2);
    // printTree(example);

    return 0;
}
