#include "log_manager.hpp"

namespace logging = boost::log;
namespace keywords = boost::log::keywords;
namespace expression = boost::log::expressions;

CLogManager::CLogManager(const std::string &filename) noexcept:
	filename_(filename) {
		init_logging();
}

void CLogManager::init_logging() {
}

void CLogManager::debug(boost::shared_ptr<char> message) {
}
