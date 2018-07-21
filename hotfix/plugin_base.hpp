#pragma once

#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H
#include <iostream>
#include <string>
#include <assert.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <csignal>

struct PluginContext;
typedef int (*plugin_main_func)(PluginContext &context);

struct PluginInternal {
	void *pso = nullptr;
	plugin_main_func entry = nullptr;
	std::string pathname;
};

struct PluginContext {
	PluginInternal *pinternal = nullptr;
	void *data = nullptr;
	int version;
};


bool set_plugin_info(PluginContext &context, const std::string &pathname) {
	assert(pathname.c_str());
	PluginInternal *internal = new PluginInternal;
	internal->pathname = pathname.c_str();
	context.pinternal = internal;
	context.version = 0;
	return true;
}

bool load_plugin(PluginContext &context) {
	assert(context.pinternal);
	dlerror();
	PluginInternal *p = context.pinternal;
	void *new_so = dlopen(p->pathname.c_str(), RTLD_NOW);
	p->pso = new_so;
	p->entry = (plugin_main_func)dlsym(new_so, "plugin_main");
	return true;
}

bool unload_plugin(PluginContext &context) {
	assert(context.pinternal);
	dlerror();
	PluginInternal *p = context.pinternal;
	assert(p->pso);
	dlclose(p->pso);
	p->pso = nullptr;
	p->entry = nullptr;
	return true;
}

int run_plugin(PluginContext &context) {
	assert(context.pinternal);

	auto p = context.pinternal;
	assert(p->entry);
	return p->entry(context);
}

void signal_handler(int sig_num, siginfo_t *info, void *context) {
	std::cout << "sig num is " << sig_num << std::endl;
	std::cout << "info sig num value is " << info->si_signo << "pid is " << info->si_pid << std::endl;
	std::cout << context << std::endl;
}

void init_signal_handler() {
	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_restorer = NULL;
	sa.sa_sigaction = signal_handler;

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGILL, &sa, NULL);
}

#endif
