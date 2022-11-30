#include <iostream>
// #include <cassert>
// #include "abstractStack.hpp"
#include "stack.hpp"
#include "rstack.hpp"
#include "lstack.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_MULTITHREADING
#include "./include/doctest.h"
#include "stack_tests.hpp"

// // using MyStack = Stack<int>;
// using MyStack = ResizingStack<int>;
// // using Stack = LinkedStack<int>;

// void convertBase()
// {
//     unsigned n;
//     std::cout << "n = ";
//     std::cin >> n;

//     unsigned base;
//     do
//     {
//         std::cout << "base = ";
//         std::cin >> base;
//     } while (base < 2 || base > 10);

//     MyStack s;
//     unsigned k = n;
//     while (k > 0)
//     {
//         s.push(k % base);
//         k /= base;
//     }

//     std::cout << n << "(10) = ";
//     while (!s.empty())
//         std::cout << s.pop();
//     std::cout << "(" << base << ")" << std::endl;
// }

// /*
// <израз> ::= <цифра>|(<израз><операция><израз>)
// след завършване на функцията expr ще сочи след последния обработен символ
// */

// /*
// double calculateExpression(char const*& expr) {
//     if (isdigit(*expr))
//         // <цифра>
//         return *expr++ - '0';
//     assert(*expr == '(');
//     // да сметнем левия операнд, прескачайки отварящата скоба
//     double left = calculateExpression(++expr);
//     // вече сме сигурни, че сме върху операцията
//     assert(isop(*expr));
//     char op = *expr;
//     // да сметнем десния операнд, прескачайки операцията
//     double right = calculateExpression(++expr);
//     assert(*expr == ')');
//     // да осигурим, че expr сочи след последния обработен символ
//     expr++;
//     return calculate(left, op, right);
// }
// */

// bool isdigit(char c)
// {
//     return '0' <= c && c <= '9';
// }

// bool isop(char c)
// {
//     return c == '+' || c == '-' || c == '*' || c == '/';
// }

// int calculate(int left, char op, int right)
// {
//     switch (op)
//     {
//     case '+':
//         return left + right;
//     case '-':
//         return left - right;
//     case '*':
//         return left * right;
//     case '/':
//         return right == 0 ? 0 : left / right;
//     default:
//         assert(isop(op));
//         return 0;
//     }
// }

// int calculateExpression(char const *expr)
// {
//     LinkedStack<int> results;
//     LinkedStack<char> ops;
//     while (*expr)
//     {
//         if (isdigit(*expr))
//             // <цифра>
//             results.push(*expr - '0');
//         else if (isop(*expr))
//             // <операция>
//             ops.push(*expr);
//         else if (*expr == ')')
//         {
//             int right = results.pop();
//             int left = results.pop();
//             char op = ops.pop();
//             results.push(calculate(left, op, right));
//         }
//         expr++;
//     }
//     return results.pop();
// }

// bool isOpeningParenthesis(char c)
// {
//     return c == '(' || c == '[' || c == '{';
// }

// bool isClosingParenthesis(char c)
// {
//     return c == ')' || c == ']' || c == '}';
// }

// bool matchParentheses(char open, char close)
// {
//     return open == '(' && close == ')' ||
//            open == '[' && close == ']' ||
//            open == '{' && close == '}';
// }

// void testExpression()
// {
//     const int MAXEXPR = 100;
//     char expr[MAXEXPR];
//     std::cin.getline(expr, MAXEXPR);
//     std::cout << " = " << calculateExpression(expr) << std::endl;
// }

// bool checkParentheses(const char *expr)
// {
//     MyStack s;
//     while (*expr != '\0')
//     {
//         if (isOpeningParenthesis(*expr))
//             s.push(*expr);
//         else if (isClosingParenthesis(*expr))
//         {
//             if (s.empty() || !matchParentheses(s.pop(), *expr))
//                 // грешка тип 2: затваряща скоба без отваряща
//                 // грешка тип 3: несъвпадащи по вид скоби
//                 return false;
//         }
//         expr++;
//     }
//     // грешка тип 1: повече отварящи скоби
//     return s.empty();
// }

// void autoTestParentheses()
// {
//     assert(true == checkParentheses("((2+3)*(5-7))"));
//     assert(true == checkParentheses("[(2+3)*{5-7}]"));
//     // тест за грешка тип 1
//     assert(false == checkParentheses("((2+3)+(5-7)"));
//     // тест за грешка тип 2
//     assert(false == checkParentheses("((2+3)))*((5-7)"));
//     // тест за грешка тип 3
//     assert(false == checkParentheses("[(2+3)*{5-7)]"));
//     // тест за голям израз (100 скоби)
//     assert(true == checkParentheses("((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((2))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))"));
//     // тест за голям израз (101 скоби)
//     assert(true == checkParentheses("(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((2)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))"));
//     std::cout << "OK" << std::endl;
// }

