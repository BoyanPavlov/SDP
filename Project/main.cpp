#include <iostream>
#include <string>
#include <vector>
#include "skipList.hpp"
#include "route_towns.hpp"
#include "file_proccesing.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using connection = std::pair<string, string>;

int main()
{
    // A)

    // SkipList<string> *route = getWantedTowns();
    // route->printList();

    // B)

    string Pl = "Plovdiv.txt";
    SkipList<string> *attractions = processFile(Pl);

    // delete route;
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
