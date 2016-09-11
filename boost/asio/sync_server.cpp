#include <iostream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>

std::string get_date_string() {
    std::time_t now = std::time(0);
    return std::ctime(&now);
}

int main() {
    boost::asio::io_service io;
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 52562);
    boost::asio::ip::tcp::acceptor acceptor(io, endpoint);

    while(true) {
        boost::asio::ip::tcp::socket socket(io);
        acceptor.accept(socket);

        std::cout << "Accept a client" << std::endl;
        std::string message = get_date_string();
        boost::system::error_code e;
        boost::asio::write(socket, boost::asio::buffer(message), e);
    }
    return 0;
}
