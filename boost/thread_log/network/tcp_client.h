#pragma once

#include <string>
#include <boost/asio.hpp>
#include "tcp_connection.h"

class CTcpClient {
	private:
		std::string ip_addr_;
		int port_;
		boost::asio::ip::tcp::socket socket_;

		bool check_port();
	public:
		boost::asio::ip::tcp::socket& get_socket() {return socket_;}
		void connect();

		CTcpClient(std::string &ip_str, int port);
};
