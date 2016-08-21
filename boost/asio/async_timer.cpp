#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void print(const boost::system::error_code &e) {
    std::cout << "Hello world!" << std::endl;
}

int main() {
    boost::asio::io_service io;

    std::cout << "Create a deadline timer wait for 5 seconds" << std::endl << std::ends;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

    t.async_wait(&print);
    std::cout << "Start to wait" << std::endl << std::ends;

    io.run();

    return 1;
}


