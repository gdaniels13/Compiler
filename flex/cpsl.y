%{
#include <iostream>
#include <string>
#include <cstdio>
#define YYERROR_VERBOSE 1


extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int numLines;

int yylex();

int yyerror(const char *p) 
{ 
	fprintf(stdout, "%s", p);
	std::cout << " on line "<< numLines  << std::endl; 

}

%}


%token ID_SYMBOL
%token CHARACTER_SYMBOL
%token INTEGER_SYMBOL
%token STRING_SYMBOL
%token ARRAY_SYMBOL 
%token BEGIN_SYMBOL 
%token ELSE_SYMBOL
%token ELSEIF_SYMBOL
%token IF_SYMBOL
%token OF_SYMBOL
%token RECORD_SYMBOL
%token REPEAT_SYMBOL
%token TO_SYMBOL 
%token TYPE_SYMBOL
%token CHR_SYMBOL
%token CONST_SYMBOL
%token DO_SYMBOL
%token END_SYMBOL
%token FOR_SYMBOL
%token FORWARD_SYMBOL 
%token ORD_SYMBOL
%token PRED_SYMBOL
%token PROCEDURE_SYMBOL
%token RETURN_SYMBOL
%token STOP_SYMBOL
%token SUCC_SYMBOL
%token UNTIL_SYMBOL 
%token VAR_SYMBOL
%token WHILE_SYMBOL
%token DOWNTO_SYMBOL
%token FUNCTION_SYMBOL
%token READ_SYMBOL
%token THEN_SYMBOL
%token WRITE_SYMBOL
%token ASSIGN_SYMBOL
%token ADD_SYMBOL
%token SUB_SYMBOL
%token MULT_SYMBOL
%token DIV_SYMBOL
%token AND_SYMBOL
%token OR_SYMBOL
%token NOT_SYMBOL
%token EQUAL_SYMBOL
%token NOT_EQUAL_SYMBOL
%token LESS_SYMBOL
%token LESS_EQUAL_SYMBOL
%token GREAT_SYMBOL
%token GREAT_EQUAL_SYMBOL
%token DOT_SYMBOL
%token COMMA_SYMBOL
%token COLON_SYMBOL
%token SEMI_COLON_SYMBOL
%token LEFT_BRACE_SYMBOL
%token RIGHT_BRACE_SYMBOL
%token LEFT_SQUARE_SYMBOL
%token RIGHT_SQUARE_SYMBOL
%token PERCENT_SYMBOL

%union
{	
	int int_val;
	char *name_ptr;
}


%left 		OR_SYMBOL
%left 		AND_SYMBOL
%right 		NOT_SYMBOL

%nonassoc 	LESS_SYMBOL 
%nonassoc 	LESS_EQUAL_SYMBOL
%nonassoc 	GREAT_SYMBOL
%nonassoc 	GREAT_EQUAL_SYMBOL
%nonassoc 	EQUAL_SYMBOL
%nonassoc 	NOT_EQUAL_SYMBOL

%left		ADD_SYMBOL SUB_SYMBOL
%left 		MULT_SYMBOL DIV_SYMBOL PERCENT_SYMBOL
%right 		UMINUS



%%
Program:  ConstantDecl TypeDecl VarDecl subProgram Block DOT_SYMBOL

		;

		subProgram: ProcedureDecl subProgram
					| FunctionDecl subProgram
					| /*empty*/
					;


/* 3.1.1 */
ConstantDecl: CONST_SYMBOL ID_SYMBOL EQUAL_SYMBOL ConstExpression SEMI_COLON_SYMBOL ConstantDecl
					|
					;

/*3.1.2*/ 
ProcedureDecl: PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL FORWARD_SYMBOL SEMI_COLON_SYMBOL
			| PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL Body
			;

FunctionDecl: FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL FORWARD_SYMBOL SEMI_COLON_SYMBOL
			|	FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL Body SEMI_COLON_SYMBOL
			;

FormalParameters:  /*comment*/
			| VAR_SYMBOL IdentList COLON_SYMBOL Type subFormalParameters /*do i need a semi colon here*/
			| IdentList COLON_SYMBOL Type subFormalParameters /*do i need a semi colon here*/
			;

	subFormalParameters: SEMI_COLON_SYMBOL VAR_SYMBOL IdentList COLON_SYMBOL Type subFormalParameters 
			|  SEMI_COLON_SYMBOL IdentList COLON_SYMBOL Type subFormalParameters 
			|
			;

Body: ConstantDecl TypeDecl VarDecl Block
	;


Block: BEGIN_SYMBOL StatementSequence END_SYMBOL
	;

/*3.1.3*/

TypeDecl:	TYPE_SYMBOL ID_SYMBOL EQUAL_SYMBOL SEMI_COLON_SYMBOL subTypeDecl
		|
		;

		subTypeDecl: ID_SYMBOL EQUAL_SYMBOL Type SEMI_COLON_SYMBOL subTypeDecl
					| 
					;

Type : SimpleType
	| RecordType
	|ArrayType
	;

SimpleType: ID_SYMBOL
	;

