#include <iostream>
#include "tree_utils.h"

int main(int argc, char const *argv[])
{
    Tree<int> *example = new Tree<int>(4, new Tree<int>(2), new Tree<int>(6));

    // insertInBST(example, 2);
    // printTree(example);

    insertInBST(example, 7);
    std::cout << containsBST(example, 7);
    std::cout << containsBST(example, 1);

    
    return 0;
}
