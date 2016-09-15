#include <ctime>
#include <iostream>
#include <string>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

typedef boost::asio::ip::tcp TCP;

class TcpConnection : public boost::enable_shared_from_this<TcpConnection> {
public:
    typedef boost::shared_ptr<TcpConnection> pointer;
    static pointer create(boost::asio::io_service &io) {
        return pointer(new TcpConnection(io));
    }
    inline TCP::socket &get_socket() {return m_socket_;}
private:
    TcpConnection(boost::asio::io_service &io) : m_socket_(io) {}
    TCP::socket m_socket_;
};
    

class TcpServer {
public:
    TcpServer(TCP::endpoint &endpoint, boost::asio::io_service &io);
    boost::asio::io_service &get_io_service() {return m_acceptor_.get_io_service();}
    bool StartAccept();
    bool AcceptHandler(TcpConnection::pointer connection, const boost::system::error_code &error);
private:
    std::vector<boost::shared_ptr<TcpConnection> > m_all_connections_;
    TCP::acceptor m_acceptor_;
};

TcpServer::TcpServer(TCP::endpoint &endpoint, boost::asio::io_service &io) :
    m_acceptor_(io, endpoint) {
}

bool TcpServer::StartAccept() {
    TcpConnection::pointer connection = TcpConnection::create(get_io_service());
    m_acceptor_.async_accept(connection->get_socket(), boost::bind(&TcpServer::AcceptHandler, this, connection, boost::asio::placeholders::error));
    return true;
}

bool TcpServer::AcceptHandler(TcpConnection::pointer connection, const boost::system::error_code &error) {
    if (!error) {
        std::string message("test");
        boost::system::error_code e;
        boost::asio::write(connection->get_socket(), boost::asio::buffer(message), e);
        return true;
    }
    else {
        return false;
    }
}

int main() {
    boost::asio::io_service io;
    TCP::endpoint host_point(TCP::v4(), 50000);
    TcpServer server(host_point, io);
    server.StartAccept();

    while(true) {
        try {
            io.run();
            break;
        }
        catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
