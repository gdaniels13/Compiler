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
     STRING_SYMBOL = 261,
     ARRAY_SYMBOL = 262,
     BEGIN_SYMBOL = 263,
     ELSE_SYMBOL = 264,
     ELSEIF_SYMBOL = 265,
     IF_SYMBOL = 266,
     OF_SYMBOL = 267,
     RECORD_SYMBOL = 268,
     REPEAT_SYMBOL = 269,
     TO_SYMBOL = 270,
     TYPE_SYMBOL = 271,
     CHR_SYMBOL = 272,
     CONST_SYMBOL = 273,
     DO_SYMBOL = 274,
     END_SYMBOL = 275,
     FOR_SYMBOL = 276,
     FORWARD_SYMBOL = 277,
     ORD_SYMBOL = 278,
     PRED_SYMBOL = 279,
     PROCEDURE_SYMBOL = 280,
     RETURN_SYMBOL = 281,
     STOP_SYMBOL = 282,
     SUCC_SYMBOL = 283,
     UNTIL_SYMBOL = 284,
     VAR_SYMBOL = 285,
     WHILE_SYMBOL = 286,
     DOWNTO_SYMBOL = 287,
     FUNCTION_SYMBOL = 288,
     READ_SYMBOL = 289,
     THEN_SYMBOL = 290,
     WRITE_SYMBOL = 291,
     ASSIGN_SYMBOL = 292,
     ADD_SYMBOL = 293,
     SUB_SYMBOL = 294,
     MULT_SYMBOL = 295,
     DIV_SYMBOL = 296,
     AND_SYMBOL = 297,
     OR_SYMBOL = 298,
     NOT_SYMBOL = 299,
     EQUAL_SYMBOL = 300,
     NOT_EQUAL_SYMBOL = 301,
     LESS_SYMBOL = 302,
     LESS_EQUAL_SYMBOL = 303,
     GREAT_SYMBOL = 304,
     GREAT_EQUAL_SYMBOL = 305,
     DOT_SYMBOL = 306,
     COMMA_SYMBOL = 307,
     COLON_SYMBOL = 308,
     SEMI_COLON_SYMBOL = 309,
     LEFT_BRACE_SYMBOL = 310,
     RIGHT_BRACE_SYMBOL = 311,
     LEFT_SQUARE_SYMBOL = 312,
     RIGHT_SQUARE_SYMBOL = 313,
     PERCENT_SYMBOL = 314,
     UMINUS = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 83 "cpsl.y"
	
	int int_val;
	char *name_ptr;



/* Line 2068 of yacc.c  */
#line 117 "cpsl.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


