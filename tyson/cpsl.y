%{
#define YYERROR_VERBOSE 1

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "logger.h"
#include "table.h"

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int numLines;
 
void yyerror(const char *s);

%}

%union
{ 
	int int_val;
	char * name_ptr; 
	void * none_type;
	Const * const_type;
	std::vector<std::shared_ptr<Var>> * formalParameter;
	std::vector<std::string> * identList;
	Type * type;
	std::vector<std::shared_ptr<Type>> * typeList;
}

%token <int_val> INTEGER_SYMBOL
%token <name_ptr> STRING_SYMBOL
%token <name_ptr> ID_SYMBOL	
%token <name_ptr> CHARACTER_SYMBOL	

%token ADD_SYMBOL
%token AND_SYMBOL
%token ARRAY_SYMBOL 
%token ASSIGN_SYMBOL		
%token BEGIN_SYMBOL 		
%token CHR_SYMBOL
%token COLON_SYMBOL	
%token COMMA_SYMBOL		
%token CONST_SYMBOL	
%token DIV_SYMBOL	
%token DO_SYMBOL	
%token DOT_SYMBOL
%token DOWNTO_SYMBOL
%token ELSE_SYMBOL		
%token ELSEIF_SYMBOL				
%token END_SYMBOL	
%token EQUAL_SYMBOL
%token FOR_SYMBOL		
%token FORWARD_SYMBOL 	
%token FUNCTION_SYMBOL	
%token GREAT_EQUAL_SYMBOL
%token GREAT_SYMBOL	
%token IF_SYMBOL
%token LEFT_BRACE_SYMBOL
%token LEFT_SQUARE_SYMBOL
%token LESS_SYMBOL
%token LESS_EQUAL_SYMBOL
%token MULT_SYMBOL
%token NOT_SYMBOL
%token NOT_EQUAL_SYMBOL			
%token OF_SYMBOL	
%token OR_SYMBOL				
%token ORD_SYMBOL	
%token PERCENT_SYMBOL		
%token PRED_SYMBOL	
%token PROCEDURE_SYMBOL			
%token READ_SYMBOL	
%token RECORD_SYMBOL		
%token REPEAT_SYMBOL
%token RETURN_SYMBOL	
%token RIGHT_BRACE_SYMBOL
%token RIGHT_SQUARE_SYMBOL
%token SEMI_COLON_SYMBOL
%token STOP_SYMBOL
%token SUB_SYMBOL			
%token SUCC_SYMBOL			
%token THEN_SYMBOL	
%token TO_SYMBOL			
%token TYPE_SYMBOL			
%token UNTIL_SYMBOL 
%token UNARY_MINUS_SYMBOL		
%token VAR_SYMBOL			
%token WHILE_SYMBOL			
%token WRITE_SYMBOL

%type <type> ArrayType

/*
%type Assignment
%type Block
%type Body
%type ConstantDecl
%type ConstantStuff
*/

%type <const_type> ConstExpression

/*
%type Expression
%type ExpressionStuff
*/

%type <formalParameter> FormalParameters

/*
%type ForStatement
%type FunctionDecl
*/

//%type <formalParameter> FuncStuff
%type <identList> IdentList
%type <identList> IdentStuff

/*
%type IfStatement
%type IfStuff
%type LValue
%type LValueStuff
%type NullStatement
*/

%type <formalParameter> ParamStuff

/*
%type ProcedureCall
%type ProcedureDecl
%type ProcedureStuff
%type ProcFunc
%type Program
%type ReadStatement
%type ReadStuff
*/

%type <type> RecordType
%type <typeList> RecordStuff

/*
%type RepeatStatement
%type ReturnStatement
*/

%type <type> SimpleType

/*
%type Statement
%type StatementSequence
%type StatementStuff
%type StopStatement
*/

%type <type> Type

/*
%type TypeDecl
%type TypeStuff
%type VarDecl
%type VarStuff
%type WhileStatement
%type WriteStatement
%type WriteStuff
*/




%left OR_SYMBOL
%left AND_SYMBOL
%right NOT_SYMBOL
%nonassoc LESS_SYMBOL LESS_EQUAL_SYMBOL NOT_EQUAL_SYMBOL EQUAL_SYMBOL GREAT_EQUAL_SYMBOL GREAT_SYMBOL 
%left ADD_SYMBOL SUB_SYMBOL
%left MULT_SYMBOL DIV_SYMBOL PERCENT_SYMBOL
%right UNARY_MINUS_SYMBOL


