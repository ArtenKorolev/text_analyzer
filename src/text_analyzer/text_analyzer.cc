#include "text_analyzer.h"

#include <string>

auto TextStatistics::serialize() const -> std::string
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

    constexpr auto INITIAL_LINES_NUMBER = 1;

    TextStatistics stats{.words_number = 0,
                         .characters_number = static_cast<std::uint32_t>(_text.size()),
                         .lines_number = INITIAL_LINES_NUMBER};

    _analyze_text_impl(stats);

    return stats;
}

void TextAnalyzer::_analyze_text_impl(TextStatistics& stats) const
{
    bool in_word{false};

    for (std::size_t i = 0; i < _text.size(); ++i)
    {
        const char chr = _text.at(i);

        if (_is_end_of_line(i))
        {
            ++stats.lines_number;
        }

        if (_is_space(chr))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            ++stats.words_number;
            in_word = true;
        }
    }
}

auto TextAnalyzer::_is_end_of_line(const std::size_t charIndex) const -> bool
{
    return _is_end_of_line_regular(charIndex) || _is_end_of_line_windows(charIndex);
}

auto TextAnalyzer::_is_end_of_line_regular(const std::size_t charIndex) const -> bool
{
    return _text.at(charIndex) == '\n';
}

auto TextAnalyzer::_is_end_of_line_windows(const std::size_t charIndex) const -> bool
{
    return charIndex < _text.size() - 1 && _text.at(charIndex) == '\r' &&
           _text.at(charIndex + 1) == '\n';
}

auto TextAnalyzer::_is_space(const char chr) -> bool
{
    return chr == ' ' || chr == '\t' || chr == '\n';
}
