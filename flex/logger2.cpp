#include "logger.h"

Logger::Logger(LogLevel t):
m_mutex()
{
	level = t;
}

std::shared_ptr<Logger> Logger::getInstance()
{
	if(!m_instance)
	{
		std::shared_ptr<Logger> logger(new Logger(ERROR));
		m_instance = logger;
		
	}
	return m_instance;
	
}

void Logger::LogMessage(std::string newString)
{
	getInstance()->m_mutex.lock();
    std::cout << newString << std::endl;
    getInstance()->m_mutex.unlock();
}

void Logger::LogMessage(int lineNumber, std::string newString )
{
	getInstance()->m_mutex.lock();
    std::cout <<"Line "<<lineNumber<<" : "<< newString << std::endl;
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

void Logger::LogMessage(std::string newString, std::string token, int lineNumber)
{
	getInstance()->m_mutex.lock();
    std::cout<<"Line "<<lineNumber<<" : " << newString << " " << token << std::endl;
    getInstance()->m_mutex.unlock();
}

void Logger::LogMessage(std::string newString, int token,int lineNumber)
{
	getInstance()->m_mutex.lock();
    std::cout<<"Line "<<lineNumber<<" : " << newString << " " << token << std::endl;
    getInstance()->m_mutex.unlock();
}
/*my changes*/

void Logger::SetLevel(LogLevel t)
{
	getInstance()->m_mutex.lock();
	getInstance()->setTheLevel(t);
    getInstance()->m_mutex.unlock();
}

void Logger::setTheLevel(LogLevel t)
{
	level = t;
}

void Logger::logError(std::string newString, int lineNumber)
{
	getInstance()->m_mutex.lock();
	if(Logger::getLevel() >= ERROR)
	{
   		std::cout<<"ERROR Line "<<lineNumber<<": " << newString << std::endl;
	}
    getInstance()->m_mutex.unlock();
}

void Logger::logDebug(std::string newString, int lineNumber)
{
	getInstance()->m_mutex.lock();
	if(Logger::getLevel() >= DEBUG)
	{
   		std::cout<<"DEBUG Line "<<lineNumber<<": " << newString << std::endl;
	}
    getInstance()->m_mutex.unlock();
}

void Logger::logMessage(std::string newString, int lineNumber)
{
	getInstance()->m_mutex.lock();
	if(Logger::getLevel() >= VERBOSE)
	{
   		std::cout<<"INFO Line "<<lineNumber<<": " << newString << std::endl;
	}
    getInstance()->m_mutex.unlock();
}



