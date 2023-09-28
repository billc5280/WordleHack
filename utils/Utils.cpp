//
// Created by Bill on 9/19/2023.
//

#include "Utils.h"

vector<string> Utils::findFiveLetterWords() {
    vector<string> result;

    ifstream dictionaryFile;

    string word;

    dictionaryFile.open("../data/freebsd-v1.14.txt");

    while (!dictionaryFile.eof()) {
        dictionaryFile >> word;

        if (word.length() == 5)
            result.push_back(word);
    }

    dictionaryFile.close();

    return result;
}

// Letter is in word in the 'include' spot but may also have more than one entry.
bool Utils::find_others(const string &word, char ch, int include) {

    if (word.at(include) != ch)
        return false;
    else
        return true;

//    if (word.find_first_of(ch, include) != string::npos)
//        return true;
//    else
//        return false;
}


// Letter is in word but not in the 'exclude' spot.
bool Utils::find_except(const string &word, char ch, const set<int> &excludes) {
    bool rc = false;

    for (int i = 0; i < word.length(); i++) {
        auto pos = word.find_first_of(ch, i);

        if (pos != string::npos && excludes.contains((int) pos))
            return false;
        else if (pos != string::npos && !excludes.contains((int) pos))
            rc = true;
        else
            continue;
    }

    return rc;
}

bool Utils::getOutOfPlaceCharWords(vector<char> &outOfPlaceChar, vector<set<int>> &outOfPlaceIdx, const string &word) {
    bool outOfPlaceResult = true;
    int index = 0;

    for (const auto &ch: outOfPlaceChar) {
        if (!Utils::find_except(word, ch, outOfPlaceIdx.at(index))) {
            outOfPlaceResult = false;
            break;
        }

        index++;
    }

    return outOfPlaceResult;
}

bool Utils::getInPlaceCharWords(vector<char> &inPlaceChar, vector<int> &inPlaceIdx, const string &word) {
    bool inPlaceResult = true;
    int index = 0;

    for (const auto &ch: inPlaceChar) {
        if (!Utils::find_others(word, ch, inPlaceIdx.at(index))) {
            inPlaceResult = false;
            break;
        }

        index++;
    }

    return inPlaceResult;
}

bool Utils::getExcludedCharWords(vector<char> &excludedChar, const string &word) {
    bool excludedResult = true;

    for (const auto &ch: excludedChar) {
        if (word.find(ch) != string::npos) {
            excludedResult = false;
            break;
        }
    }

    return excludedResult;
}
