%{
#include <string>
#include <utility>
#include <iostream>
#include "cpsl.tab.h"
#include "logger.h"	
#include "stdlib.h"


int numLines = 1;

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
array|ARRAY 		{Logger::LogMessage("Found", yytext); return(ARRAY_SYMBOL);}
begin|BEGIN 		{Logger::LogMessage("Found", yytext); return(BEGIN_SYMBOL);}
else|ELSE 			{Logger::LogMessage("Found", yytext); return(ELSE_SYMBOL);}
elseif|ELSEIF 		{Logger::LogMessage("Found", yytext); return(ELSEIF_SYMBOL);}
if|IF 				{Logger::LogMessage("Found", yytext); return(IF_SYMBOL);}
of|OF 				{Logger::LogMessage("Found", yytext); return(OF_SYMBOL);}
record|RECORD 		{Logger::LogMessage("Found", yytext); return(RECORD_SYMBOL);}
repeat|REPEAT 		{Logger::LogMessage("Found", yytext); return(REPEAT_SYMBOL);}
to|TO 				{Logger::LogMessage("Found", yytext); return(TO_SYMBOL);}
type|TYPE 			{Logger::LogMessage("Found", yytext); return(TYPE_SYMBOL);}
chr|CHR 			{Logger::LogMessage("Found", yytext); return(CHR_SYMBOL);}
const|CONST 		{Logger::LogMessage("Found", yytext); return(CONST_SYMBOL);}
do|DO 				{Logger::LogMessage("Found", yytext); return(DO_SYMBOL);}
end|END 			{Logger::LogMessage("Found", yytext); return(END_SYMBOL);}
for|FOR 			{Logger::LogMessage("Found", yytext); return(FOR_SYMBOL);}
forward|FORWARD 	{Logger::LogMessage("Found", yytext); return(FORWARD_SYMBOL);}
ord|ORD 			{Logger::LogMessage("Found", yytext); return(ORD_SYMBOL);}
pred|PRED 			{Logger::LogMessage("Found", yytext); return(PRED_SYMBOL);}
procedure|PROCEDURE {Logger::LogMessage("Found", yytext); return(PROCEDURE_SYMBOL);}
return|RETURN 		{Logger::LogMessage("Found", yytext); return(RETURN_SYMBOL);}
stop|STOP 			{Logger::LogMessage("Found", yytext); return(STOP_SYMBOL);}
succ|SUCC 			{Logger::LogMessage("Found", yytext); return(SUCC_SYMBOL);}
until|UNTIL 		{Logger::LogMessage("Found", yytext); return(UNTIL_SYMBOL);}
var|VAR 			{Logger::LogMessage("Found", yytext); return(VAR_SYMBOL);}
while|WHILE 		{Logger::LogMessage("Found", yytext); return(WHILE_SYMBOL);}
downto|DOWNTO 		{Logger::LogMessage("Found", yytext); return(DOWNTO_SYMBOL);}
function|FUNCTION 	{Logger::LogMessage("Found", yytext); return(FUNCTION_SYMBOL);}
read|READ 			{Logger::LogMessage("Found", yytext); return(READ_SYMBOL);}
then|THEN 			{Logger::LogMessage("Found", yytext); return(THEN_SYMBOL);}
write|WRITE 		{Logger::LogMessage("Found", yytext); return(WRITE_SYMBOL);}
[a-zA-Z][_a-zA-Z0-9]*	{Logger::LogMessage("Found ID, Value  = ", yytext); return(ID_SYMBOL);}
\"[\x20-\x7e]*\" 	{Logger::LogMessage("Found STRING, Value = ", yytext); yylval.name_ptr = strdup(yytext); return(STRING_SYMBOL);}
'[\x20-\x7e]+'		{Logger::LogMessage("Found CHAR, Value = ", yytext); yylval.name_ptr = strdup(yytext); return(CHARACTER_SYMBOL);}
0x[0-9a-fA-F]+		{Logger::LogMessage("Found HEX, Value = ", yytext); yylval.int_val = hexToInt(yytext); return(INTEGER_SYMBOL);}
0[1-7][0-7]*		{Logger::LogMessage("Found OCT, Value = ", yytext); yylval.int_val = octToInt(yytext); return(INTEGER_SYMBOL);}
[1-9][0-9]*			{Logger::LogMessage("Found INT, Value = ", yytext); yylval.int_val = atoi(yytext); return(INTEGER_SYMBOL);}
0 					{Logger::LogMessage("Found 0, Value = ", yytext); yylval.int_val = atoi(yytext); return(INTEGER_SYMBOL);}
":="				{Logger::LogMessage("Found", yytext); return(ASSIGN_SYMBOL);}
"+"					{Logger::LogMessage("Found", yytext); return(ADD_SYMBOL);}
"-"					{Logger::LogMessage("Found", yytext); return(SUB_SYMBOL);}
"*"					{Logger::LogMessage("Found", yytext); return(MULT_SYMBOL);}
"/"					{Logger::LogMessage("Found", yytext); return(DIV_SYMBOL);}
"&"					{Logger::LogMessage("Found", yytext); return(AND_SYMBOL);}
"|"					{Logger::LogMessage("Found", yytext); return(OR_SYMBOL);}
"~"					{Logger::LogMessage("Found", yytext); return(NOT_SYMBOL);}
"="					{Logger::LogMessage("Found", yytext); return(EQUAL_SYMBOL);}
"<>"				{Logger::LogMessage("Found", yytext); return(NOT_EQUAL_SYMBOL);}
"<"					{Logger::LogMessage("Found", yytext); return(LESS_SYMBOL);}
"<="				{Logger::LogMessage("Found", yytext); return(LESS_EQUAL_SYMBOL);}
">"					{Logger::LogMessage("Found", yytext); return(GREAT_SYMBOL);}
">="				{Logger::LogMessage("Found", yytext); return(GREAT_EQUAL_SYMBOL);}
"."					{Logger::LogMessage("Found", yytext); return(DOT_SYMBOL);}
","					{Logger::LogMessage("Found", yytext); return(COMMA_SYMBOL);}
":"					{Logger::LogMessage("Found", yytext); return(COLON_SYMBOL);}
";"					{Logger::LogMessage("Found", yytext); return(SEMI_COLON_SYMBOL);}
"("					{Logger::LogMessage("Found", yytext); return(LEFT_BRACE_SYMBOL);}
")"					{Logger::LogMessage("Found", yytext); return(RIGHT_BRACE_SYMBOL);}
"["					{Logger::LogMessage("Found", yytext); return(LEFT_SQUARE_SYMBOL);}
"]"					{Logger::LogMessage("Found", yytext); return(RIGHT_SQUARE_SYMBOL);}
"%"					{Logger::LogMessage("Found", yytext); return(PERCENT_SYMBOL);}	
[\n\r] 				{++numLines;}
.					{Logger::LogMessage("Lexical Error:", yytext);}
%%

