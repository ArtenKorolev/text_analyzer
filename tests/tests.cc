#include <gtest/gtest.h>

#include "text_analyzer.h"

// TODO: add more tests

TEST(TextAnalyzerTest, NormalText)
{
    TextAnalyzer analyzer{"Hello, world!\nHello, mom!"};
    auto res = analyzer.analyze_text();

    EXPECT_EQ(res.characters_number, 25);
    EXPECT_EQ(res.lines_number, 2);
    EXPECT_EQ(res.words_number, 4);
}

TEST(TextAnalyzerTest, EmptyText)
{
    TextAnalyzer analyzer{""};
    auto res = analyzer.analyze_text();

    EXPECT_EQ(res.characters_number, 0);
    EXPECT_EQ(res.lines_number, 1);
    EXPECT_EQ(res.words_number, 0);
}

TEST(TextAnalyzerTest, OnlySpacesAndTabs)
{
    TextAnalyzer analyzer{"    \t  \t"};
    auto res = analyzer.analyze_text();

    EXPECT_EQ(res.characters_number, 8);
    EXPECT_EQ(res.lines_number, 1);
    EXPECT_EQ(res.words_number, 0);
}

TEST(TextAnalyzerTest, MultipleLines)
{
    TextAnalyzer analyzer{"Line one\nLine two\nLine three"};
    auto res = analyzer.analyze_text();

    EXPECT_EQ(res.characters_number, 28);
    EXPECT_EQ(res.lines_number, 3);
    EXPECT_EQ(res.words_number, 6);
}

TEST(TextAnalyzerTest, TextWithPunctuation)
{
    TextAnalyzer analyzer{"Hi! Are you okay? Yes, I'm fine."};
    auto res = analyzer.analyze_text();

    EXPECT_EQ(res.characters_number, 32);
    EXPECT_EQ(res.lines_number, 1);
    EXPECT_EQ(res.words_number, 7);
}

TEST(TextAnalyzerTest, OnlyNewLines)
{
    TextAnalyzer analyzer{"\n\n\n"};
    auto res = analyzer.analyze_text();

    EXPECT_EQ(res.characters_number, 3);
    EXPECT_EQ(res.lines_number, 4);
    EXPECT_EQ(res.words_number, 0);
}