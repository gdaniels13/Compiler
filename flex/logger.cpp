#include "logger.h"

std::shared_ptr<Logger> Logger::m_instance;
LogLevel Logger::m_level;


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
		m_level = ERROR;
	}
	return m_instance;
	
}

void Logger::SetLevel(LogLevel t)
{
	getInstance()->m_level = t;
}


void Logger::logError(std::string newString, int lineNumber)
{
	getInstance()->m_mutex.lock();
	if(getInstance()->getLevel() >= ERROR)
	{
   		std::cout<<"ERROR Line "<<lineNumber<<": " << newString << std::endl;
	}
    getInstance()->m_mutex.unlock();
}

void Logger::logDebug(std::string newString, int lineNumber)
{
	getInstance()->m_mutex.lock();
	if(getInstance()->getLevel() >= DEBUG)
	{
   		std::cout<<"DEBUG Line "<<lineNumber<<": " << newString << std::endl;
	}
    getInstance()->m_mutex.unlock();
}

void Logger::logMessage(std::string newString, int lineNumber)
{
	getInstance()->m_mutex.lock();
	if(getInstance()->getLevel() >= VERBOSE)
	{
   		std::cout<<"INFO Line "<<lineNumber<<": " << newString << std::endl;
	}
    getInstance()->m_mutex.unlock();
}

LogLevel Logger::getLevel()
{
	return m_level;
}


