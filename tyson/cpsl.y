%{
#define YYERROR_VERBOSE 1

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "logger.h"
#include "table.h"
#include "OutputFile.h"

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
	Expression * expr_type;
	std::vector<std::shared_ptr<Var>> * formalParameter;
	std::vector<std::string> * identList;
	Type * type;
	std::vector<std::shared_ptr<Type>> * typeList;
	std::vector<Expression *> * exprList;
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
%type <const_type> ConstExpression
%type <expr_type> Expression
%type <exprList> ExpressionStuff
%type <formalParameter> FormalParameters
%type <name_ptr> ForBegin
%type <name_ptr> ForTo
%type <name_ptr> ForDownTo
%type <name_ptr> FuncStuff
%type <identList> IdentList
%type <identList> IdentStuff
%type <expr_type> LValue
%type <expr_type> LValueStuff
%type <formalParameter> ParamStuff
%type <name_ptr> PreFuncBody
%type <name_ptr> PreProcBody
%type <exprList> ProcedureStuff
%type <name_ptr> ProcStuff
%type <exprList> ReadStuff
%type <type> RecordType
%type <typeList> RecordStuff
%type <type> SimpleType
%type <type> Type
%type <exprList> WriteStuff




%left OR_SYMBOL
%left AND_SYMBOL
%right NOT_SYMBOL
%nonassoc LESS_SYMBOL LESS_EQUAL_SYMBOL NOT_EQUAL_SYMBOL EQUAL_SYMBOL GREAT_EQUAL_SYMBOL GREAT_SYMBOL 
%left ADD_SYMBOL SUB_SYMBOL
%left MULT_SYMBOL DIV_SYMBOL PERCENT_SYMBOL
%right UNARY_MINUS_SYMBOL


%%
Program			    : ConstantDecl TypeDecl VarDecl ProcFunc MainBlock DOT_SYMBOL
					| ConstantDecl TypeDecl ProcFunc MainBlock DOT_SYMBOL
					| ConstantDecl VarDecl ProcFunc MainBlock DOT_SYMBOL
					| ConstantDecl ProcFunc MainBlock DOT_SYMBOL
					| TypeDecl VarDecl ProcFunc MainBlock DOT_SYMBOL
					| TypeDecl ProcFunc MainBlock DOT_SYMBOL
					| VarDecl ProcFunc MainBlock DOT_SYMBOL
					| ProcFunc MainBlock DOT_SYMBOL
					;

MainBlock			: WriteBegin StatementSequence END_SYMBOL
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
			  		| PreProcBody Block SEMI_COLON_SYMBOL {Table::RemoveScope(); Table::MakeProcedureEnd($1); Output::writeEnd();}
			  		;

ProcStuff			: PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL {Element element(new Function($2,*$4,$2,false)); Table::InsertElement($2, element); Table::AddScope($4); $$ = $2;}
					;

FunctionDecl 		: FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL FORWARD_SYMBOL SEMI_COLON_SYMBOL  {Element element(new Function(std::shared_ptr<Type>($7),$2,*$4,$2,true)); Table::InsertElement($2, element);}
			 		| PreFuncBody Block SEMI_COLON_SYMBOL {Table::RemoveScope(); Table::MakeProcedureEnd($1); Output::writeEnd();}
			 		;


FuncStuff			: FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL{Element element(new Function(std::shared_ptr<Type>($7),$2,*$4,$2,false)); Table::InsertElement($2, element); Table::AddScope($4); $$ = $2;}
					;

FormalParameters 	: {$$ = new std::vector<std::shared_ptr<Var>>;}
				 	| VAR_SYMBOL IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($4,$2,$5);}
				 	| IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($3,$1,$4);}
				 	;

ParamStuff 			: SEMI_COLON_SYMBOL VAR_SYMBOL IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($5,$3,$6);}
		   			| SEMI_COLON_SYMBOL IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($4,$2,$5);}
		   			| {$$ = new std::vector<std::shared_ptr<Var>>;}
		   			;

PreFuncBody			: FuncStuff BodyStuff {Table::SetFunctionSize($1); Table::MakeProcedureMain($1); $$ = $1;}
					;

PreProcBody			: ProcStuff BodyStuff {Table::SetFunctionSize($1); Table::MakeProcedureMain($1); $$ = $1;}
					;

