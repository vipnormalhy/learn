#include <boost/bind.hpp>
#include "udp_server.h"
#include "common.h"

CUdpServer::CUdpServer(const boost::asio::ip::address &addr, unsigned short port):
	CServerBase(addr, port),
	endpoint_(addr, port),
	socket_(common_io_context){
	}

bool CUdpServer::start_listen() {
	bool ret = CServerBase::start_listen();
	if (!ret) {
		return ret;
	}

	boost::system::error_code err;
	socket_.bind(endpoint_, err);

	if (err) {
		BOOST_LOG_SEV(g_logger, LOG_ERROR) << "bind udp server failed. " << err.message();
		return false;
	}

	return true;
}

void CUdpServer::run() {
	if (start_listen()) {
		return;
	}
	start_receive();
}

void CUdpServer::start_receive() {
	socket_.async_receive_from(boost::asio::buffer(receive_buffer_), remote_endpoint_,
			boost::bind(&CUdpServer::handle_receive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void CUdpServer::handle_receive(const boost::system::error_code &err, std::size_t bytes_transferred) {
	if (!err) {
		std::cout << "receive data from " << remote_endpoint_ << " size " << bytes_transferred << std::endl;;
	} else {
		std::cout << "receive from error" << err.message() << std::endl;
	}

	start_receive();
}
