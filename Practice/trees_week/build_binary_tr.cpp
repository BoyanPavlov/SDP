#include <iostream>
#include <vector>
#include "tree_utils.h"

template <class T>
void attachChild(Tree<T> *&node, const T &elem)
{
}

template <class T>
Tree<T> *buildBalancedBinTree(const vector<T> &arr)
{
    Tree<T> *node = nullptr;
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (/* condition */)
        {
            /* code */
        }
    }
}

using std::vector;
int main(int argc, char const *argv[])
{
    vector<int> arr = {8, 3, 1, 6, 4, 7, 10, 14, 13};

    return 0;
}
