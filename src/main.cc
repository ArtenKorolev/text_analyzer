#include <iostream>
#include <vector>

#include "config.h"
#include "directory_analyzer.h"
#include "file_analyzer.h"

auto main(int argc, char *argv[]) -> int
{
    std::string dir_path = argc >= 2 ? argv[1] : config::DEFAULT_ANALYZE_PATH;

    DirectoryAnalyzer dir_an{dir_path};

    std::vector<FileStatistics> dir_data;

    if constexpr (config::DEBUG_MODE)
    {
        dir_data = dir_an.analyze_dir_one_thread();
    }
    else
    {
        dir_data = dir_an.analyze_dir();
    }

    for (const auto &file_data : dir_data)
    {
        std::cout << file_data.get_in_printable_format() << '\n';
    }
}
