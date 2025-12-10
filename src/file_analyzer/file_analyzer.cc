#include "file_analyzer.h"

#include "text_file_reader.h"

FileAnalyzer::FileAnalyzer(std::filesystem::path file_path)
    : _file_reader{TextFileReader(file_path)}, _file_path{std::move(file_path)}
{
}

auto FileStatistics::get_in_printable_format() const -> std::string
{
    return file_path + ": " + text_stats.get_in_printable_format();
}

auto FileAnalyzer::analyze_file() const -> FileStatistics
{
    auto file_text{_file_reader.read()};
    const TextAnalyzer text_analyzer{std::move(file_text)};
    return {text_analyzer.analyze_text(), _file_path};
}