BodyStuff			: ConstantDecl TypeDecl VarDecl
					| ConstantDecl TypeDecl
					| ConstantDecl VarDecl
					| ConstantDecl
					| TypeDecl VarDecl
					| TypeDecl
					| VarDecl
					|
					;

Block 				: BEGIN_SYMBOL StatementSequence END_SYMBOL
	  				;

WriteBegin			: BEGIN_SYMBOL {Output::writeBegin();}
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

Assignment			: LValue ASSIGN_SYMBOL Expression {Table::Assign($1,$3);}
					;

IfStatement			: IfFirst StatementSequence IfStuff EndFirst StatementSequence END_SYMBOL {Table::MakeEndIf();}
					| IfFirst StatementSequence IfStuff END_SYMBOL {Table::MakeEndIf2();}
					;

IfFirst				: IF_SYMBOL Expression THEN_SYMBOL {Table::MakeFirstIf($2);}
					;

EndFirst			: ELSE_SYMBOL {Table::MakeElse();}
					;

IfStuff				:
					| IfEnd ElseIfFirst StatementSequence IfStuff
					;

IfEnd				: {Table::MakeElse();}
					;

ElseIfFirst			: ELSEIF_SYMBOL Expression THEN_SYMBOL {Table::MakeIf($2);}
					;

WhileStatement		: WhileStart StatementSequence END_SYMBOL {Table::MakeWhileEnd();}
					;

WhileStart			: WhilePre Expression DO_SYMBOL {Table::MakeWhileBegin($2);}
					;

WhilePre			: WHILE_SYMBOL	{Table::MakeWhilePre();}
					;

RepeatStatement		: RepeatPre StatementSequence UNTIL_SYMBOL Expression {Table::MakeRepeatEnd($4);}
					;

RepeatPre			: REPEAT_SYMBOL {Table::MakeRepeatPre();}
					;

ForStatement		: ForTo StatementSequence END_SYMBOL {Table::MakeForToEnd($1);}
					| ForDownTo StatementSequence END_SYMBOL {Table::MakeForDownToEnd($1);}
					;

ForTo				: ForBegin TO_SYMBOL Expression DO_SYMBOL {Table::MakeForTo($1,$3);}
					;

ForDownTo			: ForBegin DOWNTO_SYMBOL Expression DO_SYMBOL {Table::MakeForDownTo($1,$3);}
					;

ForBegin			: FOR_SYMBOL ID_SYMBOL ASSIGN_SYMBOL Expression {$$ = Table::MakeForBegin($2,$4);}
					;

StopStatement		: STOP_SYMBOL {Output::endFile();}
					;

ReturnStatement		: RETURN_SYMBOL Expression {Table::MakeReturn($2);}
					| RETURN_SYMBOL  
					;

ReadStatement		: READ_SYMBOL LEFT_BRACE_SYMBOL LValue ReadStuff RIGHT_BRACE_SYMBOL {$4->push_back($3); Table::ReadCode($4);}
					;

ReadStuff			: COMMA_SYMBOL LValue ReadStuff {$3->push_back($2); $$ = $3;}
					| {$$ = new std::vector<Expression *>;}
					;

WriteStatement		: WRITE_SYMBOL LEFT_BRACE_SYMBOL Expression WriteStuff RIGHT_BRACE_SYMBOL {$4->push_back($3); Table::WriteCode($4);}
					;

WriteStuff			: {$$ = new std::vector<Expression *>;}
					| COMMA_SYMBOL Expression WriteStuff {$3->push_back($2); $$ = $3;}
					;

ProcedureCall		: ID_SYMBOL LEFT_BRACE_SYMBOL Expression ProcedureStuff RIGHT_BRACE_SYMBOL {$4->push_back($3); Table::MakeProcedureCall($4,$1);}
					| ID_SYMBOL LEFT_BRACE_SYMBOL RIGHT_BRACE_SYMBOL {Table::MakeProcedureCall(0,$1);}
					;

ProcedureStuff		:  {$$ = new std::vector<Expression *>;}
					| COMMA_SYMBOL Expression ProcedureStuff {$3->push_back($2); $$ = $3;}
					;

NullStatement		: 
					;

