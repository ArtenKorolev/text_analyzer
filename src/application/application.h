#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <string>
#include <vector>

class Application
{
   public:
    explicit Application(std::vector<std::string> args);

    [[nodiscard]] auto run() const -> int;

   private:
    void _try_to_run() const;

    std::vector<std::string> _args;
};

#endif  // _APPLICATION_H_
