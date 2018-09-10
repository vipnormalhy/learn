#include "tcp_client.h"
#include "common.h"

CTcpClient::CTcpClient(std::string &ip_str, int port):
	ip_addr_(ip_str),
	port_(port),
  socket_(common_io_context) {
}

bool CTcpClient::check_port() {
	if (port_ < 65535 && port_ > 1024) {
		return true;
	} else {
		return false;
	}
}

void CTcpClient::connect() {
	if (ip_addr_.empty()) {
		BOOST_LOG_SEV(g_logger, LOG_ERROR) << "client no connect ip address!";
		return;
	}

	if (!check_port()) {
		BOOST_LOG_SEV(g_logger, LOG_ERROR) << "client no connect port!";
		return;
	}

	BOOST_LOG_SEV(g_logger, LOG_INFO) << "Connect to ip " << ip_addr_ << " port" << port_;

	boost::asio::ip::tcp::resolver resolver(common_io_context);;
	boost::asio::ip::tcp::resolver::query query_endpoints(ip_addr_, std::to_string(port_));
	boost::asio::ip::tcp::resolver::iterator resolver_iter = resolver.resolve(query_endpoints);
	boost::asio::ip::tcp::resolver::iterator iter_end;

	bool succeed = false;
	for (;resolver_iter != iter_end; resolver_iter++) {
		boost::system::error_code err;

		boost::asio::connect(socket_, resolver_iter, err);

		if (!err) {
			succeed = true;
			BOOST_LOG_SEV(g_logger, LOG_INFO) << "Client connect to " << resolver_iter->endpoint() << " Succeed!";
			break;
		} else {
			BOOST_LOG_SEV(g_logger, LOG_INFO) << "Client connect to " << resolver_iter->endpoint() << " Failed!";
		}
	}

	if (!succeed) {
		BOOST_LOG_SEV(g_logger, LOG_ERROR) << "Client connect to " << ip_addr_ << "FAILED!";
	}
}
