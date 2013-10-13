#include "SymbolTable.h"
#include <stdexcept>      // std::out_of_range
#include <map>
#include <memory>
#include <sstream>

extern "C" int numLines;
/*
Procedure and Function (name, signature, location)
Types (names, sizes, layout)
Variables (name, location)
Constants (name, location or value)
*/

std::string filterString(std::string input)
{
	std::string output = "";
	for(int i = 0; i<input.length(); ++i)
	{
		if(isalnum(input[i]))
		{
			output+=input[i];

		}
	}
	return output;
}



std::shared_ptr<SymbolTable> SymbolTable::instance ;

SymbolTable::SymbolTable()
{
	addPredefined();
	verbose = false;
	//put global and predefined tables on the vector;
};


std::shared_ptr<SymbolTable> SymbolTable::getInstance()
{
	
	
	if(!instance)
	{
		// instance = std::make_shared<SymbolTable>();
		std::shared_ptr<SymbolTable> inst(new SymbolTable());
		instance = inst;
	}
	
	return instance;
}


void SymbolTable::addPredefined()
{
	//add predefined types to the global 
	Table t(verbose, "GLOBAL");
	std::shared_ptr<Type> integer = std::make_shared<Type> ("integer",4);
	t.addSymbol(integer);
	integer->name = "INTEGER";
	t.addSymbol(integer);
	integer = std::make_shared<Type> ("char",4);
	t.addSymbol(integer);
	integer->name = "CHAR";
	t.addSymbol(integer);
	integer = std::make_shared<Type> ("BOOLEAN",4);
	t.addSymbol(integer);
	integer->name = "boolean";
	t.addSymbol(integer);
	integer = std::make_shared<Type> ("STRING",4);
	t.addSymbol(integer);
	integer->name = "string";
	t.addSymbol(integer);
	integer = std::make_shared<Type> ("TRUE",4);
	t.addSymbol(integer);
	integer->name = "true";
	t.addSymbol(integer);
	integer = std::make_shared<Type> ("FALSE",4);
	t.addSymbol(integer);
	integer->name = "false";
	t.addSymbol(integer);

	symbolTables.push_back(t);
	Table f(verbose, "MAIN");
	symbolTables.push_back(f);
}

bool SymbolTable::isVerbose()
{
	return getInstance()->verbose;
}

void SymbolTable::pushScope(std::string name)
{
	Table t(getInstance()->verbose, name);
	getInstance()->symbolTables.push_back(t);
}

void SymbolTable::popScope()
{
	if(isVerbose())
	{
		getInstance()->getCurScope()->print();
	}
	getInstance()->symbolTables.pop_back();
}


 void SymbolTable::print()
 {
	std::shared_ptr<SymbolTable> ins = SymbolTable::getInstance();
	for(int i = ins->symbolTables.size()-1;i>=0; --i)
	{
		ins->symbolTables.at(i).print();
	}
}



std::shared_ptr<Symbol> SymbolTable::lookupSymbol(std::string symbol)
{
	// std::cout<<"looking up: "<<"**"<<symbol<<"**"<<symbol.length()<<std::endl;
	std::shared_ptr<SymbolTable> table = getInstance();	
	// std::cout<<table->symbolTables.size();
	for(int i = table->symbolTables.size()-1; i>=0;--i )
	{
		// std::cout<<"table: "<<i<<std::endl;
		// table->symbolTables.at(i).print();
		try	{
			auto toReturn = table->symbolTables.at(i).lookup(symbol);
			return toReturn;
		}
		catch(const std::out_of_range& oor)
		{
			// std::cout<<symbol<<" not found in scope " << i<<std::endl;
		}
	}
	// std::stringstream temp ;
	std::cout<<"ERROR: UNKNOWN SYMBOL "<<"**"<<symbol<<"** on line "<<numLines<<std::endl;

	table->print();
	exit(-1);
}
bool SymbolTable::exists(std::string symbol)
{
	// std::cout<<"looking up: "<<"**"<<symbol<<"**"<<symbol.length()<<std::endl;
	std::shared_ptr<SymbolTable> table = getInstance();	
	// std::cout<<table->symbolTables.size();
	for(int i = table->symbolTables.size()-1; i>=0;--i )
	{
		// std::cout<<"table: "<<i<<std::endl;
		// table->symbolTables.at(i).print();
		try	{
			auto toReturn = table->symbolTables.at(i).lookup(symbol);
			return true;
		}
		catch(const std::out_of_range& oor)
		{
			// std::cout<<symbol<<" not found in scope " << i<<std::endl;
		}
	}
	return false;
}


