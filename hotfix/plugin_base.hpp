#pragma once

#ifndef PLUGIN_BASE_H
#define PLUGIN_BASE_H
#include <iostream>
#include <string>
#include <assert.h>
#include <dlfcn.h>
#include <sys/types.h>
#include <csignal>
#include <link.h>
#include <thread>
#include <chrono>
#include <sys/stat.h>
#include <stdio.h>
#include <elf.h>
#include <stdlib.h>

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

int iterator_shared_objects(struct dl_phdr_info *info, size_t size, void *data) {
	std::cout << "shared object name is " << info->dlpi_name << std::endl;
	std::cout << "shared object size is " << size << std::endl;
	printf("shared object data location is %p\n", data);
	return 0;
}

size_t file_size(const std::string &filepath) {
	struct stat stats;

	if (!stat(filepath.c_str(), &stats)) {
		return stats.st_size;
	} else {
		return 0;
	}
}

void get_all_shared_objects() {
	void *data = NULL;
	dl_iterate_phdr(iterator_shared_objects, data);
}

void parse_elf_header(char *pdata) {
	assert(pdata);
	Elf64_Ehdr *p_ehdr = (Elf64_Ehdr *)pdata;
	if (p_ehdr->e_ident[EI_MAG0] != ELFMAG0 ||
			p_ehdr->e_ident[EI_MAG1] != ELFMAG1 || 
			p_ehdr->e_ident[EI_MAG2] != ELFMAG2 ||
			p_ehdr->e_ident[EI_MAG3] != ELFMAG3) {
		return;
	}

	// do not deal with 32bit library
	if (p_ehdr->e_ident[EI_CLASS] == ELFCLASS32) {
		return;
	}

	Elf64_Shdr *p_shdr = (Elf64_Shdr *)(pdata + p_ehdr->e_shoff);
	auto sh_strtab = &p_shdr[p_ehdr->e_shstrndx];
	const char *const sh_strtable_p = (char *)pdata + sh_strtab->sh_offset;

	for (int i = 0; i < p_ehdr->e_shnum; i++) {
		printf("section name is %s\n", (char *)(sh_strtable_p + p_shdr[i].sh_name));
	}
}

void parse_plugin(const std::string &filepath) {
	FILE *fp = fopen(filepath.c_str(), "rb");
	size_t filesize = file_size(filepath);

	char *p = (char *)malloc(filesize);
	size_t readsize = fread(p, 1, filesize, fp);
	fclose(fp);
	fp = NULL;

	if (readsize != filesize) {
		std::cout << "Read file failed.Filesize not fit" << readsize << " " << filesize << std::endl;
		return;
	}

	// parse elf header
	parse_elf_header(p);
	free(p);
}

#endif
