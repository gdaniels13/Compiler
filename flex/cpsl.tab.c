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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   625

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNRULES -- Number of states.  */
#define YYNSTATES  293

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
      46,    49,    50,    57,    58,    67,    75,    86,    97,    98,
     104,   109,   116,   122,   123,   128,   132,   138,   144,   145,
     147,   149,   151,   153,   157,   163,   164,   173,   176,   180,
     181,   188,   194,   195,   198,   202,   203,   205,   207,   209,
     211,   213,   215,   217,   219,   221,   223,   225,   229,   237,
     243,   244,   247,   248,   254,   259,   269,   271,   274,   276,
     282,   286,   287,   293,   297,   298,   302,   308,   312,   313,
     314,   318,   322,   326,   330,   334,   338,   342,   346,   350,
     354,   358,   362,   366,   369,   372,   376,   381,   387,   392,
     397,   402,   407,   409,   411,   415,   416,   418,   422,   427,
     430,   433,   437,   439,   441,   443
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    64,    71,    80,    63,    70,    51,    -1,
      64,    80,    63,    70,    51,    -1,    64,    71,    63,    70,
      51,    -1,    64,    63,    70,    51,    -1,    71,    80,    63,
      70,    51,    -1,    71,    70,    63,    51,    -1,    80,    70,
      63,    51,    -1,    65,    63,    -1,    66,    63,    -1,    -1,
      18,     3,    45,   104,    54,    64,    -1,    -1,    25,     3,
      55,    67,    56,    54,    22,    54,    -1,    25,     3,    55,
      67,    56,    54,    69,    -1,    33,     3,    55,    67,    56,
      53,    73,    54,    22,    54,    -1,    33,     3,    55,    67,
      56,    53,    73,    54,    69,    54,    -1,    -1,    30,    78,
      53,    73,    68,    -1,    78,    53,    73,    68,    -1,    54,
      30,    78,    53,    73,    68,    -1,    54,    78,    53,    73,
      68,    -1,    -1,    64,    71,    80,    70,    -1,     8,    82,
      20,    -1,    16,     3,    45,    54,    72,    -1,     3,    45,
      73,    54,    72,    -1,    -1,    74,    -1,    75,    -1,    77,
      -1,     3,    -1,    13,    76,    20,    -1,    78,    53,    73,
      54,    76,    -1,    -1,     7,    58,   104,    53,   104,    58,
      12,    73,    -1,     3,    79,    -1,    52,     3,    79,    -1,
      -1,    30,    78,    53,    73,    54,    81,    -1,    78,    53,
      73,    54,    81,    -1,    -1,    84,    83,    -1,    54,    84,
      83,    -1,    -1,    85,    -1,    86,    -1,    89,    -1,    90,
      -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,    96,
      -1,    98,    -1,   100,    -1,   103,    37,   104,    -1,    11,
     101,    35,    82,    87,    88,    20,    -1,    10,   101,    35,
      82,    87,    -1,    -1,     9,    82,    -1,    -1,    31,   101,
      19,    82,    20,    -1,    14,    82,    29,   101,    -1,    21,
       3,    37,   101,    15,   101,    19,    82,    20,    -1,    27,
      -1,    26,   101,    -1,    26,    -1,    34,    55,   103,    95,
      56,    -1,    52,   103,    95,    -1,    -1,    36,    55,   101,
      97,    56,    -1,    52,   101,    97,    -1,    -1,     3,    55,
      56,    -1,     3,    55,   101,    99,    56,    -1,    52,   101,
      99,    -1,    -1,    -1,   101,    43,   101,    -1,   101,    42,
     101,    -1,   101,    45,   101,    -1,   101,    46,   101,    -1,
     101,    48,   101,    -1,   101,    50,   101,    -1,   101,    47,
     101,    -1,   101,    49,   101,    -1,   101,    38,   101,    -1,
     101,    39,   101,    -1,   101,    40,   101,    -1,   101,    41,
     101,    -1,   101,    59,   101,    -1,    44,   101,    -1,    39,
     101,    -1,    55,   101,    56,    -1,     3,    55,   101,    56,
      -1,     3,    55,   101,   102,    56,    -1,    17,    55,   101,
      56,    -1,    23,    55,   101,    56,    -1,    24,    55,   101,
      56,    -1,    28,    55,   101,    56,    -1,   103,    -1,   104,
      -1,    52,   101,   102,    -1,    -1,     3,    -1,     3,    51,
       3,    -1,     3,    57,   101,    58,    -1,    44,   104,    -1,
      39,   104,    -1,    55,   104,    56,    -1,     5,    -1,     4,
      -1,     6,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   103,   104,   105,   106,   107,   108,   111,
     112,   113,   118,   119,   123,   124,   127,   128,   131,   132,
     133,   136,   137,   138,   141,   145,   150,   153,   154,   157,
     158,   159,   162,   165,   168,   169,   172,   175,   178,   179,
     183,   186,   187,   192,   195,   196,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   212,   216,   220,
     221,   223,   224,   228,   231,   234,   237,   240,   241,   244,
     247,   248,   252,   255,   256,   260,   261,   264,   265,   268,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   300,   301,   305,   306,   307,   311,
     312,   313,   314,   315,   316,   317
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
  "RepeatStatment", "ForStatement", "StopStatement", "ReturnStatment",
  "ReadStatement", "subReadStatement", "WriteStatement",
  "subWriteStatement", "ProcedureCall", "subProcedureCall",
  "NullStatement", "Expression", "subExpressionIdent", "LValue",
  "ConstExpression", 0
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
       0,    61,    62,    62,    62,    62,    62,    62,    62,    63,
      63,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    68,    69,    70,    71,    72,    72,    73,
      73,    73,    74,    75,    76,    76,    77,    78,    79,    79,
      80,    81,    81,    82,    83,    83,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    85,    86,    87,
      87,    88,    88,    89,    90,    91,    92,    93,    93,    94,
      95,    95,    96,    97,    97,    98,    98,    99,    99,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   102,   102,   103,   103,   103,   104,
     104,   104,   104,   104,   104,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     5,     4,     5,     4,     4,     2,
       2,     0,     6,     0,     8,     7,    10,    10,     0,     5,
       4,     6,     5,     0,     4,     3,     5,     5,     0,     1,
       1,     1,     1,     3,     5,     0,     8,     2,     3,     0,
       6,     5,     0,     2,     3,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     7,     5,
       0,     2,     0,     5,     4,     9,     1,     2,     1,     5,
       3,     0,     5,     3,     0,     3,     5,     3,     0,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     3,     4,     5,     4,     4,
       4,     4,     1,     1,     3,     0,     1,     3,     4,     2,
       2,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      13,     0,     0,     0,     0,    11,     0,     0,     0,     0,
      39,     0,     1,     0,     0,     0,    11,    11,    11,    11,
      79,    11,    11,    11,     0,     0,     0,    37,     0,     0,
       0,     0,     9,    10,     0,    11,     0,   106,     0,    79,
       0,    68,    66,     0,     0,     0,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,     0,
       0,     0,     0,    28,   115,   113,   112,   114,     0,     0,
       0,     0,    39,    32,     0,    35,     0,    29,    30,    31,
      18,    18,     5,     0,     0,     0,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,   102,   103,
       0,     0,    67,     0,     0,     0,    25,    79,    43,     0,
       7,     0,     8,     0,    26,   110,   109,     0,    13,    38,
       0,     0,     0,    42,     0,     0,     0,     0,     4,     0,
       3,   107,    75,    78,     0,     0,     0,     0,     0,     0,
      94,   103,    93,   103,     0,   103,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,   106,    71,    74,    45,    57,     6,     0,
     111,    12,     0,    33,     0,     0,    40,     0,     0,     0,
       0,     2,     0,     0,   108,     0,     0,     0,     0,     0,
      95,    60,    88,    89,    90,    91,    81,    80,    82,    83,
      86,    84,    87,    85,    92,    64,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,    13,    23,
       0,    78,    76,     0,    96,     0,    98,    99,   100,   101,
       0,    62,     0,    63,    71,    69,    74,    72,    28,     0,
      35,     0,    23,     0,     0,    15,     0,    20,     0,    77,
     105,    97,     0,    79,     0,     0,    70,    73,    27,     0,
      34,    42,    19,    14,     0,     0,     0,    13,   104,    79,
      61,    58,    79,     0,    41,     0,     0,     0,     0,     0,
      60,     0,    36,    24,     0,    23,    16,    17,    59,    65,
      23,    22,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    15,   244,    16,    17,   125,   247,   245,    21,
       6,   114,    76,    77,    78,   121,    79,   122,    27,     7,
     176,    46,   108,    47,    48,    49,   231,   254,    50,    51,
      52,    53,    54,    55,   209,    56,   211,    57,   183,    58,
      97,   225,    98,    99
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -221
static const yytype_int16 yypact[] =
{
      19,     6,    23,    38,    10,    50,    20,    34,    -1,    12,
      29,    31,  -221,    68,    79,    34,    13,    13,    43,    13,
     175,    13,    13,    13,    39,    14,    89,  -221,    27,    48,
      49,    54,  -221,  -221,    34,    13,    34,    44,   176,   175,
      91,   176,  -221,   176,    61,    62,   100,    69,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,    87,
      75,    34,    76,   126,  -221,  -221,  -221,  -221,    14,    14,
      14,    77,    29,  -221,    74,    38,    80,  -221,  -221,  -221,
      18,    18,  -221,    82,    34,    84,   133,     8,   176,    51,
      88,    90,    92,    93,   176,   176,   176,   300,  -221,  -221,
     113,   107,   536,   246,   161,   176,  -221,   175,  -221,    14,
    -221,   114,  -221,   122,  -221,  -221,  -221,   112,   151,  -221,
      14,   152,   118,    38,    38,   117,   121,   119,  -221,   125,
    -221,  -221,  -221,   359,   374,   176,   176,   176,   176,   176,
    -221,  -221,   263,  -221,   396,   112,   175,   176,   176,   176,
     176,   176,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   176,   175,   -18,   131,   418,    69,  -221,  -221,    27,
    -221,  -221,   132,  -221,    27,   134,  -221,   135,   136,    27,
     138,  -221,   176,   139,  -221,   337,   433,   455,   477,   499,
    -221,   184,    15,    15,  -221,  -221,   263,   551,   566,   566,
     566,   566,   566,   566,  -221,   536,   231,   177,   161,   142,
     176,   147,  -221,   153,    14,   154,    27,    27,    96,   156,
      27,   359,  -221,   176,  -221,   157,  -221,  -221,  -221,  -221,
     176,   207,   176,  -221,   131,  -221,   418,  -221,   126,   159,
      38,   160,   156,   164,   213,  -221,    21,  -221,   179,  -221,
     521,  -221,   322,   175,   210,   278,  -221,  -221,  -221,   224,
    -221,    38,  -221,  -221,   209,    38,   188,    97,  -221,   175,
    -221,  -221,   175,    27,  -221,    34,   189,    27,   193,   194,
     184,   223,  -221,  -221,    27,   156,  -221,  -221,  -221,  -221,
     156,  -221,  -221
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,   205,     7,  -221,  -221,   168,  -220,   -17,    -7,
       1,    16,  -107,  -221,  -221,    11,  -221,    -2,   180,    -3,
      -6,   -34,    94,   150,  -221,  -221,   -22,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,    28,  -221,    30,  -221,    46,  -221,
       2,    25,   -16,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      23,    11,    19,    22,    59,   100,    18,     5,    31,     8,
      12,    89,    65,    66,    67,    35,    71,    64,    65,    66,
      67,    10,   262,    59,    10,    90,     9,    83,    20,    85,
      73,    91,    92,    86,    74,     1,    93,     2,    13,    88,
      75,    10,    20,   102,    24,   103,    14,    94,   124,     3,
       3,   265,    95,    68,   111,   149,   150,    25,    69,   115,
     116,   117,   213,    96,   132,   291,     1,   215,    13,    70,
     292,    29,   219,     3,   159,    13,    14,   129,   126,   126,
       3,    26,    30,    14,    28,   141,   143,   145,   164,   133,
     134,    59,    72,    63,   101,    86,   140,   142,   144,    87,
     167,    88,    86,    80,    81,    82,   135,   165,    88,   241,
     242,   172,   191,   248,     2,     2,   104,   105,   243,   278,
     106,   175,   177,   107,   109,   171,   110,   112,   207,   113,
      59,   118,   120,   128,   123,   130,   131,   185,   186,   187,
     188,   189,   160,   136,   161,   137,    59,   138,   139,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   163,   168,   282,   169,   170,     2,
     285,   174,   173,   178,   179,   180,   181,   290,    37,    89,
      65,    66,    67,   208,   221,   214,    38,   216,   217,    39,
     218,   220,   234,    90,   230,   222,    40,   233,   235,    91,
      92,    41,    42,   237,    93,   239,    43,   238,   240,    44,
     246,    45,   236,   251,   261,    94,   253,   259,   263,   270,
      95,    32,    33,    34,    36,   250,    60,    61,    62,     1,
     271,    96,   252,   267,   255,   280,   273,    59,   281,     3,
      84,   277,   284,   289,   266,   264,   232,   286,   287,   127,
     279,   260,   119,    59,   258,   274,    59,   166,   288,   175,
     212,   275,   256,   276,     0,   162,   257,   249,   283,   147,
     148,   149,   150,   151,   152,   268,   153,   154,   155,   156,
     157,   158,     0,     0,   147,   148,   149,   150,   151,   152,
     159,   153,   154,   155,   156,   157,   158,   272,     0,     0,
       0,   147,   148,   149,   150,   159,     0,     0,   153,   154,
     155,   156,   157,   158,     0,     0,   147,   148,   149,   150,
     151,   152,   159,   153,   154,   155,   156,   157,   158,     0,
       0,     0,     0,     0,     0,   146,     0,   159,   147,   148,
     149,   150,   151,   152,     0,   153,   154,   155,   156,   157,
     158,     0,     0,     0,     0,     0,     0,   269,     0,   159,
     147,   148,   149,   150,   151,   152,     0,   153,   154,   155,
     156,   157,   158,     0,     0,   147,   148,   149,   150,   151,
     152,   159,   153,   154,   155,   156,   157,   158,     0,   223,
       0,     0,     0,   224,     0,     0,   159,   147,   148,   149,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
       0,   182,   147,   148,   149,   150,   151,   152,   159,   153,
     154,   155,   156,   157,   158,     0,     0,     0,     0,     0,
       0,     0,   184,   159,   147,   148,   149,   150,   151,   152,
       0,   153,   154,   155,   156,   157,   158,     0,     0,     0,
       0,     0,   190,     0,     0,   159,   147,   148,   149,   150,
     151,   152,     0,   153,   154,   155,   156,   157,   158,     0,
     210,   147,   148,   149,   150,   151,   152,   159,   153,   154,
     155,   156,   157,   158,     0,     0,     0,     0,     0,   226,
       0,     0,   159,   147,   148,   149,   150,   151,   152,     0,
     153,   154,   155,   156,   157,   158,     0,     0,     0,     0,
       0,   227,     0,     0,   159,   147,   148,   149,   150,   151,
     152,     0,   153,   154,   155,   156,   157,   158,     0,     0,
       0,     0,     0,   228,     0,     0,   159,   147,   148,   149,
     150,   151,   152,     0,   153,   154,   155,   156,   157,   158,
       0,     0,     0,     0,     0,   229,     0,     0,   159,   147,
     148,   149,   150,   151,   152,     0,   153,   154,   155,   156,
     157,   158,     0,   223,   147,   148,   149,   150,   151,   152,
     159,   153,   154,   155,   156,   157,   158,     0,     0,   147,
     148,   149,   150,   151,     0,   159,   153,   154,   155,   156,
     157,   158,     0,     0,   147,   148,   149,   150,     0,     0,
     159,    -1,    -1,    -1,    -1,    -1,    -1,     0,     0,     0,
       0,     0,     0,     0,     0,   159
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-221))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
       7,     3,     5,     6,    20,    39,     5,     0,    15,     3,
       0,     3,     4,     5,     6,    18,    25,     3,     4,     5,
       6,     3,   242,    39,     3,    17,     3,    34,     8,    36,
       3,    23,    24,    51,     7,    16,    28,    18,    25,    57,
      13,     3,     8,    41,    45,    43,    33,    39,    30,    30,
      30,    30,    44,    39,    61,    40,    41,    45,    44,    68,
      69,    70,   169,    55,    56,   285,    16,   174,    25,    55,
     290,     3,   179,    30,    59,    25,    33,    84,    80,    81,
      30,    52,     3,    33,    53,    94,    95,    96,   104,    87,
      88,   107,     3,    54,     3,    51,    94,    95,    96,    55,
     109,    57,    51,    55,    55,    51,    55,   105,    57,   216,
     217,   120,   146,   220,    18,    18,    55,    55,    22,    22,
      20,   123,   124,    54,    37,   118,    51,    51,   162,     3,
     146,    54,    58,    51,    54,    51,     3,   135,   136,   137,
     138,   139,    29,    55,    37,    55,   162,    55,    55,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,     3,    51,   273,    45,    56,    18,
     277,    53,    20,    56,    53,    56,    51,   284,     3,     3,
       4,     5,     6,    52,   182,    53,    11,    53,    53,    14,
      54,    53,   208,    17,    10,    56,    21,    20,    56,    23,
      24,    26,    27,    56,    28,   214,    31,    54,    54,    34,
      54,    36,   210,    56,    54,    39,     9,    58,    54,   253,
      44,    16,    17,    18,    19,   223,    21,    22,    23,    16,
      20,    55,   230,    54,   232,   269,    12,   253,   272,    30,
      35,    53,    53,    20,   246,   244,    15,    54,    54,    81,
     267,   240,    72,   269,   238,   261,   272,   107,   280,   261,
     166,   264,   234,   265,    -1,    19,   236,   221,   275,    38,
      39,    40,    41,    42,    43,   250,    45,    46,    47,    48,
      49,    50,    -1,    -1,    38,    39,    40,    41,    42,    43,
      59,    45,    46,    47,    48,    49,    50,    19,    -1,    -1,
      -1,    38,    39,    40,    41,    59,    -1,    -1,    45,    46,
      47,    48,    49,    50,    -1,    -1,    38,    39,    40,    41,
      42,    43,    59,    45,    46,    47,    48,    49,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    59,    38,    39,
      40,    41,    42,    43,    -1,    45,    46,    47,    48,    49,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    59,
      38,    39,    40,    41,    42,    43,    -1,    45,    46,    47,
      48,    49,    50,    -1,    -1,    38,    39,    40,    41,    42,
      43,    59,    45,    46,    47,    48,    49,    50,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      -1,    52,    38,    39,    40,    41,    42,    43,    59,    45,
      46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    38,    39,    40,    41,    42,    43,
      -1,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    59,    38,    39,    40,    41,
      42,    43,    -1,    45,    46,    47,    48,    49,    50,    -1,
      52,    38,    39,    40,    41,    42,    43,    59,    45,    46,
      47,    48,    49,    50,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    38,
      39,    40,    41,    42,    43,    -1,    45,    46,    47,    48,
      49,    50,    -1,    52,    38,    39,    40,    41,    42,    43,
      59,    45,    46,    47,    48,    49,    50,    -1,    -1,    38,
      39,    40,    41,    42,    -1,    59,    45,    46,    47,    48,
      49,    50,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      59,    45,    46,    47,    48,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    18,    30,    62,    64,    71,    80,     3,     3,
       3,    78,     0,    25,    33,    63,    65,    66,    71,    80,
       8,    70,    80,    70,    45,    45,    52,    79,    53,     3,
       3,    70,    63,    63,    63,    80,    63,     3,    11,    14,
      21,    26,    27,    31,    34,    36,    82,    84,    85,    86,
      89,    90,    91,    92,    93,    94,    96,    98,   100,   103,
      63,    63,    63,    54,     3,     4,     5,     6,    39,    44,
      55,   104,     3,     3,     7,    13,    73,    74,    75,    77,
      55,    55,    51,    70,    63,    70,    51,    55,    57,     3,
      17,    23,    24,    28,    39,    44,    55,   101,   103,   104,
      82,     3,   101,   101,    55,    55,    20,    54,    83,    37,
      51,    70,    51,     3,    72,   104,   104,   104,    54,    79,
      58,    76,    78,    54,    30,    67,    78,    67,    51,    70,
      51,     3,    56,   101,   101,    55,    55,    55,    55,    55,
     101,   104,   101,   104,   101,   104,    35,    38,    39,    40,
      41,    42,    43,    45,    46,    47,    48,    49,    50,    59,
      29,    37,    19,     3,   103,   101,    84,   104,    51,    45,
      56,    64,   104,    20,    53,    78,    81,    78,    56,    53,
      56,    51,    52,    99,    58,   101,   101,   101,   101,   101,
      56,    82,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,    82,    52,    95,
      52,    97,    83,    73,    53,    73,    53,    53,    54,    73,
      53,   101,    56,    52,    56,   102,    56,    56,    56,    56,
      10,    87,    15,    20,   103,    56,   101,    56,    54,   104,
      54,    73,    73,    22,    64,    69,    54,    68,    73,    99,
     101,    56,   101,     9,    88,   101,    95,    97,    72,    58,
      76,    54,    68,    54,    71,    30,    78,    54,   102,    35,
      82,    20,    19,    12,    81,    80,    78,    53,    22,    69,
      82,    82,    73,    70,    53,    73,    54,    54,    87,    20,
      73,    68,    68
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
#line 1761 "cpsl.tab.c"
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
#line 323 "cpsl.y"


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

