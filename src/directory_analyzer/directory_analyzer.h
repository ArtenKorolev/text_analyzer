#ifndef _DIRECTORY_ANALYZER_H_
#define _DIRECTORY_ANALYZER_H_

#include <filesystem>
#include <vector>

#include "file_analyzer.h"

class DirectoryAnalyzer
{
   public:
    explicit DirectoryAnalyzer(std::filesystem::path dir_path);
    [[nodiscard]] auto analyze_dir() const -> std::vector<FileData>;
    [[nodiscard]] auto analyze_dir_one_thread() const -> std::vector<FileData>;

   private:
    std::filesystem::path _dir_path;
};

#endif  // _DIRECTORY_ANALYZER_H_
