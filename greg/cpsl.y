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
 
extern "C" void yyerror(const char *s);

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
	Expression * exp_type;
	std::deque<Expression*> * exp_list_type;
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


%type <exp_type> Assignment
%type <exp_type> ArrayBegin
//%type Block
//%type Body
//%type ConstantDecl
//%type ConstantStuff
%type <const_type> ConstExpression
%type <none_type> ElseStatement
%type <exp_list_type> ExpressionList
%type <exp_type> Expression
%type <formalParameter> FormalParameters
//%type ForStatement
//%type FunctionDecl
%type <name_ptr> FuncStuff
%type <identList> IdentList
%type <identList> IdentStuff
%type <none_type> IfStatement
%type <none_type> IfStuff
%type <exp_type> IncrementingFor
%type <exp_type> DecrementingFor
%type <none_type> BeginIfStuff
%type <int_val> BeginIfStatement
%type <exp_type>LValue
//%type LValueStuff
//%type NullStatement
%type <formalParameter> ParamStuff
%type <none_type> PreIfStuff
%type <none_type> ProcedureCall
//%type ProcedureDecl
//%type ProcedureStuff
//%type ProcFunc
%type <name_ptr> PreFuncBody
%type <name_ptr> PreProcBody
%type <name_ptr> ProcStuff
//%type Program
%type <nonetype> ReadStatement
%type <exp_list_type> ReadStuff
%type <exp_type> RecordBegin
%type <type> RecordType
%type <typeList> RecordStuff
//%type RepeatStatement
//%type ReturnStatement
%type <type> SimpleType
//%type Statement
//%type StatementSequence
//%type StatementStuff
%type <none_type> StopStatement
%type <type> Type
//%type TypeDecl
//%type TypeStuff
//%type VarDecl
//%type VarStuff
//%type WhileStatement
%type <none_type> WriteStatement
//%type WriteStuff
%left OR_SYMBOL
%left AND_SYMBOL
%right NOT_SYMBOL
%nonassoc LESS_SYMBOL LESS_EQUAL_SYMBOL NOT_EQUAL_SYMBOL EQUAL_SYMBOL GREAT_EQUAL_SYMBOL GREAT_SYMBOL 
%left ADD_SYMBOL SUB_SYMBOL
%left MULT_SYMBOL DIV_SYMBOL PERCENT_SYMBOL
%right UNARY_MINUS_SYMBOL

%%


Program			    : BeginMain Block DOT_SYMBOL {Output::endFile();}
					;

//done
BeginMain			: BeginStuff ProcFunc 		 {Output::out("_begin:");}

BeginStuff			: ConstantDecl TypeDecl VarDecl {Output::out("J _begin");}
					| ConstantDecl TypeDecl {Output::out("J _begin");}
					| ConstantDecl VarDecl {Output::out("J _begin");}
					| ConstantDecl {Output::out("J _begin");}
					| TypeDecl VarDecl {Output::out("J _begin");}
					| TypeDecl {Output::out("J _begin");}
					| VarDecl {Output::out("J _begin");}
					|
					;

//done
ConstantDecl 		: CONST_SYMBOL ID_SYMBOL EQUAL_SYMBOL ConstExpression SEMI_COLON_SYMBOL ConstantStuff 
					{Table::MakeConst($2,$4);}
			 		;
//done
ConstantStuff		:
					| ID_SYMBOL EQUAL_SYMBOL ConstExpression SEMI_COLON_SYMBOL ConstantStuff {Table::MakeConst($1,$3);}
					;
//done
ProcFunc 			: ProcedureDecl ProcFunc
		 			| FunctionDecl ProcFunc
					|
					;
//done
ProcedureDecl 		: PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL FORWARD_SYMBOL SEMI_COLON_SYMBOL 
							{Element element(new Function($2,*$4,$2,true)); Table::InsertElement($2, element);}
			  		| PreProcBody Block SEMI_COLON_SYMBOL { Table::makeProcedureEpilog($1); Table::RemoveScope();}
			  		;