// void testCopyStack()
// {
//     MyStack s1;
//     for (int i = 1; i <= 10; i++)
//         s1.push(i);
//     // Stack s2 = s1;
//     MyStack s2;
//     s2 = s1;
//     s2 = s2;
//     std::cout << s2.pop() << std::endl;
//     // !!! std::cout << s1.pop() << std::endl;
//     s2.push(20);
//     std::cout << s1.peek() << std::endl;
//     std::cout << s2.pop() << std::endl;
//     std::cout << s1.pop() << std::endl;
//     std::cout << s1.pop() << std::endl;
// }

// void testDestroyStack()
// {
//     for (int i = 0; i < 1E8; i++)
//     {
//         // ResizingStack s;
//         LinkedStack<int> s;
//         for (int j = 1; j <= 10; j++)
//             s.push(j);
//     }
//     std::cout << "Готово!\n";
//     char x;
//     std::cin >> x;
// }

// void testAbstractStack()
// {
//     AbstractStack<int> *stacks[] = {
//         new Stack<int>,
//         new ResizingStack<int>,
//         new LinkedStack<int>};
//     size_t count = sizeof(stacks) / sizeof(stacks[0]);
//     for (int i = 0; i < count; i++)
//         for (int x = 1; x <= 10; x++)
//             stacks[i]->push(x);

//     for (int i = 0; i < count; i++)
//         while (!stacks[i]->empty())
//             std::cout << stacks[i]->pop() << std::endl;

//     for (int i = 0; i < count; i++)
//         delete stacks[i];
// }

// int main(int, char **)
// {
//     // convertBase();
//     // testExpression();
//     // autoTestParentheses();
//     // testCopyStack();
//     // testDestroyStack();
//     // testAbstractStack();
//     return 0;
// }

////////////////////////////////////////////////////////////////////////
// #include <iostream>
// #include <cstring>

// using std::cout;
// using std::string;

// void emptyStack()
// {
//     //"Creating empty stack"
//     Stack<int> s;
//     ResizingStack<int> rs;
//     LinkedStack<int> ls;

//     cout << (s.empty() == true);
//     cout << (rs.empty() == true);
//     cout << (ls.empty() == true);
// }

// void notEmptyStack()
// {
//     //"Not emtpy stack"
//     Stack<int> s;
//     ResizingStack<int> rs;
//     LinkedStack<int> ls;
//     s.push(10);
//     rs.push(10);
//     ls.push(10);

//     cout << (s.empty() != true);
//     cout << (rs.empty() != true);
//     cout << (ls.empty() != true);
// }

// void ExcludingElements()
// {
//     //"Excluding elements"
//     Stack<int> s;
//     ResizingStack<int> rs;
//     LinkedStack<int> ls;

//     s.push(10);
//     s.push(20);
//     s.push(30);

//     rs.push(10);
//     rs.push(20);
//     rs.push(30);

//     ls.push(10);
//     ls.push(20);
//     ls.push(30);

//     cout << (s.empty() == false);
//     cout << (s.pop() == 30);
//     cout << (s.pop() == 20);
//     cout << (s.pop() == 10);
//     cout << (s.empty() == true);

//     cout << (rs.empty() == false);
//     cout << (rs.pop() == 30);
//     cout << (rs.pop() == 20);
//     cout << (rs.pop() == 10);
//     cout << (rs.empty() == true);

//     cout << (ls.empty() == false);
//     cout << (ls.pop() == 30);
//     cout << (ls.pop() == 20);
//     cout << (ls.pop() == 10);
//     cout << (ls.empty() == true);
// }

// void peek()
// {
//     // peek
//     Stack<int> s;
//     ResizingStack<int> rs;
//     LinkedStack<int> ls;

//     s.push(10);
//     rs.push(10);
//     ls.push(10);
//     cout << (s.peek() == 10);
//     cout << (rs.peek() == 10);
//     cout << (ls.peek() == 10);
//     s.push(20);
//     rs.push(20);
//     ls.push(20);
//     cout << (s.peek() == 20);
//     cout << (rs.peek() == 20);
//     cout << (ls.peek() == 20);
//     s.pop();
//     rs.pop();
//     ls.pop();
//     cout << (s.peek() == 10);
//     cout << (rs.peek() == 10);
//     cout << (ls.peek() == 10);
// }

// void LinkedStack_trying_to_peek()
// {
//     // LinkedStack: trying to peek
//     LinkedStack<int> s;
//     int x;

//     cout << (!s.peek(x) == true);
// }

// void Exception_for_peek_or_pop()
// {
//     // Exception for peek or pop
//     Stack<int> s;
//     ResizingStack<int> rs;
//     LinkedStack<int> ls;

