//
// Created by Bill on 9/19/2023.
//

#include <iostream>
#include <vector>

using namespace std;

#include "gtest/gtest.h"
#include "Utils.h"

class UtilsFixture : public ::testing::Test {

protected:
    void SetUp() override {}

    void TearDown() override {}
};

TEST_F(UtilsFixture, findOthers) {

    vector<string> words;
    vector<string> results;

    words.emplace_back("aaaaa");
    words.emplace_back("aaaba");
    words.emplace_back("aaaab");
    words.emplace_back("abaaa");
    words.emplace_back("baaaa");
    words.emplace_back("abaca");
    words.emplace_back("baaca");
    words.emplace_back("abaac");
    words.emplace_back("baaac");
    words.emplace_back("abacd");
    words.emplace_back("baacd");
    words.emplace_back("bcade");
    words.emplace_back("bcaad");
    words.emplace_back("bcada");
    words.emplace_back("aabaa");

    for (const auto &word: words) {
        if (Utils::find_others(word, 'a', 2))
            results.push_back(word);
    }

    cout << "Number found: " << results.size() << endl << endl;
    for (const auto &result: results) {
        cout << result << endl;
    }

    EXPECT_EQ(results.size(), 14);
}

TEST_F(UtilsFixture, findOthers_loyal) {

    vector<string> words;
    vector<string> results;

    words.emplace_back("royal");
    words.emplace_back("loyal");

    for (const auto &word: words) {
        if (Utils::find_others(word, 'l', 4))
            results.push_back(word);
    }

    cout << "Number found: " << results.size() << endl << endl;
    for (const auto &result: results) {
        cout << result << endl;
    }

    EXPECT_EQ(results.size(), 2);
}

TEST_F(UtilsFixture, findExcept) {

    vector<string> words;
    vector<string> results;

    words.emplace_back("aaaaa"); // excluded
    words.emplace_back("aabaa");
    words.emplace_back("abbaa");
    words.emplace_back("aabba");
    words.emplace_back("abcde");
    words.emplace_back("bacde");
    words.emplace_back("bcdae");
    words.emplace_back("bcdea");
    words.emplace_back("aabcd");
    words.emplace_back("bcdaa");
    words.emplace_back("bbbbb"); // excluded
    words.emplace_back("bbabb"); // excluded

    for (const auto &word: words) {
        if (Utils::find_except(word, 'a', {2}))
            results.push_back(word);
    }

    cout << "Number found: " << results.size() << endl << endl;
    for (const auto &result: results) {
        cout << result << endl;
    }

    EXPECT_EQ(results.size(), 9);
}
