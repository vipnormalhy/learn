#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H

struct PluginContext {
	void *plugin;
	void *data;
	int version;
};
#endif
