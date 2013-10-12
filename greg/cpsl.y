%{
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <cstdio>
#include "Symbols.h"
#include "logger.h"
#include "SymbolTable.h"

#define YYERROR_VERBOSE 1


extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int numLines;

int yylex();

int yyerror(const char *p) 
{ 
	Logger::logError(p,numLines);
}

void debug(std::string t)
{
	//std::cout<<t<<std::endl;
}

%}




%token <name_ptr> ID_SYMBOL
%token <name_ptr> CHARACTER_SYMBOL
%token <int_val> INTEGER_SYMBOL
%token  ARRAY_SYMBOL 
%token  BEGIN_SYMBOL 
%token  ELSE_SYMBOL
%token  ELSEIF_SYMBOL
%token  IF_SYMBOL
%token  OF_SYMBOL
%token  RECORD_SYMBOL
%token  REPEAT_SYMBOL
%token  TO_SYMBOL 
%token  TYPE_SYMBOL
%token  CHR_SYMBOL
%token  CONST_SYMBOL
%token  DO_SYMBOL
%token  END_SYMBOL
%token  FOR_SYMBOL
%token  FORWARD_SYMBOL 
%token  ORD_SYMBOL
%token  PRED_SYMBOL
%token  PROCEDURE_SYMBOL
%token  RETURN_SYMBOL
%token  STOP_SYMBOL
%token  SUCC_SYMBOL
%token  UNTIL_SYMBOL 
%token  VAR_SYMBOL
%token  WHILE_SYMBOL
%token  DOWNTO_SYMBOL
%token  FUNCTION_SYMBOL
%token  READ_SYMBOL
%token  THEN_SYMBOL
%token  WRITE_SYMBOL
%token  ASSIGN_SYMBOL
%token <name_ptr> ADD_SYMBOL
%token <name_ptr> SUB_SYMBOL
%token <name_ptr> MULT_SYMBOL
%token <name_ptr> DIV_SYMBOL
%token <name_ptr> AND_SYMBOL
%token <name_ptr> OR_SYMBOL
%token <name_ptr> NOT_SYMBOL
%token <name_ptr> EQUAL_SYMBOL
%token <name_ptr> NOT_EQUAL_SYMBOL
%token <name_ptr> LESS_SYMBOL
%token <name_ptr> LESS_EQUAL_SYMBOL
%token <name_ptr> GREAT_SYMBOL
%token <name_ptr> GREAT_EQUAL_SYMBOL
%token  DOT_SYMBOL
%token  COMMA_SYMBOL
%token  COLON_SYMBOL
%token  SEMI_COLON_SYMBOL
%token  LEFT_BRACE_SYMBOL
%token  RIGHT_BRACE_SYMBOL
%token  LEFT_SQUARE_SYMBOL
%token  RIGHT_SQUARE_SYMBOL
%token <name_ptr> PERCENT_SYMBOL
%token	<name_ptr> STRING_SYMBOL

%union
{	
	int int_val;
	char *name_ptr;
	std::vector<std::string> * id_list;
	std::vector<std::shared_ptr<Variable>> * form_params;
	void* none_type;
	Symbol* symbol_type;
	std::vector<std::pair<std::vector<std::string>*,std::string>>* record_type;
	Constant * const_type;
	yytokentype * token_type;
}


%type <form_params> subFormalParameters
%type <id_list> IdentList subIdentList
%type <name_ptr> Type SimpleType RecordType ArrayType
%type <record_type> subRecordType
%type <form_params> FormalParameters
%type <none_type> VarDecl subVarDecl TypeDecl subTypeDecl ConstantDecl subConstantDecl Block Body ProcedureDecl FunctionDecl ScopeIt
%type <const_type> ConstExpression 

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

		subProgram: subProgram ProcedureDecl 
					|  subProgram FunctionDecl 
					| /*empty*/ 
					;


/* 3.1.1 */
ConstantDecl: CONST_SYMBOL ID_SYMBOL EQUAL_SYMBOL ConstExpression SEMI_COLON_SYMBOL subConstantDecl {SymbolTable::addConstant($2,$4);}
					|{}
					;
		subConstantDecl:  ID_SYMBOL EQUAL_SYMBOL ConstExpression SEMI_COLON_SYMBOL subConstantDecl {SymbolTable::addConstant($1,$3);}
						|{} 
						;

/*3.1.2*/ 
ProcedureDecl: PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL FORWARD_SYMBOL SEMI_COLON_SYMBOL 
				{SymbolTable::addFunction($2,$4, "NONE", true);}

			| PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL Body SEMI_COLON_SYMBOL 
				{SymbolTable::addFunction($2,$4, "NONE", false); SymbolTable::popScope();}
			;

FunctionDecl: FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL FORWARD_SYMBOL SEMI_COLON_SYMBOL 
				{SymbolTable::addFunction($2,$4, $7, true);}
			
			|	FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL Body SEMI_COLON_SYMBOL 
				{SymbolTable::addFunction($2,$4, $7, false);	SymbolTable::popScope();}
			
			;

