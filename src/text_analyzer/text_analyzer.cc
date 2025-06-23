#include "text_analyzer.h"

#include <string>

auto TextData::get_format_info() const -> std::string
{
    return "Lines: " + std::to_string(lines_number) + ", Wrods: " + std::to_string(words_number) +
           ", Characters: " + std::to_string(characters_number);
}

TextAnalyzer::TextAnalyzer(std::string text_to_analyze) : _text{std::move(text_to_analyze)}
{
}

auto TextAnalyzer::analyze_text() const -> TextData
{
    TextData text_data{_count_words(), _count_characters(), _count_lines()};
    return text_data;
}

auto TextAnalyzer::_count_words() const -> std::uint32_t
{
    std::uint32_t words_number = 0;

    for (int i = 1; i < _text.size(); ++i)
    {
        if (_check_if_char_is_after_word(i) ||
            i == _text.size() - 1 && (std::isalnum(_text.at(i)) != 0))
        {
            ++words_number;
        }
    }

    return words_number;
}

auto TextAnalyzer::_check_if_char_is_after_word(int char_index) const -> bool
{
    return (_text.at(char_index) == ' ' || _text.at(char_index) == '\n') &&
           (std::isalnum(_text.at(char_index - 1)) != 0);
}

auto TextAnalyzer::_count_lines() const -> std::uint32_t
{
    std::uint32_t lines_number = 0;

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
    std::uint32_t characters_number = 0;

    for (const auto &symbol : _text)
    {
        if (std::isalnum(symbol) != 0)
        {
            ++characters_number;
        }
    }

    return characters_number;
}
