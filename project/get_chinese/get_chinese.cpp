#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

void handle_file(std::string filename, std::string &filename_postfix, std::string &method_call) {
    std::string::size_type pos = filename.rfind(filename_postfix);
    if (pos == std::string::npos) {
        return;
    }

    std::string::size_type filename_len = filename.size();
    std::string::size_type postfix_len = filename_postfix.size();

    if (pos != filename_len - postfix_len) {
        return;
    }

    std::cout << "find file" << filename << std::endl;
    return;
}

void handle_directory(boost::filesystem::path dirpath, std::string &filename_postfix, std::string &method_call) {
    for (auto path_entry : boost::filesystem::recursive_directory_iterator(dirpath)) {
        if (boost::filesystem::is_regular_file(path_entry.path())) {
            handle_file(path_entry.path().c_str(), filename_postfix, method_call);
        }
    }
}


int main(int argc, char *argv[]) {
    std::string usage_str("Get Chinese from code files");
    std::string filename_postfix(".py");  // default filename postfix is .py
    std::string method_call;
    std::string dirpath;

    po::options_description options_desc(usage_str.c_str());

    options_desc.add_options()
        ("help,h", "show help info")
        ("dirpath,d", po::value<std::string>(), "scan root path")
        ("postfix,p", po::value<std::string>(), "filename postfix")
        ("method,m", po::value<std::string>(), "find method's call string");
    

    if (argc < 2) {
        std::cout << "Params error, Usage:" << std::endl;
        std::cout << options_desc << std::endl;
        return -1;
    }

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, options_desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << options_desc << std::endl;
        return -1;
    }

    // scan directory path
    if (!vm.count("dirpath")) {
        std::cout << "There must be a dirpath to scan" << std::endl;
        std::cout << options_desc << std::endl;
        return -1;
    }

    dirpath = vm["dirpath"].as<std::string>();
    if (!boost::filesystem::exists(dirpath)) {
        std::cout << "dirname " << dirpath << " not exists!!!" << std::endl;
        return -2;
    }

    // find file postfix
    if (vm.count("postfix")) {
        filename_postfix = vm["postfix"].as<std::string>();
    }

    if (vm.count("method")) {
        method_call = vm["method"].as<std::string>();
    }

    // handle directory or regular file
    if (BOOST_UNLIKELY(boost::filesystem::is_regular_file(dirpath))) {
        handle_file(dirpath, filename_postfix, method_call);
    } else if (BOOST_LIKELY(boost::filesystem::is_directory(dirpath))) {
        handle_directory(dirpath, filename_postfix, method_call);        
    } else {
        std::cout << "Cannot find " << dirpath << std::endl;
        return -1;
    }
    return 0;
}
