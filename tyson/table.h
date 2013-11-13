#ifndef TABLE_H
#define TABLE_H
#include <map>
#include <vector>
#include <mutex>
#include <memory>
#include "OutputFile.h"

enum symbols
{
	OR,
	AND,
	NOT_EQUAL,
	EQUAL,
	LESS_EQUAL,
	GREAT,
	GREAT_EQUAL,
	LESS,
	ADD,
	SUB,
	DIV,
	MOD,
	MULT,
	NOT,
	UNARY
};

enum ConstType
{
	UNKNOWN, 	//0
	ID,			//1
	INT,		//2
	CHAR,		//3
	STRING		//4
};

enum SymbolType
{
	_Symbol,
	_Type,
	_SimpleType,
	_Array,
	_Record,
	_Var,
	_Const,
	_Function,
	_Expression
};

class Symbol
{
public:
	SymbolType m_symbolType;
	std::string m_name;
	virtual void print();
	~Symbol(){};
	Symbol(SymbolType);
	Symbol(std::string);
	Symbol();
	Symbol(std::string, SymbolType);
	Symbol(Symbol &, SymbolType);
};

class Type : public Symbol
{
public:
	int m_size;
	virtual void print();
	~Type(){};
	Type(SymbolType);
	Type(int, std::string, SymbolType);
	Type(int, std::string);
	Type(int, SymbolType);
};

class SimpleType : public Type
{
public:
	std::string m_type;
	virtual void print();
	~SimpleType(){};
	SimpleType();
	SimpleType(std::string, int, std::string);
};
class Array : public Type
{
public:
	int m_lower;
	int m_upper;
	std::shared_ptr<Type> m_type;
	virtual void print();
	~Array(){};
	Array();
	Array(int,int,std::shared_ptr<Type>);
	Array(int,int,std::shared_ptr<Type>, int, std::string);
	Array(int,int,std::shared_ptr<Type>, int);
};

class Record : public Type
{
public:
	std::vector<std::shared_ptr<Type>> m_layout;
	virtual void print();
	~Record(){};
	Record();
	Record(std::vector<std::shared_ptr<Type>>, int, std::string);
};

class Var : public Symbol
{
public:
	std::shared_ptr<Type> m_type;
	std::string m_location;
	virtual void print();
	~Var(){};
	Var();
	Var(std::string, std::shared_ptr<Type>, std::string);
};

class Const : public Symbol
{
public:
	std::string m_value;
	std::string m_location;
	ConstType m_type;
	virtual void print();
	~Const(){};
	Const();
	Const(std::string, ConstType);
	Const(std::string, std::string, std::string);
	Const(std::string, std::string, std::string, ConstType);
};

class Function : public Symbol
{
public:
	bool m_forward;
	std::shared_ptr<Type> m_returnType;
	std::vector<std::shared_ptr<Var>> m_parameters;
	std::string m_location;
	int m_size;
	virtual void print();
	~Function(){};
	Function();
	Function(std::shared_ptr<Type>, std::string, std::vector<std::shared_ptr<Var>>, std::string, bool);
	Function(std::string, std::vector<std::shared_ptr<Var>>, std::string, bool);
};

class Expression : public Symbol
{
public:
	std::string m_location;
	std::string m_value;
	ConstType m_type;
	virtual void print();
	Expression();
	Expression(std::string, ConstType);
	Expression(std::string, ConstType, std::string);
};

typedef std::shared_ptr<Symbol> Element;

class Table
{
public:
	static std::vector<std::shared_ptr<Var>> * MakeVars(Type *, std::vector<std::string> *, std::vector<std::shared_ptr<Var>> *);
	static std::vector<std::shared_ptr<Type>> * MakeSubRecord(Type *, std::vector<std::shared_ptr<Type>> *,std::vector<std::string> *);
	static int getArraySize(Const*,Const*,int);
	static int getSize(Const *);
	static SimpleType * MakeSimple(std::string);
	static Record * MakeRecord(std::vector<std::shared_ptr<Type>>*);
	static void MakeVar(std::vector<std::string>*, Type *);
	static Const * makeConst(Const *,symbols,Const *);
	static Expression * makeExpression(Expression *, symbols, Expression *);
	static void MakeConst(std::string, Const *);
	static void InsertElement(std::string,Element);
	static Element GetElement(std::string);
	static void AddScope(std::vector<std::shared_ptr<Var>> *);
	static void RemoveScope();
	static void PrintTable();
	static void PrintScope();
	static bool isVerbose();
	static void setVerbose(bool);
	static void printStrings();
	static void WriteCode(std::vector<Expression *> *);
	static void ReadCode(std::vector<Expression *> *);
	static std::string getStringCount();
	static void Assign(Expression *, Expression *);
	static void MakeFirstIf(Expression *);
	static void MakeIf(Expression *);
	static void MakeElse();
	static void MakeEndIf();
	static void MakeEndIf2();
	static void MakeWhileBegin(Expression *);
	static void MakeWhileEnd();
	static void MakeWhilePre();
	static void MakeRepeatPre();
	static void MakeRepeatEnd(Expression *);
	static char * MakeForBegin(char *,Expression *);
	static void MakeForTo(char *, Expression *);
	static void MakeForDownTo(char *, Expression *);
	static void MakeForToEnd(char *);
	static void MakeForDownToEnd(char *);
	static void MakeProcedureCall(std::vector<Expression *> *, char *);
	static void MakeProcedureMain(char *);
	static int GetFrameSize(std::vector<std::shared_ptr<Var>> vars);
	static void MakeProcedureEnd(char *);
	static void MakeReturn(Expression *);
	static Expression * MakeFunctionCall(std::vector<Expression *> *, char *);
	~Table(){};
private:
	static std::vector<std::string> m_strings;
	Table();
	static std::shared_ptr<Table> getInstance();
	static std::shared_ptr<Table> m_instance;
	bool verbose;
	std::mutex m_mutex;
	std::vector<std::map<std::string, Element>> m_table;
	int m_scope;
	std::string getScope(std::string);
};

#endif