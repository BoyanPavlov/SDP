#include "abstractStack.hpp"
#include "stack.hpp"
#include "rstack.hpp"
#include "lstack.hpp"

#include "../TestingFiles/catch.hpp"

#include <string>
using std::string;

TEST_CASE("Creating empty stack")
{
    Stack<int> s;
    ResizingStack<int> rs;
    LinkedStack<int> ls;

    REQUIRE(s.empty() == true);
    REQUIRE(rs.empty() == true);
    REQUIRE(ls.empty() == true);
}

TEST_CASE("Not emtpy stack")
{
    Stack<int> s;
    ResizingStack<int> rs;
    LinkedStack<int> ls;
    s.push(10);
    rs.push(10);
    ls.push(10);

    REQUIRE(s.empty() != true);
    REQUIRE(rs.empty() != true);
    REQUIRE(ls.empty() != true);
}

TEST_CASE("Excluding elements")
{

    Stack<int> s;
    ResizingStack<int> rs;
    LinkedStack<int> ls;

    s.push(10);
    s.push(20);
    s.push(30);

    rs.push(10);
    rs.push(20);
    rs.push(30);

    ls.push(10);
    ls.push(20);
    ls.push(30);

    REQUIRE(!s.empty() == false);
    REQUIRE(s.pop() == 30);
    REQUIRE(s.pop() == 20);
    REQUIRE(s.pop() == 10);
    REQUIRE(s.empty() == true);

    REQUIRE(!rs.empty() == false);
    REQUIRE(rs.pop() == 30);
    REQUIRE(rs.pop() == 20);
    REQUIRE(rs.pop() == 10);
    REQUIRE(rs.empty() == true);

    REQUIRE(!ls.empty() == false);
    REQUIRE(ls.pop() == 30);
    REQUIRE(ls.pop() == 20);
    REQUIRE(ls.pop() == 10);
    REQUIRE(ls.empty() == true);
}

TEST_CASE("Peek")
{
    Stack<int> s;
    ResizingStack<int> rs;
    LinkedStack<int> ls;

    s.push(10);
    rs.push(10);
    ls.push(10);
    REQUIRE(s.peek() == 10);
    REQUIRE(rs.peek() == 10);
    REQUIRE(ls.peek() == 10);
    s.push(20);
    rs.push(20);
    ls.push(20);
    REQUIRE(s.peek() == 20);
    REQUIRE(rs.peek() == 20);
    REQUIRE(ls.peek() == 20);
    s.pop();
    rs.pop();
    ls.pop();
    REQUIRE(s.peek() == 10);
    REQUIRE(rs.peek() == 10);
    REQUIRE(ls.peek() == 10);
}

TEST_CASE("LinkedStack: trying to peek")
{
    LinkedStack<int> s;
    int x;

    REQUIRE(!s.peek(x) == true);
}

TEST_CASE("Exception for peek or pop")
{
    Stack<int> s;
    ResizingStack<int> rs;
    LinkedStack<int> ls;

    string peekError = "An attempt to peek in empty stack";
    string popError = "An attempt of popping from empty stack\n";

    try
    {
        s.peek();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
        REQUIRE(peekError == e.what());
    }

    try
    {
        s.pop();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
        REQUIRE(popError == e.what());
    }

    try
    {
        rs.peek();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
        REQUIRE(peekError == e.what());
    }

    try
    {
        rs.pop();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
        REQUIRE(popError == e.what());
    }

    try
    {
        ls.peek();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
        REQUIRE(peekError == e.what());
    }

    try
    {
        ls.pop();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
        REQUIRE(popError == e.what());
    }
}

TEST_CASE("LinkedStack: safely peeking")
{
    LinkedStack<int> ls;

    ls.push(10);
    int x;
    REQUIRE(ls.peek(x) == true);
    REQUIRE(x == 10);

    ls.push(20);
    REQUIRE(ls.peek(x) == true);
    REQUIRE(x == 20);

    ls.pop();
    REQUIRE(ls.peek(x) == true);
    REQUIRE(x == 10);
}

TEST_CASE("LinkedStack: copy constr doesn't share")
{
    LinkedStack<int> s1;
    for (int i = 1; i <= 10; i++)
    {
        s1.push(i);
    }

    LinkedStack<int> s2 = s1;
    // std::clog << s2.pop() << std::endl;
    s2.push(20);
    for (int i = 10; i >= 1; i--)
    {
        REQUIRE(!s1.empty() == true);
        REQUIRE(s1.pop() == i);
    }
    REQUIRE(s1.empty() == true);
}

TEST_CASE("LinkedStack: safe pop throws an error for trying to exclude from empty stack")
{
    LinkedStack<int> s;
    bool success = true;
    int x = s.pop(success);
    REQUIRE(success == false);
}

template <typename T>
LinkedStack<T> reverse(LinkedStack<T> s)
{
    LinkedStack<T> result;
    while (!s.empty())
        result.push(s.pop());
    return result;
}

LinkedStack<int> createStack(unsigned n)
{
    LinkedStack<int> result;
    for (int i = 1; i <= n; i++)
        result.push(i);
    return result;
}

LinkedStack<int> doubleTop(LinkedStack<int> s)
{
    s.push(s.pop() * 2);
    return s;
}

TEST_CASE("LinkedStack: copy in reverse")
{
    std::clog << "LinkedStack: копиране при reverse\n";
    LinkedStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    LinkedStack<int> s2 = reverse(s);
    REQUIRE(s2.pop() == 1);
    REQUIRE(s2.pop() == 2);
    REQUIRE(s2.pop() == 3);
    REQUIRE(s2.empty() == true);
}

// TEST_CASE("LinkedStack: копиране при doubleTop")
// {
//     // std::clog << "LinkedStack: копиране при doubleTop\n";
//     LinkedStack<int> s2 = doubleTop(createStack(10));
// }

// TEST_CASE("LinkedStack: assigning to doubleTop")
// {
//     // std::clog << "LinkedStack: присвояване при doubleTop\n";
//     LinkedStack<int> s2 = createStack(10);
//     s2 = doubleTop(createStack(10));
// }

TEST_CASE("LinkedStack: std::move")
{
    // std::clog << "LinkedStack: std::move\n";
    LinkedStack<int> temp = createStack(10);
    LinkedStack<int> s2 = doubleTop(std::move(temp));
    REQUIRE(temp.empty() == true);
}


