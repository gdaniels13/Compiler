#include "logger.h"

Logger::Logger():
m_mutex()
{
}

Logger * Logger::getInstance()
{
	static Logger instance;
	return &instance;
}

void Logger::LogMessage(std::string newString)
{
	Logger * instance = getInstance();
	instance->m_mutex.lock();
    std::cout << newString << std::endl;
    instance->m_mutex.unlock();
}

void Logger::LogMessage(int lineNumber, std::string newString )
{
	Logger * instance = getInstance();
	instance->m_mutex.lock();
    std::cout <<"Line "<<lineNumber<<" : "<< newString << std::endl;
    instance->m_mutex.unlock();
}

void Logger::LogMessage(std::string newString, std::string token)
{
	Logger * instance = getInstance();
	instance->m_mutex.lock();
    std::cout << newString << " " << token << std::endl;
    instance->m_mutex.unlock();
}

void Logger::LogMessage(std::string newString, int token)
{
	Logger * instance = getInstance();
	instance->m_mutex.lock();
    std::cout << newString << " " << token << std::endl;
    instance->m_mutex.unlock();
}

void Logger::LogMessage(std::string newString, std::string token, int lineNumber)
{
	Logger * instance = getInstance();
	instance->m_mutex.lock();
    std::cout<<"Line "<<lineNumber<<" : " << newString << " " << token << std::endl;
    instance->m_mutex.unlock();
}

void Logger::LogMessage(std::string newString, int token,int lineNumber)
{
	Logger * instance = getInstance();
	instance->m_mutex.lock();
    std::cout<<"Line "<<lineNumber<<" : " << newString << " " << token << std::endl;
    instance->m_mutex.unlock();
}