#include "OutputFile.h"
#include <iostream>

std::shared_ptr<Output> Output::m_instance;

extern "C" int yyerror(const char*);

Output::Output()
{
	// m_out.open(".asm");
	ifCount = 0;
	EndIfStatement = 0;
	whileCount = 0;
	repeatCount = 0;
	forCount = 0;
	setUpFile();
	for(int i = 0; i<18; ++i)
		registers[i] = false;
}

std::string Output::getCurFunction()
{
	return getInstance()->currentFunction;
}

void Output::setCurFunction(std::string id)
{
	getInstance()->currentFunction = id;
}

std::string Output::addString(std::string str)
{
	std::string label="str"+std::to_string(getInstance()->strings.size());
	getInstance()->strings.insert(std::make_pair(label,str));
	return label;
}


int Output::getRegister()
{
	// comment("getting Register ");

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
		//	comment("getting Register " + std::to_string(8+i));
			return 8+i;
		}
	}
	yyerror("OUT OF REGISTERS");
}

void Output::freeRegister(int t)
{
	//comment("freeing Register " + std::to_string(t));
	bool * array =  getInstance()->registers;
	array[(t-8)] = false;
}

void Output::setUpFile()
{
	m_out<<"#header of the file needs to happen here\n";
	m_out<<("MOVE $fp,\t$sp")<<std::endl;
	// m_out<<("J _begin")<<std::endl;
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

	for(int i = 0; i<17; ++i)
		if(getInstance()->registers[i])
			comment(std::to_string(i));
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
   	getInstance()->m_out.flush();
}

void Output::comment(std::string message )
{
   	getInstance()->m_out <<'#'<< message << std::endl;
   	getInstance()->m_out.flush();
   	
}


int Output::pushIfQueue()
{
	auto instance = getInstance();
	int temp = instance->ifCount++;
	instance->ifQueue.push_front(temp);
	return temp;
}

int Output::popIfQueue()
{
	auto instance = getInstance();
	int temp = instance->ifQueue.front();

	instance->ifQueue.pop_front();
	return temp;	
}

int Output::pushEndIfQueue()
{
	auto instance = getInstance();
	int temp = instance->EndIfStatement++;
	instance->endIfQueue.push_front(temp);
	return temp;
}

int Output::getEndIfQueue()
{
	return getInstance()->endIfQueue.front();
}

int Output::popEndIfQueue()
{
	auto instance = getInstance();
	int temp = instance->endIfQueue.front();
	instance->endIfQueue.pop_front();
	return temp;	
}


int Output::pushWhile()
{
	auto instance = getInstance();
	int temp = instance->whileCount++;
	instance->whileQueue.push_front(temp);
	return temp;
}

int Output::getWhile()
{
	return getInstance()->whileQueue.front();
}

int Output::popWhile()
{
	auto instance = getInstance();
	int temp = instance->whileQueue.front();
	instance->whileQueue.pop_front();
	return temp;	
}


int Output::pushRepeat()
{
	auto instance = getInstance();
	int temp = instance->repeatCount++;
	instance->repeatQueue.push_front(temp);
	return temp;
}

int Output::getRepeat()
{
	return getInstance()->repeatQueue.front();
}

int Output::popRepeat()
{
	auto instance = getInstance();
	int temp = instance->repeatQueue.front();
	instance->repeatQueue.pop_front();
	return temp;	
}

int Output::pushFor()
{
	auto instance = getInstance();
	int temp = instance->forCount++;
	instance->forQueue.push_front(temp);
	return temp;
}

int Output::getFor()
{
	return getInstance()->forQueue.front();
}

int Output::popFor()
{
	auto instance = getInstance();
	int temp = instance->forQueue.front();
	instance->forQueue.pop_front();
	return temp;	
}
