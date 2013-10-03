%{
#define YYERROR_VERBOSE 1

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "logger.h"
#include "table.h"

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int numLines;
 
void yyerror(const char *s);

//& vs && | vs || ~
//unary minus and plus
//true and false?
%}

%union
{ 
	int int_val;
	char * name_ptr; 
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


%left OR_SYMBOL
%left AND_SYMBOL
%right NOT_SYMBOL
%nonassoc LESS_SYMBOL LESS_EQUAL_SYMBOL NOT_EQUAL_SYMBOL EQUAL_SYMBOL GREAT_EQUAL_SYMBOL GREAT_SYMBOL 
%left ADD_SYMBOL SUB_SYMBOL
%left MULT_SYMBOL DIV_SYMBOL PERCENT_SYMBOL
%right UNARY_MINUS_SYMBOL

%type <int_val> Expression
%type <int_val> ConstExpression

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

ConstantDecl 		: CONST_SYMBOL ID_SYMBOL EQUAL_SYMBOL ConstExpression SEMI_COLON_SYMBOL ConstantStuff
			 		;

ConstantStuff		:
					| ID_SYMBOL EQUAL_SYMBOL ConstExpression SEMI_COLON_SYMBOL ConstantStuff
					;

ProcFunc 			: ProcedureDecl ProcFunc
		 			| FunctionDecl ProcFunc
					|
					;

ProcedureDecl 		: PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL FORWARD_SYMBOL 							  SEMI_COLON_SYMBOL
			  		| PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL Body SEMI_COLON_SYMBOL
			  		;

FunctionDecl 		: FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL 
					  FORWARD_SYMBOL SEMI_COLON_SYMBOL
			 		| FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL Body 	  SEMI_COLON_SYMBOL
			 		;

FormalParameters 	: 
				 	| VAR_SYMBOL IdentList COLON_SYMBOL Type ParamStuff
				 	| IdentList COLON_SYMBOL Type ParamStuff
				 	;

ParamStuff 			: SEMI_COLON_SYMBOL VAR_SYMBOL IdentList COLON_SYMBOL Type ParamStuff
		   			| SEMI_COLON_SYMBOL IdentList COLON_SYMBOL Type ParamStuff
		   			|
		   			;

Body 				: ConstantDecl TypeDecl VarDecl Block
	 				| ConstantDecl TypeDecl Block
	 				| ConstantDecl VarDecl Block
	 				| ConstantDecl Block
	 				| TypeDecl VarDecl Block
	 				| TypeDecl Block
	 				| VarDecl Block
	 				| Block
	 				;

Block 				: BEGIN_SYMBOL StatementSequence END_SYMBOL
	  				;

TypeDecl 			: TYPE_SYMBOL ID_SYMBOL EQUAL_SYMBOL Type SEMI_COLON_SYMBOL TypeStuff
					;

TypeStuff			:
					| ID_SYMBOL EQUAL_SYMBOL Type SEMI_COLON_SYMBOL TypeStuff
					;

Type 				: SimpleType
					| RecordType
					| ArrayType
					;

SimpleType			: ID_SYMBOL
					;

RecordType			: RECORD_SYMBOL RecordStuff END_SYMBOL
					;

RecordStuff			: IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL RecordStuff
					|
					;

ArrayType			: ARRAY_SYMBOL LEFT_SQUARE_SYMBOL ConstExpression COLON_SYMBOL ConstExpression RIGHT_SQUARE_SYMBOL OF_SYMBOL Type
					;

IdentList			: ID_SYMBOL IdentStuff
					;

IdentStuff			: 
					| COMMA_SYMBOL ID_SYMBOL IdentStuff
					;

VarDecl				: VAR_SYMBOL IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL VarStuff
					;

VarStuff			: 
					| IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL VarStuff
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

ConstExpression 	: ConstExpression OR_SYMBOL ConstExpression 
					| ConstExpression AND_SYMBOL ConstExpression
					| ConstExpression EQUAL_SYMBOL ConstExpression
					| ConstExpression NOT_EQUAL_SYMBOL ConstExpression
					| ConstExpression LESS_EQUAL_SYMBOL ConstExpression
					| ConstExpression GREAT_EQUAL_SYMBOL ConstExpression
					| ConstExpression LESS_SYMBOL ConstExpression
					| ConstExpression GREAT_SYMBOL ConstExpression
					| ConstExpression ADD_SYMBOL ConstExpression
					| ConstExpression SUB_SYMBOL ConstExpression
					| ConstExpression MULT_SYMBOL ConstExpression
					| ConstExpression DIV_SYMBOL ConstExpression
					| ConstExpression PERCENT_SYMBOL ConstExpression
					| NOT_SYMBOL ConstExpression
					| SUB_SYMBOL ConstExpression %prec UNARY_MINUS_SYMBOL
					| LEFT_BRACE_SYMBOL ConstExpression RIGHT_BRACE_SYMBOL
					| INTEGER_SYMBOL
					| CHARACTER_SYMBOL
					| STRING_SYMBOL
					| ID_SYMBOL
					;
%%

//inputfile, outputfile, -v (print to console)
int main(int argc, char ** argv)
{
	argc--, argv++;
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