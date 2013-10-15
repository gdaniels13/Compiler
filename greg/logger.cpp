#include "logger.h"

std::shared_ptr<Logger> Logger::m_instance;

Logger::Logger():
m_level(ERROR),
m_out(),
m_mutex(),
m_toFile(false)
{
}

std::shared_ptr<Logger> Logger::getInstance()
{
	if(!m_instance)
	{
		std::shared_ptr<Logger> logger(new Logger());
		m_instance = logger;
	}
	return m_instance;
	
}
void Logger::LogMessage(std::string message, int lineNum)
{
	getInstance()->m_mutex.lock();
	if(getInstance()->m_level >= VERBOSE)
	{
	    std::cout << "INFO Line: " << lineNum << " : " << message << std::endl;
	    if(getInstance()->m_toFile)
	    	getInstance()->m_out << "INFO Line: " << lineNum << " : " << message << std::endl;
	}
    getInstance()->m_mutex.unlock();
}


void Logger::SetFilePath(std::string path)
{
	getInstance()->m_out.open(path);
	if(!getInstance()->m_out)
		getInstance()->m_out.open("out.txt");
	getInstance()->m_toFile = true;
}

void Logger::SetLevel(LogLevel level)
{
	getInstance()->m_level = level;
}

void Logger::LogError(std::string message, int lineNum)
{
	getInstance()->m_mutex.lock();
	if(getInstance()->m_level >= ERROR)
	{
	    std::cout << "ERROR Line: " << lineNum << " : " << message << std::endl;
	    if(getInstance()->m_toFile)
	    	getInstance()->m_out << "ERROR Line: " << lineNum << " : " << message << std::endl;
	}
    getInstance()->m_mutex.unlock();
}

void Logger::LogDebug(std::string message, int lineNum)
{
	getInstance()->m_mutex.lock();
	if(getInstance()->m_level >= DEBUG)
	{
	    std::cout << "DEBUG Line: " << lineNum << " : " << message << std::endl;
	    if(getInstance()->m_toFile)
	    	getInstance()->m_out << "DEBUG Line: " << lineNum << " : " << message << std::endl;
	}
    getInstance()->m_mutex.unlock();
}

