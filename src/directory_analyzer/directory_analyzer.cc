#include "directory_analyzer.h"

#include <mutex>
#include <thread>
#include <vector>

#include "config.h"
#include "directory_scanner.h"
#include "file_analyzer.h"

DirectoryAnalyzer::DirectoryAnalyzer(std::filesystem::path dir_path)
    : _dir_path{std::move(dir_path)}
{
}

auto DirectoryAnalyzer::analyze_dir() const -> std::vector<FileData>
{
    DirectoryScaner scanner{_dir_path};
    auto files{scanner.get_files()};

    std::vector<FileData> all_files_data;
    all_files_data.reserve(files.size());
    std::vector<std::thread> threads;
    threads.reserve(files.size());

    std::mutex mtx;

    for (const auto &file : files)
    {
        threads.emplace_back(
            [&file, &all_files_data, &mtx]()
            {
                FileAnalyzer analyzer{file};
                auto file_data{analyzer.analyze()};

                std::lock_guard<std::mutex> guard{mtx};
                all_files_data.emplace_back(file_data);
            });
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    return all_files_data;
}

auto DirectoryAnalyzer::analyze_dir_one_thread() const -> std::vector<FileData>
{
    static_assert(config::DEBUG_MODE, "This method can be used only in debug mode");

    auto files{DirectoryScaner(_dir_path).get_files()};
    std::vector<FileData> all_files_data;
    all_files_data.reserve(files.size());

    for (const auto &file : files)
    {
        FileAnalyzer file_analyzer{file};
        all_files_data.emplace_back(file_analyzer.analyze());
    }

    return all_files_data;
}
