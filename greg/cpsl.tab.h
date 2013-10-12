/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID_SYMBOL = 258,
     CHARACTER_SYMBOL = 259,
     INTEGER_SYMBOL = 260,
     ARRAY_SYMBOL = 261,
     BEGIN_SYMBOL = 262,
     ELSE_SYMBOL = 263,
     ELSEIF_SYMBOL = 264,
     IF_SYMBOL = 265,
     OF_SYMBOL = 266,
     RECORD_SYMBOL = 267,
     REPEAT_SYMBOL = 268,
     TO_SYMBOL = 269,
     TYPE_SYMBOL = 270,
     CHR_SYMBOL = 271,
     CONST_SYMBOL = 272,
     DO_SYMBOL = 273,
     END_SYMBOL = 274,
     FOR_SYMBOL = 275,
     FORWARD_SYMBOL = 276,
     ORD_SYMBOL = 277,
     PRED_SYMBOL = 278,
     PROCEDURE_SYMBOL = 279,
     RETURN_SYMBOL = 280,
     STOP_SYMBOL = 281,
     SUCC_SYMBOL = 282,
     UNTIL_SYMBOL = 283,
     VAR_SYMBOL = 284,
     WHILE_SYMBOL = 285,
     DOWNTO_SYMBOL = 286,
     FUNCTION_SYMBOL = 287,
     READ_SYMBOL = 288,
     THEN_SYMBOL = 289,
     WRITE_SYMBOL = 290,
     ASSIGN_SYMBOL = 291,
     ADD_SYMBOL = 292,
     SUB_SYMBOL = 293,
     MULT_SYMBOL = 294,
     DIV_SYMBOL = 295,
     AND_SYMBOL = 296,
     OR_SYMBOL = 297,
     NOT_SYMBOL = 298,
     EQUAL_SYMBOL = 299,
     NOT_EQUAL_SYMBOL = 300,
     LESS_SYMBOL = 301,
     LESS_EQUAL_SYMBOL = 302,
     GREAT_SYMBOL = 303,
     GREAT_EQUAL_SYMBOL = 304,
     DOT_SYMBOL = 305,
     COMMA_SYMBOL = 306,
     COLON_SYMBOL = 307,
     SEMI_COLON_SYMBOL = 308,
     LEFT_BRACE_SYMBOL = 309,
     RIGHT_BRACE_SYMBOL = 310,
     LEFT_SQUARE_SYMBOL = 311,
     RIGHT_SQUARE_SYMBOL = 312,
     PERCENT_SYMBOL = 313,
     STRING_SYMBOL = 314,
     UMINUS = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 94 "cpsl.y"
	
	int int_val;
	char *name_ptr;
	std::vector<std::string> * id_list;
	std::vector<std::shared_ptr<Variable>> * form_params;
	void* none_type;
	Symbol* symbol_type;
	std::vector<std::pair<std::vector<std::string>*,std::string>>* record_type;
	Constant * const_type;
	yytokentype * token_type;



/* Line 2068 of yacc.c  */
#line 124 "cpsl.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


