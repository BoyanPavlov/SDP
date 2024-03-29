#include "./include/doctest.h"
#include "squeue.hpp"
#include "lqueue.hpp"
#include "queue_utils.hpp"

#define ALL_QUEUES StaticQueue<int>, LinkedQueue<int>

TYPE_TO_STRING(StaticQueue<int>);
TYPE_TO_STRING(LinkedQueue<int>);

TEST_CASE_TEMPLATE("След създаване на опашка, тя е празна",
                   AnyQueue, ALL_QUEUES)
{
    AnyQueue q;
    CHECK(q.empty());
}

TEST_CASE_TEMPLATE("След добавяне на елемент в опашка, тя не е празна",
                   AnyQueue, ALL_QUEUES)
{
    AnyQueue q;
    q.enqueue(42);
    CHECK_FALSE(q.empty());
}

TEST_CASE_TEMPLATE("Опит за поглеждане в или изключване на елемент от празна опашка хвърля изключение",
                   AnyQueue, ALL_QUEUES)
{
    AnyQueue q;
    CHECK_THROWS(q.head());
    CHECK_THROWS(q.dequeue());
}

TEST_CASE_TEMPLATE("При последователно добавяне на елементи в опашката се изключва първият добавен",
                   AnyQueue, ALL_QUEUES)
{
    AnyQueue q;
    for (int i = 1; i <= 10; i++)
        q.enqueue(i);
    CHECK_EQ(q.head(), 1);
    CHECK_EQ(q.dequeue(), 1);
    CHECK_NE(q.head(), 1);
}

TEST_CASE_TEMPLATE("При последователно добавяне на елементи в опашката, се изключват в същия ред и след това опашката остава празна",
                   AnyQueue, ALL_QUEUES)
{
    AnyQueue q;
    for (int i = 1; i <= 10; i++)
        q.enqueue(i);
    CHECK_FALSE(q.empty());
    for (int i = 1; i <= 10; i++)
        CHECK_EQ(q.dequeue(), i);
    CHECK(q.empty());

    for (int i = 11; i <= 20; i++)
        q.enqueue(i);
    CHECK_FALSE(q.empty());
    for (int i = 11; i <= 20; i++)
        CHECK_EQ(q.dequeue(), i);
    CHECK(q.empty());
}

// TEST_CASE_TEMPLATE("Многократно добавяне и изключване на елементи",
//                     AnyQueue, ALL_QUEUES) {
//     AnyQueue q;
//     for(int j = 0; j < 100; j++) {
//         for(int i = 1; i <= 10; i++)
//             q.enqueue(i);
//         CHECK_FALSE(q.empty());
//         for(int i = 1; i <= 10; i++)
//             CHECK_EQ(q.dequeue(), i);
//         CHECK(q.empty());
//     }
// }

// TEST_CASE_TEMPLATE("Конструкторът за копиране не споделя памет",
//                    AnyQueue, ALL_QUEUES)
// {
//     AnyQueue q1;
//     for (int i = 1; i <= 10; i++)
//         q1.enqueue(i);
//     AnyQueue q2 = q1;
//     q2.enqueue(20);
//     for (int i = 1; i <= 10; i++)
//     {
//         CHECK(!q1.empty());
//         CHECK_EQ(q1.dequeue(), i);
//     }
//     CHECK(q1.empty());
// }

TEST_CASE_TEMPLATE("Копиране на празна опашка",
                   AnyQueue, ALL_QUEUES)
{
    AnyQueue q1;
    AnyQueue q2 = q1;
    CHECK(q2.empty());
}

// TODO: тест за операция за присвояване

// problem here
// TEST_CASE_TEMPLATE("От тестова опашка коректно се изключва най-малкия елемент",
//                    AnyQueue, ALL_QUEUES)
// {
//     AnyQueue q;
//     q.enqueue(5);
//     q.enqueue(3);
//     q.enqueue(6);
//     q.enqueue(1);
//     q.enqueue(2);
//     CHECK_EQ(QueueUtils<int>::extractMin(q), 1);
//     while (!q.empty())
//     {
//         int x = q.dequeue();
//         // TODO: да се подобри!
//         CHECK((x == 2 || x == 3 || x == 5 || x == 6));
//     }
// }

// problem here
//  TEST_CASE_TEMPLATE("Тестова опашка се сортира успешно",
//                     AnyQueue, ALL_QUEUES)
//  {
//      AnyQueue q;
//      q.enqueue(5);
//      q.enqueue(3);
//      q.enqueue(6);
//      q.enqueue(1);
//      q.enqueue(2);
//      int expectedResult[] = {1, 2, 3, 5, 6};
//      AnyQueue sortedQueue;
//      QueueUtils<int>::sortQueue(q, sortedQueue);
//      int i = 0;
//      int val1 = 0;
//      int val2 = 0;

//     while (!sortedQueue.empty())
//     {
//         val1 = expectedResult[i++];
//         val2 = sortedQueue.dequeue();
//         CHECK_EQ(val1, val2);
//     }
//     CHECK_EQ(i, 5);
// }
