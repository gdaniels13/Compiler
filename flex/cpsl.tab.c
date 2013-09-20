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
#define YYLAST   448

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
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
       0,     0,     3,    10,    13,    16,    17,    24,    28,    29,
      38,    47,    58,    69,    70,    76,    81,    88,    94,    95,
     100,   104,   111,   112,   118,   119,   121,   123,   125,   127,
     131,   137,   138,   147,   150,   154,   155,   162,   163,   169,
     170,   173,   177,   178,   180,   182,   184,   186,   188,   190,
     192,   194,   196,   198,   200,   204,   212,   218,   219,   222,
     223,   229,   234,   244,   246,   248,   250,   253,   255,   261,
     265,   266,   272,   276,   277,   281,   287,   291,   292,   293,
     297,   300,   303,   307,   312,   317,   322,   327,   332,   334,
     336,   338,   340,   342,   344,   348,   353,   355,   357,   359,
     361,   363,   365,   367,   369,   371,   373,   375,   377,   379,
     382,   383,   387,   388,   392,   396,   400,   404,   408,   412,
     416,   420,   424,   428,   432,   436,   440,   443,   446,   450,
     452,   454,   456
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    64,    72,    81,    63,    71,    51,    -1,
      66,    63,    -1,    67,    63,    -1,    -1,    18,     3,    45,
     109,    54,    65,    -1,    54,    45,   109,    -1,    -1,    25,
       3,    55,    68,    56,    54,    22,    54,    -1,    25,     3,
      55,    68,    56,    54,    70,    54,    -1,    33,     3,    55,
      68,    56,    53,    74,    54,    22,    54,    -1,    33,     3,
      55,    68,    56,    53,    74,    54,    70,    54,    -1,    -1,
      30,    79,    53,    74,    69,    -1,    79,    53,    74,    69,
      -1,    54,    30,    79,    53,    74,    69,    -1,    54,    79,
      53,    74,    69,    -1,    -1,    64,    72,    81,    71,    -1,
       8,    83,    20,    -1,    16,     3,    45,    74,    54,    73,
      -1,    -1,     3,    45,    74,    54,    73,    -1,    -1,    75,
      -1,    76,    -1,    78,    -1,     3,    -1,    13,    77,    20,
      -1,    79,    53,    74,    54,    77,    -1,    -1,     7,    57,
     109,    53,   109,    58,    12,    74,    -1,     3,    80,    -1,
      52,     3,    80,    -1,    -1,    30,    79,    53,    74,    54,
      82,    -1,    -1,    79,    53,    74,    54,    82,    -1,    -1,
      85,    84,    -1,    54,    85,    84,    -1,    -1,    86,    -1,
      87,    -1,    90,    -1,    91,    -1,    92,    -1,    94,    -1,
      95,    -1,    96,    -1,    98,    -1,   100,    -1,   102,    -1,
     105,    37,   109,    -1,    11,   103,    35,    83,    88,    89,
      20,    -1,    10,   103,    35,    83,    88,    -1,    -1,     9,
      83,    -1,    -1,    31,   103,    19,    83,    20,    -1,    14,
      83,    29,   103,    -1,    21,     3,    37,   103,    93,   103,
      19,    83,    20,    -1,    32,    -1,    15,    -1,    27,    -1,
      26,   103,    -1,    26,    -1,    34,    55,   105,    97,    56,
      -1,    52,   105,    97,    -1,    -1,    36,    55,   103,    99,
      56,    -1,    52,   103,    99,    -1,    -1,     3,    55,    56,
      -1,     3,    55,   103,   101,    56,    -1,    52,   103,   101,
      -1,    -1,    -1,   104,   106,   104,    -1,    44,   103,    -1,
      39,   103,    -1,    55,   103,    56,    -1,     3,    55,   107,
      56,    -1,    17,    55,   103,    56,    -1,    23,    55,   103,
      56,    -1,    24,    55,   103,    56,    -1,    28,    55,   103,
      56,    -1,   104,    -1,   105,    -1,     5,    -1,     4,    -1,
       6,    -1,     3,    -1,   105,    51,   105,    -1,   105,    57,
     103,    58,    -1,    43,    -1,    42,    -1,    45,    -1,    46,
      -1,    48,    -1,    50,    -1,    47,    -1,    49,    -1,    38,
      -1,    39,    -1,    40,    -1,    41,    -1,    59,    -1,   103,
     108,    -1,    -1,    52,   103,   108,    -1,    -1,   109,    43,
     109,    -1,   109,    42,   109,    -1,   109,    45,   109,    -1,
     109,    46,   109,    -1,   109,    48,   109,    -1,   109,    50,
     109,    -1,   109,    47,   109,    -1,   109,    49,   109,    -1,
     109,    38,   109,    -1,   109,    39,   109,    -1,   109,    40,
     109,    -1,   109,    41,   109,    -1,   109,    59,   109,    -1,
      44,   109,    -1,    39,   109,    -1,    55,   109,    56,    -1,
       5,    -1,     4,    -1,     6,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   111,   112,   113,   118,   120,   121,   125,
     126,   129,   130,   133,   134,   135,   138,   139,   140,   143,
     147,   152,   153,   156,   157,   160,   161,   162,   165,   168,
     171,   172,   175,   178,   181,   182,   186,   187,   190,   191,
     196,   199,   200,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   216,   220,   224,   225,   227,   228,
     232,   235,   238,   240,   241,   244,   247,   248,   251,   254,
     255,   259,   262,   263,   267,   268,   271,   272,   275,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   294,
     295,   296,   297,   300,   301,   302,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   320,
     321,   324,   325,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348
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
  "subProgram", "ConstantDecl", "subConstantDecl", "ProcedureDecl",
  "FunctionDecl", "FormalParameters", "subFormalParameters", "Body",
  "Block", "TypeDecl", "subTypeDecl", "Type", "SimpleType", "RecordType",
  "subRecordType", "ArrayType", "IdentList", "subIdentList", "VarDecl",
  "subVarDecl", "StatementSequence", "subStatementSequence", "Statement",
  "Assignment", "IfStatement", "subIfStatment", "subElse",
  "WhileStatement", "RepeatStatment", "ForStatement", "subForType",
  "StopStatement", "ReturnStatment", "ReadStatement", "subReadStatement",
  "WriteStatement", "subWriteStatement", "ProcedureCall",
  "subProcedureCall", "NullStatement", "Expression", "subExpression",
  "LValue", "Operator", "subExpressionIdent", "subSubExpressionIndent",
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
       0,    61,    62,    63,    63,    63,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    68,    69,    69,    69,    70,
      71,    72,    72,    73,    73,    74,    74,    74,    75,    76,
      77,    77,    78,    79,    80,    80,    81,    81,    82,    82,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    87,    88,    88,    89,    89,
      90,    91,    92,    93,    93,    94,    95,    95,    96,    97,
      97,    98,    99,    99,   100,   100,   101,   101,   102,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   107,
     107,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     2,     0,     6,     3,     0,     8,
       8,    10,    10,     0,     5,     4,     6,     5,     0,     4,
       3,     6,     0,     5,     0,     1,     1,     1,     1,     3,
       5,     0,     8,     2,     3,     0,     6,     0,     5,     0,
       2,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     7,     5,     0,     2,     0,
       5,     4,     9,     1,     1,     1,     2,     1,     5,     3,
       0,     5,     3,     0,     3,     5,     3,     0,     0,     3,
       2,     2,     3,     4,     4,     4,     4,     4,     1,     1,
       1,     1,     1,     1,     3,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     3,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    22,     0,     1,     0,    37,     0,     0,
       0,     5,   132,   130,   129,   131,     0,     0,     0,     0,
       0,    35,     0,     0,     0,     0,     5,     5,   127,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,    28,     0,    31,     0,    25,
      26,    27,     0,    33,     0,     0,     0,    78,     0,     3,
       4,   128,   121,   122,   123,   124,   114,   113,   115,   116,
     119,   117,   120,   118,     0,     6,   125,     0,     0,     0,
      24,    35,     0,    13,    13,    93,     0,    78,     0,    67,
      65,     0,     0,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,     0,     2,     0,
       0,    29,     0,     0,    21,    34,    39,     0,     0,     0,
       0,     0,    93,    91,    90,    92,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,     0,     0,    66,     0,
       0,     0,    20,    78,    40,     0,     0,     0,     7,     0,
       0,     0,     0,    36,     0,     0,     0,     0,    74,    77,
     110,     0,     0,     0,     0,    81,    80,     0,    78,   104,
     105,   106,   107,    97,    96,    98,    99,   102,   100,   103,
     101,   108,     0,     0,     0,    78,    93,    70,    73,    42,
      54,    94,     0,     0,    31,     0,     0,     0,     0,    18,
       0,     0,     0,   112,     0,     0,     0,     0,     0,    82,
      57,    79,    61,     0,     0,     0,     0,     0,     0,    41,
      95,     0,    30,    24,     0,    18,     0,    22,     0,     0,
      15,     0,    77,    75,     0,   109,    83,    84,    85,    86,
      87,     0,    59,    64,    63,     0,    60,    70,    68,    73,
      71,     0,    23,    39,    14,     9,    37,    10,     0,     0,
       0,    76,   112,     0,    78,     0,     0,    69,    72,    32,
      38,     0,     0,     0,     0,     0,   111,    78,    58,    55,
      78,    19,     0,    18,    11,    12,    57,     0,    18,    17,
      56,    62,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    25,   227,    75,    26,    27,   118,   230,   228,
      58,     7,   114,    48,    49,    50,    78,    51,    79,    53,
      11,   153,    94,   144,    95,    96,    97,   242,   265,    98,
      99,   100,   245,   101,   102,   103,   216,   104,   218,   105,
     202,   106,   133,   134,   135,   182,   204,   235,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -222
