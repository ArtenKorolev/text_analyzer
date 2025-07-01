#ifndef _DIRECTORY_SCANNER_H_
#define _DIRECTORY_SCANNER_H_

#include <filesystem>
#include <string>
#include <vector>

class DirectoryScanner
{
   public:
    explicit DirectoryScanner(std::filesystem::path dir_path);
    [[nodiscard]] auto get_files() const -> std::vector<std::string>;

   private:
    void _validate_path() const;

    std::filesystem::path _dir_path;
};

#endif  // _DIRECTORY_SCANNER_H_
