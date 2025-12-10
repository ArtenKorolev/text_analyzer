#include "text_analyzer.h"

#include <string>

auto TextStatistics::get_in_printable_format() const -> std::string
{
    return "Lines: " + std::to_string(lines_number) + ", Words: " + std::to_string(words_number) +
           ", Characters: " + std::to_string(characters_number);
}

TextAnalyzer::TextAnalyzer(std::string text_to_analyze) : _text{std::move(text_to_analyze)}
{
}

auto TextAnalyzer::analyze_text() const -> TextStatistics
{
    return {.words_number = _count_words(),
            .characters_number = _count_characters(),
            .lines_number = _count_lines()};
}

auto TextAnalyzer::_count_words() const -> std::uint32_t
{
    std::uint32_t words_number{0};

    bool in_word = false;

    for (const char symbol : _text)
    {
        if (std::isspace(symbol) != 0)
        {
            in_word = false;
        }
        else if (!in_word)
        {
            ++words_number;
            in_word = true;
        }
    }

    return words_number;
}

auto TextAnalyzer::_count_lines() const -> std::uint32_t
{
    std::uint32_t lines_number{0};

    for (const auto &symbol : _text)
    {
        if (symbol == '\n')
        {
            ++lines_number;
        }
    }

    return lines_number + 1;
}

auto TextAnalyzer::_count_characters() const -> std::uint32_t
{
    return static_cast<std::uint32_t>(_text.size());
}
