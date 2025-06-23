#ifndef _FILE_ANALYZER_H_
#define _FILE_ANALYZER_H_

#include <string>

struct TextData
{
    std::uint32_t words_number, characters_number, lines_counter;
};

class TextAnalyzer
{
   public:
    explicit TextAnalyzer(std::string text_to_analyze);
    [[nodiscard]] auto analyze_text() const -> TextData;

   private:
    std::string _text;
};

#endif  // _FILE_ANALYZER_H_
