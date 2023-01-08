#include <iostream>
#include <string>
#include <vector>
#include "skipList.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using connection = std::pair<string, string>;

bool isStringValid(const string &input)
{
    for (int i = 0; i < input.size(); i++)
    {
        if (!(('a' <= input[i] && 'z' >= input[i]) || ('A' <= input[i] && 'Z' >= input[i])))
        {
            return false;
        }
    }
    return true;
}

vector<string> getTowns(size_t numberOfTowns)
{
    vector<string> towns;
    towns.resize(numberOfTowns);

    cout << "Please entere the sequens of towns \n: ";
    bool notValidTown = true;

    for (int i = 0; i < numberOfTowns; i++)
    {
        notValidTown = true;
        do
        {
            cin >> towns[i];
            if (!isStringValid(towns[i]))
            {
                towns.pop_back();
                notValidTown = true;
            }
            else
            {
                notValidTown = false;
            }

        } while (notValidTown);
    }
    return towns;
}

vector<connection> readConnections()
{
    vector<connection> connections;
    size_t numberOfConnections = 0;
    cout << "Please enter the number of the direct connections: ";
    cin >> numberOfConnections;
    connections.resize(numberOfConnections);

    for (size_t i = 0; i < numberOfConnections; i++)
    {
        cin >> connections[i].first >> connections[i].second;
    }
    return connections;
}

template <class T>
SkipList<T> *createSkipList(vector<T> &towns)
{
    SkipList<T> *list = new SkipList<T>;

    for (int i = 0; i < towns.size(); i++)
    {
        list->pushBack(towns[i]);
    }

    return list;
}

// template <class T>
// typename SkipList<T>::Iterator checkIfExists(SkipList<T> *list, const T &town)
// {
//     list->resetIterator();
//     while (list->getIterator() != list->end())
//     {
//         if (*(list->getIterator()) == town)
//         {
//             return Iterator(list->getIterator());
//         }
//         (list->getIterator())++;
//     }
//
//     return SkipList<T>::Iterator(nullptr);
// }

template <class T>
SkipListNode<T> *getNode(SkipList<T> *list, const T &town)
{
    list->resetIterator();
    while (list->getIterator() != list->end())
    {
        if (*(list->getIterator()) == town)
        {
            return list->getIterator().getNode();
        }
        ++(list->getIterator());
    }
    return nullptr;
}

void makeConnections(vector<connection> &connections, SkipList<string> *&list)
{
    list->resetIterator();

    while (list->getIterator() != list->end())
    {
        for (int i = 0; i < connections.size(); i++)
        {
            SkipListNode<string> *toChange = getNode(list, connections[i].first);
            SkipListNode<string> *toAdd = getNode(list, connections[i].second);
            if (toChange)
            {
                toChange->jumpNode = toAdd;
            }
        }

        (list->getIterator())++;
    }
}

template <class T>
SkipList<T> *findRoute(SkipList<T> *list, vector<T> wantedTowns)
{
    list->resetIterator();
    SkipList<T> *route = new SkipList<T>;
    // route->pushBack(*(list->begin()));

    int i = 0;
    while (list->getIterator() != list->end())
    {
        route->pushBack(*(list->getIterator()));
        if (i >= wantedTowns.size())
        {
            (list->getIterator())++;
            continue;
        }

        if (*(list->getIterator().next()) == wantedTowns[i])
        {
            while (*list->getIterator() != wantedTowns[i])
            {
                (list->getIterator())++;
            }
            i++;
        }
        else if (*(list->getIterator()) == wantedTowns[i])
        {
            i++;
            if (*(list->getIterator().next()) == wantedTowns[i])
            {
                while (*list->getIterator() != wantedTowns[i] && list->getIterator() != list->end())
                {
                    (list->getIterator())++;
                }
                i++;
            }
        }
        else
        {
            (list->getIterator())++;
        }
    }

    return route;
}

int main()
{
    size_t numberOfTowns = 0;

    cout << "Please enter number of towns: ";
    cin >> numberOfTowns;

    vector<string> towns = getTowns(numberOfTowns);
    SkipList<string> *list = createSkipList(towns);
    vector<connection> connections = readConnections();
    makeConnections(connections, list);

    size_t numberOfWantedTowns = 0;
    cout << "Please enter number of wanted towns\n";
    cin >> numberOfTowns;
    vector<string> wantedTowns = getTowns(numberOfTowns);
    SkipList<string> *route = findRoute(list, wantedTowns);
    route->printList();

    delete route;
    delete list;
    return 0;
}

// 9
// Sofia Pazardzhik Plovdiv Dimitrovgrad StaraZagora NovaZagora Yambol Karnobat Burgas
// 5
// Sofia Plovdiv
// Plovdiv NovaZagora
// Dimitrovgrad NovaZagora
// StaraZagora Yambol
// NovaZagora Burgas
// 3
// Plovdiv StaraZagora Yambol

// Output: Sofia Plovdiv Dimitrovgrad StaraZagora Yambol Karnobat Burgas
