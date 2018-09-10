#include "common.h"
#include "tcp_server.h"

CTcpServer::CTcpServer(const boost::asio::ip::address &addr, unsigned short port):
	CServerBase(addr, port),
	endpoint_(addr, port),
	acceptor_(io_context, endpoint_) {
	}

bool CTcpServer::start_listen() {
	return true;
}

void CTcpServer::run() {
}
