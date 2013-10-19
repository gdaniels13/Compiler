#include "OutputFile.h"
#include <iostream>

std::shared_ptr<Output> Output::m_instance;

// extern "C" int yyerror(const char*);

Output::Output()
{
	// m_out.open(".asm");
	setUpFile();
	for(int i = 0; i<18; ++i)
		registers[i] = false;
}


std::string Output::addString(std::string str)
{
	std::string label="str"+std::to_string(getInstance()->strings.size());
	getInstance()->strings.insert(std::make_pair(label,str));
	return label;
}


int Output::getRegister()
{
	bool * array =  getInstance()->registers;
	for(int i = 0; i<18;++i)
	{
		// if(!getInstance()->registers[i])
		// {
		// 	getInstance()->registers[i] = true;
		// 	return 7+i;
		// }
		if(!array[i])
		{
			array[i] = true;
			return 8+i;
		}
	}
	std::cout<<"out of registers";
	exit(-1);
}

void Output::freeRegister(int t)
{
	comment("freeing Register " + std::to_string(t));
	bool * array =  getInstance()->registers;
	array[(t-8)] = false;
}

void Output::setUpFile()
{
	m_out<<"#header of the file needs to happen here\n";
}

void Output::endFile()
{
	comment("Printing all the Strings");
	out("\t.data");

	for(auto t : getInstance()->strings)
	{
		out("\t"+t.first  + ":\t" + ".asciiz\t"+ t.second);
	}
	out("\n\n\n");
	comment( "printing end of program");

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

void Output::comment(std::string message )
{
   	getInstance()->m_out <<'#'<< message << std::endl;
}