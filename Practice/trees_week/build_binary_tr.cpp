#include <iostream>
#include <vector>
#include "tree_utils.h"
using std::vector;

template <class T>
Tree<T> *buildFromRec(const std::vector<T> &v, int start, int end)
{
    if (end < start)
    {
        return nullptr;
    }

    int mid = (end - start) / 2 + start;

    return new Tree<T>(v[mid], buildFromRec(v, start, mid - 1), buildFromRec(v, mid + 1, end));
}

template <class T>
Tree<T> *buildFrom(const std::vector<T> &v)
{
    return buildFromRec(v, 0, v.size() - 1);
}

template <class T>
void bubleSort(vector<T> &arr)
{
    bool changed = true;
    int index = 0;
    do
    {
        changed = false;
        for (size_t i = 1; i < arr.size() - index; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                std::swap(arr[i - 1], arr[i]);
                changed = true;
            }
        }
        index++;

    } while (changed);
}

template <class T>
void printVector(const vector<T> &arr)
{
    for (T item : arr)
    {
        cout << item << " ";
    }
    cout << '\n';
}

vector<int> createVector(int size)
{
    vector<int> arr;
    for (size_t i = 1; i <= size; i++)
    {
        arr.push_back(i);
    }

    return arr;
}

using std::vector;
int main()
{
    // vector<int> arr = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    vector<int> arr = createVector(8);

    bubleSort(arr);
    Tree<int> *myTree = buildFrom(arr);
    printTree(myTree);

    return 0;
}
