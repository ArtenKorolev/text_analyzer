#ifndef _TEXT_ANALYZER_H_
#define _TEXT_ANALYZER_H_

#include <string>

struct TextStatistics
{
    [[nodiscard]] auto serialize() const -> std::string;

    std::uint32_t words_number, characters_number, lines_number;
};

class TextAnalyzer
{
   public:
    explicit TextAnalyzer(std::string text_to_analyze);
    [[nodiscard]] auto analyze_text() const -> TextStatistics;

   private:
    void _analyze_text_impl(TextStatistics &stats) const;
    [[nodiscard]] static auto _is_space(char chr) -> bool;
    [[nodiscard]] auto _is_end_of_line(std::size_t charIndex) const -> bool;
    [[nodiscard]] auto _is_end_of_line_regular(std::size_t charIndex) const -> bool;
    [[nodiscard]] auto _is_end_of_line_windows(std::size_t charIndex) const -> bool;

    std::string _text;
};

#endif  // _TEXT_ANALYZER_H_
