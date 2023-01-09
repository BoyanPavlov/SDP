#include <iostream>
#include <string>
#include <vector>
#include "skipList.hpp"

#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using connection = std::pair<string, string>;

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

void readFile(const string &path)
{
    if (checkFileIsValid(path))
    {
        std::ifstream in(path, std::ios::in);
        if (!in.is_open())
        {
            throw std::runtime_error("Couldn't open the file\n");
        }
    }
    else
    {
        throw std::runtime_error("File doesn't exist\n");
    }
}

template <class T>
SkipList<T> processFile(const string &path)
{
    
}

#endif // _FILE_PROCESSING_HPP_