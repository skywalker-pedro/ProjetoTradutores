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

/////////////////////////////////// Variaveis de controle de escolpo, declaracao e checagem de tipos
int existe_simbolo;
int existe_main = 0;
char * redeclaracao_funcao;
int flag_redeclaracao_funcao;
int registrador_atual = 0;
//int erro_count = 0;
int aux=1;
int escopo_correto;
int argumento_func;
//////////////////////////////////
char * escopoAtual = "Global";
/* Print TS Function*/
void printTS(){
	Hash_table* aux = hashed_symbol_table;
    while(aux!=NULL){
        printf("\n Id simbolo: %d | Nome simbolo: %s | Tipo simbolo: %s %s | Escopo: %s | Registrador: $%d",aux->id,aux->name,aux->type,aux->varType, aux -> escopo,aux -> registrador);
        aux = aux -> hh.next;
    }
	//free(aux);
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
	//free(aux);
	if(retorno == 1){
		return 1;
	}else{
		return 0;
	}
}

//Search symbol type in symbol table
char * searchVarType(char*symbol,char*symbol_scope){
	Hash_table* aux = hashed_symbol_table;
    while(aux!=NULL){
		//strcmp retorna 0 caso as strings sejam iguais
        if (strcmp(aux->name,symbol)==0){
			if (strcmp(aux->escopo,symbol_scope)==0){
				return aux -> varType;
			}
		}
        aux = aux -> hh.next;
    }
	return NULL;
	//free(aux);
}


//Search symbol scope in symbol table
int searchScope(char*symbol,char*symbol_scope){
	Hash_table* aux = hashed_symbol_table;
	int retorno = 0;
    while(aux!=NULL){
		//strcmp retorna 0 caso as strings sejam iguais
        if (strcmp(aux->name,symbol)==0){
			if (strcmp(aux->escopo,"Global")==0){
				retorno = 1;
			}
			if (strcmp(aux->escopo,symbol_scope)==0){
				retorno = 1;
			}
		}
        aux = aux -> hh.next;
    }
	//free(aux);
	if(retorno == 1){
		return 1;
	}else{
		return 0;
	}
}

//Check if parameters in function call are correct
int searchFunctionVariable(char*symbol,char*symbol_scope){
	Hash_table* aux = hashed_symbol_table;
	int retorno = 0;
	char * tipo_variavel;
	tipo_variavel = searchVarType(symbol,symbol_scope);
    while(aux!=NULL){
		//strcmp retorna 0 caso as strings sejam iguais
        if (strcmp(aux->name,symbol_scope)==0){
			if (strcmp(aux-> varType,tipo_variavel)==0){
				retorno = 1;
			}
		}
        aux = aux -> hh.next;
    }
	//free(aux);
	if(retorno == 1){
		return 1;
	}else{
		return 0;
	}
}




