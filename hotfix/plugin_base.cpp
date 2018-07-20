// Purpose: Create for c/c++ plugin hotfix test
#include "plugin_base.hpp"
#include "test_data.h"

int main() {
	std::string filepath("./libplugin_test_so.so");
	PluginContext context;
	TestData data;
	data.test_str = "Hello, world";
	context.data = (void *)&data;
	set_plugin_info(context, filepath);
	load_plugin(context);
	run_plugin(context);
	unload_plugin(context);
	return 0;
}
