namespace config
{

const auto DEBUG =

#ifdef BUILD_DEBUG
    true;
#elif defined(BUILD_RELEASE)
    false;
#endif

constexpr auto DEFAULT_ANALYZE_PATH = ".";

}  // namespace config