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
#include <string.h>

extern int yylex();
extern void yyerror(const char* msg);
extern int yylex_destroy();
extern FILE *yyin;
extern Hash_table * hashed_symbol_table;
int symbol_ID = 0;
treeNode* tree = NULL;
int existe_simbolo;
char * escopoAtual = "Global";
/* Print TS Function*/
void printTS(){
	Hash_table* aux = hashed_symbol_table;
    while(aux!=NULL){
        printf("\n Id simbolo: %d | Nome simbolo: %s | Tipo simbolo: %s %s | Escopo: %s",aux->id,aux->name,aux->type,aux->varType, aux -> escopo);
        aux = aux -> hh.next;
    }
	free(aux);
}

//Search symbol in symbol table
int searchSymbol(char*symbol){
	Hash_table* aux = hashed_symbol_table;
	int retorno = 0;
    while(aux!=NULL){
		//strcmp retorna 0 caso as strings sejam iguais
        if (strcmp(aux->name,symbol)==0){
			retorno = 1;
		}
        aux = aux -> hh.next;
    }
	free(aux);
	if(retorno == 1){
		return 1;
	}else{
		return 0;
	}
}


#line 120 "skylang.tab.c"

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
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_params = 53,                    /* params  */
  YYSYMBOL_params_list = 54,               /* params_list  */
  YYSYMBOL_param = 55,                     /* param  */
  YYSYMBOL_codeBlock = 56,                 /* codeBlock  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_forStatement = 58,              /* forStatement  */
  YYSYMBOL_callFuncStatement = 59,         /* callFuncStatement  */
  YYSYMBOL_call_params = 60,               /* call_params  */
  YYSYMBOL_call_params_list = 61,          /* call_params_list  */
  YYSYMBOL_call_param = 62,                /* call_param  */
  YYSYMBOL_inputStatement = 63,            /* inputStatement  */
  YYSYMBOL_outPutStatement = 64,           /* outPutStatement  */
  YYSYMBOL_forAllStatement = 65,           /* forAllStatement  */
  YYSYMBOL_ifStatement = 66,               /* ifStatement  */
  YYSYMBOL_exp = 67,                       /* exp  */
  YYSYMBOL_assignmentExp = 68,             /* assignmentExp  */
  YYSYMBOL_setExp = 69,                    /* setExp  */
  YYSYMBOL_terms_set = 70,                 /* terms_set  */
  YYSYMBOL_aritSetExp = 71,                /* aritSetExp  */
  YYSYMBOL_aritExp = 72,                   /* aritExp  */
  YYSYMBOL_relExp = 73,                    /* relExp  */
  YYSYMBOL_rel = 74,                       /* rel  */
  YYSYMBOL_terminal = 75                   /* terminal  */
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
#define YYLAST   1179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  68
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

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
       0,    77,    77,    88,    95,   103,   109,   118,   130,   130,
     143,   151,   158,   164,   171,   180,   187,   197,   204,   210,
     216,   222,   228,   234,   241,   248,   258,   272,   282,   290,
     297,   303,   310,   320,   330,   336,   346,   366,   373,   384,
     390,   396,   402,   409,   418,   428,   435,   442,   452,   461,
     474,   480,   486,   497,   504,   511,   518,   527,   538,   543,
     548,   553,   558,   563,   568,   577,   590,   596,   603
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
  "declaration", "variable_declaration", "func_declaration", "$@1",
  "params", "params_list", "param", "codeBlock", "statement",
  "forStatement", "callFuncStatement", "call_params", "call_params_list",
  "call_param", "inputStatement", "outPutStatement", "forAllStatement",
  "ifStatement", "exp", "assignmentExp", "setExp", "terms_set",
  "aritSetExp", "aritExp", "relExp", "rel", "terminal", YY_NULLPTR
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

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    27,    29,     5,    11,    15,    16,   -13,  -117,    25,
       3,    62,     4,    34,   -29,    -5,    31,    33,    13,     4,
     225,    23,   254,    48,   884,   795,    30,    43,    44,    56,
      57,    80,    82,    83,    86,   909,   934,    73,   800,   289,
     318,   347,    20,    84,    85,   376,   405,    88,    91,    92,
      94,    97,   959,    98,     6,   984,    99,   800,   102,   109,
     110,     8,     8,     8,   795,   138,    50,   434,   463,   492,
     521,   813,   826,   831,   844,   857,   862,   875,   795,   795,
     795,   795,   795,   795,   116,   140,    37,    41,   550,   142,
     143,   144,   145,   167,   168,   170,   176,   178,   180,   181,
     182,   160,   184,  1009,   162,   163,   164,   165,   172,   173,
     174,     6,   183,   175,   177,   179,   185,    22,    22,    22,
     795,   212,   186,   225,     8,   195,   204,   205,   207,   206,
     579,   203,   208,   209,   210,   800,   188,    93,    22,   213,
     225,   217,   218,   220,   608,   225,   233,   225,   637,   666,
     228,   695,   724,   753,  1034,   235,   236,   237,  1059,  1084,
     800,   238,   239,   240,   241,  1109,   782,    49,    51,    74,
     800,   242,   243,   249,   263,   250,     8,     8,     8,   251,
     800,   800,   800,   800,   800,   800,   258,   260,   294,   295,
     296,  1134,   268,   276,   278,   281,   282,   297,    75,     8,
      22,    22,    22,   319,   299,   300,   301,    22,   302,   303,
     304,   305,   306,   307
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
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,  -117,   345,   111,  -117,  -117,  -117,   202,  -117,
     -77,  -117,  -117,  -117,  -117,   253,  -117,  -117,  -117,  -117,
    -117,   -25,   -17,    -8,   108,  -116,     9,    26,   200,   -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    39,     6,    12,    14,    15,    16,
      22,    40,    41,    42,    84,    85,    86,    43,    44,    45,
      46,    47,    48,    49,    97,    98,    50,    51,    83,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   175,   175,   175,   165,    -2,    -8,    13,     1,    18,
     167,    -4,    93,    66,    -4,    -5,    -6,     1,    -5,    -6,
      87,   161,   175,   165,    10,    -3,   171,    11,    -3,     8,
     162,     7,    89,   -10,   168,   169,    94,    95,    17,   101,
     161,    -8,   -13,   170,   -31,    96,   130,   163,    20,   162,
     172,   173,    53,   104,   105,   106,   107,   108,   109,   174,
      67,   -11,    -7,   144,   164,    -7,   163,    57,   149,   -12,
     151,   -14,    19,    -9,   -14,   -30,    -9,    87,   111,   -32,
      58,    59,   -32,   164,   175,   175,   175,   -65,   103,   -67,
     -65,   175,   -67,    60,    61,   128,   -37,   -37,   -37,   -37,
     141,   165,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     139,     5,   -66,   -68,     5,   -66,   -68,    62,   161,    63,
      64,   -37,   -37,    65,    68,    69,   165,   162,    70,   -37,
     -37,   -43,   -39,    90,   -40,   179,   165,   -41,   166,    88,
      91,    92,   102,   161,   163,   186,   165,   165,   165,   165,
     165,   165,   162,   161,   110,   192,   193,   194,   195,   196,
     197,   164,   162,   161,   161,   161,   161,   161,   161,   163,
      99,   100,   162,   162,   162,   162,   162,   162,   -28,   163,
     112,   113,   114,   115,   -49,   -51,   164,   -50,   116,   163,
     163,   163,   163,   163,   163,   117,   164,   -48,   118,   119,
     120,   121,   -44,   -54,   -55,   -53,   164,   164,   164,   164,
     164,   164,   -56,   -57,   -27,   -34,   129,   -35,   123,   -33,
     138,    21,   124,   140,   -29,   125,   126,   127,   -16,   -16,
     -16,   -16,   131,   132,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   133,   134,   136,   -52,   142,   135,   -47,   -45,
     -46,   143,   145,   -16,   -16,   147,   146,    23,    24,    25,
      26,   -16,   -16,    27,    28,    29,    30,    31,    32,    33,
      34,   150,   176,   177,   178,   187,   -43,   -39,   -40,   -41,
     -49,   -51,    35,    36,   188,   189,   190,   -50,   -48,   191,
      37,    38,   -17,   -17,   -17,   -17,   198,   199,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -44,   203,   204,   205,
     206,   200,   201,   202,   -54,   211,   -55,   -17,   -17,   -53,
     -56,   -15,   -15,   -15,   -15,   -17,   -17,   -15,   -15,   -15,
     -15,   -15,   -15,   -15,   -15,   -57,   207,   208,   209,   210,
     -47,   -45,   -46,   212,   213,   -52,   -15,   -15,     9,     0,
     -25,   -25,   -25,   -25,   -15,   -15,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   122,   185,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -25,   -25,     0,     0,   -20,
     -20,   -20,   -20,   -25,   -25,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,     0,     0,     0,     0,     0,     0,     0,
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
     -21,   -21,     0,     0,   -18,   -18,   -18,   -18,   -21,   -21,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -18,
     -18,     0,     0,   -24,   -24,   -24,   -24,   -18,   -18,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -24,   -24,
       0,     0,    23,    24,    25,    26,   -24,   -24,    27,    28,
      29,    30,    31,    32,    33,    34,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,    36,     0,
       0,    23,    24,    25,    26,   137,    38,    27,    28,    29,
      30,    31,    32,    33,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    36,     0,     0,
     -36,   -36,   -36,   -36,   148,    38,   -36,   -36,   -36,   -36,
     -36,   -36,   -36,   -36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -36,   -36,     0,     0,    23,
      24,    25,    26,   -36,   -36,    27,    28,    29,    30,    31,
      32,    33,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,    36,     0,     0,    23,    24,
      25,    26,   152,    38,    27,    28,    29,    30,    31,    32,
      33,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    36,     0,     0,   -38,   -38,   -38,
     -38,   153,    38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,
     -38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -38,   -38,     0,     0,   -26,   -26,   -26,   -26,
     -38,   -38,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -26,   -26,     0,     0,    -7,    -7,    -7,    -7,   -26,
     -26,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    55,
       0,     0,     0,     0,   154,     0,     0,    30,    31,    32,
      -7,    -7,   155,   156,   157,     0,     0,   -63,    -7,    -7,
       0,     0,     0,    35,    36,   -63,   -63,   -63,   158,   159,
     -61,     0,    38,     0,     0,   -60,     0,   160,   -61,   -61,
     -61,   -63,   -63,   -60,   -60,   -60,     0,     0,   -59,     0,
     -63,     0,     0,     0,   -61,   -61,   -59,   -59,   -59,   -60,
     -60,   -62,     0,   -61,     0,     0,   -64,     0,   -60,   -62,
     -62,   -62,   -59,   -59,   -64,   -64,   -64,     0,     0,   -58,
       0,   -59,     0,     0,     0,   -62,   -62,   -58,   -58,   -58,
     -64,   -64,     0,     0,   -62,     0,     0,     0,     0,   -64,
       0,     0,     0,   -58,   -58,   -65,   -65,   -65,   -65,   -65,
     -65,   -65,   -58,     0,     0,     0,     0,   -65,     0,     0,
       0,    54,     0,     0,   -65,     0,   -65,   -65,   -65,   -65,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,     0,     0,     0,
       0,     0,   -67,     0,     0,     0,     0,     0,     0,   -67,
       0,   -67,   -67,   -67,   -67,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,     0,     0,     0,     0,     0,   -66,     0,     0,
       0,     0,     0,     0,   -66,     0,   -66,   -66,   -66,   -66,
      71,    72,    73,    74,    75,    76,    77,     0,     0,     0,
       0,     0,    78,     0,     0,     0,     0,     0,     0,   -42,
       0,    79,    80,    81,    82,   -65,   -65,   -65,   -65,   -65,
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
      71,    72,    73,    74,    75,    76,    77,     0,     0,     0,
       0,     0,   180,     0,     0,     0,     0,   -42,     0,     0,
       0,   181,   182,   183,   184,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,     0,     0,     0,     0,     0,   -68,     0,     0,
       0,     0,   -68,     0,     0,     0,   -68,   -68,   -68,   -68
};

