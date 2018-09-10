#include "common.h"

// global logger
CLogManager g_logger_manager("common");
CLogManager::LOGGER_TYPE g_logger = g_logger_manager.get_logger();
CLogManager::LOGGER_MT_TYPE g_logger_mt = g_logger_manager.get_logger_mt();

// global configuration
CConfiguration g_config();

boost::asio::io_context io_context;
