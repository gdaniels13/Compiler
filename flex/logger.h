#ifndef LOGGER_H
#define LOOGER_H

#include <iostream>
#include <memory>
#include <mutex>

enum LogLevel{
	VERBOSE = 4,
	DEBUG = 3,
	ERROR = 2,
	SILENT = 1
};

class Logger
{
public:
    static void LogMessage(std::string newString);
    static void LogMessage(std::string newString, std::string token);
    static void LogMessage(std::string newString, int token);
    static void SetLevel(LogLevel);

private:
	Logger();
	static std::shared_ptr<Logger> getInstance();
	static std::shared_ptr<Logger> m_instance;
	std::mutex m_mutex;
	static LogLevel level;
};
#endif