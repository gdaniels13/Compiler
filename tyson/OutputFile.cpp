#include "OutputFile.h"
#include <iostream>

std::shared_ptr<Output> Output::m_instance;


Output::Output():
m_out()
{
	for(int i = 0; i < 18; ++i)
		m_registers[i] = false;
}

void Output::setUpFile()
{
	m_out << "\t.text  \t\t\t#predefined header" << std::endl << 
             "\t.globl main \t#predefined header" << std::endl << 
             "main: la $gp, GA \t#predefined header" << std::endl <<
             "\tb _begin" << std::endl << std::endl;
}

void Output::writeBegin()
{
	getInstance()->m_out << "_begin:" << std::endl;
}

void Output::writeEnd()
{
	getInstance()->m_out << std::endl;
}

void Output::endFile()
{
	out("\tli $v0, 10");
	out("\tsyscall \t\t#exit");
	out("\t.data");
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

int Output::getRegister()
{
	int reg = 0;
	for(int i = 0; i < 18; ++i)
	{
		if(getInstance()->m_registers[i] == false)
		{
			reg = i+8;
			getInstance()->m_registers[i] = true;
			break;
		}
	}
	if(reg == 0)
	{
		std::cout << "HOLY FLIP! YOU SUCK AT REGISTER ALLOCATION" << std::endl;
		exit(-1);
	}
	return reg;
}

void Output::freeRegister(int reg)
{
	getInstance()->m_registers[reg - 8] = false;
}



void Output::SetFilePath(std::string path)
{
	getInstance()->m_out.open(path);
	getInstance()->setUpFile();
}

void Output::out(std::string message )
{
   	getInstance()->m_out << message << std::endl;
}