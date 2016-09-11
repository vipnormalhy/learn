#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

int main() {
    boost::asio::io_service io;

    boost::asio::ip::tcp::resolver resolver(io);
    // boost::asio::ip::tcp::resolver::query query("www.baidu.com", "http");
    boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), "13");
    boost::asio::ip::tcp::resolver::iterator endpoint_iter = resolver.resolve(query);
    boost::asio::ip::tcp::resolver::iterator end;
    boost::asio::ip::tcp::socket socket(io);

    while(endpoint_iter != end) {
        boost::asio::ip::tcp::endpoint endpoint = *endpoint_iter;
        std::cout << "Try to connect to " << endpoint << std::endl;
        boost::asio::connect(socket, endpoint_iter);
        std::cout << "Connected to " << endpoint << "!!!!" << std::endl;

        std::cout << "Read from " << endpoint << std::endl;

        while(true) {
            boost::array<char, 128> buf;
            boost::system::error_code e;

            std::cout << "Read Once" << std::endl;

            size_t len = socket.read_some(boost::asio::buffer(buf), e);
            if (e == boost::asio::error::eof) {
                std::cout << "Read Succeed!!!" << std::endl;
                break;
            }
            else {
                std::cout << "Fatal ERROR!!! " << e << std::endl;
                break;
            }

            std::cout.write(buf.data(), len);
        }
        endpoint_iter++;
    }

    return 0;
}
