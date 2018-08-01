
#pragma once

#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/utility/setup.hpp>
#include <boost/log/expressions.hpp>

class CLogManager {
	private:
		std::string filename_;
		void init_logging();
	public:
		CLogManager(const std::string &filename) noexcept;
		CLogManager(const char *filename) noexcept;
		void debug(const char *message);
		void debug(const char *format, const char *msg);
};