Expression 			: Expression OR_SYMBOL Expression {$$ = Table::makeExpression($1, OR, $3);}
					| Expression AND_SYMBOL Expression {$$ = Table::makeExpression($1, AND, $3);}
					| Expression EQUAL_SYMBOL Expression {$$ = Table::makeExpression($1, EQUAL, $3);}
					| Expression NOT_EQUAL_SYMBOL Expression {$$ = Table::makeExpression($1, NOT_EQUAL, $3);}
					| Expression LESS_EQUAL_SYMBOL Expression {$$ = Table::makeExpression($1, LESS_EQUAL, $3);}
					| Expression GREAT_EQUAL_SYMBOL Expression {$$ = Table::makeExpression($1, GREAT_EQUAL, $3);}
					| Expression LESS_SYMBOL Expression {$$ = Table::makeExpression($1, LESS, $3);}
					| Expression GREAT_SYMBOL Expression {$$ = Table::makeExpression($1, GREAT, $3);}
					| Expression ADD_SYMBOL Expression  {$$ = Table::makeExpression($1, ADD, $3);}
					| Expression SUB_SYMBOL Expression {$$ = Table::makeExpression($1, SUB, $3);}
					| Expression MULT_SYMBOL Expression {$$ = Table::makeExpression($1, MULT, $3);}
					| Expression DIV_SYMBOL Expression {$$ = Table::makeExpression($1, DIV, $3);}
					| Expression PERCENT_SYMBOL Expression {$$ = Table::makeExpression($1, MOD, $3);}
					| NOT_SYMBOL Expression {$$ = Table::makeExpression(new Expression("",UNKNOWN),NOT,$2);}
					| SUB_SYMBOL Expression %prec UNARY_MINUS_SYMBOL {$$ = Table::makeExpression(new Expression("",UNKNOWN),UNARY,$2);}
					| LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL {$$ = $2;}
					| ID_SYMBOL LEFT_BRACE_SYMBOL RIGHT_BRACE_SYMBOL {$$ = Table::MakeFunctionCall(0,$1);}
					| ID_SYMBOL LEFT_BRACE_SYMBOL Expression ExpressionStuff RIGHT_BRACE_SYMBOL {$4->push_back($3); $$ = Table::MakeFunctionCall($4, $1);}//function
					| CHR_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL {$$ = Table::MakeChr($3);}
					| ORD_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL {$$ = Table::MakeOrd($3);}
					| PRED_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL {$$ = Table::MakePrec($3);}
					| SUCC_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL {$$ = Table::MakeSucc($3);}
					| INTEGER_SYMBOL 	{$$ = new Expression(std::to_string($1),INT);}				
					| CHARACTER_SYMBOL 	{$$ = new Expression($1,CHAR);}				
					| STRING_SYMBOL 	{$$ = new Expression($1,STRING,Table::getStringCount());}
					| LValue {$$ = $1;}
					;

ExpressionStuff 	: COMMA_SYMBOL Expression ExpressionStuff {$3->push_back($2); $$ = $3;}
					| {$$ = new std::vector<Expression *>;}
					;

LValue 				: ID_SYMBOL {$$ = new Expression($1,ID);}
					| ID_SYMBOL DOT_SYMBOL ID_SYMBOL LValueStuff  {$$ = 0;}//record
					| ID_SYMBOL LEFT_SQUARE_SYMBOL Expression RIGHT_SQUARE_SYMBOL LValueStuff {Expression * temp = Table::GetArrayNumber($3,$5); $$ = Table::MakeArrayIndex($1,temp);}
					;

LValueStuff			: DOT_SYMBOL ID_SYMBOL LValueStuff{$$ = 0;}
					| LEFT_SQUARE_SYMBOL Expression RIGHT_SQUARE_SYMBOL LValueStuff {$$ = Table::GetArrayNumber($2,$4);}
					| {$$ = 0;}
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

	Table::setVerbose(false);
	if(argc == 3)
	{
		std::cout<<argv[2];
		if(argv[2][1] == 'v')
		{
			std::cout<<"setting verbose\n";
			Table::setVerbose(true);
		}
	
		std::string filePath = argv[1];
		Output::SetFilePath(filePath);
	}


	if(argc == 2)
	{
		std::string filePath = argv[1];
		Output::SetFilePath(filePath);
	}

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
	if(Table::isVerbose());
	{
		Table::PrintTable();
		Output::CheckRegisters();
	}
	Output::endFile();
	Table::printStrings();
	return 0;
};

void yyerror(const char * message) 
{
	Logger::LogError(message, numLines);
	exit(-1);
}