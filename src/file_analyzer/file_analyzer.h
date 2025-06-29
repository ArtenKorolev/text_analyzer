#ifndef _FILE_ANALYZER_H_
#define _FILE_ANALYZER_H_

#include "text_analyzer.h"
#include "text_file_reader.h"

struct FileStatistics
{
    [[nodiscard]] auto get_in_printable_format() const -> std::string;

    TextStatistics text_stats;
    std::string file_path;
};

class FileAnalyzer
{
   public:
    explicit FileAnalyzer(std::filesystem::path file_path);
    [[nodiscard]] auto analyze_file() const -> FileStatistics;

   private:
    TextFileReader _file_reader;
    std::filesystem::path _file_path;
};

#endif  // _FILE_ANALYZER_H_
