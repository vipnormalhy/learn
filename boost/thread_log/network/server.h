#pragma once

#include <boost/asio.hpp>

class CServerBase {
	private:
		boost::asio::ip::address bind_address_;
		unsigned short bind_port_;

		bool check_port();
		bool check_address();
	public:
		CServerBase(const boost::asio::ip::address &addr, unsigned short port);
		virtual bool start_listen();
		virtual void run();
		virtual ~CServerBase();
};