//done
PreProcBody			: ProcStuff BodyStuff {Table::makeProcedureProlog($1); $$ = $1;}
					;
//done
PreFuncBody			: FuncStuff BodyStuff {Table::makeProcedureProlog($1); $$ = $1;}
					;

//done
ProcStuff			: PROCEDURE_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL SEMI_COLON_SYMBOL 
						{Element element(new Function($2,*$4,$2,false)); Table::InsertElement($2, element); Table::AddScope($4); $$ = $2;}
					;
//done
FunctionDecl 		: FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL FORWARD_SYMBOL SEMI_COLON_SYMBOL  
										{Element element(new Function(std::shared_ptr<Type>($7),$2,*$4,$2,true)); Table::InsertElement($2, element);}
			 		|  PreFuncBody Block SEMI_COLON_SYMBOL {Table::makeProcedureEpilog($1); Table::RemoveScope();}
			 		;

//done
FuncStuff			: FUNCTION_SYMBOL ID_SYMBOL LEFT_BRACE_SYMBOL FormalParameters RIGHT_BRACE_SYMBOL COLON_SYMBOL Type SEMI_COLON_SYMBOL
                    	{
                    		Element element(new Function(std::shared_ptr<Type>($7),$2,*$4,$2,false)); 
                    		Table::InsertElement($2, element); 
                    		Table::AddScope($4);
                    		$$ = $2;
                    	}
					;

//done
FormalParameters 	: {$$ = new std::vector<std::shared_ptr<Var>>;}
				 	| VAR_SYMBOL IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($4,$2,$5);}
				 	| IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($3,$1,$4);}
				 	;

//done
ParamStuff 			: SEMI_COLON_SYMBOL VAR_SYMBOL IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($5,$3,$6);}
		   			| SEMI_COLON_SYMBOL IdentList COLON_SYMBOL Type ParamStuff {$$ = Table::MakeVars($4,$2,$5);}
		   			| {$$ = new std::vector<std::shared_ptr<Var>>;}
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

//done
Block 				: BEGIN_SYMBOL StatementSequence END_SYMBOL
	  				;

TypeDecl 			: TypeBlah TypeStuff 
					;

TypeBlah			: TYPE_SYMBOL ID_SYMBOL EQUAL_SYMBOL Type SEMI_COLON_SYMBOL 
							{
								$4->m_name = $2;
								Element e($4);
								Table::InsertElement($2, e);
							}
					;

TypeStuff			:
					| ID_SYMBOL EQUAL_SYMBOL Type SEMI_COLON_SYMBOL TypeStuff
							{
								$3->m_name = $1;
								Element e($3); 
								Table::InsertElement($1, e);
							}
					;

Type 				: SimpleType {$$ = $1;}
					| RecordType {$$ = $1;}
					| ArrayType {$$ = $1;}
					;

//done
SimpleType			: ID_SYMBOL {$$ = Table::MakeSimple($1);}
					;

RecordType			: RECORD_SYMBOL RecordStuff END_SYMBOL {$$ = Table::MakeRecord($2);}
					;

RecordStuff			: IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL RecordStuff {$$ = Table::MakeSubRecord($3,$5, $1);}
					| {$$ = new std::vector<std::shared_ptr<Type>>;}
					;

ArrayType			: ARRAY_SYMBOL LEFT_SQUARE_SYMBOL ConstExpression COLON_SYMBOL ConstExpression RIGHT_SQUARE_SYMBOL OF_SYMBOL Type 
						{$$ = new Array(Table::getSize($3),Table::getSize($5),std::shared_ptr<Type>($8),Table::getArraySize($3,$5,$8->m_size), $8->m_name);}
					;
//done
IdentList			: ID_SYMBOL IdentStuff {$2->push_back($1); $$ = $2;} 
					;

