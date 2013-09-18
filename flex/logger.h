#ifndef LOGGER_H
#define LOOGER_H

#include <iostream>
#include <mutex>

enum LogLevel{
	VERBOSE = 1,
	DEBUG = 2,
	INFO = 3,
	SILENT = 4
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
private:
	static LogLevel level;
	static Logger * instance;
	Logger();
	static Logger * getInstance();
	std::mutex m_mutex;
};
#endif