/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "cpsl.y"

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
 
void yyerror(const char *s);



/* Line 268 of yacc.c  */
#line 94 "cpsl.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
#line 24 "cpsl.y"
 
	int int_val;
	char * name_ptr; 
	void * none_type;
	Const * const_type;
	std::vector<std::shared_ptr<Var>> * formalParameter;
	std::vector<std::string> * identList;
	Type * type;
	std::vector<std::shared_ptr<Type>> * typeList;



/* Line 293 of yacc.c  */
#line 203 "cpsl.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 215 "cpsl.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1069

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNRULES -- Number of states.  */
#define YYNSTATES  351

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    16,    22,    27,    33,    38,    43,
      47,    54,    55,    61,    64,    67,    68,    77,    81,    88,
      99,   103,   112,   113,   119,   124,   131,   137,   138,   141,
     143,   147,   150,   153,   155,   158,   160,   162,   166,   169,
     175,   176,   182,   184,   186,   188,   190,   194,   200,   201,
     210,   213,   214,   218,   225,   226,   232,   235,   236,   240,
     242,   244,   246,   248,   250,   252,   254,   256,   258,   260,
     262,   266,   275,   282,   283,   289,   295,   300,   310,   320,
     322,   325,   327,   333,   337,   338,   344,   345,   349,   355,
     359,   360,   364,   365,   369,   373,   377,   381,   385,   389,
     393,   397,   401,   405,   409,   413,   417,   420,   423,   427,
     431,   437,   442,   447,   452,   457,   459,   461,   463,   465,
     469,   470,   472,   477,   483,   487,   492,   493,   497,   501,
     505,   509,   513,   517,   521,   525,   529,   533,   537,   541,
     545,   548,   551,   555,   557,   559,   561
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    63,    75,    85,    65,    74,    18,    -1,
      63,    75,    65,    74,    18,    -1,    63,    85,    65,    74,
      18,    -1,    63,    65,    74,    18,    -1,    75,    85,    65,
      74,    18,    -1,    75,    65,    74,    18,    -1,    85,    65,
      74,    18,    -1,    65,    74,    18,    -1,    15,     5,    23,
     109,    49,    64,    -1,    -1,     5,    23,   109,    49,    64,
      -1,    66,    65,    -1,    68,    65,    -1,    -1,    42,     5,
      30,    70,    47,    49,    25,    49,    -1,    67,    72,    49,
      -1,    42,     5,    30,    70,    47,    49,    -1,    26,     5,
      30,    70,    47,    13,    78,    49,    25,    49,    -1,    69,
      72,    49,    -1,    26,     5,    30,    70,    47,    13,    78,
      49,    -1,    -1,    58,    83,    13,    78,    71,    -1,    83,
      13,    78,    71,    -1,    49,    58,    83,    13,    78,    71,
      -1,    49,    83,    13,    78,    71,    -1,    -1,    73,    74,
      -1,    74,    -1,    63,    75,    85,    -1,    63,    75,    -1,
      63,    85,    -1,    63,    -1,    75,    85,    -1,    75,    -1,
      85,    -1,    11,    87,    22,    -1,    76,    77,    -1,    55,
       5,    23,    78,    49,    -1,    -1,     5,    23,    78,    49,
      77,    -1,    79,    -1,    80,    -1,    82,    -1,     5,    -1,
      44,    81,    22,    -1,    83,    13,    78,    49,    81,    -1,
      -1,     9,    31,   109,    13,   109,    48,    37,    78,    -1,
       5,    84,    -1,    -1,    14,     5,    84,    -1,    58,    83,
      13,    78,    49,    86,    -1,    -1,    83,    13,    78,    49,
      86,    -1,    89,    88,    -1,    -1,    49,    89,    88,    -1,
      90,    -1,    91,    -1,    93,    -1,    94,    -1,    95,    -1,
      96,    -1,    97,    -1,    98,    -1,   100,    -1,   102,    -1,
     104,    -1,   107,    10,   105,    -1,    29,   105,    53,    87,
      92,    20,    87,    22,    -1,    29,   105,    53,    87,    92,
      22,    -1,    -1,    21,   105,    53,    87,    92,    -1,    59,
     105,    17,    87,    22,    -1,    45,    87,    56,   105,    -1,
      24,     5,    10,   105,    54,   105,    17,    87,    22,    -1,
      24,     5,    10,   105,    19,   105,    17,    87,    22,    -1,
      50,    -1,    46,   105,    -1,    46,    -1,    43,    30,   107,
      99,    47,    -1,    14,   107,    99,    -1,    -1,    60,    30,
     105,   101,    47,    -1,    -1,    14,   105,   101,    -1,     5,
      30,   105,   103,    47,    -1,     5,    30,    47,    -1,    -1,
      14,   105,   103,    -1,    -1,   105,    38,   105,    -1,   105,
       8,   105,    -1,   105,    23,   105,    -1,   105,    36,   105,
      -1,   105,    33,   105,    -1,   105,    27,   105,    -1,   105,
      32,   105,    -1,   105,    28,   105,    -1,   105,     7,   105,
      -1,   105,    51,   105,    -1,   105,    34,   105,    -1,   105,
      16,   105,    -1,   105,    40,   105,    -1,    35,   105,    -1,
      51,   105,    -1,    30,   105,    47,    -1,     5,    30,    47,
      -1,     5,    30,   105,   106,    47,    -1,    12,    30,   105,
      47,    -1,    39,    30,   105,    47,    -1,    41,    30,   105,
      47,    -1,    52,    30,   105,    47,    -1,     3,    -1,     6,
      -1,     4,    -1,   107,    -1,    14,   105,   106,    -1,    -1,
       5,    -1,     5,    18,     5,   108,    -1,     5,    31,   105,
      48,   108,    -1,    18,     5,   108,    -1,    31,   105,    48,
     108,    -1,    -1,   109,    38,   109,    -1,   109,     8,   109,
      -1,   109,    23,   109,    -1,   109,    36,   109,    -1,   109,
      33,   109,    -1,   109,    27,   109,    -1,   109,    32,   109,
      -1,   109,    28,   109,    -1,   109,     7,   109,    -1,   109,
      51,   109,    -1,   109,    34,   109,    -1,   109,    16,   109,
      -1,   109,    40,   109,    -1,    35,   109,    -1,    51,   109,
      -1,    30,   109,    47,    -1,     3,    -1,     6,    -1,     4,
      -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   186,   187,   188,   189,   190,   191,   192,
     195,   198,   199,   202,   203,   204,   207,   208,   211,   214,
     215,   218,   221,   222,   223,   226,   227,   228,   231,   232,
     235,   236,   237,   238,   239,   240,   241,   244,   247,   250,
     253,   254,   257,   258,   259,   262,   265,   268,   269,   272,
     275,   278,   279,   282,   285,   286,   289,   292,   293,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     309,   312,   313,   316,   317,   320,   323,   326,   327,   330,
     333,   334,   337,   340,   341,   344,   347,   348,   351,   352,
     355,   356,   359,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   390,
     391,   394,   395,   396,   399,   400,   401,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_SYMBOL", "STRING_SYMBOL",
  "ID_SYMBOL", "CHARACTER_SYMBOL", "ADD_SYMBOL", "AND_SYMBOL",
  "ARRAY_SYMBOL", "ASSIGN_SYMBOL", "BEGIN_SYMBOL", "CHR_SYMBOL",
  "COLON_SYMBOL", "COMMA_SYMBOL", "CONST_SYMBOL", "DIV_SYMBOL",
  "DO_SYMBOL", "DOT_SYMBOL", "DOWNTO_SYMBOL", "ELSE_SYMBOL",
  "ELSEIF_SYMBOL", "END_SYMBOL", "EQUAL_SYMBOL", "FOR_SYMBOL",
  "FORWARD_SYMBOL", "FUNCTION_SYMBOL", "GREAT_EQUAL_SYMBOL",
  "GREAT_SYMBOL", "IF_SYMBOL", "LEFT_BRACE_SYMBOL", "LEFT_SQUARE_SYMBOL",
  "LESS_SYMBOL", "LESS_EQUAL_SYMBOL", "MULT_SYMBOL", "NOT_SYMBOL",
  "NOT_EQUAL_SYMBOL", "OF_SYMBOL", "OR_SYMBOL", "ORD_SYMBOL",
  "PERCENT_SYMBOL", "PRED_SYMBOL", "PROCEDURE_SYMBOL", "READ_SYMBOL",
  "RECORD_SYMBOL", "REPEAT_SYMBOL", "RETURN_SYMBOL", "RIGHT_BRACE_SYMBOL",
  "RIGHT_SQUARE_SYMBOL", "SEMI_COLON_SYMBOL", "STOP_SYMBOL", "SUB_SYMBOL",
  "SUCC_SYMBOL", "THEN_SYMBOL", "TO_SYMBOL", "TYPE_SYMBOL", "UNTIL_SYMBOL",
  "UNARY_MINUS_SYMBOL", "VAR_SYMBOL", "WHILE_SYMBOL", "WRITE_SYMBOL",
  "$accept", "Program", "ConstantDecl", "ConstantStuff", "ProcFunc",
  "ProcedureDecl", "ProcStuff", "FunctionDecl", "FuncStuff",
  "FormalParameters", "ParamStuff", "Body", "BodyStuff", "Block",
  "TypeDecl", "TypeBlah", "TypeStuff", "Type", "SimpleType", "RecordType",
  "RecordStuff", "ArrayType", "IdentList", "IdentStuff", "VarDecl",
  "VarStuff", "StatementSequence", "StatementStuff", "Statement",
  "Assignment", "IfStatement", "IfStuff", "WhileStatement",
  "RepeatStatement", "ForStatement", "StopStatement", "ReturnStatement",
  "ReadStatement", "ReadStuff", "WriteStatement", "WriteStuff",
  "ProcedureCall", "ProcedureStuff", "NullStatement", "Expression",
  "ExpressionStuff", "LValue", "LValueStuff", "ConstExpression", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      63,    64,    64,    65,    65,    65,    66,    66,    67,    68,
      68,    69,    70,    70,    70,    71,    71,    71,    72,    72,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    76,
      77,    77,    78,    78,    78,    79,    80,    81,    81,    82,
      83,    84,    84,    85,    86,    86,    87,    88,    88,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    91,    91,    92,    92,    93,    94,    95,    95,    96,
      97,    97,    98,    99,    99,   100,   101,   101,   102,   102,
     103,   103,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   106,
     106,   107,   107,   107,   108,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     5,     4,     5,     4,     4,     3,
       6,     0,     5,     2,     2,     0,     8,     3,     6,    10,
       3,     8,     0,     5,     4,     6,     5,     0,     2,     1,
       3,     2,     2,     1,     2,     1,     1,     3,     2,     5,
       0,     5,     1,     1,     1,     1,     3,     5,     0,     8,
       2,     0,     3,     6,     0,     5,     2,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     8,     6,     0,     5,     5,     4,     9,     9,     1,
       2,     1,     5,     3,     0,     5,     0,     3,     5,     3,
       0,     3,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     3,
       5,     4,     4,     4,     4,     1,     1,     1,     1,     3,
       0,     1,     4,     5,     3,     4,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     0,     0,     0,     0,     0,    15,     0,    15,
       0,    15,     0,    15,    40,    15,     0,     0,     0,     0,
      51,     0,     1,     0,    15,    15,    92,     0,    13,    33,
       0,     0,    29,    35,    36,    14,     0,     0,    15,     0,
      38,     0,     0,    22,    22,     0,     0,    50,     0,     0,
       0,    15,     0,   121,     0,     0,     0,    92,    81,    79,
       0,     0,     0,    57,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     9,    31,    32,    17,
      28,    34,    20,     0,     0,     0,     0,   143,   145,   146,
     144,     0,     0,     0,     0,     0,     0,     0,     0,    45,
       0,    48,     0,    42,    43,    44,    51,     0,     5,     0,
       0,     0,     0,     0,     0,     0,   115,   117,   121,   116,
       0,     0,     0,     0,     0,     0,     0,     0,   118,     0,
       0,    80,     0,     0,    37,    92,    56,     0,    30,     7,
       0,     0,     8,     0,   140,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    52,    54,
       3,     0,     4,   126,    89,    90,     0,     0,     0,     0,
       0,   106,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
     121,    84,     0,    92,    86,    57,    70,     6,    40,   142,
     135,   128,   138,   129,   132,   134,   133,   131,   137,   130,
     127,   139,     0,    10,   136,     0,     0,    27,    18,     0,
      46,     0,     0,    53,     2,     0,     0,   122,     0,     0,
     126,     0,   109,   120,     0,   108,     0,     0,     0,   101,
      94,   104,    95,    98,   100,    99,    97,   103,    96,    93,
     105,   102,    73,     0,     0,    76,     0,     0,     0,    58,
      41,     0,    27,     0,     0,    24,     0,     0,     0,     0,
     126,     0,    90,    88,   123,     0,     0,     0,     0,   111,
     112,   113,   114,     0,     0,    84,    82,    75,    86,    85,
       0,    23,    21,     0,     0,    16,     0,    48,     0,   124,
     126,    91,     0,     0,   120,   110,     0,    92,    72,    83,
      87,    11,     0,     0,     0,     0,    47,    54,   125,    92,
      92,   119,    92,     0,    12,    19,     0,    27,     0,    55,
       0,     0,    73,    71,    27,    26,    49,    78,    77,    74,
      25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    29,   223,     8,     9,    10,    11,    12,    96,
     275,    30,    31,    32,    33,    14,    40,   102,   103,   104,
     165,   105,    97,    47,    34,   233,    62,   136,    63,    64,
      65,   294,    66,    67,    68,    69,    70,    71,   264,    72,
     268,    73,   239,    74,   127,   288,   128,   237,    94
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -250
static const yytype_int16 yypact[] =
{
       1,     7,    12,    36,    47,    71,    11,    72,    80,   -11,
      -1,   -11,    -1,    73,    95,   -11,    69,    81,    82,    90,
     104,    96,  -250,    80,    73,   -11,    79,   101,  -250,     0,
      74,    80,  -250,    63,  -250,  -250,    83,    80,   -11,   105,
    -250,    80,   179,    21,    21,    16,   128,  -250,    16,   116,
      80,   -11,    80,    15,   130,   306,   106,    79,   306,  -250,
     306,   107,   118,   114,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,   135,  -250,    63,  -250,  -250,
    -250,  -250,  -250,   147,    80,    16,   153,  -250,  -250,  -250,
    -250,   179,   179,   179,   366,    71,   125,   160,   132,  -250,
     144,    71,   139,  -250,  -250,  -250,   104,   140,  -250,   159,
      80,   172,   186,   164,   306,   182,  -250,  -250,    75,  -250,
     165,   306,   306,   166,   167,   306,   168,   220,  -250,   196,
     148,   882,   402,   306,  -250,    79,  -250,   306,  -250,  -250,
     188,   158,  -250,   416,   932,  -250,   179,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   203,   179,
     197,   199,    16,   169,   179,   191,   204,  -250,  -250,    71,
    -250,   201,  -250,    19,  -250,   450,   464,   306,   278,   306,
     498,   954,   306,   306,  -250,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,    79,
      30,   206,   306,    79,   532,   114,   882,  -250,    95,  -250,
       2,   932,  -250,   968,   968,   968,   968,   968,  -250,   968,
     896,  -250,   198,  -250,     2,    16,    16,   173,   200,   566,
    -250,    16,   210,  -250,  -250,   219,   306,  -250,   306,   185,
      19,   316,  -250,   600,   614,  -250,   648,   682,   716,    86,
     954,  -250,   990,   990,   990,   990,   990,  -250,   990,   918,
    -250,    86,   205,   196,   190,   882,   207,   306,   192,  -250,
    -250,   179,   173,   184,    24,  -250,   193,   179,   195,    16,
      19,   750,   450,  -250,  -250,   306,   306,   306,   194,  -250,
    -250,  -250,  -250,   306,    31,   206,  -250,  -250,   532,  -250,
     784,  -250,   215,    71,   222,  -250,   798,    71,   212,  -250,
      19,  -250,   834,   848,   600,  -250,   352,    79,  -250,  -250,
    -250,   203,   214,   232,    16,   209,  -250,    71,  -250,    79,
      79,  -250,    79,   233,  -250,  -250,    16,   173,    16,  -250,
     237,   242,   205,  -250,   173,  -250,  -250,  -250,  -250,  -250,
    -250
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -250,  -250,   265,   -54,  1018,  -250,  -250,  -250,  -250,   224,
    -249,   254,  -250,    -3,    87,  -250,    62,   -45,  -250,  -250,
     -35,  -250,    -5,   170,     6,   -49,   -55,    84,   145,  -250,
    -250,   -57,  -250,  -250,  -250,  -250,  -250,  -250,    -9,  -250,
     -10,  -250,     5,  -250,   -36,   -20,   -25,  -236,   -84
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      21,    75,   130,   107,   284,    27,    15,   143,   144,   145,
      26,    22,    16,    25,     1,     2,     1,    17,   148,    38,
      49,    99,   131,   301,   132,   100,    20,     2,    80,    20,
      51,     3,    75,   112,    83,    78,   154,   235,    86,    81,
     141,    18,   157,     3,   309,   113,   114,   109,   112,   111,
     236,   317,    19,   318,     4,     4,     4,     5,     5,     5,
     101,   114,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   328,   224,    20,   175,   176,    95,
     229,   140,   303,   138,    53,   180,   181,    13,   345,   184,
     160,    26,    42,   112,    24,   350,   166,   204,     2,     2,
      39,   206,   188,    54,   201,   178,   114,   171,    55,    48,
      75,    43,    44,    45,     3,     3,    77,   227,    46,    76,
     194,     5,    56,    79,    57,    58,   197,     4,    85,    59,
       5,     5,    82,   106,   108,   115,   129,   133,    60,    61,
     134,   241,   243,   244,   262,   137,   246,   247,   266,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   135,   232,   139,   265,   116,   117,   118,
     119,   142,   161,   162,    75,   164,   120,   170,    75,   163,
     272,   273,    87,    88,    89,    90,   278,   300,   167,   169,
     172,   173,   177,   306,   121,   179,   182,   183,   185,   122,
     281,   200,   282,   123,   202,   124,   207,   208,   222,    91,
     225,   174,   226,   230,    92,   125,   126,   231,   228,   234,
     263,   271,   274,   279,   280,   276,   293,   186,   187,   297,
      93,   298,   283,   302,   308,   324,   188,   296,   295,   299,
     322,   315,   305,   189,   307,   336,   338,   190,   191,   312,
     313,   314,   192,   193,   194,   343,   195,   316,   196,   347,
     197,   327,   333,   335,   348,     7,    36,   334,    98,   304,
     270,   198,   326,   199,   340,   341,   168,   342,   339,   337,
     205,   116,   117,   118,   119,   349,   319,   311,   320,   269,
     120,   344,    75,   346,   331,     0,     0,     0,   323,     0,
       0,     0,   166,     0,    75,    75,     0,    75,   121,   116,
     117,   118,   119,   122,     0,     0,     0,   123,   120,   124,
       0,     0,   232,   186,   187,   242,     0,     0,     0,   125,
     126,     0,   188,     0,     0,   285,   121,     0,     0,   189,
       0,   122,     0,   190,   191,   123,     0,   124,   192,   193,
     194,     0,   195,     0,   196,     0,   197,   125,   126,   186,
     187,     0,     0,     0,     0,     0,     0,   198,   188,     0,
     286,     0,     0,   146,   147,   189,     0,     0,     0,   190,
     191,     0,   148,     0,   192,   193,   194,     0,   195,   149,
     196,     0,   197,   150,   151,     0,     0,     0,   152,   153,
     154,     0,   155,   198,   156,   332,   157,     0,     0,   186,
     187,     0,     0,     0,     0,   158,     0,   159,   188,   203,
       0,     0,     0,   146,   147,   189,     0,     0,     0,   190,
     191,     0,   148,     0,   192,   193,   194,     0,   195,   149,
     196,     0,   197,   150,   151,     0,     0,     0,   152,   153,
     154,     0,   155,   198,   156,     0,   157,   186,   187,     0,
       0,     0,     0,   209,   238,     0,   188,   159,     0,     0,
       0,   186,   187,   189,     0,     0,     0,   190,   191,     0,
     188,     0,   192,   193,   194,     0,   195,   189,   196,     0,
     197,   190,   191,     0,     0,     0,   192,   193,   194,     0,
     195,   198,   196,     0,   197,   186,   187,     0,     0,     0,
       0,     0,   240,     0,   188,   198,     0,     0,     0,     0,
       0,   189,     0,     0,     0,   190,   191,     0,     0,     0,
     192,   193,   194,     0,   195,     0,   196,     0,   197,   186,
     187,     0,     0,     0,     0,   245,   267,     0,   188,   198,
       0,     0,     0,     0,     0,   189,     0,     0,     0,   190,
     191,     0,     0,     0,   192,   193,   194,     0,   195,     0,
     196,     0,   197,   146,   147,     0,     0,     0,     0,   277,
       0,     0,   148,   198,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   151,     0,     0,     0,   152,   153,
     154,     0,   155,     0,   156,     0,   157,   186,   187,     0,
       0,     0,     0,     0,   287,     0,   188,   159,     0,     0,
       0,   186,   187,   189,     0,     0,     0,   190,   191,     0,
     188,     0,   192,   193,   194,     0,   195,   189,   196,     0,
     197,   190,   191,     0,     0,     0,   192,   193,   194,     0,
     195,   198,   196,     0,   197,   186,   187,     0,     0,     0,
       0,   289,     0,     0,   188,   198,     0,     0,     0,     0,
       0,   189,     0,     0,     0,   190,   191,     0,     0,     0,
     192,   193,   194,     0,   195,     0,   196,     0,   197,   186,
     187,     0,     0,     0,     0,   290,     0,     0,   188,   198,
       0,     0,     0,     0,     0,   189,     0,     0,     0,   190,
     191,     0,     0,     0,   192,   193,   194,     0,   195,     0,
     196,     0,   197,   186,   187,     0,     0,     0,     0,   291,
       0,     0,   188,   198,     0,     0,     0,     0,     0,   189,
       0,     0,     0,   190,   191,     0,     0,     0,   192,   193,
     194,     0,   195,     0,   196,     0,   197,   186,   187,     0,
       0,     0,     0,   292,     0,     0,   188,   198,     0,     0,
       0,     0,     0,   189,     0,     0,     0,   190,   191,     0,
       0,     0,   192,   193,   194,     0,   195,     0,   196,     0,
     197,   146,   147,     0,     0,     0,     0,     0,   310,     0,
     148,   198,     0,     0,     0,   146,   147,   149,     0,     0,
       0,   150,   151,     0,   148,     0,   152,   153,   154,     0,
     155,   149,   156,     0,   157,   150,   151,     0,     0,     0,
     152,   153,   154,   321,   155,   159,   156,     0,   157,     0,
       0,   186,   187,     0,     0,     0,   325,     0,     0,   159,
     188,   329,     0,     0,     0,   186,   187,   189,     0,     0,
       0,   190,   191,     0,   188,   330,   192,   193,   194,     0,
     195,   189,   196,     0,   197,   190,   191,     0,     0,     0,
     192,   193,   194,     0,   195,   198,   196,     0,   197,   186,
     187,     0,     0,     0,     0,     0,     0,     0,   188,   198,
       0,     0,     0,   146,   147,   189,     0,     0,     0,   190,
     191,     0,   148,     0,   192,   193,   194,     0,   195,   149,
     196,     0,   197,   150,   151,   186,   187,     0,   152,   153,
     154,     0,   155,   198,   188,     0,   157,     0,     0,   146,
       0,   189,     0,     0,     0,   190,   191,   159,   148,     0,
     192,   193,   194,     0,   195,   149,     0,     0,   197,   150,
     151,   186,     0,     0,   152,   153,   154,     0,   155,   198,
     188,     0,   157,     0,     0,   146,     0,   189,     0,     0,
       0,   190,   191,   159,   148,     0,   192,   193,   194,     0,
     195,    -1,     0,     0,   197,    -1,    -1,   186,     0,     0,
      -1,    -1,   154,     0,    -1,   198,   188,     0,   157,     0,
       0,     0,     0,    -1,     0,     0,     0,    -1,    -1,   159,
       0,     0,    -1,    -1,   194,    23,    -1,    28,     0,    35,
     197,    37,     0,    41,     0,     0,     0,     0,     0,     0,
       0,   198,    50,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   110
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-250))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
       5,    26,    57,    48,   240,     8,     0,    91,    92,    93,
      11,     0,     5,     7,    15,    26,    15,     5,    16,    13,
      23,     5,    58,   272,    60,     9,     5,    26,    31,     5,
      24,    42,    57,    18,    37,    29,    34,    18,    41,    33,
      85,     5,    40,    42,   280,    30,    31,    50,    18,    52,
      31,    20,     5,    22,    55,    55,    55,    58,    58,    58,
      44,    31,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   310,   159,     5,   113,   114,    58,
     164,    84,    58,    77,     5,   121,   122,     0,   337,   125,
      95,    11,    23,    18,     7,   344,   101,   133,    26,    26,
       5,   137,    16,    24,   129,    30,    31,   110,    29,    13,
     135,    30,    30,    23,    42,    42,    29,   162,    14,    18,
      34,    58,    43,    49,    45,    46,    40,    55,    23,    50,
      58,    58,    49,     5,    18,     5,    30,    30,    59,    60,
      22,   177,   178,   179,   199,    10,   182,   183,   203,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,    49,   169,    18,   202,     3,     4,     5,
       6,    18,    47,    13,   199,    31,    12,    18,   203,    47,
     225,   226,     3,     4,     5,     6,   231,   271,    49,    49,
      18,     5,    10,   277,    30,    30,    30,    30,    30,    35,
     236,     5,   238,    39,    56,    41,    18,    49,     5,    30,
      13,    47,    13,    22,    35,    51,    52,    13,    49,    18,
      14,    23,    49,    13,     5,    25,    21,     7,     8,    22,
      51,   267,    47,    49,   279,    13,    16,    47,   263,    47,
      25,    47,    49,    23,    49,    13,    37,    27,    28,   285,
     286,   287,    32,    33,    34,    22,    36,   293,    38,    22,
      40,    49,   317,    49,    22,     0,    12,   321,    44,   274,
     208,    51,   307,    53,   329,   330,   106,   332,   327,   324,
     135,     3,     4,     5,     6,   342,   295,   282,   298,   205,
      12,   336,   317,   338,   314,    -1,    -1,    -1,   303,    -1,
      -1,    -1,   307,    -1,   329,   330,    -1,   332,    30,     3,
       4,     5,     6,    35,    -1,    -1,    -1,    39,    12,    41,
      -1,    -1,   327,     7,     8,    47,    -1,    -1,    -1,    51,
      52,    -1,    16,    -1,    -1,    19,    30,    -1,    -1,    23,
      -1,    35,    -1,    27,    28,    39,    -1,    41,    32,    33,
      34,    -1,    36,    -1,    38,    -1,    40,    51,    52,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    51,    16,    -1,
      54,    -1,    -1,     7,     8,    23,    -1,    -1,    -1,    27,
      28,    -1,    16,    -1,    32,    33,    34,    -1,    36,    23,
      38,    -1,    40,    27,    28,    -1,    -1,    -1,    32,    33,
      34,    -1,    36,    51,    38,    53,    40,    -1,    -1,     7,
       8,    -1,    -1,    -1,    -1,    49,    -1,    51,    16,    17,
      -1,    -1,    -1,     7,     8,    23,    -1,    -1,    -1,    27,
      28,    -1,    16,    -1,    32,    33,    34,    -1,    36,    23,
      38,    -1,    40,    27,    28,    -1,    -1,    -1,    32,    33,
      34,    -1,    36,    51,    38,    -1,    40,     7,     8,    -1,
      -1,    -1,    -1,    47,    14,    -1,    16,    51,    -1,    -1,
      -1,     7,     8,    23,    -1,    -1,    -1,    27,    28,    -1,
      16,    -1,    32,    33,    34,    -1,    36,    23,    38,    -1,
      40,    27,    28,    -1,    -1,    -1,    32,    33,    34,    -1,
      36,    51,    38,    -1,    40,     7,     8,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    16,    51,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      32,    33,    34,    -1,    36,    -1,    38,    -1,    40,     7,
       8,    -1,    -1,    -1,    -1,    47,    14,    -1,    16,    51,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    32,    33,    34,    -1,    36,    -1,
      38,    -1,    40,     7,     8,    -1,    -1,    -1,    -1,    13,
      -1,    -1,    16,    51,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    32,    33,
      34,    -1,    36,    -1,    38,    -1,    40,     7,     8,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    16,    51,    -1,    -1,
      -1,     7,     8,    23,    -1,    -1,    -1,    27,    28,    -1,
      16,    -1,    32,    33,    34,    -1,    36,    23,    38,    -1,
      40,    27,    28,    -1,    -1,    -1,    32,    33,    34,    -1,
      36,    51,    38,    -1,    40,     7,     8,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    16,    51,    -1,    -1,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      32,    33,    34,    -1,    36,    -1,    38,    -1,    40,     7,
       8,    -1,    -1,    -1,    -1,    47,    -1,    -1,    16,    51,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    32,    33,    34,    -1,    36,    -1,
      38,    -1,    40,     7,     8,    -1,    -1,    -1,    -1,    47,
      -1,    -1,    16,    51,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    32,    33,
      34,    -1,    36,    -1,    38,    -1,    40,     7,     8,    -1,
      -1,    -1,    -1,    47,    -1,    -1,    16,    51,    -1,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    27,    28,    -1,
      -1,    -1,    32,    33,    34,    -1,    36,    -1,    38,    -1,
      40,     7,     8,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      16,    51,    -1,    -1,    -1,     7,     8,    23,    -1,    -1,
      -1,    27,    28,    -1,    16,    -1,    32,    33,    34,    -1,
      36,    23,    38,    -1,    40,    27,    28,    -1,    -1,    -1,
      32,    33,    34,    49,    36,    51,    38,    -1,    40,    -1,
      -1,     7,     8,    -1,    -1,    -1,    48,    -1,    -1,    51,
      16,    17,    -1,    -1,    -1,     7,     8,    23,    -1,    -1,
      -1,    27,    28,    -1,    16,    17,    32,    33,    34,    -1,
      36,    23,    38,    -1,    40,    27,    28,    -1,    -1,    -1,
      32,    33,    34,    -1,    36,    51,    38,    -1,    40,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    51,
      -1,    -1,    -1,     7,     8,    23,    -1,    -1,    -1,    27,
      28,    -1,    16,    -1,    32,    33,    34,    -1,    36,    23,
      38,    -1,    40,    27,    28,     7,     8,    -1,    32,    33,
      34,    -1,    36,    51,    16,    -1,    40,    -1,    -1,     7,
      -1,    23,    -1,    -1,    -1,    27,    28,    51,    16,    -1,
      32,    33,    34,    -1,    36,    23,    -1,    -1,    40,    27,
      28,     7,    -1,    -1,    32,    33,    34,    -1,    36,    51,
      16,    -1,    40,    -1,    -1,     7,    -1,    23,    -1,    -1,
      -1,    27,    28,    51,    16,    -1,    32,    33,    34,    -1,
      36,    23,    -1,    -1,    40,    27,    28,     7,    -1,    -1,
      32,    33,    34,    -1,    36,    51,    16,    -1,    40,    -1,
      -1,    -1,    -1,    23,    -1,    -1,    -1,    27,    28,    51,
      -1,    -1,    32,    33,    34,     7,    36,     9,    -1,    11,
      40,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    26,    42,    55,    58,    62,    63,    65,    66,
      67,    68,    69,    75,    76,    85,     5,     5,     5,     5,
       5,    83,     0,    65,    75,    85,    11,    74,    65,    63,
      72,    73,    74,    75,    85,    65,    72,    65,    85,     5,
      77,    65,    23,    30,    30,    23,    14,    84,    13,    74,
      65,    85,    65,     5,    24,    29,    43,    45,    46,    50,
      59,    60,    87,    89,    90,    91,    93,    94,    95,    96,
      97,    98,   100,   102,   104,   107,    18,    75,    85,    49,
      74,    85,    49,    74,    65,    23,    74,     3,     4,     5,
       6,    30,    35,    51,   109,    58,    70,    83,    70,     5,
       9,    44,    78,    79,    80,    82,     5,    78,    18,    74,
      65,    74,    18,    30,    31,     5,     3,     4,     5,     6,
      12,    30,    35,    39,    41,    51,    52,   105,   107,    30,
      87,   105,   105,    30,    22,    49,    88,    10,    85,    18,
      74,    78,    18,   109,   109,   109,     7,     8,    16,    23,
      27,    28,    32,    33,    34,    36,    38,    40,    49,    51,
      83,    47,    13,    47,    31,    81,    83,    49,    84,    49,
      18,    74,    18,     5,    47,   105,   105,    10,    30,    30,
     105,   105,    30,    30,   105,    30,     7,     8,    16,    23,
      27,    28,    32,    33,    34,    36,    38,    40,    51,    53,
       5,   107,    56,    17,   105,    89,   105,    18,    49,    47,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,     5,    64,   109,    13,    13,    78,    49,   109,
      22,    13,    83,    86,    18,    18,    31,   108,    14,   103,
      48,   105,    47,   105,   105,    47,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,    87,    14,    99,   105,    87,    14,   101,    88,
      77,    23,    78,    78,    49,    71,    25,    13,    78,    13,
       5,   105,   105,    47,   108,    19,    54,    14,   106,    47,
      47,    47,    47,    21,    92,   107,    47,    22,   105,    47,
     109,    71,    49,    58,    83,    49,   109,    49,    78,   108,
      48,   103,   105,   105,   105,    47,   105,    20,    22,    99,
     101,    49,    25,    83,    13,    48,    81,    49,   108,    17,
      17,   106,    53,    87,    64,    49,    13,    78,    37,    86,
      87,    87,    87,    22,    78,    71,    78,    22,    22,    92,
      71
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 10:

/* Line 1806 of yacc.c  */
#line 195 "cpsl.y"
    {Table::MakeConst((yyvsp[(2) - (6)].name_ptr),(yyvsp[(4) - (6)].const_type));}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 199 "cpsl.y"
    {Table::MakeConst((yyvsp[(1) - (5)].name_ptr),(yyvsp[(3) - (5)].const_type));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 207 "cpsl.y"
    {Element element(new Function((yyvsp[(2) - (8)].name_ptr),*(yyvsp[(4) - (8)].formalParameter),(yyvsp[(2) - (8)].name_ptr),true)); Table::InsertElement((yyvsp[(2) - (8)].name_ptr), element);}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 208 "cpsl.y"
    {Table::RemoveScope();}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 211 "cpsl.y"
    {Element element(new Function((yyvsp[(2) - (6)].name_ptr),*(yyvsp[(4) - (6)].formalParameter),(yyvsp[(2) - (6)].name_ptr),false)); Table::InsertElement((yyvsp[(2) - (6)].name_ptr), element); Table::AddScope((yyvsp[(4) - (6)].formalParameter));}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 214 "cpsl.y"
    {Element element(new Function(std::shared_ptr<Type>((yyvsp[(7) - (10)].type)),(yyvsp[(2) - (10)].name_ptr),*(yyvsp[(4) - (10)].formalParameter),(yyvsp[(2) - (10)].name_ptr),true)); Table::InsertElement((yyvsp[(2) - (10)].name_ptr), element);}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 215 "cpsl.y"
    {Table::RemoveScope();}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 218 "cpsl.y"
    {Element element(new Function(std::shared_ptr<Type>((yyvsp[(7) - (8)].type)),(yyvsp[(2) - (8)].name_ptr),*(yyvsp[(4) - (8)].formalParameter),(yyvsp[(2) - (8)].name_ptr),false)); Table::InsertElement((yyvsp[(2) - (8)].name_ptr), element); Table::AddScope((yyvsp[(4) - (8)].formalParameter));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 221 "cpsl.y"
    {(yyval.formalParameter) = new std::vector<std::shared_ptr<Var>>;}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 222 "cpsl.y"
    {(yyval.formalParameter) = Table::MakeVars((yyvsp[(4) - (5)].type),(yyvsp[(2) - (5)].identList),(yyvsp[(5) - (5)].formalParameter));}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 223 "cpsl.y"
    {(yyval.formalParameter) = Table::MakeVars((yyvsp[(3) - (4)].type),(yyvsp[(1) - (4)].identList),(yyvsp[(4) - (4)].formalParameter));}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 226 "cpsl.y"
    {(yyval.formalParameter) = Table::MakeVars((yyvsp[(5) - (6)].type),(yyvsp[(3) - (6)].identList),(yyvsp[(6) - (6)].formalParameter));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 227 "cpsl.y"
    {(yyval.formalParameter) = Table::MakeVars((yyvsp[(4) - (5)].type),(yyvsp[(2) - (5)].identList),(yyvsp[(5) - (5)].formalParameter));}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 228 "cpsl.y"
    {(yyval.formalParameter) = new std::vector<std::shared_ptr<Var>>;}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 250 "cpsl.y"
    {(yyvsp[(4) - (5)].type)->m_name = (yyvsp[(2) - (5)].name_ptr); Element e((yyvsp[(4) - (5)].type)); Table::InsertElement((yyvsp[(2) - (5)].name_ptr), e);}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 254 "cpsl.y"
    {(yyvsp[(3) - (5)].type)->m_name = (yyvsp[(1) - (5)].name_ptr); Element e((yyvsp[(3) - (5)].type)); Table::InsertElement((yyvsp[(1) - (5)].name_ptr), e);}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 257 "cpsl.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 258 "cpsl.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 259 "cpsl.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 262 "cpsl.y"
    {(yyval.type) = Table::MakeSimple((yyvsp[(1) - (1)].name_ptr));}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 265 "cpsl.y"
    {(yyval.type) = Table::MakeRecord((yyvsp[(2) - (3)].typeList));}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 268 "cpsl.y"
    {(yyval.typeList) = Table::MakeSubRecord((yyvsp[(3) - (5)].type),(yyvsp[(5) - (5)].typeList), (yyvsp[(1) - (5)].identList));}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 269 "cpsl.y"
    {(yyval.typeList) = new std::vector<std::shared_ptr<Type>>;}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 272 "cpsl.y"
    {(yyval.type) = new Array(Table::getSize((yyvsp[(3) - (8)].const_type)),Table::getSize((yyvsp[(5) - (8)].const_type)),std::shared_ptr<Type>((yyvsp[(8) - (8)].type)),Table::getArraySize((yyvsp[(3) - (8)].const_type),(yyvsp[(5) - (8)].const_type),(yyvsp[(8) - (8)].type)->m_size), (yyvsp[(8) - (8)].type)->m_name);}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 275 "cpsl.y"
    {(yyvsp[(2) - (2)].identList)->push_back((yyvsp[(1) - (2)].name_ptr)); (yyval.identList) = (yyvsp[(2) - (2)].identList);}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 278 "cpsl.y"
    {(yyval.identList) = new std::vector<std::string>;}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 279 "cpsl.y"
    {(yyvsp[(3) - (3)].identList)->push_back((yyvsp[(2) - (3)].name_ptr)); (yyval.identList) = (yyvsp[(3) - (3)].identList);}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 282 "cpsl.y"
    {Table::MakeVar((yyvsp[(2) - (6)].identList),(yyvsp[(4) - (6)].type)); delete (yyvsp[(2) - (6)].identList); delete (yyvsp[(4) - (6)].type);}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 286 "cpsl.y"
    {Table::MakeVar((yyvsp[(1) - (5)].identList),(yyvsp[(3) - (5)].type)); delete (yyvsp[(1) - (5)].identList); delete (yyvsp[(3) - (5)].type);}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 404 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),OR,(yyvsp[(3) - (3)].const_type));}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 405 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),AND,(yyvsp[(3) - (3)].const_type));}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 406 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),EQUAL,(yyvsp[(3) - (3)].const_type));}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 407 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),NOT_EQUAL,(yyvsp[(3) - (3)].const_type));}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 408 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),LESS_EQUAL,(yyvsp[(3) - (3)].const_type));}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 409 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),GREAT_EQUAL,(yyvsp[(3) - (3)].const_type));}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 410 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),LESS,(yyvsp[(3) - (3)].const_type));}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 411 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),GREAT,(yyvsp[(3) - (3)].const_type));}
    break;

  case 135:

