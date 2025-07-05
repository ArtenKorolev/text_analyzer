#ifndef _TIMER_H_
#define _TIMER_H_

#include <chrono>

class Timer
{
   public:
    Timer();
    ~Timer() = default;

    void start();
    void stop();
    [[nodiscard]] auto elapsed_seconds() const -> double;
    [[nodiscard]] auto elapsed_milliseconds() const -> double;
    [[nodiscard]] auto elapsed_microseconds() const -> double;
    [[nodiscard]] auto formatted_elapsed_time() const -> std::string;

    Timer(const Timer&) = delete;
    auto operator=(const Timer&) -> Timer& = delete;
    Timer(Timer&&) = delete;
    auto operator=(Timer&&) -> Timer& = delete;

   private:
    using Clock = std::chrono::high_resolution_clock;
    std::chrono::time_point<Clock> _start_time;
    std::chrono::time_point<Clock> _end_time;
    bool _running = false;
};

#endif  // _TIMER_H_