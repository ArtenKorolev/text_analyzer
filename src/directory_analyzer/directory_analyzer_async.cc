#include "directory_analyzer_async.h"

#include <future>
#include <vector>

#include "directory_scanner.h"
#include "file_analyzer.h"

DirectoryAnalyzerAsync::DirectoryAnalyzerAsync(std::filesystem::path dir_path)
    : _dir_path{std::move(dir_path)}
{
}

auto DirectoryAnalyzerAsync::analyze_dir() const -> std::vector<FileStatistics>
{
    const DirectoryScanner scanner{_dir_path};
    const auto files{scanner.get_files()};

    std::vector<FileStatistics> all_files_stats;
    all_files_stats.reserve(files.size());
    std::vector<std::future<FileStatistics>> tasks;
    tasks.reserve(files.size());

    for (const auto &file : files)
    {
        tasks.emplace_back(std::async(std::launch::async,
                                      [&file]() -> FileStatistics
                                      {
                                          const FileAnalyzer analyzer{file};
                                          auto file_data{analyzer.analyze_file()};
                                          return file_data;
                                      }));
    }

    for (auto &future : tasks)
    {
        all_files_stats.emplace_back(future.get());
    }

    return all_files_stats;
}
