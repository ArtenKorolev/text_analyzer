#include "text_file_reader.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

TextFileReader::TextFileReader(std::filesystem::path file_path) : _file_path{std::move(file_path)}
{
}

auto TextFileReader::read() const -> std::string
{
    std::ifstream file_stream{_file_path};

    if (!file_stream.is_open())
    {
        throw std::runtime_error("Unable to open file: " + _file_path.string());
    }

    std::stringstream str_stream{};
    str_stream << file_stream.rdbuf();

    return str_stream.str();
}
