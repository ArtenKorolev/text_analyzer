#include <iostream>

#include "file_analyzer/file_analyzer.h"

auto main() -> int
{
    FileAnalyzer file_analyzer{"CMakeCache.txt"};
    auto data = file_analyzer.analyze();
    std::cout << data.get_format_info() << '\n';
}