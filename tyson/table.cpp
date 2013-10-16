#include "table.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#define SIZE 20
#define SIZE2 10
#define SIZE3 10
int m_globalStackPointer = 0;
int m_localStackPointer = 0;

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
	std::shared_ptr<Symbol> x(new Symbol("EMPTY"));
	return x;
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
}

void Table::RemoveScope()
{
	m_localStackPointer = m_globalStackPointer;
	if(getInstance()->m_scope > 0)
	{
		std::cout << "POP SCOPE" << std::endl;
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
	std::for_each(identList->begin(), identList->end(), [&] (std::string element)
	{
		std::shared_ptr<Type> newType(new Type(type->m_size, type->m_name));
		std::shared_ptr<Var> myVar(new Var("NONE", newType, element));
		paramStuff->push_back(myVar);
	});
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
	std::for_each(identList->begin(), identList->end(), [&] (std::string element)
	{
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
	});
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
	else if(a->m_type == INT || a->m_type == CHAR)
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

Expression * Table::makeExpression(Expression * a, symbols sym, Expression * b)
{
	Expression * E;
	std::cout << a->m_value << " " << sym << " " << b->m_value << std::endl;
	return E;
}

void Table::MakeConst(std::string element, Const * type)
{
	//std::shared_ptr<Const> myConst(new Const(type->m_value, std::to_string(m_localStackPointer), element, type->m_type));
	std::shared_ptr<Const> myConst(new Const(type->m_value, element, element, type->m_type));
	InsertElement(element,myConst);
	/*
	if(m_localStackPointer == m_globalStackPointer)
	{
		m_localStackPointer += 4;
		m_globalStackPointer += 4;
	}
	else
	{
		m_localStackPointer += 4;
	}
	*/
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
}

Function::Function(std::string location, std::vector<std::shared_ptr<Var>> parameters, std::string name, bool forward):
Symbol(name),
m_returnType(),
m_location(location),
m_parameters(parameters),
m_forward(forward)
{
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

Expression::Expression():
Symbol(),
m_location(""),
m_type(UNKNOWN),
m_value("")
{
}

Expression::Expression(std::string value, ConstType type):
Symbol(),
m_location(""),
m_type(type),
m_value(value)
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
	std::cout << std::setw(SIZE) << "Const --- ID: " << std::left << std::setw(SIZE2) << m_name << std::right << " Location: " << std::left << std::setw(SIZE3) << m_location << std::right << " Value: " << m_value << " Type: " << m_type;
}
void SimpleType::print()
{
    std::cout << std::setw(SIZE) << "Simple --- ID: " << std::left << std::setw(SIZE2) << m_name << std::right << " Size: " << m_size << " Type: " << m_type;
}
