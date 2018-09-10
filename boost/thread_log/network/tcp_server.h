#pragma once

#include "server.h"

class CTcpServer: public CServerBase {
	private:
		boost::asio::ip::tcp::endpoint endpoint_;
		boost::asio::ip::tcp::acceptor acceptor_;
	public:
		CTcpServer(const boost::asio::ip::address &addr, unsigned short port);
		virtual bool start_listen();
		virtual void run();
};
