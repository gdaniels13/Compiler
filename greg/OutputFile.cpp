#include "OutputFile.h"

std::shared_ptr<Output> Output::m_instance;


Output::Output()
{
	m_out.open("out.asm");
	setUpFile();
}

void Output::setUpFile()
{
	m_out<<"#header of the file needs to happen here";
}

void Output::endFile()
{
	out("li\t $v0, 10\n syscall\n\n");
}

std::shared_ptr<Output> Output::getInstance()
{
	if(!m_instance)
	{
		std::shared_ptr<Output> logger(new Output());
		m_instance = logger;
	}
	return m_instance;
}



void Output::SetFilePath(std::string path)
{
	getInstance()->m_out.close();
	getInstance()->m_out.open(path);
	getInstance()->setUpFile();
}

void Output::out(std::string message )
{
   	getInstance()->m_out << message << std::endl;
}