#ifndef _DIRECTORY_ANALYZER_ASYNC_H_
#define _DIRECTORY_ANALYZER_ASYNC_H_

#include <filesystem>
#include <vector>

#include "file_analyzer.h"

class DirectoryAnalyzerAsync
{
   public:
    explicit DirectoryAnalyzerAsync(std::filesystem::path dir_path);
    [[nodiscard]] auto analyze_dir() const -> std::vector<FileStatistics>;

   private:
    std::filesystem::path _dir_path;
};

#endif  // _DIRECTORY_ANALYZER_ASYNC_H_