FormalParameters:  /*empty*/ {$$ = new std::vector<std::shared_ptr<Variable>>();}
			| VAR_SYMBOL IdentList COLON_SYMBOL Type subFormalParameters {$$ = SymbolTable::makeVarList($2,$5,$4);} 
			| IdentList COLON_SYMBOL Type subFormalParameters {$$ = SymbolTable::makeVarList($1,$4,$3);}
			;


	subFormalParameters: SEMI_COLON_SYMBOL VAR_SYMBOL IdentList COLON_SYMBOL Type subFormalParameters {$$ = SymbolTable::makeVarList($3,$6,$5);}
			|  SEMI_COLON_SYMBOL IdentList COLON_SYMBOL Type subFormalParameters {$$ = SymbolTable::makeVarList($2,$5,$4);}
			| {$$ = new std::vector<std::shared_ptr<Variable>>();}																							
			;

Body: ScopeIt ConstantDecl TypeDecl VarDecl Block 
	;

ScopeIt: {SymbolTable::pushScope("tempScopeName");}
	;



Block: BEGIN_SYMBOL StatementSequence END_SYMBOL {}
	;

/*3.1.3*/

TypeDecl:	TYPE_SYMBOL subTypeDecl 
		|
		;

		subTypeDecl: subTypeDecl ID_SYMBOL EQUAL_SYMBOL Type SEMI_COLON_SYMBOL  { SymbolTable::makeType($2,$4); debug("making"); debug($2);}
					| 			{}
					;

Type : SimpleType {$<name_ptr>$ = $1; debug("simpleType"); }
	| ArrayType {$<name_ptr>$ = $1; 	debug("ArrayType");}
	| RecordType {$<name_ptr>$ = $1; debug("record Type;");}
	;

SimpleType: ID_SYMBOL {$<name_ptr>$ =$1;}
	;

RecordType: RECORD_SYMBOL subRecordType END_SYMBOL {$<name_ptr>$ = SymbolTable::createRecord(*$2);}
	;

	subRecordType: IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL subRecordType 
							{ $5->push_back(std::make_pair($1,$3)); $$=$5; }
				|	/*empty*/ {$$ = new std::vector<std::pair<std::vector<std::string>*,std::string>>();}
				;

ArrayType: ARRAY_SYMBOL LEFT_SQUARE_SYMBOL ConstExpression COLON_SYMBOL ConstExpression RIGHT_SQUARE_SYMBOL OF_SYMBOL Type 
					{$$ = SymbolTable::makeArray($3,$5,$8);}
		;

IdentList: ID_SYMBOL subIdentList 							{$2->push_back($1); $$ = $2;}
		;

		subIdentList: COMMA_SYMBOL ID_SYMBOL subIdentList	{$3->push_back($2); $$ = $3;}
					| /*empty*/								{$$= new std::vector<std::string>();}
					;
/*3.1.4*/

VarDecl: VAR_SYMBOL IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL subVarDecl
											{ SymbolTable::addVarDecl($4,$2);  }
		|  {}
		;

		subVarDecl:IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL subVarDecl 
											{ SymbolTable::addVarDecl($3,$1);  }
				| /*empty*/ {}
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

ForStatement: FOR_SYMBOL ID_SYMBOL ASSIGN_SYMBOL Expression subForType Expression DO_SYMBOL StatementSequence END_SYMBOL
			;
		subForType: DOWNTO_SYMBOL
					| TO_SYMBOL
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

LValue: ID_SYMBOL
		| LValue DOT_SYMBOL LValue
		| LValue LEFT_SQUARE_SYMBOL Expression RIGHT_SQUARE_SYMBOL
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


ConstExpression: ConstExpression OR_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression AND_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression EQUAL_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression NOT_EQUAL_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression LESS_EQUAL_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression GREAT_EQUAL_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression LESS_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression GREAT_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression ADD_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression SUB_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression MULT_SYMBOL ConstExpression  {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression DIV_SYMBOL ConstExpression  {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| ConstExpression PERCENT_SYMBOL ConstExpression {$$ = SymbolTable::evaluateConstantExpression($1,$3,$2);}
			| NOT_SYMBOL ConstExpression {$$ = $2->makeBoolNot();}
			| SUB_SYMBOL ConstExpression %prec UMINUS {$$ = $2->makeNegative();}
			| LEFT_BRACE_SYMBOL ConstExpression RIGHT_BRACE_SYMBOL {$$ = $2;}
			| INTEGER_SYMBOL 			{$$ = new Constant($1);}
			| CHARACTER_SYMBOL			{$$ = new Constant($1);}
			| STRING_SYMBOL  			{$$ = new Constant($1, STR);}	
			| ID_SYMBOL 	 			{$$ = new Constant($1, ID);}
			;		
%%

int main(int argc, char ** argv)
{
	argc--, argv++;
	if(argc > 0)
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
	argc--,argv++;
	Logger::SetLevel(ERROR);
	if(argc>0)
	{
		if(argv[0][1] == 'v')
		{
			std::cout<<"now verbose\n";
			SymbolTable::setVerbose(true);
		}
	}
	yyparse();

	if(SymbolTable::isVerbose())
	{
//		std::cout<<"printing table:\n";
		SymbolTable::print();
	}
	std::cout<<"finished Parsing\n";
	return 0;
};
