#include <exception>
#include <iostream>
#include <string>

#include "cli.h"
#include "config.h"

auto main(int argc, char *argv[]) -> int
{
    try
    {
        std::string directory_to_analyze =
            argc > 1 ? argv[1] : config::DEFAULT_ANALYZE_PATH;  // NOLINT
        Cli::outputDirectoryAnalyzed(directory_to_analyze);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
