#include "text_file_reader.h"

#include <fstream>
#include <iterator>
#include <stdexcept>

TextFileReader::TextFileReader(std::filesystem::path file_path) : _file_path{std::move(file_path)}
{
}

auto TextFileReader::read() const -> std::string
{
    std::ifstream file_stream{_file_path};

    if (!file_stream.is_open()) [[unlikely]]
    {
        throw std::runtime_error("Unable to open file: " + _file_path.string());
    }

    const auto file_contents =
        std::string{std::istreambuf_iterator<char>(file_stream), std::istreambuf_iterator<char>()};

    return file_contents;
}
