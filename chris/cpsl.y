%{
#include <iostream>
#include "Symbol_Table.hpp"
#define YYERROR_VERBOSE 1
extern int yylex();
extern int yyparse();

void yyerror(const char *s);
%}
/*Type symbols*/
%token <ival> INTSY <sval> STRINGSY <sval> IDENTSY <cval> CHARSY
/*Keyword symbols*/
%token ARRAYSY ELSESY IFSY RECORDSY TOSY BEGINSY ELSEIFSY OFSY
%token REPEATSY TYPESY CHRSY ENDSY ORDSY RETURNSY UNTILSY CONSTSY
%token FORSY PREDSY STOPSY VARSY DOSY FORWARDSY PROCEDURESY SUCCSY
%token WHILESY DOWNTOSY FUNCTIONSY READSY THENSY WRITESY
/*Operator symbols*/
%token PLUSSY NOTEQUALSY SEMICOLONSY MINUSSY LESSTHANSY LEFTPARENSY
%token MULTIPLYSY LESSEQUALSY RIGHTPARENSY DIVIDESY GREATERTHANSY
%token LEFTBRACKETSY ANDSY GREATEREQUALSY RIGHTBRACKETSY ORSY
%token PERIODSY NOTSY COMMASY MODSY ASSIGNSY COLONSY EQUALSY
%left ORSY
%left ANDSY
%right NOTSY
%nonassoc EQUALSY NOTEQUALSY LESSTHANSY LESSEQUALSY GREATERTHANSY GREATEREQUALSY
%left PLUSSY MINUSSY
%left MULTIPLYSY DIVIDESY MODSY
%right UNMINUSSY
%union
{
	int ival;
	char cval;
	char* sval;
}
%%
Program:ConstantDecl TypeDecl VarDecl ProcedureFunctionDecl Block PERIODSY;

Empty:;

ConstantDecl:CONSTSY IDENTSY ASSIGNSY ConstExpression SEMICOLONSY ConstantDecl
			|Empty
			;

ProcedureFunctionDecl:ProcedureDecl ProcedureFunctionDecl
					 |FunctionDecl ProcedureFunctionDecl
					 |Empty
					 ;

ProcedureDecl:PROCEDURESY IDENTSY LEFTPARENSY FormalParameters RIGHTPARENSY SEMICOLONSY FORWARDSY SEMICOLONSY
			 |PROCEDURESY IDENTSY LEFTPARENSY FormalParameters RIGHTPARENSY SEMICOLONSY Body SEMICOLONSY
			 ;

FunctionDecl: FUNCTIONSY IDENTSY LEFTPARENSY FormalParameters RIGHTPARENSY COLONSY Type SEMICOLONSY FORWARDSY SEMICOLONSY
			 |FUNCTIONSY IDENTSY LEFTPARENSY FormalParameters RIGHTPARENSY COLONSY Type SEMICOLONSY Body SEMICOLONSY
			 ;

FormalParameters:VARSY IdentList COLONSY Type SEMICOLONSY FormalParameters
				|IdentList COLONSY Type SEMICOLONSY FormalParameters
				|Empty
				;

Body:ConstantDecl TypeDecl VarDecl Block;

Block:BEGINSY StatementSequence ENDSY;

TypeDecl:TYPESY IDENTSY ASSIGNSY Type SEMICOLONSY InnerTypeDecl
		|Empty
		;

InnerTypeDecl:IDENTSY ASSIGNSY Type SEMICOLONSY InnerTypeDecl
			 |Empty
			 ;

Type:SimpleType
	|RecordType
	|ArrayType
	;

SimpleType:IDENTSY;

RecordType:RECORDSY InnerRecordType ENDSY;

InnerRecordType:IdentList COLONSY Type SEMICOLONSY InnerRecordType
			   |Empty
			   ;

ArrayType:ARRAYSY LEFTBRACKETSY ConstExpression COLONSY ConstExpression RIGHTBRACKETSY OFSY Type;

IdentList:IDENTSY InnerIdentList{$<sval>$=$1;}
		 ;

InnerIdentList:COMMASY IDENTSY InnerIdentList
			  |Empty
			  ;

VarDecl:VARSY IdentList COLONSY Type SEMICOLONSY InnerVarDecl{std::cout << "Variable Declaration " << $<sval>2 << '\n';}
	   |Empty
	   ;

InnerVarDecl:IdentList COLONSY Type SEMICOLONSY InnerVarDecl{std::cout << "Variable Declaration\n";}
		    |Empty
			;

