#ifndef _DIRECTORY_ANALYZER_ONE_THREAD_H_
#define _DIRECTORY_ANALYZER_ONE_THREAD_H_

#include <filesystem>
#include <vector>

#include "file_analyzer.h"

class DirectoryAnalyzerOneThread
{
   public:
    explicit DirectoryAnalyzerOneThread(std::filesystem::path dir_path);
    [[nodiscard]] auto analyze_dir() const -> std::vector<FileStatistics>;

   private:
    std::filesystem::path _dir_path;
};

#endif  // _DIRECTORY_ANALYZER_ONE_THREAD_H_