static const yytype_int16 yycheck[] =
{
      25,   117,   118,   119,    38,     0,     3,     3,     3,    38,
       4,     0,     4,    38,     3,     0,     0,     3,     3,     3,
      54,    38,   138,    57,    37,     0,     4,    40,     3,     0,
      38,     4,    57,    38,    28,    29,    28,    29,     4,    64,
      57,    38,    38,    37,    38,    37,   123,    38,    35,    57,
      28,    29,     4,    78,    79,    80,    81,    82,    83,    37,
      40,    38,     0,   140,    38,     3,    57,    37,   145,    38,
     147,    38,    41,     0,    41,    38,     3,   111,    41,    38,
      37,    37,    41,    57,   200,   201,   202,    38,    38,    38,
      41,   207,    41,    37,    37,   120,     3,     4,     5,     6,
       7,   135,     9,    10,    11,    12,    13,    14,    15,    16,
     135,     0,    38,    38,     3,    41,    41,    37,   135,    37,
      37,    28,    29,    37,    40,    40,   160,   135,    40,    36,
      37,    40,    40,    31,    40,   160,   170,    40,    40,    40,
      31,    31,     4,   160,   135,   170,   180,   181,   182,   183,
     184,   185,   160,   170,    38,   180,   181,   182,   183,   184,
     185,   135,   170,   180,   181,   182,   183,   184,   185,   160,
      62,    63,   180,   181,   182,   183,   184,   185,    38,   170,
      38,    38,    38,    38,    17,    17,   160,    17,    12,   180,
     181,   182,   183,   184,   185,    17,   170,    17,    17,    17,
      40,    17,    40,    40,    40,    40,   180,   181,   182,   183,
     184,   185,    40,    40,    40,    40,     4,    40,    35,    40,
      17,    19,    37,    35,    38,   117,   118,   119,     3,     4,
       5,     6,   124,    38,     9,    10,    11,    12,    13,    14,
      15,    16,    38,    38,    38,    17,   138,    40,    40,    40,
      40,    38,    35,    28,    29,    35,    38,     3,     4,     5,
       6,    36,    37,     9,    10,    11,    12,    13,    14,    15,
      16,    38,    37,    37,    37,    12,    38,    38,    38,    38,
      38,    38,    28,    29,   176,   177,   178,    38,    38,    38,
      36,    37,     3,     4,     5,     6,    38,    37,     9,    10,
      11,    12,    13,    14,    15,    16,    38,   199,   200,   201,
     202,    17,    17,    17,    38,   207,    38,    28,    29,    38,
      38,     3,     4,     5,     6,    36,    37,     9,    10,    11,
      12,    13,    14,    15,    16,    38,    17,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    28,    29,     3,    -1,
       3,     4,     5,     6,    36,    37,     9,    10,    11,    12,
      13,    14,    15,    16,   111,   165,    -1,    -1,    -1,    -1,
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
      37,     9,    10,    11,    12,    13,    14,    15,    16,     4,
      -1,    -1,    -1,    -1,     4,    -1,    -1,    12,    13,    14,
      28,    29,    12,    13,    14,    -1,    -1,     4,    36,    37,
      -1,    -1,    -1,    28,    29,    12,    13,    14,    28,    29,
       4,    -1,    37,    -1,    -1,     4,    -1,    37,    12,    13,
      14,    28,    29,    12,    13,    14,    -1,    -1,     4,    -1,
      37,    -1,    -1,    -1,    28,    29,    12,    13,    14,    28,
      29,     4,    -1,    37,    -1,    -1,     4,    -1,    37,    12,
      13,    14,    28,    29,    12,    13,    14,    -1,    -1,     4,
      -1,    37,    -1,    -1,    -1,    28,    29,    12,    13,    14,
      28,    29,    -1,    -1,    37,    -1,    -1,    -1,    -1,    37,
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
      37,    40,    52,     3,    53,    54,    55,     4,    38,    41,
      35,    54,    56,     3,     4,     5,     6,     9,    10,    11,
      12,    13,    14,    15,    16,    28,    29,    36,    37,    50,
      57,    58,    59,    63,    64,    65,    66,    67,    68,    69,
      72,    73,    75,     4,    37,     4,    67,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    67,    40,    40,    40,
      40,    21,    22,    23,    24,    25,    26,    27,    33,    42,
      43,    44,    45,    74,    60,    61,    62,    75,    40,    67,
      31,    31,    31,     4,    28,    29,    37,    70,    71,    70,
      70,    67,     4,    38,    67,    67,    67,    67,    67,    67,
      38,    41,    38,    38,    38,    38,    12,    17,    17,    17,
      40,    17,    61,    35,    37,    70,    70,    70,    67,     4,
      56,    70,    38,    38,    38,    40,    38,    36,    17,    67,
      35,     7,    70,    38,    56,    35,    38,    35,    36,    56,
      38,    56,    36,    36,     4,    12,    13,    14,    28,    29,
      37,    68,    69,    72,    73,    75,    40,     4,    28,    29,
      37,     4,    28,    29,    37,    71,    37,    37,    37,    67,
      33,    42,    43,    44,    45,    74,    67,    12,    70,    70,
      70,    38,    67,    67,    67,    67,    67,    67,    38,    37,
      17,    17,    17,    70,    70,    70,    70,    17,    38,    38,
      38,    70,    38,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    52,    51,
      53,    54,    54,    54,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    58,    59,    60,    61,
      61,    61,    62,    63,    64,    64,    65,    66,    66,    67,
      67,    67,    67,    67,    68,    69,    69,    69,    70,    71,
      71,    71,    71,    72,    72,    72,    72,    73,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     0,     9,
       1,     3,     1,     0,     2,     2,     0,     1,     2,     1,
       1,     2,     2,     2,     3,     1,    11,     4,     1,     3,
       1,     0,     1,     4,     4,     4,     9,     7,    11,     1,
       1,     1,     1,     1,     3,     6,     6,     6,     1,     1,
       1,     1,     8,     3,     3,     3,     3,     3,     1,     1,
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
#line 77 "skylang.y"
                        {
		//printf("\nESCOPO ATUAL: %s\n",escopoAtual);
		if(passagem == 1){
			(yyval.tree) = add_tree_node("programa");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			tree = (yyval.tree);
		}
	}
#line 1779 "skylang.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 88 "skylang.y"
                                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 1791 "skylang.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 95 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 1802 "skylang.tab.c"
    break;

  case 5: /* declaration: variable_declaration  */
#line 103 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 1813 "skylang.tab.c"
    break;

  case 6: /* declaration: func_declaration  */
#line 109 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 1824 "skylang.tab.c"
    break;

  case 7: /* variable_declaration: TYPE ID SEMICOLON  */
#line 118 "skylang.y"
                          { 
						if(passagem == 1){
							insert_symbol(symbol_ID, (yyvsp[-1].str),"VARIAVEL",(yyvsp[-2].str), escopoAtual);
							symbol_ID = symbol_ID +1;
							//printf("\nAQUI %s\n",$2);
							(yyval.tree) = add_tree_node("variable_declaration - Type ID");
						}
						 
	}
#line 1838 "skylang.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 130 "skylang.y"
                               {escopoAtual = (yyvsp[-1].str);}
#line 1844 "skylang.tab.c"
    break;

  case 9: /* func_declaration: TYPE ID PARENTESES_INI $@1 params PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 130 "skylang.y"
                                                                                                          { 
																					if(passagem == 1){
																						insert_symbol(symbol_ID, (yyvsp[-7].str),"FUNCAO",(yyvsp[-8].str),escopoAtual );
																						symbol_ID = symbol_ID +1 ;																	
																						(yyval.tree) = add_tree_node("func_declaration");																		
																						(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
																						(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
																					}
																					//printf("\nESCOPO ATUAL: %s\n",escopoAtual);
	}
#line 1859 "skylang.tab.c"
    break;

  case 10: /* params: params_list  */
#line 143 "skylang.y"
                    { 
				if(passagem == 1){
					(yyval.tree) = add_tree_node("params");
		 			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
				}
	}
#line 1870 "skylang.tab.c"
    break;

  case 11: /* params_list: param COLON params_list  */
#line 151 "skylang.y"
                                {
							if(passagem == 1){ 
								(yyval.tree) = add_tree_node("params_list_n");
		 						(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
							  	(yyval.tree) -> leaf2 = (yyvsp[0].tree);
							}
	}
#line 1882 "skylang.tab.c"
    break;

  case 12: /* params_list: param  */
#line 158 "skylang.y"
               { 
			if(passagem == 1){
				(yyval.tree) = add_tree_node("params_lis_1");
		 	 	(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			}
	}
#line 1893 "skylang.tab.c"
    break;

  case 13: /* params_list: %empty  */
#line 164 "skylang.y"
         { 
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	}
#line 1903 "skylang.tab.c"
    break;

  case 14: /* param: TYPE ID  */
#line 171 "skylang.y"
                { 
				if(passagem == 1){
					insert_symbol(symbol_ID, (yyvsp[0].str),"PARAMETRO_FUNCAO",(yyvsp[-1].str),escopoAtual);
		    		symbol_ID = symbol_ID +1;
			 		(yyval.tree) = add_tree_node("param - TYPE ID");
				}
	}
#line 1915 "skylang.tab.c"
    break;

  case 15: /* codeBlock: codeBlock statement  */
#line 180 "skylang.y"
                           {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("codeBlock");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 1927 "skylang.tab.c"
    break;

  case 16: /* codeBlock: %empty  */
#line 187 "skylang.y"
          {	
		if(passagem == 1){
			(yyval.tree) = add_tree_node("codeBlock VAZIO");
		}
		 
	}
#line 1938 "skylang.tab.c"
    break;

  case 17: /* statement: variable_declaration  */
#line 197 "skylang.y"
                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 1949 "skylang.tab.c"
    break;

  case 18: /* statement: exp SEMICOLON  */
#line 204 "skylang.y"
                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 1960 "skylang.tab.c"
    break;

  case 19: /* statement: ifStatement  */
#line 210 "skylang.y"
                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 1971 "skylang.tab.c"
    break;

  case 20: /* statement: forAllStatement  */
#line 216 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 1982 "skylang.tab.c"
    break;

  case 21: /* statement: outPutStatement SEMICOLON  */
#line 222 "skylang.y"
                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 1993 "skylang.tab.c"
    break;

  case 22: /* statement: inputStatement SEMICOLON  */
#line 228 "skylang.y"
                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2004 "skylang.tab.c"
    break;

  case 23: /* statement: callFuncStatement SEMICOLON  */
#line 234 "skylang.y"
                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2015 "skylang.tab.c"
    break;

  case 24: /* statement: RETURN exp SEMICOLON  */
#line 241 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("RETURN statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2026 "skylang.tab.c"
    break;

  case 25: /* statement: forStatement  */
#line 248 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forStatement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2037 "skylang.tab.c"
    break;

  case 26: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 258 "skylang.y"
                                                                                                                 {
			if(passagem == 1){
				(yyval.tree) = add_tree_node("ForStatement");
				(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
				(yyval.tree) -> leaf2 = (yyvsp[-6].tree);
				(yyval.tree) -> leaf3 = (yyvsp[-4].tree);
				(yyval.tree) -> leaf4 = (yyvsp[-1].tree);
			}
	}
#line 2051 "skylang.tab.c"
    break;

  case 27: /* callFuncStatement: ID PARENTESES_INI call_params PARENTESES_FIM  */
#line 272 "skylang.y"
                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallFunStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	}
#line 2062 "skylang.tab.c"
    break;

  case 28: /* call_params: call_params_list  */
#line 282 "skylang.y"
                        {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallParams");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2073 "skylang.tab.c"
    break;

  case 29: /* call_params_list: call_param COLON call_params_list  */
#line 290 "skylang.y"
                                          {
		if(passagem == 1){ 
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2085 "skylang.tab.c"
    break;

  case 30: /* call_params_list: call_param  */
#line 297 "skylang.y"
                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2096 "skylang.tab.c"
    break;

  case 31: /* call_params_list: %empty  */
#line 303 "skylang.y"
         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	 }
#line 2106 "skylang.tab.c"
    break;

  case 32: /* call_param: terminal  */
#line 310 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_param terminal");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2117 "skylang.tab.c"
    break;

  case 33: /* inputStatement: READ PARENTESES_INI STRING PARENTESES_FIM  */
#line 320 "skylang.y"
                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("inputStatement");	 
			//$$ -> leaf1 = $3;
		}
	}
#line 2128 "skylang.tab.c"
    break;

  case 34: /* outPutStatement: WRITE PARENTESES_INI STRING PARENTESES_FIM  */
#line 330 "skylang.y"
                                                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("outPutStatement");
			//$$ -> leaf1 = $3;
		}
	 }
#line 2139 "skylang.tab.c"
    break;

  case 35: /* outPutStatement: WRITELN PARENTESES_INI STRING PARENTESES_FIM  */
#line 336 "skylang.y"
                                                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("outPutStatement");
			//$$ -> leaf1 = $3;
		}
	 }
