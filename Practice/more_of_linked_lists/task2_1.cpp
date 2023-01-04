#include <stack>
#include <vector>
#include <iterator>
#include <iostream>
using std::stack;
using std::vector;

template <class T>
struct Node
{
    stack<T> data;
    Node *next;

    Node(stack<T> &&stack, Node *ptr)
    {
        data = stack;
        next = ptr;
    }
};

//How to create List of stacks properly
int main()
{
    Node<int> *first =
        new Node<int>(stack<int>({5, 4, 3, 2, 1}),
                      new Node<int>(stack<int>({7, 6}),
                                    new Node<int>(stack<int>({11, 10, 9, 8}),
                                                  new Node<int>(stack<int>({12}), nullptr))));

    while (first)
    {
        while (first->data.size())
        {
            std::cout << first->data.top() << " ";
            first->data.pop();
        }
        std::cout << std::endl;
        first = first->next;
    }
}