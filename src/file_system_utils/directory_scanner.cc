#include "directory_scanner.h"

#include <stdexcept>
#include <vector>

DirectoryScaner::DirectoryScaner(std::filesystem::path dir_path) : _dir_path{std::move(dir_path)}
{
}

auto DirectoryScaner::get_files() const -> std::vector<std::string>
{
    _validate_path();

    std::vector<std::string> dir_content;

    for (const auto& entry : std::filesystem::directory_iterator(_dir_path))
    {
        if (entry.is_regular_file())
        {
            dir_content.emplace_back(entry.path());
        }
    }

    return dir_content;
}

void DirectoryScaner::_validate_path() const
{
    if (!std::filesystem::exists(_dir_path) || !std::filesystem::is_directory(_dir_path))
    {
        throw std::runtime_error("Provided entity does not exist or is not a directory");
    }
}
