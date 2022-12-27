#include <iostream>
#include <stack>
#include <cmath>
using std::cout;
using std::endl;
using std::stack;
using std::string;

bool isNumber(char letter)
{
    if (letter >= '0' && letter <= '9')
    {
        return true;
    }
    return false;
}

int calculate(int first, int second, char sign)
{
    if (sign == '*')
    {
        return (first * second);
    }
    if (sign == '-')
    {
        return (first - second);
    }
    if (sign == '+')
    {
        return (first + second);
    }
    if (sign == '/')
    {
        return (first / second);
    }
    if (sign == '^')
    {
        return pow(first, second);
    }
    return 0;
}

int reversePolishNotation(const string &expr)
{
    stack<int> numbers;

    for (size_t i = 0; i < expr.size(); i++)
    {
        if (isNumber(expr[i]))
        {
            int number = expr[i] - '0';
            numbers.push(number);
        }
        else
        {
            int second = numbers.top();
            numbers.pop();
            int first = numbers.top();
            numbers.pop();
            int result = calculate(first, second, expr[i]);
            numbers.push(result);
        }
    }
    int result = numbers.top();
    numbers.pop();
    return result;
}

int main()
{
    string test = "7832^*4++";
    cout << (83 == reversePolishNotation(test));
    return 0;
}