%%
Program			    : ConstantDecl TypeDecl VarDecl ProcFunc Block DOT_SYMBOL
					| ConstantDecl TypeDecl ProcFunc Block DOT_SYMBOL
					| ConstantDecl VarDecl ProcFunc Block DOT_SYMBOL
					| ConstantDecl ProcFunc Block DOT_SYMBOL
					| TypeDecl VarDecl ProcFunc Block DOT_SYMBOL
					| TypeDecl ProcFunc Block DOT_SYMBOL
					| VarDecl ProcFunc Block DOT_SYMBOL
					| ProcFunc Block DOT_SYMBOL
					;

ConstantDecl 		: CONST_SYMBOL ID_SYMBOL EQUAL_SYMBOL ConstExpression SEMI_COLON_SYMBOL ConstantStuff {Table::MakeConst($2,$4);}
			 		;

ConstantStuff		:
					| ID_SYMBOL EQUAL_SYMBOL ConstExpression SEMI_COLON_SYMBOL ConstantStuff {Table::MakeConst($1,$3);}
					;

ProcFunc 			: ProcedureDecl ProcFunc
		 			| FunctionDecl ProcFunc
					|
					;

ProcedureDecl 		: PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL FORWARD_SYMBOL SEMI_COLON_SYMBOL {Element element(new Function($2,*$4,$2,true)); Table::InsertElement($2, element);}
			  		| ProcStuff Body SEMI_COLON_SYMBOL {Table::RemoveScope();}
			  		;

ProcStuff			: PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL {Element element(new Function($2,*$4,$2,false)); Table::InsertElement($2, element); Table::AddScope($4);}
					;

FunctionDecl 		: FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL FORWARD_SYMBOL SEMI_COLON_SYMBOL  {Element element(new Function(std::shared_ptr<Type>($7),$2,*$4,$2,true)); Table::InsertElement($2, element);}
			 		| FuncStuff Body SEMI_COLON_SYMBOL {Table::RemoveScope();}
			 		;

FuncStuff			: FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL{Element element(new Function(std::shared_ptr<Type>($7),$2,*$4,$2,false)); Table::InsertElement($2, element); Table::AddScope($4);}
					;

FormalParameters 	: {$$ = new std::vector<std::shared_ptr<Var>>;}
				 	| VAR_SYMBOL IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($4,$2,$5);}
				 	| IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($3,$1,$4);}
				 	;

ParamStuff 			: SEMI_COLON_SYMBOL VAR_SYMBOL IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($5,$3,$6);}
		   			| SEMI_COLON_SYMBOL IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($4,$2,$5);}
		   			| {$$ = new std::vector<std::shared_ptr<Var>>;}
		   			;

Body 				: BodyStuff Block
	 				| Block
	 				;

BodyStuff			: ConstantDecl TypeDecl VarDecl
					| ConstantDecl TypeDecl
					| ConstantDecl VarDecl
					| ConstantDecl
					| TypeDecl VarDecl
					| TypeDecl
					| VarDecl
					;

Block 				: BEGIN_SYMBOL StatementSequence END_SYMBOL
	  				;

TypeDecl 			: TypeBlah TypeStuff 
					;

TypeBlah			: TYPE_SYMBOL ID_SYMBOL EQUAL_SYMBOL Type SEMI_COLON_SYMBOL {$4->m_name = $2; Element e($4); Table::InsertElement($2, e);}
					;

TypeStuff			:
					| ID_SYMBOL EQUAL_SYMBOL Type SEMI_COLON_SYMBOL TypeStuff{$3->m_name = $1; Element e($3); Table::InsertElement($1, e);}
					;

Type 				: SimpleType {$$ = $1;}
					| RecordType {$$ = $1;}
					| ArrayType {$$ = $1;}
					;

SimpleType			: ID_SYMBOL {$$ = Table::MakeSimple($1);}
					;

RecordType			: RECORD_SYMBOL RecordStuff END_SYMBOL {$$ = Table::MakeRecord($2);}
					;

RecordStuff			: IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL RecordStuff {$$ = Table::MakeSubRecord($3,$5, $1);}
					| {$$ = new std::vector<std::shared_ptr<Type>>;}
					;

ArrayType			: ARRAY_SYMBOL LEFT_SQUARE_SYMBOL ConstExpression COLON_SYMBOL ConstExpression RIGHT_SQUARE_SYMBOL OF_SYMBOL Type {$$ = new Array(Table::getSize($3),Table::getSize($5),std::shared_ptr<Type>($8),Table::getArraySize($3,$5,$8->m_size), $8->m_name);}
					;

