#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include "consts.hpp"
#include "common.h"

namespace po = boost::program_options;

void usage() {
	std::string filename("ReadMe");
	boost::filesystem::path filepath(filename.c_str());
	if (!boost::filesystem::exists(filepath)) {
		BOOST_LOG_SEV(g_logger, boost::log::trivial::warning) << "Cannot find help files!";
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

int main(int argc, const char *const *argv) {
	// Parse command options
	po::options_description options_desc("Allowed Options");
	options_desc.add_options()
		("listen_ip", po::value<std::string>()->default_value(""), "if starts like a server,need a listen ip and port")
		("listen_port", po::value<unsigned short>()->default_value(0), "if starts like a server,need a listen port and ip")
		("help", "produce help message");

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, options_desc), vm);
	po::notify(vm);

	if (argc <= 1 || vm.count("help")) {
		usage();
		return OK;
	}

	if (vm.count("listen_ip")) {
		// if (check_ip(vm["listen_ip"].as<std::string>())) {
		// }
	}

	return OK;
}
