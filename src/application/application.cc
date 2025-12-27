#include "application.h"

#include <filesystem>

#include "cli.h"
#include "config.h"
#include "directory_analyzer.h"
#include "directory_analyzer_one_thread.h"
#include "file_analyzer.h"
#include "timer.h"

Application::Application(std::vector<std::string> args) : _args{std::move(args)}
{
}

auto Application::run() const -> int
{
    try
    {
        _try_to_run();
        return 0;
    }
    catch (const std::exception &e)
    {
        Cli::printError(e);
        return 1;
    }
}

void Application::_try_to_run() const
{
    if (_args.empty())
    {
        throw std::runtime_error{"Entity for analyzing was not provided"};
    }

    const fs_path analyzing_target{_args.at(0)};

    if (!std::filesystem::exists(analyzing_target))
    {
        throw std::runtime_error{"Entity does not exist: " + analyzing_target.string()};
    }

    if (std::filesystem::is_directory(analyzing_target))
    {
        _run_directory_analyzing(analyzing_target);
    }
    else if (std::filesystem::is_regular_file(analyzing_target))
    {
        _run_file_analyzing(analyzing_target);
    }
    else
    {
        throw std::runtime_error{"Unsupported entity type"};
    }
}

void Application::_run_directory_analyzing(const fs_path &analyzing_target)
{
    if constexpr (config::DEBUG)
    {
        _run_debug_benchmarking(analyzing_target);
    }
    else
    {
        const DirectoryAnalyzer directory_analyzer{analyzing_target};
        const auto analyzing_result{directory_analyzer.analyze_dir()};
        Cli::printAnalyzingResultsForDirectory(analyzing_result, analyzing_target);
    }
}

void Application::_run_debug_benchmarking(const fs_path &analyzing_target)
{
    Cli::printMessage(
        "You see this output because the program was built in debug mode.\n"
        "It is intended to show the difference between the \n"
        "single-threaded and multithreaded versions.\n");

    const DirectoryAnalyzer directory_analyzer{analyzing_target};
    const DirectoryAnalyzerOneThread directory_analyzer_one_thread{analyzing_target};
    Timer timer;

    {
        timer.start();
        const auto result = directory_analyzer.analyze_dir();
        timer.stop();

        Cli::printMessage("Multithread version: " + timer.formatted_elapsed_time());
    }

    {
        timer.start();
        const auto result = directory_analyzer_one_thread.analyze_dir();
        timer.stop();

        Cli::printMessage("One thread version: " + timer.formatted_elapsed_time());
    }
}

void Application::_run_file_analyzing(const fs_path &analyzing_target)
{
    if constexpr (config::DEBUG)
    {
        Cli::printMessage(
            "You will not see debug output here because a single file is processed\n"
            "in one thread, and there is no difference between the single-threaded\n"
            "and multithreaded versions.\n");
    }

    const FileAnalyzer file_analyzer{analyzing_target};
    const auto analyzing_result{file_analyzer.analyze_file()};
    Cli::printAnalyzingResultsForFile(analyzing_result);
}
