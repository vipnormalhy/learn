#include <boost/asio.hpp>
#include <iostream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>


void test_func() {
    std::cout << "enter 1test" << boost::chrono::time_point_cast<boost::chrono::milliseconds>(boost::chrono::steady_clock::now()) << std::endl;
}

void test_func2() {
    std::cout << "enter test" << boost::chrono::time_point_cast<boost::chrono::milliseconds>(boost::chrono::steady_clock::now()) << std::endl;
}

void test_delay_func(boost::asio::strand &strand) {
    strand.post(boost::bind(test_func));
}

int main() {
    boost::asio::io_service io;
    boost::asio::strand strand(io);
    boost::asio::io_service io2;

    boost::asio::deadline_timer t2(io2, boost::posix_time::milliseconds(2000));
    // t2.async_wait(strand.wrap(boost::bind(test_func)));
    t2.async_wait(boost::bind(test_delay_func, strand));

    std::cout << "async time" << boost::chrono::time_point_cast<boost::chrono::milliseconds>(boost::chrono::steady_clock::now()) << std::endl;

    boost::asio::deadline_timer t1(io, boost::posix_time::milliseconds(5000));
    t1.async_wait(boost::bind(test_func2));

    boost::thread t(boost::bind(&boost::asio::io_service::run, &io2));

    io.run();
    t.join();
    return 0;
}
