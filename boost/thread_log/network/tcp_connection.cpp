#include "tcp_connection.h"
#include "common.h"

CTcpConnection::CTcpConnection():
	socket_(common_io_context) {
}

boost::asio::ip::tcp::socket& CTcpConnection::get_socket() {
	return socket_;
}
