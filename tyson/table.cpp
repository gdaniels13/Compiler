#include "table.h"
#include "OutputFile.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#define SIZE 20
#define SIZE2 10
#define SIZE3 10
int m_globalStackPointer = 0;
int m_localStackPointer = 0;
int m_stringCount = 0;
int m_ifCount = 0;
int m_whileCount = 0;
int m_repeatCount = 0;
int m_forCount = 0;
int m_returnCount = 0;
std::vector<int> ifVec;
std::vector<int> endVec;
std::vector<int> whileVec;
std::vector<int> repeatVec;
std::vector<int> forVec;

std::string Table::getStringCount()
{
	std::string output = "str";
	output += std::to_string(m_stringCount++);
	return output;
}


std::shared_ptr<Table> Table::m_instance;
std::vector<std::string> Table::m_strings;

Table::Table():
m_mutex(),
m_table(),
m_scope(0),
m_arrayIndex(0)
{
	ifVec = std::vector<int>();
	endVec = std::vector<int>();
	whileVec = std::vector<int>();
	repeatVec = std::vector<int>();
	forVec = std::vector<int>();
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

void Table::printStrings()
{
	Output::out("SA:");
	std::for_each(getInstance()->m_strings.begin(), getInstance()->m_strings.end(), [] (std::string element)
	{
		Output::out("\t" + element);
	});
	Output::out("GA: .word 0\n");
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
	std::cout << "GET ELEMENT ERROR " << id << std::endl;
	std::shared_ptr<Symbol> x(new Symbol("EMPTY"));
	return x;
}


std::string Table::getScope(std::string id)
{
	std::map<std::string, Element>::iterator it;

	for(auto i = getInstance()->m_scope; i > 0; --i)
	{
		std::map<std::string, Element> scope = getInstance()->m_table[i];
		it = scope.find(id);
		if(it != scope.end())
		{
			if(i == 1)
				return "($gp)";
			else
				return "($sp)";
			break;
		}
	}
	std::cout << "GET ELEMENT ERROR " << id << std::endl;
	exit(-1);
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
	for(int i = vars->size() - 1; i >=0; --i)
	{
		auto element = vars->at(i);
		element->m_location = std::to_string(m_localStackPointer);
		InsertElement(element->m_name, element);
		m_localStackPointer += element->m_type->m_size;
	}
}

void Table::MakeProcedureMain(char * id)
{
	auto temp = GetElement(id);
	if(temp->m_symbolType == _Function)
	{
		auto funcName = dynamic_cast<Function *>(temp.get());
		Output::out(funcName->m_location + ":");
		Output::out("\taddi $sp, $sp, -4");
		Output::out("\tsw $ra, 0($sp)");
		Output::out("\taddi $sp, $sp, " + std::to_string(-funcName->m_size));
	}
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

void Table::MakeProcedureEnd(char * id)
{
	auto temp = GetElement(id);
	if(temp->m_symbolType == _Function)
	{
		auto func = dynamic_cast<Function *>(temp.get());
		Output::out("RETURN" + std::to_string(m_returnCount++) + ":");
		Output::out("\taddi $sp, $sp, " + std::to_string(func->m_size));
		Output::out("\tlw $ra, 0($sp)");
		Output::out("\taddi $sp, $sp, 4");
		Output::out("\tjr $ra");
	}
}

void Table::MakeReturn(Expression * expr)
{
	if(expr == 0)
	{

	}
	else
	{
		if(expr->m_location == "")
		{
			if(expr->m_type == ID)
			{
				auto temp = GetElement(expr->m_value);
				if(temp->m_symbolType == _Var)
				{
					auto var = dynamic_cast<Var *>(temp.get());
					if(var->m_location == "")
					{
						Output::out("return var");
					}
					else
					{
						Output::out("\tmove $v0, $" + var->m_location);
						Output::out("\tj RETURN" + std::to_string(m_returnCount));
						Output::freeRegister(std::stoi(var->m_location));
					}
				}
				else if(temp->m_symbolType == _Const)
				{
					Output::out("return const");
				}
				else if(temp->m_symbolType == _Function)
				{
					Output::out("return function");
				}
				else if(temp->m_symbolType == _Array)
				{
					Output::out("return array");
				}
				else if(temp->m_symbolType == _Expression)
				{
					Output::out("return expression");
				}
				else if(temp->m_symbolType == _Symbol)
				{
					Output::out("return symbol");
				}
				else if(temp->m_symbolType == _Record)
				{
					Output::out("return record");
				}
				else if(temp->m_symbolType == _Type)
				{
					Output::out("return type");
				}
				else if(temp->m_symbolType == _SimpleType)
				{
					auto simple = dynamic_cast<SimpleType *>(temp.get());
					if(simple->m_type == "integer" || simple->m_type == "INTEGER")
					{
						Output::out("return integer");
					}
					else if(simple->m_type == "char" || simple->m_type == "CHAR")
					{
						Output::out("return char");
					}
					else if(simple->m_type == "string" || simple->m_type == "STRING")
					{
						Output::out("return string");
					}
					else if(simple->m_type == "boolean" || simple->m_type == "BOOLEAN")
					{
						Output::out("return boolean");
					}
					else if(simple->m_type == "true" || simple->m_type == "TRUE")
					{
						int regA = Output::getRegister();
						Output::out("\tli $" + std::to_string(regA) + ", 1");
						Output::out("\tmove $v0, $" + std::to_string(regA));
						Output::out("\tj RETURN" + std::to_string(m_returnCount));
						Output::freeRegister(regA);
					}
					else if(simple->m_type == "false" || simple->m_type == "FALSE")
					{
						int regA = Output::getRegister();
						Output::out("\tli $" + std::to_string(regA) + ", 0");
						Output::out("\tmove $v0, $" + std::to_string(regA));
						Output::out("\tj RETURN" + std::to_string(m_returnCount));
						Output::freeRegister(regA);
					}
					else
					{
						Output::out("return issues");
					}
				}
				else
				{
						Output::out("return issues");
				}
			}
			else
			{
				if(expr->m_type == INT || expr->m_type == CHAR)
				{
					int regA = Output::getRegister();
					Output::out("\tli $" + std::to_string(regA) + ", " + expr->m_value);
					Output::out("\tmove $v0, $" + std::to_string(regA));
					Output::out("\tj RETURN" + std::to_string(m_returnCount));
					Output::freeRegister(regA);
				}
				else if(expr->m_type == STRING)
				{
					int regA = Output::getRegister();
					Output::out("\tla $" + std::to_string(regA) + ", " + expr->m_value);
					Output::out("\tmove $v0, $" + std::to_string(regA));
					Output::out("\tj RETURN" + std::to_string(m_returnCount));
					Output::freeRegister(regA);
				}
				else
				{
					std::cout << "return errors";
				}
			}
		}
		else
		{
			Output::out("\tmove $v0, $" + expr->m_location);
			Output::out("\tj RETURN" + std::to_string(m_returnCount));
			Output::freeRegister(std::stoi(expr->m_location));
		}
	}
}

std::vector<std::shared_ptr<Var>> * Table::MakeVars(Type* type, std::vector<std::string> * identList, std::vector<std::shared_ptr<Var>> * paramStuff)
{
	if(identList == 0 || paramStuff == 0)
	{
		return 0;
	}
	else
	{
		std::for_each(identList->begin(), identList->end(), [&] (std::string element)
		{
			std::shared_ptr<Type> newType(new Type(type->m_size, type->m_name));
			std::shared_ptr<Var> myVar(new Var("NONE", newType, element));
			paramStuff->push_back(myVar);
		});
		return paramStuff;
	}
}

std::vector<std::shared_ptr<Type>> * Table::MakeSubRecord(Type * type, std::vector<std::shared_ptr<Type>> * paramStuff ,std::vector<std::string> * identList)
{
	if(paramStuff == 0 || identList == 0)
	{

	}
	else
	{
		std::for_each(identList->begin(), identList->end(), [&] (std::string element)
		{
			std::shared_ptr<Type> myVar(new Type(type->m_size, element));
			paramStuff->push_back(myVar);
		});
		return paramStuff;
	}
}

Record * Table::MakeRecord(std::vector<std::shared_ptr<Type>>* types)
{
	if(types == 0)
	{

	}
	else
	{
		int count = 0;
		std::for_each(types->begin(), types->end(), [&](std::shared_ptr<Type> t)
		{
			count += t->m_size;
		});
		Record * record = new Record(*types,count,"");
		return record;
	}
}

void Table::WriteCode(std::vector<Expression *> * exprList)
{
	if(exprList == 0)
	{

	}
	else
	{
		while(exprList->size() > 0)
		{
			Expression * exp = exprList->back();
			exprList->pop_back();
			if(exp == 0)
			{

			}
			else
			{
				if(exp->m_type == INT)
				{
					if(exp->m_location == "")
					{
						Output::out("\tli $a0, " + exp->m_value);
						Output::out("\tli $v0, 1");
						Output::out("\tsyscall \t\t#write int");
					}
					else
					{
						Output::out("\tmove $a0, $" + exp->m_location);
						Output::out("\tli $v0, 1");
						Output::out("\tsyscall \t\t#write int");
						Output::freeRegister(std::stoi(exp->m_location));
					}

				}
				else if(exp->m_type == CHAR)
				{
					if(exp->m_location == "")
					{
						Output::out("\tli $a0, " + exp->m_value);
						Output::out("\tli $v0, 11");
						Output::out("\tsyscall \t\t#write char");
					}
					else
					{
						Output::out("\tmove $a0, $" + exp->m_location);
						Output::out("\tli $v0, 11");
						Output::out("\tsyscall \t\t#write char");
						Output::freeRegister(std::stoi(exp->m_location));
					}
				}
				else if(exp->m_type == STRING)
				{
					Output::out("\tla $a0, " + exp->m_location);
					Output::out("\tli $v0, 4");
					Output::out("\tsyscall \t\t#write string");
					std::string temp = exp->m_location;
					temp += ": \t.asciiz ";
					temp += exp->m_value;
					getInstance()->m_strings.push_back(temp);
				}
				else if(exp->m_type == ID)
				{
					if(exp->m_location == "")
					{
						auto tempA = GetElement(exp->m_value);
						if(tempA->m_symbolType == _Var)
						{
							auto varA = dynamic_cast<Var *>(tempA.get());
							if(varA->m_type->m_name == "integer" || varA->m_type->m_name == "INTEGER")
							{
								Output::out("\tlw $a0, " + varA->m_location + "($sp)");
								Output::out("\tli $v0, 1");
								Output::out("\tsyscall \t\t#write expression");
							}
							else if(varA->m_type->m_name == "char" || varA->m_type->m_name == "CHAR")
							{
								Output::out("\tlw $a0, " + varA->m_location + "($sp)");
								Output::out("\tli $v0, 11");
								Output::out("\tsyscall \t\t#write expression");
							}
							else if(varA->m_type->m_name == "string" || varA->m_type->m_name == "STRING")
							{
								Output::out("\tlw $a0, " + varA->m_location + "($sp)");
								Output::out("\tli $v0, 4");
								Output::out("\tsyscall \t\t#write expression");
							}
							else
							{
								std::cout << "TYPE NOT IMPLEMENTED YET";
							}
						}
						else if(tempA->m_symbolType == _Const)
						{
							auto varA = dynamic_cast<Const *>(tempA.get());
							Output::out("\tli $a0, " + varA->m_value);
							Output::out("\tli $v0, 1");
							Output::out("\tsyscall \t\t#write expression");
						}
						else
						{
							std::cout << "SYMBOL NOT IMPLEMENTED YET";
						}
					}
					else
					{
						auto tempA = GetElement(exp->m_value);
						if(tempA->m_symbolType == _Var)
						{
							auto varA = dynamic_cast<Var *>(tempA.get());
							if(varA->m_type->m_name == "integer" || varA->m_type->m_name == "INTEGER")
							{
								Output::out("\tmove $a0, $" + exp->m_location);
								Output::out("\tli $v0, 1");
								Output::out("\tsyscall \t\t#write expression");
								Output::freeRegister(std::stoi(exp->m_location.c_str()));
							}
							else if(varA->m_type->m_name == "char" || varA->m_type->m_name == "CHAR")
							{
								Output::out("\tmove $a0, $" + exp->m_location);
								Output::out("\tli $v0, 11");
								Output::out("\tsyscall \t\t#write expression");
								Output::freeRegister(std::stoi(exp->m_location.c_str()));
							}
							else
							{
								std::cout << "ugh";
							}
						}
						else if(tempA->m_symbolType == _Const)
						{
							auto varA = dynamic_cast<Const *>(tempA.get());
							if(varA->m_type == INT)
							{
								Output::out("\tmove $a0, $" + exp->m_location);
								Output::out("\tli $v0, 1");
								Output::out("\tsyscall \t\t#write expression");
								Output::freeRegister(std::stoi(exp->m_location.c_str()));
							}
							else
							{
								std::cout << "ugh";
							}
						}
						else
						{
							std::cout << "flip!";
						}
					}
				}
				else
				{
					std::cout << "PROBLEMS WRITING CODE" << std::endl;
				}
			}
		}
	}
}

void Table::ReadCode(std::vector<Expression *> * exprList)
{
	if(exprList == 0)
	{

	}
	else
	{
		while(exprList->size() > 0)
		{
			Expression * exp = exprList->back();
			exprList->pop_back();
			if(exp == 0)
			{

			}
			else
			{
				if(exp->m_type == ID)
				{
					auto tempA = GetElement(exp->m_value);
					if(tempA->m_symbolType == _Var)
					{
						auto varA = dynamic_cast<Var *>(tempA.get());
						if(varA->m_type->m_name == "integer" || varA->m_type->m_name == "INTEGER")
						{
							Output::out("\tli $v0, 5");
							Output::out("\tsyscall");
							Output::out("\tsw $v0, " + varA->m_location + "($sp) \t#read expression");
						}
						else if(varA->m_type->m_name == "char" || varA->m_type->m_name == "CHAR")
						{
							Output::out("\tli $v0, 12");
							Output::out("\tsyscall");
							Output::out("\tsw $v0, " + varA->m_location + "($sp) \t#read expression");
						}
						else
						{
							std::cout << "TYPE NOT IMPLEMENTED YET";
						}
					}
					else
					{
						std::cout << "SYMBOL NOT IMPLEMENTED YET";
					}
				}
				else
				{
					std::cout << "PROBLEMS WRITING CODE" << std::endl;
				}
			}
		}
	}
}

void Table::MakeVar(std::vector<std::string>* identList, Type * type)
{
	if(type == 0)
	{

	}
	else
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
}

Const * Table::makeConst(Const * a,symbols sym,Const * b)
{
	if(a == 0 || b == 0)
	{
		return 0;
	}
	else
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
}
int Table::getArraySize(Const *a,Const *b, int size)
{
	if(a == 0 || b == 0)
	{
		return 0;
	}
	else
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
}

Expression * Table::makeExpression(Expression * a, symbols sym, Expression * b)
{
	if(a == 0 || b == 0)
	{
		return 0;
	}
	else
	{
		if(a->m_type == UNKNOWN)
		{
			if(sym == NOT)
			{
				int size = (int)atoi(b->m_value.c_str());
				size = ~size;
				return new Expression(std::to_string(size),b->m_type);
			}
			else if(sym == UNARY)
			{
				int size = (int)atoi(b->m_value.c_str());
				size = -size;
				return new Expression(std::to_string(size),b->m_type);
			}
			else
			{
				std::cout << "CONST ERRORS UNKNOWN SYMBOL" << std::endl;
				exit(-1);
			}
		}
		else if(a->m_location != "" && b->m_location != "")
		{
			int regA = Output::getRegister();
			int regB = Output::getRegister();
			switch(sym)
			{
				case OR:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg1 = Output::getRegister();
					Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					int tempReg2 = Output::getRegister();
					Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
					Output::freeRegister(tempReg1);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
				}
				case AND:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg1 = Output::getRegister();
					Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
					Output::freeRegister(regA);
					int tempReg2 = Output::getRegister();
					Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
					Output::freeRegister(regB);
					int tempReg3 = Output::getRegister();
					Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
					Output::freeRegister(tempReg1);
					Output::freeRegister(tempReg2);
					int tempReg4 = Output::getRegister();
					Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
					Output::freeRegister(tempReg3);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
				}
				case NOT_EQUAL:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				case EQUAL:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				case LESS_EQUAL:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				case GREAT:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				case GREAT_EQUAL:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				case LESS:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				case ADD:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				case SUB:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				case DIV:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				case MOD:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				case MULT:
				{
					Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
					Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
					int tempReg = Output::getRegister();
					Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
					Output::freeRegister(regA);
					Output::freeRegister(regB);
					Output::freeRegister(std::stoi(a->m_location));
					Output::freeRegister(std::stoi(b->m_location));
					return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
				}
				default:
					std::cout << "EXP ERRORS MAKE CONST" << std::endl;
					exit(-1);
			}
		}
		else if(a->m_type == ID && b->m_type == INT || a->m_type == ID && b->m_type == CHAR)
		{
			if(a->m_location == "")
			{
				auto tempA = GetElement(a->m_value);
				if(tempA->m_symbolType == _Var)
				{
					auto varA = dynamic_cast<Var *>(tempA.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Const)
				{
					auto varA = dynamic_cast<Const *>(tempA.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else
				{
					std::cout << "unimplemented Type" << std::endl;
				}
			}
			else
			{
				auto tempA = GetElement(a->m_value);
				if(tempA->m_symbolType == _Var)
				{
					auto varA = dynamic_cast<Var *>(tempA.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Const)
				{
					auto varA = dynamic_cast<Const *>(tempA.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::freeRegister(std::stoi(a->m_location));
							Output::out("\tli $" + std::to_string(regB) + ", " + b->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else
				{
					std::cout << "ID: " << tempA->m_symbolType << " INT: " << b->m_value << " with location" << std::endl;
				}
			}
		}
		else if(a->m_type == INT && b->m_type == ID)
		{
			if(b->m_location == "")
			{
				if(a->m_location == "")
				{
					auto tempB = GetElement(b->m_value);
					if(tempB->m_symbolType == _Var)
					{
						auto varB = dynamic_cast<Var *>(tempB.get());
						int regA = Output::getRegister();
						int regB = Output::getRegister();
						switch(sym)
						{
							case OR:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg1 = Output::getRegister();
								Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								int tempReg2 = Output::getRegister();
								Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
								Output::freeRegister(tempReg1);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg2));
							}
							case AND:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg1 = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
								Output::freeRegister(regA);
								int tempReg2 = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
								Output::freeRegister(regB);
								int tempReg3 = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
								Output::freeRegister(tempReg1);
								Output::freeRegister(tempReg2);
								int tempReg4 = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
								Output::freeRegister(tempReg3);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg4));
							}
							case NOT_EQUAL:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case EQUAL:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case LESS_EQUAL:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case GREAT:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case GREAT_EQUAL:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case LESS:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case ADD:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case SUB:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case DIV:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case MOD:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case MULT:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							default:
								std::cout << "EXP ERRORS MAKE CONST" << std::endl;
								exit(-1);
						}
					}
					else if(tempB->m_symbolType == _Const)
					{
						auto varB = dynamic_cast<Const *>(tempB.get());
						int regA = Output::getRegister();
						int regB = Output::getRegister();
						switch(sym)
						{
							case OR:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg1 = Output::getRegister();
								Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								int tempReg2 = Output::getRegister();
								Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
								Output::freeRegister(tempReg1);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg2));
							}
							case AND:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg1 = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
								Output::freeRegister(regA);
								int tempReg2 = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
								Output::freeRegister(regB);
								int tempReg3 = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
								Output::freeRegister(tempReg1);
								Output::freeRegister(tempReg2);
								int tempReg4 = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
								Output::freeRegister(tempReg3);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg4));
							}
							case NOT_EQUAL:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case EQUAL:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case LESS_EQUAL:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case GREAT:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case GREAT_EQUAL:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case LESS:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case ADD:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case SUB:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case DIV:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case MOD:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case MULT:
							{
								Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							default:
								std::cout << "EXP ERRORS MAKE CONST" << std::endl;
								exit(-1);
						}
					}
				}
				else
				{
					auto tempB = GetElement(b->m_value);
					if(tempB->m_symbolType == _Var)
					{
						auto varB = dynamic_cast<Var *>(tempB.get());
						int regA = Output::getRegister();
						int regB = Output::getRegister();
						switch(sym)
						{
							case OR:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg1 = Output::getRegister();
								Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								int tempReg2 = Output::getRegister();
								Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
								Output::freeRegister(tempReg1);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg2));
							}
							case AND:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg1 = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
								Output::freeRegister(regA);
								int tempReg2 = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
								Output::freeRegister(regB);
								int tempReg3 = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
								Output::freeRegister(tempReg1);
								Output::freeRegister(tempReg2);
								int tempReg4 = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
								Output::freeRegister(tempReg3);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg4));
							}
							case NOT_EQUAL:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case EQUAL:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case LESS_EQUAL:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case GREAT:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case GREAT_EQUAL:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case LESS:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case ADD:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case SUB:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case DIV:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case MOD:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case MULT:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
								int tempReg = Output::getRegister();
								Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							default:
								std::cout << "EXP ERRORS MAKE CONST" << std::endl;
								exit(-1);
						}
					}
					else if(tempB->m_symbolType == _Const)
					{
						auto varB = dynamic_cast<Const *>(tempB.get());
						int regA = Output::getRegister();
						int regB = Output::getRegister();
						switch(sym)
						{
							case OR:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg1 = Output::getRegister();
								Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								int tempReg2 = Output::getRegister();
								Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
								Output::freeRegister(tempReg1);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg2));
							}
							case AND:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg1 = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
								Output::freeRegister(regA);
								int tempReg2 = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
								Output::freeRegister(regB);
								int tempReg3 = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
								Output::freeRegister(tempReg1);
								Output::freeRegister(tempReg2);
								int tempReg4 = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
								Output::freeRegister(tempReg3);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg4));
							}
							case NOT_EQUAL:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case EQUAL:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case LESS_EQUAL:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case GREAT:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case GREAT_EQUAL:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case LESS:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case ADD:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case SUB:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case DIV:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case MOD:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							case MULT:
							{
								Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
								Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
								int tempReg = Output::getRegister();
								Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
								Output::freeRegister(regA);
								Output::freeRegister(regB);
								Output::freeRegister(std::stoi(a->m_location));
								return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
							}
							default:
								std::cout << "EXP ERRORS MAKE CONST" << std::endl;
								exit(-1);
						}
					}
				}
			}
			else
			{
				auto tempB = GetElement(b->m_value);
				if(tempB->m_symbolType == _Var)
				{
					auto varB = dynamic_cast<Var *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempB->m_symbolType == _Const)
				{
					auto varB = dynamic_cast<Const *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + a->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							Output::freeRegister(std::stoi(b->m_location));
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else
				{
					std::cout << "INT: " << a->m_value << " ID: " << tempB->m_symbolType << " with location" << std::endl;
				}
			}
		}
		else if((a->m_type == INT && b->m_type == INT) || (a->m_type == CHAR && b->m_type == CHAR))
		{
			switch(sym)
			{
				case OR:
				{
					int size = (int)atoi(a->m_value.c_str()) ||  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case AND:
				{
					int size = (int)atoi(a->m_value.c_str()) &&  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case NOT_EQUAL:
				{
					int size = (int)atoi(a->m_value.c_str()) !=  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case EQUAL:
				{
					int size = (int)atoi(a->m_value.c_str()) ==  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case LESS_EQUAL:
				{
					int size = (int)atoi(a->m_value.c_str()) <=  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case GREAT:
				{
					int size = (int)atoi(a->m_value.c_str()) >  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case GREAT_EQUAL:
				{
					int size = (int)atoi(a->m_value.c_str()) >=  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case LESS:
				{
					int size = (int)atoi(a->m_value.c_str()) <  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case ADD:
				{
					int size = (int)atoi(a->m_value.c_str()) +  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case SUB:
				{
					int size = (int)atoi(a->m_value.c_str()) -  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case DIV:
				{
					int size = (int)atoi(a->m_value.c_str()) /  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case MOD:
				{
					int size = (int)atoi(a->m_value.c_str()) %  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
				}
				case MULT:
				{
					int size = (int)atoi(a->m_value.c_str()) *  (int)atoi(b->m_value.c_str());
					return new Expression(std::to_string(size), a->m_type);
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
					return new Expression(std::to_string(size), a->m_type);
				}
				case AND:
				{
					int size = a->m_value.length() && a->m_value.length();
					return new Expression(std::to_string(size), a->m_type);
				}
				case NOT_EQUAL:
				{
					int size = a->m_value.length() != a->m_value.length();
					return new Expression(std::to_string(size), a->m_type);
				}
				case EQUAL:
				{
					int size = a->m_value.length() == a->m_value.length();
					return new Expression(std::to_string(size), a->m_type);
				}
				case LESS_EQUAL:
				{
					int size = a->m_value.length() <= a->m_value.length();
					return new Expression(std::to_string(size), a->m_type);
				}
				case GREAT:
				{
					int size = a->m_value.length() > a->m_value.length();
					return new Expression(std::to_string(size), a->m_type);
				}
				case GREAT_EQUAL:
				{
					int size = a->m_value.length() >= a->m_value.length();
					return new Expression(std::to_string(size), a->m_type);
				}
				case LESS:
				{
					int size = a->m_value.length() < a->m_value.length();
					return new Expression(std::to_string(size), a->m_type);
				}
				case ADD:
				{
					std::string size = a->m_value + a->m_value;
					return new Expression(size, a->m_type);
				}
				default:
					std::cout << "CONST ERRORS MAKE CONST" << std::endl;
					exit(-1);
			}
		}
		else if(a->m_type == ID && b->m_type == CHAR)
		{
			std::cout << "char";
		}
		else if(b->m_type == CHAR && b->m_type == ID)
		{
			std::cout << "id";
		}
		else //id symbols were found
		{
			if(a->m_location == "" && b->m_location == "")
			{
				auto tempA = GetElement(a->m_value);
				auto tempB = GetElement(b->m_value);
				if(tempA->m_symbolType == _Var && tempB->m_symbolType == _Var)
				{
					auto varA = dynamic_cast<Var *>(tempA.get());
					auto varB = dynamic_cast<Var *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Const && tempB->m_symbolType == _Const)
				{
					auto varA = dynamic_cast<Const *>(tempA.get());
					auto varB = dynamic_cast<Const *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Var && tempB->m_symbolType == _Const)
				{
					auto varA = dynamic_cast<Var *>(tempA.get());
					auto varB = dynamic_cast<Const *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Const && tempB->m_symbolType == _Var)
				{
					auto varA = dynamic_cast<Const *>(tempA.get());
					auto varB = dynamic_cast<Var *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else
				{
					std::cout << "ID: " << tempA->m_symbolType << " ID: " << tempB->m_symbolType << std::endl;
				}
			}
			else if(a->m_location != "" && b->m_location == "")
			{
				auto tempA = GetElement(a->m_value);
				auto tempB = GetElement(b->m_value);
				if(tempA->m_symbolType == _Var && tempB->m_symbolType == _Var)
				{
					auto varA = dynamic_cast<Var *>(tempA.get());
					auto varB = dynamic_cast<Var *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Const && tempB->m_symbolType == _Const)
				{
					auto varA = dynamic_cast<Const *>(tempA.get());
					auto varB = dynamic_cast<Const *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Var && tempB->m_symbolType == _Const)
				{
					auto varA = dynamic_cast<Var *>(tempA.get());
					auto varB = dynamic_cast<Const *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Const && tempB->m_symbolType == _Var)
				{
					auto varA = dynamic_cast<Const *>(tempA.get());
					auto varB = dynamic_cast<Var *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
							Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(a->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else
				{
					std::cout << "ID: " << tempA->m_symbolType << " ID: " << tempB->m_symbolType << std::endl;
				}
			}
			else if(a->m_location == "" && b->m_location != "")
			{
				auto tempA = GetElement(a->m_value);
				auto tempB = GetElement(b->m_value);
				if(tempA->m_symbolType == _Var && tempB->m_symbolType == _Var)
				{
					auto varA = dynamic_cast<Var *>(tempA.get());
					auto varB = dynamic_cast<Var *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Const && tempB->m_symbolType == _Const)
				{
					auto varA = dynamic_cast<Const *>(tempA.get());
					auto varB = dynamic_cast<Const *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Var && tempB->m_symbolType == _Const)
				{
					auto varA = dynamic_cast<Var *>(tempA.get());
					auto varB = dynamic_cast<Const *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else if(tempA->m_symbolType == _Const && tempB->m_symbolType == _Var)
				{
					auto varA = dynamic_cast<Const *>(tempA.get());
					auto varB = dynamic_cast<Var *>(tempB.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					switch(sym)
					{
						case OR:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg1 = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							int tempReg2 = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
							Output::freeRegister(tempReg1);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg2));
						}
						case AND:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg1 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
							Output::freeRegister(regA);
							int tempReg2 = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
							Output::freeRegister(regB);
							int tempReg3 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
							Output::freeRegister(tempReg1);
							Output::freeRegister(tempReg2);
							int tempReg4 = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
							Output::freeRegister(tempReg3);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg4));
						}
						case NOT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case LESS_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case GREAT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case GREAT_EQUAL:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case LESS:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case ADD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case SUB:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case DIV:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case MOD:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						case MULT:
						{
							Output::out("\tli $" + std::to_string(regA) + ", " + varA->m_value);
							Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
							int tempReg = Output::getRegister();
							Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
							Output::freeRegister(regA);
							Output::freeRegister(regB);
							Output::freeRegister(std::stoi(b->m_location));
							return new Expression(b->m_value, b->m_type, std::to_string(tempReg));
						}
						default:
							std::cout << "EXP ERRORS MAKE CONST" << std::endl;
							exit(-1);
					}
				}
				else
				{
					std::cout << "ID: " << tempA->m_symbolType << " ID: " << tempB->m_symbolType << std::endl;
				}
			}
			else
			{
				int regA = Output::getRegister();
				int regB = Output::getRegister();
				switch(sym)
				{
					case OR:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg1 = Output::getRegister();
						Output::out("\tadd $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB));
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						int tempReg2 = Output::getRegister();
						Output::out("\tsgt $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1) + ", 0");
						Output::freeRegister(tempReg1);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg2));
					}
					case AND:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg1 = Output::getRegister();
						Output::out("\tsne $" + std::to_string(tempReg1) + ", $" + std::to_string(regA) + ", 0");
						Output::freeRegister(regA);
						int tempReg2 = Output::getRegister();
						Output::out("\tsne $" + std::to_string(tempReg2) + ", $" + std::to_string(regB) + ", 0");
						Output::freeRegister(regB);
						int tempReg3 = Output::getRegister();
						Output::out("\tseq $" + std::to_string(tempReg3) + ", $" + std::to_string(tempReg2) + ", $" + std::to_string(tempReg1));
						Output::freeRegister(tempReg1);
						Output::freeRegister(tempReg2);
						int tempReg4 = Output::getRegister();
						Output::out("\tseq $" + std::to_string(tempReg4) + ", $" + std::to_string(tempReg3) + ", 1 \t#and expression");
						Output::freeRegister(tempReg3);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg4));
					}
					case NOT_EQUAL:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\tsne $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#not equal expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					case EQUAL:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\tseq $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#equal expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					case LESS_EQUAL:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\tsle $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less equal expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					case GREAT:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\tsgt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					case GREAT_EQUAL:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\tsge $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#great equal expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					case LESS:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\tslt $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#less expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					case ADD:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					case SUB:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#sub expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					case DIV:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\tdiv $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#div expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					case MOD:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\trem $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mod expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					case MULT:
					{
						Output::out("\tmove $" + std::to_string(regA) + ", $" + a->m_location);
						Output::out("\tmove $" + std::to_string(regB) + ", $" + b->m_location);
						int tempReg = Output::getRegister();
						Output::out("\tmul $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#mul expressions");
						Output::freeRegister(regA);
						Output::freeRegister(regB);
						Output::freeRegister(std::stoi(a->m_location));
						Output::freeRegister(std::stoi(b->m_location));
						return new Expression(a->m_value, a->m_type, std::to_string(tempReg));
					}
					default:
						std::cout << "EXP ERRORS MAKE CONST" << std::endl;
						exit(-1);
				}
			}
		}
	}
}

void Table::MakeConst(std::string element, Const * type)
{
	if(type == 0)
	{

	}
	else
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
}

int Table::getSize(Const * a)
{
	if(a == 0)
	{
		return 0;
	}
	else
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
}

SimpleType * Table::MakeSimple(std::string id)
{
	auto temp = GetElement(id);
	if(temp->m_name == "EMPTY")
		return new SimpleType(id, 4, id);

	auto newTemp = dynamic_cast<Type *>(temp.get());
	return new SimpleType(id, newTemp->m_size, id);
}


void Table::Assign(Expression * lVal, Expression * rVal)
{
	if(lVal == 0 || rVal == 0)
	{
		std::cout << "errors" << std::endl;
		exit(-1);
	}
	if(lVal->m_value == "ARRAYRETURN")
	{
		if(rVal->m_location != "")
		{
			int regA = Output::getRegister();
			Output::out("\tmove $" + std::to_string(regA) + ", $" + rVal->m_location);
			Output::out("\tsw $" + std::to_string(regA) + ", 0($25)");
			Output::freeRegister(regA);
			Output::freeRegister(std::stoi(rVal->m_location));
			Output::freeRegister(std::stoi(lVal->m_location));
		}
		else if(rVal->m_value != "")
		{
			if((rVal->m_type == INT && lVal->m_type == INT) || (rVal->m_type == CHAR && lVal->m_type == CHAR))
			{
				int regA = Output::getRegister();
				Output::out("\tli $" + std::to_string(regA) + ", " + rVal->m_value);
				Output::out("\tsw $" + std::to_string(regA) + ", 0($25)");
				Output::freeRegister(regA);
				Output::freeRegister(std::stoi(lVal->m_location));
			}
			else if(rVal->m_type == ID)
			{
				auto temp = GetElement(rVal->m_value);
				if(temp->m_symbolType == _Var)
				{
					auto newRVal = dynamic_cast<Var *>(temp.get());
					int regA = Output::getRegister();
					Output::out("\tlw $" + std::to_string(regA) + ", " + newRVal->m_location + "($sp)");
					Output::out("\tsw $" + std::to_string(regA) + ", 0($25)");
					Output::freeRegister(regA);
					Output::freeRegister(std::stoi(lVal->m_location));
				}
				else if(temp->m_symbolType == _Const)
				{
					auto newRVal = dynamic_cast<Const *>(temp.get());
					int regA = Output::getRegister();
					Output::out("\tli $" + std::to_string(regA) + ", " + newRVal->m_value);
					Output::out("\tsw $" + std::to_string(regA) + ", 0($25)");
					Output::freeRegister(regA);
					Output::freeRegister(std::stoi(lVal->m_location));
				}
				else
				{
					std::cout << "FLIP" << std::endl;
				}
			}
		}
		else
		{
			std::cout << "here.." << std::endl;
		}
	}
	else
	{
		auto temp = GetElement(lVal->m_value);
		if(temp->m_symbolType == _Var)
		{
			if(lVal->m_location == "" && rVal->m_location == "" && rVal->m_type == ID && lVal->m_type == ID)
			{
				auto newLVal = dynamic_cast<Var *>(temp.get());
				auto temp2 = GetElement(rVal->m_value);
				if(temp2->m_symbolType == _Var)
				{
					auto newRVal = dynamic_cast<Var *>(temp2.get());
					int regA = Output::getRegister();
					Output::out("\tlw $" + std::to_string(regA) + ", " + newRVal->m_location + "($sp)");
					Output::out("\tsw $" + std::to_string(regA) + ", " + newLVal->m_location + "($sp) \t#assign value");
					Output::freeRegister(regA);
				}
				else
				{
					auto newRVal = dynamic_cast<Const *>(temp2.get());
					int regA = Output::getRegister();
					Output::out("\tli $" + std::to_string(regA) + ", " + newRVal->m_value);
					Output::out("\tsw $" + std::to_string(regA) + ", " + newLVal->m_location + "($sp) \t#assign value");
					Output::freeRegister(regA);
				}
			}
			else if(lVal->m_location == "")
			{
				auto newTemp = dynamic_cast<Var *>(temp.get());
				if(rVal->m_value != "")
				{
					if((newTemp->m_type->m_name == "integer" && rVal->m_type == INT) || (newTemp->m_type->m_name == "INTEGER" && rVal->m_type == INT))
					{
						int regA = Output::getRegister();
						Output::out("\tli $" + std::to_string(regA) + ", " + rVal->m_value);
						Output::out("\tsw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp) \t#assign value");
						Output::freeRegister(regA);
					}
					else if((newTemp->m_type->m_name == "integer" && rVal->m_type == ID) || (newTemp->m_type->m_name == "INTEGER" && rVal->m_type == ID))
					{
						auto temp1 = GetElement(rVal->m_value);
						if(temp1->m_symbolType == _Var)
						{
							Output::out("\tsw $" + rVal->m_location + ", " + newTemp->m_location + "($sp) \t#assign value");
							Output::freeRegister(std::stoi(rVal->m_location));
						}
						else if(temp1->m_symbolType == _Const)
						{
							auto temp2 = dynamic_cast<Const *>(temp1.get());
							int regA = Output::getRegister();
							Output::out("\tli $" + std::to_string(regA) + ", " + temp2->m_value);
							Output::out("\tsw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp) \t#assign value");
							Output::freeRegister(regA);
						}
						else
						{
							std::cout << newTemp->m_type->m_name << " needs to be implemented still" << std::endl;
						}
					}
					else if((newTemp->m_type->m_name == "char" && rVal->m_type == ID) || (newTemp->m_type->m_name == "CHAR" && rVal->m_type == ID))
					{
						auto temp1 = GetElement(rVal->m_value);
						if(temp1->m_symbolType == _Var)
						{
							Output::out("\tsw $" + rVal->m_location + ", " + newTemp->m_location + "($sp) \t#assign value");
							Output::freeRegister(std::stoi(rVal->m_location));
						}
						else if(temp1->m_symbolType == _Const)
						{
							auto temp2 = dynamic_cast<Const *>(temp1.get());
							int regA = Output::getRegister();
							Output::out("\tli $" + std::to_string(regA) + ", " + temp2->m_value);
							Output::out("\tsw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp) \t#assign value");
							Output::freeRegister(regA);
						}
						else
						{
							std::cout << newTemp->m_type->m_name << " needs to be implemented still" << std::endl;
						}
					}
					else if((newTemp->m_type->m_name == "char" && rVal->m_type == CHAR) || (newTemp->m_type->m_name == "CHAR" && rVal->m_type == CHAR))
					{
						int regA = Output::getRegister();
						Output::out("\tli $" + std::to_string(regA) + ", " + rVal->m_value);
						Output::out("\tsw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp) \t#assign value");
						Output::freeRegister(regA);
					}
					else if((newTemp->m_type->m_name == "string" && rVal->m_type == STRING) || (newTemp->m_type->m_name == "STRING" && rVal->m_type == STRING))
					{
						int regA = Output::getRegister();
						Output::out("\tla $" + std::to_string(regA) + ", " + rVal->m_location);
						Output::out("\tsw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp) \t#assign value");
						std::string temp = rVal->m_location;
						temp += ": \t.asciiz ";
						temp += rVal->m_value;
						getInstance()->m_strings.push_back(temp);
						Output::freeRegister(regA);
					}
					else
					{
						std::cout <<"assign error";
					}
				}
				else
				{
					Output::out("\tsw $" + rVal->m_location + ", " + newTemp->m_location + "($sp) \t#assign value");
					Output::freeRegister(std::stoi(rVal->m_location));
				}
			}
			else
			{
				auto newTemp = dynamic_cast<Var *>(temp.get());
				if((newTemp->m_type->m_name == "integer" && rVal->m_type == INT) || (newTemp->m_type->m_name == "INTEGER" && rVal->m_type == INT))
				{
					int regA = Output::getRegister();
					Output::out("\tli $" + std::to_string(regA) + ", " + rVal->m_value);
					Output::out("\tsw $" + std::to_string(regA) + ", " + lVal->m_location + "($sp) \t#assign value");
					Output::freeRegister(regA);
				}
				else if((newTemp->m_type->m_name == "integer" && rVal->m_type == ID) || (newTemp->m_type->m_name == "INTEGER" && rVal->m_type == ID))
				{
					auto temp1 = GetElement(rVal->m_value);
					if(temp1->m_symbolType == _Var)
					{
						Output::out("\tsw $" + rVal->m_location + ", " + lVal->m_location + "($sp) \t#assign value");
						Output::freeRegister(std::stoi(rVal->m_location));
					}
					else if(temp1->m_symbolType == _Const)
					{
						auto temp2 = dynamic_cast<Const *>(temp1.get());
						int regA = Output::getRegister();
						Output::out("\tli $" + std::to_string(regA) + ", " + temp2->m_value);
						Output::out("\tsw $" + std::to_string(regA) + ", " + lVal->m_location + "($sp) \t#assign value");
						Output::freeRegister(regA);
					}
					else
					{
						std::cout << newTemp->m_type->m_name << " needs to be implemented still" << std::endl;
					}
				}
			}
		}
		else
		{
			std::cout << "assign error" << std::endl;
		}
	}
}

void Table::MakeFirstIf(Expression * a)
{
	if(a == 0)
	{

	}
	else
	{
		if(a->m_type == ID)
		{
			if(a->m_location != "")
			{
				ifVec.push_back(m_ifCount);
				endVec.push_back(m_ifCount++);
				Output::out("\tbeq $" + a->m_location + ", 0, ELSEIF" + std::to_string(ifVec.back()));
				Output::freeRegister(std::stoi(a->m_location));
			}
			else
			{
				auto temp = GetElement(a->m_value);
				if(temp->m_symbolType == _Var)
				{
					ifVec.push_back(m_ifCount);
					endVec.push_back(m_ifCount++);
					int regA = Output::getRegister();
					auto newTemp = dynamic_cast<Var *>(temp.get());
					Output::out("\tlw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp)");
					Output::out("\tbeq $" + std::to_string(regA) + ", 0, ELSEIF" + std::to_string(ifVec.back()));
					Output::freeRegister(regA);
				}
				else
				{
					std::cout << "unimplemented methods" << std::endl;
				}
			}
		}
		else
		{
			ifVec.push_back(m_ifCount);
			endVec.push_back(m_ifCount++);
			Output::out("\tbeq " + a->m_value + ", 0, ELSEIF" + std::to_string(ifVec.back()));
		}
	}
}

void Table::MakeIf(Expression * a)
{
	if(a == 0)
	{

	}
	else
	{
		if(a->m_type == ID)
		{
			if(a->m_location != "")
			{
				ifVec.push_back(m_ifCount++);
				Output::out("\tbeq $" + a->m_location + ", 0, ELSEIF" + std::to_string(ifVec.back()));
				Output::freeRegister(std::stoi(a->m_location));
			}
			else
			{
				auto temp = GetElement(a->m_value);
				if(temp->m_symbolType == _Var)
				{
					ifVec.push_back(m_ifCount++);
					int regA = Output::getRegister();
					auto newTemp = dynamic_cast<Var *>(temp.get());
					Output::out("\tlw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp)");
					Output::out("\tbeq $" + std::to_string(regA) + ", 0, ELSEIF" + std::to_string(ifVec.back()));
					Output::freeRegister(regA);
				}
				else
				{
					std::cout << "unimplemented methods" << std::endl;
				}
			}
		}
		else
		{
			ifVec.push_back(m_ifCount++);
			Output::out("\tbeq " + a->m_value + ", 0, ELSEIF" + std::to_string(ifVec.back()));
		}
	}
}

void Table::MakeElse()
{
	if(ifVec.size() > 0)
	{
		Output::out("\tj ENDIF" + std::to_string(endVec.back()));
		Output::out("ELSEIF" + std::to_string(ifVec.back()) + ":");
		ifVec.pop_back();
	}
}

void Table::MakeEndIf()
{
	if(endVec.size() > 0)
	{
		Output::out("ENDIF" + std::to_string(endVec.back()) + ":");
		endVec.pop_back();
	}
}

void Table::MakeEndIf2()
{
	if(ifVec.size() > 0)
	{
		Output::out("ELSEIF" + std::to_string(ifVec.back()) + ":");
		ifVec.pop_back();
	}
	if(endVec.size() > 0)
	{
		Output::out("ENDIF" + std::to_string(endVec.back()) + ":");
		endVec.pop_back();
	}
}

void Table::MakeWhileBegin(Expression * a)
{
	if(a == 0)
	{

	}
	else
	{
		if(a->m_type == ID)
		{
			if(a->m_location != "")
			{
				Output::out("\tbeq $" + a->m_location + ", 0, ENDWHILE" + std::to_string(whileVec.back()));
				Output::freeRegister(std::stoi(a->m_location));
			}
			else
			{
				auto temp = GetElement(a->m_value);
				if(temp->m_symbolType == _Var)
				{
					int regA = Output::getRegister();
					auto newTemp = dynamic_cast<Var *>(temp.get());
					Output::out("\tlw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp)");
					Output::out("\tbeq $" + std::to_string(regA) + ", 0, ENDWHILE" + std::to_string(whileVec.back()));
					Output::freeRegister(std::stoi(newTemp->m_location));
					Output::freeRegister(regA);
				}
				else
				{
					std::cout << "unimplemented methods" << std::endl;
				}
			}
		}
		else
		{
			Output::out("\tbeq $" + a->m_location + ", 0, ENDWHILE" + std::to_string(whileVec.back()));
			Output::freeRegister(std::stoi(a->m_location));
		}
	}
}

void Table::MakeWhileEnd()
{
	if(whileVec.size() > 0)
	{
		Output::out("\tj WHILE" + std::to_string(whileVec.back()));
		Output::out("ENDWHILE" + std::to_string(whileVec.back()) + ":");
		whileVec.pop_back();
	}
}

void Table::MakeWhilePre()
{
	whileVec.push_back(m_ifCount++);
	Output::out("WHILE" + std::to_string(whileVec.back()) + ":");
}

void Table::MakeRepeatPre()
{
	repeatVec.push_back(m_repeatCount++);
	Output::out("REPEAT" + std::to_string(repeatVec.back()) + ":");
}

void Table::MakeRepeatEnd(Expression * a)
{
	if(a == 0)
	{

	}
	else
	{
		if(a->m_type == ID)
		{
			if(a->m_location != "")
			{
				Output::out("\tbeq $" + a->m_location + ", 0, REPEAT" + std::to_string(repeatVec.back()));
				Output::freeRegister(std::stoi(a->m_location));
				repeatVec.pop_back();
			}
			else
			{
				auto temp = GetElement(a->m_value);
				if(temp->m_symbolType == _Var)
				{
					int regA = Output::getRegister();
					auto newTemp = dynamic_cast<Var *>(temp.get());
					Output::out("\tlw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp)");
					Output::out("\tbeq $" + std::to_string(regA) + ", 0, REPEAT" + std::to_string(repeatVec.back()));
					Output::freeRegister(std::stoi(newTemp->m_location));
					Output::freeRegister(regA);
					repeatVec.pop_back();
				}
				else
				{
					std::cout << "unimplemented methods" << std::endl;
				}
			}
		}
		else
		{
			Output::out("\tbeq $" + a->m_location + ", 0, REPEAT" + std::to_string(repeatVec.back()));
			Output::freeRegister(std::stoi(a->m_location));
			repeatVec.pop_back();
		}
	}
}

char * Table::MakeForBegin(char * id, Expression * rVal)
{
	if(id == 0 || rVal == 0)
	{
		return 0;
	}
	else
	{
		auto temp = GetElement(id);
		if(temp->m_symbolType == _Var)
		{
			auto newTemp = dynamic_cast<Var *>(temp.get());
			if((newTemp->m_type->m_name == "integer" && rVal->m_type == INT) || (newTemp->m_type->m_name == "INTEGER" && rVal->m_type == INT))
			{
				int regA = Output::getRegister();
				Output::out("\tli $" + std::to_string(regA) + ", " + rVal->m_value);
				Output::out("\tsw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp) \t#assign value");
				Output::freeRegister(regA);
			}
			else if((newTemp->m_type->m_name == "integer" && rVal->m_type == ID) || (newTemp->m_type->m_name == "INTEGER" && rVal->m_type == ID))
			{
				auto temp1 = GetElement(rVal->m_value);
				if(rVal->m_location == "")
				{
					if(temp1->m_symbolType == _Var)
					{
						auto temp2 = dynamic_cast<Var *>(temp1.get());
						int regA = Output::getRegister();
						Output::out("\tlw $" + std::to_string(regA) + ", " + temp2->m_location + "($sp)");
						Output::out("\tsw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp) \t#assign value");
						Output::freeRegister(regA);
					}
					else if(temp1->m_symbolType == _Const)
					{
						auto temp2 = dynamic_cast<Const *>(temp1.get());
						int regA = Output::getRegister();
						Output::out("\tli $" + std::to_string(regA) + ", " + temp2->m_value);
						Output::out("\tsw $" + std::to_string(regA) + ", " + newTemp->m_location + "($sp) \t#assign value");
						Output::freeRegister(regA);
					}
					else
					{
						std::cout << newTemp->m_type->m_name << " needs to be implemented still" << std::endl;
					}
				}
				else
				{
					if(temp1->m_symbolType == _Var)
					{
						Output::out("\tsw $" + rVal->m_location + ", " + newTemp->m_location + "($sp) \t#assign value");
						Output::freeRegister(std::stoi(rVal->m_location));
					}
					else if(temp1->m_symbolType == _Const)
					{
						Output::out("\tsw $" + rVal->m_location + ", " + newTemp->m_location + "($sp) \t#assign value");
						Output::freeRegister(std::stoi(rVal->m_location));
					}
					else
					{
						std::cout << newTemp->m_type->m_name << " needs to be implemented still" << std::endl;
					}
				}
			}
			else
			{
				std::cout << newTemp->m_type->m_name << " needs to be implemented still" << std::endl;
			}
		}
		else
		{
			std::cout << "assign error" << std::endl;
		}
		return id;
	}
}

//assign is going to have the new expression stored in it, a will be a var or constant, could also be stored in a reg
void Table::MakeForTo(char * assign, Expression * a)
{
	if(assign == 0 || a == 0)
	{

	}
	else
	{
		//first need to write a label
		forVec.push_back(m_forCount++);
		Output::out("FOR" + std::to_string(forVec.back()) + ":");
		auto temp = GetElement(assign);
		if(temp->m_symbolType == _Var)
		{
			auto varA = dynamic_cast<Var *>(temp.get());
			if(a->m_type == ID)
			{
				auto temp2 = GetElement(a->m_value);
				if(temp2->m_symbolType == _Const)
				{
					auto varB = dynamic_cast<Const *>(temp2.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
					Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
					Output::out("\tbgt $" + std::to_string(regA) + ", $" + std::to_string(regB) + ", FOREND" + std::to_string(forVec.back()));
					Output::freeRegister(regA);
					Output::freeRegister(regB);
				}
				else if(temp2->m_symbolType == _Var)
				{
					auto varB = dynamic_cast<Var *>(temp2.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
					Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
					Output::out("\tbgt $" + std::to_string(regA) + ", $" + std::to_string(regB) + ", FOREND" + std::to_string(forVec.back()));
					Output::freeRegister(regA);
					Output::freeRegister(regB);
				}
				else
				{
					std::cout << "ugh";
				}
			}
			else if(a->m_type == INT)
			{
				int regA = Output::getRegister();
				int regB = Output::getRegister();
				Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
				Output::out("\tli $" + std::to_string(regB) + ", " + a->m_value);
				Output::out("\tbgt $" + std::to_string(regA) + ", $" + std::to_string(regB) + ", FOREND" + std::to_string(forVec.back()));
				Output::freeRegister(regA);
				Output::freeRegister(regB);
			}
			else
			{
				std::cout << "ugh";
			}
		}
		else
		{
			std::cout << "UGH";
		}
	}
}

//assign is going to have the new expression stored in it, a will be a var or constant, could also be stored in a reg
void Table::MakeForDownTo(char * assign, Expression * a)
{
	if(assign == 0 || a == 0)
	{

	}
	else
	{
		//first need to write a label
		forVec.push_back(m_forCount++);
		Output::out("FOR" + std::to_string(forVec.back()) + ":");
		auto temp = GetElement(assign);
		if(temp->m_symbolType == _Var)
		{
			auto varA = dynamic_cast<Var *>(temp.get());
			if(a->m_type == ID)
			{
				auto temp2 = GetElement(a->m_value);
				if(temp2->m_symbolType == _Const)
				{
					auto varB = dynamic_cast<Const *>(temp2.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
					Output::out("\tli $" + std::to_string(regB) + ", " + varB->m_value);
					Output::out("\tblt $" + std::to_string(regA) + ", $" + std::to_string(regB) + ", FOREND" + std::to_string(forVec.back()));
					Output::freeRegister(regA);
					Output::freeRegister(regB);
				}
				else if(temp2->m_symbolType == _Var)
				{
					auto varB = dynamic_cast<Var *>(temp2.get());
					int regA = Output::getRegister();
					int regB = Output::getRegister();
					Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
					Output::out("\tlw $" + std::to_string(regB) + ", " + varB->m_location + "($sp)");
					Output::out("\tblt $" + std::to_string(regA) + ", $" + std::to_string(regB) + ", FOREND" + std::to_string(forVec.back()));
					Output::freeRegister(regA);
					Output::freeRegister(regB);
				}
				else
				{
					std::cout << "ugh";
				}
			}
			else if(a->m_type == INT)
			{
				int regA = Output::getRegister();
				int regB = Output::getRegister();
				Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
				Output::out("\tli $" + std::to_string(regB) + ", " + a->m_value);
				Output::out("\tblt $" + std::to_string(regA) + ", $" + std::to_string(regB) + ", FOREND" + std::to_string(forVec.back()));
				Output::freeRegister(regA);
				Output::freeRegister(regB);
			}
			else
			{
				std::cout << "ugh";
			}
		}
		else
		{
			std::cout << "UGH";
		}
	}
}

void Table::MakeForDownToEnd(char * assign)
{
	if(assign == 0)
	{

	}
	else
	{
		auto temp = GetElement(assign);
		if(temp->m_symbolType == _Var)
		{
			auto varA = dynamic_cast<Var *>(temp.get());
			int regA = Output::getRegister();
			int regB = Output::getRegister();
			int tempReg = Output::getRegister();
			Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
			Output::out("\tli $" + std::to_string(regB) + ", 1");
			Output::out("\tsub $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
			Output::out("\tsw $" + std::to_string(tempReg) + ", " + varA->m_location + "($sp) \t#assign value");
			Output::out("\tj FOR" + std::to_string(forVec.back()));
			Output::freeRegister(regA);
			Output::freeRegister(regB);
			Output::freeRegister(tempReg);
			Output::out("FOREND" + std::to_string(forVec.back()) + ":");
			forVec.pop_back();
		}
		else
		{
			std::cout << "UGH";
		}
	}
}

void Table::MakeForToEnd(char * assign)
{
	if(assign == 0)
	{

	}
	else
	{
		auto temp = GetElement(assign);
		if(temp->m_symbolType == _Var)
		{
			auto varA = dynamic_cast<Var *>(temp.get());
			int regA = Output::getRegister();
			int regB = Output::getRegister();
			int tempReg = Output::getRegister();
			Output::out("\tlw $" + std::to_string(regA) + ", " + varA->m_location + "($sp)");
			Output::out("\tli $" + std::to_string(regB) + ", 1");
			Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + std::to_string(regB) +" \t#add expressions");
			Output::out("\tsw $" + std::to_string(tempReg) + ", " + varA->m_location + "($sp) \t#assign value");
			Output::out("\tj FOR" + std::to_string(forVec.back()));
			Output::freeRegister(regA);
			Output::freeRegister(regB);
			Output::freeRegister(tempReg);
			Output::out("FOREND" + std::to_string(forVec.back()) + ":");
			forVec.pop_back();
		}
		else
		{
			std::cout << "UGH";
		}
	}
}

void Table::MakeProcedureCall(std::vector<Expression *> * exprList, char * id)
{
	auto temp = GetElement(id);
	if(temp->m_symbolType == _Function)
	{
		auto func = dynamic_cast<Function *>(temp.get());
		if(exprList == 0)
		{
			Output::out("\tjal " + func->m_location);
		}
		else
		{
			std::vector<Expression *> newList(exprList->begin(), exprList->end());
			int currentSize = func->m_size + 4;
			currentSize = -currentSize;
			for(int i = newList.size() - 1; i >= 0; --i)
			{
				//this is where we write the code for each item on the stack
				auto temp = newList[i];
				if(!temp)
				{
					std::cout << "User defined types not implemented";
				}
				else
				{
					if(temp->m_location != "")
					{
						Output::out("\tsw $" + temp->m_location + ", " + std::to_string(currentSize) + "($sp)");
						currentSize += 4;
						Output::freeRegister(std::stoi(temp->m_location));
					}
					else
					{
						if(temp->m_type == ID)
						{
							auto sym = GetElement(temp->m_value);
							if(sym->m_symbolType == _Var)
							{
								auto var = dynamic_cast<Var *>(sym.get());
								int regA = Output::getRegister();
								Output::out("\tlw $" + std::to_string(regA) + ", " + var->m_location + "($sp)");
								Output::out("\tsw $" + std::to_string(regA) + ", " + std::to_string(currentSize) + "($sp)");
								Output::freeRegister(regA);
								currentSize += 4;

							}
							else if(sym->m_symbolType == _Const)
							{
								auto var = dynamic_cast<Const *>(sym.get());
								int regA = Output::getRegister();
								if(var->m_type == STRING)
									Output::out("\tla $" + std::to_string(regA) + ", " + var->m_value);
								else if(var->m_type == INT || var->m_type == CHAR)
									Output::out("\tli $" + std::to_string(regA) + ", " + var->m_value);
								Output::out("\tsw $" + std::to_string(regA) + ", " + std::to_string(currentSize) + "($sp)");
								Output::freeRegister(regA);
								currentSize += 4;
							}
							else
							{
								std::cout << "unimplemented procedure call";
							}

						}
						else
						{
							int regA = Output::getRegister();
							if(temp->m_type == STRING)
								Output::out("\tla $" + std::to_string(regA) + ", " + temp->m_value);
							else if(temp->m_type == INT || temp->m_type == CHAR)
								Output::out("\tli $" + std::to_string(regA) + ", " + temp->m_value);
							Output::out("\tsw $" + std::to_string(regA) + ", " + std::to_string(currentSize) + "($sp)");
							Output::freeRegister(regA);
							currentSize += 4;
						}
					}
				}
			}
			Output::out("\tjal " + func->m_location);
		}
	}
}

Expression * Table::MakeFunctionCall(std::vector<Expression *> * exprList, char * id)
{
	auto temp = GetElement(id);
	if(temp->m_symbolType == _Function)
	{
		auto func = dynamic_cast<Function *>(temp.get());
		if(exprList == 0)
		{
			Output::out("\tjal " + func->m_location);
			int regA = Output::getRegister();
			Output::out("\tmove $" + std::to_string(regA) + ", $v0");
			auto simple = dynamic_cast<SimpleType *>(func->m_returnType.get());
			if(!simple)
				exit(-1);
			if(simple->m_type == "integer" || simple->m_type == "INTEGER")
				return new Expression("",INT,std::to_string(regA));
			else if(simple->m_type == "char" || simple->m_type == "CHAR")
				return new Expression("",CHAR,std::to_string(regA));
			else if(simple->m_type == "string" || simple->m_type == "STRING")
				return new Expression("",STRING,std::to_string(regA));
			else if(simple->m_type == "boolean" || simple->m_type == "BOOLEAN")
				return new Expression("",INT,std::to_string(regA));
			else
				return new Expression("",UNKNOWN,std::to_string(regA));
		}
		else
		{
			std::vector<Expression *> newList(exprList->begin(), exprList->end());
			int currentSize = func->m_size + 4;
			currentSize = -currentSize;
			for(int i = newList.size() - 1; i >= 0; --i)
			{
				//this is where we write the code for each item on the stack
				auto temp = newList[i];
				if(!temp)
				{
					std::cout << "User defined types not implemented";
				}
				else
				{
					if(temp->m_location != "")
					{
						Output::out("\tsw $" + temp->m_location + ", " + std::to_string(currentSize) + "($sp)");
						currentSize += 4;
						Output::freeRegister(std::stoi(temp->m_location));
					}
					else
					{
						if(temp->m_type == ID)
						{
							auto sym = GetElement(temp->m_value);
							if(sym->m_symbolType == _Var)
							{
								auto var = dynamic_cast<Var *>(sym.get());
								int regA = Output::getRegister();
								Output::out("\tlw $" + std::to_string(regA) + ", " + var->m_location + "($sp)");
								Output::out("\tsw $" + std::to_string(regA) + ", " + std::to_string(currentSize) + "($sp)");
								Output::freeRegister(regA);
								currentSize += 4;

							}
							else if(sym->m_symbolType == _Const)
							{
								auto var = dynamic_cast<Const *>(sym.get());
								int regA = Output::getRegister();
								if(var->m_type == STRING)
									Output::out("\tla $" + std::to_string(regA) + ", " + var->m_value);
								else if(var->m_type == INT || var->m_type == CHAR)
									Output::out("\tli $" + std::to_string(regA) + ", " + var->m_value);
								Output::out("\tsw $" + std::to_string(regA) + ", " + std::to_string(currentSize) + "($sp)");
								Output::freeRegister(regA);
								currentSize += 4;
							}
							else
							{
								std::cout << "unimplemented procedure call";
							}

						}
						else
						{
							int regA = Output::getRegister();
							if(temp->m_type == STRING)
								Output::out("\tla $" + std::to_string(regA) + ", " + temp->m_value);
							else if(temp->m_type == INT || temp->m_type == CHAR)
								Output::out("\tli $" + std::to_string(regA) + ", " + temp->m_value);
							Output::out("\tsw $" + std::to_string(regA) + ", " + std::to_string(currentSize) + "($sp)");
							Output::freeRegister(regA);
							currentSize += 4;
						}
					}
				}
			}
			Output::out("\tjal " + func->m_location);
			int regA = Output::getRegister();
			Output::out("\tmove $" + std::to_string(regA) + ", $v0");
			auto simple = dynamic_cast<SimpleType *>(func->m_returnType.get());
			if(!simple)
				exit(-1);
			if(simple->m_type == "integer" || simple->m_type == "INTEGER")
				return new Expression("",INT,std::to_string(regA));
			else if(simple->m_type == "char" || simple->m_type == "CHAR")
				return new Expression("",CHAR,std::to_string(regA));
			else if(simple->m_type == "string" || simple->m_type == "STRING")
				return new Expression("",STRING,std::to_string(regA));
			else if(simple->m_type == "boolean" || simple->m_type == "BOOLEAN")
				return new Expression("",INT,std::to_string(regA));
			else
				return new Expression("",UNKNOWN,std::to_string(regA));
		}
	}
}

int Table::GetFrameSize()
{
	int size = 0;
	//Table::PrintScope();
	std::for_each(getInstance()->m_table[getInstance()->m_scope].begin(), getInstance()->m_table[getInstance()->m_scope].end(), [&](std::pair<std::string, Element> sym)
	{
		if(sym.second->m_symbolType == _Var)
		{
			auto temp = dynamic_cast<Var *>(sym.second.get());
			size += temp->m_type->m_size;
			//std::cout << "name: " << sym.first << " size_var: " << temp->m_type->m_size << std::endl;
		}
		else if(sym.second->m_symbolType == _Const)
		{
			auto temp = dynamic_cast<Const *>(sym.second.get());
			if(temp->m_type == ID)
			{
				auto var = GetElement(temp->m_value);
				if(var->m_symbolType == _Array)
				{
					auto rec = dynamic_cast<Array *>(var.get());
					size += rec->m_size;
					//std::cout << "size_array: " << rec->m_size << std::endl;
				}
				else if(var->m_symbolType == _Record)
				{
					auto rec = dynamic_cast<Record *>(var.get());
					size += rec->m_size;
					//std::cout << "size_record: " << rec->m_size << std::endl;
				}
				else if(var->m_symbolType == _Type)
				{
					auto rec = dynamic_cast<Type *>(var.get());
					size += rec->m_size;
					//std::cout << "size_type: " << rec->m_size << std::endl;
				}
				else
				{
					size += 4;
					//std::cout << "other_size: " << 4 << std::endl;
				}
			}
			else
			{
				size += 4;
				//std::cout << "other_size: " << 4 << std::endl;
			}
		}
		else if(sym.second->m_symbolType == _Type)
		{
			auto temp = dynamic_cast<Type *>(sym.second.get());
			size += temp->m_size;
			//std::cout << "size_type: " << temp->m_size << std::endl;
		}
		else
		{
			//std::cout << sym.first << " is not implemented" << std::endl;
		}
	});
	//std::cout << "total_size: " << size << std::endl;
	return size;
}

void Table::SetFunctionSize(char * id)
{
	int size = Table::GetFrameSize();
	auto temp = Table::GetElement(id);
	auto func = dynamic_cast<Function *>(temp.get());

	if(!func)
	{
		
	}
	else
	{
		func->m_size = size;
	}
}

Symbol::Symbol():
m_name(""),
m_symbolType(_Symbol)
{
}

Symbol::Symbol(std::string name, SymbolType type):
m_name(name),
m_symbolType(type)
{
}

Symbol::Symbol(std::string name):
m_name(name),
m_symbolType(_Symbol)
{
}

Symbol::Symbol(SymbolType type):
m_name(""),
m_symbolType(type)
{
}

Symbol::Symbol(Symbol & x, SymbolType type):
m_name(x.m_name),
m_symbolType(type)
{
}

Function::Function():
Symbol(_Function),
m_returnType(),
m_location(""),
m_parameters(),
m_forward(false),
m_size(0)
{
}

Function::Function(std::shared_ptr<Type> returnType, std::string location, std::vector<std::shared_ptr<Var>> parameters, std::string name, bool forward):
Symbol(name, _Function),
m_returnType(returnType),
m_location(location),
m_parameters(parameters),
m_forward(forward)
{
	//m_size = Table::GetFrameSize(parameters);
}

Function::Function(std::string location, std::vector<std::shared_ptr<Var>> parameters, std::string name, bool forward):
Symbol(name, _Function),
m_returnType(),
m_location(location),
m_parameters(parameters),
m_forward(forward)
{
	//m_size = Table::GetFrameSize(parameters);
}

Type::Type(SymbolType type):
Symbol(type),
m_size(4)
{
}

Type::Type(int size, SymbolType type):
Symbol(type),
m_size(size)
{
}

Type::Type(int size, std::string name, SymbolType type):
Symbol(name, type),
m_size(size)
{
}

Type::Type(int size, std::string name):
Symbol(name, _Type),
m_size(size)
{
}

Array::Array():
Type(_Array),
m_lower(0),
m_upper(0),
m_type()
{
}

Array::Array(int lower,int upper, std::shared_ptr<Type> type, int size, std::string name):
Type(size, name, _Array),
m_lower(lower),
m_upper(upper),
m_type(type)
{
}

Array::Array(int lower,int upper, std::shared_ptr<Type> type, int size):
Type(size, _Array),
m_lower(lower),
m_upper(upper),
m_type(type)
{
}

Array::Array(int lower,int upper, std::shared_ptr<Type> type):
Type(_Array),
m_lower(lower),
m_upper(upper),
m_type(type)
{
}


Record::Record():
Type(_Record),
m_layout()
{
}

Record::Record(std::vector<std::shared_ptr<Type>> layout, int size, std::string name):
Type(size, name,_Record),
m_layout(layout)
{
}

SimpleType::SimpleType():
Type(_SimpleType),
m_type("")
{
}

SimpleType::SimpleType(std::string type, int size, std::string name):
Type(size, name,_SimpleType),
m_type(type)
{
}

Var::Var():
Symbol(_Var),
m_type(),
m_location("")
{
}

Var::Var(std::string location, std::shared_ptr<Type> type, std::string name):
Symbol(name, _Var),
m_type(type),
m_location(location)
{
}

Const::Const():
Symbol(_Const),
m_type(UNKNOWN),
m_value(""),
m_location("")
{
}

Const::Const(std::string value, ConstType type):
Symbol(_Const),
m_type(type),
m_value(value),
m_location("")
{ 
}

Const::Const(std::string value, std::string location, std::string name):
Symbol(name, _Const),
m_value(value),
m_type(UNKNOWN),
m_location(location)
{
}

Const::Const(std::string value, std::string location, std::string name, ConstType type):
Symbol(name, _Const),
m_type(type),
m_value(value),
m_location(location)
{
}

Expression::Expression():
Symbol(_Expression),
m_location(""),
m_type(UNKNOWN),
m_value("")
{
}

Expression::Expression(std::string value, ConstType type):
Symbol(_Expression),
m_location(""),
m_type(type),
m_value(value)
{
}

Expression::Expression(std::string value, ConstType type, std::string location):
Symbol(_Expression),
m_location(location),
m_type(type),
m_value(value)
{
	if(m_type == CHAR)
	{
		std::string temp;
		for(int i = 1; i < m_value.size() - 1; ++i)
			temp.push_back(m_value[i]);
		m_value = temp;
	}
}

void Expression::print()
{
	std::cout << "Name: " << m_name << " SymbolType: " << m_symbolType << " Location: " << m_location << " Value: " << m_value << " Type: " << m_type << std::endl;
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

Expression * Table::MakeChr(Expression * a)
{
	//takes int and makes char
	if(a->m_type == ID)
	{
		auto temp = GetElement(a->m_value);
		if(temp->m_symbolType == _Var)
		{
			//auto var = dynamic_cast<Var *>(temp.get());
		}
		else if(temp->m_symbolType == _Const)
		{
			auto var = dynamic_cast<Const *>(temp.get());
			if(var->m_type == INT)
			{
				var->m_type = CHAR;
			}
			else
			{
				std::cout << "must be type of type int" << std::endl;
				exit(-1);
			}
		}
		else
		{
			std::cout << "must be type of type int" << std::endl;
			exit(-1);
		}
	}
	else if(a->m_type == INT)
	{
		a->m_type = CHAR;
	}
	else
	{
		std::cout << "must be type of type int" << std::endl;
		exit(-1);
	}
	return a;
}

Expression * Table::MakeOrd(Expression * a)
{
	if(a->m_type == ID)
	{
		auto temp = GetElement(a->m_value);
		if(temp->m_symbolType == _Var)
		{
			//auto var = dynamic_cast<Var *>(temp.get());
		}
		else if(temp->m_symbolType == _Const)
		{
			auto var = dynamic_cast<Const *>(temp.get());
			if(var->m_type == CHAR)
			{
				var->m_type = INT;
			}
			else
			{
				std::cout << "must be type of type char" << std::endl;
				exit(-1);
			}
		}
		else
		{
			std::cout << "must be type of type char" << std::endl;
			exit(-1);
		}
	}
	else if(a->m_type == CHAR)
	{
		a->m_type = INT;
	}
	else
	{
		std::cout << "must be type of type char" << std::endl;
		exit(-1);
	}
	return a;
}

Expression * Table::MakeSucc(Expression * a)
{
	if(a->m_type == ID)
	{
		auto temp = GetElement(a->m_value);
		if(temp->m_symbolType == _Var)
		{
			auto var = dynamic_cast<Var *>(temp.get());
			if(var->m_type->m_name == "CHAR" || var->m_type->m_name == "char")
			{
				int regA = Output::getRegister();
				Output::out("\tlw $" + std::to_string(regA) + ", " + var->m_location + "($sp)");
				Output::out("\taddi $" + std::to_string(regA) + ", $" + std::to_string(regA) + ", 1");
				Output::out("\tsw $" + std::to_string(regA) + ", " + var->m_location + "($sp) \t#assign value");
				Output::freeRegister(regA);
			}
			else
			{
				std::cout << "must be type of type char" << std::endl;
				exit(-1);
			}
		}
		else if(temp->m_symbolType == _Const)
		{
			auto var = dynamic_cast<Const *>(temp.get());
			if(var->m_type == CHAR)
			{
				int x = std::stoi(var->m_value.c_str());
				x++;
				var->m_value = std::to_string(x);
			}
			else
			{
				std::cout << "must be type of type char" << std::endl;
				exit(-1);
			}
		}
		else
		{
			std::cout << "must be type of type char" << std::endl;
			exit(-1);
		}
	}
	else if(a->m_type == CHAR)
	{
		int x = std::stoi(a->m_value.c_str());
		x++;
		a->m_value = std::to_string(x);
	}
	else
	{
		std::cout << "must be type of type char" << std::endl;
		exit(-1);
	}
	return a;
}

Expression * Table::MakePrec(Expression * a)
{
	if(a->m_type == ID)
	{
		auto temp = GetElement(a->m_value);
		if(temp->m_symbolType == _Var)
		{
			auto var = dynamic_cast<Var *>(temp.get());
			if(var->m_type->m_name == "CHAR" || var->m_type->m_name == "char")
			{
				int regA = Output::getRegister();
				Output::out("\tlw $" + std::to_string(regA) + ", " + var->m_location + "($sp)");
				Output::out("\tsubi $" + std::to_string(regA) + ", $" + std::to_string(regA) + ", 1");
				Output::out("\tsw $" + std::to_string(regA) + ", " + var->m_location + "($sp) \t#assign value");
				Output::freeRegister(regA);
			}
			else
			{
				std::cout << "must be type of type char" << std::endl;
				exit(-1);
			}
		}
		else if(temp->m_symbolType == _Const)
		{
			auto var = dynamic_cast<Const *>(temp.get());
			if(var->m_type == CHAR)
			{
				int x = std::stoi(var->m_value.c_str());
				x--;
				var->m_value = std::to_string(x);
			}
			else
			{
				std::cout << "must be type of type char" << std::endl;
				exit(-1);
			}
		}
		else
		{
			std::cout << "must be type of type char" << std::endl;
			exit(-1);
		}
	}
	else if(a->m_type == CHAR)
	{
		int x = std::stoi(a->m_value.c_str());
		x--;
		a->m_value = std::to_string(x);
	}
	else
	{
		std::cout << "must be type of type char" << std::endl;
		exit(-1);
	}
	return a;
}

Expression * Table::GetArrayNumber(Expression * newExpr, Expression * oldExpr)
{
	int newSize = 0;
	int mult = 1;

	if(newExpr == 0)
		return 0;

	if(oldExpr == 0)
	{
		getInstance()->m_arrayIndex = 0;
		if(newExpr->m_location == "")
		{
			if(newExpr->m_type == ID)
			{
				auto temp = GetElement(newExpr->m_value);
				if(temp->m_symbolType == _Var)
				{
					auto var = dynamic_cast<Var *>(temp.get());
					if(var->m_type->m_name == "INTEGER" || var->m_type->m_name == "integer")
					{
						int regA = Output::getRegister();
						Output::out("\tlw $" + std::to_string(regA) + ", " + var->m_location + "($sp)");
						getInstance()->m_arrayIndex++;
						return new Expression(newExpr->m_value, newExpr->m_type, std::to_string(regA));
					}
					else
					{
						std::cout << "must be of type int" << std::endl;
						exit(-1);
					}
				}
				else if(temp->m_symbolType == _Const)
				{
					auto var = dynamic_cast<Const *>(temp.get());
					if(var->m_type == INT)
					{
						int regA = Output::getRegister();
						Output::out("\tli $" + std::to_string(regA) + ", " + var->m_value);
						getInstance()->m_arrayIndex++;
						return new Expression(newExpr->m_value, newExpr->m_type, std::to_string(regA));
					}
					else
					{
						std::cout << "must be of type int" << std::endl;
						exit(-1);
					}
				}
				else
				{
					std::cout << "must be of type int" << std::endl;
					exit(-1);	
				}
			}
			else if(newExpr->m_type == INT)
			{
				newSize = std::stoi(newExpr->m_value.c_str());
				newSize *= mult;
				int regA = Output::getRegister();
				Output::out("\tli $" + std::to_string(regA) + ", " + newExpr->m_value);
				getInstance()->m_arrayIndex++;
				return new Expression(newExpr->m_value, newExpr->m_type, std::to_string(regA));
			}
			else
			{
				std::cout << "must be of type int" << std::endl;
				exit(-1);	
			}
		}
		else
		{
			return newExpr;
		}
	}
	else
	{
		for(int i = 0; i < getInstance()->m_arrayIndex; ++i)
			mult *= 2;
		mult += getInstance()->m_arrayIndex;

		int regA = Output::getRegister();
		int tempReg = Output::getRegister();
		if(newExpr->m_type == INT)
			Output::out("\tli $" + std::to_string(regA) + ", " + newExpr->m_value);
		else if(newExpr->m_type == ID)
		{
			auto temp = GetElement(newExpr->m_value);
			if(temp->m_symbolType == _Var)
			{
				auto var = dynamic_cast<Var *>(temp.get());
				if(var->m_type->m_name == "INTEGER" || var->m_type->m_name == "integer")
				{
					Output::out("\tlw $" + std::to_string(regA) + ", " + var->m_location + "($sp)");
				}
				else
				{
					std::cout << "must be of type int" << std::endl;
					exit(-1);
				}
			}
			else if(temp->m_symbolType == _Const)
			{
				auto var = dynamic_cast<Const *>(temp.get());
				if(var->m_type == INT)
				{
					Output::out("\tli $" + std::to_string(regA) + ", " + var->m_value);
				}
				else
				{
					std::cout << "must be of type int" << std::endl;
					exit(-1);
				}
			}
			else
			{
				std::cout << "must be of type int" << std::endl;
				exit(-1);	
			}
		}
		Output::out("\tmul $" + std::to_string(regA) + ", $" + std::to_string(regA) + ", " + std::to_string(mult));
		Output::out("\tadd $" + std::to_string(tempReg) + ", $" + std::to_string(regA) + ", $" + oldExpr->m_location);
		Output::freeRegister(regA);
		Output::freeRegister(std::stoi(oldExpr->m_location.c_str()));
		return new Expression(newExpr->m_value, newExpr->m_type, std::to_string(tempReg));
	}
}

Expression * Table::MakeArrayIndex(char * id, Expression * expr)
{
	if(expr == 0)
	{
		std::cout << "expr is empty" << std::endl;
		exit(-1);
	}
	auto temp = GetElement(id);
	if(temp->m_symbolType == _Var)
	{
		auto var = dynamic_cast<Var *>(temp.get());
		int location = std::stoi(var->m_location);
		auto type = GetElement(var->m_type->m_name.c_str());
		int size = 0;
		if(type->m_symbolType == _SimpleType)
			size = 4;
		else if(type->m_symbolType == _Array)
		{
			auto array = dynamic_cast<Array *>(type.get());
			size = array->m_size;
		}
		else if(type->m_symbolType == _Record)
		{
			auto record = dynamic_cast<Record *>(type.get());
			size = record->m_size;
		}
		else
		{
			std::cout << "incorrect type" << std::endl;
			exit(-1);
		}

		int regA = Output::getRegister();
		int regB = Output::getRegister();
		Output::out("\tmul $" + std::to_string(regA) + ", $" + expr->m_location + ", " + std::to_string(size));
		Output::out("\taddi $" + std::to_string(regA) + ", $" + std::to_string(regA) + ", " + var->m_location);
		Output::out("\tmove $" + std::to_string(regB) + ", $sp");
		Output::out("\tadd $" + std::to_string(regB) + ", $" + std::to_string(regB) + ", $" + std::to_string(regA));
		Output::out("\tmove $25, $" + std::to_string(regB));
		Output::out("\tlw $" + std::to_string(regB) + ", ($" + std::to_string(regB)+")");
		Output::freeRegister(regA);
		Output::freeRegister(std::stoi(expr->m_location.c_str()));
		getInstance()->m_arrayIndex = 0;
		return new Expression("ARRAYRETURN", INT, std::to_string(regB));
		
	}
	else
	{
		std::cout << "array is not a var" << std::endl;
		exit(-1);
	}
}
