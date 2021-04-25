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
  YYSYMBOL_APOST = 33,                     /* APOST  */
  YYSYMBOL_CHAVES_INI = 34,                /* CHAVES_INI  */
  YYSYMBOL_CHAVES_FIM = 35,                /* CHAVES_FIM  */
  YYSYMBOL_PARENTESES_INI = 36,            /* PARENTESES_INI  */
  YYSYMBOL_PARENTESES_FIM = 37,            /* PARENTESES_FIM  */
  YYSYMBOL_EMPTY = 38,                     /* EMPTY  */
  YYSYMBOL_SEMICOLON = 39,                 /* SEMICOLON  */
  YYSYMBOL_EQUALS = 40,                    /* EQUALS  */
  YYSYMBOL_COLON = 41,                     /* COLON  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
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
  YYSYMBOL_callFuncStatement = 57,         /* callFuncStatement  */
  YYSYMBOL_call_params = 58,               /* call_params  */
  YYSYMBOL_call_params_list = 59,          /* call_params_list  */
  YYSYMBOL_call_param = 60,                /* call_param  */
  YYSYMBOL_inputStatement = 61,            /* inputStatement  */
  YYSYMBOL_outPutStatement = 62,           /* outPutStatement  */
  YYSYMBOL_forAllStatement = 63,           /* forAllStatement  */
  YYSYMBOL_ifStatement = 64,               /* ifStatement  */
  YYSYMBOL_variable_assignment = 65,       /* variable_assignment  */
  YYSYMBOL_exp = 66,                       /* exp  */
  YYSYMBOL_setExp = 67,                    /* setExp  */
  YYSYMBOL_terms_set = 68,                 /* terms_set  */
  YYSYMBOL_aritSetExp = 69,                /* aritSetExp  */
  YYSYMBOL_aritExp = 70,                   /* aritExp  */
  YYSYMBOL_relExp = 71,                    /* relExp  */
  YYSYMBOL_rel = 72,                       /* rel  */
  YYSYMBOL_terminal = 73                   /* terminal  */
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
#define YYLAST   881

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
       2,     2,    42,    43,     2,    44,     2,    45,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    51,    51,    59,    64,    70,    74,    81,    90,    99,
     104,   108,   111,   115,   121,   126,   134,   138,   142,   146,
     150,   154,   158,   162,   166,   176,   184,   190,   195,   199,
     204,   212,   220,   224,   232,   240,   245,   254,   261,   265,
     269,   273,   280,   285,   290,   298,   305,   309,   319,   325,
     331,   336,   343,   352,   355,   358,   361,   365,   368,   371,
     377,   381,   385
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
  "NEGATION", "APOST", "CHAVES_INI", "CHAVES_FIM", "PARENTESES_INI",
  "PARENTESES_FIM", "EMPTY", "SEMICOLON", "EQUALS", "COLON", "'*'", "'+'",
  "'-'", "'/'", "$accept", "programa", "declarationList", "declaration",
  "variable_declaration", "func_declaration", "params", "params_list",
  "param", "codeBlock", "statement", "callFuncStatement", "call_params",
  "call_params_list", "call_param", "inputStatement", "outPutStatement",
  "forAllStatement", "ifStatement", "variable_assignment", "exp", "setExp",
  "terms_set", "aritSetExp", "aritExp", "relExp", "rel", "terminal", YY_NULLPTR
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
     295,   296,    42,    43,    45,    47
};
#endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-63)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,     4,     9,    26,    87,    91,    92,    72,  -105,   155,
      -1,   157,    14,    -6,    -5,   -21,   -18,     3,    -1,    93,
       1,   194,    40,   704,   637,    10,    21,    22,    29,    30,
      35,    37,    42,   729,   736,   161,   221,   248,    20,    47,
      54,   275,   302,    62,    71,    73,    90,    98,   761,   110,
      11,   637,   768,   111,   644,    49,   125,   131,    13,    13,
      13,   159,   329,   356,   383,   410,   437,   655,   666,   673,
     677,   684,   695,   706,   637,   637,   637,   637,   637,   138,
     147,   -16,     6,   148,   464,   149,   151,   152,   153,   179,
     175,   176,   177,   184,   192,   195,   172,   174,   178,   180,
     181,   189,    11,   187,   197,   199,   200,   204,    41,    41,
      41,   210,   205,    93,    13,   206,   207,   208,   209,   491,
     198,   202,   216,   224,   213,   167,    41,    93,   214,   228,
     518,    93,   229,   545,   572,   201,   599,   626,    23,    31,
      48,   793,   231,   232,   233,   802,   827,   234,   235,   236,
     836,   253,   257,   258,   245,   255,   256,   278,   259,   260,
      13,    13,    13,   644,   644,   644,   644,   644,   262,   277,
     282,   283,   264,   265,   272,   280,   284,    13,    41,    41,
      41,   303,   285,   286,   287,    41,   288,   289,   290,   291,
     292,   299
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
       0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,   316,   182,  -105,  -105,   326,  -105,  -103,
    -105,  -105,  -105,   114,  -105,  -105,  -105,  -105,  -105,  -105,
     -24,   -40,   -26,  -104,   -19,     2,   145,   -47
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    36,     6,    13,    14,    15,    21,
      37,    38,    79,    80,    81,    39,    40,    41,    42,    43,
      44,    45,    90,    91,    46,    47,    78,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,     1,    12,    82,   158,   158,   158,   150,     7,     8,
     119,    92,    92,    92,   147,   138,   -11,   151,    16,   -13,
      18,   -28,   158,   -13,   130,   102,    -2,    83,   134,     1,
      85,    17,    -9,    93,    94,   148,   -12,    19,   -10,   139,
     140,   152,   153,   -30,    49,   154,    54,   -30,   -29,    89,
      96,    97,    98,    99,   100,    82,   149,    55,    56,    62,
     -60,   159,   159,   159,   -60,    57,    58,    92,   -62,   155,
     156,    59,   -62,    60,   158,   158,   158,   157,    61,   159,
      86,   158,   115,   116,   117,   -61,    63,    -4,   120,   -61,
      -4,    -5,    -6,    64,    -5,    -6,   -15,   -15,   -15,   -15,
     129,    65,   -15,   -15,   -15,   -15,   -15,   -15,    10,   -15,
      66,    11,   -38,    92,    92,    92,   150,   150,   150,   150,
     150,   -15,   -15,   147,   147,   147,   147,   147,   -15,   -39,
      92,   159,   159,   159,   169,   170,   171,   -40,   159,   172,
     173,   174,   175,   176,   148,   148,   148,   148,   148,   137,
      84,   181,   182,   183,   184,    -3,    87,    -7,    -3,   189,
      -7,    -8,    88,    95,    -8,   149,   149,   149,   149,   149,
     -35,   -35,   -35,   -35,   128,   101,   -35,   -35,   -35,   -35,
     -35,   -35,     5,   -35,   -26,     5,   103,   -37,   104,   105,
     106,   107,   108,   -45,   -46,   -35,   -35,    22,    23,    24,
      25,   109,   -35,    26,    27,    28,    29,    30,    31,   110,
      32,   -48,   111,   -49,   118,   126,   112,   -50,   -47,   -51,
     -52,   113,    33,    34,   -16,   -16,   -16,   -16,   -25,    35,
     -16,   -16,   -16,   -16,   -16,   -16,   -32,   -16,   -33,   -31,
     114,   -44,   -27,   121,   122,   123,   124,   127,   131,   -16,
     -16,   -14,   -14,   -14,   -14,   -42,   -16,   -14,   -14,   -14,
     -14,   -14,   -14,   -43,   -14,   132,   135,   160,   161,   162,
     -60,   -38,   -39,   -40,   -62,   -61,   -14,   -14,   -20,   -20,
     -20,   -20,   -60,   -14,   -20,   -20,   -20,   -20,   -20,   -20,
     168,   -20,   -62,   -61,   178,   167,   -45,   -46,   177,   179,
     180,   -48,   -49,   -20,   -20,   -19,   -19,   -19,   -19,   -50,
     -20,   -19,   -19,   -19,   -19,   -19,   -19,   -51,   -19,     9,
     185,   -52,   186,   187,   188,   -44,   -42,   -43,   190,   191,
     -19,   -19,   -23,   -23,   -23,   -23,   -47,   -19,   -23,   -23,
     -23,   -23,   -23,   -23,    20,   -23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -23,   -23,   -22,
     -22,   -22,   -22,     0,   -23,   -22,   -22,   -22,   -22,   -22,
     -22,     0,   -22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -22,   -22,   -21,   -21,   -21,   -21,
       0,   -22,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -21,   -21,   -17,   -17,   -17,   -17,     0,   -21,   -17,
     -17,   -17,   -17,   -17,   -17,     0,   -17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -17,   -17,
     -18,   -18,   -18,   -18,     0,   -17,   -18,   -18,   -18,   -18,
     -18,   -18,     0,   -18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -18,   -18,   -24,   -24,   -24,
     -24,     0,   -18,   -24,   -24,   -24,   -24,   -24,   -24,     0,
     -24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -24,   -24,    22,    23,    24,    25,     0,   -24,
      26,    27,    28,    29,    30,    31,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
      34,    22,    23,    24,    25,     0,   125,    26,    27,    28,
      29,    30,    31,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,   -34,   -34,
     -34,   -34,     0,   133,   -34,   -34,   -34,   -34,   -34,   -34,
       0,   -34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -34,   -34,    22,    23,    24,    25,     0,
     -34,    26,    27,    28,    29,    30,    31,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,   -36,   -36,   -36,   -36,     0,   136,   -36,   -36,
     -36,   -36,   -36,   -36,     0,   -36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -36,   -36,    -7,
      -7,    -7,    -7,     0,   -36,    -7,    -7,    -7,    -7,    -7,
      -7,    52,    -7,     0,     0,     0,     0,     0,   141,    29,
      30,    31,     0,     0,    -7,    -7,   142,   143,   144,   -58,
       0,    -7,     0,     0,     0,    33,    34,   -58,   -58,   -58,
     -56,     0,   145,   146,     0,     0,     0,   -55,   -56,   -56,
     -56,   -54,     0,   -58,   -58,   -55,   -55,   -55,   -57,   -54,
     -54,   -54,     0,     0,   -56,   -56,   -57,   -57,   -57,   -59,
       0,   -55,   -55,     0,     0,   -54,   -54,   -59,   -59,   -59,
     -53,     0,   -57,   -57,     0,     0,     0,     0,   -53,   -53,
     -53,     0,     0,   -59,   -59,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,     0,     0,   -53,   -53,     0,     0,     0,     0,
      50,     0,     0,   -60,    51,     0,   -60,   -60,   -60,   -60,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -61,   -61,   -61,
     -61,   -61,   -61,   -61,     0,     0,     0,     0,   -62,     0,
       0,   -62,   -62,   -62,   -62,   -61,     0,     0,   -61,   -61,
     -61,   -61,    67,    68,    69,    70,    71,    72,    73,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,     0,     0,     0,     0,
     -41,     0,     0,    74,    75,    76,    77,   -60,     0,     0,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,   -60,
     -60,     0,     0,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -60,     0,     0,     0,     0,   -60,   -60,   -60,   -60,   -62,
       0,     0,     0,     0,   -62,   -62,   -62,   -62,   -61,   -61,
     -61,   -61,   -61,   -61,   -61,     0,     0,    67,    68,    69,
      70,    71,    72,    73,   -61,     0,     0,     0,     0,   -61,
     -61,   -61,   -61,   -41,     0,     0,     0,     0,   163,   164,
     165,   166
};

