#include "cli.h"

#include <iostream>

#include "directory_analyzer.h"
#include "timer.h"

void Cli::printAnalyzingResultsForDirectory(const std::vector<FileStatistics>& stats,
                                            const std::string& directory_to_analyze)
{
    std::cout << "Analyzing directory: " << directory_to_analyze << '\n';

    for (const auto& file_stat : stats)
    {
        printAnalyzingResultsForFile(file_stat);
    }
}

void Cli::printAnalyzingResultsForFile(const FileStatistics& stats)
{
    std::cout << stats.get_in_printable_format() << '\n';
}

void Cli::printError(const std::exception& exception)
{
    std::cerr << "Error occurred: " << exception.what() << '\n';
}

void Cli::printMessage(const std::string& message)
{
    std::cout << message << '\n';
}