#line 2150 "skylang.tab.c"
    break;

  case 36: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 346 "skylang.y"
                                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forAllStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[-6].str));
			if(existe_simbolo != 1){
				printf("\nERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}
			existe_simbolo = searchSymbol((yyvsp[-4].str));
			if(existe_simbolo != 1){
				printf("\nERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}
		}
	 }
#line 2171 "skylang.tab.c"
    break;

  case 37: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 366 "skylang.y"
                                                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	 }
#line 2183 "skylang.tab.c"
    break;

  case 38: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM ELSE CHAVES_INI codeBlock CHAVES_FIM  */
#line 373 "skylang.y"
                                                                                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-5].tree);
			(yyval.tree) -> leaf3 = (yyvsp[-1].tree);
		}
	 }
#line 2196 "skylang.tab.c"
    break;

  case 39: /* exp: setExp  */
#line 384 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2207 "skylang.tab.c"
    break;

  case 40: /* exp: aritExp  */
#line 390 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2218 "skylang.tab.c"
    break;

  case 41: /* exp: relExp  */
#line 396 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2229 "skylang.tab.c"
    break;

  case 42: /* exp: terminal  */
#line 402 "skylang.y"
                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2240 "skylang.tab.c"
    break;

  case 43: /* exp: assignmentExp  */