static const yytype_int16 yypact[] =
{
      -1,    24,    31,    12,    16,  -222,    65,    42,     9,    34,
      77,    -7,  -222,  -222,  -222,  -222,     9,     9,     9,   211,
      17,    29,    30,    83,    84,    85,    -7,    -7,  -222,   344,
     233,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,    40,     9,  -222,    45,    77,    43,  -222,
    -222,  -222,    96,  -222,    17,    49,    50,   180,    57,  -222,
    -222,  -222,    10,    10,  -222,  -222,   344,   329,   128,   -30,
     359,   374,   389,    79,    64,  -222,  -222,     9,    90,    59,
     112,    29,    67,     3,     3,    68,   153,   180,   123,   153,
    -222,   153,    86,    91,   119,    95,  -222,  -222,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,  -222,   -32,  -222,     9,
     255,  -222,    17,   100,  -222,  -222,    77,    77,    97,    87,
      99,    72,   116,  -222,  -222,  -222,   117,   120,   124,   127,
     153,   153,   153,   143,   299,    14,   122,   115,  -222,   167,
     185,   153,  -222,   180,  -222,     9,   185,   153,   314,     9,
     135,    17,   137,  -222,   142,   145,    17,   147,  -222,   151,
     153,   153,   153,   153,   153,  -222,  -222,   148,   180,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,  -222,   131,   153,   153,   180,  -222,     6,   158,    95,
     314,    14,   154,   277,    77,   159,    17,    17,    38,   161,
      17,   153,   149,   165,   168,   170,   171,   172,   174,  -222,
     213,  -222,  -222,    20,   201,   185,   175,   153,   176,  -222,
    -222,   221,  -222,   112,   182,   161,   183,    12,   184,     4,
    -222,   186,   151,  -222,   153,  -222,  -222,  -222,  -222,  -222,
    -222,   153,   225,  -222,  -222,   153,  -222,     6,  -222,   158,
    -222,    17,  -222,    77,  -222,  -222,    42,  -222,    77,   188,
      48,  -222,   165,   204,   180,   224,   226,  -222,  -222,  -222,
    -222,    85,   194,    17,   208,   209,  -222,   180,  -222,  -222,
     180,  -222,    17,   161,  -222,  -222,   213,   235,   161,  -222,
    -222,  -222,  -222
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,    28,   264,  -222,  -222,  -222,   193,  -221,     7,
      -5,    41,    46,   -53,  -222,  -222,    92,  -222,   -10,   203,
      32,    37,   -84,    98,   156,  -222,  -222,    21,  -222,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,    44,  -222,    36,  -222,
      74,  -222,     1,   129,   -55,  -222,  -222,    47,     5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      22,    82,   107,   136,   254,   145,    21,    21,    31,    32,
      33,    34,    12,    13,    14,    15,    -1,     1,    23,   146,
      45,    28,    29,    30,    46,   147,    24,     4,     6,    44,
      47,     5,   107,   117,   258,   243,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    16,    76,
      33,    34,   244,    17,    59,    60,     1,   146,   215,   150,
     226,     8,   289,   147,    18,   146,     1,   292,     9,    44,
     274,   147,    10,   119,   119,   122,   123,   124,   125,    20,
      21,    52,   110,    54,   210,   187,    55,    56,   107,   126,
     138,   191,   139,    57,    74,   127,   128,    80,   195,    81,
     129,   214,    77,   199,    83,    84,   152,   154,   108,   109,
     111,   130,   112,   107,   148,   113,   131,    31,    32,    33,
      34,   116,   159,   121,    37,    38,   137,   132,   158,    -1,
     107,   165,   166,   167,   186,   123,   124,   125,    44,   142,
     156,   140,   188,   224,   225,   151,   141,   231,   192,   143,
     190,   183,   184,   155,   193,   157,   122,   123,   124,   125,
     247,   203,   205,   206,   207,   208,    31,    32,    33,    34,
     126,   160,   161,    -1,    38,   162,   127,   128,   168,   163,
     278,   129,   164,    85,   212,   213,   185,    44,   186,   194,
     196,    86,   130,   286,    87,   197,   287,   131,   269,   198,
     200,    88,   232,   201,   209,   233,    89,    90,   132,   107,
     217,    91,   220,   223,    92,   229,    93,   234,   249,   259,
     283,   246,   107,   241,   236,   107,   237,   238,   239,   288,
     240,   248,   250,   251,   264,   262,   253,   255,   257,   277,
     260,   273,   263,   152,   279,   280,   266,   282,   272,    31,
      32,    33,    34,    35,    36,   291,    37,    38,    39,    40,
      41,    42,   284,   285,     3,    43,   281,   275,   256,   252,
      44,    31,    32,    33,    34,    35,    36,   120,    37,    38,
      39,    40,    41,    42,   115,   268,   222,   219,   271,    61,
     270,   267,    44,    31,    32,    33,    34,    35,    36,   189,
      37,    38,    39,    40,    41,    42,   261,   290,   149,   276,
       0,   211,     0,     0,    44,    31,    32,    33,    34,    35,
      36,     0,    37,    38,    39,    40,    41,    42,     0,     0,
       0,     0,     0,     0,     0,   221,    44,   169,   170,   171,
     172,   173,   174,     0,   175,   176,   177,   178,   179,   180,
       0,     0,    31,    32,    33,    34,    35,    36,   181,    37,
      38,    39,    40,    41,    42,     0,     0,    31,    32,    33,
      34,    35,     0,    44,    37,    38,    39,    40,    41,    42,
       0,     0,    31,    32,    33,    34,     0,     0,    44,    37,
      38,    39,    40,    41,    42,     0,     0,    31,    32,    33,
      34,     0,     0,    44,    37,    38,    -1,    40,    41,    42,
       0,     0,    31,    32,    33,    34,     0,     0,    44,    37,
      38,     0,    -1,    41,    42,     0,     0,    31,    32,    33,
      34,     0,     0,    44,    37,    38,     0,     0,    -1,    42,
       0,     0,     0,     0,     0,     0,     0,     0,    44
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-222))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
      10,    54,    57,    87,   225,    37,     3,     3,    38,    39,
      40,    41,     3,     4,     5,     6,    46,    18,    25,    51,
       3,    16,    17,    18,     7,    57,    33,     3,    16,    59,
      13,     0,    87,    30,    30,    15,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    39,    44,
      40,    41,    32,    44,    26,    27,    18,    51,    52,   112,
      22,    45,   283,    57,    55,    51,    18,   288,     3,    59,
      22,    57,    30,    83,    84,     3,     4,     5,     6,    45,
       3,    52,    77,    53,   168,   140,     3,     3,   143,    17,
      89,   146,    91,     8,    54,    23,    24,    54,   151,     3,
      28,   185,    57,   156,    55,    55,   116,   117,    51,    45,
      20,    39,    53,   168,   109,     3,    44,    38,    39,    40,
      41,    54,   121,    55,    45,    46,     3,    55,    56,    50,
     185,   130,   131,   132,     3,     4,     5,     6,    59,    20,
      53,    55,   141,   196,   197,    45,    55,   200,   147,    54,
     145,    29,    37,    56,   149,    56,     3,     4,     5,     6,
     215,   160,   161,   162,   163,   164,    38,    39,    40,    41,
      17,    55,    55,    45,    46,    55,    23,    24,    35,    55,
     264,    28,    55,     3,   183,   184,    19,    59,     3,    54,
      53,    11,    39,   277,    14,    53,   280,    44,   251,    54,
      53,    21,   201,    52,    56,    56,    26,    27,    55,   264,
      52,    31,    58,    54,    34,    54,    36,    52,   217,   229,
     273,    20,   277,    10,    56,   280,    56,    56,    56,   282,
      56,    56,    56,    12,     9,   234,    54,    54,    54,    35,
      54,    53,   241,   253,    20,    19,   245,    53,   258,    38,
      39,    40,    41,    42,    43,    20,    45,    46,    47,    48,
      49,    50,    54,    54,     0,    54,   271,   260,   227,   223,
      59,    38,    39,    40,    41,    42,    43,    84,    45,    46,
      47,    48,    49,    50,    81,   249,   194,   189,   256,    56,
     253,   247,    59,    38,    39,    40,    41,    42,    43,   143,
      45,    46,    47,    48,    49,    50,   232,   286,    53,   262,
      -1,   182,    -1,    -1,    59,    38,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    48,    49,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    58,    59,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    48,    49,    50,
      -1,    -1,    38,    39,    40,    41,    42,    43,    59,    45,
      46,    47,    48,    49,    50,    -1,    -1,    38,    39,    40,
      41,    42,    -1,    59,    45,    46,    47,    48,    49,    50,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    59,    45,
      46,    47,    48,    49,    50,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    59,    45,    46,    47,    48,    49,    50,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    59,    45,
      46,    -1,    48,    49,    50,    -1,    -1,    38,    39,    40,
      41,    -1,    -1,    59,    45,    46,    -1,    -1,    49,    50,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    62,    64,     3,     0,    16,    72,    45,     3,
      30,    81,     3,     4,     5,     6,    39,    44,    55,   109,
      45,     3,    79,    25,    33,    63,    66,    67,   109,   109,
     109,    38,    39,    40,    41,    42,    43,    45,    46,    47,
      48,    49,    50,    54,    59,     3,     7,    13,    74,    75,
      76,    78,    52,    80,    53,     3,     3,     8,    71,    63,
      63,    56,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,    54,    65,   109,    57,    77,    79,
      54,     3,    74,    55,    55,     3,    11,    14,    21,    26,
      27,    31,    34,    36,    83,    85,    86,    87,    90,    91,
      92,    94,    95,    96,    98,   100,   102,   105,    51,    45,
     109,    20,    53,     3,    73,    80,    54,    30,    68,    79,
      68,    55,     3,     4,     5,     6,    17,    23,    24,    28,
      39,    44,    55,   103,   104,   105,    83,     3,   103,   103,
      55,    55,    20,    54,    84,    37,    51,    57,   109,    53,
      74,    45,    79,    82,    79,    56,    53,    56,    56,   103,
      55,    55,    55,    55,    55,   103,   103,   103,    35,    38,
      39,    40,    41,    42,    43,    45,    46,    47,    48,    49,
      50,    59,   106,    29,    37,    19,     3,   105,   103,    85,
     109,   105,   103,   109,    54,    74,    53,    53,    54,    74,
      53,    52,   101,   103,   107,   103,   103,   103,   103,    56,
      83,   104,   103,   103,    83,    52,    97,    52,    99,    84,
      58,    58,    77,    54,    74,    74,    22,    64,    70,    54,
      69,    74,   103,    56,    52,   108,    56,    56,    56,    56,
      56,    10,    88,    15,    32,    93,    20,   105,    56,   103,
      56,    12,    73,    54,    69,    54,    72,    54,    30,    79,
      54,   101,   103,   103,     9,    89,   103,    97,    99,    74,
      82,    81,    79,    53,    22,    70,   108,    35,    83,    20,
      19,    71,    53,    74,    54,    54,    83,    83,    74,    69,
      88,    20,    69
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
#line 1735 "cpsl.tab.c"
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
#line 354 "cpsl.y"


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

