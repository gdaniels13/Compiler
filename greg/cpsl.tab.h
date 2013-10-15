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
     INTEGER_SYMBOL = 258,
     STRING_SYMBOL = 259,
     ID_SYMBOL = 260,
     CHARACTER_SYMBOL = 261,
     ADD_SYMBOL = 262,
     AND_SYMBOL = 263,
     ARRAY_SYMBOL = 264,
     ASSIGN_SYMBOL = 265,
     BEGIN_SYMBOL = 266,
     CHR_SYMBOL = 267,
     COLON_SYMBOL = 268,
     COMMA_SYMBOL = 269,
     CONST_SYMBOL = 270,
     DIV_SYMBOL = 271,
     DO_SYMBOL = 272,
     DOT_SYMBOL = 273,
     DOWNTO_SYMBOL = 274,
     ELSE_SYMBOL = 275,
     ELSEIF_SYMBOL = 276,
     END_SYMBOL = 277,
     EQUAL_SYMBOL = 278,
     FOR_SYMBOL = 279,
     FORWARD_SYMBOL = 280,
     FUNCTION_SYMBOL = 281,
     GREAT_EQUAL_SYMBOL = 282,
     GREAT_SYMBOL = 283,
     IF_SYMBOL = 284,
     LEFT_BRACE_SYMBOL = 285,
     LEFT_SQUARE_SYMBOL = 286,
     LESS_SYMBOL = 287,
     LESS_EQUAL_SYMBOL = 288,
     MULT_SYMBOL = 289,
     NOT_SYMBOL = 290,
     NOT_EQUAL_SYMBOL = 291,
     OF_SYMBOL = 292,
     OR_SYMBOL = 293,
     ORD_SYMBOL = 294,
     PERCENT_SYMBOL = 295,
     PRED_SYMBOL = 296,
     PROCEDURE_SYMBOL = 297,
     READ_SYMBOL = 298,
     RECORD_SYMBOL = 299,
     REPEAT_SYMBOL = 300,
     RETURN_SYMBOL = 301,
     RIGHT_BRACE_SYMBOL = 302,
     RIGHT_SQUARE_SYMBOL = 303,
     SEMI_COLON_SYMBOL = 304,
     STOP_SYMBOL = 305,
     SUB_SYMBOL = 306,
     SUCC_SYMBOL = 307,
     THEN_SYMBOL = 308,
     TO_SYMBOL = 309,
     TYPE_SYMBOL = 310,
     UNTIL_SYMBOL = 311,
     UNARY_MINUS_SYMBOL = 312,
     VAR_SYMBOL = 313,
     WHILE_SYMBOL = 314,
     WRITE_SYMBOL = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 24 "cpsl.y"
 
	int int_val;
	char * name_ptr; 
	void * none_type;
	Const * const_type;
	std::vector<std::shared_ptr<Var>> * formalParameter;
	std::vector<std::string> * identList;
	Type * type;
	std::vector<std::shared_ptr<Type>> * typeList;



/* Line 2068 of yacc.c  */
#line 123 "cpsl.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


