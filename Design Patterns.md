# Design patterns
### Some design patterns I heard of in the process of studing data structures

## Proxy Design Pattern
Sources
https://sourcemaking.com/design_patterns/proxy
https://en.wikipedia.org/wiki/Proxy_pattern#Remote_proxy

Intent
- Provide a surrogate or placeholder for another object to control access to it.
- Use an extra level of indirection to support distributed, controlled, or intelligent access.
- Add a wrapper and delegation to protect the real component from undue complexity.

Problem
You need to support resource-hungry objects, and you do not want to instantiate such objects unless and until they are actually requested by the client.

There are four common situations in which the Proxy pattern is applicable.

A virtual proxy is a placeholder for "expensive to create" objects. The real object is only created when a client first requests/accesses the object.

A remote proxy provides a local representative for an object that resides in a different address space. This is what the "stub" code in RPC and CORBA provides.

A protective proxy controls access to a sensitive master object. The "surrogate" object checks that the caller has the access permissions required prior to forwarding the request.

A smart proxy interposes additional actions when an object is accessed. Typical uses include:

- Counting the number of references to the real object so that it can be freed automatically when there are no more references (aka smart pointer),
- Loading a persistent object into memory when it's first referenced,
- Checking that the real object is locked before it is accessed to ensure that no other object can change it.

Example

The Proxy provides a surrogate or place holder to provide access to an object.
A check or bank draft is a proxy for funds in an account.
A check can be used in place of cash for making purchases and ultimately controls access to cash in the issuer's account.


# Iterator Design Pattern

https://cplusplus.com/reference/iterator/
https://en.wikipedia.org/wiki/Iterator_pattern

## What is iterator of a data structure?
An iterator is any object that, pointing to some element in a range of elements (such as an array or a container),
has the ability to iterate through the elements of that range using a set of operators (with at least the increment (++) and dereference (*) operators).

The most obvious form of iterator is a pointer: A pointer can point to elements in an array, and can iterate through them using the increment operator (++).
But other kinds of iterators are possible. For example, each container type (such as a list) has a specific iterator type designed to iterate through its elements.

Notice that while a pointer is a form of iterator, not all iterators have the same functionality of pointers;
Depending on the properties supported by iterators, they are classified into five different categories:

Input
Output
Forward
Bidirectional
Random Access


In object-oriented programming, the iterator pattern is a design pattern in which an iterator is used to traverse a container and access the container's elements.
The iterator pattern decouples algorithms from containers; in some cases, algorithms are necessarily container-specific and thus cannot be decoupled.
