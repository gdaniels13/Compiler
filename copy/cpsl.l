%{
#include <string>
#include <utility>
#include <iostream>
#include "cpsl.tab.h"
#include "logger.h"	
#include "stdlib.h"
int numLines = 1;
myStruct yylval;
int hexToInt(char * text)
{
	text+=2;
	int newValue = (int)strtol(text, &text, 16);
	//Logger::LogMessage("New value = ", newValue);
	return newValue;
}

int octToInt(char * text)
{
	text++;
	int newValue = (int)strtol(text, &text, 8);
	//Logger::LogMessage("New value = ", newValue);
	return newValue;
}
%}

%%	
[ \t]				;
[$].*				;
array|ARRAY 		{Logger::LogMessage("Found", yytext,numLines); return(ARRAY_SYMBOL);}
begin|BEGIN 		{Logger::LogMessage("Found", yytext,numLines); return(BEGIN_SYMBOL);}
else|ELSE 			{Logger::LogMessage("Found", yytext,numLines); return(ELSE_SYMBOL);}
elseif|ELSEIF 		{Logger::LogMessage("Found", yytext,numLines); return(ELSEIF_SYMBOL);}
if|IF 				{Logger::LogMessage("Found", yytext,numLines); return(IF_SYMBOL);}
of|OF 				{Logger::LogMessage("Found", yytext,numLines); return(OF_SYMBOL);}
record|RECORD 		{Logger::LogMessage("Found", yytext,numLines); return(RECORD_SYMBOL);}
repeat|REPEAT 		{Logger::LogMessage("Found", yytext,numLines); return(REPEAT_SYMBOL);}
to|TO 				{Logger::LogMessage("Found", yytext,numLines); return(TO_SYMBOL);}
type|TYPE 			{Logger::LogMessage("Found", yytext,numLines); return(TYPE_SYMBOL);}
chr|CHR 			{Logger::LogMessage("Found", yytext,numLines); return(CHR_SYMBOL);}
const|CONST 		{Logger::LogMessage("Found", yytext,numLines); return(CONST_SYMBOL);}
do|DO 				{Logger::LogMessage("Found", yytext,numLines); return(DO_SYMBOL);}
end|END 			{Logger::LogMessage("Found", yytext,numLines); return(END_SYMBOL);}
for|FOR 			{Logger::LogMessage("Found", yytext,numLines); return(FOR_SYMBOL);}
forward|FORWARD 	{Logger::LogMessage("Found", yytext,numLines); return(FORWARD_SYMBOL);}
ord|ORD 			{Logger::LogMessage("Found", yytext,numLines); return(ORD_SYMBOL);}
pred|PRED 			{Logger::LogMessage("Found", yytext,numLines); return(PRED_SYMBOL);}
procedure|PROCEDURE {Logger::LogMessage("Found", yytext,numLines); return(PROCEDURE_SYMBOL);}
return|RETURN 		{Logger::LogMessage("Found", yytext,numLines); return(RETURN_SYMBOL);}
stop|STOP 			{Logger::LogMessage("Found", yytext,numLines); return(STOP_SYMBOL);}
succ|SUCC 			{Logger::LogMessage("Found", yytext,numLines); return(SUCC_SYMBOL);}
until|UNTIL 		{Logger::LogMessage("Found", yytext,numLines); return(UNTIL_SYMBOL);}
var|VAR 			{Logger::LogMessage("Found", yytext,numLines); return(VAR_SYMBOL);}
while|WHILE 		{Logger::LogMessage("Found", yytext,numLines); return(WHILE_SYMBOL);}
downto|DOWNTO 		{Logger::LogMessage("Found", yytext,numLines); return(DOWNTO_SYMBOL);}
function|FUNCTION 	{Logger::LogMessage("Found", yytext,numLines); return(FUNCTION_SYMBOL);}
read|READ 			{Logger::LogMessage("Found", yytext,numLines); return(READ_SYMBOL);}
then|THEN 			{Logger::LogMessage("Found", yytext,numLines); return(THEN_SYMBOL);}
write|WRITE 		{Logger::LogMessage("Found", yytext,numLines); return(WRITE_SYMBOL);}
[a-zA-Z][_a-zA-Z0-9]*	{Logger::LogMessage("Found ID, Value  = ", yytext,numLines); return(ID_SYMBOL);}
\"[\x20-\x7e]*\" 	{Logger::LogMessage("Found STRING, Value = ", yytext,numLines); yylval.name_ptr = strdup(yytext); return(STRING_SYMBOL);}
'[\x20-\x7e]+'		{Logger::LogMessage("Found CHAR, Value = ", yytext,numLines); yylval.str = strdup(yytext); return(CHARACTER_SYMBOL);}
0x[0-9a-fA-F]+		{Logger::LogMessage("Found HEX, Value = ", yytext,numLines); yylval.int_val = hexToInt(yytext); return(INTEGER_SYMBOL);}
0[1-7][0-7]*		{Logger::LogMessage("Found OCT, Value = ", yytext,numLines); yylval.int_val = octToInt(yytext); return(INTEGER_SYMBOL);}
[1-9][0-9]*			{Logger::LogMessage("Found INT, Value = ", yytext,numLines); yylval.int_val = atoi(yytext); return(INTEGER_SYMBOL);}
0 					{Logger::LogMessage("Found 0, Value = ", yytext,numLines); yylval.int_val = atoi(yytext); return(INTEGER_SYMBOL);}
":="				{Logger::LogMessage("Found", yytext,numLines); return(ASSIGN_SYMBOL);}
"+"					{Logger::LogMessage("Found", yytext,numLines); return(ADD_SYMBOL);}
"-"					{Logger::LogMessage("Found", yytext,numLines); return(SUB_SYMBOL);}
"*"					{Logger::LogMessage("Found", yytext,numLines); return(MULT_SYMBOL);}
"/"					{Logger::LogMessage("Found", yytext,numLines); return(DIV_SYMBOL);}
"&"					{Logger::LogMessage("Found", yytext,numLines); return(AND_SYMBOL);}
"|"					{Logger::LogMessage("Found", yytext,numLines); return(OR_SYMBOL);}
"~"					{Logger::LogMessage("Found", yytext,numLines); return(NOT_SYMBOL);}
"="					{Logger::LogMessage("Found", yytext,numLines); return(EQUAL_SYMBOL);}
"<>"				{Logger::LogMessage("Found", yytext,numLines); return(NOT_EQUAL_SYMBOL);}
"<"					{Logger::LogMessage("Found", yytext,numLines); return(LESS_SYMBOL);}
"<="				{Logger::LogMessage("Found", yytext,numLines); return(LESS_EQUAL_SYMBOL);}
">"					{Logger::LogMessage("Found", yytext,numLines); return(GREAT_SYMBOL);}
">="				{Logger::LogMessage("Found", yytext,numLines); return(GREAT_EQUAL_SYMBOL);}
"."					{Logger::LogMessage("Found", yytext,numLines); return(DOT_SYMBOL);}
","					{Logger::LogMessage("Found", yytext,numLines); return(COMMA_SYMBOL);}
":"					{Logger::LogMessage("Found", yytext,numLines); return(COLON_SYMBOL);}
";"					{Logger::LogMessage("Found", yytext,numLines); return(SEMI_COLON_SYMBOL);}
"("					{Logger::LogMessage("Found", yytext,numLines); return(LEFT_BRACE_SYMBOL);}
")"					{Logger::LogMessage("Found", yytext,numLines); return(RIGHT_BRACE_SYMBOL);}
"["					{Logger::LogMessage("Found", yytext,numLines); return(LEFT_SQUARE_SYMBOL);}
"]"					{Logger::LogMessage("Found", yytext,numLines); return(RIGHT_SQUARE_SYMBOL);}
"%"					{Logger::LogMessage("Found", yytext,numLines); return(PERCENT_SYMBOL);}	
<<EOF>>				{Logger::LogMessage(numLines,"Found EOF"); return(EOF_SYMBOL);}
[\n\r] 				{++numLines;}
.					{Logger::LogMessage("Lexical Error:", yytext, numLines);}
%%

int main(int argc, char ** argv)
{
	argc--, argv++;
	if(argc > 0)
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
	int in = yylex();
	while(in != EOF_SYMBOL)
	{
		in = yylex();
	}
	return 0;
};
