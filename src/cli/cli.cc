#include "cli.h"

#include <iostream>

#include "config.h"
#include "directory_analyzer.h"
#include "directory_analyzer_one_thread.h"
#include "timer.h"

void Cli::analyzeDirectoryAndOutput(std::string directory_to_analyze)
{
    DirectoryAnalyzer directory_analyzer{directory_to_analyze};

    if (config::DEBUG)
    {
        std::cout << "Analyzing directory: " << directory_to_analyze << '\n';

        DirectoryAnalyzerOneThread directory_analyzer_debug{std::move(directory_to_analyze)};

        Timer benchmark_timer;

        {
            benchmark_timer.start();
            auto directory_stats = directory_analyzer.analyze_dir();
            benchmark_timer.stop();
            std::cout << "Multithread version: " << benchmark_timer.formatted_elapsed_time()
                      << '\n';
        }

        {
            benchmark_timer.start();
            auto directory_stats = directory_analyzer_debug.analyze_dir();
            std::cout << "One thread version: " << benchmark_timer.formatted_elapsed_time() << '\n';
            benchmark_timer.stop();
        }
    }
    else
    {
        std::cout << " " << directory_to_analyze << '\n';
        for (const auto &file_stat : directory_analyzer.analyze_dir())
        {
            std::cout << "  " << file_stat.get_in_printable_format() << '\n';
        }
    }
}