//done
IdentStuff			: {$$ = new std::vector<std::string>;}
					| COMMA_SYMBOL ID_SYMBOL IdentStuff {$3->push_back($2); $$ = $3;}
					;

//done
VarDecl				: VAR_SYMBOL IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL VarStuff 
						{Table::MakeVar($2,$4); delete $2; delete $4;}
					;

//done
VarStuff			: 
					| IdentList COLON_SYMBOL Type SEMI_COLON_SYMBOL VarStuff 
						{Table::MakeVar($1,$3); delete $1; delete $3;}
					;

//done
StatementSequence 	: Statement StatementStuff
					;

//done
StatementStuff		:
					| SEMI_COLON_SYMBOL Statement StatementStuff
					;

Statement 			: Assignment 		//done
					| IfStatement 		//done
					| WhileStatement	//done
					| RepeatStatement	//done
					| ForStatement		//done
					| StopStatement 	//done
					| ReturnStatement 	//done
					| ReadStatement 	//done
					| WriteStatement 	//done
					| ProcedureCall 	//done
					| NullStatement
					;

//done
Assignment			: LValue ASSIGN_SYMBOL Expression {$$ = Table::makeAssignment($1,$3);}
					;

//done
IfStatement			: BeginIfStatement StatementSequence IfStuff ElseStatement StatementSequence END_SYMBOL {Table::finishElseStatement();}
					| BeginIfStatement StatementSequence IfStuff END_SYMBOL {Table::finishIfStatement($1);}
					;
//done
ElseStatement		:	ELSE_SYMBOL {Table::finishSubIf();}
					;
//done
BeginIfStatement	: IF_SYMBOL Expression THEN_SYMBOL {$$ =  Table::makeBeginIfStatement($2);}
					;

//done
IfStuff				: {/*Empty*/}
					| BeginIfStuff StatementSequence IfStuff {/*Table::makeIfStuff();*/}
					;
//done
BeginIfStuff		: PreIfStuff ELSEIF_SYMBOL Expression THEN_SYMBOL { Table::makeIfStuff($3);}
					;
//done
PreIfStuff			: {Table::finishSubIf();}
					;

//done
WhileStatement		: WhileBegin  WhileMiddle StatementSequence END_SYMBOL {Table::endWhileLoop();}
					;
//done
WhileBegin			: WHILE_SYMBOL {Table::beginWhileLoop();}
					;
//done
WhileMiddle			:Expression DO_SYMBOL {Table::evaluateWhileCondition($1); }
					;

//done
RepeatStatement		: RepeatBegin StatementSequence UNTIL_SYMBOL Expression  {Table::finishRepeat( $4 );}
					;
//done
RepeatBegin			: REPEAT_SYMBOL {Table::beginRepeat();}
					;
//done
ForStatement		: IncrementingFor StatementSequence END_SYMBOL {Table::finishForLoop($1);}
					| DecrementingFor StatementSequence END_SYMBOL {Table::finishForLoop($1);}
					;
//done
IncrementingFor		: FOR_SYMBOL Assignment TO_SYMBOL Expression DO_SYMBOL {$$ = $4; Table::beginForLoop($2,$4, true);}
					;
//done
DecrementingFor		:  FOR_SYMBOL Assignment DOWNTO_SYMBOL Expression DO_SYMBOL {$$ = $4; Table::beginForLoop($2,$4, false);}
					; 

//done
StopStatement		: STOP_SYMBOL {Output::out("li\t $v0, 10\n syscall\n\n");}
					;

ReturnStatement		: RETURN_SYMBOL Expression   {Table::makeReturnStatement($2);}
					| RETURN_SYMBOL 			 {Table::makeReturnStatement(NULL);}
					;
//done
ReadStatement		: READ_SYMBOL LEFT_BRACE_SYMBOL LValue ReadStuff RIGHT_BRACE_SYMBOL 	{$4->push_front($3); Table::makeReadStatement($4);}
					;