#line 409 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2251 "skylang.tab.c"
    break;

  case 44: /* assignmentExp: terminal EQUALS exp  */
#line 418 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("assigmentExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2263 "skylang.tab.c"
    break;

  case 45: /* setExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 428 "skylang.y"
                                                                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 2275 "skylang.tab.c"
    break;

  case 46: /* setExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 435 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 2287 "skylang.tab.c"
    break;

  case 47: /* setExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 442 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 2299 "skylang.tab.c"
    break;

  case 48: /* terms_set: aritSetExp  */
#line 452 "skylang.y"
                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terms_set");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2310 "skylang.tab.c"
    break;

  case 49: /* aritSetExp: ID  */
#line 461 "skylang.y"
           {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal ID");
		}
		 
		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[0].str));
			if(existe_simbolo != 1){
				printf("\nERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}
		}

	 }
#line 2328 "skylang.tab.c"
    break;

  case 50: /* aritSetExp: FLOAT  */
#line 474 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal FLOAT");
		}
		 
	 }
#line 2339 "skylang.tab.c"
    break;

  case 51: /* aritSetExp: INTEGER  */
#line 480 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal INTEGER");
		}
		 
	 }
#line 2350 "skylang.tab.c"
    break;

  case 52: /* aritSetExp: PARENTESES_INI EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM PARENTESES_FIM  */