#line 197 "skylang.tab.c"

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
  YYSYMBOL_THEN = 46,                      /* THEN  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_programa = 48,                  /* programa  */
  YYSYMBOL_declarationList = 49,           /* declarationList  */
  YYSYMBOL_declaration = 50,               /* declaration  */
  YYSYMBOL_variable_declaration = 51,      /* variable_declaration  */
  YYSYMBOL_func_declaration = 52,          /* func_declaration  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_params = 54,                    /* params  */
  YYSYMBOL_params_list = 55,               /* params_list  */
  YYSYMBOL_param = 56,                     /* param  */
  YYSYMBOL_codeBlock = 57,                 /* codeBlock  */
  YYSYMBOL_statement_list = 58,            /* statement_list  */
  YYSYMBOL_statement = 59,                 /* statement  */
  YYSYMBOL_forStatement = 60,              /* forStatement  */
  YYSYMBOL_callFuncStatement = 61,         /* callFuncStatement  */
  YYSYMBOL_call_params = 62,               /* call_params  */
  YYSYMBOL_call_params_list = 63,          /* call_params_list  */
  YYSYMBOL_call_param = 64,                /* call_param  */
  YYSYMBOL_inputStatement = 65,            /* inputStatement  */
  YYSYMBOL_outPutStatement = 66,           /* outPutStatement  */
  YYSYMBOL_forAllStatement = 67,           /* forAllStatement  */
  YYSYMBOL_ifStatement = 68,               /* ifStatement  */
  YYSYMBOL_exp = 69,                       /* exp  */
  YYSYMBOL_assignmentExp = 70,             /* assignmentExp  */
  YYSYMBOL_setExp = 71,                    /* setExp  */
  YYSYMBOL_terms_set = 72,                 /* terms_set  */
  YYSYMBOL_aritSetExp = 73,                /* aritSetExp  */
  YYSYMBOL_aritExp = 74,                   /* aritExp  */
  YYSYMBOL_relExp = 75,                    /* relExp  */
  YYSYMBOL_rel = 76,                       /* rel  */
  YYSYMBOL_terminal = 77                   /* terminal  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2254

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  363

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   158,   158,   169,   176,   192,   198,   207,   221,   231,
     231,   267,   275,   282,   288,   302,   313,   329,   334,   344,
     351,   357,   363,   369,   375,   381,   388,   395,   405,   419,
     437,   445,   452,   459,   466,   480,   490,   497,   504,   510,
     518,   525,   535,   565,   572,   585,   592,   598,   604,   610,
     617,   626,   636,   643,   650,   660,   669,   687,   693,   699,
     710,   717,   724,   731,   740,   751,   756,   761,   766,   771,
     776,   781,   790,   808,   814,   821
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
  "PLUS", "MINUS", "MULT", "DIV", "THEN", "$accept", "programa",
  "declarationList", "declaration", "variable_declaration",
  "func_declaration", "$@1", "params", "params_list", "param", "codeBlock",
  "statement_list", "statement", "forStatement", "callFuncStatement",
  "call_params", "call_params_list", "call_param", "inputStatement",
  "outPutStatement", "forAllStatement", "ifStatement", "exp",
  "assignmentExp", "setExp", "terms_set", "aritSetExp", "aritExp",
  "relExp", "rel", "terminal", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,    22,    12,    20,    28,   207,   211,   220,   -29,  -117,
     235,     3,   239,     4,    46,    -6,    34,    -8,   147,    45,
       4,  1209,    48,    52,  1246,   272,    92,  1984,   158,    67,
      81,    85,    86,    94,    98,   101,   104,   106,  2009,  2034,
     158,   190,  1283,  1320,  1357,    93,   110,   114,  1394,  1431,
     115,   119,   121,   123,   128,  2059,   135,    -2,  2084,   136,
     190,    63,   152,   187,    61,    61,    61,   158,   188,   153,
     171,  1468,  1505,  1542,  1579,   345,   533,   601,   636,  1941,
    1954,  1967,   158,   158,   158,   158,   158,   158,   179,   186,
     216,   223,  1616,   192,   193,   199,   203,   205,   212,   228,
     230,   209,   260,   261,   268,   267,   269,   281,   285,   245,
     288,  2109,   266,   270,   271,   275,   276,   282,   284,    -2,
    1838,   289,   300,   304,   310,   311,   315,   316,   191,    97,
      97,    97,   158,   303,   279,    42,    61,   290,   308,   322,
     321,   324,  1868,   291,   323,   325,   329,   190,   274,  1653,
      97,   332,  1898,   333,   337,   339,   338,  1898,  1690,   361,
     343,  1727,  1764,   530,   344,   346,   347,  2134,  2159,   190,
     190,   342,   348,   349,   350,  2184,  1801,   238,   255,   256,
     190,   455,   381,   158,   352,   353,   360,   689,   728,   358,
     359,   362,   765,   802,   369,   363,   375,   376,   403,   378,
     382,   415,   158,   383,   384,   386,   389,   390,   387,   388,
     393,   398,   399,   396,    61,    61,    61,   391,   400,   190,
     190,   190,   190,   190,   190,   402,   397,   401,   190,   158,
     438,   839,   876,   913,   950,   406,   404,   405,   190,   158,
     444,   414,   416,   419,   427,   434,   456,   457,  2209,   440,
     441,   442,   443,   450,   465,   262,   987,  1024,   466,   432,
     468,    61,   459,   470,   469,   453,   491,    97,    97,    97,
    1838,   158,   505,   493,  1928,   158,   507,   476,   478,   480,
    1061,   479,   482,    97,    33,   518,   158,   486,   487,   494,
      66,    74,    75,   492,   495,   496,    76,    77,   498,   501,
     504,   510,   511,   520,  1838,   190,   508,   521,   524,   526,
     190,   158,   556,  1898,    78,    80,    96,   100,   190,   534,
    1098,   541,  1898,   542,   122,   133,   543,   544,   568,   550,
     558,  1898,   553,   563,   562,  1928,   158,   598,   569,   567,
    1898,  1135,   137,   566,   571,  1898,   576,   581,  1928,   190,
     572,   582,  1172,   138,   583,  1898,   584,   587,   589,  1898,
     141,   591,   142
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
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
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,  -117,   619,     0,  -117,  -117,  -117,   611,  -117,
    -117,  -117,   297,   -21,   -15,  -117,   515,  -117,   -14,   -12,
      -5,    -3,   -23,   184,   277,   447,  -116,   306,   370,   460,
     172
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,   206,     7,    13,    15,    16,    17,
      23,    24,    43,   207,   208,    88,    89,    90,   209,   210,
     211,   212,   213,    51,    52,   105,   106,    53,    54,    87,
      55
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    50,   177,    44,     6,    59,    -9,    14,    11,    45,
      46,    12,    47,   199,   199,   199,     8,    69,    70,    48,
       9,    49,    -8,    -8,    42,    -8,   178,   179,    -2,     1,
     -13,     2,    19,    20,   199,   180,   -33,    93,    96,    99,
      -8,    -9,   -14,   -43,   109,   -43,   -43,   -43,   -43,   142,
      18,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   112,
     113,   114,   115,   116,   117,   101,     1,   163,     2,    -8,
     -43,   -43,   -11,   -19,   -43,   164,   165,   166,   -43,   -43,
      21,   313,   -27,   -22,   -21,   -25,   -12,   -24,    25,   102,
     103,   167,   168,    94,    95,   169,    56,   194,   104,   188,
     170,   195,   -19,   -23,    60,   189,   190,   -20,   191,   140,
     -43,   -27,   -22,   -21,   -25,   192,   -24,   193,    61,    50,
     187,    44,    62,    63,   151,   196,   197,    45,    46,    -7,
      47,    64,   -23,    71,   198,    65,   -20,    48,    66,    49,
     -26,    67,    42,    68,   348,   -44,   217,   218,   -42,   -28,
      72,   199,   199,   199,    73,    74,   163,   225,    -7,   -50,
     227,   -46,    58,   -47,   164,   165,   166,   199,   -48,   -26,
      33,    34,    35,   -43,   -44,   176,    92,   -42,   -28,   237,
     167,   168,    97,    98,   169,   -15,    38,    39,   -15,   170,
      40,   100,   110,   -45,   163,    41,   249,   250,   251,   252,
     253,   254,   164,   165,   166,   258,   259,    -4,    -4,   111,
      -4,    -5,    -5,   175,    -5,   264,   265,   118,   167,   168,
      -6,    -6,   169,    -6,   -30,   171,   -56,   170,   136,    91,
     120,   121,   175,   175,   175,    -3,    -3,   122,    -3,    -7,
      -7,   123,    -7,   124,   171,   171,   171,   194,   281,   188,
     125,   298,   299,   292,   -32,   189,   190,   119,   191,   293,
     294,   -34,   295,   309,   -34,   192,   126,   193,   127,   296,
     187,   297,   -10,   -10,   290,   -10,   -72,   -58,   -57,   -72,
     128,   194,   321,   188,   129,   132,   -55,   326,   327,   189,
     190,    91,   191,   -74,   -73,   330,   -74,   -73,   130,   192,
     -75,   193,   131,   -75,   187,   133,   -51,   141,   150,   152,
     -61,   -62,   298,   343,   292,   -60,   -63,   -31,   172,   175,
     293,   294,   -64,   295,   -29,   298,   354,   292,   144,   -37,
     296,   171,   297,   293,   294,   290,   295,   172,   172,   172,
     -36,   175,   175,   296,   -38,   297,   145,   173,   290,   -70,
     -40,   -39,   175,   171,   171,   -41,   -35,   -70,   -70,   -70,
     146,   147,   148,   -54,   171,   -52,   173,   173,   173,   -53,
     154,   156,   157,   -70,   -70,   158,   159,   -70,   -59,   161,
     -50,   214,   -70,   215,   216,   226,   -46,   -47,   -48,   228,
     229,   175,   175,   175,   175,   175,   175,   230,   231,   232,
     175,   -56,   233,   171,   171,   171,   171,   171,   171,   234,
     175,   174,   171,   -58,   -57,   235,   -55,   135,    -8,   236,
     238,   239,   171,   240,   172,   -19,   -27,   241,   242,   -45,
     174,   174,   174,   243,   -22,   -21,   244,   256,   248,   149,
     255,   257,   260,   261,   262,   263,   172,   172,   266,   155,
     -25,   267,   -24,   173,   160,   -23,    -8,   172,    -8,    -8,
      -8,    -8,    -8,   -20,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,   271,   268,   269,   173,   173,   175,   -51,   -61,
     -62,   -60,   175,    -8,    -8,   272,   173,    -8,   -63,   171,
     175,    -8,    -8,   275,   171,    -7,   172,   172,   172,   172,
     172,   172,   171,   -64,   270,   172,   -26,   274,   276,   282,
     283,   300,   107,   108,   301,   172,   302,   174,   303,   305,
     306,   175,   308,   310,   311,   173,   173,   173,   173,   173,
     173,   312,   314,   171,   173,   315,   316,   -68,   317,   174,
     174,   318,   319,   322,   173,   -68,   -68,   -68,   -54,   -52,
     174,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -53,   323,
     328,   -68,   -68,   -72,   324,   -68,   325,   280,   -72,   331,
     -68,   291,   -72,   -72,   -72,   -72,   137,   138,   139,   332,
     334,   335,   172,   143,   336,   337,   -44,   172,   340,   174,
     174,   174,   174,   174,   174,   172,   338,   153,   174,   341,
     -59,   320,   344,   346,   345,   -67,   349,   355,   174,   350,
     329,   173,   -42,   -67,   -67,   -67,   173,   352,   356,   333,
     -28,   357,   359,    10,   173,   360,   172,   362,   339,   -67,
     -67,    22,   342,   -67,   134,   224,     0,   347,   -67,     0,
     -66,     0,   351,     0,     0,   353,     0,     0,   -66,   -66,
     -66,     0,   358,     0,     0,   173,   361,     0,     0,     0,
       0,   245,   246,   247,   -66,   -66,     0,     0,   -66,     0,
       0,     0,     0,   -66,     0,   174,     0,     0,     0,     0,
     174,     0,     0,     0,     0,     0,     0,     0,   174,     0,
     -19,     0,   -19,   -19,   -19,   -19,   -19,     0,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,     0,     0,   273,     0,
       0,     0,     0,     0,   277,   278,   279,   -19,   -19,   174,
       0,   -19,     0,     0,     0,   -19,   -19,     0,     0,   -27,
     307,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -27,   -27,     0,     0,
     -27,     0,     0,     0,   -27,   -27,   -22,     0,   -22,   -22,
     -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -22,   -22,     0,     0,   -22,     0,     0,
       0,   -22,   -22,   -21,     0,   -21,   -21,   -21,   -21,   -21,
       0,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -21,   -21,     0,     0,   -21,     0,     0,     0,   -21,   -21,
     -25,     0,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -25,   -25,     0,
       0,   -25,     0,     0,     0,   -25,   -25,   -24,     0,   -24,
     -24,   -24,   -24,   -24,     0,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -24,   -24,     0,     0,   -24,     0,
       0,     0,   -24,   -24,   -23,     0,   -23,   -23,   -23,   -23,
     -23,     0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -23,   -23,     0,     0,   -23,     0,     0,     0,   -23,
     -23,   -20,     0,   -20,   -20,   -20,   -20,   -20,     0,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -20,   -20,
       0,     0,   -20,     0,     0,     0,   -20,   -20,    -7,     0,
      -7,    -7,    -7,    -7,    -7,     0,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,    -7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -7,    -7,     0,     0,    -7,
       0,     0,     0,    -7,    -7,   -26,     0,   -26,   -26,   -26,
     -26,   -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -26,   -26,     0,     0,   -26,     0,     0,     0,
     -26,   -26,   -43,     0,   -43,   -43,   -43,   -43,   304,     0,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -43,
     -43,     0,     0,   -43,     0,     0,     0,   -43,   -43,   -44,
       0,   -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -44,   -44,     0,     0,
     -44,     0,     0,     0,   -44,   -44,   -42,     0,   -42,   -42,
     -42,   -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -42,   -42,     0,     0,   -42,     0,     0,
       0,   -42,   -42,   -28,     0,   -28,   -28,   -28,   -28,   -28,
       0,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -28,   -28,     0,     0,   -28,     0,     0,     0,   -28,   -28,
     -18,     0,   -18,   -18,   -18,   -18,     0,     0,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -18,   -18,     0,
       0,   -18,     0,     0,     0,   -18,   -18,   162,     0,    26,
      27,    28,    29,     0,     0,    30,    31,    32,    33,    34,
      35,    36,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,     0,     0,    40,     0,
       0,     0,   -16,    41,   -19,     0,   -19,   -19,   -19,   -19,
       0,     0,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -19,   -19,     0,     0,   -19,     0,     0,     0,   -19,
     -19,   -17,     0,   -17,   -17,   -17,   -17,     0,     0,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -17,   -17,
       0,     0,   -17,     0,     0,     0,   -17,   -17,   -27,     0,
     -27,   -27,   -27,   -27,     0,     0,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -27,   -27,     0,     0,   -27,
       0,     0,     0,   -27,   -27,   -22,     0,   -22,   -22,   -22,
     -22,     0,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -22,   -22,     0,     0,   -22,     0,     0,     0,
     -22,   -22,   -21,     0,   -21,   -21,   -21,   -21,     0,     0,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -21,
     -21,     0,     0,   -21,     0,     0,     0,   -21,   -21,   -25,
       0,   -25,   -25,   -25,   -25,     0,     0,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -25,   -25,     0,     0,
     -25,     0,     0,     0,   -25,   -25,   -24,     0,   -24,   -24,
     -24,   -24,     0,     0,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -24,   -24,     0,     0,   -24,     0,     0,
       0,   -24,   -24,   -23,     0,   -23,   -23,   -23,   -23,     0,
       0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -23,   -23,     0,     0,   -23,     0,     0,     0,   -23,   -23,
     -20,     0,   -20,   -20,   -20,   -20,     0,     0,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -20,   -20,     0,
       0,   -20,     0,     0,     0,   -20,   -20,   -26,     0,   -26,
     -26,   -26,   -26,     0,     0,   -26,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -26,   -26,     0,     0,   -26,     0,
       0,     0,   -26,   -26,   -44,     0,   -44,   -44,   -44,   -44,
       0,     0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -44,   -44,     0,     0,   -44,     0,     0,     0,   -44,
     -44,   -42,     0,   -42,   -42,   -42,   -42,     0,     0,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -42,   -42,
       0,     0,   -42,     0,     0,     0,   -42,   -42,   -28,     0,
     -28,   -28,   -28,   -28,     0,     0,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -28,   -28,     0,     0,   -28,
       0,     0,     0,   -28,   -28,    -8,     0,    -8,    -8,    -8,
      -8,     0,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -8,    -8,     0,     0,    -8,     0,     0,     0,
      -8,    -8,    -7,     0,    -7,    -7,    -7,    -7,     0,     0,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    -7,
      -7,     0,     0,    -7,     0,     0,     0,    -7,    -7,   181,
       0,   182,    27,   183,   184,     0,     0,    30,    31,    32,
      33,    34,    35,   185,   186,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,     0,   162,
      40,    26,    27,    28,    29,    41,     0,    30,    31,    32,
      33,    34,    35,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,     0,   200,
      40,   201,    27,   202,   203,    41,     0,    30,    31,    32,
      33,    34,    35,   204,   205,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,     0,   284,
      40,   285,    27,   286,   287,    41,     0,    30,    31,    32,
      33,    34,    35,   288,   289,   -69,     0,     0,     0,     0,
       0,     0,     0,   -69,   -69,   -69,    38,    39,   -71,     0,
      40,     0,     0,     0,     0,    41,   -71,   -71,   -71,   -69,
     -69,   -65,     0,   -69,     0,     0,     0,     0,   -69,   -65,
     -65,   -65,   -71,   -71,     0,     0,   -71,     0,     0,     0,
       0,   -71,     0,     0,     0,   -65,   -65,     0,     0,   -65,
       0,     0,     0,     0,   -65,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,     0,     0,     0,     0,     0,   -72,     0,     0,
       0,    57,     0,     0,   -72,     0,   -72,   -72,   -72,   -72,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,     0,
       0,     0,   -74,     0,     0,     0,     0,     0,     0,   -74,
       0,   -74,   -74,   -74,   -74,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,     0,     0,     0,     0,     0,   -73,     0,     0,
       0,     0,     0,     0,   -73,     0,   -73,   -73,   -73,   -73,
      75,    76,    77,    78,    79,    80,    81,     0,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,     0,   -49,
       0,    83,    84,    85,    86,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,     0,     0,     0,     0,     0,   -72,     0,     0,
       0,     0,     0,     0,   -72,     0,   -72,   -72,   -72,   -72,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,
       0,     0,   -75,     0,     0,     0,     0,     0,     0,   -75,
       0,   -75,   -75,   -75,   -75,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,     0,     0,     0,     0,     0,   -74,     0,     0,
       0,     0,   -74,     0,     0,     0,   -74,   -74,   -74,   -74,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,     0,     0,     0,
       0,     0,   -73,     0,     0,     0,     0,   -73,     0,     0,
       0,   -73,   -73,   -73,   -73,    75,    76,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,   219,     0,     0,
       0,     0,   -49,     0,     0,     0,   220,   221,   222,   223,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,     0,     0,
       0,     0,   -75,     0,     0,     0,     0,   -75,     0,     0,
       0,   -75,   -75,   -75,   -75
};

static const yytype_int16 yycheck[] =
{
       0,    24,     4,    24,     4,    28,     3,     3,    37,    24,
      24,    40,    24,   129,   130,   131,     4,    40,    41,    24,
       0,    24,     0,     1,    24,     3,    28,    29,     0,     1,
      38,     3,    38,    41,   150,    37,    38,    60,    61,    62,
       7,    38,    38,     1,    67,     3,     4,     5,     6,     7,
       4,     9,    10,    11,    12,    13,    14,    15,    16,    82,
      83,    84,    85,    86,    87,     4,     1,     4,     3,    36,
      28,    29,    38,     7,    32,    12,    13,    14,    36,    37,
      35,     7,     7,     7,     7,     7,    38,     7,    36,    28,
      29,    28,    29,    30,    31,    32,     4,   120,    37,   120,
      37,     4,    36,     7,    37,   120,   120,     7,   120,   132,
      36,    36,    36,    36,    36,   120,    36,   120,    37,   142,
     120,   142,    37,    37,   147,    28,    29,   142,   142,     7,
     142,    37,    36,    40,    37,    37,    36,   142,    37,   142,
       7,    37,   142,    37,     7,     7,   169,   170,     7,     7,
      40,   267,   268,   269,    40,    40,     4,   180,    36,    40,
     183,    40,     4,    40,    12,    13,    14,   283,    40,    36,
      12,    13,    14,    36,    36,    40,    40,    36,    36,   202,
      28,    29,    30,    31,    32,    38,    28,    29,    41,    37,
      32,     4,     4,    40,     4,    37,   219,   220,   221,   222,
     223,   224,    12,    13,    14,   228,   229,     0,     1,    38,
       3,     0,     1,    41,     3,   238,   239,    38,    28,    29,
       0,     1,    32,     3,    38,    41,    17,    37,    37,    57,
      38,    38,    60,    61,    62,     0,     1,    38,     3,     0,
       1,    38,     3,    38,    60,    61,    62,   270,   271,   270,
      38,   274,   275,   274,    38,   270,   270,    41,   270,   274,
     274,    38,   274,   286,    41,   270,    38,   270,    38,   274,
     270,   274,     0,     1,   274,     3,    38,    17,    17,    41,
      12,   304,   305,   304,    17,    40,    17,   310,   311,   304,
     304,   119,   304,    38,    38,   318,    41,    41,    17,   304,
      38,   304,    17,    41,   304,    17,    40,     4,    17,    35,
      40,    40,   335,   336,   335,    40,    40,    38,    41,   147,
     335,   335,    40,   335,    40,   348,   349,   348,    38,    40,
     335,   147,   335,   348,   348,   335,   348,    60,    61,    62,
      40,   169,   170,   348,    40,   348,    38,    41,   348,     4,
      40,    40,   180,   169,   170,    40,    40,    12,    13,    14,
      38,    40,    38,    40,   180,    40,    60,    61,    62,    40,
      38,    38,    35,    28,    29,    36,    38,    32,    17,    36,
      38,    37,    37,    37,    37,     4,    38,    38,    38,    37,
      37,   219,   220,   221,   222,   223,   224,    37,    40,    40,
     228,    38,    40,   219,   220,   221,   222,   223,   224,    40,
     238,    41,   228,    38,    38,    12,    38,   120,    36,     4,
      37,    37,   238,    37,   147,    36,    36,    40,    40,    38,
      60,    61,    62,    40,    36,    36,    40,    40,    38,   142,
      38,    40,     4,    37,    40,    40,   169,   170,     4,   152,
      36,    17,    36,   147,   157,    36,     1,   180,     3,     4,
       5,     6,     7,    36,     9,    10,    11,    12,    13,    14,
      15,    16,    40,    17,    17,   169,   170,   305,    38,    38,
      38,    38,   310,    28,    29,    17,   180,    32,    38,   305,
     318,    36,    37,    40,   310,    36,   219,   220,   221,   222,
     223,   224,   318,    38,    38,   228,    36,    38,    17,     4,
      17,     4,    65,    66,    38,   238,    38,   147,    38,    40,
      38,   349,     4,    37,    37,   219,   220,   221,   222,   223,
     224,    37,    40,   349,   228,    40,    40,     4,    40,   169,
     170,    40,    38,    35,   238,    12,    13,    14,    38,    38,
     180,    21,    22,    23,    24,    25,    26,    27,    38,    38,
       4,    28,    29,    33,    40,    32,    40,   270,    38,    35,
      37,   274,    42,    43,    44,    45,   129,   130,   131,    38,
      38,    38,   305,   136,    40,    17,    36,   310,    35,   219,
     220,   221,   222,   223,   224,   318,    38,   150,   228,    36,
      38,   304,     4,    36,    35,     4,    40,    35,   238,    38,
     313,   305,    36,    12,    13,    14,   310,    36,    36,   322,
      36,    38,    35,     4,   318,    36,   349,    36,   331,    28,
      29,    20,   335,    32,   119,   175,    -1,   340,    37,    -1,
       4,    -1,   345,    -1,    -1,   348,    -1,    -1,    12,    13,
      14,    -1,   355,    -1,    -1,   349,   359,    -1,    -1,    -1,
      -1,   214,   215,   216,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    37,    -1,   305,    -1,    -1,    -1,    -1,
     310,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,    -1,
       1,    -1,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,   261,    -1,
      -1,    -1,    -1,    -1,   267,   268,   269,    28,    29,   349,
      -1,    32,    -1,    -1,    -1,    36,    37,    -1,    -1,     1,
     283,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    36,    37,     1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,
      -1,    36,    37,     1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,
       1,    -1,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,    36,    37,     1,    -1,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    36,    37,     1,    -1,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    36,
      37,     1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    36,    37,     1,    -1,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    36,    37,     1,    -1,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,
      36,    37,     1,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,     1,
      -1,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    36,    37,     1,    -1,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,
      -1,    36,    37,     1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,    36,    37,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    36,    37,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    36,
      37,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    36,    37,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    36,    37,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,
      36,    37,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,
      32,    -1,    -1,    -1,    36,    37,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,
      -1,    36,    37,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    32,    -1,    -1,    -1,    36,    37,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,    -1,
      -1,    -1,    36,    37,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,    36,
      37,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    -1,    32,    -1,    -1,    -1,    36,    37,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    36,    37,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,
      36,    37,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,     1,
      32,     3,     4,     5,     6,    37,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,     1,
      32,     3,     4,     5,     6,    37,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,     1,
      32,     3,     4,     5,     6,    37,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,     4,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    28,    29,     4,    -1,
      32,    -1,    -1,    -1,    -1,    37,    12,    13,    14,    28,
      29,     4,    -1,    32,    -1,    -1,    -1,    -1,    37,    12,
      13,    14,    28,    29,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    37,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
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
      -1,    42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    48,    49,    50,    51,    52,     4,     0,
      50,    37,    40,    53,     3,    54,    55,    56,     4,    38,
      41,    35,    55,    57,    58,    36,     3,     4,     5,     6,
       9,    10,    11,    12,    13,    14,    15,    16,    28,    29,
      32,    37,    51,    59,    60,    61,    65,    66,    67,    68,
      69,    70,    71,    74,    75,    77,     4,    37,     4,    69,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    69,
      69,    40,    40,    40,    40,    21,    22,    23,    24,    25,
      26,    27,    33,    42,    43,    44,    45,    76,    62,    63,
      64,    77,    40,    69,    30,    31,    69,    30,    31,    69,
       4,     4,    28,    29,    37,    72,    73,    72,    72,    69,
       4,    38,    69,    69,    69,    69,    69,    69,    38,    41,
      38,    38,    38,    38,    38,    38,    38,    38,    12,    17,
      17,    17,    40,    17,    63,    59,    37,    72,    72,    72,
      69,     4,     7,    72,    38,    38,    38,    40,    38,    59,
      17,    69,    35,    72,    38,    59,    38,    35,    36,    38,
      59,    36,     1,     4,    12,    13,    14,    28,    29,    32,
      37,    70,    71,    74,    75,    77,    40,     4,    28,    29,
      37,     1,     3,     5,     6,    15,    16,    51,    60,    61,
      65,    66,    67,    68,    69,     4,    28,    29,    37,    73,
       1,     3,     5,     6,    15,    16,    51,    60,    61,    65,
      66,    67,    68,    69,    37,    37,    37,    69,    69,    33,
      42,    43,    44,    45,    76,    69,     4,    69,    37,    37,
      37,    40,    40,    40,    40,    12,     4,    69,    37,    37,
      37,    40,    40,    40,    40,    72,    72,    72,    38,    69,
      69,    69,    69,    69,    69,    38,    40,    40,    69,    69,
       4,    37,    40,    40,    69,    69,     4,    17,    17,    17,
      38,    40,    17,    72,    38,    40,    17,    72,    72,    72,
      59,    69,     4,    17,     1,     3,     5,     6,    15,    16,
      51,    59,    60,    61,    65,    66,    67,    68,    69,    69,
       4,    38,    38,    38,     7,    40,    38,    72,     4,    69,
      37,    37,    37,     7,    40,    40,    40,    40,    40,    38,
      59,    69,    35,    38,    40,    40,    69,    69,     4,    59,
      69,    35,    38,    59,    38,    38,    40,    17,    38,    59,
      35,    36,    59,    69,     4,    35,    36,    59,     7,    40,
      38,    59,    36,    59,    69,    35,    36,    38,    59,    35,
      36,    59,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    53,
      52,    54,    55,    55,    55,    56,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    61,
      62,    63,    63,    63,    64,    65,    66,    66,    66,    66,
      66,    66,    67,    68,    68,    69,    69,    69,    69,    69,
      69,    70,    71,    71,    71,    72,    73,    73,    73,    73,
      74,    74,    74,    74,    75,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     1,     0,
       9,     1,     3,     1,     0,     2,     1,     2,     0,     1,
       2,     1,     1,     2,     2,     2,     3,     1,    11,     4,
       1,     3,     1,     0,     1,     4,     4,     4,     4,     4,
       4,     4,     9,     5,     7,     2,     1,     1,     1,     1,
       1,     3,     6,     6,     6,     1,     1,     1,     1,     8,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3
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
#line 158 "skylang.y"
                        {
		//printf("\nESCOPO ATUAL: %s\n",escopoAtual);
		if(passagem == 1){
			(yyval.tree) = add_tree_node("programa");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			tree = (yyval.tree);
		}
	}
#line 2125 "skylang.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 169 "skylang.y"
                                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2137 "skylang.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 176 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2148 "skylang.tab.c"
    break;

  case 5: /* declaration: variable_declaration  */
