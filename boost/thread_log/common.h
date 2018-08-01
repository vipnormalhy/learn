#pragma once
#ifndef LEARN_THREADS_LOG_COMMON_H
#define LEARN_THREADS_LOG_COMMON_H

#include <boost/log/trivial.hpp>

// global logger
boost::log::sources::severity_logger_mt<boost::log::trivial::severity_level> g_logger_mt;
boost::log::sources::severity_logger<boost::log::trivial::severity_level> g_logger;

#endif
