#include <iostream>
#include <string>
#include "plugin_base.hpp"
#include "test_data.h"

void output(std::string &str) {
	std::cout << str << std::endl;
}

void output2(int value) {
	std::cout << "number is " << value << std::endl;
}

#ifdef __cplusplus
extern "C" {
#endif
	int plugin_main(PluginContext &context) {
		assert(context.data);
		TestData *pdata = (TestData *)(context.data);
		output2(pdata->num);
		output(pdata->test_str);
		return 0;
	}
#ifdef __cplusplus
}
#endif