//done
ReadStuff			: COMMA_SYMBOL LValue ReadStuff 	{$$ = $3; $3->push_front($2);	}
					|  									{$$ = new std::deque<Expression*>();}
					;
//done
WriteStatement		: WRITE_SYMBOL LEFT_BRACE_SYMBOL Expression ExpressionList RIGHT_BRACE_SYMBOL 
							{$4->push_front($3); Table::makeWriteStatement($4);}
					;


//done
ProcedureCall		: ID_SYMBOL LEFT_BRACE_SYMBOL Expression ExpressionList RIGHT_BRACE_SYMBOL
						{Table::makeProcedureCall($1,$3,$4);}
					| ID_SYMBOL LEFT_BRACE_SYMBOL RIGHT_BRACE_SYMBOL
						{Table::makeProcedureCall($1,NULL,NULL);}

					;

NullStatement		:
					;
//done
ExpressionList		: COMMA_SYMBOL Expression ExpressionList 	{	$$ = $3; $3->push_front($2);	}
					| 											{$$ = new std::deque<Expression*>();}
					;


Expression 			: Expression OR_SYMBOL Expression 											{$$ = Table::makeExpression($1,OR,$3);}
					| Expression AND_SYMBOL Expression 											{$$ = Table::makeExpression($1,AND,$3);}
					| Expression EQUAL_SYMBOL Expression 										{$$ = Table::makeExpression($1,EQUAL,$3);}
					| Expression NOT_EQUAL_SYMBOL Expression 									{$$ = Table::makeExpression($1,NOT_EQUAL,$3);}
					| Expression LESS_EQUAL_SYMBOL Expression 									{$$ = Table::makeExpression($1,LESS_EQUAL,$3);}
					| Expression GREAT_EQUAL_SYMBOL Expression 									{$$ = Table::makeExpression($1,GREAT_EQUAL,$3);}
					| Expression LESS_SYMBOL Expression 										{$$ = Table::makeExpression($1,LESS,$3);}
					| Expression GREAT_SYMBOL Expression 										{$$ = Table::makeExpression($1,GREAT,$3);}
					| Expression ADD_SYMBOL Expression 											{$$ = Table::makeExpression($1,ADD,$3);}
					| Expression SUB_SYMBOL Expression  										{$$ = Table::makeExpression($1,SUB,$3);}
					| Expression MULT_SYMBOL Expression 										{$$ = Table::makeExpression($1,MULT,$3);}
					| Expression DIV_SYMBOL Expression 											{$$ = Table::makeExpression($1,DIV,$3);}
					| Expression PERCENT_SYMBOL Expression 										{$$ = Table::makeExpression($1,MOD,$3);}
					| NOT_SYMBOL Expression 													{$$ = Table::makeExpression(new Expression("",UNKNOWN), NOT, $2);}
					| SUB_SYMBOL Expression %prec UNARY_MINUS_SYMBOL 							{$$ = Table::makeExpression(new Expression("",UNKNOWN), UNARY, $2);}
					| LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL 							{$$ = $2;}
					| ID_SYMBOL LEFT_BRACE_SYMBOL RIGHT_BRACE_SYMBOL							{ Table::makeProcedureCall($1,NULL,NULL); $$ = Table::functionReturn($1);}
					| ID_SYMBOL LEFT_BRACE_SYMBOL Expression ExpressionList RIGHT_BRACE_SYMBOL	{Table::makeProcedureCall($1,$3,$4); $$ = Table::functionReturn($1);}
					| CHR_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL				{ $$ = Table::intToChar($3);/*char cast*/}
					| ORD_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL				{ $$ = Table::charToInt($3);/*int cast*/ }
					| PRED_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL				{ $$ = Table::decrementExpression($3);}
					| SUCC_SYMBOL LEFT_BRACE_SYMBOL Expression RIGHT_BRACE_SYMBOL				{ $$ = Table::incrementExpression($3);}
					| INTEGER_SYMBOL															{$$ = Table::makeIntExpression($1);}				
					| CHARACTER_SYMBOL 															{$$ = Table::makeCharExpression($1); }				
					| STRING_SYMBOL 															{$$ = Table::makeStringExpression($1); }				
					| LValue 																	{$$ = $1;}
					;


