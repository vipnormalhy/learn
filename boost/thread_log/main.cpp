#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <boost/asio.hpp>
#include "consts.hpp"
#include "common.h"

namespace po = boost::program_options;

void usage() {
	std::string filename("ReadMe");
	boost::filesystem::path filepath(filename.c_str());
	if (!boost::filesystem::exists(filepath)) {
		BOOST_LOG_SEV(g_logger, LOG_WARNING) << "Cannot find help files!";
		return;
	}

	std::ifstream ifs(filename, std::ios::in);
	std::string line;
	while (std::getline(ifs, line)) {
		std::cout << line << std::endl;
	}
	ifs.close();
	return;
}

bool check_ip(const std::string ip) {
	if (ip.size() <= 0) {
		return false;
	}

	boost::system::error_code ec;
	boost::asio::ip::address ip_addr(boost::asio::ip::make_address(ip, ec));
	if (ec) {
		BOOST_LOG_SEV(g_logger, LOG_ERROR) << "listen ip error! " << ec.message();
		return false;
	} else {
		BOOST_LOG_SEV(g_logger, LOG_INFO) << "Try to bind ip " << ip_addr.to_string();
	}
	return true;
}

int check_port(int listen_port) {
	if (listen_port < 65535 && listen_port > 1024) {
		BOOST_LOG_SEV(g_logger, LOG_INFO) << "Try to bind port" << listen_port;
		return true;
	} else {
		BOOST_LOG_SEV(g_logger, LOG_ERROR) << "Try to bind bad port " << listen_port;
		return false;
	}
}

int main(int argc, const char *const *argv) {
	// Parse command options
	po::options_description options_desc("Allowed Options");
	options_desc.add_options()
		("help", "produce help message")
		("listen_ip", po::value<std::string>(), "if starts like a server,need a listen ip and port")
		("listen_port", po::value<int>(), "if starts like a server,need a listen port and ip");

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, options_desc), vm);
	po::notify(vm);

	if (argc <= 1 || vm.count("help")) {
		usage();
		std::cout << options_desc << std::endl;
		return OK;
	}

	if (vm.count("listen_ip")) {
		if (!check_ip(vm["listen_ip"].as<std::string>())) {
			std::cout << "IP ERROR" << std::endl;
			return -1;
		}
	}

	if (vm.count("listen_port")) {
		if (!check_port(vm["listen_port"].as<int>())) {
			std::cout << "PORT ERROR" << std::endl;
			return -1;
		}
	}

	return OK;
}
