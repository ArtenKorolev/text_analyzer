#include <iostream>

#include "config.h"
#include "directory_analyzer.h"

auto main(int argc, char *argv[]) -> int
{
    std::string dir_path = argc >= 2 ? argv[1] : config::DEFAULT_ANALYZE_PATH;

    DirectoryAnalyzer dir_an{dir_path};
    auto dir_data{dir_an.analyze_dir_one_thread()};

    for (const auto &file_data : dir_data)
    {
        std::cout << file_data.file_path << ": ";
        std::cout << file_data.text_data.get_format_info() << '\n';
    }
}
