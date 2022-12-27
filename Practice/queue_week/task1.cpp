#include <iostream>
#include <queue>
#include <cmath>
using std::cout;
using std::endl;
using std::queue;
using std::string;

// bool needMorePoweer(queue<int> Q, int number)
// {
//     int result = 0;
//     int power = 0;
//     for (size_t i = 0; i < Q.size(); i++)
//     {
//         if (result == number)
//         {
//             return false;
//         }
//         else
//         {
//             result += Q.front() * (pow(power, 2));
//             Q.pop();
//             power++;
//         }
//     }
//     return true;
// }

// bool isLastDigitZero(queue<int> Q)
// {
//     for (size_t i = 0; i < Q.size() - 1; i++)
//     {
//         Q.pop();
//     }
//     if (Q.front())
//     {
//         return true;
//     }
//     return false;
// }

// void printQ(queue<int> Q)
// {
//     for (size_t i = 0; i < Q.size(); i++)
//     {
//         cout << Q.front();
//         Q.pop();
//     }
//     cout << ' ';
// }

// void enlargeQ(queue<int> &Q, int number)
// {
//     if (needMorePoweer(Q, number))
//     {
//         printQ(Q);
//         if (isLastDigitZero(Q))
//         {
//             // make the last digit 1 instead of 0
//             // create a copy Q
//             // push in new Q n-1 elements
//             // repush in the old Q
//         }
//         else
//         {
//             Q.push(0);
//         }
//     }
// }

// int main()
// {

//     return 0;
// }

//fking genius
void printAllBinaryNumbers(size_t n)
{
    std::queue<std::string> q;

    q.push("1");

    while (n)
    {
        std::string currentNumber = q.front();
        q.pop();

        std::cout << currentNumber << " ";

        q.push(currentNumber + "0");
        q.push(currentNumber + "1");

        n--;
    }
}

int main()
{
    printAllBinaryNumbers(10);
}