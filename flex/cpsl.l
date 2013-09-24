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
	return newValue;
}

int octToInt(char * text)
{
	text++;
	int newValue = (int)strtol(text, &text, 8);
	return newValue;
}
%}

%%	
[ \t]				;
[$].*				;
array|ARRAY 		{Logger::logMessage( yytext,numLines); return(ARRAY_SYMBOL);}
begin|BEGIN 		{Logger::logMessage( yytext,numLines); return(BEGIN_SYMBOL);}
else|ELSE 			{Logger::logMessage( yytext,numLines); return(ELSE_SYMBOL);}
elseif|ELSEIF 		{Logger::logMessage( yytext,numLines); return(ELSEIF_SYMBOL);}
if|IF 				{Logger::logMessage( yytext,numLines); return(IF_SYMBOL);}
of|OF 				{Logger::logMessage( yytext,numLines); return(OF_SYMBOL);}
record|RECORD 		{Logger::logMessage( yytext,numLines); return(RECORD_SYMBOL);}
repeat|REPEAT 		{Logger::logMessage( yytext,numLines); return(REPEAT_SYMBOL);}
to|TO 				{Logger::logMessage( yytext,numLines); return(TO_SYMBOL);}
type|TYPE 			{Logger::logMessage( yytext,numLines); return(TYPE_SYMBOL);}
chr|CHR 			{Logger::logMessage( yytext,numLines); return(CHR_SYMBOL);}
const|CONST 		{Logger::logMessage( yytext,numLines); return(CONST_SYMBOL);}
do|DO 				{Logger::logMessage( yytext,numLines); return(DO_SYMBOL);}
end|END 			{Logger::logMessage( yytext,numLines); return(END_SYMBOL);}
for|FOR 			{Logger::logMessage( yytext,numLines); return(FOR_SYMBOL);}
forward|FORWARD 	{Logger::logMessage( yytext,numLines); return(FORWARD_SYMBOL);}
ord|ORD 			{Logger::logMessage( yytext,numLines); return(ORD_SYMBOL);}
pred|PRED 			{Logger::logMessage( yytext,numLines); return(PRED_SYMBOL);}
procedure|PROCEDURE {Logger::logMessage( yytext,numLines); return(PROCEDURE_SYMBOL);}
return|RETURN 		{Logger::logMessage( yytext,numLines); return(RETURN_SYMBOL);}
stop|STOP 			{Logger::logMessage( yytext,numLines); return(STOP_SYMBOL);}
succ|SUCC 			{Logger::logMessage( yytext,numLines); return(SUCC_SYMBOL);}
until|UNTIL 		{Logger::logMessage( yytext,numLines); return(UNTIL_SYMBOL);}
var|VAR 			{Logger::logMessage( yytext,numLines); return(VAR_SYMBOL);}
while|WHILE 		{Logger::logMessage( yytext,numLines); return(WHILE_SYMBOL);}
downto|DOWNTO 		{Logger::logMessage( yytext,numLines); return(DOWNTO_SYMBOL);}
function|FUNCTION 	{Logger::logMessage( yytext,numLines); return(FUNCTION_SYMBOL);}
read|READ 			{Logger::logMessage( yytext,numLines); return(READ_SYMBOL);}
then|THEN 			{Logger::logMessage( yytext,numLines); return(THEN_SYMBOL);}
write|WRITE 		{Logger::logMessage( yytext,numLines); return(WRITE_SYMBOL);}
[a-zA-Z][_a-zA-Z0-9]*	{Logger::logMessage( yytext, numLines); return(ID_SYMBOL);}
\"[\x20-\x7e]*\" 	{Logger::logMessage(yytext,numLines); yylval.name_ptr = strdup(yytext); return(STRING_SYMBOL);}
'[\x20-\x7e]+'		{Logger::logMessage(yytext,numLines); yylval.name_ptr = strdup(yytext); return(CHARACTER_SYMBOL);}
0x[0-9a-fA-F]+		{Logger::logMessage(yytext,numLines); yylval.int_val = hexToInt(yytext); return(INTEGER_SYMBOL);}
0[1-7][0-7]*		{Logger::logMessage(yytext,numLines); yylval.int_val = octToInt(yytext); return(INTEGER_SYMBOL);}
[1-9][0-9]*			{Logger::logMessage(yytext,numLines); yylval.int_val = atoi(yytext); return(INTEGER_SYMBOL);}
0 					{Logger::logMessage(yytext,numLines); yylval.int_val = atoi(yytext); return(INTEGER_SYMBOL);}
":="				{Logger::logMessage( yytext,numLines); return(ASSIGN_SYMBOL);}
"+"					{Logger::logMessage( yytext,numLines); return(ADD_SYMBOL);}
"-"					{Logger::logMessage( yytext,numLines); return(SUB_SYMBOL);}
"*"					{Logger::logMessage( yytext,numLines); return(MULT_SYMBOL);}
"/"					{Logger::logMessage( yytext,numLines); return(DIV_SYMBOL);}
"&"					{Logger::logMessage( yytext,numLines); return(AND_SYMBOL);}
"|"					{Logger::logMessage( yytext,numLines); return(OR_SYMBOL);}
"~"					{Logger::logMessage( yytext,numLines); return(NOT_SYMBOL);}
"="					{Logger::logMessage( yytext,numLines); return(EQUAL_SYMBOL);}
"<>"				{Logger::logMessage( yytext,numLines); return(NOT_EQUAL_SYMBOL);}
"<"					{Logger::logMessage( yytext,numLines); return(LESS_SYMBOL);}
"<="				{Logger::logMessage( yytext,numLines); return(LESS_EQUAL_SYMBOL);}
">"					{Logger::logMessage( yytext,numLines); return(GREAT_SYMBOL);}
">="				{Logger::logMessage( yytext,numLines); return(GREAT_EQUAL_SYMBOL);}
"."					{Logger::logMessage( yytext,numLines); return(DOT_SYMBOL);}
","					{Logger::logMessage( yytext,numLines); return(COMMA_SYMBOL);}
":"					{Logger::logMessage( yytext,numLines); return(COLON_SYMBOL);}
";"					{Logger::logMessage( yytext,numLines); return(SEMI_COLON_SYMBOL);}
"("					{Logger::logMessage( yytext,numLines); return(LEFT_BRACE_SYMBOL);}
")"					{Logger::logMessage( yytext,numLines); return(RIGHT_BRACE_SYMBOL);}
"["					{Logger::logMessage( yytext,numLines); return(LEFT_SQUARE_SYMBOL);}
"]"					{Logger::logMessage( yytext,numLines); return(RIGHT_SQUARE_SYMBOL);}
"%"					{Logger::logMessage( yytext,numLines); return(PERCENT_SYMBOL);}	
[\n\r] 				{++numLines;}
.					{Logger::logError(yytext,numLines);}
%%

