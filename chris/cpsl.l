%{
int num_lines = 0, num_chars = 0;
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "cpsl.tab.h"
extern int yylex();
extern FILE *yyin;
%}

identifier [a-zA-Z][a-zA-Z0-9_]*

hexint 0x[1-9A-Fa-f][0-9A-Fa-f]*

octint 0[0-7]*

integer [1-9][0-9]*

character '.'|'\\n'|'\\r'|'\\b'|'\\t'|'\\f'

string \"..*\"

comment \$.*

whitespace [ \n\t][ \n\t]*


%%

array|ARRAY {return ARRAYSY;}

else|ELSE {return ELSESY;}

if|IF {return IFSY;}

record|RECORD {return RECORDSY;}

to|TO {return TOSY;}

begin|BEGIN {return BEGINSY;}

elseif|ELSEIF {return ELSEIFSY;}

of|OF {return OFSY;}

repeat|REPEAT {return REPEATSY;}

type|TYPE {return TYPESY;}

chr|CHR {return CHRSY;}

end|END {return ENDSY;}

ord|ORD {return ORDSY;}

return|RETURN {return RETURNSY;}

until|UNTIL {return UNTILSY;}

const|CONST {return CONSTSY;}

for|FOR {return FORSY;}

pred|PRED {return PREDSY;}

stop|STOP {return STOPSY;}

var|VAR {return VARSY;}

do|DO {return DOSY;}

forward|FORWARD {return FORWARDSY;}

procedure|PROCEDURE {return PROCEDURESY;}

succ|SUCC {return SUCCSY;}

while|WHILE {return WHILESY;}

downto|DOWNTO {return DOWNTOSY;}

function|FUNCTION {return FUNCTIONSY;}

read|READ {return READSY;}

then|THEN {return THENSY;}

write|WRITE {return WRITESY;}

{identifier} {yylval.sval = strdup(yytext); return IDENTSY;}

\+ {return PLUSSY;}

\<\> {return NOTEQUALSY;}

\; {return SEMICOLONSY;}

\- {return MINUSSY;}

\< {return LESSTHANSY;}

\( {return LEFTPARENSY;}

\∗ {return MULTIPLYSY;}

\<\= {return LESSEQUALSY;}

\) {return RIGHTPARENSY;}

\/ {return DIVIDESY;}

\> {return GREATERTHANSY;}

\[ {return LEFTBRACKETSY;}

\& {return ANDSY;}

\>\= {return GREATEREQUALSY;}

\] {return RIGHTBRACKETSY;}

\| {return ORSY;}

\. {return PERIODSY;}

\:\= {return ASSIGNSY;}

\~ {return NOTSY;}

\, {return COMMASY;}

\% {return MODSY;}

\= {return EQUALSY;}

\: {return COLONSY;}

{hexint} {yylval.ival = (int)strtol(yytext, NULL, 16); return INTSY;}

{octint} {yylval.ival = (int)strtol(yytext, NULL, 8); return INTSY;}

{integer} {yylval.ival = atoi(yytext); return INTSY;}

{character} {
	if(yytext[1] == '\\')
	{
		if(yytext[2] == 'n')
			yylval.cval == '\n';
		else if(yytext[2] == 'r')
			yylval.cval == '\r';
		else if(yytext[2] == 'b')
			yylval.cval == '\b';
		else if(yytext[2] == 't')
			yylval.cval == '\t';
		else if(yytext[2] == 'f')
			yylval.cval == '\f';
	}
	else
		yylval.cval = yytext[1];
	return CHARSY;
}

{string} {yylval.sval = strdup(yytext); return STRINGSY;}

{comment}

{whitespace}

.  {std::cout << "Unrecognised Token "; ECHO; std::cout << '\n'; return -1;}
