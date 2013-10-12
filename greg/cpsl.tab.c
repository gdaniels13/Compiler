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

#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <cstdio>
#include "Symbols.h"
#include "logger.h"
#include "SymbolTable.h"

#define YYERROR_VERBOSE 1


extern "C" int yyparse();
extern "C" FILE *yyin;
extern "C" int numLines;

int yylex();

int yyerror(const char *p) 
{ 
	Logger::logError(p,numLines);
}

void debug(std::string t)
{
	//std::cout<<t<<std::endl;
}



/* Line 268 of yacc.c  */
#line 103 "cpsl.tab.c"

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

/* Line 293 of yacc.c  */
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



/* Line 293 of yacc.c  */
#line 213 "cpsl.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 225 "cpsl.tab.c"

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
#define YYLAST   494

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  289

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
       0,     0,     3,    10,    13,    16,    17,    24,    25,    31,
      32,    41,    50,    61,    72,    73,    79,    84,    91,    97,
      98,   104,   105,   109,   112,   113,   119,   120,   122,   124,
     126,   128,   132,   138,   139,   148,   151,   155,   156,   163,
     164,   170,   171,   174,   178,   179,   181,   183,   185,   187,
     189,   191,   193,   195,   197,   199,   201,   205,   213,   219,
     220,   223,   224,   230,   235,   245,   247,   249,   251,   254,
     256,   262,   266,   267,   273,   277,   278,   282,   288,   292,
     293,   294,   298,   301,   304,   308,   313,   318,   323,   328,
     333,   335,   337,   339,   341,   343,   345,   349,   354,   356,
     358,   360,   362,   364,   366,   368,   370,   372,   374,   376,
     378,   380,   383,   384,   388,   389,   393,   397,   401,   405,
     409,   413,   417,   421,   425,   429,   433,   437,   441,   444,
     447,   451,   453,   455,   457
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    64,    73,    82,    63,    72,    50,    -1,
      63,    66,    -1,    63,    67,    -1,    -1,    17,     3,    44,
     110,    53,    65,    -1,    -1,     3,    44,   110,    53,    65,
      -1,    -1,    24,     3,    54,    68,    55,    53,    21,    53,
      -1,    24,     3,    54,    68,    55,    53,    70,    53,    -1,
      32,     3,    54,    68,    55,    52,    75,    53,    21,    53,
      -1,    32,     3,    54,    68,    55,    52,    75,    53,    70,
      53,    -1,    -1,    29,    80,    52,    75,    69,    -1,    80,
      52,    75,    69,    -1,    53,    29,    80,    52,    75,    69,
      -1,    53,    80,    52,    75,    69,    -1,    -1,    71,    64,
      73,    82,    72,    -1,    -1,     7,    84,    19,    -1,    15,
      74,    -1,    -1,    74,     3,    44,    75,    53,    -1,    -1,
      76,    -1,    79,    -1,    77,    -1,     3,    -1,    12,    78,
      19,    -1,    80,    52,    75,    53,    78,    -1,    -1,     6,
      56,   110,    52,   110,    57,    11,    75,    -1,     3,    81,
      -1,    51,     3,    81,    -1,    -1,    29,    80,    52,    75,
      53,    83,    -1,    -1,    80,    52,    75,    53,    83,    -1,
      -1,    86,    85,    -1,    53,    86,    85,    -1,    -1,    87,
      -1,    88,    -1,    91,    -1,    92,    -1,    93,    -1,    95,
      -1,    96,    -1,    97,    -1,    99,    -1,   101,    -1,   103,
      -1,   106,    36,   110,    -1,    10,   104,    34,    84,    89,
      90,    19,    -1,     9,   104,    34,    84,    89,    -1,    -1,
       8,    84,    -1,    -1,    30,   104,    18,    84,    19,    -1,
      13,    84,    28,   104,    -1,    20,     3,    36,   104,    94,
     104,    18,    84,    19,    -1,    31,    -1,    14,    -1,    26,
      -1,    25,   104,    -1,    25,    -1,    33,    54,   106,    98,
      55,    -1,    51,   106,    98,    -1,    -1,    35,    54,   104,
     100,    55,    -1,    51,   104,   100,    -1,    -1,     3,    54,
      55,    -1,     3,    54,   104,   102,    55,    -1,    51,   104,
     102,    -1,    -1,    -1,   105,   107,   105,    -1,    43,   104,
      -1,    38,   104,    -1,    54,   104,    55,    -1,     3,    54,
     108,    55,    -1,    16,    54,   104,    55,    -1,    22,    54,
     104,    55,    -1,    23,    54,   104,    55,    -1,    27,    54,
     104,    55,    -1,   105,    -1,   106,    -1,     5,    -1,     4,
      -1,    59,    -1,     3,    -1,   106,    50,   106,    -1,   106,
      56,   104,    57,    -1,    42,    -1,    41,    -1,    44,    -1,
      45,    -1,    47,    -1,    49,    -1,    46,    -1,    48,    -1,
      37,    -1,    38,    -1,    39,    -1,    40,    -1,    58,    -1,
     104,   109,    -1,    -1,    51,   104,   109,    -1,    -1,   110,
      42,   110,    -1,   110,    41,   110,    -1,   110,    44,   110,
      -1,   110,    45,   110,    -1,   110,    47,   110,    -1,   110,
      49,   110,    -1,   110,    46,   110,    -1,   110,    48,   110,
      -1,   110,    37,   110,    -1,   110,    38,   110,    -1,   110,
      39,   110,    -1,   110,    40,   110,    -1,   110,    58,   110,
      -1,    43,   110,    -1,    38,   110,    -1,    54,   110,    55,
      -1,     5,    -1,     4,    -1,    59,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   139,   140,   141,   146,   147,   149,   150,
     154,   157,   161,   164,   169,   170,   171,   175,   176,   177,
     180,   183,   188,   193,   194,   197,   198,   201,   202,   203,
     206,   209,   212,   214,   217,   221,   224,   225,   229,   231,
     234,   236,   241,   244,   245,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   261,   265,   269,   270,
     272,   273,   277,   280,   283,   285,   286,   289,   292,   293,
     296,   299,   300,   304,   307,   308,   312,   313,   316,   317,
     320,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   339,   340,   341,   342,   345,   346,   347,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   365,   366,   369,   370,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID_SYMBOL", "CHARACTER_SYMBOL",
  "INTEGER_SYMBOL", "ARRAY_SYMBOL", "BEGIN_SYMBOL", "ELSE_SYMBOL",
  "ELSEIF_SYMBOL", "IF_SYMBOL", "OF_SYMBOL", "RECORD_SYMBOL",
  "REPEAT_SYMBOL", "TO_SYMBOL", "TYPE_SYMBOL", "CHR_SYMBOL",
  "CONST_SYMBOL", "DO_SYMBOL", "END_SYMBOL", "FOR_SYMBOL",
  "FORWARD_SYMBOL", "ORD_SYMBOL", "PRED_SYMBOL", "PROCEDURE_SYMBOL",
  "RETURN_SYMBOL", "STOP_SYMBOL", "SUCC_SYMBOL", "UNTIL_SYMBOL",
  "VAR_SYMBOL", "WHILE_SYMBOL", "DOWNTO_SYMBOL", "FUNCTION_SYMBOL",
  "READ_SYMBOL", "THEN_SYMBOL", "WRITE_SYMBOL", "ASSIGN_SYMBOL",
  "ADD_SYMBOL", "SUB_SYMBOL", "MULT_SYMBOL", "DIV_SYMBOL", "AND_SYMBOL",
  "OR_SYMBOL", "NOT_SYMBOL", "EQUAL_SYMBOL", "NOT_EQUAL_SYMBOL",
  "LESS_SYMBOL", "LESS_EQUAL_SYMBOL", "GREAT_SYMBOL", "GREAT_EQUAL_SYMBOL",
  "DOT_SYMBOL", "COMMA_SYMBOL", "COLON_SYMBOL", "SEMI_COLON_SYMBOL",
  "LEFT_BRACE_SYMBOL", "RIGHT_BRACE_SYMBOL", "LEFT_SQUARE_SYMBOL",
  "RIGHT_SQUARE_SYMBOL", "PERCENT_SYMBOL", "STRING_SYMBOL", "UMINUS",
  "$accept", "Program", "subProgram", "ConstantDecl", "subConstantDecl",
  "ProcedureDecl", "FunctionDecl", "FormalParameters",
  "subFormalParameters", "Body", "ScopeIt", "Block", "TypeDecl",
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
      66,    66,    67,    67,    68,    68,    68,    69,    69,    69,
      70,    71,    72,    73,    73,    74,    74,    75,    75,    75,
      76,    77,    78,    78,    79,    80,    81,    81,    82,    82,
      83,    83,    84,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    87,    88,    89,    89,
      90,    90,    91,    92,    93,    94,    94,    95,    96,    96,
      97,    98,    98,    99,   100,   100,   101,   101,   102,   102,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   105,   105,   106,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     2,     2,     0,     6,     0,     5,     0,
       8,     8,    10,    10,     0,     5,     4,     6,     5,     0,
       5,     0,     3,     2,     0,     5,     0,     1,     1,     1,
       1,     3,     5,     0,     8,     2,     3,     0,     6,     0,
       5,     0,     2,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     7,     5,     0,
       2,     0,     5,     4,     9,     1,     1,     1,     2,     1,
       5,     3,     0,     5,     3,     0,     3,     5,     3,     0,
       0,     3,     2,     2,     3,     4,     4,     4,     4,     4,
       1,     1,     1,     1,     1,     1,     3,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     0,     3,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,    24,     0,     1,    26,    39,     0,    23,
       0,     5,   134,   132,   131,     0,     0,     0,   133,     0,
       0,    37,     0,     0,   129,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
       0,     0,     0,    35,     0,    80,     0,     0,     3,     4,
       0,   130,   123,   124,   125,   126,   116,   115,   117,   118,
     121,   119,   122,   120,     0,     6,   127,    30,     0,    33,
       0,    27,    29,    28,    37,     0,    95,     0,    80,     0,
      69,    67,     0,     0,     0,     0,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     0,     0,
       0,     2,     0,     0,     0,     0,    25,    36,    41,     0,
      95,    93,    92,     0,     0,     0,     0,     0,     0,     0,
      94,     0,    90,    91,     0,     0,    68,     0,     0,     0,
      22,    80,    42,     0,     0,     0,    14,    14,     0,     0,
      31,     0,     0,    38,    76,    79,   112,     0,     0,     0,
       0,    83,    82,     0,    80,   106,   107,   108,   109,    99,
      98,   100,   101,   104,   102,   105,   103,   110,     0,     0,
       0,    80,    95,    72,    75,    44,    56,    96,     0,     0,
       0,     0,     0,     9,     0,     0,     0,     0,     0,   114,
       0,     0,     0,     0,     0,    84,    59,    81,    63,     0,
       0,     0,     0,     0,     0,    43,    97,     0,     0,     0,
       0,     8,     0,    33,     0,    79,    77,     0,   111,    85,
      86,    87,    88,    89,     0,    61,    66,    65,     0,    62,
      72,    70,    75,    73,     0,    21,    19,     0,     0,    32,
      41,    78,   114,     0,    80,     0,     0,    71,    74,    19,
       0,     0,     7,     0,    16,     0,     0,    40,   113,    80,
      60,    57,    80,    15,    10,    11,    24,     0,     0,    21,
      34,    59,     0,    39,     0,     0,     0,     0,    58,    64,
       0,     0,    19,    12,    13,    20,    19,    18,    17
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    23,     3,    65,    48,    49,   180,   254,   251,
     252,    50,     7,     9,    70,    71,    72,   104,    73,   105,
      43,    11,   143,    85,   132,    86,    87,    88,   225,   245,
      89,    90,    91,   228,    92,    93,    94,   202,    95,   204,
      96,   188,    97,   121,   122,   123,   168,   190,   218,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -249
