#ifndef TABLE_H
#define TABLE_H
#include <map>
#include <vector>
#include <mutex>
#include <memory>

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
	UNKNOWN,
	ID,
	INT,
	CHAR,
	STRING
};

class Symbol
{
public:
	std::string m_name;
	virtual void print();
	~Symbol(){};
	Symbol();
	Symbol(std::string);
	Symbol(Symbol &);
};

class Type : public Symbol
{
public:
	int m_size;
	virtual void print();
	~Type(){};
	Type();
	Type(int, std::string);
	Type(int);
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
	virtual void print();
	~Function(){};
	Function();
	Function(std::shared_ptr<Type>, std::string, std::vector<std::shared_ptr<Var>>, std::string, bool);
	Function(std::string, std::vector<std::shared_ptr<Var>>, std::string, bool);
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
	static void MakeConst(std::string, Const *);
	static void InsertElement(std::string,Element);
	static Element GetElement(std::string);
	static void AddScope(std::vector<std::shared_ptr<Var>> *);
	static void RemoveScope();
	static void PrintTable();
	static void PrintScope();
	static bool isVerbose();
	static void setVerbose(bool);

	~Table(){};
private:
	Table();
	static std::shared_ptr<Table> getInstance();
	static std::shared_ptr<Table> m_instance;
	std::mutex m_mutex;
	std::vector<std::map<std::string, Element>> m_table;
	int m_scope;
	bool verbose;
};

#endif