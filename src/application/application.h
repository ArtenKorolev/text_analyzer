#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <filesystem>
#include <string>
#include <vector>

using fs_path = std::filesystem::path;

class Application
{
   public:
    explicit Application(std::vector<std::string> args);

    [[nodiscard]] auto run() const -> int;

   private:
    void _try_to_run() const;

    static void _run_debug_benchmarking(const fs_path &analyzing_target);
    static void _run_directory_analyzing(const fs_path &analyzing_target);
    static void _run_file_analyzing(const fs_path &analyzing_target);

    std::vector<std::string> _args;
};

#endif  // _APPLICATION_H_
