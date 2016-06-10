#include <gtest/gtest.h>

#include <regex>
#include <simmo/iterator/regex.hpp>

using namespace std;

TEST(regex_iterator_test, for_each)
{
    const string str("foo bar baz");
    regex re("\\w+");

    vector<string> matches;
    sregex_iterator it(str.begin(), str.end(), re);
    for (auto match : it)
        matches.push_back(match.str());

    vector<string> matches_expect = {"foo", "bar", "baz"};

    EXPECT_EQ(matches, matches_expect);
}

TEST(regex_iterator_test, token_for_each)
{
    const string str("foo bar baz");
    regex re("\\s");

    vector<string> tokens;
    sregex_token_iterator it(str.begin(), str.end(), re, -1);
    for (auto token : it)
        tokens.push_back(token.str());

    vector<string> tokens_expect = {"foo", "bar", "baz"};

    EXPECT_EQ(tokens, tokens_expect);
}
