#ifndef TABLE_H
#define TABLE_H
#include <map>
#include <vector>
#include <mutex>
#include <memory>
#include <deque>

enum symbols
{
	OR,		//0
	AND,	//1
	NOT_EQUAL,
	EQUAL,
	LESS_EQUAL,
	GREAT,
	GREAT_EQUAL,
	LESS,
	ADD,	//8
	SUB,
	DIV,
	MOD,
	MULT,	//12
	NOT,
	UNARY
};

enum ConstType
{
	UNKNOWN,
	ID,
	INT,
	CHAR,
	STRING,
	BOOLEAN,
	RECORD,
	ARRAY,
	REFFERENCE
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
	ConstType m_constype;
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


class Expression : Symbol
{
public:
	std::string m_location;
	std::string m_value;
	ConstType m_type;
	std::shared_ptr<Type> m_typeReal;
	bool m_isConstant;
	int m_size;
	Expression();
	Expression(ConstType, std::string);
	Expression(std::string, ConstType);
	void print();
	void releaseRegister();
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
	std::string typeName;
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
	int m_parameterSize;
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
 	static int whichScope(std::string id);
 	static int getScopeSize();

 	static std::string getPointer(std::string);
 	static std::string getArrayPointer(std::string);
 	static void checkFunctionSignature(std::string, std::deque<Expression*>*);
//expressions

	static Expression * makeExpression(Expression *, symbols , Expression *);
	static void makeWriteStatement(std::deque<Expression*>*);
	static Expression* makeIntExpression(int);
	static Expression* makeStringExpression(std::string);
	static Expression* makeCharExpression(std::string);
	static void writeExpression(Expression *);
	static void readExpression(Expression *);
	static void makeReadStatement(std::deque<Expression *>*);
	static Expression* lookupExpression(Expression*);
	static Expression* makeAssignment(Expression*, Expression*);

	//If Statements
	static void finishIfStatement(int);
	static void makeIfStuff(Expression*);
	static int makeBeginIfStatement(Expression*);
	static void finishSubIf();
	static void printElse();
	static void finishElseStatement();

	//while staement
	static void beginWhileLoop();
	static void evaluateWhileCondition(Expression *);
	static void endWhileLoop();

	//Repeat Statement
	static void beginRepeat();
	static void finishRepeat(Expression* );

	//for statement
	static void beginForLoop(Expression* , Expression*, bool);
	static void finishForLoop(Expression*);

	//char cast
	static Expression* intToChar(Expression*);
	static Expression* charToInt(Expression*);

	//increment
	static Expression* incrementExpression(Expression*);
	static Expression* decrementExpression(Expression*);

	// procedure stuff
	static void makeProcedureCall(std::string, Expression*, std::deque<Expression*>*);
	static void makeProcedureProlog(std::string);
	static void makeProcedureEpilog(std::string);

	static void makeReturnStatement(Expression*);

	static Expression* functionReturn(std::string);
	static ConstType getReturnType(Function*);

//array Stuff
	static Expression* arrayToExpression(std::string, Expression*);
	static void initializeRecordArray(std::string );
	static void convertToSimple(Expression*);

	//Record Stuff
	static Expression* RecordToExpression(std::string,std::string);

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