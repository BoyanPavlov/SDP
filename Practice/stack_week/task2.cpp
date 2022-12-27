#include <iostream>
#include <stack>

bool isStringBalanced(const std::string &str)
{
    std::stack<char> myStack;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == ')')
        {
            if (myStack.empty())
            {
                return false;
            }
            myStack.pop();
        }
        else
        {
            myStack.push(str[i]);
        }
    }
    return myStack.empty();
}

int main()
{
    std::string test0 = "()()((())";
    std::string test1 = "()()((()))";
    std::string test2 = "(((()))";

    std::cout << isStringBalanced(test0) << std::endl;
    std::cout << isStringBalanced(test1) << std::endl;
    std::cout << isStringBalanced(test2) << std::endl;

    return 0;
}