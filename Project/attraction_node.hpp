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

void findMinSpanningTree(Attrcation_node start, Attrcation_node &end,
                         vector<Attrcation_node> &attrcations,
                         size_t curr_time, size_t max_time,
                         vector<string> n_sequence, vector<string> &real, bool &changed)
{
    // int index = getIndexOfAttraction(attrcations, start.nameOfAttr);
    if (start.nameOfAttr == end.nameOfAttr)
    {
        n_sequence.push_back(start.nameOfAttr);
        if (!changed)
        {
            changed = true;
            real = n_sequence;
        }
        return;
    }

    for (size_t i = 0; i < start.otherObj.size(); i++)
    {
        int tempTime = curr_time + start.otherObj[i].second;
        if (tempTime >= max_time)
        {
            return;
        }
        n_sequence.push_back(start.otherObj[i].first);
        int pos = getIndexOfAttraction(attrcations, start.otherObj[i].first);
        findMinSpanningTree(attrcations[i], end, attrcations, tempTime, max_time, n_sequence, real, changed);
    }
}

void findSequenceHelper(vector<string> sequence,
                        vector<Attrcation_node> &attractions,
                        vector<bool> visited, size_t currTime, size_t minutes, size_t &max)
{
    string last = sequence.back();
    int index = getIndexOfAttraction(attractions, last);
    visited[index] = true;
    Attrcation_node currNode = attractions[index];

    int vis_index = -1;

    for (size_t i = 0; i < currNode.otherObj.size(); i++)
    {
        vis_index = getIndexOfAttraction(attractions, currNode.otherObj[i].first);
        int tempTime = currTime + currNode.otherObj[i].second;

        // Railstation RomanStadium DzhumayaSquare ArtGallery AntiqueTheatre ArtGallery Railstation
        if (tempTime >= minutes)
        {
            return;
        }

        if (!visited[vis_index])
        {
            sequence.push_back(currNode.otherObj[i].first);
            currTime = tempTime;
            findSequenceHelper(sequence, attractions, visited, currTime, minutes, max);
        }

        if (currNode.otherObj[i].first == sequence[0])
        {
            sequence.push_back(currNode.otherObj[i].first);
            return;
        }

        if (*sequence.begin() == *sequence.end())
        {
            max = sequence.size();
            return;
        }

        
    }
}

vector<string> findSequence(vector<Attrcation_node> &attractions, size_t minutes)
{
    size_t maxObj = 0;
    size_t currMax = 1;
    size_t takenTime = 0;

    vector<string> sequence;
    vector<bool> visited;
    visited.resize(attractions.size());

    sequence.push_back(attractions[0].nameOfAttr);

    // TO DELETE
    // Railstation RomanStadium DzhumayaSquare ArtGallery AntiqueTheatre ArtGallery Railstation
    int startIn = getIndexOfAttraction(attractions, "AntiqueTheatre");
    int endIn = getIndexOfAttraction(attractions, "Railstation");

    vector<string> shit;
    vector<string> real;
    bool salam = false;

    findMinSpanningTree(attractions[startIn], attractions[endIn],
                        attractions, 34, minutes, shit, real, salam);

    // TO DELETE

    while (currMax > maxObj)
    {
        maxObj = currMax;
        findSequenceHelper(sequence, attractions, visited, takenTime, minutes, currMax);
    }

    return sequence;
}

void modifyAttractions(vector<Attrcation_node> &attractions)
{
    string start = "Railstation";
    for (size_t i = 0; i < attractions.size(); i++)
    {
        for (size_t j = 0; j < attractions[i].otherObj.size(); j++)
        {
            if (attractions[i].otherObj[j].first == start)
            {
                std::swap(attractions[i].otherObj[j],
                          attractions[i].otherObj[attractions[i].otherObj.size() - 1]);
            }
        }
    }
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
    modifyAttractions(attractions);
    findSequence(attractions, minutes);
    return sequence;
}

#endif // _ATTRACTION_NODE_