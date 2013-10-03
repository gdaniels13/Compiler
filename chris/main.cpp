#include <iostream>
#include <fstream>
extern FILE *yyin;
extern int yyparse();

int main(int argc, char** argv)
{
	if(argc > 1)
	{
		yyin = fopen(argv[1], "r");
	}
	while(!feof(yyin))
	{
		yyparse();
	}
}