void SymbolTable::addVarDecl(Symbol * type, std::vector<std::string>* ident_list)
{
	std::cout<<"i guess i need this"<<std::endl;
}

void SymbolTable::addVarDecl(std::string type, std::vector<std::string>* ident_list)
{
	Table* curScope = getInstance()->getCurScope();	

	std::shared_ptr<Type> t = std::dynamic_pointer_cast<Type> (lookupSymbol(type));
	int count = curScope->offset;
	std::for_each(ident_list->begin(), ident_list->end(), [&](std::string str)
	{

		curScope->addSymbol(std::make_shared<Variable>(t,count,str));
		count+=t->size;
	});
	curScope->offset = count;
}

Table* SymbolTable::getCurScope()
{
	return &(symbolTables[symbolTables.size()-1]);
}

char* SymbolTable::createRecord(std::vector<std::pair<std::vector<std::string>*,std::string>> record_thing)
{
	auto s_table = getInstance();
	auto curScope = s_table->getCurScope();

	auto curRecord = std::make_shared<Record>();
	int offset = 0;
	for(std::pair<std::vector<std::string>*,std::string> cur : record_thing)
	{
		curRecord->name +=cur.second[0] +makeRecordList(cur.first,&curRecord->records, cur.second);

	}

	curRecord->getSize();
	curScope->addSymbol(curRecord);

	std::string str= curRecord->name.c_str();
	char * writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';

	return writable;
}



Symbol* SymbolTable::getRawPointerType(std::string name)
{
	auto toReturn = lookupSymbol(name);
	return toReturn.get();
}


std::string SymbolTable::makeRecordList(std::vector<std::string>* ident_list, std::map<std::string,std::shared_ptr< Variable>>* recordList, std::string type )
 {
 	std::shared_ptr<Type> t = std::dynamic_pointer_cast<Type> (lookupSymbol(type));
 	
 	int count = ident_list->size();

 	std::string toReturn = "";
 	std::for_each(ident_list->begin(), ident_list->end(), [&](std::string str)
 	{
 		toReturn +=str;
 		recordList->insert(std::make_pair(str,std::make_shared<Variable>(t,count,str)));
 		count++;
 	});
 	return toReturn;
 }

void SymbolTable::setVerbose(bool v)
{
	getInstance()->verbose = v;
}

void SymbolTable::makeType(std::string name, std::string type)
{
	name = filterString(name);
	type = filterString(type);
	auto t = lookupSymbol(type);
	t->name = name;
	getInstance()->getCurScope()->erase(type);
	getInstance()->getCurScope()->addSymbol(t);
}

std::vector<std::shared_ptr<Variable>>* SymbolTable::makeVarList(std::vector<std::string>* ident_list, std::vector<std::shared_ptr< Variable>>* paramList, std::string type )
{
 	std::shared_ptr<Type> t = std::dynamic_pointer_cast<Type> (lookupSymbol(type));
 	
 	int count = getInstance()->getCurScope()->offset;

 	std::for_each(ident_list->begin(), ident_list->end(), [&](std::string str)
 	{
 		paramList->push_back(std::make_shared<Variable>(t,count,str));
 		count += t->size;
 	});
 	getInstance()->getCurScope()->offset = count;
 	return paramList;
}
 

char* SymbolTable::makeArray(Constant* lower,Constant* upper, std::string type)
{

	if(lower->type == ID)
	{
		auto temp = getInstance()->lookupSymbol(lower->s_value);
		lower = dynamic_cast<Constant*>(temp.get());
	}
	else if (upper->type == ID)
	{
		auto temp = getInstance()->lookupSymbol(upper->s_value);
		upper= dynamic_cast<Constant*> (temp.get());
	}

	type = filterString(type);
	if(lower->type != INT && upper->type != INT)
	{
		std::cout<<"ERROR INVALID CONSTANT FOR ARRAY INITIALIZATION\n";
		exit(-1);
	}
	
	std::stringstream blah;
	blah<<type<<lower->i_value<<upper->i_value;
	std::string toReturn;
		toReturn = filterString(blah.str());

	std::shared_ptr<Type> ty = std::dynamic_pointer_cast<Type> (lookupSymbol(type));
	// ty->print();

	auto array = std::make_shared<Array>(toReturn, lower->i_value,upper->i_value,ty);
	// array->print();
	// std::cout<<std::endl<<type<<std::endl;
	getInstance()->getCurScope()->addSymbol(array);
	
	


		char * writable = new char[toReturn.size() + 1];
		std::copy(toReturn.begin(), toReturn.end(), writable);
		writable[toReturn.size()] = '\0'; 
	return writable;
} 

