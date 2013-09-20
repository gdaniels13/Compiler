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

#include <iostream>
#include <string>
#include <cstdio>
#define YYERROR_VERBOSE 1


extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int numLines;

int yylex();

int yyerror(const char *p) 
{ 
	fprintf(stdout, "%s", p);
	std::cout << " on line "<< numLines  << std::endl; 

}



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

/* Line 293 of yacc.c  */
#line 83 "cpsl.y"
	
	int int_val;
	char *name_ptr;



/* Line 293 of yacc.c  */
#line 197 "cpsl.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 209 "cpsl.tab.c"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   426

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNRULES -- Number of states.  */
#define YYNSTATES  290

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
       0,     0,     3,    10,    13,    16,    17,    24,    25,    34,
      43,    54,    65,    66,    72,    77,    84,    90,    91,    96,
     100,   107,   108,   114,   115,   117,   119,   121,   123,   127,
     133,   134,   143,   146,   150,   151,   158,   159,   165,   166,
     169,   173,   174,   176,   178,   180,   182,   184,   186,   188,
     190,   192,   194,   196,   200,   208,   214,   215,   218,   219,
     225,   230,   240,   242,   244,   246,   249,   251,   257,   261,
     262,   268,   272,   273,   277,   283,   287,   288,   289,   293,
     296,   299,   303,   308,   313,   318,   323,   328,   330,   332,
     334,   336,   338,   340,   344,   349,   351,   353,   355,   357,
     359,   361,   363,   365,   367,   369,   371,   373,   375,   378,
     379,   383,   384,   388,   392,   396,   400,   404,   408,   412,
     416,   420,   424,   428,   432,   436,   439,   442,   446,   448,
     450,   452
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    64,    71,    80,    63,    70,    51,    -1,
      65,    63,    -1,    66,    63,    -1,    -1,    18,     3,    45,
     108,    54,    64,    -1,    -1,    25,     3,    55,    67,    56,
      54,    22,    54,    -1,    25,     3,    55,    67,    56,    54,
      69,    54,    -1,    33,     3,    55,    67,    56,    53,    73,
      54,    22,    54,    -1,    33,     3,    55,    67,    56,    53,
      73,    54,    69,    54,    -1,    -1,    30,    78,    53,    73,
      68,    -1,    78,    53,    73,    68,    -1,    54,    30,    78,
      53,    73,    68,    -1,    54,    78,    53,    73,    68,    -1,
      -1,    64,    71,    80,    70,    -1,     8,    82,    20,    -1,
      16,     3,    45,    73,    54,    72,    -1,    -1,     3,    45,
      73,    54,    72,    -1,    -1,    74,    -1,    75,    -1,    77,
      -1,     3,    -1,    13,    76,    20,    -1,    78,    53,    73,
      54,    76,    -1,    -1,     7,    57,   108,    53,   108,    58,
      12,    73,    -1,     3,    79,    -1,    52,     3,    79,    -1,
      -1,    30,    78,    53,    73,    54,    81,    -1,    -1,    78,
      53,    73,    54,    81,    -1,    -1,    84,    83,    -1,    54,
      84,    83,    -1,    -1,    85,    -1,    86,    -1,    89,    -1,
      90,    -1,    91,    -1,    93,    -1,    94,    -1,    95,    -1,
      97,    -1,    99,    -1,   101,    -1,   104,    37,   108,    -1,
      11,   102,    35,    82,    87,    88,    20,    -1,    10,   102,
      35,    82,    87,    -1,    -1,     9,    82,    -1,    -1,    31,
     102,    19,    82,    20,    -1,    14,    82,    29,   102,    -1,
      21,     3,    37,   102,    92,   102,    19,    82,    20,    -1,
      32,    -1,    15,    -1,    27,    -1,    26,   102,    -1,    26,
      -1,    34,    55,   104,    96,    56,    -1,    52,   104,    96,
      -1,    -1,    36,    55,   102,    98,    56,    -1,    52,   102,
      98,    -1,    -1,     3,    55,    56,    -1,     3,    55,   102,
     100,    56,    -1,    52,   102,   100,    -1,    -1,    -1,   103,
     105,   103,    -1,    44,   102,    -1,    39,   102,    -1,    55,
     102,    56,    -1,     3,    55,   106,    56,    -1,    17,    55,
     102,    56,    -1,    23,    55,   102,    56,    -1,    24,    55,
     102,    56,    -1,    28,    55,   102,    56,    -1,   103,    -1,
     104,    -1,     5,    -1,     4,    -1,     6,    -1,     3,    -1,
     104,    51,   104,    -1,   104,    57,   102,    58,    -1,    43,
      -1,    42,    -1,    45,    -1,    46,    -1,    48,    -1,    50,
      -1,    47,    -1,    49,    -1,    38,    -1,    39,    -1,    40,
      -1,    41,    -1,    59,    -1,   102,   107,    -1,    -1,    52,
     102,   107,    -1,    -1,   108,    43,   108,    -1,   108,    42,
     108,    -1,   108,    45,   108,    -1,   108,    46,   108,    -1,
     108,    48,   108,    -1,   108,    50,   108,    -1,   108,    47,
     108,    -1,   108,    49,   108,    -1,   108,    38,   108,    -1,
     108,    39,   108,    -1,   108,    40,   108,    -1,   108,    41,
     108,    -1,   108,    59,   108,    -1,    44,   108,    -1,    39,
     108,    -1,    55,   108,    56,    -1,     5,    -1,     4,    -1,
       6,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   111,   112,   113,   118,   119,   123,   124,
     127,   128,   131,   132,   133,   136,   137,   138,   141,   145,
     150,   151,   154,   155,   158,   159,   160,   163,   166,   169,
     170,   173,   176,   179,   180,   184,   185,   188,   189,   194,
     197,   198,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   214,   218,   222,   223,   225,   226,   230,
     233,   236,   238,   239,   242,   245,   246,   249,   252,   253,
     257,   260,   261,   265,   266,   269,   270,   273,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   292,   293,
     294,   295,   298,   299,   300,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   318,   319,
     322,   323,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID_SYMBOL", "CHARACTER_SYMBOL",
  "INTEGER_SYMBOL", "STRING_SYMBOL", "ARRAY_SYMBOL", "BEGIN_SYMBOL",
  "ELSE_SYMBOL", "ELSEIF_SYMBOL", "IF_SYMBOL", "OF_SYMBOL",
  "RECORD_SYMBOL", "REPEAT_SYMBOL", "TO_SYMBOL", "TYPE_SYMBOL",
  "CHR_SYMBOL", "CONST_SYMBOL", "DO_SYMBOL", "END_SYMBOL", "FOR_SYMBOL",
  "FORWARD_SYMBOL", "ORD_SYMBOL", "PRED_SYMBOL", "PROCEDURE_SYMBOL",
  "RETURN_SYMBOL", "STOP_SYMBOL", "SUCC_SYMBOL", "UNTIL_SYMBOL",
  "VAR_SYMBOL", "WHILE_SYMBOL", "DOWNTO_SYMBOL", "FUNCTION_SYMBOL",
  "READ_SYMBOL", "THEN_SYMBOL", "WRITE_SYMBOL", "ASSIGN_SYMBOL",
  "ADD_SYMBOL", "SUB_SYMBOL", "MULT_SYMBOL", "DIV_SYMBOL", "AND_SYMBOL",
  "OR_SYMBOL", "NOT_SYMBOL", "EQUAL_SYMBOL", "NOT_EQUAL_SYMBOL",
  "LESS_SYMBOL", "LESS_EQUAL_SYMBOL", "GREAT_SYMBOL", "GREAT_EQUAL_SYMBOL",
  "DOT_SYMBOL", "COMMA_SYMBOL", "COLON_SYMBOL", "SEMI_COLON_SYMBOL",
  "LEFT_BRACE_SYMBOL", "RIGHT_BRACE_SYMBOL", "LEFT_SQUARE_SYMBOL",
  "RIGHT_SQUARE_SYMBOL", "PERCENT_SYMBOL", "UMINUS", "$accept", "Program",
  "subProgram", "ConstantDecl", "ProcedureDecl", "FunctionDecl",
  "FormalParameters", "subFormalParameters", "Body", "Block", "TypeDecl",
  "subTypeDecl", "Type", "SimpleType", "RecordType", "subRecordType",
  "ArrayType", "IdentList", "subIdentList", "VarDecl", "subVarDecl",
  "StatementSequence", "subStatementSequence", "Statement", "Assignment",
  "IfStatement", "subIfStatment", "subElse", "WhileStatement",
  "RepeatStatment", "ForStatement", "subForType", "StopStatement",
  "ReturnStatment", "ReadStatement", "subReadStatement", "WriteStatement",
  "subWriteStatement", "ProcedureCall", "subProcedureCall",
  "NullStatement", "Expression", "subExpression", "LValue", "Operator",
  "subExpressionIdent", "subSubExpressionIndent", "ConstExpression", 0
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
       0,    61,    62,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    68,    68,    68,    69,    70,
      71,    71,    72,    72,    73,    73,    73,    74,    75,    76,
      76,    77,    78,    79,    79,    80,    80,    81,    81,    82,
      83,    83,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    85,    86,    87,    87,    88,    88,    89,
      90,    91,    92,    92,    93,    94,    94,    95,    96,    96,
      97,    98,    98,    99,    99,   100,   100,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   103,   103,
     103,   103,   104,   104,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     2,     0,     6,     0,     8,     8,
      10,    10,     0,     5,     4,     6,     5,     0,     4,     3,
       6,     0,     5,     0,     1,     1,     1,     1,     3,     5,
       0,     8,     2,     3,     0,     6,     0,     5,     0,     2,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     7,     5,     0,     2,     0,     5,
       4,     9,     1,     1,     1,     2,     1,     5,     3,     0,
       5,     3,     0,     3,     5,     3,     0,     0,     3,     2,
       2,     3,     4,     4,     4,     4,     4,     1,     1,     1,
       1,     1,     1,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     0,
       3,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,    21,     0,     1,     0,    36,     0,     0,
       0,     5,   131,   129,   128,   130,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     5,     5,   126,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,    27,     0,    30,     0,    24,
      25,    26,     0,    32,     0,     0,     0,    77,     0,     3,
       4,   127,   120,   121,   122,   123,   113,   112,   114,   115,
     118,   116,   119,   117,     6,   124,     0,     0,     0,    23,
      34,     0,    12,    12,    92,     0,    77,     0,    66,    64,
       0,     0,     0,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     2,     0,    28,
       0,     0,    20,    33,    38,     0,     0,     0,     0,     0,
      92,    90,    89,    91,     0,     0,     0,     0,     0,     0,
       0,     0,    87,    88,     0,     0,    65,     0,     0,     0,
      19,    77,    39,     0,     0,     0,     0,     0,     0,     0,
      35,     0,     0,     0,     0,    73,    76,   109,     0,     0,
       0,     0,    80,    79,     0,    77,   103,   104,   105,   106,
      96,    95,    97,    98,   101,    99,   102,   100,   107,     0,
       0,     0,    77,    92,    69,    72,    41,    53,    93,     0,
       0,    30,     0,     0,     0,     7,    17,     0,     0,     0,
     111,     0,     0,     0,     0,     0,    81,    56,    78,    60,
       0,     0,     0,     0,     0,     0,    40,    94,     0,    29,
      23,     0,    17,     0,    21,     0,     0,    14,     0,    76,
      74,     0,   108,    82,    83,    84,    85,    86,     0,    58,
      63,    62,     0,    59,    69,    67,    72,    70,     0,    22,
      38,    13,     8,    36,     9,     0,     0,     7,    75,   111,
       0,    77,     0,     0,    68,    71,    31,    37,     0,     0,
       0,     0,     0,   110,    77,    57,    54,    77,    18,     0,
      17,    10,    11,    56,     0,    17,    16,    55,    61,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    25,   224,    26,    27,   116,   227,   225,    58,
       7,   112,    48,    49,    50,    77,    51,    78,    53,    11,
     150,    93,   142,    94,    95,    96,   239,   262,    97,    98,
      99,   242,   100,   101,   102,   213,   103,   215,   104,   199,
     105,   131,   132,   133,   179,   201,   232,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -216