static const yytype_int16 yypact[] =
{
     -14,    10,    23,    11,   -19,  -249,  -249,     4,    16,    63,
      65,  -249,  -249,  -249,  -249,    16,    16,    16,  -249,   221,
      30,    33,    28,    29,  -249,   376,   243,    16,    16,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    78,
      16,    76,    82,  -249,    76,   152,    83,    86,  -249,  -249,
      41,  -249,   -28,   -28,  -249,  -249,   376,   361,    18,   -23,
     391,   406,   421,   436,    48,  -249,  -249,  -249,    38,    65,
      42,  -249,  -249,  -249,    33,    44,    47,   197,   152,    99,
     197,  -249,   197,    49,    53,    89,    56,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,    15,    57,
      58,  -249,    16,    16,    91,    66,  -249,  -249,    65,   116,
      69,  -249,  -249,    70,    71,    74,    75,   197,   197,   197,
    -249,    97,   331,   -32,   112,    81,  -249,   123,   139,   197,
    -249,   152,  -249,    16,   139,   197,     2,     2,   265,   287,
    -249,    76,    94,  -249,  -249,    96,   197,   197,   197,   197,
     197,  -249,  -249,    93,   152,  -249,  -249,  -249,  -249,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,  -249,     5,   197,
     197,   152,  -249,    22,    98,    56,   346,   -32,    95,    65,
     103,   101,   106,    78,    16,   110,    76,   197,   109,   100,
     111,   113,   121,   124,   125,  -249,   141,  -249,  -249,    46,
     162,   139,   128,   197,   129,  -249,  -249,   134,   136,    76,
     142,  -249,   309,    65,   140,    96,  -249,   197,  -249,  -249,
    -249,  -249,  -249,  -249,   197,   189,  -249,  -249,   197,  -249,
      22,  -249,    98,  -249,    76,   177,   146,    76,   194,  -249,
      65,  -249,   100,   172,   152,   188,   190,  -249,  -249,   146,
     156,   157,   -14,     3,  -249,   159,    76,  -249,  -249,   152,
    -249,  -249,   152,  -249,  -249,  -249,    11,    65,   164,   196,
    -249,   141,   203,     4,   171,    76,   173,   174,  -249,  -249,
     218,    76,   146,  -249,  -249,  -249,   146,  -249,  -249
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -249,  -249,  -249,   -24,    51,  -249,  -249,    92,  -248,   -38,
    -249,   -48,   -30,  -249,   -42,  -249,  -249,    24,  -249,   -10,
     167,   -35,     6,   -71,    67,   114,  -249,  -249,   -27,  -249,
    -249,  -249,  -249,  -249,  -249,  -249,  -249,    17,  -249,    20,
    -249,    34,  -249,   -13,    80,   -41,  -249,  -249,     8,    12
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      22,   263,    75,     1,    98,    21,    21,   124,   172,   111,
     112,    29,    30,     4,    27,    28,    29,    30,   134,    12,
      13,    14,    -1,     5,   135,     8,     6,    24,    25,    26,
      40,   179,   267,    10,   287,    40,    45,    98,   288,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   133,    66,    46,    15,    27,    28,    29,    30,    16,
     226,    47,    -1,    34,   120,   134,    20,   126,    21,   127,
      17,   135,   134,   201,    41,    18,    40,   227,   135,    67,
      44,    64,    68,   196,    42,    74,    99,   173,    69,   100,
      98,   101,   102,   177,   103,   106,   145,   108,   142,   185,
     200,   109,   125,   128,   151,   152,   153,   129,   130,   131,
     140,   136,   137,    98,   138,   139,   174,   170,   141,   110,
     111,   112,   178,   146,   147,   148,   181,   181,   149,   150,
      98,   154,   113,   189,   191,   192,   193,   194,   114,   115,
     169,   171,   172,   116,   214,   176,   186,   187,   195,   203,
     224,   217,   206,   209,   117,    76,   198,   199,   208,   118,
     230,   210,    77,   213,   216,    78,   219,   236,   220,   207,
     119,   144,    79,   260,   215,   120,   221,    80,    81,   222,
     223,   229,    82,   231,   233,    83,   234,    84,   271,   235,
     232,   272,   249,   240,   237,   255,   212,   244,   250,   253,
     110,   111,   112,    98,   242,   256,   259,   261,   262,   264,
     265,   243,   269,   113,   270,   246,   275,   276,    98,   114,
     115,    98,   279,   281,   116,    45,   283,   284,   266,   182,
     142,   277,   285,   282,   211,   117,   273,   239,   280,   286,
     118,   107,   205,   268,   278,   175,   257,   247,   197,   241,
     258,   119,   248,     0,     0,     0,   120,   274,    27,    28,
      29,    30,    31,    32,     0,    33,    34,    35,    36,    37,
      38,     0,     0,     0,    39,     0,     0,     0,     0,    40,
      27,    28,    29,    30,    31,    32,     0,    33,    34,    35,
      36,    37,    38,     0,     0,     0,     0,     0,    51,     0,
       0,    40,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,    37,    38,     0,     0,     0,   183,     0,
       0,     0,     0,    40,    27,    28,    29,    30,    31,    32,
       0,    33,    34,    35,    36,    37,    38,     0,     0,   184,
       0,     0,     0,     0,     0,    40,    27,    28,    29,    30,
      31,    32,     0,    33,    34,    35,    36,    37,    38,     0,
       0,     0,     0,     0,     0,     0,   238,    40,   155,   156,
     157,   158,   159,   160,     0,   161,   162,   163,   164,   165,
     166,     0,     0,    27,    28,    29,    30,    31,    32,   167,
      33,    34,    35,    36,    37,    38,     0,     0,    27,    28,
      29,    30,    31,     0,    40,    33,    34,    35,    36,    37,
      38,     0,     0,    27,    28,    29,    30,     0,     0,    40,
      33,    34,    35,    36,    37,    38,     0,     0,    27,    28,
      29,    30,     0,     0,    40,    33,    34,    -1,    36,    37,
      38,     0,     0,    27,    28,    29,    30,     0,     0,    40,
      33,    34,     0,    -1,    37,    38,     0,     0,    27,    28,
      29,    30,     0,     0,    40,    33,    34,     0,     0,    -1,
      38,     0,     0,    27,    28,    29,    30,     0,     0,    40,
      33,    34,     0,     0,     0,    -1,     0,     0,     0,     0,
       0,     0,     0,     0,    40
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-249))

