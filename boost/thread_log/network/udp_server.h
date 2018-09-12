#pragma once

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "server.h"

class CUdpServer: public CServerBase {
	private:
		boost::asio::ip::udp::endpoint endpoint_;
		boost::asio::ip::udp::socket socket_;
		boost::array<char, 1> receive_buffer_;
		boost::asio::ip::udp::endpoint remote_endpoint_;
	public:
		CUdpServer(const boost::asio::ip::address &addr, unsigned short port);
		virtual bool start_listen();
		virtual void run();

	private:
		void start_receive();

		void handle_receive(const boost::system::error_code &err, std::size_t bytes_transferred);
};
