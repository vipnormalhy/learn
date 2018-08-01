#include <boost/shared_ptr.hpp>
#include <boost/log/sinks.hpp>
#include <string>
#include "log_manager.hpp"

namespace logging = boost::log;
namespace keywords = boost::log::keywords;
namespace expression = boost::log::expressions;
namespace attr = boost::log::attributes;
namespace sinks = boost::log::sinks;

CLogManager::CLogManager(const std::string &filename) noexcept:
	filename_(filename) {
	init_logging();
}

CLogManager::CLogManager(const char *filename) noexcept:
	filename_(filename) {
	init_logging();
}

void CLogManager::init_logging() {
	logging::add_common_attributes();	

	// add filetag value
	std::string filetag(filename_);
	if (filename_.size() <= 0) {
		filetag.append("default");
	}
	logger_.add_attribute("FileTag", attr::constant<std::string>(filename_));

	// add multifile sinks
	boost::shared_ptr<sinks::text_multifile_backend> backend =
		boost::make_shared<sinks::text_multifile_backend>();

	// multifile composer
	backend->set_file_name_composer(
			sinks::file::as_file_name_composer(
				expression::stream << "logs/" << expression::attr<std::string>("FileTag") << ".log"));

	typedef sinks::synchronous_sink<sinks::text_multifile_backend> SINK_TYPE;
	boost::shared_ptr<SINK_TYPE> sink = boost::make_shared<SINK_TYPE>(backend);

	logging::core::get()->add_sink(sink);
}
