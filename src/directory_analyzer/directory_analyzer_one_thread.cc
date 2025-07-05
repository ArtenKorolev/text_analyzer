#include "directory_analyzer_one_thread.h"

#include "config.h"
#include "directory_scanner.h"

DirectoryAnalyzerOneThread::DirectoryAnalyzerOneThread(std::filesystem::path dir_path)
    : _dir_path{std::move(dir_path)}
{
}

auto DirectoryAnalyzerOneThread::analyze_dir() const -> std::vector<FileStatistics>
{
    static_assert(config::DEBUG, "This method can be used only in debug mode");

    auto files{DirectoryScanner(_dir_path).get_files()};
    std::vector<FileStatistics> all_files_stats;
    all_files_stats.reserve(files.size());

    for (const auto &file : files)
    {
        FileAnalyzer file_analyzer{file};
        all_files_stats.emplace_back(file_analyzer.analyze_file());
    }

    return all_files_stats;
}
