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

    cout << "Number of five letter words: " << words.size() << endl << endl;

    // First guess 'adieu'
    for (const string &word: words) {

        // Example :
        //   Second guess: 'baste'
        //   Third guess : 'cheap'
        //   Fourth guess: 'cream'
        //   Fifth guess : 'clear' (This is the wordle word.)
        //   if (find_others(word, 'a', 3)
        //       && word.find('d') == string::npos
        //       && word.find('i') == string::npos
        //       && find_others(word, 'e', 2)
        //       && word.find('u') == string::npos
        //       && word.find('b') == string::npos
        //       && word.find('s') == string::npos
        //       && word.find('t') == string::npos
        //       && word.find('h') == string::npos
        //       && word.find('p') == string::npos
        //       && word.find('m') == string::npos
        //       && find_others(word, 'c', 0)
        //       && find_except(word, 'r', { 1 })
        //    )

        if (//word.find('a') == string::npos
//                Utils::find_except(word, 'a', {0,4})
                Utils::find_others(word, 'a', 2)
                && word.find('d') == string::npos
                && word.find('i') == string::npos
                // && Utils::find_except(word, 'i', {1, 2})
                //                && word.find('e') == string::npos
                && Utils::find_others(word, 'e', 4)
                //                && Utils::find_except(word, 'e', {1,3})
                && word.find('u') == string::npos
                // && Utils::find_except(word, 'u', {3, 4})
                && Utils::find_others(word, 'r', 3)
                && Utils::find_others(word, 's', 0)
                && word.find('z') == string::npos
                && word.find('b') == string::npos
                && word.find('h') == string::npos
            // && word.find('n') == string::npos
            // && word.find('l') == string::npos
            // && word.find('c') == string::npos
            // && Utils::find_except(word, 'r', {2, 4})
//                && Utils::find_others(word, 'o', 2)
                )

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