#line 192 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2159 "skylang.tab.c"
    break;

  case 6: /* declaration: func_declaration  */
#line 198 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2170 "skylang.tab.c"
    break;

  case 7: /* variable_declaration: TYPE ID SEMICOLON  */
#line 207 "skylang.y"
                          { 
						if(passagem == 1){
							
 							insert_symbol(symbol_ID, (yyvsp[-1].str),"VARIAVEL",(yyvsp[-2].str), escopoAtual,registrador_atual);
							registrador_atual = registrador_atual +1;
							symbol_ID = symbol_ID +1;
							//printf("\nAQUI %s\n",$2);
							(yyval.tree) = add_tree_node("variable_declaration");
						}

						 
	}
#line 2187 "skylang.tab.c"
    break;

  case 8: /* variable_declaration: error  */
#line 221 "skylang.y"
               {
		if(passagem == 1){
			//erro_count = erro_count +1;
			(yyval.tree) = add_tree_node("Erro Sintatico");
			yyerror(yymsg);
		}
	}
#line 2199 "skylang.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 231 "skylang.y"
                               {escopoAtual = (yyvsp[-1].str);
							if(passagem == 1){
								existe_simbolo = searchSymbol((yyvsp[-1].str));
								if(existe_simbolo == 1){
									redeclaracao_funcao = "\n--> ERRO SEMANTICO: redeclaracao de funcao\n";
									flag_redeclaracao_funcao = 1;
								}
							}
							}
