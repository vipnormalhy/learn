#pragma once
#ifndef LEARN_THREADS_LOG_COMMON_H
#define LEARN_THREADS_LOG_COMMON_H

#include "configure.h"
#include "log_manager/log_manager.hpp"

// global logger
CLogManager g_logger_manager("common");
CLogManager::LOGGER_TYPE g_logger = g_logger_manager.get_logger();
CLogManager::LOGGER_MT_TYPE g_logger_mt = g_logger_manager.get_logger_mt();

// global configuration
CConfiguration g_config();


#endif
