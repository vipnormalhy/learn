#include <boost/dll/import.hpp>
#include <boost/filesystem.hpp>
#include <boost/shared_ptr.hpp>
#include "test_api.hpp"


int main() {
    boost::filesystem::path dllpath("test.dylib");
    if (dllpath.is_relative()) {
        dllpath = boost::filesystem::system_complete(dllpath);
    }

    if (!boost::filesystem::exists(dllpath)) {
        return -1;
    }

    boost::shared_ptr<my_test_api> plugin;
    std::cout << "start load dll" << std::endl;
    plugin = boost::dll::import<my_test_api>(dllpath, "plugin_out");
    std::cout << "load dll finished" << std::endl;
    if (plugin) {
        plugin->calculate(3, 5);
    } else {
        std::cout << "test......" << std::endl;
    }

    return 0;
}
