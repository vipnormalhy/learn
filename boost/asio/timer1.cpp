#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main() {
    boost::asio::io_service io;

    std::cout << "Create a deadline timer wait for 5 seconds" << std::endl << std::ends;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

    std::cout << "Start to wait" << std::endl << std::ends;
    t.wait();
    std::cout << "Wait finished" << std::endl << std::ends;

    std::cout << "Hello world" << std::endl;
    return 1;
}
