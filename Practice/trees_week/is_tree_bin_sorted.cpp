#include <iostream>
#include "tree_utils.h"

//added to utils
// template <class T>
// bool isBinTreeSorted(Tree<T> *node)
// {
//     if (!node)
//     {
//         return true;
//     }
//     if (node->left)
//     {
//         if (node->left->data > node->data)
//         {
//             return false;
//         }
//     }
//     if (node->right)
//     {
//         if (node->right->data < node->data)
//         {
//             return false;
//         }
//     }

//     return isBinTreeSorted(node->left) && isBinTreeSorted(node->right);
// }

int main(int argc, char const *argv[])
{
    Tree<int> *root = new Tree<int>(8,
                                    new Tree<int>(3, new Tree<int>(1),
                                                  new Tree<int>(6, new Tree<int>(4), new Tree<int>(7))),
                                    new Tree<int>(10, nullptr, new Tree<int>(14, new Tree<int>(13))));

    std::cout << isBinTreeSorted(root);

    Tree<int> *example = new Tree<int>(4, new Tree<int>(6), new Tree<int>(2));
    std::cout << isBinTreeSorted(example);

    freeTree(root);
    freeTree(example);
    return 0;
}