#line 486 "skylang.y"
                                                                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
		}
	}
#line 2362 "skylang.tab.c"
    break;

  case 53: /* aritExp: terminal MULT exp  */
#line 497 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	 }
#line 2374 "skylang.tab.c"
    break;

  case 54: /* aritExp: terminal PLUS exp  */
#line 504 "skylang.y"
                           {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	 }
#line 2386 "skylang.tab.c"
    break;

  case 55: /* aritExp: terminal MINUS exp  */
#line 511 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	 }
#line 2398 "skylang.tab.c"
    break;

  case 56: /* aritExp: terminal DIV exp  */
#line 518 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	 }
#line 2410 "skylang.tab.c"
    break;

  case 57: /* relExp: terminal rel exp  */
#line 527 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("relExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
		}
	 }
#line 2423 "skylang.tab.c"
    break;

  case 58: /* rel: CGE  */
#line 538 "skylang.y"
            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel CGE");
		}
	 }
#line 2433 "skylang.tab.c"
    break;

  case 59: /* rel: CGT  */
#line 543 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 2443 "skylang.tab.c"
    break;

  case 60: /* rel: CNE  */
#line 548 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 2453 "skylang.tab.c"
    break;

  case 61: /* rel: CLT  */
#line 553 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 2463 "skylang.tab.c"
    break;

  case 62: /* rel: AND  */
