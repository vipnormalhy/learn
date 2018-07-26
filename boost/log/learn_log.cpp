#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup.hpp>

void init_logging() {
	namespace logging = boost::log;
	namespace keywords = boost::log::keywords;
	logging::add_common_attributes();

	logging::add_file_log(
		keywords::file_name = "sample_%N.log",
		keywords::rotation_size = 10 * 1024 * 1024,
		keywords::format = "[%TimeStamp%]: %Message%");
	logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::info);
}

int main(int, char *[]) {
	init_logging();

	namespace boost_trivial = boost::log::trivial;
	namespace boost_src = boost::log::sources;

	boost_src::severity_logger<boost_trivial::severity_level> lg;

	BOOST_LOG_SEV(lg, boost::log::trivial::trace) << "This is trace message";
	BOOST_LOG_SEV(lg, boost_trivial::debug) << "This is debug message";
	BOOST_LOG_SEV(lg, boost_trivial::info) << "This is info message";
	BOOST_LOG_SEV(lg, boost_trivial::warning) << "This is warning message";
	BOOST_LOG_SEV(lg, boost_trivial::error) << "This is error message";
	BOOST_LOG_SEV(lg, boost_trivial::fatal) << "This is fatal message";
	return 0;
}
