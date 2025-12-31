#include <future>
#include <vector>

#include "directory_analyzer_async.h"
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
    std::vector<std::future<FileStatistics>> futures;
    futures.reserve(files.size());

    for (const auto &file : files)
    {
        futures.emplace_back(std::async(std::launch::async,
                                        [&]() -> FileStatistics
                                        {
                                            const FileAnalyzer analyzer{file};
                                            auto file_data{analyzer.analyze_file()};
                                            return file_data;
                                        }));
    }

    for (auto &future : futures)
    {
        all_files_stats.emplace_back(future.get());
    }

    return all_files_stats;
}