IdentList			: ID_SYMBOL IdentStuff {$2->push_back($1); $$ = $2;} 
					;

IdentStuff			: {$$ = new std::vector<std::string>;}
					| COMMA_SYMBOL ID_SYMBOL IdentStuff {$3->push_back($2); $$ = $3;}
					;

VarDecl				: VAR_SYMBOL IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL VarStuff {Table::MakeVar($2,$4); delete $2; delete $4;}
					;

VarStuff			: 
					| IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL VarStuff {Table::MakeVar($1,$3); delete $1; delete $3;}
					;

StatementSequence 	: Statement StatementStuff
					;

StatementStuff		:
					| SEMI_COLON_SYMBOL Statement StatementStuff
					;

Statement 			: Assignment
					| IfStatement
					| WhileStatement
					| RepeatStatement
					| ForStatement
					| StopStatement
					| ReturnStatement
					| ReadStatement
					| WriteStatement
					| ProcedureCall
					| NullStatement
					;

Assignment			: LValue ASSIGN_SYMBOL Expression
					;

IfStatement			: IF_SYMBOL Expression THEN_SYMBOL StatementSequence IfStuff ELSE_SYMBOL StatementSequence END_SYMBOL
					| IF_SYMBOL Expression THEN_SYMBOL StatementSequence IfStuff END_SYMBOL
					;

IfStuff				: 
					| ELSEIF_SYMBOL Expression THEN_SYMBOL StatementSequence IfStuff
					;

WhileStatement		: WHILE_SYMBOL Expression DO_SYMBOL StatementSequence END_SYMBOL
					;

RepeatStatement		: REPEAT_SYMBOL StatementSequence UNTIL_SYMBOL Expression
					;

ForStatement		: FOR_SYMBOL ID_SYMBOL ASSIGN_SYMBOL Expression TO_SYMBOL Expression DO_SYMBOL StatementSequence END_SYMBOL
					| FOR_SYMBOL ID_SYMBOL ASSIGN_SYMBOL Expression DOWNTO_SYMBOL Expression DO_SYMBOL StatementSequence END_SYMBOL
					;

StopStatement		: STOP_SYMBOL
					;

ReturnStatement		: RETURN_SYMBOL Expression
					| RETURN_SYMBOL
					;

ReadStatement		: READ_SYMBOL LEFT_BRACE_SYMBOL LValue ReadStuff RIGHT_BRACE_SYMBOL
					;

ReadStuff			: COMMA_SYMBOL LValue ReadStuff
					|
					;

WriteStatement		: WRITE_SYMBOL LEFT_BRACE_SYMBOL Expression WriteStuff RIGHT_BRACE_SYMBOL
					;

WriteStuff			: 
					| COMMA_SYMBOL Expression WriteStuff
					;

ProcedureCall		: ID_SYMBOL LEFT_BRACE_SYMBOL Expression ProcedureStuff RIGHT_BRACE_SYMBOL
					| ID_SYMBOL LEFT_BRACE_SYMBOL RIGHT_BRACE_SYMBOL
					;

ProcedureStuff		:
					| COMMA_SYMBOL Expression ProcedureStuff
					;

NullStatement		:
					;

Expression 			: Expression OR_SYMBOL Expression
					| Expression AND_SYMBOL Expression
					| Expression EQUAL_SYMBOL Expression
					| Expression NOT_EQUAL_SYMBOL Expression
					| Expression LESS_EQUAL_SYMBOL Expression
					| Expression GREAT_EQUAL_SYMBOL Expression
					| Expression LESS_SYMBOL Expression
					| Expression GREAT_SYMBOL Expression
					| Expression ADD_SYMBOL Expression
					| Expression SUB_SYMBOL Expression
					| Expression MULT_SYMBOL Expression
					| Expression DIV_SYMBOL Expression
					| Expression PERCENT_SYMBOL Expression
					| NOT_SYMBOL Expression
					| SUB_SYMBOL Expression %prec UNARY_MINUS_SYMBOL
					| LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL
					| ID_SYMBOL LEFT_BRACE_SYMBOL RIGHT_BRACE_SYMBOL
					| ID_SYMBOL LEFT_BRACE_SYMBOL Expression ExpressionStuff RIGHT_BRACE_SYMBOL
					| CHR_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL
					| ORD_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL
					| PRED_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL
					| SUCC_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL
					| INTEGER_SYMBOL
					| CHARACTER_SYMBOL
					| STRING_SYMBOL
					| LValue
					;

