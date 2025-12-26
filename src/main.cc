#include <string>
#include <vector>

#include "application.h"

auto parseArgs(const int argc, const char **argv) -> std::vector<std::string>
{
    std::vector<std::string> args;
    args.reserve(argc - 1);

    for (int i = 1; i < argc; ++i)
    {
        args.emplace_back(argv[i]);  // NOLINT
    }

    return args;
}

auto main(const int argc, const char *argv[]) -> int
{
    const Application app(parseArgs(argc, argv));
    return app.run();
}
