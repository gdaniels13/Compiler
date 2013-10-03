#ifndef LOGGER_H
#define LOOGER_H

#include <iostream>
#include <memory>
#include <mutex>
#include <fstream>

enum LogLevel
{
	VERBOSE = 4,
	DEBUG 	= 3,
	ERROR 	= 2,
	SILENT	= 1
};

class Logger
{
public:
	static void SetFilePath(std::string path);
	static void SetLevel(LogLevel level);
    static void LogMessage(std::string message, int lineNum);
    static void LogError(std::string message, int lineNum);
    static void LogDebug(std::string message, int lineNum);

private:
	Logger();
	static std::shared_ptr<Logger> getInstance();
	LogLevel getLogLevel();
	static std::shared_ptr<Logger> m_instance;
	LogLevel m_level;
	std::mutex m_mutex;
	std::ofstream m_out;
	bool m_toFile;
};
#endif