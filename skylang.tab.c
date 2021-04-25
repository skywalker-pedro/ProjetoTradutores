/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "skylang.y"


#include <stdio.h>
#include <stdlib.h>
#include "skylang.h"
#include "symbol_table.h"
#include "skylangTree.h"

extern int yylex();
extern void yyerror(const char* msg);
extern int yylex_destroy();
extern FILE *yyin;
extern Hash_table * hashed_symbol_table;
int symbol_ID = 0;
treeNode* tree = NULL;

/* Print TS Function*/
void printTS(){
    while(hashed_symbol_table!=NULL){
        printf("\n Id simbolo: %d | Nome simbolo: %s | Tipo simbolo: %s %s",hashed_symbol_table->id,hashed_symbol_table->name,hashed_symbol_table->type,hashed_symbol_table->varType);
        hashed_symbol_table = hashed_symbol_table -> hh.next;
    }
}


#line 97 "skylang.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "skylang.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPE = 3,                       /* TYPE  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_WRITE = 9,                      /* WRITE  */
  YYSYMBOL_WRITELN = 10,                   /* WRITELN  */
  YYSYMBOL_READ = 11,                      /* READ  */
  YYSYMBOL_EXISTS = 12,                    /* EXISTS  */
  YYSYMBOL_ADD = 13,                       /* ADD  */
  YYSYMBOL_REMOVE = 14,                    /* REMOVE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_FORALL = 16,                    /* FORALL  */
  YYSYMBOL_IN = 17,                        /* IN  */
  YYSYMBOL_IS_IN = 18,                     /* IS_IN  */
  YYSYMBOL_IS_SET = 19,                    /* IS_SET  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_CLE = 21,                       /* CLE  */
  YYSYMBOL_CLT = 22,                       /* CLT  */
  YYSYMBOL_CNE = 23,                       /* CNE  */
  YYSYMBOL_CGT = 24,                       /* CGT  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_CEQ = 26,                       /* CEQ  */
  YYSYMBOL_CGE = 27,                       /* CGE  */
  YYSYMBOL_INTEGER = 28,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 29,                     /* FLOAT  */
  YYSYMBOL_CHAR = 30,                      /* CHAR  */
  YYSYMBOL_STRING = 31,                    /* STRING  */
  YYSYMBOL_NEGATION = 32,                  /* NEGATION  */
  YYSYMBOL_EQUALS = 33,                    /* EQUALS  */
  YYSYMBOL_APOST = 34,                     /* APOST  */
  YYSYMBOL_CHAVES_INI = 35,                /* CHAVES_INI  */
  YYSYMBOL_CHAVES_FIM = 36,                /* CHAVES_FIM  */
  YYSYMBOL_PARENTESES_INI = 37,            /* PARENTESES_INI  */
  YYSYMBOL_PARENTESES_FIM = 38,            /* PARENTESES_FIM  */
  YYSYMBOL_EMPTY = 39,                     /* EMPTY  */
  YYSYMBOL_SEMICOLON = 40,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 41,                     /* COLON  */
  YYSYMBOL_PLUS = 42,                      /* PLUS  */
  YYSYMBOL_MINUS = 43,                     /* MINUS  */
  YYSYMBOL_MULT = 44,                      /* MULT  */
  YYSYMBOL_DIV = 45,                       /* DIV  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_programa = 47,                  /* programa  */
  YYSYMBOL_declarationList = 48,           /* declarationList  */
  YYSYMBOL_declaration = 49,               /* declaration  */
  YYSYMBOL_variable_declaration = 50,      /* variable_declaration  */
  YYSYMBOL_func_declaration = 51,          /* func_declaration  */
  YYSYMBOL_params = 52,                    /* params  */
  YYSYMBOL_params_list = 53,               /* params_list  */
  YYSYMBOL_param = 54,                     /* param  */
  YYSYMBOL_codeBlock = 55,                 /* codeBlock  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_forStatement = 57,              /* forStatement  */
  YYSYMBOL_callFuncStatement = 58,         /* callFuncStatement  */
  YYSYMBOL_call_params = 59,               /* call_params  */
  YYSYMBOL_call_params_list = 60,          /* call_params_list  */
  YYSYMBOL_call_param = 61,                /* call_param  */
  YYSYMBOL_inputStatement = 62,            /* inputStatement  */
  YYSYMBOL_outPutStatement = 63,           /* outPutStatement  */
  YYSYMBOL_forAllStatement = 64,           /* forAllStatement  */
  YYSYMBOL_ifStatement = 65,               /* ifStatement  */
  YYSYMBOL_variable_assignment = 66,       /* variable_assignment  */
  YYSYMBOL_exp = 67,                       /* exp  */
  YYSYMBOL_setExp = 68,                    /* setExp  */
  YYSYMBOL_terms_set = 69,                 /* terms_set  */
  YYSYMBOL_aritSetExp = 70,                /* aritSetExp  */
  YYSYMBOL_aritExp = 71,                   /* aritExp  */
  YYSYMBOL_relExp = 72,                    /* relExp  */
  YYSYMBOL_rel = 73,                       /* rel  */
  YYSYMBOL_terminal = 74                   /* terminal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    62,    67,    73,    77,    84,    93,   102,
     107,   111,   114,   118,   124,   129,   137,   141,   146,   150,
     154,   158,   162,   166,   171,   176,   185,   197,   205,   211,
     216,   220,   225,   233,   241,   245,   253,   261,   266,   275,
     339,   343,   347,   351,   358,   363,   368,   376,   383,   387,
     391,   395,   405,   411,   417,   422,   428,   435,   444,   447,
     450,   453,   456,   459,   462,   469,   473,   477,   482
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TYPE", "ID", "RETURN",
  "IF", "ELSE", "WHILE", "WRITE", "WRITELN", "READ", "EXISTS", "ADD",
  "REMOVE", "FOR", "FORALL", "IN", "IS_IN", "IS_SET", "OR", "CLE", "CLT",
  "CNE", "CGT", "AND", "CEQ", "CGE", "INTEGER", "FLOAT", "CHAR", "STRING",
  "NEGATION", "EQUALS", "APOST", "CHAVES_INI", "CHAVES_FIM",
  "PARENTESES_INI", "PARENTESES_FIM", "EMPTY", "SEMICOLON", "COLON",
  "PLUS", "MINUS", "MULT", "DIV", "$accept", "programa", "declarationList",
  "declaration", "variable_declaration", "func_declaration", "params",
  "params_list", "param", "codeBlock", "statement", "forStatement",
  "callFuncStatement", "call_params", "call_params_list", "call_param",
  "inputStatement", "outPutStatement", "forAllStatement", "ifStatement",
  "variable_assignment", "exp", "setExp", "terms_set", "aritSetExp",
  "aritExp", "relExp", "rel", "terminal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
#endif

#define YYPACT_NINF (-124)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,     7,     4,     9,    14,    15,    20,    -9,  -124,    80,
      -2,   103,    12,    -8,    -6,    66,    88,     3,    -2,   241,
       1,   270,    49,   874,    33,    17,    26,    28,    34,    35,
      39,    48,    55,    59,   899,   924,   125,    38,   299,   328,
     357,    46,    57,    68,   386,   415,    70,    74,    91,    96,
     116,   949,   123,    33,     6,   974,   136,    38,   112,   114,
     152,    45,    45,    45,    33,   173,    89,   444,   473,   502,
     531,   560,    65,    87,   105,   834,   839,   852,   865,    33,
      33,    33,    33,    33,    33,   138,   153,   161,    94,    99,
     589,   163,   164,   165,   166,   188,   189,   190,   178,   197,
     203,   213,   214,   192,   216,   999,   194,   195,   196,   202,
     218,   219,   224,     6,   208,   225,   226,   227,   234,    83,
      83,    83,    33,   268,   191,   241,    45,   249,   250,   251,
     252,   253,   618,   273,   254,   255,   256,    38,   258,   212,
      83,   259,   241,   265,   263,   281,   647,   241,   279,   241,
     676,   705,   301,   734,   763,   792,  1024,   282,   283,   284,
    1049,  1074,    38,   285,   286,   287,  1099,   821,   133,   134,
     146,    38,   288,   291,   292,   310,   307,    45,    45,    45,
     308,    38,    38,    38,    38,    38,    38,   309,   311,   332,
     333,   334,  1124,   314,   315,   316,   317,   320,   321,   147,
      45,    83,    83,    83,   358,   336,   338,   339,    83,   340,
     341,   342,   343,   344,   345
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -124,  -124,  -124,   381,   141,  -124,  -124,   369,  -124,  -123,
    -124,  -124,  -124,  -124,   275,  -124,  -124,  -124,  -124,  -124,
    -124,   -24,   -16,    60,  -113,    11,    27,   237,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    38,     6,    13,    14,    15,    21,
      39,    40,    41,    86,    87,    88,    42,    43,    44,    45,
      46,    47,    48,    99,   100,    49,    50,    84,    51
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    12,   132,     1,     8,   166,   176,   176,   176,    -2,
     168,     7,     1,    66,    -4,    -5,    16,    -4,    -5,   146,
      -6,   163,    89,    -6,   151,   166,   153,   176,    10,    85,
      17,    11,    -9,    91,   169,   170,   -12,    55,    19,   -10,
     103,   163,   156,   171,   -31,    29,    30,    31,   164,    95,
     157,   158,   159,    52,    57,   106,   107,   108,   109,   110,
     111,    34,    35,    58,   165,    59,   160,   161,   164,   -63,
      37,    60,    61,    96,    97,   162,    62,   -63,   -63,   -63,
      -3,    89,    98,    -3,   165,    63,    67,   172,   176,   176,
     176,   -61,    64,   -63,   -63,   176,    65,    68,   130,   -61,
     -61,   -61,   -63,    -7,   -11,   166,    -7,    18,    69,   -60,
      70,   173,   174,   141,    71,   -61,   -61,   -60,   -60,   -60,
     175,   163,   101,   102,   -61,    -8,   -13,   105,    -8,   -13,
     166,   -40,   -30,   -60,   -60,   113,   -41,   -32,   180,   166,
     -32,     5,   -60,    92,     5,    93,   163,   187,   164,   166,
     166,   166,   166,   166,   166,   163,   -42,   193,   194,   195,
     196,   197,   198,   167,   165,   163,   163,   163,   163,   163,
     163,   -65,   -67,   164,   -65,   -67,    90,   104,   -39,   127,
     128,   129,   164,    94,   -66,   -68,   133,   -66,   -68,   165,
     118,   112,   164,   164,   164,   164,   164,   164,   165,   -28,
     144,   114,   115,   116,   117,   -48,   -50,   -49,   165,   165,
     165,   165,   165,   165,   119,   -37,   -37,   -37,   -37,   143,
     -47,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -29,
     120,   121,   122,   123,   -56,   -53,   -54,   189,   190,   191,
     -37,   -37,   -52,   125,   -15,   -15,   -15,   -15,   -37,   -37,
     -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -55,   -57,
     204,   205,   206,   207,   -27,   -34,   -35,   -33,   212,   -15,
     -15,   126,   131,    22,    23,    24,    25,   -15,   -15,    26,
      27,    28,    29,    30,    31,    32,    33,   134,   135,   136,
     140,   138,   137,   142,   -46,   -44,   -45,   145,    34,    35,
     147,   148,   -16,   -16,   -16,   -16,    36,    37,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   149,   152,   -51,   177,
     178,   179,   188,   -40,   -41,   -42,   -48,   -16,   -16,   -50,
     -49,   -14,   -14,   -14,   -14,   -16,   -16,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -47,   192,   199,   200,   201,
     202,   203,   -56,   -53,   -54,   -52,   -14,   -14,   -55,   -57,
     -25,   -25,   -25,   -25,   -14,   -14,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   209,   208,   210,   211,   -46,   -44,
     -45,   213,   214,   -51,     9,   -25,   -25,    20,   124,   -20,
     -20,   -20,   -20,   -25,   -25,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -20,   -20,     0,     0,   -19,   -19,
     -19,   -19,   -20,   -20,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -19,   -19,     0,     0,   -23,   -23,   -23,
     -23,   -19,   -19,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -23,   -23,     0,     0,   -22,   -22,   -22,   -22,
     -23,   -23,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -22,   -22,     0,     0,   -21,   -21,   -21,   -21,   -22,
     -22,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -21,   -21,     0,     0,   -17,   -17,   -17,   -17,   -21,   -21,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -17,
     -17,     0,     0,   -18,   -18,   -18,   -18,   -17,   -17,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -18,   -18,
       0,     0,   -24,   -24,   -24,   -24,   -18,   -18,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -24,   -24,     0,
       0,    22,    23,    24,    25,   -24,   -24,    26,    27,    28,
      29,    30,    31,    32,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,    35,     0,     0,
      22,    23,    24,    25,   139,    37,    26,    27,    28,    29,
      30,    31,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    35,     0,     0,   -36,
     -36,   -36,   -36,   150,    37,   -36,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -36,   -36,     0,     0,    22,    23,
      24,    25,   -36,   -36,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,     0,     0,    22,    23,    24,
      25,   154,    37,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,    35,     0,     0,   -38,   -38,   -38,   -38,
     155,    37,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -38,   -38,     0,     0,   -26,   -26,   -26,   -26,   -38,
     -38,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -26,   -26,     0,     0,    -7,    -7,    -7,    -7,   -26,   -26,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,   -59,     0,
       0,     0,     0,   -62,     0,     0,   -59,   -59,   -59,    -7,
      -7,   -62,   -62,   -62,     0,     0,   -64,    -7,    -7,     0,
       0,     0,   -59,   -59,   -64,   -64,   -64,   -62,   -62,   -58,
       0,   -59,     0,     0,     0,     0,   -62,   -58,   -58,   -58,
     -64,   -64,     0,     0,     0,     0,     0,     0,     0,   -64,
       0,     0,     0,   -58,   -58,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -58,     0,     0,     0,     0,    53,     0,     0,
       0,    54,     0,     0,   -65,     0,   -65,   -65,   -65,   -65,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,     0,
       0,     0,   -67,     0,     0,     0,     0,     0,     0,   -67,
       0,   -67,   -67,   -67,   -67,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,     0,     0,     0,     0,     0,   -66,     0,     0,
       0,     0,     0,     0,   -66,     0,   -66,   -66,   -66,   -66,
      72,    73,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,   -43,
       0,    80,    81,    82,    83,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,     0,     0,     0,     0,     0,   -65,     0,     0,
       0,     0,     0,     0,   -65,     0,   -65,   -65,   -65,   -65,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,     0,     0,     0,
       0,     0,   -68,     0,     0,     0,     0,     0,     0,   -68,
       0,   -68,   -68,   -68,   -68,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,     0,     0,     0,     0,     0,   -65,     0,     0,
       0,     0,   -65,     0,     0,     0,   -65,   -65,   -65,   -65,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,     0,
       0,     0,   -67,     0,     0,     0,     0,   -67,     0,     0,
       0,   -67,   -67,   -67,   -67,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,     0,     0,     0,     0,     0,   -66,     0,     0,
       0,     0,   -66,     0,     0,     0,   -66,   -66,   -66,   -66,
      72,    73,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,   181,     0,     0,     0,     0,   -43,     0,     0,
       0,   182,   183,   184,   185,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,     0,     0,     0,     0,     0,   -68,     0,     0,
       0,     0,   -68,     0,     0,     0,   -68,   -68,   -68,   -68
};

static const yytype_int16 yycheck[] =
{
      24,     3,   125,     3,     0,    37,   119,   120,   121,     0,
       4,     4,     3,    37,     0,     0,     4,     3,     3,   142,
       0,    37,    54,     3,   147,    57,   149,   140,    37,    53,
      38,    40,    38,    57,    28,    29,    38,     4,    35,    38,
      64,    57,     4,    37,    38,    12,    13,    14,    37,     4,
      12,    13,    14,     4,    37,    79,    80,    81,    82,    83,
      84,    28,    29,    37,    37,    37,    28,    29,    57,     4,
      37,    37,    37,    28,    29,    37,    37,    12,    13,    14,
       0,   113,    37,     3,    57,    37,    40,     4,   201,   202,
     203,     4,    37,    28,    29,   208,    37,    40,   122,    12,
      13,    14,    37,     0,    38,   137,     3,    41,    40,     4,
      40,    28,    29,   137,    40,    28,    29,    12,    13,    14,
      37,   137,    62,    63,    37,     0,    38,    38,     3,    41,
     162,    40,    38,    28,    29,    41,    40,    38,   162,   171,
      41,     0,    37,    31,     3,    31,   162,   171,   137,   181,
     182,   183,   184,   185,   186,   171,    40,   181,   182,   183,
     184,   185,   186,    40,   137,   181,   182,   183,   184,   185,
     186,    38,    38,   162,    41,    41,    40,     4,    40,   119,
     120,   121,   171,    31,    38,    38,   126,    41,    41,   162,
      12,    38,   181,   182,   183,   184,   185,   186,   171,    38,
     140,    38,    38,    38,    38,    17,    17,    17,   181,   182,
     183,   184,   185,   186,    17,     3,     4,     5,     6,     7,
      17,     9,    10,    11,    12,    13,    14,    15,    16,    38,
      17,    17,    40,    17,    40,    40,    40,   177,   178,   179,
      28,    29,    40,    35,     3,     4,     5,     6,    36,    37,
       9,    10,    11,    12,    13,    14,    15,    16,    40,    40,
     200,   201,   202,   203,    40,    40,    40,    40,   208,    28,
      29,    37,     4,     3,     4,     5,     6,    36,    37,     9,
      10,    11,    12,    13,    14,    15,    16,    38,    38,    38,
      17,    38,    40,    35,    40,    40,    40,    38,    28,    29,
      35,    38,     3,     4,     5,     6,    36,    37,     9,    10,
      11,    12,    13,    14,    15,    16,    35,    38,    17,    37,
      37,    37,    12,    38,    38,    38,    38,    28,    29,    38,
      38,     3,     4,     5,     6,    36,    37,     9,    10,    11,
      12,    13,    14,    15,    16,    38,    38,    38,    37,    17,
      17,    17,    38,    38,    38,    38,    28,    29,    38,    38,
       3,     4,     5,     6,    36,    37,     9,    10,    11,    12,
      13,    14,    15,    16,    38,    17,    38,    38,    38,    38,
      38,    38,    38,    38,     3,    28,    29,    18,   113,     3,
       4,     5,     6,    36,    37,     9,    10,    11,    12,    13,
      14,    15,    16,   166,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,     3,     4,
       5,     6,    36,    37,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,     3,     4,     5,
       6,    36,    37,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,     3,     4,     5,     6,
      36,    37,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,     3,     4,     5,     6,    36,
      37,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,     3,     4,     5,     6,    36,    37,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,     3,     4,     5,     6,    36,    37,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,     3,     4,     5,     6,    36,    37,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,     3,     4,     5,     6,    36,    37,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
       3,     4,     5,     6,    36,    37,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,     3,
       4,     5,     6,    36,    37,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,     3,     4,
       5,     6,    36,    37,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,     3,     4,     5,
       6,    36,    37,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,     3,     4,     5,     6,
      36,    37,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,     3,     4,     5,     6,    36,
      37,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,     3,     4,     5,     6,    36,    37,
       9,    10,    11,    12,    13,    14,    15,    16,     4,    -1,
      -1,    -1,    -1,     4,    -1,    -1,    12,    13,    14,    28,
      29,    12,    13,    14,    -1,    -1,     4,    36,    37,    -1,
      -1,    -1,    28,    29,    12,    13,    14,    28,    29,     4,
      -1,    37,    -1,    -1,    -1,    -1,    37,    12,    13,    14,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    28,    29,    21,    22,    23,    24,    25,
      26,    27,    37,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    37,    -1,    -1,    40,    -1,    42,    43,    44,    45,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    42,    43,    44,    45,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    42,    43,    44,    45,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    42,    43,    44,    45,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    42,    43,    44,    45,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    42,    43,    44,    45,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    42,    43,    44,    45,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    43,    44,    45,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    42,    43,    44,    45,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    43,    44,    45,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,    48,    49,    50,    51,     4,     0,    49,
      37,    40,     3,    52,    53,    54,     4,    38,    41,    35,
      53,    55,     3,     4,     5,     6,     9,    10,    11,    12,
      13,    14,    15,    16,    28,    29,    36,    37,    50,    56,
      57,    58,    62,    63,    64,    65,    66,    67,    68,    71,
      72,    74,     4,    33,    37,     4,    67,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    67,    40,    40,    40,
      40,    40,    21,    22,    23,    24,    25,    26,    27,    33,
      42,    43,    44,    45,    73,    67,    59,    60,    61,    74,
      40,    67,    31,    31,    31,     4,    28,    29,    37,    69,
      70,    69,    69,    67,     4,    38,    67,    67,    67,    67,
      67,    67,    38,    41,    38,    38,    38,    38,    12,    17,
      17,    17,    40,    17,    60,    35,    37,    69,    69,    69,
      67,     4,    55,    69,    38,    38,    38,    40,    38,    36,
      17,    67,    35,     7,    69,    38,    55,    35,    38,    35,
      36,    55,    38,    55,    36,    36,     4,    12,    13,    14,
      28,    29,    37,    68,    71,    72,    74,    40,     4,    28,
      29,    37,     4,    28,    29,    37,    70,    37,    37,    37,
      67,    33,    42,    43,    44,    45,    73,    67,    12,    69,
      69,    69,    38,    67,    67,    67,    67,    67,    67,    38,
      37,    17,    17,    17,    69,    69,    69,    69,    17,    38,
      38,    38,    69,    38,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    52,
      53,    53,    53,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    58,    59,    60,
      60,    60,    61,    62,    63,    63,    64,    65,    65,    66,
      67,    67,    67,    67,    68,    68,    68,    69,    70,    70,
      70,    70,    71,    71,    71,    71,    71,    72,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     8,     1,
       3,     1,     0,     2,     2,     0,     1,     2,     2,     1,
       1,     2,     2,     2,     3,     1,    11,     4,     1,     3,
       1,     0,     1,     4,     4,     4,     9,     7,    11,     3,
       1,     1,     1,     1,     6,     6,     6,     1,     1,     1,
       1,     8,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* programa: declarationList  */
