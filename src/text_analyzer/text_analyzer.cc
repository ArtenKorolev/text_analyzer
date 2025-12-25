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
    if (_text.empty())
    {
        return {.words_number = 0, .characters_number = 0, .lines_number = 0};
    }

    constexpr auto START_LINES_NUMBER = 1;
    std::uint32_t lines_number{START_LINES_NUMBER};
    std::uint32_t words_number{0};

    bool in_word{false};

    for (std::size_t i = 0; i < _text.size(); ++i)
    {
        const char chr = _text.at(i);

        if (_is_end_of_line(i))
        {
            ++lines_number;
        }

        if (_is_space(chr))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            ++words_number;
            in_word = true;
        }
    }

    return {.words_number = words_number,
            .characters_number = static_cast<std::uint32_t>(_text.size()),
            .lines_number = lines_number};
}

auto TextAnalyzer::_is_end_of_line(const std::size_t charIndex) const -> bool
{
    if (_text.at(charIndex) == '\n')
    {
        return true;
    }
    if (charIndex < _text.size() - 1 && _text.at(charIndex) == '\r' &&
        _text.at(charIndex + 1) == '\n')
    {
        return true;
    }

    return false;
}

auto TextAnalyzer::_is_space(const char chr) -> bool
{
    return chr == ' ' || chr == '\t' || chr == '\n';
}
