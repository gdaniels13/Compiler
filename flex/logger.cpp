#include "logger.h"

std::shared_ptr<Logger> Logger::m_instance;

Logger::Logger():
m_mutex()
{
}

std::shared_ptr<Logger> Logger::getInstance()
{
	if(!m_instance)
	{
		std::shared_ptr<Logger> logger(new Logger());
		m_instance = logger;
		level = ERROR;
	}
	return m_instance;
	
}

void Logger::LogMessage(std::string newString)
{
	getInstance()->m_mutex.lock();
    std::cout << newString << std::endl;
    getInstance()->m_mutex.unlock();
}

void Logger::LogMessage(std::string newString, std::string token)
{
	getInstance()->m_mutex.lock();
    std::cout << newString << " " << token << std::endl;
    getInstance()->m_mutex.unlock();
}

void Logger::LogMessage(std::string newString, int token)
{
	getInstance()->m_mutex.lock();
    std::cout << newString << " " << token << std::endl;
    getInstance()->m_mutex.unlock();
}

void Logger::SetLevel(LogLevel t)
{
	getInstance()->level = t;
}