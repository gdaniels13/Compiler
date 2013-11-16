#include "table.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "OutputFile.h"


//for output formatting
#define SIZE 20
#define SIZE2 10
#define SIZE3 10


int m_globalStackPointer = 0;
int m_localStackPointer = 0;

extern "C" void yyerror(const char *s);

std::shared_ptr<Table> Table::m_instance;

Table::Table():
m_mutex(),
m_table(),
m_scope(0)
{
	std::map<std::string, Element> newElement = std::map<std::string, Element>();;
	Element symbol(new SimpleType("integer", 4, "integer"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("INTEGER", 4, "INTEGER"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("CHAR", 4, "CHAR"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("char", 4, "char"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("boolean", 4, "boolean"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("BOOLEAN", 4, "BOOLEAN"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("string", 4, "string"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("STRING", 4, "STRING"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("true", 4, "true"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("TRUE", 4, "TRUE"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("false", 4, "false"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	symbol.reset(new SimpleType("FALSE", 4, "FALSE"));
	newElement.insert(std::make_pair(symbol->m_name, symbol));
	m_table.push_back(newElement);
	std::map<std::string, Element> newElement1 = std::map<std::string, Element>();;
	m_table.push_back(newElement1);
	m_scope++;
}

std::shared_ptr<Table> Table::getInstance()
{
	if(!m_instance)
	{
		std::shared_ptr<Table> table(new Table());
		m_instance = table;
	}
	return m_instance;
}


void Table::setVerbose(bool t)
{
	getInstance()->verbose = t;
}


std::string Table::getPointer(std::string id)
{
	int scope = whichScope(id);
	if(scope ==1)
		return "($gp)";
	else
		return "($fp)";
}

bool Table::isVerbose()
{
	return getInstance()->verbose;
}

Element Table::GetElement(std::string id)
{
	std::map<std::string, Element>::iterator it;

	for(auto i = getInstance()->m_scope; i >= 0; --i)
	{
		std::map<std::string, Element> scope = getInstance()->m_table[i];
		it = scope.find(id);
		if(it != scope.end())
		{
			return it->second;
			break;
		}
	}
	//std::cout<<id<<"NOT FOUND\n";
	//exit(-1);
	std::shared_ptr<Symbol> x(new Symbol("EMPTY"));
	return x;
}

int Table::whichScope(std::string id)
{
	std::map<std::string, Element>::iterator it;

	for(auto i = getInstance()->m_scope; i >= 0; --i)
	{
		std::map<std::string, Element> scope = getInstance()->m_table[i];
		it = scope.find(id);
		if(it != scope.end())
		{
			return i;
		}
	}
	yyerror("ERRORS HAVE OCCURED");
}

void Table::InsertElement(std::string id, Element symbol)
{
	if(getInstance()->m_table[getInstance()->m_scope].find(id) == getInstance()->m_table[getInstance()->m_scope].end())
		getInstance()->m_table[getInstance()->m_scope].insert(std::make_pair(id, symbol));
	else
	{
		std::map<std::string, Element>::iterator it = getInstance()->m_table[getInstance()->m_scope].find(id);
		if(dynamic_cast<Function *>(it->second.get())->m_forward == false)
		{
			std::cout << "ERROR INSERT ELEMENT ";
			symbol->print();
			std::cout << std::endl;
			exit(-1);
		}
		else
		{

		}
	}
}

void Table::PrintTable()
{
	if(!getInstance()->verbose)
		return;
	std::cout << "PRINT TABLE RESULTS" << std::endl;
	int count = 0;
	int innerCount = 0;
	std::for_each(getInstance()->m_table.begin(), getInstance()->m_table.end(), [&](std::map<std::string, Element> scope)
	{
		innerCount = 0;
		std::for_each(scope.begin(), scope.end(), [&](std::pair<std::string, Element> symbol)
		{
			std::cout << "---------------------" << std::endl;
			std::cout << "SCOPE: " << count << "  ELEMENT: " << innerCount++ << "|" << std::endl;
			std::cout << "------------------------------------------------------------" << std::endl;
			symbol.second->print();
			std::cout << std::endl << std::endl;
		});
		count++;
	});
}

void Table::PrintScope()
{
	std::cout << "PRINT SCOPE RESULTS" << std::endl;
	int count = 0;
	std::for_each(getInstance()->m_table[getInstance()->m_scope].begin(), getInstance()->m_table[getInstance()->m_scope].end(), [&](std::pair<std::string, Element> symbol)
	{
		std::cout << "-----------" << std::endl;
		std::cout << "Element: " << count++ << "|" << std::endl;
		std::cout << "------------------------------------------------------------" << std::endl;
		symbol.second->print();
		std::cout << std::endl;
	});
	std::cout << std::endl << std::endl;
}

int Table::getScopeSize()
{

}

void Table::AddScope(std::vector<std::shared_ptr<Var>> * vars)
{
	//std::cout << "PUSH SCOPE" << std::endl;
	m_localStackPointer = 0;
	getInstance()->m_scope++;
	std::map<std::string, Element> newElement = std::map<std::string, Element>();
	getInstance()->m_table.push_back(newElement);

	std::for_each(vars->begin(), vars->end(), [&] (std::shared_ptr<Var> element)
	{
		element->m_location = std::to_string(m_localStackPointer);
		InsertElement(element->m_name, element);
		m_localStackPointer += element->m_type->m_size;
	});

	// for(int i = vars->size() - 1; i >=0; --i)
	// {
	// 	auto element = vars->at(i);
	// 	element->m_location = std::to_string(m_localStackPointer);
	// 	InsertElement(element->m_name, element);
	// 	m_localStackPointer += element->m_type->m_size;
	// }
}

void Table::RemoveScope()
{
	m_localStackPointer = m_globalStackPointer;
	if(getInstance()->m_scope > 0)
	{
		// std::cout << "POP SCOPE" << std::endl;
		if(getInstance()->verbose)
			PrintScope();
		std::cout << std::endl;
		getInstance()->m_scope--;
		getInstance()->m_table.pop_back();
	}
	else
	{
		std::cout << "ERROR REMOVE SCOPE" << std::endl;
		exit(-1);
	}
}


std::vector<std::shared_ptr<Var>> * Table::MakeVars(Type* type, std::vector<std::string> * identList, std::vector<std::shared_ptr<Var>> * paramStuff)
{
	//std::for_each(identList->begin(), identList->end(), [&] (std::string element)
	for(int i = identList->size()-1; i>=0; --i)
	{
		auto element = identList->at(i);
		std::shared_ptr<Type> newType(new Type(type->m_size, type->m_name));
		std::shared_ptr<Var> myVar(new Var("NONE", newType, element));
		paramStuff->push_back(myVar);
	}//);
	return paramStuff;
}

std::vector<std::shared_ptr<Type>> * Table::MakeSubRecord(Type * type, std::vector<std::shared_ptr<Type>> * paramStuff ,std::vector<std::string> * identList)
{
	std::for_each(identList->begin(), identList->end(), [&] (std::string element)
	{
		std::shared_ptr<Type> myVar(new Type(type->m_size, element));
		paramStuff->push_back(myVar);
	});
	return paramStuff;
}

Record * Table::MakeRecord(std::vector<std::shared_ptr<Type>>* types)
{
	int count = 0;
	std::for_each(types->begin(), types->end(), [&](std::shared_ptr<Type> t)
	{
		count += t->m_size;
	});
	Record * record = new Record(*types,count,"");
	return record;
}

void Table::MakeVar(std::vector<std::string>* identList, Type * type)
{
	//std::for_each(identList->begin(), identList->end(), [&] (std::string element)
	for(int i = identList->size()-1; i>=0; --i)
	{
		std::string element = identList->at(i);
		std::shared_ptr<Type> newType(new Type(type->m_size, type->m_name));
		std::shared_ptr<Var> myVar(new Var(std::to_string(m_localStackPointer), newType, element));
		InsertElement(element,myVar);

		if(m_localStackPointer == m_globalStackPointer)
		{
			m_localStackPointer += type->m_size;
			m_globalStackPointer += type->m_size;
		}
		else
		{
			m_localStackPointer += type->m_size;
		}
	}
	//});
	
	// std::stringstream ss("");
	// 	ss<<"\tADDI $sp,\t$sp,\t-"<<m_localStackPointer<<"\t# increment sp to make space for local variables";

	// Output::out(ss.str());


}

Const * Table::makeConst(Const * a,symbols sym,Const * b)
{
	if(a->m_type == UNKNOWN)
	{
		if(sym == NOT)
		{
			int size = (int)atoi(b->m_value.c_str());
			size = ~size;
			return new Const(std::to_string(size),b->m_type);
		}
		else if(sym == UNARY)
		{
			int size = (int)atoi(b->m_value.c_str());
			size = -size;
			return new Const(std::to_string(size),b->m_type);
		}
		else
		{
			std::cout << "CONST ERRORS UNKNOWN SYMBOL" << std::endl;
			exit(-1);
		}
	}
	else if(a->m_type != b->m_type)
	{
		std::cout << "CONST ERRORS TYPE MISMATCH" << std::endl;
		exit(-1);
	}
	if(a->m_type == INT || a->m_type == CHAR)
	{
		switch(sym)
		{
			case OR:
			{
				int size = (int)atoi(a->m_value.c_str()) ||  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case AND:
			{
				int size = (int)atoi(a->m_value.c_str()) &&  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case NOT_EQUAL:
			{
				int size = (int)atoi(a->m_value.c_str()) !=  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case EQUAL:
			{
				int size = (int)atoi(a->m_value.c_str()) ==  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case LESS_EQUAL:
			{
				int size = (int)atoi(a->m_value.c_str()) <=  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case GREAT:
			{
				int size = (int)atoi(a->m_value.c_str()) >  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case GREAT_EQUAL:
			{
				int size = (int)atoi(a->m_value.c_str()) >=  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case LESS:
			{
				int size = (int)atoi(a->m_value.c_str()) <  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case ADD:
			{
				int size = (int)atoi(a->m_value.c_str()) +  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case SUB:
			{
				int size = (int)atoi(a->m_value.c_str()) -  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case DIV:
			{
				int size = (int)atoi(a->m_value.c_str()) /  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case MOD:
			{
				int size = (int)atoi(a->m_value.c_str()) %  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			case MULT:
			{
				int size = (int)atoi(a->m_value.c_str()) *  (int)atoi(b->m_value.c_str());
				return new Const(std::to_string(size), a->m_type);
			}
			default:
				std::cout << "CONST ERRORS MAKE CONST" << std::endl;
				exit(-1);
		}
	}
	else if(a->m_type == STRING)
	{
		switch(sym)
		{
			case OR:
			{
				int size = a->m_value.length() || a->m_value.length();
				return new Const(std::to_string(size), a->m_type);
			}
			case AND:
			{
				int size = a->m_value.length() && a->m_value.length();
				return new Const(std::to_string(size), a->m_type);
			}
			case NOT_EQUAL:
			{
				int size = a->m_value.length() != a->m_value.length();
				return new Const(std::to_string(size), a->m_type);
			}
			case EQUAL:
			{
				int size = a->m_value.length() == a->m_value.length();
				return new Const(std::to_string(size), a->m_type);
			}
			case LESS_EQUAL:
			{
				int size = a->m_value.length() <= a->m_value.length();
				return new Const(std::to_string(size), a->m_type);
			}
			case GREAT:
			{
				int size = a->m_value.length() > a->m_value.length();
				return new Const(std::to_string(size), a->m_type);
			}
			case GREAT_EQUAL:
			{
				int size = a->m_value.length() >= a->m_value.length();
				return new Const(std::to_string(size), a->m_type);
			}
			case LESS:
			{
				int size = a->m_value.length() < a->m_value.length();
				return new Const(std::to_string(size), a->m_type);
			}
			case ADD:
			{
				std::string size = a->m_value + a->m_value;
				return new Const(size, a->m_type);
			}
			default:
				std::cout << "CONST ERRORS MAKE CONST" << std::endl;
				exit(-1);
		}
	}
	else
	{
		//lookup
	}
}

int Table::getArraySize(Const *a,Const *b, int size)
{
	int vala = 0;
	int valb = 0;
	if((a->m_type == INT || a->m_type == INT) || (a->m_type == ID || a->m_type == INT) || (a->m_type == INT || a->m_type == ID))
	{
		if(a->m_type == INT && b->m_type == INT)
		{
			vala = (int)atoi(a->m_value.c_str());
			valb = (int)atoi(b->m_value.c_str());
			return (valb - vala + 1) * size;
		}
		else if(a->m_type == ID && b->m_type == INT)
		{
			auto temp = GetElement(a->m_value);
			auto newTemp = dynamic_cast<Const *>(temp.get());
			vala = (int)atoi(newTemp->m_value.c_str());
			valb = (int)atoi(b->m_value.c_str());
			return (valb - vala + 1)*size;
		}
		else if(a->m_type == INT && b->m_type == ID)
		{
			auto temp = GetElement(b->m_value);
			auto newTemp = dynamic_cast<Const *>(temp.get());
			valb = (int)atoi(newTemp->m_value.c_str());
			vala = (int)atoi(a->m_value.c_str());
			return (valb - vala + 1)*size;
		}
	}
	else
	{
		std::cout << "CONST ERRORS ARRAY SIZE MISMATCH" << std::endl;
		exit(-1);
	}
}


void Table::MakeConst(std::string element, Const * type)
{
	std::shared_ptr<Const> myConst(new Const(type->m_value, element, element, type->m_type));
	InsertElement(element,myConst);

}

int Table::getSize(Const * a)
{
	if(a->m_type == ID)
	{
		auto temp = GetElement(a->m_value);
		auto newTemp = dynamic_cast<Const *>(temp.get());
		return (int)atoi(newTemp->m_value.c_str());
	}
	else if(a->m_type == INT)
	{
		return (int)atoi(a->m_value.c_str());
	}
	else
	{
		std::cout << "CONST CONVERSION ERRORS" << std::endl;
		exit(-1);
	}

}

SimpleType * Table::MakeSimple(std::string id)
{
	auto temp = GetElement(id);
	if(temp->m_name == "EMPTY")
		return new SimpleType(id, 4, id);

	auto newTemp = dynamic_cast<Type *>(temp.get());
	return new SimpleType(id, newTemp->m_size, id);
}

Symbol::Symbol():
m_name("")
{
}

Symbol::Symbol(std::string name):
m_name(name)
{
}

Symbol::Symbol(Symbol & x):
m_name(x.m_name)
{
}

Function::Function():
Symbol(),
m_returnType(),
m_location(""),
m_parameters(),
m_forward(false)
{
}

Function::Function(std::shared_ptr<Type> returnType, std::string location, std::vector<std::shared_ptr<Var>> parameters, std::string name, bool forward):
Symbol(name),
m_returnType(returnType),
m_location(location),
m_parameters(parameters),
m_forward(forward)
{
	m_parameterSize = 0;
	for(auto var : parameters)
	{
		m_parameterSize+= var->m_type->m_size;
	}
}

Function::Function(std::string location, std::vector<std::shared_ptr<Var>> parameters, std::string name, bool forward):
Symbol(name),
m_returnType(),
m_location(location),
m_parameters(parameters),
m_forward(forward)
{
	m_parameterSize = 0;
	for(auto var : parameters)
	{
		m_parameterSize+= var->m_type->m_size;
	}
}

Type::Type():
Symbol(),
m_size(4)
{
}

Type::Type(int size):
Symbol(""),
m_size(size)
{
}

Type::Type(int size, std::string name):
Symbol(name),
m_size(size)
{
}

Array::Array():
Type(),
m_lower(0),
m_upper(0),
m_type()
{
}

Array::Array(int lower,int upper, std::shared_ptr<Type> type, int size, std::string name):
Type(size, name),
m_lower(lower),
m_upper(upper),
m_type(type)
{
}

Array::Array(int lower,int upper, std::shared_ptr<Type> type, int size):
Type(size),
m_lower(lower),
m_upper(upper),
m_type(type)
{
}

Array::Array(int lower,int upper, std::shared_ptr<Type> type):
Type(),
m_lower(lower),
m_upper(upper),
m_type(type)
{
}


Record::Record():
Type(),
m_layout()
{
}

Record::Record(std::vector<std::shared_ptr<Type>> layout, int size, std::string name):
Type(size, name),
m_layout(layout)
{
}

SimpleType::SimpleType():
Type(),
m_type("")
{
}

SimpleType::SimpleType(std::string type, int size, std::string name):
Type(size, name),
m_type(type)
{
}

Var::Var():
Symbol(),
m_type(),
m_location("")
{
}

Var::Var(std::string location, std::shared_ptr<Type> type, std::string name):
Symbol(name),
m_type(type),
m_location(location)
{
}

Const::Const():
Symbol(),
m_type(UNKNOWN),
m_value(""),
m_location("")
{
}

Const::Const(std::string value, ConstType type):
Symbol(),
m_type(type),
m_value(value),
m_location("")
{
}

Const::Const(std::string value, std::string location, std::string name):
Symbol(name),
m_value(value),
m_type(UNKNOWN),
m_location(location)
{
}

Const::Const(std::string value, std::string location, std::string name, ConstType type):
Symbol(name),
m_type(type),
m_value(value),
m_location(location)
{
}

void Symbol::print()
{
	std::cout << "ERRORS" << std::endl;
}

void Function::print()
{
	std::cout << std::setw(SIZE) << "Function --- ID: " << std::left << std::setw(SIZE2) << m_name << std::right << " Location: " << std::left << std::setw(SIZE3) << m_location << std::right;
	if(m_returnType)
	{
		std::cout << " ReturnType: ";
		m_returnType->print();
	}
	std::cout << " Parameters: ";
	std::for_each(m_parameters.begin(), m_parameters.end(), [](std::shared_ptr<Var> var)
	{
		std::cout << std::endl;
		var->print();
	});
	if(m_parameters.size() == 0)
		std::cout << " None ";
}

void Type::print()
{
	std::cout << "\t" <<std::setw(SIZE) << "Type --- ID: " <<  std::left << std::setw(SIZE2) << m_name << std::right << " Size: " << m_size;
}

void Array::print()
{
	std::cout << std::setw(SIZE) << "Array --- ID: " << std::left << std::setw(SIZE2) << m_name << std::right << " Size: " << m_size << " Lower: " << m_lower << " Upper: " << m_upper << " Type: ";
	m_type->print();
}

void Record::print()
{
	std::cout << std::setw(SIZE) << "Record --- ID: " << std::left << std::setw(SIZE2) << m_name << std::right << " Size: " << m_size << " Layout: ";
	std::for_each(m_layout.begin(), m_layout.end(), [](std::shared_ptr<Type> type)
	{
		std::cout << std::endl;
		type->print();
	});
}

void Var::print()
{
	std::cout << std::setw(SIZE) << "Var --- ID: " << std::left << std::setw(SIZE2) << m_name << std::right << " Location: " << std::left << std::setw(SIZE3) << m_location << std::right << " Type: " << m_type->m_name;
	std::cout << std::endl;
	m_type->print();
}

void Const::print()
{
	std::cout << std::setw(SIZE) << "Const --- ID: " << std::left << std::setw(SIZE2) << m_name << std::right << " Location: " << std::left << std::setw(SIZE3) << m_location << std::right << " Value: " << m_value;
}

void SimpleType::print()
{
    std::cout << std::setw(SIZE) << "Simple --- ID: " << std::left << std::setw(SIZE2) << m_name << std::right << " Size: " << m_size << " Type: " << m_type;
}

void Expression::print()
{
	std::cout<<"\n location:\t"<<m_location<<"Type: "<<m_type<<std::endl;
	// // std::cout << std::setw(SIZE) << "Expression: " << std::left << std::setw(SIZE2) 
	// 			<< m_location << std::right 
	// 			<< " Size: " << m_value << " Type: " << m_type<<std::endl;
}

Expression::Expression():
Symbol(),
m_location(""),
m_type(UNKNOWN),
m_value("")
{
	m_isConstant = false;
}

Expression::Expression(ConstType type, std::string location)
{
	m_isConstant = false;
	m_location = location;
	m_type = type;
}

Expression::Expression(std::string value, ConstType type):
Symbol(),
m_location(""),
m_type(type),
m_value(value)
{
	m_isConstant = false;
}

void Expression::releaseRegister()
{ 
	int reg = std::stoi(m_location.substr(1,m_location.size()));
	// std::cout<<"releasing :"<<reg<<std::endl;
	Output::freeRegister(reg);
}

Expression * Table::makeExpression(Expression * a, symbols sym, Expression * b)
{
	std::stringstream mst("");
	int reg = Output::getRegister();
	if(a==NULL || b== NULL)
	{
		yyerror("NULL Expression");
	}
	if(a->m_type == ID)
	{
		lookupExpression(a);
	}
	if(b->m_type == ID)
	{
		lookupExpression(b);
	}

		int areg = Output::getRegister();
		int breg = Output::getRegister();
	
	if(a->m_isConstant)
	{
		mst<<"\tLI,\t$"<<areg<<",\t"<<a->m_value<<"# load the constant value into register\n";
	}
	if(b->m_isConstant)
	{
		mst<<"\tLI,\t$"<<breg<<",\t"<<b->m_value<<"# load the constant value into register\n";
	}
	Output::freeRegister(areg);
	Output::freeRegister(breg);



	switch(sym)
		{
			case NOT:
			{
				Output::comment("NOT expression");
				mst	<<"\t seq \t$"<<reg<<",\t$0,"<<b->m_location<<"\t#check if they not"<<std::endl;
				Output::freeRegister(reg);
				Output::out(mst.str());
				b->releaseRegister();
				auto temp =  new Expression(BOOLEAN, "$" + std::to_string(reg));;				
				temp->m_size = 4;
				return temp;
			}
			case UNARY:
			{
				Output::comment("unary minux expression");
				mst	<<"\t SUB \t$"<<reg<<",\t$0,"<<b->m_location<<"\t#Unary MINUS"<<std::endl;
				Output::freeRegister(reg);
				Output::out(mst.str());
				b->releaseRegister();
				auto temp =  new Expression(b->m_type, '$' + std::to_string(reg));				
				temp->m_size = 4;
				return temp;
			}
			case OR:
			{

				Output::comment("OR expression");
				mst <<"\t li \t$"<<reg<<",\t0"<<"\t#OR"<<std::endl
					<<"\t or \t"<<a->m_location<<",\t"<<a->m_location<<",\t$"<<"\t#OR"<<reg<<std::endl
					<<"\t sne \t$"<<reg<<",\t"<<a->m_location<<",\t$"<<"\t#OR"<<reg<<std::endl;

				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;
			}
			case AND:
			{
				Output::comment("and expression");

				mst <<"\t li \t$"<<reg<<",\t0"<<"\t#AND"<<std::endl
					<<"\t seq \t"<<a->m_location<<",\t"<<a->m_location<<",\t$"<<reg<<"\t#AND"<<std::endl
					<<"\t seq \t"<<b->m_location<<",\t"<<b->m_location<<",\t$"<<reg<<"\t#AND"<<std::endl
					<<"\t seq \t$"<<reg<<",\t"<<b->m_location<<",\t"<<a->m_location<<"\t#AND"<<std::endl;

				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;

			}
			case NOT_EQUAL:
			{
				Output::comment("<> expressions");
				mst <<"\t sne \t$"<<reg<<",\t" <<a->m_location<<",\t"<<b->m_location<<"\t#<> NOT EQUAL";
				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;
			}
			case EQUAL:
			{
				Output::comment("== expressions");
				mst <<"\t seq \t$"
					<<reg<<",\t" 
					<<a->m_location
					<<",\t"
					<<b->m_location<<"\t# == Comparison";
				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;
			}
			case LESS_EQUAL:
			{
				Output::comment("<= expressions");
				mst <<"\t sle \t$"
					<<reg<<",\t" 
					<<a->m_location
					<<",\t"
					<<b->m_location<<"\t#LESS EQUAL";
				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;

			}
			case GREAT:
			{
				Output::comment("> expressions");
				mst <<"\t sgt \t$"
					<<reg<<",\t" 
					<<a->m_location
					<<",\t"
					<<b->m_location<<"\t#GREATER THAN";
				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;

			}
			case GREAT_EQUAL:
			{
				Output::comment(">= expressions");
				mst <<"\t sge \t$"
					<<reg<<",\t" 
					<<a->m_location
					<<",\t"
					<<b->m_location<<"\t#Greater than or EQUAL";
				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;

			}
			case LESS:
			{
				Output::comment("< expressions");
				mst <<"\t slt \t$"
					<<reg<<",\t" 
					<<a->m_location
					<<",\t"
					<<b->m_location<<"\t#LESS THAN";
				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));				
				temp->m_size = 4;
				return temp;
			}
			case ADD:
			{
				Output::comment("Add two expressions");
				mst <<"\t add \t$"
					<<reg<<",\t" 
					<<a->m_location
					<<",\t"
					<<b->m_location<<"\t#ADDITION";
				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;
			}
			case SUB:
			{
				Output::comment("subtract two expressions");
				mst <<"\t sub \t$"
					<<reg<<",\t" 
					<<a->m_location
					<<",\t"
					<<b->m_location<<"\t#Subtraction";
				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;
			}
			case DIV:
			{
				Output::comment("Divide two expressions");
				mst <<"\t div \t"<<a->m_location
					<<",\t"	<<b->m_location<<"\t#Division"<<std::endl;
				a->releaseRegister();
				b->releaseRegister();
				mst<<"\t mflo \t$"	<<reg;
				Output::out(mst.str());
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;
			}
			case MOD:
			{
				Output::comment("Divide two expressions");
				mst <<"\t div \t"<<a->m_location
					<<",\t"	<<b->m_location<<std::endl;

				mst<<"\t mfhi \t$"	<<reg;
				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;
			}
			case MULT:
			{
				Output::comment("multiply two expressions");
				mst <<"\t mult \t"<<a->m_location
					<<",\t"	<<b->m_location<<std::endl;

				mst<<"\t mflo \t$"	<<reg<<"\t#Muliplication";
				Output::out(mst.str());
				a->releaseRegister();
				b->releaseRegister();
				auto temp =  new Expression(a->m_type, "$" + std::to_string(reg));
				temp->m_size = 4;
				return temp;
			}
			default:
				std::cout << "ERRORS MAKE EXPRESSION" << std::endl;
				exit(-1);
		}

}


Expression* Table::makeIntExpression(int t)
{
	std::stringstream mst("");
	int reg = Output::getRegister();
	// Output::comment("loading int into register");
	mst<<"\tli $"<<reg<<",\t"<<t<<"\t#New Integer Expression"; 
	Output::out(mst.str());
	auto temp =  new Expression(INT, "$" + std::to_string(reg) );
	temp->m_size = 4;
	return temp;
}

Expression* Table::makeStringExpression(std::string t)
{
	// std::stringstream mst("");
	std::string label = Output::addString(t);
	return new Expression(STRING, label );
}

Expression* Table::makeCharExpression(std::string t)
{
	std::stringstream mst("");
	int reg = Output::getRegister();
	mst<<"\tli $"<<reg<<",\t"<<t<<"\t#loading character into register"; 
	// Output::comment();
	Output::out(mst.str());
	auto temp =  new Expression(CHAR, "$" + std::to_string(reg) );
	temp->m_size = 4;
	return temp;
}


void Table::makeWriteStatement(std::deque<Expression*>* elist)
{
	for(Expression* ep : *elist)
	{
		writeExpression(ep);
	}
}

Expression * Table::lookupExpression(Expression * ep)
{
	if(ep == NULL)
	{
		yyerror("Expression can not be null");
	}

	std::stringstream ss("");
	int areg = Output::getRegister();
	auto var = dynamic_cast<Var*>( Table::GetElement(ep->m_value).get());
	bool boolean = false;
	SimpleType * tp;
	if(var == NULL) // not a var
	{
		tp = dynamic_cast<SimpleType*>( Table::GetElement(ep->m_value).get());
	
		if(tp == NULL) // it might be constant
		{
			auto p = dynamic_cast<Const*>( Table::GetElement(ep->m_value).get());

			if(p==NULL)
			{
				auto temp = "UNKNOWN SYMBOL " + ep->m_value; 
				yyerror(temp.c_str() );
			}

			ep->m_value = p->m_value;
			ep->m_isConstant = true;
			ep->m_type = p->m_type;
			return ep;
		}
		else
		{
			if(tp->m_type=="true" || tp->m_type=="TRUE")
			{
				boolean = true;
				ep->m_type = BOOLEAN;
				ss<<"\t LI \t$"<<areg<<", \t 1"<<"\t#Load boolean true into register"<<std::endl;

			}
			else if(tp->m_type=="false" || tp->m_type=="FALSE")
			{
				boolean = true;
				ep->m_type = BOOLEAN;
						ss<<"\t LI \t$"<<areg<<", \t 0"<<"\t#Load boolean false into register"<<std::endl;
			}
		}

	}
	else
	{
		if(var->m_type->m_name=="integer" || var->m_type->m_name=="INTEGER")
		{
			ep->m_type = INT;
		}
		else if(var->m_type->m_name=="char" || var->m_type->m_name=="CHAR")
		{
			ep->m_type = CHAR;
		}
		else if(var->m_type->m_name=="boolean" || var->m_type->m_name=="BOOLEAN")
		{
			ep->m_type = BOOLEAN;
		}
		else
		{
			yyerror("OOPS, SOMETHING BAD HAPPENED");
		}
	} 
	if(!boolean)
	{
		int location = std::stoi(var->m_location);
		ss<<"\t LW \t$"<<areg<<", \t -" << location<<getPointer(var->m_name)<<"\t#Load "<<ep->m_location<<" into register"<<std::endl;
	}
	
	ep->m_location = "$" + std::to_string(areg);
	// Output::comment("looking up id ");
	Output::out(ss.str());
		
	return ep;
	
}

void Table::writeExpression(Expression * ep)
{
	if(ep == NULL)
	{
		yyerror("invalid expression");
	}

	// Output::comment("Write Statement "+ std::to_string(ep->m_type));
	std::stringstream mst("");

	if(ep->m_type == ID )
	{
		lookupExpression(ep);
	}
	if(ep->m_isConstant)
	{
		auto treg = Output::getRegister();
		mst<<"\tLI \t$"<<treg<<",\t"<<ep->m_value<<"\t#load the constant into a register to print\n";
		ep->m_location = "$" + std::to_string(treg);
	}

	switch(ep->m_type)
	{
		case INT:
		case BOOLEAN:
		{
			mst<<"\tli\t $v0, \t1"<<"\t#Load COMMAND to print INTEGER"<<" \n";
			mst<<"\tmove\t $a0,\t "<<ep->m_location<<"\t#load the expressions value"<<std::endl;
			mst<<"\tsyscall";
			ep->releaseRegister();
			break;
		}
		case STRING:
		{
			mst<<"\tli\t $v0, \t4"<<"\t#Load command to print string"<<"\n";
			mst<<"\tla\t $a0,\t "<<ep->m_location<<"\t#load the expressions value"<<std::endl;
			mst<<"\tsyscall";

			break;
		}
		case CHAR:
		{
			ep = intToChar(ep);
			mst<<"\tli\t $v0, \t11"<<"\t#load commad to print char"<<" \n";
			mst<<"\tmove\t $a0,\t "<<ep->m_location<<"\t#Load the expressions value"<<std::endl;
			mst<<"\tsyscall";
			ep->releaseRegister();
			break;
		}
	}

	Output::out(mst.str());
}


void Table::makeReadStatement(std::deque<Expression*>* elist)
{
	if(elist == NULL)
	{
		yyerror("invalid expression list");
	}

	for(Expression* ep : *elist)
	{
		readExpression(ep);
	}
}

void Table::readExpression(Expression * ep)
{
	if(ep == NULL)
	{
		yyerror("invalid expression");
	}
	
	auto var = dynamic_cast<Var*>( Table::GetElement(ep->m_value).get());

	if(var == NULL)
	{
		auto temp =  ep->m_value + " is not known in the current scope";
		yyerror( temp.c_str());
	}

	int type;
	int location = std::stoi(var->m_location);
	if(var->m_type->m_name=="integer" || var->m_type->m_name=="INTEGER" || var->m_type->m_name=="boolean" || var->m_type->m_name=="BOOLEAN"  )
	{
		type = 5;
	}
	else if(var->m_type->m_name=="CHAR" || var->m_type->m_name=="char"  )
	{
		type = 12;
	}
	std::stringstream mst("");

	// Output::comment("read expression");
	mst <<"\t li \t $v0, \t "<<type<<"\t#Load correct system call int is 5 char is 12"<<std::endl;
	mst <<"\tsyscall\n";

	int reg = Output::getRegister();
	mst<<"\t sw \t$v0, \t-" << location<<getPointer(ep->m_value)<<"\t#save the value that was read"<<std::endl;

	Output::out(mst.str());
	Output::freeRegister(reg);
}


Expression* Table::makeAssignment(Expression* left, Expression* right)
{
	if(left == NULL || right == NULL)
	{
		yyerror("invalid expression");
	}

	std::stringstream ss("");
	if(left->m_type != ID)
	{
		yyerror("ERROR NOT AN LVALUE");
	}
	if(right->m_type == ID)
	{
		lookupExpression(right);
	}

	auto var = dynamic_cast<Var*>( Table::GetElement(left->m_value).get());
	int location = std::stoi(var->m_location);

	ss<<"\tSW\t"<< right->m_location<<", \t-"<<location<<getPointer(left->m_value)<<"\t#assign new value to " << left->m_value<<std::endl;

	Output::out(ss.str());
	right ->releaseRegister();
	return left;
}

int Table::makeBeginIfStatement(Expression * exp)
{
	// Output::comment("IF STATEMENT");
	if(exp == NULL)
	{
		yyerror("invalid expression");
	}

	std::stringstream ss("");
	if(exp->m_type == ID)
	{
		lookupExpression(exp);
	}
	exp->releaseRegister();

	Output::pushEndIfQueue();
	int ifCount = Output::pushIfQueue();
	
	ss<<"\t BEQ \t $0"<<", \t"<<exp->m_location<<", ELSEIF"<<ifCount<<"\t#comparison for if statement"<<std::endl;
	Output::out(ss.str());
	return 999;

}

void Table::makeIfStuff(Expression * exp)
{
	if(exp == NULL)
	{
		yyerror("invalid expression");
	}
	std::stringstream ss("");
	if(exp->m_type == ID)
	{
		lookupExpression(exp);
	}
	exp->releaseRegister();
	int nextLabel = Output::pushIfQueue();

	// Output::comment(" nextLabel: " +std::to_string( nextLabel));



	//finish off the last part of the la

	ss<<"\t BEQ \t $0"<<", \t"<<exp->m_location<<", ELSEIF"<<nextLabel<<"\t#else if part of if statement"<<std::endl;
	Output::out(ss.str());
}

void Table::finishIfStatement(int end)
{
	std::stringstream ss("");
	ss<<"ELSEIF"<<Output::popIfQueue()<<":\n";
	ss<<"ENDOFIFSTATEMENT"<<Output::popEndIfQueue()<<":\n";
	Output::out(ss.str());
}

void Table::finishSubIf()
{
	std::stringstream ss("");
	int curLabel = Output::popIfQueue();
	ss<<"\tJ\t ENDOFIFSTATEMENT"<<Output::getEndIfQueue()<<"\t#Jump to the end of the if statement"<<std::endl;

	//set up the label for this else if
	ss<<"ELSEIF"<<curLabel<<":\t# sub else if statement"<<"\n";

	Output::out(ss.str());
}

void Table::finishElseStatement()
{
	std::stringstream ss("");
	ss<<"ENDOFIFSTATEMENT"<<Output::popEndIfQueue()<<":\n";
	Output::out(ss.str());
}

void Table::printElse()
{
	std::stringstream ss("");
	ss<<"ELSEIF"<<Output::popIfQueue()<<":\n";
	Output::out(ss.str());
}


void Table::beginWhileLoop()
{
	// Output::comment("WHILE LOOP");
	std::stringstream ss("");
	ss<<"WHILE"<<Output::pushWhile()<<":\n";
	Output::out(ss.str());
}

void Table::evaluateWhileCondition(Expression* exp)
{
	std::stringstream ss("");
	
	if(exp->m_type == ID){
		lookupExpression(exp);
	}
	
	exp->releaseRegister();
	ss<<"\tBEQZ\t"<<exp->m_location<<"\t ENDWHILE"<<Output::getWhile()<<"\t#Evaluate While Condition"<<std::endl;
	Output::out(ss.str());

}

void Table::endWhileLoop()
{
	std::stringstream ss("");

	ss<<"\tJ WHILE"<<Output::getWhile()<<"\n";
	ss<<"ENDWHILE"<<Output::popWhile()<<":\n";
	Output::out(ss.str());
}


void Table::beginRepeat()
{
	Output::comment("REPEAT LOOP");
	std::stringstream ss("");
	ss<<"REPEAT"<<Output::pushRepeat()<<":\n";
	Output::out(ss.str());
}


void Table::finishRepeat(Expression* exp)
{
	if(exp == NULL)
	{
		yyerror("invalid expression");
	}
	std::stringstream ss("");

	if(exp->m_type == ID){
		lookupExpression(exp);
	}
	exp->releaseRegister();

	ss<<"\tBEQZ\t"<<exp->m_location<<"\tREPEAT"<<Output::popRepeat()<<"\t#evaluate repeat loop"<<std::endl;
	Output::out(ss.str());
}

void Table::beginForLoop(Expression* counter, Expression* limit, bool increment)
{
	Output::comment("FOR LOOP");
	if(counter == NULL || limit == NULL)
	{
		yyerror("invalid expression");
	}

	std::stringstream ss("");

	if(limit->m_type == ID){
		lookupExpression(limit);
	}


	//get the expression into a register
	int areg = Output::getRegister();
	auto var = dynamic_cast<Var*>( Table::GetElement(counter->m_value).get());
	int location = std::stoi(var->m_location);


	ss<<"\tJ\tFORBODY"<<Output::pushFor()<<std::endl;


	
	ss<<"FORINCREMENT"<<Output::getFor()<<":\t#increment the counter variable"<<":\n";

	ss<<"\tLW \t$"<<areg<<", \t-" << location<<getPointer(var->m_name)<<"\n";

	if(increment)
	{
		ss<<"\tADDI\t$";
	}
	else
	{
		ss<<"\tSUBI\t$";
	}	
	ss<<areg<<",\t$"<<areg<<",\t"<<1<<"\t#Increment/decrement loop"<<std::endl;

	ss<<"\tSW\t$"<<areg<<", \t-"<<location<<getPointer(var->m_name)<<"\t#save off the incremented variable"<<"\n";

	if(increment)
	{
		ss<<"\tBGT\t$";
	}
	else
	{
		ss<<"\tBLT\t$";
	}
	ss<<areg<<",\t"<<limit->m_location<<",\tFOREND"<<Output::getFor()<<"\t#check done condition"<<std::endl;

	ss<<"FORBODY"<<Output::getFor()<<":\n";

	Output::out(ss.str());
	//limit->releaseRegister();
	Output::freeRegister(areg);
}

void Table::finishForLoop(Expression* t)
{
	if(t == NULL)
	{
		yyerror("invalid expression");
	}

	t->releaseRegister();
	std::stringstream ss("");
	ss<<"\tJ\tFORINCREMENT"<<Output::getFor()<<std::endl;
	ss<<"FOREND"<<Output::popFor()<<":\n";
	Output::out(ss.str());
}


Expression* Table::intToChar(Expression* exp)
{
	if(exp == NULL)
	{
		yyerror("invalid expression");
	}

	if(exp->m_type == ID){
		lookupExpression(exp);
	}

	exp->m_type = CHAR;

	return exp; 
}

Expression* Table::charToInt(Expression* exp)
{

	if(exp == NULL)
	{
		yyerror("invalid expression");
	}

	if(exp->m_type == ID){
		lookupExpression(exp);
	}

	exp->m_type = INT;

	return exp; 
}



Expression* Table::incrementExpression(Expression* exp)
{

	// Output::comment("INCREMENT CHAR");
	if(exp == NULL)
	{
		yyerror("invalid expression");
	}

	if(exp->m_type == ID){
		lookupExpression(exp);
	}

	std::stringstream ss("");

	ss<<"\tADDI\t"<<exp->m_location<<",\t"<<exp->m_location<<",\t1"<<"\t#increment character";
	Output::out(ss.str());
	return exp;
}


Expression* Table::decrementExpression(Expression* exp)
{
	Output::comment("DECREMENT CHAR");
	if(exp == NULL)
	{
		yyerror("invalid expression");
	}
	if(exp->m_type == ID){
		lookupExpression(exp);
	}

	std::stringstream ss("");

	ss<<"\tSUBI\t"<<exp->m_location<<",\t"<<exp->m_location<<",\t1"<<"\t#decrement char";
	Output::out(ss.str());
	return exp;
}


void Table::checkFunctionSignature(std::string id, std::deque<Expression*>* elist)
{
	auto func = dynamic_cast<Function*>( Table::GetElement(id).get());
	if(func == NULL) 
		yyerror("UNKNOWN Function");
	if(elist->size() != func->m_parameters.size())
		yyerror("ivalid parameters");

}


void Table::makeProcedureCall(std::string id, Expression* exp, std::deque<Expression*>* elist)
{
	std::stringstream ss("");

		ss<<"\tSW\t$fp,\t-4($sp)\t#Save the old frame pointer onto the stack\n";
		ss<<"\tMOVE\t$fp,\t$sp\t#move the frame pointer to point at the stack pointer\n";
		ss<<"\tADDI\t$sp,\t$sp,\t-4"<<"\t#move the stack pointer to make room the frame pointer"<<std::endl;
	auto func = dynamic_cast<Function*>( Table::GetElement(id).get());

	if(func == NULL)
		yyerror("Unknown function");

	int functionOffset;
	if(exp == NULL)
	{

	}
	else
	{	
		elist->push_front(exp);
		checkFunctionSignature(id,elist);

		ss<<"\tADDI\t$sp,\t$sp,\t-4"<<"\t#move the stack pointer to make room the ra"<<std::endl;

		// push everything on the stack
		for(Expression* ep : *elist)
		{
			if(ep->m_type == ID)
			{
				lookupExpression(ep);
			}

			ss<<"\tADDI\t$sp,\t$sp"<<",\t-"<<ep->m_size <<"\t#increment the sp for new parameter"<<std::endl;
			ss<<"\tSW\t"<<ep->m_location<<",\t0($sp)"<<"\t#store the value into the stack"<<std::endl;
			ep->releaseRegister();
		}
	}

	ss<<"JAL "<<func->m_location<<"_PROLOG"<<"\t#go to the function"<<"\n";
	Output::out(ss.str());
}


void Table::makeProcedureProlog(std::string id)
{
	Output::setCurFunction(id);
	// Output::comment("making procedure");
	std::stringstream ss("");
	ss<<id<<"_PROLOG:\n";
	
		auto func = dynamic_cast<Function*>( Table::GetElement(id).get());
	
	if(func == NULL)
		yyerror("Unknown function");
	ss<<"\tSW\t$ra,\t"<<-8<<"($fp)"<<"\t#save the return address above the stack pointer"<<std::endl;
	ss<<"\tADDI\t$fp,\t$fp,\t-12\t#move frame pointer up 8\n";

	ss<<"\tADD\t$sp,\t$fp,\t-"<<m_localStackPointer<<"\t#make room for local variables \n";	

//	ss<<"\tADDI\t$sp,\t$sp,\t"<<m_localStackPointer<<"#make space for local variables\n";
//	ss<<"\tADDI\t$sp,\t$sp,\t"<<std::endl;
//ss<<"\t"<<"SW\t $fp, \t"<<-4<<"($sp)"<<"\t#save the old stack pointer"<<std::endl;
	
//	ss<<"\tMOVE\t$fp,\t$sp"<<"\t#move the frame pointer to point at the top of the stack"<<std::endl;
	Output::out(ss.str());

}


void Table::makeProcedureEpilog(std::string id)
{
	std::stringstream ss("");
	ss<<id<<"_EPILOG:\n";
	ss<<"\tADDI\t$fp,\t$fp,\t12\t#move frame pointer back 8\n";

	ss<<"\tMOVE\t$sp,\t$fp"<<"\t#move the stack pointer back to the beginning of the frame"<<std::endl;

	ss<<"\tLW\t $ra\t, -8($sp)"<<"\t#re load the return address"<<std::endl;
	
	ss<<"\tLW\t $fp\t, -4($sp)"<<"\t#reload the old frame pointer"<<std::endl;
	
	ss<<"\tJR\t$ra"<<"\t#Jump back to where we came from";
	Output::out(ss.str());
	Output::setCurFunction("__BEGIN");
}

void Table::makeReturnStatement(Expression* ep)
{
	std::stringstream ss("");


	auto func = dynamic_cast<Function*>( Table::GetElement(Output::getCurFunction()).get());

	if(func == NULL)
	{
		yyerror("UNKNOWN FUNCTION");
	}

	if(ep == NULL)
	{
		if(getReturnType(func) != UNKNOWN )
		{
			yyerror("FUNCTION MUST RETURN A VALUE");
		}
	}
	else
	{
		if(ep->m_type == ID)
		{
			lookupExpression(ep);
		}
		if(ep->m_type != getReturnType(func))
		{
			yyerror("FUNCTION RETURNING INVALID TYPE");
		}
		ss<<"\tMOVE\t$v0\t,"<<ep->m_location<<"\t#load the return value to v0"<<std::endl;
		ep->releaseRegister();
	}
	ss<<"\tJ\t"<<Output::getCurFunction()<<"_EPILOG"<<"\t#Jump to the end of this function"<<std::endl;
	Output::out(ss.str());
}


Expression* Table::functionReturn(std::string id)
{
	std::stringstream ss("");

	auto func = dynamic_cast<Function*>( Table::GetElement(id).get());
	if(func == NULL)
	{
		yyerror("UNKNOWN FUNCTION");
	}

	int reg = Output::getRegister();
	ss<<"\tMOVE\t$"<<reg<<",\t$v0"<<"\t#load the return value to the new register"<<std::endl;

	Output::out(ss.str());

	auto temp =  new Expression(getReturnType(func), "$" + std::to_string(reg));

	return temp;
}


ConstType Table::getReturnType(Function* func)
{
	if(func == NULL)
	{
		yyerror("something bad happened");
	}
	if(func->m_returnType == NULL)
	{
		return UNKNOWN;
	}
	else if(func->m_returnType->m_name == "integer" || func->m_returnType->m_name == "INTEGER")
	{
		return INT;
	}
	else if(func->m_returnType->m_name == "char" || func->m_returnType->m_name == "CHAR")
	{
		return CHAR;
	}
	else if(func->m_returnType->m_name == "boolean" || func->m_returnType->m_name == "boolean")
	{
		return BOOLEAN;
	}
}