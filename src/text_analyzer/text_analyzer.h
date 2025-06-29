#ifndef _TEXT_ANALYZER_H_
#define _TEXT_ANALYZER_H_

#include <string>

struct TextStatistics
{
    [[nodiscard]] auto get_in_printable_format() const -> std::string;

    std::uint32_t words_number, characters_number, lines_number;
};

class TextAnalyzer
{
   public:
    explicit TextAnalyzer(std::string text_to_analyze);
    [[nodiscard]] auto analyze_text() const -> TextStatistics;

   private:
    [[nodiscard]] auto _count_words() const -> std::uint32_t;
    [[nodiscard]] auto _check_if_char_is_after_word(int char_index) const -> bool;
    [[nodiscard]] auto _count_lines() const -> std::uint32_t;
    [[nodiscard]] auto _count_characters() const -> std::uint32_t;

    std::string _text;
};

#endif  // _TEXT_ANALYZER_H_
