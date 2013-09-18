#ifndef LOGGER_H
#define LOOGER_H

#include <iostream>
#include <mutex>

class Logger
{
public:
    static void LogMessage(std::string newString);
    static void LogMessage(int lineNumber, std::string newString);
    static void LogMessage(std::string newString, std::string token);
    static void LogMessage(std::string newString, int token);
    static void LogMessage(std::string newString, std::string token, int lineNumber);
	static void LogMessage(std::string newString, int token,int lineNumber);
private:
	Logger();
	static Logger * getInstance();
	std::mutex m_mutex;
};
#endif