#line 2213 "skylang.tab.c"
    break;

  case 10: /* func_declaration: TYPE ID PARENTESES_INI $@1 params PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 239 "skylang.y"
                                                                                                                 { 
																					if(passagem == 1){
											
																						insert_symbol(symbol_ID, (yyvsp[-7].str),"FUNCAO",(yyvsp[-8].str),escopoAtual,-1);
																						//registrador_atual = registrador_atual +1;
																						symbol_ID = symbol_ID +1 ;																	
																						(yyval.tree) = add_tree_node("func_declaration");																		
																						(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
																						(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
																					}
																					if(passagem ==2 ){
																						aux = strcmp((yyvsp[-7].str),"main");
																						if(aux == 0 ){
																							existe_main = 1;
																						}
																					}

																					/*if(passagem == 2){
																						existe_simbolo = searchSymbol($2);
																						if(existe_simbolo == 1){
																							printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: redeclaracao de funcao\n", num_linha,posicao_linha);
																						}
																					}*/
																					//printf("\nESCOPO ATUAL: %s\n",escopoAtual);
	}
#line 2243 "skylang.tab.c"
    break;

  case 11: /* params: params_list  */
#line 267 "skylang.y"
                    { 
				if(passagem == 1){
					(yyval.tree) = add_tree_node("params");
		 			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
				}
	}
