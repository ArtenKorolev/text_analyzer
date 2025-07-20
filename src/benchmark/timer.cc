#include "timer.h"

#include <iomanip>
#include <sstream>

Timer::Timer() = default;

void Timer::start()
{
    _start_time = Clock::now();
    _running = true;
}

void Timer::stop()
{
    _end_time = Clock::now();
    _running = false;
}

auto Timer::elapsed_seconds() const -> double
{
    auto end_time = _running ? Clock::now() : _end_time;
    return std::chrono::duration<double>(end_time - _start_time).count();
}

auto Timer::elapsed_milliseconds() const -> double
{
    auto end_time = _running ? Clock::now() : _end_time;
    return std::chrono::duration<double, std::milli>(end_time - _start_time).count();
}

auto Timer::elapsed_microseconds() const -> double
{
    auto end_time = _running ? Clock::now() : _end_time;
    return std::chrono::duration<double, std::micro>(end_time - _start_time).count();
}

auto Timer::formatted_elapsed_time() const -> std::string
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3);

    double seconds = elapsed_seconds();
    if (seconds >= 1.0)
    {
        oss << seconds << " s";
    }
    else
    {
        double milliseconds = elapsed_milliseconds();
        if (milliseconds >= 1.0)
        {
            oss << milliseconds << " ms";
        }
        else
        {
            double microseconds = elapsed_microseconds();
            oss << microseconds << " us";
        }
    }

    return oss.str();
}