StatementSequence:Statement InnerStatementSequence;

InnerStatementSequence:SEMICOLONSY Statement InnerStatementSequence
					  |Empty
					  ;

Statement:Assignment
		 |IfStatement
		 |WhileStatement
		 |RepeatStatement
		 |ForStatement
		 |StopStatement
		 |ReturnStatement
		 |ReadStatement
		 |WriteStatement
		 |ProcedureCall
		 |NullStatement
		 ;

Assignment:LValue ASSIGNSY Expression;

IfStatement:IFSY Expression THENSY StatementSequence ElseIfStatement ElseStatement ENDSY;

ElseIfStatement:ELSEIFSY Expression THENSY StatementSequence ElseIfStatement
			   |Empty
			   ;

ElseStatement:ELSESY StatementSequence
			 |Empty
			 ;

WhileStatement:WHILESY Expression DOSY StatementSequence ENDSY;

RepeatStatement:REPEATSY StatementSequence UNTILSY Expression;

ForStatement:FORSY IDENTSY ASSIGNSY Expression ToDownto Expression DOSY StatementSequence ENDSY;

ToDownto:TOSY|DOWNTOSY;

StopStatement:STOPSY;

ReturnStatement:RETURNSY InnerReturn;

InnerReturn:Expression
		   |Empty
		   ;

ReadStatement:READSY RIGHTPARENSY LValue InnerReadStatement RIGHTPARENSY;

InnerReadStatement:COMMASY LValue InnerReadStatement
				  |Empty
				  ;

WriteStatement:WRITESY LEFTPARENSY Expression InnerWriteStatement RIGHTPARENSY;

InnerWriteStatement:COMMASY Expression InnerWriteStatement
				   |Empty
				   ;

ProcedureCall:IDENTSY LEFTPARENSY InnerProcedureCall RIGHTPARENSY;

InnerProcedureCall:Expression InnerInnerProcedureCall
				  |Empty
				  ;

InnerInnerProcedureCall:COMMASY Expression InnerInnerProcedureCall
					   |Empty
					   ;

NullStatement:Empty;

Expression:Expression ORSY Expression
		  |Expression ANDSY Expression
		  |Expression EQUALSY Expression
		  |Expression NOTEQUALSY Expression
		  |Expression LESSEQUALSY Expression
		  |Expression GREATEREQUALSY Expression
		  |Expression LESSTHANSY Expression
		  |Expression GREATERTHANSY Expression
		  |Expression PLUSSY Expression
		  |Expression MINUSSY Expression
		  |Expression MULTIPLYSY Expression
		  |Expression DIVIDESY Expression
		  |Expression MODSY Expression
		  |NOTSY Expression
		  |MINUSSY Expression %prec UNMINUSSY
		  |LEFTPARENSY Expression RIGHTPARENSY 
		  |ProcedureCall
		  |CHRSY LEFTPARENSY Expression RIGHTPARENSY
		  |ORDSY LEFTPARENSY Expression RIGHTPARENSY
		  |PREDSY LEFTPARENSY Expression RIGHTPARENSY
		  |SUCCSY LEFTPARENSY Expression RIGHTPARENSY
		  |LValue
		  ;

LValue:IDENTSY InnerLValue;

InnerLValue:InnerLValue PERIODSY IDENTSY
		   |InnerLValue LEFTBRACKETSY Expression RIGHTBRACKETSY
		   |Empty
		   ;

ConstExpression:ConstExpression ORSY ConstExpression
			   |ConstExpression ANDSY ConstExpression
			   |ConstExpression EQUALSY ConstExpression
			   |ConstExpression NOTEQUALSY ConstExpression
			   |ConstExpression LESSEQUALSY ConstExpression
			   |ConstExpression GREATEREQUALSY ConstExpression
			   |ConstExpression LESSTHANSY ConstExpression
			   |ConstExpression GREATERTHANSY ConstExpression
			   |ConstExpression PLUSSY ConstExpression
			   |ConstExpression MINUSSY ConstExpression
			   |ConstExpression MULTIPLYSY ConstExpression
			   |ConstExpression DIVIDESY ConstExpression
			   |ConstExpression MODSY ConstExpression
			   |NOTSY ConstExpression
			   |MINUSSY ConstExpression %prec UNMINUSSY
			   |LEFTPARENSY ConstExpression RIGHTPARENSY
			   |INTSY
			   |CHARSY
			   |STRINGSY
			   |IDENTSY
			   ;

%%
void yyerror(const char *s)
{
	std::cout << s << '\n';
	exit(-1);
}