#line 2254 "skylang.tab.c"
    break;

  case 12: /* params_list: param COLON params_list  */
#line 275 "skylang.y"
                                {
							if(passagem == 1){ 
								(yyval.tree) = add_tree_node("params_list");
		 						(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
							  	(yyval.tree) -> leaf2 = (yyvsp[0].tree);
							}
	}
#line 2266 "skylang.tab.c"
    break;

  case 13: /* params_list: param  */
#line 282 "skylang.y"
               { 
			if(passagem == 1){
				(yyval.tree) = add_tree_node("params_list");
		 	 	(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			}
	}
#line 2277 "skylang.tab.c"
    break;

  case 14: /* params_list: %empty  */
#line 288 "skylang.y"
         { 
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	}
#line 2287 "skylang.tab.c"
    break;

  case 15: /* param: TYPE ID  */
#line 302 "skylang.y"
                { 
				if(passagem == 1){
				
					insert_symbol(symbol_ID, (yyvsp[0].str),"PARAMETRO_FUNCAO",(yyvsp[-1].str),escopoAtual,-1);
					//registrador_atual = registrador_atual +1;
		    		symbol_ID = symbol_ID +1;
			 		(yyval.tree) = add_tree_node("param");
				}
	}
#line 2301 "skylang.tab.c"
    break;

  case 16: /* codeBlock: statement_list  */
#line 313 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CodeBlock");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2312 "skylang.tab.c"
    break;

  case 17: /* statement_list: statement_list statement  */
#line 329 "skylang.y"
                                 {
			(yyval.tree) = add_tree_node("Statement_list");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
#line 2322 "skylang.tab.c"
    break;

  case 18: /* statement_list: %empty  */
#line 334 "skylang.y"
          {	
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Statement_list VAZIO");
		}
		 
	}
#line 2333 "skylang.tab.c"
    break;

  case 19: /* statement: variable_declaration  */
#line 344 "skylang.y"
                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2344 "skylang.tab.c"
    break;

  case 20: /* statement: exp SEMICOLON  */
#line 351 "skylang.y"
                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2355 "skylang.tab.c"
    break;

  case 21: /* statement: ifStatement  */
#line 357 "skylang.y"
                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2366 "skylang.tab.c"
    break;

  case 22: /* statement: forAllStatement  */
#line 363 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2377 "skylang.tab.c"
    break;

  case 23: /* statement: outPutStatement SEMICOLON  */
#line 369 "skylang.y"
                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2388 "skylang.tab.c"
    break;

  case 24: /* statement: inputStatement SEMICOLON  */
#line 375 "skylang.y"
                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2399 "skylang.tab.c"
    break;

  case 25: /* statement: callFuncStatement SEMICOLON  */
#line 381 "skylang.y"
                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2410 "skylang.tab.c"
    break;

  case 26: /* statement: RETURN exp SEMICOLON  */
#line 388 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("RETURN statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2421 "skylang.tab.c"
    break;

  case 27: /* statement: forStatement  */
#line 395 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forStatement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2432 "skylang.tab.c"
    break;

  case 28: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM CHAVES_INI statement CHAVES_FIM  */
#line 405 "skylang.y"
                                                                                                                 {
			if(passagem == 1){
				(yyval.tree) = add_tree_node("ForStatement");
				(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
				(yyval.tree) -> leaf2 = (yyvsp[-6].tree);
				(yyval.tree) -> leaf3 = (yyvsp[-4].tree);
				(yyval.tree) -> leaf4 = (yyvsp[-1].tree);
			}
	}
#line 2446 "skylang.tab.c"
    break;

  case 29: /* callFuncStatement: ID PARENTESES_INI call_params PARENTESES_FIM  */
#line 419 "skylang.y"
                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallFunStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}

		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[-3].str));
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Funcao nao declarada\n", num_linha,posicao_linha);
			}
		}

	}