/* Line 1806 of yacc.c  */
#line 412 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),ADD,(yyvsp[(3) - (3)].const_type));}
    break;

  case 136:

/* Line 1806 of yacc.c  */
#line 413 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),SUB,(yyvsp[(3) - (3)].const_type));}
    break;

  case 137:

/* Line 1806 of yacc.c  */
#line 414 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),MULT,(yyvsp[(3) - (3)].const_type));}
    break;

  case 138:

/* Line 1806 of yacc.c  */
#line 415 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),DIV,(yyvsp[(3) - (3)].const_type));}
    break;

  case 139:

/* Line 1806 of yacc.c  */
#line 416 "cpsl.y"
    {(yyval.const_type) = Table::makeConst((yyvsp[(1) - (3)].const_type),MOD,(yyvsp[(3) - (3)].const_type));}
    break;

  case 140:

/* Line 1806 of yacc.c  */
#line 417 "cpsl.y"
    {(yyval.const_type) = Table::makeConst(new Const("",UNKNOWN),NOT,(yyvsp[(2) - (2)].const_type));}
    break;

  case 141:

/* Line 1806 of yacc.c  */
#line 418 "cpsl.y"
    {(yyval.const_type) = Table::makeConst(new Const("",UNKNOWN),UNARY,(yyvsp[(2) - (2)].const_type));}
    break;

  case 142:

/* Line 1806 of yacc.c  */
#line 419 "cpsl.y"
    {(yyval.const_type) = (yyvsp[(2) - (3)].const_type);}
    break;

  case 143:

/* Line 1806 of yacc.c  */
#line 420 "cpsl.y"
    {(yyval.const_type) = new Const(std::to_string((yyvsp[(1) - (1)].int_val)),INT);}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 421 "cpsl.y"
    {(yyval.const_type) = new Const((yyvsp[(1) - (1)].name_ptr),CHAR);}
    break;

  case 145:

/* Line 1806 of yacc.c  */
#line 422 "cpsl.y"
    {(yyval.const_type) = new Const((yyvsp[(1) - (1)].name_ptr),STRING);}
    break;

  case 146:

/* Line 1806 of yacc.c  */
#line 423 "cpsl.y"
    {(yyval.const_type) = new Const((yyvsp[(1) - (1)].name_ptr),ID);}
    break;



/* Line 1806 of yacc.c  */
#line 2240 "cpsl.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 425 "cpsl.y"


//inputfile, outputfile, -v (print to console)
int main(int argc, char ** argv)
{
	argc--, argv++;
	
	Output::SetFilePath("bob.asm");
	// Output::out("testing to see if it even works");


	/*
	if(argc >= 3)
	{
		std::string filePath = argv[1];
		Logger::SetFilePath(filePath);
		std::string logLevel = argv[2];
		if(logLevel == "-v")
			Logger::SetLevel(VERBOSE);
		else if(logLevel == "-e")
			Logger::SetLevel(ERROR);
		else if(logLevel == "-s")
			Logger::SetLevel(SILENT);
		else if(logLevel == "-d")
			Logger::SetLevel(DEBUG);
	}
	else if(argc == 2)
	{
		std::string arg1 = argv[1];
		if(arg1 == "-v")
			Logger::SetLevel(VERBOSE);
		else if(arg1 == "-e")
			Logger::SetLevel(ERROR);
		else if(arg1 == "-s")
			Logger::SetLevel(SILENT);
		else if(arg1 == "-d")
			Logger::SetLevel(DEBUG);
		else
			Logger::SetFilePath(arg1);
	}
	*/

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
	Table::PrintTable();
	return 0;
};

void yyerror(const char * message) 
{
	Logger::LogError(message, numLines);
	exit(-1);
}
