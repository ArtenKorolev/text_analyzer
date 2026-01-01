#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string_view>

namespace config
{

constexpr auto DEBUG =

#ifdef BUILD_DEBUG
    true;
#elif defined(BUILD_RELEASE)
    false;
#endif

constexpr std::string_view DEFAULT_PATH_FOR_ANALYZING = ".";

}  // namespace config

#endif  // _CONFIG_H_
