#ifndef _ATTRACTION_NODE_
#define _ATTRACTION_NODE_

#include <iostream>
#include <string>
#include <vector>
#include "skipList.hpp"
#include "route_towns.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using connection = std::pair<string, string>;
using attr_connection = std::pair<connection, size_t>;
using attr_conn_node = std::pair<string, size_t>;

struct Attrcation_node
{
    string nameOfAttr;
    vector<attr_conn_node> otherObj;
    Attrcation_node(const string &name) : nameOfAttr(name) {}
};

bool isObjInList(SkipList<string> *sequence, const string &str)
{
    sequence->resetIterator();
    while (sequence->getIterator() != sequence->end())
    {
        if (*(sequence->getIterator()) == str)
        {
            return true;
        }
        ++(sequence->getIterator());
    }
    return false;
}

void printAttractions(vector<Attrcation_node> &arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << "========" << arr[i].nameOfAttr << "========\n";
        for (int j = 0; j < arr[i].otherObj.size(); j++)
        {
            cout << arr[i].otherObj[j].first << " " << arr[i].otherObj[j].second << '\n';
        }
    }
}

void addConnection(vector<attr_conn_node> &otherObj, const string &attractionToAdd, size_t cost)
{
    bool found = false;
    for (int i = 0; i < otherObj.size(); i++)
    {
        if (otherObj[i].first == attractionToAdd)
        {
            found = true;
        }
    }
    if (!found)
    {
        otherObj.push_back({attractionToAdd, cost});
    }
}

int getIndexOfAttraction(vector<Attrcation_node> &attractions, const string &toFind)
{
    int i = -1;
    for (i = 0; i < attractions.size(); i++)
    {
        if (attractions[i].nameOfAttr == toFind)
        {
            return i;
        }
    }
    return i;
}

vector<Attrcation_node> makeAttrConnections(vector<string> &obj, vector<attr_connection> &conn)
{
    vector<Attrcation_node> attractions;
    for (size_t i = 0; i < obj.size(); i++)
    {
        attractions.push_back(obj[i]);
    }

    for (int i = 0; i < conn.size(); i++)
    {
        for (size_t j = 0; j < attractions.size(); j++)
        {
            if (attractions[j].nameOfAttr == conn[i].first.first)
            {
                addConnection(attractions[j].otherObj, conn[i].first.second, conn[i].second);

                int index = getIndexOfAttraction(attractions, conn[i].first.second);
                if (index > -1)
                {
                    addConnection(attractions[index].otherObj, conn[i].first.first, conn[i].second);
                }
                else
                {
                    std::runtime_error("How on earth I lost the index...\n");
                }

                break;
            }
            if (attractions[j].nameOfAttr == conn[i].first.second)
            {
                addConnection(attractions[j].otherObj, conn[i].first.first, conn[i].second);

                int index = getIndexOfAttraction(attractions, conn[i].first.first);
                if (index > -1)
                {
                    addConnection(attractions[index].otherObj, conn[i].first.second, conn[i].second);
                }
                else
                {
                    std::runtime_error("How on earth I lost the index...\n");
                }
                break;
            }
        }
    }

    // printAttractions(attractions);

    return attractions;
}

SkipList<string> *findSequenceHelper()
{
}

void findSequence(vector<Attrcation_node> &attractions, size_t minutes)
{
    size_t maxObj = 1;
    size_t currMax = 1;
    size_t takenTime = 0;

    vector<string> sequence;
}

SkipList<string> *getSequenceOfAttractions(vector<string> &obj, vector<attr_connection> &conn, size_t minutes)
{
    vector<Attrcation_node> attractions = makeAttrConnections(obj, conn);
    string start = "Railstation";

    SkipList<string> *sequence = new SkipList<string>;
    sequence->pushBack(start);

    int index = getIndexOfAttraction(attractions, start);
    bool canHaveATrip = false;

    int currentCost = 0;
    for (size_t i = 0; i < attractions[index].otherObj.size(); i++)
    {
        currentCost = 2 * attractions[index].otherObj[i].second;
        if (currentCost < minutes)
        {
            canHaveATrip = true;
            break;
        }
    }
    if (!canHaveATrip)
    {
        return sequence;
    }

    findSequence(attractions, minutes);
    return sequence;
}

#endif // _ATTRACTION_NODE_