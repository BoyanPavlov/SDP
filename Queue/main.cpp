#include "squeue.hpp"
#include "lqueue.hpp"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "./include/doctest.h"
#include "queue_tests.hpp"

// void EmptyQ()
// {
//     StaticQueue<int> q;
//     cout << (q.empty());
// }

// void NotEmptyQ()
// {
//     StaticQueue<int> q;
//     q.enqueue(42);
//     cout << (!q.empty());
// }

// void exceptionsForEmptyQ()
// {
//     StaticQueue<int> q;
//     string errorEmpty = "Attempt of extracting element from empty Queue\n";
//     string errorPeek = "An attempt of peeking from empty queue\n";

//     try
//     {
//         q.head();
//     }
//     catch (const std::exception &e)
//     {
//         cout << (errorPeek == e.what());
//     }

//     try
//     {
//         q.dequeue();
//     }
//     catch (const std::exception &e)
//     {
//         cout << (errorEmpty == e.what());
//     }
// }

// void testingTheSequence()
// {
//     StaticQueue<int> q;

//     for (int i = 1; i <= 10; i++)
//         q.enqueue(i);
//     cout << (q.head() == 1);
//     cout << (q.dequeue() == 1);

//     // false
//     cout << (q.head() == 2);
// }

// void testingTheSequence2()
// {
//     StaticQueue<int> q;
//     for (int i = 1; i <= 10; i++)
//         q.enqueue(i);
//     cout << (!q.empty());

//     for (int i = 1; i <= 10; i++)
//         cout << (q.dequeue() == i);

//     cout << (q.empty() == true);

//     for (int i = 11; i <= 20; i++)
//         q.enqueue(i);

//     cout << (!q.empty());
//     for (int i = 11; i <= 20; i++)
//         cout << (q.dequeue() == i);

//     cout << (q.empty() == true);
// }

// void testingTheSequence3()
// {
//     StaticQueue<int> q;
//     for (int j = 0; j < 100; j++)
//     {
//         for (int i = 1; i <= 10; i++)
//         {
//             q.enqueue(i);
//         }

//         cout << (q.empty() == false);

//         /* for (int i = 1; i <= 10; i++)
//              cout << (q.dequeue() == i);
//          cout << (q.empty());*/
//     }
// }

// void testingTheSequence4()
// {
//     StaticQueue<int> q1;
//     for (int i = 1; i <= 10; i++)
//         q1.enqueue(i);
//     StaticQueue<int> q2 = q1;
//     q2.enqueue(20);
//     for (int i = 1; i <= 10; i++)
//     {
//         cout << (!q1.empty());
//         cout << (q1.dequeue() == i);
//     }
//     cout << (q1.empty());
// }

// void copyingEmptyQ()
// {
//     StaticQueue<int> q1;
//     StaticQueue<int> q2 = q1;
//     cout << (q2.empty());
// }

// int main()
// {
//     EmptyQ();
//     NotEmptyQ();
//     exceptionsForEmptyQ();
//     copyingEmptyQ();
//     testingTheSequence();
//     testingTheSequence2();
//     // testingTheSequence3();
//     testingTheSequence4();

//     return 0;
// }
