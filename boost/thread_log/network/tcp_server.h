#pragma once

#include "server.h"
#include "tcp_connection.h"

class CTcpServer: public CServerBase {
	private:
		boost::asio::ip::tcp::endpoint endpoint_;
		boost::asio::ip::tcp::acceptor acceptor_;
	public:
		CTcpServer(const boost::asio::ip::address &addr, unsigned short port);
		virtual ~CTcpServer();
		virtual bool start_listen();
		virtual void run();

	private:
		void start_accept();

		void handle_accept(CTcpConnection::connection_ptr new_connection, const boost::system::error_code &err);
};