#define yytable_value_is_error(yytable_value) \
  ((yytable_value) == (-1))

static const yytype_int16 yycheck[] =
{
      10,   249,    44,    17,    45,     3,     3,    78,     3,     4,
       5,    39,    40,     3,    37,    38,    39,    40,    50,     3,
       4,     5,    45,     0,    56,    44,    15,    15,    16,    17,
      58,    29,    29,    29,   282,    58,     7,    78,   286,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    36,    40,    24,    38,    37,    38,    39,    40,    43,
      14,    32,    44,    45,    59,    50,     3,    80,     3,    82,
      54,    56,    50,    51,    44,    59,    58,    31,    56,     3,
      52,     3,     6,   154,    51,     3,     3,   128,    12,     3,
     131,    50,    44,   134,    56,    53,   109,    53,   108,   141,
     171,    54,     3,    54,   117,   118,   119,    54,    19,    53,
      19,    54,    54,   154,   102,   103,   129,    36,    52,     3,
       4,     5,   135,    54,    54,    54,   136,   137,    54,    54,
     171,    34,    16,   146,   147,   148,   149,   150,    22,    23,
      28,    18,     3,    27,   186,   133,    52,    51,    55,    51,
       9,    51,    57,    52,    38,     3,   169,   170,    55,    43,
     201,    55,    10,    53,    55,    13,    55,   209,    55,   179,
      54,    55,    20,   244,   187,    59,    55,    25,    26,    55,
      55,    19,    30,    55,    55,    33,    52,    35,   259,    53,
     203,   262,   234,    53,    52,   237,   184,     8,    21,    53,
       3,     4,     5,   244,   217,    11,    34,    19,    18,    53,
      53,   224,    53,    16,   256,   228,    52,    21,   259,    22,
      23,   262,    19,    52,    27,     7,    53,    53,   252,   137,
     240,   269,   280,   275,   183,    38,   266,   213,   273,   281,
      43,    74,   175,   253,   271,   131,   240,   230,   168,   215,
     242,    54,   232,    -1,    -1,    -1,    59,   267,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    58,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    46,    47,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    58,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    58,    37,    38,    39,    40,
      41,    42,    -1,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,    37,    38,    39,    40,    41,    42,    58,
      44,    45,    46,    47,    48,    49,    -1,    -1,    37,    38,
      39,    40,    41,    -1,    58,    44,    45,    46,    47,    48,
      49,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    58,
      44,    45,    46,    47,    48,    49,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    58,    44,    45,    46,    47,    48,
      49,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    58,
      44,    45,    -1,    47,    48,    49,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    58,    44,    45,    -1,    -1,    48,
      49,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    58,
      44,    45,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    62,    64,     3,     0,    15,    73,    44,    74,
      29,    82,     3,     4,     5,    38,    43,    54,    59,   110,
       3,     3,    80,    63,   110,   110,   110,    37,    38,    39,
      40,    41,    42,    44,    45,    46,    47,    48,    49,    53,
      58,    44,    51,    81,    52,     7,    24,    32,    66,    67,
      72,    55,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,     3,    65,   110,     3,     6,    12,
      75,    76,    77,    79,     3,    75,     3,    10,    13,    20,
      25,    26,    30,    33,    35,    84,    86,    87,    88,    91,
      92,    93,    95,    96,    97,    99,   101,   103,   106,     3,
       3,    50,    44,    56,    78,    80,    53,    81,    53,    54,
       3,     4,     5,    16,    22,    23,    27,    38,    43,    54,
      59,   104,   105,   106,    84,     3,   104,   104,    54,    54,
      19,    53,    85,    36,    50,    56,    54,    54,   110,   110,
      19,    52,    80,    83,    55,   104,    54,    54,    54,    54,
      54,   104,   104,   104,    34,    37,    38,    39,    40,    41,
      42,    44,    45,    46,    47,    48,    49,    58,   107,    28,
      36,    18,     3,   106,   104,    86,   110,   106,   104,    29,
      68,    80,    68,    53,    52,    75,    52,    51,   102,   104,
     108,   104,   104,   104,   104,    55,    84,   105,   104,   104,
      84,    51,    98,    51,   100,    85,    57,    80,    55,    52,
      55,    65,   110,    53,    75,   104,    55,    51,   109,    55,
      55,    55,    55,    55,     9,    89,    14,    31,    94,    19,
     106,    55,   104,    55,    52,    53,    75,    52,    57,    78,
      53,   102,   104,   104,     8,    90,   104,    98,   100,    75,
      21,    70,    71,    53,    69,    75,    11,    83,   109,    34,
      84,    19,    18,    69,    53,    53,    64,    29,    80,    53,
      75,    84,    84,    73,    80,    52,    21,    70,    89,    19,
      82,    52,    75,    53,    53,    72,    75,    69,    69
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
        case 6:

/* Line 1806 of yacc.c  */
#line 146 "cpsl.y"
    {SymbolTable::addConstant((yyvsp[(2) - (6)].name_ptr),(yyvsp[(4) - (6)].const_type));}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 147 "cpsl.y"
    {}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 149 "cpsl.y"
    {SymbolTable::addConstant((yyvsp[(1) - (5)].name_ptr),(yyvsp[(3) - (5)].const_type));}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 150 "cpsl.y"
    {}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 155 "cpsl.y"
    {SymbolTable::addFunction((yyvsp[(2) - (8)].name_ptr),(yyvsp[(4) - (8)].form_params), "NONE", true);}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 158 "cpsl.y"
    {SymbolTable::addFunction((yyvsp[(2) - (8)].name_ptr),(yyvsp[(4) - (8)].form_params), "NONE", false); SymbolTable::popScope();}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 162 "cpsl.y"
    {SymbolTable::addFunction((yyvsp[(2) - (10)].name_ptr),(yyvsp[(4) - (10)].form_params), (yyvsp[(7) - (10)].name_ptr), true);}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 165 "cpsl.y"
    {SymbolTable::addFunction((yyvsp[(2) - (10)].name_ptr),(yyvsp[(4) - (10)].form_params), (yyvsp[(7) - (10)].name_ptr), false);	SymbolTable::popScope();}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 169 "cpsl.y"
    {(yyval.form_params) = new std::vector<std::shared_ptr<Variable>>();}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 170 "cpsl.y"
    {(yyval.form_params) = SymbolTable::makeVarList((yyvsp[(2) - (5)].id_list),(yyvsp[(5) - (5)].form_params),(yyvsp[(4) - (5)].name_ptr));}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 171 "cpsl.y"
    {(yyval.form_params) = SymbolTable::makeVarList((yyvsp[(1) - (4)].id_list),(yyvsp[(4) - (4)].form_params),(yyvsp[(3) - (4)].name_ptr));}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 175 "cpsl.y"
    {(yyval.form_params) = SymbolTable::makeVarList((yyvsp[(3) - (6)].id_list),(yyvsp[(6) - (6)].form_params),(yyvsp[(5) - (6)].name_ptr));}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 176 "cpsl.y"
    {(yyval.form_params) = SymbolTable::makeVarList((yyvsp[(2) - (5)].id_list),(yyvsp[(5) - (5)].form_params),(yyvsp[(4) - (5)].name_ptr));}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 177 "cpsl.y"
    {(yyval.form_params) = new std::vector<std::shared_ptr<Variable>>();}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 183 "cpsl.y"
    {SymbolTable::pushScope("tempScopeName");}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 188 "cpsl.y"
    {}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 197 "cpsl.y"
    { SymbolTable::makeType((yyvsp[(2) - (5)].name_ptr),(yyvsp[(4) - (5)].name_ptr)); debug("making"); debug((yyvsp[(2) - (5)].name_ptr));}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 198 "cpsl.y"
    {}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 201 "cpsl.y"
    {(yyval.name_ptr) = (yyvsp[(1) - (1)].name_ptr); debug("simpleType"); }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 202 "cpsl.y"
    {(yyval.name_ptr) = (yyvsp[(1) - (1)].name_ptr); 	debug("ArrayType");}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 203 "cpsl.y"
    {(yyval.name_ptr) = (yyvsp[(1) - (1)].name_ptr); debug("record Type;");}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 206 "cpsl.y"
    {(yyval.name_ptr) =(yyvsp[(1) - (1)].name_ptr);}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 209 "cpsl.y"
    {(yyval.name_ptr) = SymbolTable::createRecord(*(yyvsp[(2) - (3)].record_type));}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 213 "cpsl.y"
    { (yyvsp[(5) - (5)].record_type)->push_back(std::make_pair((yyvsp[(1) - (5)].id_list),(yyvsp[(3) - (5)].name_ptr))); (yyval.record_type)=(yyvsp[(5) - (5)].record_type); }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 214 "cpsl.y"
    {(yyval.record_type) = new std::vector<std::pair<std::vector<std::string>*,std::string>>();}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 218 "cpsl.y"
    {(yyval.name_ptr) = SymbolTable::makeArray((yyvsp[(3) - (8)].const_type),(yyvsp[(5) - (8)].const_type),(yyvsp[(8) - (8)].name_ptr));}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 221 "cpsl.y"
    {(yyvsp[(2) - (2)].id_list)->push_back((yyvsp[(1) - (2)].name_ptr)); (yyval.id_list) = (yyvsp[(2) - (2)].id_list);}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 224 "cpsl.y"
    {(yyvsp[(3) - (3)].id_list)->push_back((yyvsp[(2) - (3)].name_ptr)); (yyval.id_list) = (yyvsp[(3) - (3)].id_list);}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 225 "cpsl.y"
    {(yyval.id_list)= new std::vector<std::string>();}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 230 "cpsl.y"
    { SymbolTable::addVarDecl((yyvsp[(4) - (6)].name_ptr),(yyvsp[(2) - (6)].id_list));  }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 231 "cpsl.y"
    {}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 235 "cpsl.y"
    { SymbolTable::addVarDecl((yyvsp[(3) - (5)].name_ptr),(yyvsp[(1) - (5)].id_list));  }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 236 "cpsl.y"
    {}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 374 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 375 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 376 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 377 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 378 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 379 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 380 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 381 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 382 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 383 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 384 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 385 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 386 "cpsl.y"
    {(yyval.const_type) = SymbolTable::evaluateConstantExpression((yyvsp[(1) - (3)].const_type),(yyvsp[(3) - (3)].const_type),(yyvsp[(2) - (3)].name_ptr));}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 387 "cpsl.y"
    {(yyval.const_type) = (yyvsp[(2) - (2)].const_type)->makeBoolNot();}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 388 "cpsl.y"
    {(yyval.const_type) = (yyvsp[(2) - (2)].const_type)->makeNegative();}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 389 "cpsl.y"
    {(yyval.const_type) = (yyvsp[(2) - (3)].const_type);}
    break;

  case 131:

/* Line 1806 of yacc.c  */
#line 390 "cpsl.y"
    {(yyval.const_type) = new Constant((yyvsp[(1) - (1)].int_val));}
    break;

  case 132:

/* Line 1806 of yacc.c  */
#line 391 "cpsl.y"
    {(yyval.const_type) = new Constant((yyvsp[(1) - (1)].name_ptr));}
    break;

  case 133:

/* Line 1806 of yacc.c  */
#line 392 "cpsl.y"
    {(yyval.const_type) = new Constant((yyvsp[(1) - (1)].name_ptr), STR);}
    break;

  case 134:

/* Line 1806 of yacc.c  */
#line 393 "cpsl.y"
    {(yyval.const_type) = new Constant((yyvsp[(1) - (1)].name_ptr), ID);}
    break;



/* Line 1806 of yacc.c  */
#line 2129 "cpsl.tab.c"
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
#line 395 "cpsl.y"


int main(int argc, char ** argv)
{
	argc--, argv++;
	if(argc > 0)
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
	argc--,argv++;
	Logger::SetLevel(ERROR);
	if(argc>0)
	{
		if(argv[0][1] == 'v')
		{
			std::cout<<"now verbose\n";
			SymbolTable::setVerbose(true);
		}
	}
	yyparse();

	if(SymbolTable::isVerbose())
	{
//		std::cout<<"printing table:\n";
		SymbolTable::print();
	}
	std::cout<<"finished Parsing\n";
	return 0;
};
