#include "server.h"

namespace asio = boost::asio;

CServerBase::CServerBase(const asio::ip::address &addr, unsigned short port) :
	bind_address_(addr),
	bind_port_(port) {
	}

bool CServerBase::start_listen() {
	if (check_address()) {
		return false;
	}

	if (!check_port()) {
		return false;
	}

	return true;
}

bool CServerBase::check_port() {
	if (bind_port_ < 1024 || bind_port_ > 65535) {
		return false;
	} else {
		return true;
	}
}

bool CServerBase::check_address() {
	if (bind_address_.is_unspecified()) {
		return false;
	} else {
		return true;
	}
}

void CServerBase::run() {
}

CTcpServer::CTcpServer(const boost::asio::ip::address &addr, unsigned short port):
	CServerBase(addr, port) {
	}

bool CTcpServer::start_listen() {
	return true;
}

void CTcpServer::run() {
}

CUdpServer::CUdpServer(const boost::asio::ip::address &addr, unsigned short port):
	CServerBase(addr, port) {
	}

bool CUdpServer::start_listen() {
	return true;
}

void CUdpServer::run() {
}
