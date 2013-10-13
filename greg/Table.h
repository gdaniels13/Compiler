#ifndef TABLE_H
#define TABLE_H

#include <cstdlib>
#include <map>
#include <string>
#include "Symbols.h"
#include <memory>
#include <iostream>
extern "C" int numLines;
class Table {
	
private:
	std::map<std::string, std::shared_ptr<Symbol>> symbolMap;
	bool verbose;
public:
	std::string name;
	int offset;
	
	Table(bool v, std::string n)
	{
		offset = 0;
		name = n;
		verbose = v;
	}

	void addSymbol(std::shared_ptr<Symbol> sym)
	{
		auto s = std::make_pair(sym->name,sym);
		auto t = symbolMap.insert(s);
		
		if(!t.second)
		{
			std::cout<<"ERROR, LINE: "<<numLines<<" DUPLICATE INSERTION OF ";
			sym->print();
			print();
			exit(-1);
		}
	}

	void erase(std::string t)
	{
		symbolMap.erase(t);
	}
	
	std::shared_ptr<Symbol> lookup(std::string key)
	{
		return symbolMap.at(key);
	}

	void print()
	{
		std::cout<<"PrintingTable::"<<name<<std::endl;
		std::for_each(symbolMap.begin(),symbolMap.end(), [](std::pair<std::string,std::shared_ptr<Symbol>> cur)
		{
			// std::cout<<"Key: *" <<cur.first<<"*"<<cur.first.length();
			cur.second->print();
		});
	}

	// ~Table()
	// {
	// 	if(verbose)
	// 		print();
	// }
};
#endif
