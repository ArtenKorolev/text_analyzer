#ifndef _FILE_ANALYZER_H_
#define _FILE_ANALYZER_H_

#include "text_analyzer.h"
#include "text_file_reader.h"

class FileAnalyzer
{
   public:
    explicit FileAnalyzer(std::filesystem::path file_path);
    [[nodiscard]] auto analyze() const -> TextData;

   private:
    TextFileReader _file_reader;
};

#endif  // _FILE_ANALYZER_H_