static const yytype_int16 yycheck[] =
{
      24,     3,     3,    50,   108,   109,   110,    54,     4,     0,
     113,    58,    59,    60,    54,     4,    37,     4,     4,    37,
      41,    37,   126,    41,   127,    41,     0,    51,   131,     3,
      54,    37,    37,    59,    60,    54,    37,    34,    37,    28,
      29,    28,    29,    37,     4,     4,    36,    41,    37,    36,
      74,    75,    76,    77,    78,   102,    54,    36,    36,    39,
      37,   108,   109,   110,    41,    36,    36,   114,    37,    28,
      29,    36,    41,    36,   178,   179,   180,    36,    36,   126,
      31,   185,   108,   109,   110,    37,    39,     0,   114,    41,
       3,     0,     0,    39,     3,     3,     3,     4,     5,     6,
     126,    39,     9,    10,    11,    12,    13,    14,    36,    16,
      39,    39,    39,   160,   161,   162,   163,   164,   165,   166,
     167,    28,    29,   163,   164,   165,   166,   167,    35,    39,
     177,   178,   179,   180,   160,   161,   162,    39,   185,   163,
     164,   165,   166,   167,   163,   164,   165,   166,   167,    39,
      39,   177,   178,   179,   180,     0,    31,     0,     3,   185,
       3,     0,    31,     4,     3,   163,   164,   165,   166,   167,
       3,     4,     5,     6,     7,    37,     9,    10,    11,    12,
      13,    14,     0,    16,    37,     3,    37,    39,    37,    37,
      37,    12,    17,    17,    17,    28,    29,     3,     4,     5,
       6,    17,    35,     9,    10,    11,    12,    13,    14,    17,
      16,    39,    17,    39,     4,    17,   102,    39,    17,    39,
      39,    34,    28,    29,     3,     4,     5,     6,    39,    35,
       9,    10,    11,    12,    13,    14,    39,    16,    39,    39,
      36,    39,    37,    37,    37,    37,    37,    34,    34,    28,
      29,     3,     4,     5,     6,    39,    35,     9,    10,    11,
      12,    13,    14,    39,    16,    37,    37,    36,    36,    36,
      17,    37,    37,    37,    17,    17,    28,    29,     3,     4,
       5,     6,    37,    35,     9,    10,    11,    12,    13,    14,
      12,    16,    37,    37,    17,   150,    37,    37,    36,    17,
      17,    37,    37,    28,    29,     3,     4,     5,     6,    37,
      35,     9,    10,    11,    12,    13,    14,    37,    16,     3,
      17,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      28,    29,     3,     4,     5,     6,    37,    35,     9,    10,
      11,    12,    13,    14,    18,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,     3,
       4,     5,     6,    -1,    35,     9,    10,    11,    12,    13,
      14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,     3,     4,     5,     6,
      -1,    35,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,     3,     4,     5,     6,    -1,    35,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
       3,     4,     5,     6,    -1,    35,     9,    10,    11,    12,
      13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,     3,     4,     5,
       6,    -1,    35,     9,    10,    11,    12,    13,    14,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,     3,     4,     5,     6,    -1,    35,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,     3,     4,     5,     6,    -1,    35,     9,    10,    11,
      12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,     3,     4,
       5,     6,    -1,    35,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,     3,     4,     5,     6,    -1,
      35,     9,    10,    11,    12,    13,    14,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,     3,     4,     5,     6,    -1,    35,     9,    10,
      11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,     3,
       4,     5,     6,    -1,    35,     9,    10,    11,    12,    13,
      14,     4,    16,    -1,    -1,    -1,    -1,    -1,     4,    12,
      13,    14,    -1,    -1,    28,    29,    12,    13,    14,     4,
      -1,    35,    -1,    -1,    -1,    28,    29,    12,    13,    14,
       4,    -1,    28,    29,    -1,    -1,    -1,     4,    12,    13,
      14,     4,    -1,    28,    29,    12,    13,    14,     4,    12,
      13,    14,    -1,    -1,    28,    29,    12,    13,    14,     4,
      -1,    28,    29,    -1,    -1,    28,    29,    12,    13,    14,
       4,    -1,    28,    29,    -1,    -1,    -1,    -1,    12,    13,
      14,    -1,    -1,    28,    29,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    39,    40,    -1,    42,    43,    44,    45,
      21,    22,    23,    24,    25,    26,    27,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    42,    43,    44,    45,    39,    -1,    -1,    42,    43,
      44,    45,    21,    22,    23,    24,    25,    26,    27,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    42,    43,    44,    45,    39,    -1,    -1,
      42,    43,    44,    45,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    37,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    37,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    37,    -1,    -1,    -1,    -1,    42,    43,
      44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    47,    48,    49,    50,    51,     4,     0,    49,
      36,    39,     3,    52,    53,    54,     4,    37,    41,    34,
      53,    55,     3,     4,     5,     6,     9,    10,    11,    12,
      13,    14,    16,    28,    29,    35,    50,    56,    57,    61,
      62,    63,    64,    65,    66,    67,    70,    71,    73,     4,
      36,    40,     4,    66,    36,    36,    36,    36,    36,    36,
      36,    36,    39,    39,    39,    39,    39,    21,    22,    23,
      24,    25,    26,    27,    42,    43,    44,    45,    72,    58,
      59,    60,    73,    66,    39,    66,    31,    31,    31,    36,
      68,    69,    73,    68,    68,     4,    66,    66,    66,    66,
      66,    37,    41,    37,    37,    37,    37,    12,    17,    17,
      17,    17,    59,    34,    36,    68,    68,    68,     4,    55,
      68,    37,    37,    37,    37,    35,    17,    34,     7,    68,
      55,    34,    37,    35,    55,    37,    35,    39,     4,    28,
      29,     4,    12,    13,    14,    28,    29,    67,    70,    71,
      73,     4,    28,    29,     4,    28,    29,    36,    69,    73,
      36,    36,    36,    42,    43,    44,    45,    72,    12,    68,
      68,    68,    66,    66,    66,    66,    66,    36,    17,    17,
      17,    68,    68,    68,    68,    17,    37,    37,    37,    68,
      37,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    52,
      53,    53,    53,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    57,    58,    59,    59,    59,
      60,    61,    62,    62,    63,    64,    64,    65,    66,    66,
      66,    66,    67,    67,    67,    68,    69,    69,    70,    70,
      70,    70,    71,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     8,     1,
       3,     1,     0,     2,     2,     0,     1,     2,     2,     1,
       1,     2,     2,     2,     3,     4,     1,     3,     1,     0,
       1,     4,     4,     4,     9,     7,    11,     3,     1,     1,
       1,     1,     6,     6,     6,     1,     1,     8,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 51 "skylang.y"
                        {
		(yyval.tree) = add_tree_node("programa");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		tree = (yyval.tree);
	}
#line 1685 "skylang.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 59 "skylang.y"
                                    {
		(yyval.tree) = add_tree_node("declarationList");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	}
#line 1695 "skylang.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 64 "skylang.y"
                      {
		(yyval.tree) = add_tree_node("declarationList");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1704 "skylang.tab.c"
    break;

  case 5: /* declaration: variable_declaration  */
#line 70 "skylang.y"
                            {
		(yyval.tree) = add_tree_node("declaration");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1713 "skylang.tab.c"
    break;

  case 6: /* declaration: func_declaration  */
#line 74 "skylang.y"
                          {
		(yyval.tree) = add_tree_node("declaration");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1722 "skylang.tab.c"
    break;

  case 7: /* variable_declaration: TYPE ID SEMICOLON  */
#line 81 "skylang.y"
                          { insert_symbol(symbol_ID, (yyvsp[-1].str),"VARIAVEL",(yyvsp[-2].str) );
						symbol_ID = symbol_ID +1;
						//printf("\nAQUI %s\n",$2);
						(yyval.tree) = add_tree_node("variable_declaration - Type ID");
						 
	}
#line 1733 "skylang.tab.c"
    break;

  case 8: /* func_declaration: TYPE ID PARENTESES_INI params PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 90 "skylang.y"
                                                                                      { insert_symbol(symbol_ID, (yyvsp[-6].str),"FUNCAO",(yyvsp[-7].str) );
																					symbol_ID = symbol_ID +1 ;																	
																					(yyval.tree) = add_tree_node("func_declaration");																		
																					(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
																					(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
	}
#line 1744 "skylang.tab.c"
    break;

  case 9: /* params: params_list  */
#line 99 "skylang.y"
                    { (yyval.tree) = add_tree_node("params");
		 		  (yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1752 "skylang.tab.c"
    break;

  case 10: /* params_list: param COLON params_list  */
#line 104 "skylang.y"
                                { (yyval.tree) = add_tree_node("params_list_n");
		 					  (yyval.tree) -> leaf1 = (yyvsp[-2].tree);
							  (yyval.tree) -> leaf2 = (yyvsp[0].tree);
	}
#line 1761 "skylang.tab.c"
    break;

  case 11: /* params_list: param  */
#line 108 "skylang.y"
               { (yyval.tree) = add_tree_node("params_lis_1");
		 	 (yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1769 "skylang.tab.c"
    break;

  case 12: /* params_list: %empty  */
#line 111 "skylang.y"
         { (yyval.tree) = add_tree_node("Vazio");
	}
#line 1776 "skylang.tab.c"
    break;

  case 13: /* param: TYPE ID  */
#line 115 "skylang.y"
                { insert_symbol(symbol_ID, (yyvsp[0].str),"PARAMETRO_FUNCAO",(yyvsp[-1].str) );
		      symbol_ID = symbol_ID +1;
			  (yyval.tree) = add_tree_node("param - TYPE ID");
	}
#line 1785 "skylang.tab.c"
    break;

  case 14: /* codeBlock: codeBlock statement  */
#line 121 "skylang.y"
                           {
		(yyval.tree) = add_tree_node("codeBlock");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	}
#line 1795 "skylang.tab.c"
    break;

  case 15: /* codeBlock: %empty  */
#line 126 "skylang.y"
          {
		(yyval.tree) = add_tree_node("codeBlock VAZIO");
		 
	}
#line 1804 "skylang.tab.c"
    break;

  case 16: /* statement: variable_declaration  */
#line 134 "skylang.y"
                             {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 1813 "skylang.tab.c"
    break;

  case 17: /* statement: variable_assignment SEMICOLON  */
#line 138 "skylang.y"
                                       {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1822 "skylang.tab.c"
    break;

  case 18: /* statement: exp SEMICOLON  */
#line 142 "skylang.y"
                       {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1831 "skylang.tab.c"
    break;

  case 19: /* statement: ifStatement  */
#line 146 "skylang.y"
                     {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 1840 "skylang.tab.c"
    break;

  case 20: /* statement: forAllStatement  */
#line 150 "skylang.y"
                         {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 1849 "skylang.tab.c"
    break;

  case 21: /* statement: outPutStatement SEMICOLON  */
#line 154 "skylang.y"
                                   {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1858 "skylang.tab.c"
    break;

  case 22: /* statement: inputStatement SEMICOLON  */
#line 158 "skylang.y"
                                  {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1867 "skylang.tab.c"
    break;

  case 23: /* statement: callFuncStatement SEMICOLON  */
#line 162 "skylang.y"
                                     {
		(yyval.tree) = add_tree_node("statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1876 "skylang.tab.c"
    break;

  case 24: /* statement: RETURN exp SEMICOLON  */
#line 166 "skylang.y"
                              {
		(yyval.tree) = add_tree_node("RETURN statement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);

	 }
#line 1886 "skylang.tab.c"
    break;

  case 25: /* callFuncStatement: ID PARENTESES_INI call_params PARENTESES_FIM  */
#line 176 "skylang.y"
                                                     {
		(yyval.tree) = add_tree_node("CallFunStatement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	}
#line 1895 "skylang.tab.c"
    break;

  case 26: /* call_params: call_params_list  */
#line 184 "skylang.y"
                        {
		(yyval.tree) = add_tree_node("CallParams");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1904 "skylang.tab.c"
    break;

  case 27: /* call_params_list: call_param COLON call_params_list  */
#line 190 "skylang.y"
                                          {
		(yyval.tree) = add_tree_node("call_params_list");
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	}
#line 1914 "skylang.tab.c"
    break;

  case 28: /* call_params_list: call_param  */
#line 195 "skylang.y"
                    {
		(yyval.tree) = add_tree_node("call_params_list");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1923 "skylang.tab.c"
    break;

  case 29: /* call_params_list: %empty  */
#line 199 "skylang.y"
         {
		(yyval.tree) = add_tree_node("Vazio");
	 }
#line 1931 "skylang.tab.c"
    break;

  case 30: /* call_param: terminal  */
#line 204 "skylang.y"
                 {
		(yyval.tree) = add_tree_node("call_param terminal");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 1940 "skylang.tab.c"
    break;

  case 31: /* inputStatement: READ PARENTESES_INI STRING PARENTESES_FIM  */
#line 212 "skylang.y"
                                                  {
		(yyval.tree) = add_tree_node("inputStatement");	 
		//$$ -> leaf1 = $3;
	}
#line 1949 "skylang.tab.c"
    break;

  case 32: /* outPutStatement: WRITE PARENTESES_INI STRING PARENTESES_FIM  */
#line 220 "skylang.y"
                                                    {
		(yyval.tree) = add_tree_node("outPutStatement");
		//$$ -> leaf1 = $3;
	 }
#line 1958 "skylang.tab.c"
    break;

  case 33: /* outPutStatement: WRITELN PARENTESES_INI STRING PARENTESES_FIM  */
#line 224 "skylang.y"
                                                       {
		(yyval.tree) = add_tree_node("outPutStatement");
		//$$ -> leaf1 = $3;
	 }
#line 1967 "skylang.tab.c"
    break;

  case 34: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 232 "skylang.y"
                                                                                      {
		(yyval.tree) = add_tree_node("forAllStatement");
		(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
	 }
#line 1976 "skylang.tab.c"
    break;

  case 35: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 240 "skylang.y"
                                                                              {
		(yyval.tree) = add_tree_node("ifStatement");
		(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
	 }
#line 1986 "skylang.tab.c"
    break;

  case 36: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM ELSE CHAVES_INI codeBlock CHAVES_FIM  */
#line 245 "skylang.y"
                                                                                                                   {
		(yyval.tree) = add_tree_node("ifElseStatement");
		(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-5].tree);
		(yyval.tree) -> leaf3 = (yyvsp[-1].tree);
	 }
#line 1997 "skylang.tab.c"
    break;

  case 37: /* variable_assignment: ID EQUALS exp  */
#line 254 "skylang.y"
                      {
		(yyval.tree) = add_tree_node("var_assign");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 2006 "skylang.tab.c"
    break;

  case 38: /* exp: setExp  */
#line 261 "skylang.y"
                {
		(yyval.tree) = add_tree_node("exp");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 2015 "skylang.tab.c"
    break;

  case 39: /* exp: aritExp  */
#line 265 "skylang.y"
                 {
		(yyval.tree) = add_tree_node("exp");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 2024 "skylang.tab.c"
    break;

  case 40: /* exp: relExp  */
#line 269 "skylang.y"
                {
		(yyval.tree) = add_tree_node("exp");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 2033 "skylang.tab.c"
    break;

  case 41: /* exp: terminal  */
#line 273 "skylang.y"
                  {
		(yyval.tree) = add_tree_node("exp");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	 }
#line 2042 "skylang.tab.c"
    break;

  case 42: /* setExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 280 "skylang.y"
                                                                 {
		(yyval.tree) = add_tree_node("setExp");
		(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
	}
#line 2052 "skylang.tab.c"
    break;

  case 43: /* setExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 285 "skylang.y"
                                                                      {
		(yyval.tree) = add_tree_node("setExp");
		(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
	}
#line 2062 "skylang.tab.c"
    break;

  case 44: /* setExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 290 "skylang.y"
                                                                      {
		(yyval.tree) = add_tree_node("setExp");
		(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
	}
#line 2072 "skylang.tab.c"
    break;

  case 45: /* terms_set: aritSetExp  */
#line 298 "skylang.y"
                   {
		(yyval.tree) = add_tree_node("terms_set");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 2081 "skylang.tab.c"
    break;

  case 46: /* aritSetExp: terminal  */
#line 305 "skylang.y"
                 {
		(yyval.tree) = add_tree_node("aritSetExp");
		(yyval.tree) -> leaf1 = (yyvsp[0].tree);
	}
#line 2090 "skylang.tab.c"
    break;

  case 47: /* aritSetExp: PARENTESES_INI EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM PARENTESES_FIM  */
#line 309 "skylang.y"
                                                                                                   {
		(yyval.tree) = add_tree_node("aritSetExp");
		 
		(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
	}
#line 2101 "skylang.tab.c"
    break;

  case 48: /* aritExp: terminal '*' exp  */
#line 319 "skylang.y"
                         {
		(yyval.tree) = add_tree_node("aritExp");
		 
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	 }
#line 2112 "skylang.tab.c"
    break;

  case 49: /* aritExp: terminal '+' exp  */
#line 325 "skylang.y"
                          {
		(yyval.tree) = add_tree_node("aritExp");
		 
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	 }
#line 2123 "skylang.tab.c"
    break;

  case 50: /* aritExp: terminal '-' exp  */
#line 331 "skylang.y"
                          {
		(yyval.tree) = add_tree_node("aritExp");
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	 }
#line 2133 "skylang.tab.c"
    break;

  case 51: /* aritExp: terminal '/' exp  */
#line 336 "skylang.y"
                          {
		(yyval.tree) = add_tree_node("aritExp");
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[0].tree);
	 }
#line 2143 "skylang.tab.c"
    break;

  case 52: /* relExp: terminal rel exp  */
#line 343 "skylang.y"
                         {
		(yyval.tree) = add_tree_node("relExp");
		(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
		(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		(yyval.tree) -> leaf3 = (yyvsp[0].tree);
	 }
#line 2154 "skylang.tab.c"
    break;

  case 53: /* rel: CGE  */
#line 352 "skylang.y"
            {
		(yyval.tree) = add_tree_node("rel CGE");
	 }
#line 2162 "skylang.tab.c"
    break;

  case 54: /* rel: CGT  */
#line 355 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel");
	 }
#line 2170 "skylang.tab.c"
    break;

  case 55: /* rel: CNE  */
#line 358 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel");
	 }
#line 2178 "skylang.tab.c"
    break;

  case 56: /* rel: CLT  */
#line 361 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel");
		
	 }
#line 2187 "skylang.tab.c"
    break;

  case 57: /* rel: AND  */
#line 365 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel");
	 }
#line 2195 "skylang.tab.c"
    break;

  case 58: /* rel: CLE  */
#line 368 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel");
	 }
#line 2203 "skylang.tab.c"
    break;

  case 59: /* rel: CEQ  */
#line 371 "skylang.y"
              {
		(yyval.tree) = add_tree_node("rel CEQ");
	 }
#line 2211 "skylang.tab.c"
    break;

  case 60: /* terminal: ID  */
#line 377 "skylang.y"
           {
		(yyval.tree) = add_tree_node("terminal ID");
		 
	 }
#line 2220 "skylang.tab.c"
    break;

  case 61: /* terminal: FLOAT  */
#line 381 "skylang.y"
               {
		(yyval.tree) = add_tree_node("terminal FLOAT");
		 
	 }
#line 2229 "skylang.tab.c"
    break;

  case 62: /* terminal: INTEGER  */
#line 385 "skylang.y"
                 {
		(yyval.tree) = add_tree_node("terminal INTEGER");
		 
	 }
#line 2238 "skylang.tab.c"
    break;


#line 2242 "skylang.tab.c"

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

#line 391 "skylang.y"


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
