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
    static void LogMesslineNumberage(std::string newString);
    static void LogMessage(std::string newString, std::string token);
    static void LogMessage(std::string newString, int token);
	static void SetLevel(LogLevel);
	static void logError(std::string newString, int lineNumber);
	static void logDebug(std::string newString, int lineNumber);
	static void logMessage(std::string newString, int lineNumber);
private:
	static LogLevel getLevel();
	Logger();
	static std::shared_ptr<Logger> getInstance();
	static std::shared_ptr<Logger> m_instance;
	std::mutex m_mutex;
	static LogLevel m_level;
};
#endif