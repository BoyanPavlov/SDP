#include <iostream>
#include <stack>
#include <string>
#include <exception>

using std::stack;
using std::string;

// aa* -> "a"
// erase***** -> ""
// thi*s i*s exampl*e -> "ths s exampe"

string removeStars(const string &str)
{
    stack<char> myStack;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '*')
        {
            if (myStack.empty())
            {
                throw std::runtime_error("invalid expr\n");
            }
            else
            {
                myStack.pop();
            }
        }
        else
        {
            myStack.push(str[i]);
        }
    }
    string result(myStack.size(), '\0');
    int size = myStack.size();

    while (!myStack.empty())
    {
        result[--size] = myStack.top();
        myStack.pop();
    }
    return result;
}

int main()
{
    string test1 = "aa*\n";
    string test2 = "erase*****\n";
    string test3 = "thi*s i*s exampl*e\n";

    // string result1 = "a";
    // string result2 = "";
    // string result3 = "ths s exampe";

    std::cout << removeStars(test1);
    std::cout << removeStars(test2);
    std::cout << removeStars(test3);

    return 0;
}
