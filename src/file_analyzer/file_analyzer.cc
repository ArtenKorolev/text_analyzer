#include "file_analyzer.h"

#include "text_file_reader.h"

FileAnalyzer::FileAnalyzer(std::filesystem::path file_path)
    : _file_reader{TextFileReader(std::move(file_path))}
{
}

auto FileAnalyzer::analyze() const -> TextData
{
    auto file_text = _file_reader.read();
    TextAnalyzer text_analyzer{std::move(file_text)};
    return text_analyzer.analyze_text();
}
