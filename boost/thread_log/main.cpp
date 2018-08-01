#include <iostream>
#include <fstream>
#include <string>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include "consts.hpp"

namespace po = boost::program_options;

void usage() {
	std::string filename("ReadMe");
	boost::filesystem::path filepath(filename.c_str());
	if (!boost::filesystem::exists(filepath)) {
	}
}

int main(int argc, const char *const *argv) {
	
	// Parse command options
	po::options_description options_desc("Allowed Options");
	options_desc.add_options()
		("help", "produce help message");

	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, options_desc), vm);
	po::notify(vm);

	if (vm.count("help")) {
		usage();
		return OK;
	}

	return OK;
}
