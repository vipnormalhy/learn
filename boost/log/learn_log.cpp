#include <boost/shared_ptr.hpp>
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup.hpp>
#include <boost/log/sinks.hpp>
#include <fstream>
// #include <boost/log/attributes.hpp>

void add_log_sink() {
	namespace sinks = boost::log::sinks;
	namespace logging = boost::log;
	// construct sink
	typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();

	sink->locked_backend()->add_stream(boost::make_shared<std::ofstream>("sample.log"));
	logging::core::get()->add_sink(sink);
}

void add_detail_sink() {
	namespace sinks = boost::log::sinks;
	namespace logging = boost::log;

	// construct sink
	typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
	boost::shared_ptr<sinks::text_ostream_backend> backend = boost::make_shared<sinks::text_ostream_backend>();
	backend->add_stream(boost::make_shared<std::ofstream>("sample2.log"));

	boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>(backend);
	boost::shared_ptr<logging::core> core(logging::core::get());
	core->add_sink(sink);
}

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
	add_log_sink();
	add_detail_sink();

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