//     string peekError = "An attempt to peek in empty stack";
//     string popError = "An attempt of popping from empty stack\n";

//     try
//     {
//         s.peek();
//     }
//     catch (const std::runtime_error &e)
//     {
//         // std::cerr << e.what() << '\n';
//         cout << (peekError == e.what());
//     }

//     try
//     {
//         s.pop();
//     }
//     catch (const std::runtime_error &e)
//     {
//         // std::cerr << e.what() << '\n';
//         cout << (popError == e.what());
//     }

//     try
//     {
//         rs.peek();
//     }
//     catch (const std::runtime_error &e)
//     {
//         // std::cerr << e.what() << '\n';
//         cout << (peekError == e.what());
//     }

//     try
//     {
//         rs.pop();
//     }
//     catch (const std::runtime_error &e)
//     {
//         // std::cerr << e.what() << '\n';
//         cout << (popError == e.what());
//     }

//     // wtf
//     // try
//     //{
//     //     ls.peek();
//     // }
//     //// catch (const std::runtime_error &e)
//     // catch (const std::exception &e)
//     //{
//     //     //std::cerr << e.what() << '\n';
//     //     cout << (peekError == e.what());
//     // }

//     try
//     {
//         ls.pop();
//     }
//     catch (const std::runtime_error &e)
//     {
//         // std::cerr << e.what() << '\n';
//         cout << (popError == e.what());
//     }
// }

// void LinkedStack_safely_peeking()
// {
//     LinkedStack<int> ls;

//     ls.push(10);
//     int x;
//     cout << (ls.peek(x) == true);
//     cout << (x == 10);

//     ls.push(20);
//     cout << (ls.peek(x) == true);
//     cout << (x == 20);

//     ls.pop();
//     cout << (ls.peek(x) == true);
//     cout << (x == 10);
// }

// void LinkedStack_copy_constr_doesnt_share()
// {
//     LinkedStack<int> s1;
//     for (int i = 1; i <= 10; i++)
//     {
//         s1.push(i);
//     }

//     LinkedStack<int> s2 = s1;
//     // std::clog << s2.pop() << std::endl;
//     s2.push(20);
//     for (int i = 10; i >= 1; i--)
//     {
//         cout << (!s1.empty() == true);
//         cout << (s1.pop() == i);
//     }
//     cout << (s1.empty() == true);
// }

// void LinkedStack_safe_pop_throws_an_error_for_trying_to_exclude_from_empty_stack()
// {
//     LinkedStack<int> s;
//     bool success = true;
//     int x = s.pop(success);
//     cout << (success == false);
// }

// template <typename T>
// LinkedStack<T> reverse(LinkedStack<T> s)
// {
//     LinkedStack<T> result;
//     while (!s.empty())
//         result.push(s.pop());
//     return result;
// }

// LinkedStack<int> createStack(unsigned n)
// {
//     LinkedStack<int> result;
//     for (int i = 1; i <= n; i++)
//         result.push(i);
//     return result;
// }

// LinkedStack<int> doubleTop(LinkedStack<int> s)
// {
//     s.push(s.pop() * 2);
//     return s;
// }

// void LinkedStack_copy_in_reverse()
// {
//     // cout << "LinkedStack: копиране при reverse\n";
//     LinkedStack<int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     LinkedStack<int> s2 = reverse(s);
//     cout << (s2.pop() == 1);
//     cout << (s2.pop() == 2);
//     cout << (s2.pop() == 3);
//     cout << (s2.empty() == true);
// }

// void LinkedStack_std_move()
// {
//     // std::clog << "LinkedStack: std::move\n";
//     LinkedStack<int> temp = createStack(10);
//     LinkedStack<int> s2 = doubleTop(std::move(temp));
//     cout << (temp.empty() == true);
// }

// void copyingAStack()
// {
//     LinkedStack<int> myStack;
//     myStack.push(10);
//     myStack.push(20);
//     myStack.push(30);

//     LinkedStack<int> my2Stack = myStack;
//     while (!my2Stack.empty())
//     {
//         cout << my2Stack.pop() << " ";
//     }
// }

// int main(int argc, char const *argv[])
// {
//     // emptyStack();
//     // notEmptyStack();
//     // ExcludingElements();
//     // peek();
//     // LinkedStack_trying_to_peek();
//     // Exception_for_peek_or_pop();

//     // LinkedStack_safely_peeking();
//     // LinkedStack_copy_constr_doesnt_share();
//     // LinkedStack_safe_pop_throws_an_error_for_trying_to_exclude_from_empty_stack();
//     // LinkedStack_copy_in_reverse();
//     // LinkedStack_std_move();

//     copyingAStack();
//     return 0;
// }
