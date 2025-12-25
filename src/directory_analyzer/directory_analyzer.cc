#include "directory_analyzer.h"

#include <mutex>
#include <thread>
#include <vector>

#include "directory_scanner.h"
#include "file_analyzer.h"

DirectoryAnalyzer::DirectoryAnalyzer(std::filesystem::path dir_path)
    : _dir_path{std::move(dir_path)}
{
}

// TODO: replace with thread pool pattern
auto DirectoryAnalyzer::analyze_dir() const -> std::vector<FileStatistics>
{
    DirectoryScanner scanner{_dir_path};
    auto files{scanner.get_files()};

    std::vector<FileStatistics> all_files_stats;
    all_files_stats.reserve(files.size());
    std::vector<std::thread> threads;
    threads.reserve(files.size());

    std::mutex mtx;

    for (const auto &file : files)
    {
        threads.emplace_back(
            [&]() -> void
            {
                const FileAnalyzer analyzer{file};
                auto file_data{analyzer.analyze_file()};

                std::lock_guard<std::mutex> guard{mtx};
                all_files_stats.emplace_back(file_data);
            });
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    return all_files_stats;
}
