#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <cstdlib>
#include <map>
#include <string>
#include "Symbols.h"
#include "Table.h"
#include <memory>
#include <vector>

class SymbolTable {
public:

	static std::vector<std::shared_ptr<Variable>>* makeVarList(std::vector<std::string>* ident_list, std::vector<std::shared_ptr< Variable>>* paramList, Symbol* type );
	static void addVarDecl(Symbol *, std::vector<std::string>* );
	static std::shared_ptr<SymbolTable> getInstance();
	static std::vector<std::shared_ptr<Variable>>* makeVarList(std::vector<std::string>*,std::vector<std::shared_ptr< Variable>>* , std::string);
	static void print();
	static std::shared_ptr<Symbol> lookupSymbol(std::string);
	static bool exists(std::string);

	static void addVarDecl(std::string, std::vector<std::string>*);
	static  char* createRecord(std::vector<std::pair<std::vector<std::string>*,std::string>> );
	static std::string makeRecordList(std::vector<std::string>* , std::map<std::string,std::shared_ptr< Variable>>* , std::string );
	static void makeType(std::string,std::string);
	static char* makeArray(Constant* ,Constant*, std::string );

	static Constant*evaluateConstantExpression(Constant*, Constant*, std::string);
	static void addConstant(std::string,Constant*);

	static void setVerbose(bool);
	static void popScope();
	static void pushScope(std::string );
	static bool isVerbose();


static void addFunction(std::string , std::vector<std::shared_ptr<Variable>> * , std::string, bool );


	Table* getCurScope();

	Symbol* getRawPointerType(std::string name);


private:
	
	static std::shared_ptr<SymbolTable> instance;
	std::vector<Table> symbolTables;
	bool verbose;
	void addPredefined();
	SymbolTable();
};
#endif

