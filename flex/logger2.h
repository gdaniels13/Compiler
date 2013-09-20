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
    static void LogMessage(int lineNumber, std::string newString);
    static void LogMessage(std::string newString, std::string token);
    static void LogMessage(std::string newString, int token);
    static void LogMessage(std::string newString, std::string token, int lineNumber);
	static void LogMessage(std::string newString, int token,int lineNumber);
	static void SetLevel(LogLevel);
	static LogLevel getLevel();
	static void logError(std::string string, int lineNumber);
	static void logDebug(std::string string, int lineNumber);
	static void logMessage(std::string string, int lineNumber);
	void setTheLevel(LogLevel);
private:
	static LogLevel level;
	Logger(LogLevel);
	static std::shared_ptr<Logger> getInstance();
	static std::shared_ptr<Logger> m_instance;
	std::mutex m_mutex;

};
#endif