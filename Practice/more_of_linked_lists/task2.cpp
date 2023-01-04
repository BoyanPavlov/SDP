#include <iostream>
#include <stack>
#include <vector>
#include "LinkedList_Stoycho.hpp"

using std::cout;
using std::stack;
using std::vector;

template <class T>
std::stack<T> *getStack(vector<T> &arr)
{
    stack<T> *st = new stack<T>;
    for (int i = 0; i < arr.size(); i++)
    {
        st->push(arr[i]);
    }
    return st;
}

template <class T>
LinkedList<stack<T>> *getListOfStacks(vector<vector<T>> &arrs)
{
    LinkedList<T> *ll = new LinkedList<T>;
    for (size_t i = 0; i < arrs.size(); i++)
    {
        stack<T> *newStack = getStack(arrs[i]);
        ll->pushBack(*newStack);
    }
    return ll;
}

// how not to create list of stacks - check tast2_1.cpp
int main(int argc, char const *argv[])
{
    vector<int> arr1 = {5, 4, 3, 2, 1};
    vector<int> arr2 = {7, 6};
    vector<int> arr3 = {11, 10, 9, 8};
    vector<int> arr4 = {12};

    vector<vector<int>> arrs = {arr1, arr2, arr3, arr4};

    LinkedList<stack<int>> *ll = getListOfStacks(arrs);
    while (!ll->empty())
    {
        stack<int> temp = ll->begin().operator*();

        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp.top() << ' ';
            temp.pop();
        }
    }

    delete ll;
    return 0;
}
