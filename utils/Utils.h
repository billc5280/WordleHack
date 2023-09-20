//
// Created by Bill on 9/19/2023.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

class Utils {

public:
    Utils() = default;

    static vector<string> findFiveLetterWords();
    static bool find_others(const string &word, char ch, int include);
    static bool find_except(const string &word, char ch, const set<int> &excludes);
};

#endif // UTILS_H
