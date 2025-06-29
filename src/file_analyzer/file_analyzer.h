#ifndef _FILE_ANALYZER_H_
#define _FILE_ANALYZER_H_

#include "text_analyzer.h"
#include "text_file_reader.h"

struct FileData
{
    TextData text_data;
    std::string file_path;
};

class FileAnalyzer
{
   public:
    explicit FileAnalyzer(std::filesystem::path file_path);
    [[nodiscard]] auto analyze() const -> FileData;

   private:
    TextFileReader _file_reader;
    std::filesystem::path _file_path;
};

#endif  // _FILE_ANALYZER_H_
