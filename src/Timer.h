//
// Created by Lars on 08/06/2019.
//

#ifndef LENSESIM_TIME_H
#define LENSESIM_TIME_H

#include <chrono>

class Timer {
public:

    using clock_type = std::chrono::steady_clock;
    using time_point = clock_type::time_point;
    using duration = clock_type::duration;

    Timer() = default;

    void start() {
        starttime = clock_type::now();
    }

    void stop() {
        dt = clock_type::now() - starttime;
    }

    // delta time as a fraction of a second
    double delta_time() {
        return std::chrono::duration<double, std::chrono::seconds::period>(dt).count();
    }

    // since constructing the timer
    double time_elapsed() {
        return std::chrono::duration<double, std::chrono::seconds::period>(clock_type::now() - constructtime).count();
    }

private:
    time_point constructtime = std::chrono::steady_clock::now();
    time_point starttime = std::chrono::steady_clock::now();
    duration dt = duration(0);

};

#endif //LENSESIM_TIME_H
