#include <iostream>
#include <queue>
#include <stack>
#include <list>

using std::cout;
using std::list;
using std::queue;
using std::stack;

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

    return 0;
}

int getValueFromQ(queue<char> *q)
{
    stack<int> nums;

    int result = 0;
    while (!q->empty())
    {
        if (isNumber(q->front()))
        {
            int cDigit = q->front() - '0';
            q->pop();
            nums.push(cDigit);
        }
        else
        {
            int fst = nums.top();
            nums.pop();
            int snd = nums.top();
            nums.pop();
            char sign = q->front();
            q->pop();

            nums.push(calculate(fst, snd, sign));
        }
    }
    return nums.top();
}

bool isSymethric(list<int> &ll)
{
    list<int>::iterator start = ll.begin();
    list<int>::iterator end = ll.begin();

    while (start != end)
    {
        if (*start != *end)
        {
            return false;
        }
        ++start;
        if (start == end)
        {
            break;
        }
        --end;
    }
    return true;
}

bool solution(const std::list<std::queue<char>> &ll)
{
    std::list<int> l;
    for (auto elem : ll)
        l.push_back(getValueFromQ(&elem));

    return isSymethric(l);
}

// not finished yet
int main()
{
    list<queue<char>> ll;

    ll.push_back(queue<char>({'4',
                              '5',
                              '+'}));

    ll.push_back(queue<char>({'1',
                              '6',
                              '+',
                              '7',
                              '*'}));

    ll.push_back(queue<char>({'8'}));

    ll.push_back(queue<char>({'1',
                              '7',
                              '7',
                              '*',
                              '*'}));

    ll.push_back(queue<char>({'2',
                              '3',
                              '*',
                              '3',
                              '+'}));

    cout << solution(ll);
    return 0;
}