RecordType: RECORD_SYMBOL subRecordType END_SYMBOL
	;

	subRecordType: IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL subRecordType
				|	/*empty*/
				;

ArrayType: ARRAY_SYMBOL RIGHT_SQUARE_SYMBOL ConstExpression COLON_SYMBOL ConstExpression RIGHT_SQUARE_SYMBOL OF_SYMBOL Type
		;

IdentList: ID_SYMBOL subIdentList
		;

		subIdentList: COMMA_SYMBOL ID_SYMBOL subIdentList
					| /*empty*/
					;
/*3.1.4*/

VarDecl: VAR_SYMBOL IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL subVarDecl
		;

		subVarDecl:IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL subVarDecl
				| /*empty*/
				;

/*3.2*/

StatementSequence: Statement subStatementSequence
				;

		subStatementSequence: SEMI_COLON_SYMBOL Statement subStatementSequence
				|
				;

Statement: Assignment
	| IfStatement
	| WhileStatement
	| RepeatStatment
	| ForStatement
	| StopStatement
	| ReturnStatment
	| ReadStatement
	| WriteStatement
	| ProcedureCall
	| NullStatement
	;

Assignment: LValue ASSIGN_SYMBOL ConstExpression	
		;


IfStatement: IF_SYMBOL Expression THEN_SYMBOL StatementSequence subIfStatment subElse END_SYMBOL
			
			;

		subIfStatment: ELSEIF_SYMBOL Expression THEN_SYMBOL StatementSequence subIfStatment
					| /*empty*/
					; 
		subElse: ELSE_SYMBOL StatementSequence
		|
		;


WhileStatement: WHILE_SYMBOL Expression DO_SYMBOL StatementSequence END_SYMBOL
			;

RepeatStatment: REPEAT_SYMBOL StatementSequence UNTIL_SYMBOL Expression
				;

ForStatement: FOR_SYMBOL ID_SYMBOL ASSIGN_SYMBOL Expression TO_SYMBOL Expression DO_SYMBOL StatementSequence END_SYMBOL
			;

StopStatement: STOP_SYMBOL
			;

ReturnStatment: RETURN_SYMBOL Expression
			| RETURN_SYMBOL 
			;

ReadStatement: READ_SYMBOL LEFT_BRACE_SYMBOL LValue subReadStatement RIGHT_BRACE_SYMBOL
			;

		subReadStatement: COMMA_SYMBOL LValue subReadStatement
						| /*empty*/
						;


WriteStatement: WRITE_SYMBOL LEFT_BRACE_SYMBOL Expression subWriteStatement RIGHT_BRACE_SYMBOL
			;

		subWriteStatement: COMMA_SYMBOL Expression subWriteStatement
						| /*empty*/
						;


ProcedureCall: ID_SYMBOL LEFT_BRACE_SYMBOL RIGHT_BRACE_SYMBOL  
			| ID_SYMBOL LEFT_BRACE_SYMBOL Expression subProcedureCall RIGHT_BRACE_SYMBOL 
			;

		subProcedureCall: COMMA_SYMBOL Expression subProcedureCall
						| /*empty*/
						;

NullStatement: /*empty*/
			;


/*3.3*/


Expression: subExpression Operator subExpression
			| NOT_SYMBOL Expression
			| SUB_SYMBOL Expression %prec UMINUS
			| LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL
			| ID_SYMBOL LEFT_BRACE_SYMBOL subExpressionIdent RIGHT_BRACE_SYMBOL
			| CHR_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL
			| ORD_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL
			| PRED_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL
			| SUCC_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL
			| subExpression
			;

	subExpression: LValue
					|INTEGER_SYMBOL
					|CHARACTER_SYMBOL
					|STRING_SYMBOL
					;

Operator: 		OR_SYMBOL
				| AND_SYMBOL
				| EQUAL_SYMBOL
				| NOT_EQUAL_SYMBOL
				| LESS_EQUAL_SYMBOL
				| GREAT_EQUAL_SYMBOL
				| LESS_SYMBOL
				| GREAT_SYMBOL
				| ADD_SYMBOL
				| SUB_SYMBOL
				| MULT_SYMBOL
				| DIV_SYMBOL
				| PERCENT_SYMBOL
				;

	subExpressionIdent: Expression subSubExpressionIndent
						| /*empty*/
						;

		subSubExpressionIndent: COMMA_SYMBOL Expression subSubExpressionIndent
						| /*empty*/
						;


LValue: ID_SYMBOL
		| ID_SYMBOL DOT_SYMBOL ID_SYMBOL
		| ID_SYMBOL LEFT_SQUARE_SYMBOL Expression RIGHT_SQUARE_SYMBOL
		;

ConstExpression: ConstExpression OR_SYMBOL ConstExpression
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
			| SUB_SYMBOL ConstExpression %prec UMINUS
			| LEFT_BRACE_SYMBOL ConstExpression RIGHT_BRACE_SYMBOL
			| INTEGER_SYMBOL
			| CHARACTER_SYMBOL
			| STRING_SYMBOL
			| ID_SYMBOL
			;




%%

int main(int argc, char ** argv)
{
	argc--, argv++;
	if(argc > 0)
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
	yyparse();
	return 0;
};
