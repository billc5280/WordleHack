#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "utils/Utils.h"

using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();

    vector<string> words = Utils::findFiveLetterWords();
    vector<string> possibilities;

    cout << endl << "Number of five letter words: " << words.size() << endl << endl;

//    vector<char> excludedChar{'d','i','e','u','b','n','l','k','s','t'};
//
//    vector<char> inPlaceChar{'a', 'o', 'c'};
//    vector<int> inPlaceIdx{2, 1, 0};
//
//    vector<char> outOfPlaceChar{};
//    vector<set<int>> outOfPlaceIdx{};

    vector<char> excludedChar{'a', 'd', 'u', 'c'};

    vector<char> inPlaceChar{'i', 'e', 's'};
    vector<int> inPlaceIdx{2, 4, 0};

    vector<char> outOfPlaceChar{'l'};
    vector<set<int>> outOfPlaceIdx{{1}};

    // First guess 'adieu'
    for (const string &word: words) {

        bool excludedResult = Utils::getExcludedCharWords(excludedChar, word);
        bool inPlaceResult = Utils::getInPlaceCharWords(inPlaceChar, inPlaceIdx, word);
        bool outOfPlaceResult = Utils::getOutOfPlaceCharWords(outOfPlaceChar, outOfPlaceIdx, word);

        if (excludedResult && inPlaceResult && outOfPlaceResult)
            possibilities.push_back(word);
    }

    if (possibilities.empty())
        cout << "No possible solutions found!" << endl;
    else if (possibilities.size() == 1)
        cout << "The solution to this weeks Wordle is: '" << possibilities.at(0) << "'" << endl;
    else {
        for (const auto &possibility: possibilities)
            cout << possibility << endl;

        cout << endl << "Number of matches: " << possibilities.size() << endl;
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

    cout << endl << "Elapsed time: " << duration.count() << " ms" << endl;

    return 0;
}
