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

int main()
{
    SkipList<string> *route = getWantedTowns();
    route->printList();
    // startig B)



    delete route;
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