void SymbolTable::addFunction(std::string functionName, std::vector<std::shared_ptr<Variable>> * formParams, std::string returnType, bool forward)
{
	auto inst = getInstance();
	auto function = std::make_shared<Function>();


	function->name = functionName;
	function->location = functionName+"_function";
	
	if(returnType != "NONE")
	{
		function->returnType = std::dynamic_pointer_cast<Type>(lookupSymbol(returnType));
	}

	function->signature = functionName + "( ";
	
	int count = 0;

	for(int i = 0 ;i <formParams->size(); ++i) //(std::shared_ptr<Variable> var: *formParams)
	{
		auto var = formParams->at(i);
		inst->getCurScope()->addSymbol(var);
		function->parameters.push_back(var);
		function->signature+=var->type->name+", ";
		var->location = count;
		count += var->size;
	}

	if(returnType != "NONE")
	{
		function->signature+=") " + function->returnType->name;
	}
	else
	{
		function->signature+=") " ;	
	}

	if(forward)
	{
		inst->symbolTables[1].addSymbol(function);
	}
	else
	{
		if(!exists(functionName))
		{
			inst->symbolTables[1].addSymbol(function);
		}
		
		inst->getCurScope()->name = functionName;
	}
}







Constant * SymbolTable::evaluateConstantExpression(Constant * a, Constant * b, std::string op)
{
	std::cout<<"st364\n";
	std::cout<<op<<std::endl;
	std::cout<<std::flush;
	if(a->type = ID)
	{
		auto temp = getInstance()->lookupSymbol(a->s_value);
		a = dynamic_cast<Constant*>(temp.get());
	}
	else if (b->type = ID)
	{
		auto temp = getInstance()->lookupSymbol(b->s_value);
		b = dynamic_cast<Constant*> (temp.get());
	}


	Constant * t;
	if(a->type == b->type)
	{
		if(a->type == BOOL)
		{
			if (op == "&")
			{
				t = new Constant(a->b_value && b->b_value);
			}
			else if (op == "=")
			{
				t = new Constant(a->b_value == b->b_value);	
			}
			else if (op == "<>")
			{
				t = new Constant(a->b_value != b->b_value);
			}
			else if (op =="|")
			{
				t = new Constant(a->b_value | b->b_value);
			}
		}
		if(a->type == INT)
		{
			if (op == "=")
			{
				t = new Constant(a->i_value == b->i_value);	
			}
			else if (op == "<>")
			{
				t = new Constant(a->i_value != b->i_value);
			}
			else if (op == "<=")
			{
				t = new Constant(a->i_value <= b->i_value);
			}
			else if (op == ">=")
			{
				t = new Constant(a->i_value >= b->i_value);
			}
			else if (op == "<")
			{
				t = new Constant(a->i_value < b->i_value);
			}
			else if (op == ">")
			{
				t = new Constant(a->i_value > b->i_value);
			}
			else if (op == "+")
			{
				t = new Constant(a->i_value + b->i_value);
			}
			else if (op == "-")
			{
				t = new Constant(a->i_value - b->i_value);
			}
			else if (op == "*")
			{
				t = new Constant(a->i_value * b->i_value);
			}
			else if (op == "/")
			{
				t = new Constant(a->i_value / b->i_value);
			}
			else if (op == "%")
			{
				t = new Constant(a->i_value % b->i_value);
			}
		}
		else
		{
			std::cout<<"ERROR MISMATCHED TYPES\n";
			exit(-1);
		}
	}
	else 
	{
		std::cout<<"ERROR MISMATCHED TYPES\n";
		exit(-1);
	}
}

void SymbolTable::addConstant(std::string  name ,Constant * c)
{	
	name = filterString(name);
	auto p = std::shared_ptr<Constant>(c);
	p->name = name;
	getInstance()->getCurScope()->addSymbol(p);
	std::cout<<"finished\n";
}
