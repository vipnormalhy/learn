#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/chrono.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <ctime>

void delay_call(boost::chrono::steady_clock::time_point &start_time) {
    boost::chrono::steady_clock::time_point end_time(boost::chrono::steady_clock::now());

    boost::chrono::nanoseconds duration(end_time - start_time);
    std::cout << "duration " << boost::chrono::duration_cast<boost::chrono::microseconds>(duration) << std::endl;
}

int main() {
    boost::asio::io_service io_service;

    boost::chrono::steady_clock::time_point now(boost::chrono::steady_clock::now());
    boost::asio::deadline_timer t(io_service, boost::posix_time::microseconds(1000));
    t.async_wait(boost::bind(&delay_call, now));
    io_service.run();
    return 0;
}
