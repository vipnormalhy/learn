#pragma once

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>

class CTcpConnection: public boost::enable_shared_from_this<CTcpConnection> {
	public:
		typedef boost::shared_ptr<CTcpConnection> connection_ptr;

	public:
		static connection_ptr create() {
			return boost::make_shared<CTcpConnection>();
		}
		CTcpConnection();
		boost::asio::ip::tcp::socket& get_socket();
	private:
		boost::asio::ip::tcp::socket socket_;
};
