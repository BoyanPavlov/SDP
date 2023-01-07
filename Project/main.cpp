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

    for (size_t i = 0; i < numberOfConnections; i++)
    {
        cin >> connections[i].first >> connections[i].second;
    }
    return connections;
}

// template <class T>
// SkipList<T> *createSkipList(vector<string> &towns, vector<connection> &connections)
// {
//     SkipList<T> *list = new SkipList<T>;

//     for (int i = 0; i < towns.size(); i++)
//     {
//         list->pushBack(towns[i]);
//     }

//     for (size_t i = 0; i < towns.size(); i++)
//     {
//         for (size_t j = 0; j < connections.size(); j++)
//         {
//             list.iterl
//         }
//     }

//     return list;
// }

int main()
{
    size_t numberOfTowns = 0;

    cout << "Please enter number of towns: ";
    cin >> numberOfTowns;

    vector<string> towns = getTowns(numberOfTowns);
    vector<connection> connections = readConnections();

    SkipList<string> *list = createSkipList(towns, connections);

    return 0;
}