ExpressionStuff 	: COMMA_SYMBOL Expression ExpressionStuff
					|
					;

LValue 				: ID_SYMBOL
					| ID_SYMBOL DOT_SYMBOL ID_SYMBOL LValueStuff
					| ID_SYMBOL LEFT_SQUARE_SYMBOL Expression RIGHT_SQUARE_SYMBOL LValueStuff
					;

LValueStuff			: DOT_SYMBOL ID_SYMBOL LValueStuff
					| LEFT_SQUARE_SYMBOL Expression RIGHT_SQUARE_SYMBOL LValueStuff
					|
					;

ConstExpression 	: ConstExpression OR_SYMBOL ConstExpression {$$ = Table::makeConst($1,OR,$3);}
					| ConstExpression AND_SYMBOL ConstExpression {$$ = Table::makeConst($1,AND,$3);}
					| ConstExpression EQUAL_SYMBOL ConstExpression {$$ = Table::makeConst($1,EQUAL,$3);}
					| ConstExpression NOT_EQUAL_SYMBOL ConstExpression {$$ = Table::makeConst($1,NOT_EQUAL,$3);}
					| ConstExpression LESS_EQUAL_SYMBOL ConstExpression {$$ = Table::makeConst($1,LESS_EQUAL,$3);}
					| ConstExpression GREAT_EQUAL_SYMBOL ConstExpression {$$ = Table::makeConst($1,GREAT_EQUAL,$3);}
					| ConstExpression LESS_SYMBOL ConstExpression {$$ = Table::makeConst($1,LESS,$3);}
					| ConstExpression GREAT_SYMBOL ConstExpression {$$ = Table::makeConst($1,GREAT,$3);}
					| ConstExpression ADD_SYMBOL ConstExpression {$$ = Table::makeConst($1,ADD,$3);}
					| ConstExpression SUB_SYMBOL ConstExpression {$$ = Table::makeConst($1,SUB,$3);}
					| ConstExpression MULT_SYMBOL ConstExpression {$$ = Table::makeConst($1,MULT,$3);}
					| ConstExpression DIV_SYMBOL ConstExpression {$$ = Table::makeConst($1,DIV,$3);}
					| ConstExpression PERCENT_SYMBOL ConstExpression {$$ = Table::makeConst($1,MOD,$3);}
					| NOT_SYMBOL ConstExpression {$$ = Table::makeConst(new Const("",UNKNOWN),NOT,$2);}
					| SUB_SYMBOL ConstExpression %prec UNARY_MINUS_SYMBOL {$$ = Table::makeConst(new Const("",UNKNOWN),UNARY,$2);}
					| LEFT_BRACE_SYMBOL ConstExpression RIGHT_BRACE_SYMBOL {$$ = $2;}
					| INTEGER_SYMBOL 	{$$ = new Const(std::to_string($1),INT);}				
					| CHARACTER_SYMBOL 	{$$ = new Const($1,CHAR);}				
					| STRING_SYMBOL 	{$$ = new Const($1,STRING);}				
					| ID_SYMBOL 		{$$ = new Const($1,ID);}
					;
%%

//inputfile, outputfile, -v (print to console)
int main(int argc, char ** argv)
{
	argc--, argv++;
	/*
	if(argc >= 3)
	{
		std::string filePath = argv[1];
		Logger::SetFilePath(filePath);
		std::string logLevel = argv[2];
		if(logLevel == "-v")
			Logger::SetLevel(VERBOSE);
		else if(logLevel == "-e")
			Logger::SetLevel(ERROR);
		else if(logLevel == "-s")
			Logger::SetLevel(SILENT);
		else if(logLevel == "-d")
			Logger::SetLevel(DEBUG);
	}
	else if(argc == 2)
	{
		std::string arg1 = argv[1];
		if(arg1 == "-v")
			Logger::SetLevel(VERBOSE);
		else if(arg1 == "-e")
			Logger::SetLevel(ERROR);
		else if(arg1 == "-s")
			Logger::SetLevel(SILENT);
		else if(arg1 == "-d")
			Logger::SetLevel(DEBUG);
		else
			Logger::SetFilePath(arg1);
	}
	*/
	if(argc > 0)
	{
		yyin = fopen( argv[0], "r" );
	}
	else
	{
		yyin = stdin;
	}
	do 
	{
		yyparse();
	} while (!feof(yyin));
	Table::PrintTable();
	return 0;
};

void yyerror(const char * message) 
{
	Logger::LogError(message, numLines);
	exit(-1);
}