#line 54 "skylang.y"
                        {
		(yyval.tree) = add_tree_node("programa");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		tree = (yyval.tree);
	}
#line 1750 "skylang.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 62 "skylang.y"
                                    {
		(yyval.tree) = add_tree_node("declarationList");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	}
#line 1760 "skylang.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 67 "skylang.y"
                      {
		(yyval.tree) = add_tree_node("declarationList");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1769 "skylang.tab.c"
    break;

  case 5: /* declaration: variable_declaration  */
#line 73 "skylang.y"
                            {
		(yyval.tree) = add_tree_node("declaration");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1778 "skylang.tab.c"
    break;

  case 6: /* declaration: func_declaration  */
#line 77 "skylang.y"
                          {
		(yyval.tree) = add_tree_node("declaration");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1787 "skylang.tab.c"
    break;

  case 7: /* variable_declaration: TYPE ID SEMICOLON  */
#line 84 "skylang.y"
                          { insert_symbol(symbol_ID, (yyvsp[-1].str),"VARIAVEL",(yyvsp[-2].str) );
						symbol_ID = symbol_ID +1;
						//printf("\nAQUI %s\n",$2);
						(yyval.tree) = add_tree_node("variable_declaration - Type ID");
						 
	}
#line 1798 "skylang.tab.c"
    break;

  case 8: /* func_declaration: TYPE ID PARENTESES_INI params PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 93 "skylang.y"
                                                                                      { insert_symbol(symbol_ID, (yyvsp[-6].str),"FUNCAO",(yyvsp[-7].str) );
																					symbol_ID = symbol_ID +1 ;																	
																					(yyval.tree) = add_tree_node("func_declaration");																		
																					(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
																					(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
	}
#line 1809 "skylang.tab.c"
    break;

  case 9: /* params: params_list  */
#line 102 "skylang.y"
                    { (yyval.tree) = add_tree_node("params");
		 		  (yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1817 "skylang.tab.c"
    break;

  case 10: /* params_list: param COLON params_list  */
#line 107 "skylang.y"
                                { (yyval.tree) = add_tree_node("params_list_n");
		 					  (yyval.tree) -> leaf1 = (yyvsp[-2].tree);
							  (yyval.tree) -> leaf2 = (yyvsp[0].tree);
	}
#line 1826 "skylang.tab.c"
    break;

  case 11: /* params_list: param  */
#line 111 "skylang.y"
               { (yyval.tree) = add_tree_node("params_lis_1");
		 	 (yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1834 "skylang.tab.c"
    break;

  case 12: /* params_list: %empty  */
#line 114 "skylang.y"
         { (yyval.tree) = add_tree_node("Vazio");
	}
#line 1841 "skylang.tab.c"
    break;

  case 13: /* param: TYPE ID  */
#line 118 "skylang.y"
                { insert_symbol(symbol_ID, (yyvsp[0].str),"PARAMETRO_FUNCAO",(yyvsp[-1].str) );
		      symbol_ID = symbol_ID +1;
			  (yyval.tree) = add_tree_node("param - TYPE ID");
	}
#line 1850 "skylang.tab.c"
    break;

  case 14: /* codeBlock: codeBlock statement  */
#line 124 "skylang.y"
                           {
		(yyval.tree) = add_tree_node("codeBlock");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	}
#line 1860 "skylang.tab.c"
    break;

  case 15: /* codeBlock: %empty  */
#line 129 "skylang.y"
          {
		(yyval.tree) = add_tree_node("codeBlock VAZIO");
		 
	}
#line 1869 "skylang.tab.c"
    break;

  case 16: /* statement: variable_declaration  */
#line 137 "skylang.y"
                             {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 1878 "skylang.tab.c"
    break;

  case 17: /* statement: variable_assignment SEMICOLON  */
#line 141 "skylang.y"
                                       {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1887 "skylang.tab.c"
    break;

  case 18: /* statement: exp SEMICOLON  */
#line 146 "skylang.y"
                       {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1896 "skylang.tab.c"
    break;

  case 19: /* statement: ifStatement  */
#line 150 "skylang.y"
                     {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 1905 "skylang.tab.c"
    break;

  case 20: /* statement: forAllStatement  */
#line 154 "skylang.y"
                         {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 1914 "skylang.tab.c"
    break;

  case 21: /* statement: outPutStatement SEMICOLON  */
#line 158 "skylang.y"
                                   {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1923 "skylang.tab.c"
    break;

  case 22: /* statement: inputStatement SEMICOLON  */
#line 162 "skylang.y"
                                  {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1932 "skylang.tab.c"
    break;

  case 23: /* statement: callFuncStatement SEMICOLON  */
#line 166 "skylang.y"
                                     {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1941 "skylang.tab.c"
    break;

  case 24: /* statement: RETURN exp SEMICOLON  */
#line 171 "skylang.y"
                          {
		(yyval.tree) = add_tree_node("RETURN statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1950 "skylang.tab.c"
    break;

  case 25: /* statement: forStatement  */
#line 176 "skylang.y"
                      {
		(yyval.tree) = add_tree_node("forStatement");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1959 "skylang.tab.c"
    break;

  case 26: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 185 "skylang.y"
                                                                                                                 {
			(yyval.tree) = add_tree_node("ForStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-6].tree);
			(yyval.tree) -> leaf3 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf4 = (yyvsp[-1].tree);
	}
#line 1971 "skylang.tab.c"
    break;

  case 27: /* callFuncStatement: ID PARENTESES_INI call_params PARENTESES_FIM  */
#line 197 "skylang.y"
                                                     {
		(yyval.tree) = add_tree_node("CallFunStatement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	}
#line 1980 "skylang.tab.c"
    break;

  case 28: /* call_params: call_params_list  */
#line 205 "skylang.y"
                        {
		(yyval.tree) = add_tree_node("CallParams");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1989 "skylang.tab.c"
    break;

  case 29: /* call_params_list: call_param COLON call_params_list  */
#line 211 "skylang.y"
                                          {
		(yyval.tree) = add_tree_node("call_params_list");
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	}
#line 1999 "skylang.tab.c"
    break;

  case 30: /* call_params_list: call_param  */
#line 216 "skylang.y"
                    {
		(yyval.tree) = add_tree_node("call_params_list");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 2008 "skylang.tab.c"
    break;

  case 31: /* call_params_list: %empty  */
#line 220 "skylang.y"
         {
		(yyval.tree) = add_tree_node("Vazio");
	 }
#line 2016 "skylang.tab.c"
    break;

  case 32: /* call_param: terminal  */
#line 225 "skylang.y"
                 {
		(yyval.tree) = add_tree_node("call_param terminal");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 2025 "skylang.tab.c"
    break;

  case 33: /* inputStatement: READ PARENTESES_INI STRING PARENTESES_FIM  */
#line 233 "skylang.y"
                                                  {
		(yyval.tree) = add_tree_node("inputStatement");	 
		//$$ -> leaf1 = $3;
	}
#line 2034 "skylang.tab.c"
    break;

  case 34: /* outPutStatement: WRITE PARENTESES_INI STRING PARENTESES_FIM  */
#line 241 "skylang.y"
                                                    {
		(yyval.tree) = add_tree_node("outPutStatement");
		//$$ -> leaf1 = $3;
	 }
#line 2043 "skylang.tab.c"
    break;

  case 35: /* outPutStatement: WRITELN PARENTESES_INI STRING PARENTESES_FIM  */
#line 245 "skylang.y"
                                                       {
		(yyval.tree) = add_tree_node("outPutStatement");
		//$$ -> leaf1 = $3;
	 }
#line 2052 "skylang.tab.c"
    break;

  case 36: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 253 "skylang.y"
                                                                                      {
		(yyval.tree) = add_tree_node("forAllStatement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 2061 "skylang.tab.c"
    break;

  case 37: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 261 "skylang.y"
                                                                              {
		(yyval.tree) = add_tree_node("ifStatement");
		(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
	 }
#line 2071 "skylang.tab.c"
    break;

  case 38: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM ELSE CHAVES_INI codeBlock CHAVES_FIM  */
#line 266 "skylang.y"
                                                                                                                   {
		(yyval.tree) = add_tree_node("ifElseStatement");
		(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-5].tree);
		(yyval.tree) -> leaf3 = (yyvsp[-1].tree);
	 }
#line 2082 "skylang.tab.c"
    break;

  case 39: /* variable_assignment: ID EQUALS exp  */
#line 275 "skylang.y"
                      {
		(yyval.tree) = add_tree_node("var_assign");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 2091 "skylang.tab.c"
    break;

  case 40: /* exp: setExp  */
#line 339 "skylang.y"
                {
		(yyval.tree) = add_tree_node("exp");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 2100 "skylang.tab.c"
    break;

  case 41: /* exp: aritExp  */
#line 343 "skylang.y"
                 {
		(yyval.tree) = add_tree_node("exp");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 2109 "skylang.tab.c"
    break;

  case 42: /* exp: relExp  */
#line 347 "skylang.y"
                {
		(yyval.tree) = add_tree_node("exp");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 2118 "skylang.tab.c"
    break;

  case 43: /* exp: terminal  */
#line 351 "skylang.y"
                  {
		(yyval.tree) = add_tree_node("exp");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 2127 "skylang.tab.c"
    break;

  case 44: /* setExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 358 "skylang.y"
                                                                 {
		(yyval.tree) = add_tree_node("setExp");
		(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
	}
#line 2137 "skylang.tab.c"
    break;

  case 45: /* setExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 363 "skylang.y"
                                                                      {
		(yyval.tree) = add_tree_node("setExp");
		(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
	}
#line 2147 "skylang.tab.c"
    break;

  case 46: /* setExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 368 "skylang.y"
                                                                      {
		(yyval.tree) = add_tree_node("setExp");
		(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
	}
#line 2157 "skylang.tab.c"
    break;

  case 47: /* terms_set: aritSetExp  */
#line 376 "skylang.y"
                   {
		(yyval.tree) = add_tree_node("terms_set");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 2166 "skylang.tab.c"
    break;

  case 48: /* aritSetExp: ID  */
#line 383 "skylang.y"
           {
		(yyval.tree) = add_tree_node("terminal ID");
		 
	 }
#line 2175 "skylang.tab.c"
    break;

  case 49: /* aritSetExp: FLOAT  */
#line 387 "skylang.y"
               {
		(yyval.tree) = add_tree_node("terminal FLOAT");
		 
	 }
#line 2184 "skylang.tab.c"
    break;

  case 50: /* aritSetExp: INTEGER  */
#line 391 "skylang.y"
                 {
		(yyval.tree) = add_tree_node("terminal INTEGER");
		 
	 }
#line 2193 "skylang.tab.c"
    break;

  case 51: /* aritSetExp: PARENTESES_INI EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM PARENTESES_FIM  */
#line 395 "skylang.y"
                                                                                                   {
		(yyval.tree) = add_tree_node("aritSetExp");
		 
		(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
	}
#line 2204 "skylang.tab.c"
    break;

  case 52: /* aritExp: terminal MULT exp  */
#line 405 "skylang.y"
                          {
		(yyval.tree) = add_tree_node("aritExp");
		 
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	 }
#line 2215 "skylang.tab.c"
    break;

  case 53: /* aritExp: terminal PLUS exp  */
#line 411 "skylang.y"
                           {
		(yyval.tree) = add_tree_node("aritExp");
		 
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	 }
#line 2226 "skylang.tab.c"
    break;

  case 54: /* aritExp: terminal MINUS exp  */
#line 417 "skylang.y"
                            {
		(yyval.tree) = add_tree_node("aritExp");
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	 }
#line 2236 "skylang.tab.c"
    break;

  case 55: /* aritExp: terminal DIV exp  */
#line 422 "skylang.y"
                          {
		(yyval.tree) = add_tree_node("aritExp");
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	 }
#line 2246 "skylang.tab.c"
    break;

  case 56: /* aritExp: terminal EQUALS exp  */
#line 428 "skylang.y"
                              {
		(yyval.tree) = add_tree_node("aritExp");
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	 }
#line 2256 "skylang.tab.c"
    break;

  case 57: /* relExp: terminal rel exp  */
#line 435 "skylang.y"
                         {
		(yyval.tree) = add_tree_node("relExp");
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		(yyval.tree) -> leaf3 = (yyvsp[0].tree);
	 }
#line 2267 "skylang.tab.c"
    break;

  case 58: /* rel: CGE  */
#line 444 "skylang.y"
            {
		(yyval.tree) = add_tree_node("rel CGE");
	 }
#line 2275 "skylang.tab.c"
    break;

  case 59: /* rel: CGT  */
#line 447 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel");
	 }
#line 2283 "skylang.tab.c"
    break;

  case 60: /* rel: CNE  */
#line 450 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel");
	 }
#line 2291 "skylang.tab.c"
    break;

  case 61: /* rel: CLT  */
#line 453 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel");
	 }
#line 2299 "skylang.tab.c"
    break;

  case 62: /* rel: AND  */
#line 456 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel");
	 }
#line 2307 "skylang.tab.c"
    break;

  case 63: /* rel: CLE  */
#line 459 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel");
	 }
#line 2315 "skylang.tab.c"
    break;

  case 64: /* rel: CEQ  */
#line 462 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel CEQ");
	}
#line 2323 "skylang.tab.c"
    break;

  case 65: /* terminal: ID  */
#line 469 "skylang.y"
           {
		(yyval.tree) = add_tree_node("terminal ID");
		 
	 }
#line 2332 "skylang.tab.c"
    break;

  case 66: /* terminal: FLOAT  */
#line 473 "skylang.y"
               {
		(yyval.tree) = add_tree_node("terminal FLOAT");
		 
	 }
#line 2341 "skylang.tab.c"
    break;

  case 67: /* terminal: INTEGER  */
#line 477 "skylang.y"
                 {
		(yyval.tree) = add_tree_node("terminal INTEGER");
		 
	 }
#line 2350 "skylang.tab.c"
    break;

  case 68: /* terminal: PARENTESES_INI exp PARENTESES_FIM  */
#line 482 "skylang.y"
                                            {
		(yyval.tree) = add_tree_node("terminal EXP");
		(yyval.tree)->leaf1 =(yyvsp[-1].tree);
	}
#line 2359 "skylang.tab.c"
    break;


#line 2363 "skylang.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 489 "skylang.y"


extern void yyerror(const char* a) {
    printf("\n-->ERRO SINTATICO na linha %d, coluna %d\n",num_linha,posicao_linha);
	printf("-->  %s\n",a);
}


int main(){
char fname[100];
    printf("\nDigite o nome do arquivo a ser analisado:\n-> ");
    scanf("%s",fname);
    yyin=fopen(fname,"r+");
    yyparse();
    //yylex();
	fclose(yyin);
	printf("\n---------> Tabela de Simbolos <---------\n");
	printTS();
	printf("\n");
	printf("\n---------> ARVORE: <---------\n");
	print_tree(0,tree);
	printf("\n");
	free_tree(tree);
	//yyin=fopen(fname,"r+");
	//yyparse();
	//fclose(yyin);
    yylex_destroy();
    return 0;
}
