#ifndef _CLI_H_
#define _CLI_H_

#include <string>

#include "file_analyzer.h"

struct Cli
{
    static void printAnalyzingResultsForDirectory(const std::vector<FileStatistics> &stats,
                                                  const std::string &directory_to_analyze);
    static void printAnalyzingResultsForFile(const FileStatistics &stats);
    static void printError(const std::exception &exception);
    static void printMessage(const std::string &message);
};

#endif  // _CLI_H_
