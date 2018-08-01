
#pragma once

#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/core.hpp>
#include <boost/log/utility/setup.hpp>
#include <boost/log/expressions.hpp>


class CLogManager {
	typedef boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level> LOGGER_MT_TYPE;
	typedef boost::log::sources::severity_logger<boost::log::trivial::severity_level> LOGGER_TYPE;

	private:
		const std::string filename_;
		LOGGER_MT_TYPE logger_mt_;
		LOGGER_TYPE logger_;

		void init_logging();
	public:
		CLogManager(const std::string &filename) noexcept;
		CLogManager(const char *filename) noexcept;

		inline LOGGER_TYPE get_logger() const noexcept {return logger_;} 
		inline LOGGER_MT_TYPE get_logger_mt() const noexcept {return logger_mt_;}
};
