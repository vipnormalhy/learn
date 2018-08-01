#pragma once

#ifndef LEARN_THREADS_LOG_CONFIGUARE_H
#define LEARN_THREADS_LOG_CONFIGUARE_H

#include <string>

class CConfigure {
	private:
		std::string listen_ip_;
		unsigned short listen_port_;

	public:
		inline std::string &get_listen_ip() {return listen_ip_;}
		inline unsigned short get_listen_port() {return listen_port_;}

		inline void set_listen_ip(const std::string ip) {
			listen_ip_ = ip;
		}
		inline void set_listen_port(const unsigned short port) {
			listen_port_ = port;
		}
};

#endif