static const yytype_int16 yypact[] =
{
       0,    36,    40,    38,    16,  -216,    63,    45,     7,    49,
      93,    34,  -216,  -216,  -216,  -216,     7,     7,     7,   189,
      90,    56,    58,   106,   113,   110,    34,    34,  -216,   322,
     211,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     0,     7,  -216,    60,    93,    70,  -216,
    -216,  -216,   132,  -216,    90,    75,    83,   125,    94,  -216,
    -216,  -216,     4,     4,  -216,  -216,   322,   307,    39,   142,
     337,   352,   367,   127,  -216,  -216,     7,   129,    97,   144,
      56,   100,    11,    11,   103,   109,   125,   152,   109,  -216,
     109,   108,   114,   150,   117,  -216,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,    -4,  -216,   233,  -216,
      90,   130,  -216,  -216,    93,    93,   118,   126,   128,    32,
     134,  -216,  -216,  -216,   135,   137,   147,   148,   109,   109,
     109,   170,   277,    -9,   133,   171,  -216,   166,   184,   109,
    -216,   125,  -216,     7,   184,   109,     7,   153,    90,   156,
    -216,   157,   158,    90,   160,  -216,   159,   109,   109,   109,
     109,   109,  -216,  -216,   162,   125,  -216,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,  -216,   193,
     109,   109,   125,  -216,    17,   163,   117,   292,    -9,   165,
     255,    93,   167,    90,    90,    84,   179,    90,   109,   164,
     172,   169,   185,   186,   188,   190,  -216,   204,  -216,  -216,
       2,   227,   184,   199,   109,   206,  -216,  -216,   251,  -216,
     144,   210,   179,   212,    38,   214,    13,  -216,   215,   159,
    -216,   109,  -216,  -216,  -216,  -216,  -216,  -216,   109,   256,
    -216,  -216,   109,  -216,    17,  -216,   163,  -216,    90,  -216,
      93,  -216,  -216,    45,  -216,    93,   224,   107,  -216,   172,
     249,   125,   265,   268,  -216,  -216,  -216,  -216,   110,   235,
      90,   236,   237,  -216,   125,  -216,  -216,   125,  -216,    90,
     179,  -216,  -216,   204,   269,   179,  -216,  -216,  -216,  -216
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -216,  -216,   -18,    15,  -216,  -216,   216,  -215,    50,    41,
      82,    88,   -53,  -216,  -216,   119,  -216,   -10,   231,    59,
      71,   -83,   143,   187,  -216,  -216,    61,  -216,  -216,  -216,
    -216,  -216,  -216,  -216,  -216,    99,  -216,   104,  -216,   136,
    -216,   -38,   180,   -55,  -216,  -216,   105,   -12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      22,    81,   106,   134,    28,    29,    30,   251,    59,    60,
      12,    13,    14,    15,    21,     3,    21,   240,     1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,   106,    75,   143,   241,   120,   121,   122,   123,     4,
       5,   115,   144,   255,    33,    34,    16,   144,   145,   124,
     136,    17,   137,   145,     6,   125,   126,   147,    74,    23,
     127,     8,    18,    44,   108,   286,     9,    24,   144,   212,
     289,   128,   117,   117,   145,    10,   129,    31,    32,    33,
      34,   156,   207,   184,    -1,    38,   106,   130,   155,   188,
     162,   163,   164,    45,    20,   192,    21,    46,    44,   211,
     196,   185,     1,    47,   149,   151,   223,   189,    52,    55,
     106,    54,   120,   121,   122,   123,    56,    76,    57,   200,
     202,   203,   204,   205,    79,     1,   124,   106,    84,   271,
      82,   187,   125,   126,   190,    80,    85,   127,    83,    86,
     221,   222,   209,   210,   228,   107,    87,   111,   128,   109,
     110,    88,    89,   129,   114,   135,    90,   244,   119,    91,
     229,    92,   180,   138,   130,    31,    32,    33,    34,   139,
     140,   141,    37,    38,   152,   148,   246,    -1,   275,   153,
      31,    32,    33,    34,   154,   182,    44,   183,    -1,   157,
     158,   283,   159,   259,   284,   266,   183,   121,   122,   123,
     260,    44,   160,   161,   263,   165,   106,   191,   181,   193,
     194,   198,   195,   197,   238,   214,   256,   280,   206,   106,
     230,   220,   106,   217,   231,   233,   285,    31,    32,    33,
      34,    35,    36,   226,    37,    38,    39,    40,    41,    42,
     149,   234,   235,    43,   236,   269,   237,   243,    44,    31,
      32,    33,    34,    35,    36,   245,    37,    38,    39,    40,
      41,    42,   247,   248,   250,   261,   252,    61,   254,   257,
      44,    31,    32,    33,    34,    35,    36,   270,    37,    38,
      39,    40,    41,    42,   274,   276,   146,   277,   279,   288,
     281,   282,    44,    31,    32,    33,    34,    35,    36,   118,
      37,    38,    39,    40,    41,    42,   253,   272,   249,   278,
     219,   113,   268,   218,    44,   166,   167,   168,   169,   170,
     171,   267,   172,   173,   174,   175,   176,   177,   186,   216,
      31,    32,    33,    34,    35,    36,   178,    37,    38,    39,
      40,    41,    42,   264,   287,    31,    32,    33,    34,    35,
     265,    44,    37,    38,    39,    40,    41,    42,     0,   208,
      31,    32,    33,    34,   273,   258,    44,    37,    38,    39,
      40,    41,    42,     0,     0,    31,    32,    33,    34,     0,
       0,    44,    37,    38,    -1,    40,    41,    42,     0,     0,
      31,    32,    33,    34,     0,     0,    44,    37,    38,     0,
      -1,    41,    42,     0,     0,    31,    32,    33,    34,     0,
       0,    44,    37,    38,     0,     0,    -1,    42,     0,     0,
       0,     0,     0,     0,     0,     0,    44
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-216))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
      10,    54,    57,    86,    16,    17,    18,   222,    26,    27,
       3,     4,     5,     6,     3,     0,     3,    15,    18,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    86,    44,    37,    32,     3,     4,     5,     6,     3,
       0,    30,    51,    30,    40,    41,    39,    51,    57,    17,
      88,    44,    90,    57,    16,    23,    24,   110,    43,    25,
      28,    45,    55,    59,    76,   280,     3,    33,    51,    52,
     285,    39,    82,    83,    57,    30,    44,    38,    39,    40,
      41,   119,   165,   138,    45,    46,   141,    55,    56,   144,
     128,   129,   130,     3,    45,   148,     3,     7,    59,   182,
     153,   139,    18,    13,   114,   115,    22,   145,    52,     3,
     165,    53,     3,     4,     5,     6,     3,    57,     8,   157,
     158,   159,   160,   161,    54,    18,    17,   182,     3,    22,
      55,   143,    23,    24,   146,     3,    11,    28,    55,    14,
     193,   194,   180,   181,   197,    51,    21,     3,    39,    20,
      53,    26,    27,    44,    54,     3,    31,   212,    55,    34,
     198,    36,    29,    55,    55,    38,    39,    40,    41,    55,
      20,    54,    45,    46,    56,    45,   214,    50,   261,    53,
      38,    39,    40,    41,    56,    19,    59,     3,    46,    55,
      55,   274,    55,   231,   277,   248,     3,     4,     5,     6,
     238,    59,    55,    55,   242,    35,   261,    54,    37,    53,
      53,    52,    54,    53,    10,    52,   226,   270,    56,   274,
      56,    54,   277,    58,    52,    56,   279,    38,    39,    40,
      41,    42,    43,    54,    45,    46,    47,    48,    49,    50,
     250,    56,    56,    54,    56,   255,    56,    20,    59,    38,
      39,    40,    41,    42,    43,    56,    45,    46,    47,    48,
      49,    50,    56,    12,    54,     9,    54,    56,    54,    54,
      59,    38,    39,    40,    41,    42,    43,    53,    45,    46,
      47,    48,    49,    50,    35,    20,    53,    19,    53,    20,
      54,    54,    59,    38,    39,    40,    41,    42,    43,    83,
      45,    46,    47,    48,    49,    50,   224,   257,   220,   268,
     191,    80,   253,    58,    59,    38,    39,    40,    41,    42,
      43,   250,    45,    46,    47,    48,    49,    50,   141,   186,
      38,    39,    40,    41,    42,    43,    59,    45,    46,    47,
      48,    49,    50,   244,   283,    38,    39,    40,    41,    42,
     246,    59,    45,    46,    47,    48,    49,    50,    -1,   179,
      38,    39,    40,    41,   259,   229,    59,    45,    46,    47,
      48,    49,    50,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    59,    45,    46,    47,    48,    49,    50,    -1,    -1,
      38,    39,    40,    41,    -1,    -1,    59,    45,    46,    -1,
      48,    49,    50,    -1,    -1,    38,    39,    40,    41,    -1,
      -1,    59,    45,    46,    -1,    -1,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    62,    64,     3,     0,    16,    71,    45,     3,
      30,    80,     3,     4,     5,     6,    39,    44,    55,   108,
      45,     3,    78,    25,    33,    63,    65,    66,   108,   108,
     108,    38,    39,    40,    41,    42,    43,    45,    46,    47,
      48,    49,    50,    54,    59,     3,     7,    13,    73,    74,
      75,    77,    52,    79,    53,     3,     3,     8,    70,    63,
      63,    56,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,    64,   108,    57,    76,    78,    54,
       3,    73,    55,    55,     3,    11,    14,    21,    26,    27,
      31,    34,    36,    82,    84,    85,    86,    89,    90,    91,
      93,    94,    95,    97,    99,   101,   104,    51,   108,    20,
      53,     3,    72,    79,    54,    30,    67,    78,    67,    55,
       3,     4,     5,     6,    17,    23,    24,    28,    39,    44,
      55,   102,   103,   104,    82,     3,   102,   102,    55,    55,
      20,    54,    83,    37,    51,    57,    53,    73,    45,    78,
      81,    78,    56,    53,    56,    56,   102,    55,    55,    55,
      55,    55,   102,   102,   102,    35,    38,    39,    40,    41,
      42,    43,    45,    46,    47,    48,    49,    50,    59,   105,
      29,    37,    19,     3,   104,   102,    84,   108,   104,   102,
     108,    54,    73,    53,    53,    54,    73,    53,    52,   100,
     102,   106,   102,   102,   102,   102,    56,    82,   103,   102,
     102,    82,    52,    96,    52,    98,    83,    58,    58,    76,
      54,    73,    73,    22,    64,    69,    54,    68,    73,   102,
      56,    52,   107,    56,    56,    56,    56,    56,    10,    87,
      15,    32,    92,    20,   104,    56,   102,    56,    12,    72,
      54,    68,    54,    71,    54,    30,    78,    54,   100,   102,
     102,     9,    88,   102,    96,    98,    73,    81,    80,    78,
      53,    22,    69,   107,    35,    82,    20,    19,    70,    53,
      73,    54,    54,    82,    82,    73,    68,    87,    20,    68
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
      

/* Line 1806 of yacc.c  */
#line 1727 "cpsl.tab.c"
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
#line 352 "cpsl.y"


int main(int argc, char ** argv)
{
	argc--, argv++;
	if(argc > 0)
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
	yyparse();
	return 0;
};

