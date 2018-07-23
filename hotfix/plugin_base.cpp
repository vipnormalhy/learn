// Purpose: Create for c/c++ plugin hotfix test
#include <chrono>
#include <thread>
#include "plugin_base.hpp"
#include "test_data.h"

int main() {
#if defined(__gnu_linux__)
	std::string filepath("./libplugin_test_so.so");
#else
	std::string filepath("./libplugin_test_so.dylib");
#endif
	PluginContext context;
	TestData data;
	data.test_str = "Hello, world";
	data.num = 3;

	init_signal_handler();
	while(true) {
		context.data = (void *)&data;
		set_plugin_info(context, filepath);
		load_plugin(context);
		run_plugin(context);
		get_all_shared_objects();
		unload_plugin(context);

		std::this_thread::sleep_for(std::chrono::seconds(5));
	}
	return 0;
}
