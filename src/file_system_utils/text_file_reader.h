#ifndef _TEXT_FILE_READER_H_
#define _TEXT_FILE_READER_H_

#include <filesystem>
#include <string>

class TextFileReader
{
   public:
    explicit TextFileReader(std::filesystem::path file_path);
    [[nodiscard]] auto read() const -> std::string;

   private:
    std::filesystem::path _file_path;
};

#endif  // _TEXT_FILE_READER_H_
