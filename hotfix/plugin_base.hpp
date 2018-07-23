#pragma once

#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H
#include <iostream>
#include <string>
#include <assert.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <csignal>
#include <thread>
#include <chrono>
#include <sys/stat.h>
#include <stdio.h>
#include <elf.h>

struct PluginContext;
typedef int (*plugin_main_func)(PluginContext &context);
void parse_plugin(const std::string &filepath);

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
	parse_plugin(pathname);
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
	std::this_thread::sleep_for(std::chrono::seconds(10));
}

void init_signal_handler() {
	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO | SA_RESETHAND;
	sigemptyset(&sa.sa_mask);
#if defined(__gnu_linux__)
	sa.sa_restorer = NULL;
#endif
	sa.sa_sigaction = signal_handler;

	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGILL, &sa, NULL);
}

size_t file_size(const std::string &filepath) {
	struct stat stats;

	if (!stat(filepath.c_str(), &stats)) {
		return stats.st_size;
	} else {
		return 0;
	}
}

void parse_plugin(const std::string &filepath) {
	FILE *fp = fopen(filepath.c_str(), "rb");
	size_t filesize = file_size(filepath);

	void *p = malloc(filesize);
	size_t readsize = fread(p, 1, filesize, fp);
	fclose(fp);
	fp = NULL;

	if (readsize != filesize) {
		std::cout << "Read file failed.Filesize not fit" << readsize << " " << filesize << std::endl;
		return;
	}

}

#endif
