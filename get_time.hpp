#include <sys/time.h>
#include <iostream>

double get_current_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    int sec = tv.tv_sec;
    int usec = tv.tv_usec;

    double current_time = sec + static_cast<double>(usec) / 1000000.0;
    return current_time;
}

void output_interval(double start_time, double end_time) {
    std::cout << "run time is " << std::setprecision(6) << end_time - start_time << std::endl;
}