#line 558 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 2473 "skylang.tab.c"
    break;

  case 63: /* rel: CLE  */
#line 563 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 2483 "skylang.tab.c"
    break;

  case 64: /* rel: CEQ  */
#line 568 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel CEQ");
		}
	}
#line 2493 "skylang.tab.c"
    break;

  case 65: /* terminal: ID  */
#line 577 "skylang.y"
           {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal ID");
			
		}
		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[0].str));
			if(existe_simbolo != 1){
				printf("\nERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}
		}
		 
	 }
#line 2511 "skylang.tab.c"
    break;

  case 66: /* terminal: FLOAT  */
#line 590 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal FLOAT");
		}
		 
	 }
#line 2522 "skylang.tab.c"
    break;

  case 67: /* terminal: INTEGER  */
#line 596 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal INTEGER");
		}
		 
	 }
#line 2533 "skylang.tab.c"
    break;

  case 68: /* terminal: PARENTESES_INI exp PARENTESES_FIM  */
#line 603 "skylang.y"
                                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal EXP");
			(yyval.tree)->leaf1 =(yyvsp[-1].tree);
		}
	}
#line 2544 "skylang.tab.c"
    break;


#line 2548 "skylang.tab.c"

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

#line 612 "skylang.y"


extern void yyerror(const char* a) {
    printf("\n-->ERRO SINTATICO na linha %d, coluna %d\n",num_linha,posicao_linha);
	printf("-->  %s\n",a);
}


int main(){
char fname[100];
    scanf("%s",fname);
    yyin=fopen(fname,"r+");
	passagem=1;
	printf("\n========== Primeira Passagem ===========\n\n");
    yyparse();
    //yylex();
	fclose(yyin);
	printf("\n---------> Tabela de Simbolos <---------\n");
	printTS();
	printf("\n");
	printf("\n---------> ARVORE: <---------\n");
	print_tree(0,tree);
	printf("\n");
	passagem=2;
	yyin=fopen(fname,"r+");
	printf("\n========== Segunda Passagem ===========\n\n");
	yyparse();
	fclose(yyin);
	free_tree(tree);
    yylex_destroy();
    return 0;
}