#line 2465 "skylang.tab.c"
    break;

  case 30: /* call_params: call_params_list  */
#line 437 "skylang.y"
                        {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallParams");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2476 "skylang.tab.c"
    break;

  case 31: /* call_params_list: call_param COLON call_params_list  */
#line 445 "skylang.y"
                                          {
		if(passagem == 1){ 
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2488 "skylang.tab.c"
    break;

  case 32: /* call_params_list: call_param  */
#line 452 "skylang.y"
                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}

	}
#line 2500 "skylang.tab.c"
    break;

  case 33: /* call_params_list: %empty  */
#line 459 "skylang.y"
         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	 }
#line 2510 "skylang.tab.c"
    break;

  case 34: /* call_param: terminal  */
#line 466 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_param terminal");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}

		if(passagem == 2){
			
		}
	}
#line 2525 "skylang.tab.c"
    break;

  case 35: /* inputStatement: READ PARENTESES_INI ID PARENTESES_FIM  */
#line 480 "skylang.y"
                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("inputStatement");	 
			//$$ -> leaf1 = $3;
		}
	}
#line 2536 "skylang.tab.c"
    break;

  case 36: /* outPutStatement: WRITE PARENTESES_INI STRING PARENTESES_FIM  */
#line 490 "skylang.y"
                                                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("outPutStatement");
			//$$ -> leaf1 = $3;
		}
	 }
