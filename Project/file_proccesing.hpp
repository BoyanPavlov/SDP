#include <iostream>
#include <string>
#include <vector>
#include "skipList.hpp"

#include "attraction_node.hpp"

#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using connection = std::pair<string, string>;
using attr_connection = std::pair<connection, size_t>;

#ifndef _FILE_PROCESSING_HPP_
#define _FILE_PROCESSING_HPP_

// in main you have function for traversing the list
// calling the SALAM function you get the wanted sequence of attraction for the exact town or get an error

// you have a function which returns you the sequence of attractions
// this function has the path to file only

bool checkFileIsValid(const string &path)
{
    std::ifstream in(path, std::ios::in);
    if (!in)
    {
        in.close();
        return false;
    }
    in.close();
    return true;
}

bool checkIsLetter(const string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (!(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'))
        {
            return false;
        }
    }
    return true;
}

size_t extractNumber(const string &str)
{
    size_t num = 0;
    for (int i = 0; i < str.size(); i++)
    {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}

void extractInfo(std::ifstream &in, size_t &k, size_t &r, vector<attr_connection> &attr_con, size_t &min)
{
    r = -1; // overflow in order for max element
    bool flag_k = true;
    bool flag_r = true;
    bool flag_attr_con = true;
    int counter = 0;
    int pair_counter = 0;
    while (!in.eof())
    {
        string buffer;
        in >> buffer;

        if (flag_k && !checkIsLetter(buffer))
        {
            k = extractNumber(buffer);
            flag_k = false;
            continue;
        }

        if (flag_r && !checkIsLetter(buffer))
        {
            r = extractNumber(buffer);
            flag_r = false;
            attr_con.resize(r);
            continue;
        }

        if (flag_attr_con && counter != r)
        {
            if (pair_counter == 0)
            {
                attr_con[counter].first.first = buffer;
                pair_counter++;
                continue;
            }

            if (pair_counter == 1)
            {
                attr_con[counter].first.second = buffer;
                pair_counter++;
                continue;
            }

            if (!checkIsLetter(buffer) && pair_counter == 2)
            {
                attr_con[counter].second = extractNumber(buffer);
                pair_counter = 0;
            }

            counter++;
            continue;
        }

        if (counter == r)
        {
            min = extractNumber(buffer);
        }
    }
}

void printAttrConnections(vector<attr_connection> &attr_con)
{
    for (int i = 0; i < attr_con.size(); i++)
    {
        cout << attr_con[i].first.first << " "
             << attr_con[i].first.second << " "
             << attr_con[i].second << "\n";
    }
}

void readFile(const string &path,
              size_t &k, size_t &r, vector<attr_connection> &attr_con, size_t &min)
{
    if (checkFileIsValid(path))
    {
        std::ifstream in(path, std::ios::in);
        if (!in.is_open())
        {
            throw std::runtime_error("Couldn't open the file\n");
        }

        // cout << "File: " << path << " has opened successfully!\n";
        // cout << "...\n";
        // cout << "Loading elements\n";

        extractInfo(in, k, r, attr_con, min);

        // cout << k << " " << r << '\n';
        // printAttrConnections(attr_con);
        // cout << min << '\n';
        // cout << "This is what was read from file as info\n";
    }
    else
    {
        throw std::runtime_error("File doesn't exist\n");
    }
}

vector<string> extractAttractionObj(vector<attr_connection> &attr_con, size_t numOfObj)
{
    vector<string> attractions;
    bool flag_elem1_found = false;
    bool flag_elem2_found = false;
    for (size_t i = 0; i < attr_con.size(); i++)
    {
        flag_elem1_found = false;
        flag_elem2_found = false;

        for (size_t j = 0; j < attractions.size(); j++)
        {
            if (attractions[j] == attr_con[i].first.first)
            {
                flag_elem1_found = true;
            }
            else if (attractions[j] == attr_con[i].first.second)
            {
                flag_elem2_found = true;
            }

            if (flag_elem1_found && flag_elem2_found)
            {
                break;
            }
        }

        if (!flag_elem1_found)
        {
            attractions.push_back(attr_con[i].first.first);
        }

        if (!flag_elem2_found)
        {
            attractions.push_back(attr_con[i].first.second);
        }
    }

    if (attractions.size() != numOfObj)
    {
        throw std::runtime_error("Error in logic - couldn't extract all attractions");
    }

    return attractions;
}

// main function here
SkipList<string> *processFile(const string &path)
{
    // number of objects
    size_t k = 0;
    // number of connections
    size_t r = 0;
    size_t minutes = 0;
    vector<attr_connection> attr_con;
    readFile(path, k, r, attr_con, minutes);

    vector<string> attractions = extractAttractionObj(attr_con, k);

    SkipList<string> *attr_route = getSequenceOfAttractions(attractions, attr_con, minutes);

    return attr_route;
}

#endif // _FILE_PROCESSING_HPP_