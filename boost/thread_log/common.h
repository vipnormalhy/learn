#pragma once
#ifndef LEARN_THREADS_LOG_COMMON_H
#define LEARN_THREADS_LOG_COMMON_H

#include <boost/asio.hpp>
#include "configure.h"
#include "log_manager/log_manager.hpp"

// global logger
extern CLogManager::LOGGER_TYPE g_logger;
extern CLogManager::LOGGER_MT_TYPE g_logger_mt;

// global configuration
extern CConfiguration g_config();

// logger level
#define LOG_TRACE boost::log::trivial::trace
#define LOG_DEBUG boost::log::trivial::debug
#define LOG_INFO boost::log::trivial::info
#define LOG_WARNING boost::log::trivial::warning
#define LOG_ERROR boost::log::trivial::error
#define LOG_FATAL boost::log::trivial::fatal
extern boost::asio::io_context io_context;


#endif