#line 2547 "skylang.tab.c"
    break;

  case 37: /* outPutStatement: WRITE PARENTESES_INI CHAR PARENTESES_FIM  */
#line 497 "skylang.y"
                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("outPutStatement");
			//$$ -> leaf1 = $3;
		}
	 }
#line 2558 "skylang.tab.c"
    break;

  case 38: /* outPutStatement: WRITE PARENTESES_INI exp PARENTESES_FIM  */
#line 504 "skylang.y"
                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("outPutStatement");
			//$$ -> leaf1 = $3;
		}
	 }
#line 2569 "skylang.tab.c"
    break;

  case 39: /* outPutStatement: WRITELN PARENTESES_INI STRING PARENTESES_FIM  */
#line 510 "skylang.y"
                                                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("outPutStatement");
			//$$ -> leaf1 = $3;
		}
	 }
#line 2580 "skylang.tab.c"
    break;

  case 40: /* outPutStatement: WRITELN PARENTESES_INI CHAR PARENTESES_FIM  */
#line 518 "skylang.y"
                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("outPutStatement");
			//$$ -> leaf1 = $3;
		}
	 }
#line 2591 "skylang.tab.c"
    break;

  case 41: /* outPutStatement: WRITELN PARENTESES_INI exp PARENTESES_FIM  */
#line 525 "skylang.y"
                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("outPutStatement");
			//$$ -> leaf1 = $3;
		}
	 }
#line 2602 "skylang.tab.c"
    break;

  case 42: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI statement CHAVES_FIM  */
#line 535 "skylang.y"
                                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forAllStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[-6].str));
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope((yyvsp[-6].str),escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
			existe_simbolo = searchSymbol((yyvsp[-4].str));
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope((yyvsp[-6].str),escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
		}
	 }
