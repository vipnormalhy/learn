#include <boost/thread.hpp>
#include <boost/stacktrace.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

void init() {
	boost::log::add_file_log(
			boost::log::keywords::file_name = "sample%N.log",
			boost::log::keywords::rotation_size = 1024 * 10 * 10,
			boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
			boost::log::keywords::format = "[%TimeStamp%]: %Message%");
	boost::log::core::get()->set_filter(
			boost::log::trivial::severity > boost::log::trivial::info);
}

int main() {
	init();

	boost::stacktrace::stacktrace *st = new boost::stacktrace::stacktrace;
	BOOST_LOG_TRIVIAL(trace) << *st;
	BOOST_LOG_TRIVIAL(debug) << *st;
	BOOST_LOG_TRIVIAL(info) << *st;
	BOOST_LOG_TRIVIAL(warning) << *st;
	BOOST_LOG_TRIVIAL(error) << *st;
	BOOST_LOG_TRIVIAL(fatal) << *st;
	return 0;
}