LValue 				: ID_SYMBOL  		{$$ = new Expression($1,ID);}
					| RecordBegin LValueStuff {$$ = NULL;}
					| ArrayBegin LValueStuff 
					;

RecordBegin			: ID_SYMBOL DOT_SYMBOL ID_SYMBOL
						{
							$$ = Table::RecordToExpression($1,$3);
						}
					;


ArrayBegin			: ID_SYMBOL LEFT_SQUARE_SYMBOL Expression RIGHT_SQUARE_SYMBOL
						{
							$$ = Table::arrayToExpression($1,$3);
						}
					;

LValueStuff			: DOT_SYMBOL ID_SYMBOL LValueStuff
					| LEFT_SQUARE_SYMBOL Expression RIGHT_SQUARE_SYMBOL LValueStuff 
					|
					;

ConstExpression 	: ConstExpression OR_SYMBOL ConstExpression { $$ = Table::makeConst($1,OR,$3);}
					| ConstExpression AND_SYMBOL ConstExpression { $$ = Table::makeConst($1,AND,$3);}
					| ConstExpression EQUAL_SYMBOL ConstExpression { $$ = Table::makeConst($1,EQUAL,$3);}
					| ConstExpression NOT_EQUAL_SYMBOL ConstExpression { $$ = Table::makeConst($1,NOT_EQUAL,$3);}
					| ConstExpression LESS_EQUAL_SYMBOL ConstExpression { $$ = Table::makeConst($1,LESS_EQUAL,$3);}
					| ConstExpression GREAT_EQUAL_SYMBOL ConstExpression { $$ = Table::makeConst($1,GREAT_EQUAL,$3);}
					| ConstExpression LESS_SYMBOL ConstExpression { $$ = Table::makeConst($1,LESS,$3);}
					| ConstExpression GREAT_SYMBOL ConstExpression { $$ = Table::makeConst($1,GREAT,$3);}
					| ConstExpression ADD_SYMBOL ConstExpression { $$ = Table::makeConst($1,ADD,$3);}
					| ConstExpression SUB_SYMBOL ConstExpression { $$ = Table::makeConst($1,SUB,$3);}
					| ConstExpression MULT_SYMBOL ConstExpression { $$ = Table::makeConst($1,MULT,$3);}
					| ConstExpression DIV_SYMBOL ConstExpression { $$ = Table::makeConst($1,DIV,$3);}
					| ConstExpression PERCENT_SYMBOL ConstExpression { $$ = Table::makeConst($1,MOD,$3);}
					| NOT_SYMBOL ConstExpression { $$ = Table::makeConst(new Const("",UNKNOWN),NOT,$2);}
					| SUB_SYMBOL ConstExpression %prec UNARY_MINUS_SYMBOL { $$ = Table::makeConst(new Const("",UNKNOWN),UNARY,$2);}
					| LEFT_BRACE_SYMBOL ConstExpression RIGHT_BRACE_SYMBOL { $$ = $2;}
					| INTEGER_SYMBOL 	{ $$ = new Const(std::to_string($1),INT);}				
					| CHARACTER_SYMBOL 	{ $$ = new Const($1,CHAR);}				
					| STRING_SYMBOL 	{ $$ = new Const($1,STRING);}				
					| ID_SYMBOL 		{ $$ = new Const($1,ID);}
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
		Table::PrintTable();
	return 0;
};

void yyerror(const char * message) 
{
	Logger::LogError(message, numLines);
	exit(-1);
}