#line 2633 "skylang.tab.c"
    break;

  case 43: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement  */
#line 565 "skylang.y"
                                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	 }
#line 2645 "skylang.tab.c"
    break;

  case 44: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement ELSE statement  */
#line 572 "skylang.y"
                                                                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
		}
	 }
#line 2658 "skylang.tab.c"
    break;

  case 45: /* exp: NEGATION exp  */
#line 585 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2669 "skylang.tab.c"
    break;

  case 46: /* exp: setExp  */
#line 592 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2680 "skylang.tab.c"
    break;

  case 47: /* exp: aritExp  */
#line 598 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2691 "skylang.tab.c"
    break;

  case 48: /* exp: relExp  */
#line 604 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2702 "skylang.tab.c"
    break;

  case 49: /* exp: terminal  */
#line 610 "skylang.y"
                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2713 "skylang.tab.c"
    break;

  case 50: /* exp: assignmentExp  */
#line 617 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2724 "skylang.tab.c"
    break;

  case 51: /* assignmentExp: terminal EQUALS exp  */
#line 626 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("assigmentExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2736 "skylang.tab.c"
    break;

  case 52: /* setExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 636 "skylang.y"
                                                                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 2748 "skylang.tab.c"
    break;

  case 53: /* setExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 643 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 2760 "skylang.tab.c"
    break;

  case 54: /* setExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 650 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 2772 "skylang.tab.c"
    break;

  case 55: /* terms_set: aritSetExp  */
#line 660 "skylang.y"
                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terms_set");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2783 "skylang.tab.c"
    break;

  case 56: /* aritSetExp: ID  */
#line 669 "skylang.y"
           {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal ID");
		}
		 
		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[0].str));
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope((yyvsp[0].str),escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
		}

	}
#line 2806 "skylang.tab.c"
    break;

  case 57: /* aritSetExp: FLOAT  */
#line 687 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal FLOAT");
		}
		 
	 }
#line 2817 "skylang.tab.c"
    break;

  case 58: /* aritSetExp: INTEGER  */
#line 693 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal INTEGER");
		}
		 
	 }
#line 2828 "skylang.tab.c"
    break;

  case 59: /* aritSetExp: PARENTESES_INI EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM PARENTESES_FIM  */
#line 699 "skylang.y"
                                                                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
		}
	}
#line 2840 "skylang.tab.c"
    break;

  case 60: /* aritExp: terminal MULT exp  */
#line 710 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	 }
#line 2852 "skylang.tab.c"
    break;

  case 61: /* aritExp: terminal PLUS exp  */
#line 717 "skylang.y"
                           {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	 }
#line 2864 "skylang.tab.c"
    break;

  case 62: /* aritExp: terminal MINUS exp  */
#line 724 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	 }
#line 2876 "skylang.tab.c"
    break;

  case 63: /* aritExp: terminal DIV exp  */
#line 731 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	 }
#line 2888 "skylang.tab.c"
    break;

  case 64: /* relExp: terminal rel exp  */
#line 740 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("relExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
		}
	 }
#line 2901 "skylang.tab.c"
    break;

  case 65: /* rel: CGE  */
#line 751 "skylang.y"
            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel CGE");
		}
	 }
#line 2911 "skylang.tab.c"
    break;

  case 66: /* rel: CGT  */
#line 756 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 2921 "skylang.tab.c"
    break;

  case 67: /* rel: CNE  */
#line 761 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 2931 "skylang.tab.c"
    break;

  case 68: /* rel: CLT  */
#line 766 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 2941 "skylang.tab.c"
    break;

  case 69: /* rel: AND  */
#line 771 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 2951 "skylang.tab.c"
    break;

  case 70: /* rel: CLE  */
#line 776 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 2961 "skylang.tab.c"
    break;

  case 71: /* rel: CEQ  */
#line 781 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel CEQ");
		}
	}
#line 2971 "skylang.tab.c"
    break;

  case 72: /* terminal: ID  */
#line 790 "skylang.y"
           {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal ID");
			
		}
		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[0].str));
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope((yyvsp[0].str),escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
		}
		 
	}
#line 2994 "skylang.tab.c"
    break;

  case 73: /* terminal: FLOAT  */
#line 808 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal FLOAT");
		}
		 
	 }
#line 3005 "skylang.tab.c"
    break;

  case 74: /* terminal: INTEGER  */
#line 814 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal INTEGER");
		}
		 
	 }
#line 3016 "skylang.tab.c"
    break;

  case 75: /* terminal: PARENTESES_INI exp PARENTESES_FIM  */
#line 821 "skylang.y"
                                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal EXP");
			(yyval.tree)->leaf1 =(yyvsp[-1].tree);
		}
	}
#line 3027 "skylang.tab.c"
    break;


#line 3031 "skylang.tab.c"

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

#line 830 "skylang.y"


extern void yyerror(const char* a) {
	if(passagem==2){
    	printf("\n--> ERRO SINTATICO na linha %d, coluna %d\n",num_linha,posicao_linha);
		printf("  %s\n",a);
	}
}


int main(){
char fname[100];
    scanf("%s",fname);
    yyin=fopen(fname,"r+");
	passagem=1;
	printf("\n=================== PRIMEIRA PASSAGEM (TS E ARVORE) ====================\n\n");
    yyparse();
    //yylex();
	fclose(yyin);
	printf("\n");
	printf("\n---------> ARVORE: <---------\n");
	print_tree(0,tree);
	printf("\n\n---------> Tabela de Simbolos <---------\n");
	printTS();
	printf("\n");
	passagem=2;
	yyin=fopen(fname,"r+");
	printf("\n==================== SEGUNDA PASSAGEM (TRATAMENTO DE ERROS) =====================\n\n");
	yyparse();
	fclose(yyin);
	if(existe_main!=1){
		printf("\n--> ERRO: O codigo nao possui uma funcao main()\n");
	}
	if(flag_redeclaracao_funcao==1){
		printf("\n--> ERRO: Redeclaracao de funcao\n");
	}
    yylex_destroy();
	free_tree(tree);
	//free_TS(hashed_symbol_table);
    return 0;
}
