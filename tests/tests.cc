#include <gtest/gtest.h>

#include "text_analyzer.h"

TEST(TextAnalyzerTest, NormalText)
{
    TextAnalyzer analyzer{"Hello, world!\nHello, mom!"};
    auto res = analyzer.analyze_text();

    EXPECT_EQ(res.characters_number, 18);
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

    EXPECT_EQ(res.characters_number, 6);
    EXPECT_EQ(res.lines_number, 1);
    EXPECT_EQ(res.words_number, 0);
}

TEST(TextAnalyzerTest, MultipleLines)
{
    TextAnalyzer analyzer{"Line one\nLine two\nLine three"};
    auto res = analyzer.analyze_text();

    EXPECT_EQ(res.characters_number, 26);
    EXPECT_EQ(res.lines_number, 3);
    EXPECT_EQ(res.words_number, 6);
}

TEST(TextAnalyzerTest, TextWithPunctuation)
{
    TextAnalyzer analyzer{"Hi! Are you okay? Yes, I'm fine."};
    auto res = analyzer.analyze_text();

    EXPECT_EQ(res.characters_number, 31);
    EXPECT_EQ(res.lines_number, 1);
    EXPECT_EQ(res.words_number, 7);
}

TEST(TextAnalyzerTest, OnlyNewLines)
{
    TextAnalyzer analyzer{"\n\n\n"};
    auto res = analyzer.analyze_text();

    EXPECT_EQ(res.characters_number, 0);
    EXPECT_EQ(res.lines_number, 3);
    EXPECT_EQ(res.words_number, 0);
}