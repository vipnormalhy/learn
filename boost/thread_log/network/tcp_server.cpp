#include <boost/bind.hpp>
#include "common.h"
#include "tcp_server.h"

CTcpServer::CTcpServer(const boost::asio::ip::address &addr, unsigned short port):
	CServerBase(addr, port),
	endpoint_(addr, port),
	acceptor_(common_io_context, endpoint_) {
	}

bool CTcpServer::start_listen() {
	bool ret = CServerBase::start_listen();
	if (!ret) {
		return ret;
	}
	return true;
}

void CTcpServer::run() {
	start_listen();
	start_accept();
}

void CTcpServer::start_accept() {
	CTcpConnection::connection_ptr new_connection = CTcpConnection::create();

	acceptor_.async_accept(new_connection->get_socket(),
			boost::bind(&CTcpServer::handle_accept, this, new_connection, boost::asio::placeholders::error));
}

void CTcpServer::handle_accept(CTcpConnection::connection_ptr new_connection, boost::system::error_code &err) {
	if (!err) {
		BOOST_LOG_SEV(g_logger, LOG_INFO) << "new connection!";
		start_accept();
	}
}
