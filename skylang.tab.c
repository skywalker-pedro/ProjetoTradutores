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
#include "tac_functions.h"
#include <string.h>

extern int yylex();
extern void yyerror(const char* msg);
extern int yylex_destroy();
extern FILE *yyin;
extern Hash_table * hashed_symbol_table;
extern tac_lines * tac_completo;
extern tac_lines * elt;
int symbol_ID = 0;
treeNode* tree = NULL;

/////////////////////////////////// Variaveis de controle de escopo, declaracao e checagem de tipos
int existe_simbolo;
int existe_main = 0;
int flag_redeclaracao_funcao;
int flag_redeclaracao_variavel;
int registrador_atual = 0;
char* tipo_funcao_atual;

//int erro_count = 0;
int aux=1;
int escopo_correto;
int argumento_func;
char char_reg[999];
int int_reg;
char codigo_tac[1100];
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

int get_id_reg(char*symbol,char*symbol_scope){
	Hash_table* aux = hashed_symbol_table;
	int temp = -999;
    while(aux!=NULL){
		//strcmp retorna 0 caso as strings sejam iguais
        if (strcmp(aux->name,symbol)==0){
			if (strcmp(aux->escopo,symbol_scope)==0){
				return aux -> registrador;
			}
		}
        aux = aux -> hh.next;
    }
	return temp;
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
	char* temp = "not_found";
    while(aux!=NULL){
		//strcmp retorna 0 caso as strings sejam iguais
        if (strcmp(aux->name,symbol)==0){
			if (strcmp(aux->escopo,symbol_scope)==0){
				return aux -> varType;
			}
		}
        aux = aux -> hh.next;
    }
	return temp;
	//free(aux);
}


//Search symbol type in symbol table
char * searchFuncType(char*func){
	Hash_table* aux = hashed_symbol_table;
	char* temp = "not_found";
    while(aux!=NULL){
		//strcmp retorna 0 caso as strings sejam iguais
        if (strcmp(aux->name,func)==0){
			return aux -> type;
		}
        aux = aux -> hh.next;
    }
	return temp;
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

/*
TYPES:
0 = nao definido ainda
1 = int
2 = float
3 = set
4 = elem 
*/

int translate_type(char*tipo){
int tipo_numerico;
	if(strcmp(tipo,"not_found")==0){
		tipo_numerico = 0;
		return tipo_numerico;
	}
	if(strcmp(tipo,"int")==0){
		tipo_numerico = 1;
		return tipo_numerico;
	}
	if(strcmp(tipo,"float")==0){
		tipo_numerico = 2;
		return tipo_numerico;
	}

	if(strcmp(tipo,"set")==0){
		tipo_numerico = 3;
		return tipo_numerico;
	}
	if(strcmp(tipo,"elem")==0){
		tipo_numerico = 4;
		return tipo_numerico;
	}
	tipo_numerico = 0;
	return tipo_numerico;
}

int check_set_type(int tipo1, int tipo2){
	if (tipo1 == 3 || tipo2 == 3){
		printf("\nERRO SEMANTICO LINHA %d, coluna %d: Operacao nao permitida para o tipo SET ",num_linha_1,posicao_linha_1);
		return 1;
	}else{
		return 0;
	}
}

/*
Politica de conversao de tipo
0 = não teve conversao
1 = intToFLoat
2 = floatToInt
3 = elemToInt
4 = IntToElem
5 = elemToFloat
6 = floatToElem
TYPES:
0 = nao definido ainda
1 = int
2 = float
3 = set
4 = elem 
*/
int check_conversao(int tipo1, int tipo2){
	if(tipo1 == tipo2)
		return 0;
	if(tipo1 == 1 && tipo2 == 2) //float to int
		return 2;
	if(tipo1 == 2 && tipo2 == 1) // int to float
		return 1;
	if(tipo1 == 4  && tipo2 == 1) // int to elem
		return 4;
	if(tipo1 == 1  && tipo2 == 4) // elem to int
		return 3;
	if(tipo1 == 4  && tipo2 == 2) // float to elem
		return 6;
	if(tipo1 == 2  && tipo2 == 4) // elem to float
		return 5;
	return 0; //excecoess
}


#line 315 "skylang.tab.c"

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
  YYSYMBOL_INTEGER = 5,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_WRITE = 13,                     /* WRITE  */
  YYSYMBOL_WRITELN = 14,                   /* WRITELN  */
  YYSYMBOL_READ = 15,                      /* READ  */
  YYSYMBOL_EXISTS = 16,                    /* EXISTS  */
  YYSYMBOL_ADD = 17,                       /* ADD  */
  YYSYMBOL_REMOVE = 18,                    /* REMOVE  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_FORALL = 20,                    /* FORALL  */
  YYSYMBOL_IN = 21,                        /* IN  */
  YYSYMBOL_IS_IN = 22,                     /* IS_IN  */
  YYSYMBOL_IS_SET = 23,                    /* IS_SET  */
  YYSYMBOL_OR = 24,                        /* OR  */
  YYSYMBOL_CLE = 25,                       /* CLE  */
  YYSYMBOL_CLT = 26,                       /* CLT  */
  YYSYMBOL_CNE = 27,                       /* CNE  */
  YYSYMBOL_CGT = 28,                       /* CGT  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_CEQ = 30,                       /* CEQ  */
  YYSYMBOL_CGE = 31,                       /* CGE  */
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
  YYSYMBOL_terminal = 77,                  /* terminal  */
  YYSYMBOL_ASSIGN = 78,                    /* ASSIGN  */
  YYSYMBOL_OP = 79,                        /* OP  */
  YYSYMBOL_CONST = 80                      /* CONST  */
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
#define YYLAST   2441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  286

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
       0,   276,   276,   287,   294,   303,   309,   318,   338,   349,
     349,   393,   401,   408,   414,   428,   439,   455,   460,   470,
     477,   484,   490,   496,   502,   508,   515,   526,   536,   545,
     559,   577,   585,   592,   599,   606,   620,   631,   640,   647,
     656,   667,   694,   724,   731,   740,   747,   760,   768,   775,
     783,   790,   799,   809,   824,   837,   844,   851,   861,   870,
     888,   894,   900,   922,   945,   957,   962,   967,   972,   977,
     982,   987,  1006,  1030,  1040,  1051,  1064,  1074,  1081,  1088,
    1095,  1106,  1113,  1120
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
  "\"end of file\"", "error", "\"invalid token\"", "TYPE", "ID",
  "INTEGER", "FLOAT", "CHAR", "STRING", "RETURN", "IF", "ELSE", "WHILE",
  "WRITE", "WRITELN", "READ", "EXISTS", "ADD", "REMOVE", "FOR", "FORALL",
  "IN", "IS_IN", "IS_SET", "OR", "CLE", "CLT", "CNE", "CGT", "AND", "CEQ",
  "CGE", "NEGATION", "EQUALS", "APOST", "CHAVES_INI", "CHAVES_FIM",
  "PARENTESES_INI", "PARENTESES_FIM", "EMPTY", "SEMICOLON", "COLON",
  "PLUS", "MINUS", "MULT", "DIV", "THEN", "$accept", "programa",
  "declarationList", "declaration", "variable_declaration",
  "func_declaration", "$@1", "params", "params_list", "param", "codeBlock",
  "statement_list", "statement", "forStatement", "callFuncStatement",
  "call_params", "call_params_list", "call_param", "inputStatement",
  "outPutStatement", "forAllStatement", "ifStatement", "exp",
  "assignmentExp", "setExp", "terms_set", "aritSetExp", "aritExp",
  "relExp", "rel", "terminal", "ASSIGN", "OP", "CONST", YY_NULLPTR
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

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      36,     7,     5,    18,    13,    42,   126,   130,   -20,   -77,
     141,     2,   172,     3,    21,   -17,     6,   -12,    43,    26,
       3,  1080,    27,    30,  1105,   209,    67,  2186,  2207,  2228,
      51,    33,    53,    54,    61,    62,    71,    78,    79,    83,
      51,    69,  1130,  1155,  1180,    88,    96,   103,  1205,  1230,
     105,   107,   113,   114,   115,  2249,   128,    58,  2270,   136,
      69,  2032,  2032,   177,    74,    74,    74,    51,   182,   155,
     159,  1255,  1280,  1305,  1330,  2056,  2080,  2098,  2104,  2121,
    2127,  2144,  2038,  2150,  2167,  2173,  2190,    51,  2074,    51,
     163,   175,    66,    94,  1355,   180,   190,   195,   204,   217,
     218,   219,   220,   221,   246,   255,   256,   262,   258,   259,
     261,   263,   247,   265,  2291,   248,   250,   253,   254,   257,
      58,  1380,   264,   269,   270,   271,   273,   268,   119,   119,
     119,    51,   291,   260,  1080,   315,    74,   276,   277,   284,
     283,   289,  1415,  1990,   275,   296,   297,   298,    69,  1440,
     352,  1475,   119,   305,  1080,  1500,   267,   306,  1525,  1560,
    1080,   307,  1080,  1585,  1610,  1635,   278,  1660,  1685,  1710,
    1735,  2312,  2333,  2354,   309,   311,   312,    69,    69,   321,
     322,   326,   335,  2375,  1760,   144,   200,   211,    69,   310,
     334,   336,   389,   371,    51,   340,   341,   342,   426,   463,
     343,   345,   346,   500,   537,   347,   344,   353,   358,   364,
     359,    74,    74,    74,   363,   372,    69,  2032,    69,   373,
     374,   375,    69,    51,   377,   574,   611,   648,   685,   376,
     391,   395,   396,  2396,   380,   381,   382,   384,   212,   722,
     759,   385,   388,   403,    74,   119,   119,   119,  1785,    51,
     429,   413,   400,   409,   410,  1080,   796,   411,   412,   119,
     414,   415,   416,  1820,  2015,    69,  1845,   417,   833,   870,
     418,  1080,   907,   419,   424,  1880,  1915,   422,  1080,  1080,
     944,   981,  1940,  1965,  1018,  1055
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
       0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   445,     0,   -77,   -77,   -77,   441,   -77,
     -77,   -57,   -49,   -32,    -4,   -77,   350,   -77,    -3,    17,
      25,    37,   -29,   -26,   -14,    95,   -76,   -11,    52,   282,
     -38,   288,   292,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    42,     7,    13,    15,    16,    17,
      23,    24,    43,    44,    45,    90,    91,    92,    46,    47,
      48,    49,    50,    51,    52,   108,   109,    53,    54,    87,
      55,    88,    89,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    59,   102,   183,     6,    -9,    14,    -8,    -8,     8,
      -8,    69,    70,    -2,     1,   179,     2,    11,     9,    93,
      12,    19,   183,   183,   183,    18,   -13,   180,   117,    20,
     181,    95,    99,   101,   179,   179,   179,     1,   112,     2,
      -9,   -14,    -4,    -4,   -11,    -4,   180,   180,   180,   181,
     181,   181,   210,   210,   210,    58,    28,    29,   115,   116,
     118,    21,   185,   186,   187,   -12,    25,    35,    36,    37,
      60,    56,   135,   171,   172,   173,   210,   142,   104,   105,
     106,   -15,    93,    40,   -15,   174,   175,   176,    41,   199,
      61,    62,   205,   182,   151,   188,   -34,   159,    63,    64,
     155,   177,   140,   165,   -33,   167,   178,   120,    65,   163,
     183,   107,   182,   182,   182,    66,    67,   200,   201,   153,
      68,   198,   179,   206,   207,   208,    -5,    -5,    71,    -5,
      -6,    -6,   -35,    -6,   180,   -35,    72,   181,   202,   183,
     183,    -3,    -3,    73,    -3,    74,   203,   -52,   214,   215,
     183,   179,   179,   -48,   -49,   -50,   209,   236,   204,   219,
     110,   111,   179,   180,   180,   221,   181,   181,   184,   210,
     210,   210,    -7,    -7,   180,    -7,    94,   181,   183,   183,
     183,   103,   -72,   210,   183,   -72,   113,   234,   235,   237,
     179,   179,   179,   241,   242,   -47,   179,   114,   263,   256,
     182,   119,   180,   180,   180,   181,   181,   181,   180,   -10,
     -10,   181,   -10,   -31,   276,   269,   199,   272,   121,   205,
     257,   282,   283,   137,   138,   139,   280,   183,   -82,   182,
     182,   144,   199,   -83,   199,   205,   270,   205,   -74,   179,
     182,   -74,   -81,   199,   200,   201,   205,   157,   198,   -73,
     -75,   180,   -73,   -75,   181,   122,   123,   124,   125,   126,
     200,   201,   200,   201,   198,   202,   198,   -59,   182,   182,
     182,   200,   201,   203,   182,   198,   -61,   -60,   127,   128,
     -58,   202,   129,   202,   130,   204,   132,   131,   -64,   203,
     -53,   203,   202,   -54,   -63,   141,   152,   -30,   -32,   -62,
     203,   204,   160,   204,   -38,   136,   230,   231,   232,   -37,
     -40,   -39,   204,   -36,   145,   146,   -43,   182,   -43,   -43,
     -43,   -43,   147,   148,   -43,   -43,   143,   149,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -57,   -55,   -56,   251,
     252,   253,   254,   158,   161,   166,   211,   -43,   212,   213,
     -82,   -43,   -43,   -45,   267,   -45,   -45,   -45,   -45,   -52,
     -48,   -45,   -45,   156,   -49,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -50,   -83,   220,   -81,   222,   223,   224,
     229,   243,   -59,   225,   -45,   226,   227,   228,   -45,   -45,
      -8,   -61,    -8,    -8,    -8,    -8,   -60,   -58,    -8,    -8,
      -8,   -47,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
     233,   238,   245,   244,   239,   240,   246,   247,   -64,   -53,
     -54,    -8,   -63,   248,   250,    -8,    -8,   -19,   249,   -19,
     -19,   -19,   -19,   258,   259,   -19,   -19,   -19,   260,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   261,   262,    10,
     266,   265,   -57,   -55,   -56,   273,   275,   277,   -19,   278,
     -62,    22,   -19,   -19,   -27,   216,   -27,   -27,   -27,   -27,
     133,   217,   -27,   -27,   -27,   218,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -27,     0,     0,     0,   -27,
     -27,   -22,     0,   -22,   -22,   -22,   -22,     0,     0,   -22,
     -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -22,     0,     0,     0,   -22,   -22,   -21,     0,
     -21,   -21,   -21,   -21,     0,     0,   -21,   -21,   -21,     0,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -21,
       0,     0,     0,   -21,   -21,   -25,     0,   -25,   -25,   -25,
     -25,     0,     0,   -25,   -25,   -25,     0,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -25,     0,     0,     0,
     -25,   -25,   -24,     0,   -24,   -24,   -24,   -24,     0,     0,
     -24,   -24,   -24,     0,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -24,     0,     0,     0,   -24,   -24,   -23,
       0,   -23,   -23,   -23,   -23,     0,     0,   -23,   -23,   -23,
       0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -23,     0,     0,     0,   -23,   -23,   -20,     0,   -20,   -20,
     -20,   -20,     0,     0,   -20,   -20,   -20,     0,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   -20,     0,     0,
       0,   -20,   -20,    -7,     0,    -7,    -7,    -7,    -7,     0,
       0,    -7,    -7,    -7,     0,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -7,     0,     0,     0,    -7,    -7,
     -26,     0,   -26,   -26,   -26,   -26,     0,     0,   -26,   -26,
     -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -26,     0,     0,     0,   -26,   -26,   -43,     0,   -43,
     -43,   -43,   -43,     0,     0,   -43,   -43,   264,     0,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -43,     0,
       0,     0,   -43,   -43,   -45,     0,   -45,   -45,   -45,   -45,
       0,     0,   -45,   -45,   274,     0,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -45,     0,     0,     0,   -45,
     -45,   -44,     0,   -44,   -44,   -44,   -44,     0,     0,   -44,
     -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -44,     0,     0,     0,   -44,   -44,   -41,     0,
     -41,   -41,   -41,   -41,     0,     0,   -41,   -41,   -41,     0,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -41,
       0,     0,     0,   -41,   -41,   -29,     0,   -29,   -29,   -29,
     -29,     0,     0,   -29,   -29,   -29,     0,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -29,     0,     0,     0,
     -29,   -29,   -42,     0,   -42,   -42,   -42,   -42,     0,     0,
     -42,   -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   -42,     0,     0,     0,   -42,   -42,   -46,
       0,   -46,   -46,   -46,   -46,     0,     0,   -46,   -46,   -46,
       0,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     -46,     0,     0,     0,   -46,   -46,   -28,     0,   -28,   -28,
     -28,   -28,     0,     0,   -28,   -28,   -28,     0,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,     0,     0,     0,     0,
       0,   -18,     0,   -18,   -18,   -18,   -18,   -28,     0,   -18,
     -18,   -28,   -28,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,     0,     0,     0,     0,     0,   170,     0,    26,    27,
      28,    29,   -18,     0,    30,    31,   -18,   -18,    32,    33,
      34,    35,    36,    37,    38,    39,     0,     0,     0,     0,
       0,   -19,     0,   -19,   -19,   -19,   -19,    40,     0,   -19,
     -19,   -16,    41,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,     0,     0,     0,     0,     0,   -17,     0,   -17,   -17,
     -17,   -17,   -19,     0,   -17,   -17,   -19,   -19,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,     0,     0,     0,     0,
       0,   -27,     0,   -27,   -27,   -27,   -27,   -17,     0,   -27,
     -27,   -17,   -17,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,     0,     0,     0,     0,     0,   -22,     0,   -22,   -22,
     -22,   -22,   -27,     0,   -22,   -22,   -27,   -27,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,     0,     0,     0,     0,
       0,   -21,     0,   -21,   -21,   -21,   -21,   -22,     0,   -21,
     -21,   -22,   -22,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,     0,     0,     0,     0,     0,   -25,     0,   -25,   -25,
     -25,   -25,   -21,     0,   -25,   -25,   -21,   -21,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,     0,     0,     0,     0,
       0,   -24,     0,   -24,   -24,   -24,   -24,   -25,     0,   -24,
     -24,   -25,   -25,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,     0,     0,     0,     0,     0,   -23,     0,   -23,   -23,
     -23,   -23,   -24,     0,   -23,   -23,   -24,   -24,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,     0,     0,     0,     0,
       0,   -20,     0,   -20,   -20,   -20,   -20,   -23,     0,   -20,
     -20,   -23,   -23,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,     0,     0,     0,     0,     0,   -26,     0,   -26,   -26,
     -26,   -26,   -20,     0,   -26,   -26,   -20,   -20,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,     0,     0,     0,     0,
       0,   192,     0,   193,    27,    28,    29,   -26,     0,   194,
     195,   -26,   -26,    32,    33,    34,    35,    36,    37,   196,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,     0,     0,   134,   170,    41,    26,    27,
      28,    29,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,     0,     0,     0,     0,
       0,   170,     0,    26,    27,    28,    29,    40,     0,    30,
      31,   150,    41,    32,    33,    34,    35,    36,    37,    38,
      39,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,     0,     0,   154,   -44,    41,   -44,   -44,
     -44,   -44,     0,     0,   -44,   -44,     0,     0,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,     0,
       0,   -41,     0,   -41,   -41,   -41,   -41,   -44,     0,   -41,
     -41,   -44,   -44,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,     0,     0,     0,     0,     0,   170,     0,    26,    27,
      28,    29,   -41,     0,    30,    31,   -41,   -41,    32,    33,
      34,    35,    36,    37,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
     162,   170,    41,    26,    27,    28,    29,     0,     0,    30,
      31,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,     0,     0,     0,     0,     0,   -29,     0,   -29,   -29,
     -29,   -29,    40,     0,   -29,   -29,   164,    41,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,     0,     0,     0,     0,
       0,   -42,     0,   -42,   -42,   -42,   -42,   -29,     0,   -42,
     -42,   -29,   -29,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,     0,     0,     0,     0,     0,   170,     0,    26,    27,
      28,    29,   -42,     0,    30,    31,   -42,   -42,    32,    33,
      34,    35,    36,    37,    38,    39,     0,     0,     0,     0,
       0,   170,     0,    26,    27,    28,    29,    40,     0,    30,
      31,   168,    41,    32,    33,    34,    35,    36,    37,    38,
      39,     0,     0,     0,     0,     0,   -46,     0,   -46,   -46,
     -46,   -46,    40,     0,   -46,   -46,   169,    41,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,     0,     0,     0,     0,
       0,   -28,     0,   -28,   -28,   -28,   -28,   -46,     0,   -28,
     -28,   -46,   -46,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,     0,     0,     0,     0,     0,    -8,     0,    -8,    -8,
      -8,    -8,   -28,     0,    -8,    -8,   -28,   -28,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,     0,     0,     0,     0,
       0,    -7,     0,    -7,    -7,    -7,    -7,    -8,     0,    -7,
      -7,    -8,    -8,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,     0,     0,     0,     0,     0,   192,     0,   193,    27,
      28,    29,    -7,     0,   194,   195,    -7,    -7,    32,    33,
      34,    35,    36,    37,   196,   197,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
     255,   170,    41,    26,    27,    28,    29,     0,     0,    30,
      31,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,     0,     0,     0,     0,     0,   192,     0,   193,    27,
      28,    29,    40,     0,   194,   195,   268,    41,    32,    33,
      34,    35,    36,    37,   196,   197,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    40,     0,     0,
     271,   192,    41,   193,    27,    28,    29,     0,     0,   194,
     195,     0,     0,    32,    33,    34,    35,    36,    37,   196,
     197,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    40,     0,     0,   279,   170,    41,    26,    27,
      28,    29,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,     0,     0,     0,     0,
       0,   170,     0,    26,    27,    28,    29,    40,     0,    30,
      31,   281,    41,    32,    33,    34,    35,    36,    37,    38,
      39,     0,     0,     0,     0,     0,   170,     0,    26,    27,
      28,    29,    40,     0,    30,    31,   284,    41,    32,    33,
      34,    35,    36,    37,    38,    39,     0,     0,     0,     0,
       0,   170,     0,    26,    27,    28,    29,    40,     0,    30,
      31,   285,    41,    32,    33,    34,    35,    36,    37,    38,
      39,     0,     0,     0,     0,     0,   192,     0,   193,    27,
      28,    29,    40,     0,   194,   195,     0,    41,    32,    33,
      34,    35,    36,    37,   196,   197,   171,   172,   173,    96,
      97,     0,   -76,   -76,   -76,   -76,   -76,    40,   174,   175,
     176,     0,    41,     0,   -76,   -76,   -76,     0,     0,     0,
     -70,   -70,   -70,     0,   177,     0,     0,     0,     0,   178,
     -76,    98,   -70,   -70,   -70,   -76,     0,   -76,    58,    28,
      29,   189,   190,     0,   -68,   -68,   -68,     0,   -70,     0,
      35,    36,    37,   -70,     0,     0,   -68,   -68,   -68,     0,
       0,     0,   -67,   -67,   -67,     0,    40,     0,   -66,   -66,
     -66,    41,   -68,   191,   -67,   -67,   -67,   -68,     0,     0,
     -66,   -66,   -66,     0,     0,   -69,   -69,   -69,     0,     0,
     -67,   -71,   -71,   -71,     0,   -67,   -66,   -69,   -69,   -69,
       0,   -66,     0,   -71,   -71,   -71,     0,     0,   -65,   -65,
     -65,     0,     0,   -69,   -78,   -78,   -78,     0,   -69,   -71,
     -65,   -65,   -65,     0,   -71,     0,   -78,   -78,   -78,     0,
       0,   -79,   -79,   -79,     0,     0,   -65,   -77,   -77,   -77,
       0,   -65,   -78,   -79,   -79,   -79,     0,   -78,     0,   -77,
     -77,   -77,     0,     0,   -80,   -80,   -80,     0,     0,   -79,
       0,     0,     0,     0,   -79,   -77,   -80,   -80,   -80,     0,
     -77,   -72,   -72,   -72,   -72,   -72,   -72,   -72,     0,   -72,
       0,     0,   -80,    57,     0,     0,   -72,   -80,   -72,   -72,
     -72,   -72,   -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,
     -74,     0,     0,     0,     0,     0,     0,   -74,     0,   -74,
     -74,   -74,   -74,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
       0,   -73,     0,     0,     0,     0,     0,     0,   -73,     0,
     -73,   -73,   -73,   -73,    75,    76,    77,    78,    79,    80,
      81,     0,    82,     0,     0,     0,     0,     0,     0,   -51,
       0,    83,    84,    85,    86,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,     0,   -72,     0,     0,     0,     0,     0,     0,
     -72,     0,   -72,   -72,   -72,   -72,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,     0,   -75,     0,     0,     0,     0,     0,
       0,   -75,     0,   -75,   -75,   -75,   -75,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,     0,   -72,     0,     0,     0,     0,
     -72,     0,     0,     0,   -72,   -72,   -72,   -72,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,     0,   -74,     0,     0,     0,
       0,   -74,     0,     0,     0,   -74,   -74,   -74,   -74,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,     0,   -73,     0,     0,
       0,     0,   -73,     0,     0,     0,   -73,   -73,   -73,   -73,
      75,    76,    77,    78,    79,    80,    81,     0,    82,     0,
       0,     0,     0,   -51,     0,     0,     0,    83,    84,    85,
      86,   -75,   -75,   -75,   -75,   -75,   -75,   -75,     0,   -75,
       0,     0,     0,     0,   -75,     0,     0,     0,   -75,   -75,
     -75,   -75
};

static const yytype_int16 yycheck[] =
{
       0,    30,    62,    41,     4,     3,     3,     0,     1,     4,
       3,    40,    41,     0,     1,    41,     3,    37,     0,    57,
      40,    38,    60,    61,    62,     4,    38,    41,    88,    41,
      41,    60,    61,    62,    60,    61,    62,     1,    67,     3,
      38,    38,     0,     1,    38,     3,    60,    61,    62,    60,
      61,    62,   128,   129,   130,     4,     5,     6,    87,    88,
      89,    35,     4,     5,     6,    38,    36,    16,    17,    18,
      37,     4,   121,     4,     5,     6,   152,   134,     4,     5,
       6,    38,   120,    32,    41,    16,    17,    18,    37,   121,
      37,    37,   121,    41,   143,    37,    38,   154,    37,    37,
     149,    32,   131,   160,    38,   162,    37,    41,    37,   158,
     148,    37,    60,    61,    62,    37,    37,   121,   121,   148,
      37,   121,   148,     4,     5,     6,     0,     1,    40,     3,
       0,     1,    38,     3,   148,    41,    40,   148,   121,   177,
     178,     0,     1,    40,     3,    40,   121,    40,   177,   178,
     188,   177,   178,    40,    40,    40,    37,   217,   121,   188,
      65,    66,   188,   177,   178,   194,   177,   178,    40,   245,
     246,   247,     0,     1,   188,     3,    40,   188,   216,   217,
     218,     4,    38,   259,   222,    41,     4,   216,   217,   218,
     216,   217,   218,   222,   223,    40,   222,    38,   255,   248,
     148,    38,   216,   217,   218,   216,   217,   218,   222,     0,
       1,   222,     3,    38,   271,   264,   248,   266,    38,   248,
     249,   278,   279,   128,   129,   130,   275,   265,    38,   177,
     178,   136,   264,    38,   266,   264,   265,   266,    38,   265,
     188,    41,    38,   275,   248,   248,   275,   152,   248,    38,
      38,   265,    41,    41,   265,    38,    38,    38,    38,    38,
     264,   264,   266,   266,   264,   248,   266,    21,   216,   217,
     218,   275,   275,   248,   222,   275,    21,    21,    16,    21,
      21,   264,    21,   266,    21,   248,    21,    40,    40,   264,
      40,   266,   275,    40,    40,     4,    21,    40,    38,    21,
     275,   264,    35,   266,    40,    37,   211,   212,   213,    40,
      40,    40,   275,    40,    38,    38,     1,   265,     3,     4,
       5,     6,    38,    40,     9,    10,    11,    38,    13,    14,
      15,    16,    17,    18,    19,    20,    40,    40,    40,   244,
     245,   246,   247,    38,    38,    38,    37,    32,    37,    37,
      40,    36,    37,     1,   259,     3,     4,     5,     6,    38,
      38,     9,    10,    11,    38,    13,    14,    15,    16,    17,
      18,    19,    20,    38,    40,     4,    40,    37,    37,    37,
      16,     4,    38,    40,    32,    40,    40,    40,    36,    37,
       1,    38,     3,     4,     5,     6,    38,    38,     9,    10,
      11,    38,    13,    14,    15,    16,    17,    18,    19,    20,
      38,    38,    21,    37,    40,    40,    21,    21,    38,    38,
      38,    32,    38,    38,    21,    36,    37,     1,    40,     3,
       4,     5,     6,     4,    21,     9,    10,    11,    38,    13,
      14,    15,    16,    17,    18,    19,    20,    38,    38,     4,
      38,    40,    38,    38,    38,    38,    38,    38,    32,    35,
      38,    20,    36,    37,     1,   183,     3,     4,     5,     6,
     120,   183,     9,    10,    11,   183,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,
      37,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    36,    37,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    36,    37,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      36,    37,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    36,    37,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    36,    37,     1,    -1,     3,     4,     5,     6,    -1,
      -1,     9,    10,    11,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,
       1,    -1,     3,     4,     5,     6,    -1,    -1,     9,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    36,    37,     1,    -1,     3,
       4,     5,     6,    -1,    -1,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    36,    37,     1,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    11,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    36,
      37,     1,    -1,     3,     4,     5,     6,    -1,    -1,     9,
      10,    11,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    36,    37,     1,    -1,
       3,     4,     5,     6,    -1,    -1,     9,    10,    11,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    36,    37,     1,    -1,     3,     4,     5,
       6,    -1,    -1,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      36,    37,     1,    -1,     3,     4,     5,     6,    -1,    -1,
       9,    10,    11,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    36,    37,     1,
      -1,     3,     4,     5,     6,    -1,    -1,     9,    10,    11,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    36,    37,     1,    -1,     3,     4,
       5,     6,    -1,    -1,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,     1,    37,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,     1,    37,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      35,     1,    37,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      35,     1,    37,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      35,     1,    37,     3,     4,     5,     6,    -1,    -1,     9,
      10,    -1,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,     1,    37,     3,     4,
       5,     6,    -1,    -1,     9,    10,    -1,    -1,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    36,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,     1,    -1,     3,     4,     5,     6,    32,    -1,     9,
      10,    36,    37,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    -1,    -1,     1,    -1,     3,     4,
       5,     6,    32,    -1,     9,    10,    -1,    37,    13,    14,
      15,    16,    17,    18,    19,    20,     4,     5,     6,     7,
       8,    -1,     4,     5,     6,     7,     8,    32,    16,    17,
      18,    -1,    37,    -1,    16,    17,    18,    -1,    -1,    -1,
       4,     5,     6,    -1,    32,    -1,    -1,    -1,    -1,    37,
      32,    39,    16,    17,    18,    37,    -1,    39,     4,     5,
       6,     7,     8,    -1,     4,     5,     6,    -1,    32,    -1,
      16,    17,    18,    37,    -1,    -1,    16,    17,    18,    -1,
      -1,    -1,     4,     5,     6,    -1,    32,    -1,     4,     5,
       6,    37,    32,    39,    16,    17,    18,    37,    -1,    -1,
      16,    17,    18,    -1,    -1,     4,     5,     6,    -1,    -1,
      32,     4,     5,     6,    -1,    37,    32,    16,    17,    18,
      -1,    37,    -1,    16,    17,    18,    -1,    -1,     4,     5,
       6,    -1,    -1,    32,     4,     5,     6,    -1,    37,    32,
      16,    17,    18,    -1,    37,    -1,    16,    17,    18,    -1,
      -1,     4,     5,     6,    -1,    -1,    32,     4,     5,     6,
      -1,    37,    32,    16,    17,    18,    -1,    37,    -1,    16,
      17,    18,    -1,    -1,     4,     5,     6,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    37,    32,    16,    17,    18,    -1,
      37,    25,    26,    27,    28,    29,    30,    31,    -1,    33,
      -1,    -1,    32,    37,    -1,    -1,    40,    37,    42,    43,
      44,    45,    25,    26,    27,    28,    29,    30,    31,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    42,
      43,    44,    45,    25,    26,    27,    28,    29,    30,    31,
      -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,
      42,    43,    44,    45,    25,    26,    27,    28,    29,    30,
      31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      -1,    42,    43,    44,    45,    25,    26,    27,    28,    29,
      30,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    -1,    42,    43,    44,    45,    25,    26,    27,    28,
      29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    -1,    42,    43,    44,    45,    25,    26,    27,
      28,    29,    30,    31,    -1,    33,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    42,    43,    44,    45,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,    43,    44,    45,    25,
      26,    27,    28,    29,    30,    31,    -1,    33,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    42,    43,    44,    45,
      25,    26,    27,    28,    29,    30,    31,    -1,    33,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    43,    44,
      45,    25,    26,    27,    28,    29,    30,    31,    -1,    33,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    43,
      44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    48,    49,    50,    51,    52,     4,     0,
      50,    37,    40,    53,     3,    54,    55,    56,     4,    38,
      41,    35,    55,    57,    58,    36,     3,     4,     5,     6,
       9,    10,    13,    14,    15,    16,    17,    18,    19,    20,
      32,    37,    51,    59,    60,    61,    65,    66,    67,    68,
      69,    70,    71,    74,    75,    77,     4,    37,     4,    69,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    69,
      69,    40,    40,    40,    40,    25,    26,    27,    28,    29,
      30,    31,    33,    42,    43,    44,    45,    76,    78,    79,
      62,    63,    64,    77,    40,    69,     7,     8,    39,    69,
      80,    69,    80,     4,     4,     5,     6,    37,    72,    73,
      72,    72,    69,     4,    38,    69,    69,    80,    69,    38,
      41,    38,    38,    38,    38,    38,    38,    16,    21,    21,
      21,    40,    21,    63,    35,    59,    37,    72,    72,    72,
      69,     4,    58,    11,    72,    38,    38,    38,    40,    38,
      36,    59,    21,    69,    35,    59,    11,    72,    38,    58,
      35,    38,    35,    59,    36,    58,    38,    58,    36,    36,
       1,     4,     5,     6,    16,    17,    18,    32,    37,    70,
      71,    74,    75,    77,    40,     4,     5,     6,    37,     7,
       8,    39,     1,     3,     9,    10,    19,    20,    51,    60,
      61,    65,    66,    67,    68,    69,     4,     5,     6,    37,
      73,    37,    37,    37,    69,    69,    76,    78,    79,    69,
       4,    69,    37,    37,    37,    40,    40,    40,    40,    16,
      72,    72,    72,    38,    69,    69,    80,    69,    38,    40,
      40,    69,    69,     4,    37,    21,    21,    21,    38,    40,
      21,    72,    72,    72,    72,    35,    59,    69,     4,    21,
      38,    38,    38,    58,    11,    40,    38,    72,    36,    59,
      69,    35,    59,    38,    11,    38,    58,    38,    35,    35,
      59,    36,    58,    58,    36,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    53,
      52,    54,    55,    55,    55,    56,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    62,    63,    63,    63,    64,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    71,    72,    73,
      73,    73,    73,    74,    75,    76,    76,    76,    76,    76,
      76,    76,    77,    77,    77,    77,    78,    79,    79,    79,
      79,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     1,     0,
       9,     1,     3,     1,     0,     2,     1,     2,     0,     1,
       2,     1,     1,     2,     2,     2,     3,     1,    11,     9,
       4,     1,     3,     1,     0,     1,     4,     4,     4,     4,
       4,     7,     9,     5,     7,     7,    11,     2,     1,     1,
       1,     1,     1,     3,     3,     6,     6,     6,     1,     1,
       1,     1,     8,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 276 "skylang.y"
                        {
		//printf("\nESCOPO ATUAL: %s\n",escopoAtual);
		if(passagem == 1){
			(yyval.tree) = add_tree_node("programa");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			tree = (yyval.tree);
		}
	}
#line 2263 "skylang.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 287 "skylang.y"
                                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2275 "skylang.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 294 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2286 "skylang.tab.c"
    break;

  case 5: /* declaration: variable_declaration  */
#line 303 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2297 "skylang.tab.c"
    break;

  case 6: /* declaration: func_declaration  */
#line 309 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2308 "skylang.tab.c"
    break;

  case 7: /* variable_declaration: TYPE ID SEMICOLON  */
#line 318 "skylang.y"
                          { 
						if(passagem == 1){
							
							existe_simbolo = searchSymbol((yyvsp[-1].str));
							if(existe_simbolo == 1){
								escopo_correto = searchScope((yyvsp[-1].str),escopoAtual);
								if(escopo_correto == 1){
									flag_redeclaracao_variavel =1;
									printf("\n--> ERRO SEMANTICO: redeclaracao da VARIAVEL -> %s <- na linha %d",(yyvsp[-1].str),num_linha_1-1);
								}
							}
 							insert_symbol(symbol_ID, (yyvsp[-1].str),"VARIAVEL",(yyvsp[-2].str), escopoAtual,registrador_atual);
							registrador_atual = registrador_atual +1;
							symbol_ID = symbol_ID +1;
							//printf("\nAQUI %s\n",$2);
							(yyval.tree) = add_tree_node("variable_declaration");
				
						}

	}
#line 2333 "skylang.tab.c"
    break;

  case 8: /* variable_declaration: error  */
#line 338 "skylang.y"
               {
		if(passagem == 1){
			//erro_count = erro_count +1;
			(yyval.tree) = add_tree_node("Erro Sintatico");
			yyerror(yymsg);
		}
	}
#line 2345 "skylang.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 349 "skylang.y"
                               {escopoAtual = (yyvsp[-1].str);
							if(passagem == 1){
								existe_simbolo = searchSymbol((yyvsp[-1].str));
								if(existe_simbolo == 1){
									printf("\n--> ERRO SEMANTICO: redeclaracao da FUNCAO -> %s <- na linha %d",(yyvsp[-1].str),num_linha_1);
									flag_redeclaracao_funcao = 1;
								}
								snprintf(char_reg,999,"%s:",(yyvsp[-1].str));
								adiciona_linha_tac(tac_completo,strdup(char_reg));
								tipo_funcao_atual = (yyvsp[-2].str);
								
							}
							}
#line 2363 "skylang.tab.c"
    break;

  case 10: /* func_declaration: TYPE ID PARENTESES_INI $@1 params PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 361 "skylang.y"
                                                                                                                 { 
																					if(passagem == 1){
											
																						insert_symbol(symbol_ID, (yyvsp[-7].str),"FUNCAO",(yyvsp[-8].str),escopoAtual,-1);
																						//registrador_atual = registrador_atual +1;
																						symbol_ID = symbol_ID +1 ;																	
																						(yyval.tree) = add_tree_node("func_declaration");																		
																						(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
																						(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
																						snprintf(codigo_tac,1100,"%s:",(yyvsp[-7].str));
																						(yyval.tree)->linha_tac = strdup(codigo_tac);
																						
																	
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
#line 2397 "skylang.tab.c"
    break;

  case 11: /* params: params_list  */
#line 393 "skylang.y"
                    { 
				if(passagem == 1){
					(yyval.tree) = add_tree_node("params");
		 			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
				}
	}
#line 2408 "skylang.tab.c"
    break;

  case 12: /* params_list: param COLON params_list  */
#line 401 "skylang.y"
                                {
							if(passagem == 1){ 
								(yyval.tree) = add_tree_node("params_list");
		 						(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
							  	(yyval.tree) -> leaf2 = (yyvsp[0].tree);
							}
	}
#line 2420 "skylang.tab.c"
    break;

  case 13: /* params_list: param  */
#line 408 "skylang.y"
               { 
			if(passagem == 1){
				(yyval.tree) = add_tree_node("params_list");
		 	 	(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			}
	}
#line 2431 "skylang.tab.c"
    break;

  case 14: /* params_list: %empty  */
#line 414 "skylang.y"
         { 
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	}
#line 2441 "skylang.tab.c"
    break;

  case 15: /* param: TYPE ID  */
#line 428 "skylang.y"
                { 
				if(passagem == 1){
				
					insert_symbol(symbol_ID, (yyvsp[0].str),"PARAMETRO_FUNCAO",(yyvsp[-1].str),escopoAtual,-1);
					//registrador_atual = registrador_atual +1;
		    		symbol_ID = symbol_ID +1;
			 		(yyval.tree) = add_tree_node("param");
				}
	}
#line 2455 "skylang.tab.c"
    break;

  case 16: /* codeBlock: statement_list  */
#line 439 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CodeBlock");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2466 "skylang.tab.c"
    break;

  case 17: /* statement_list: statement_list statement  */
#line 455 "skylang.y"
                                 {
			(yyval.tree) = add_tree_node("Statement_list");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
#line 2476 "skylang.tab.c"
    break;

  case 18: /* statement_list: %empty  */
#line 460 "skylang.y"
          {	
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Statement_list VAZIO");
		}
		 
	}
#line 2487 "skylang.tab.c"
    break;

  case 19: /* statement: variable_declaration  */
#line 470 "skylang.y"
                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2498 "skylang.tab.c"
    break;

  case 20: /* statement: exp SEMICOLON  */
#line 477 "skylang.y"
                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
		}
	 }
#line 2510 "skylang.tab.c"
    break;

  case 21: /* statement: ifStatement  */
#line 484 "skylang.y"
                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2521 "skylang.tab.c"
    break;

  case 22: /* statement: forAllStatement  */
#line 490 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2532 "skylang.tab.c"
    break;

  case 23: /* statement: outPutStatement SEMICOLON  */
#line 496 "skylang.y"
                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2543 "skylang.tab.c"
    break;

  case 24: /* statement: inputStatement SEMICOLON  */
#line 502 "skylang.y"
                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2554 "skylang.tab.c"
    break;

  case 25: /* statement: callFuncStatement SEMICOLON  */
#line 508 "skylang.y"
                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2565 "skylang.tab.c"
    break;

  case 26: /* statement: RETURN exp SEMICOLON  */
#line 515 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("RETURN");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
			(yyval.tree) -> flag_print = 1;
			if((yyval.tree) -> type != translate_type(tipo_funcao_atual))
				printf("\n--> ERRO SEMANTICO: Tipo do retorno da funcao -> %s <- incorreto na linha %d",escopoAtual,num_linha_1);
		}
	 }
#line 2580 "skylang.tab.c"
    break;

  case 27: /* statement: forStatement  */
#line 526 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forStatement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2591 "skylang.tab.c"
    break;

  case 28: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 536 "skylang.y"
                                                                                                              {
			if(passagem == 1){
				(yyval.tree) = add_tree_node("ForStatement");
				(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
				(yyval.tree) -> leaf2 = (yyvsp[-6].tree);
				(yyval.tree) -> leaf3 = (yyvsp[-4].tree);
				(yyval.tree) -> leaf4 = (yyvsp[-1].tree);
			}
	}
#line 2605 "skylang.tab.c"
    break;

  case 29: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM statement  */
#line 545 "skylang.y"
                                                                             {
			if(passagem == 1){
				(yyval.tree) = add_tree_node("ForStatement");
				(yyval.tree) -> leaf1 = (yyvsp[-6].tree);
				(yyval.tree) -> leaf2 = (yyvsp[-4].tree);
				(yyval.tree) -> leaf3 = (yyvsp[-2].tree);
				(yyval.tree) -> leaf4 = (yyvsp[0].tree);
			}
	}
#line 2619 "skylang.tab.c"
    break;

  case 30: /* callFuncStatement: ID PARENTESES_INI call_params PARENTESES_FIM  */
#line 559 "skylang.y"
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
#line 2638 "skylang.tab.c"
    break;

  case 31: /* call_params: call_params_list  */
#line 577 "skylang.y"
                        {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallParams");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2649 "skylang.tab.c"
    break;

  case 32: /* call_params_list: call_param COLON call_params_list  */
#line 585 "skylang.y"
                                          {
		if(passagem == 1){ 
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2661 "skylang.tab.c"
    break;

  case 33: /* call_params_list: call_param  */
#line 592 "skylang.y"
                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}

	}
#line 2673 "skylang.tab.c"
    break;

  case 34: /* call_params_list: %empty  */
#line 599 "skylang.y"
         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	 }
#line 2683 "skylang.tab.c"
    break;

  case 35: /* call_param: terminal  */
#line 606 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_param terminal");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}

		if(passagem == 2){
			
		}
	}
#line 2698 "skylang.tab.c"
    break;

  case 36: /* inputStatement: READ PARENTESES_INI ID PARENTESES_FIM  */
#line 620 "skylang.y"
                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("read ID");	 
			(yyval.tree) -> flag_print = 1;
			//$$ -> leaf1 = $3;
		}
	}
#line 2710 "skylang.tab.c"
    break;

  case 37: /* outPutStatement: WRITE PARENTESES_INI CONST PARENTESES_FIM  */
#line 631 "skylang.y"
                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("write");
			(yyval.tree) -> flag_print = 1;
			//$$ -> leaf1 = $3;
		}
	 }
#line 2722 "skylang.tab.c"
    break;

  case 38: /* outPutStatement: WRITE PARENTESES_INI exp PARENTESES_FIM  */
#line 640 "skylang.y"
                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("write");
			(yyval.tree) -> flag_print = 1;
			//$$ -> leaf1 = $3;
		}
	 }
#line 2734 "skylang.tab.c"
    break;

  case 39: /* outPutStatement: WRITELN PARENTESES_INI CONST PARENTESES_FIM  */
#line 647 "skylang.y"
                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("writeln");
			(yyval.tree) -> flag_print = 1;
			//$$ -> leaf1 = $3;
		}
	 }
#line 2746 "skylang.tab.c"
    break;

  case 40: /* outPutStatement: WRITELN PARENTESES_INI exp PARENTESES_FIM  */
#line 656 "skylang.y"
                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("writeln");
			(yyval.tree) -> flag_print = 1;
			//$$ -> leaf1 = $3;
		}
	 }
#line 2758 "skylang.tab.c"
    break;

  case 41: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM statement  */
#line 667 "skylang.y"
                                                                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forAllStatement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[-4].str));
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope((yyvsp[-4].str),escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
			existe_simbolo = searchSymbol((yyvsp[-2].str));
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope((yyvsp[-4].str),escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
		}
	 }
#line 2789 "skylang.tab.c"
    break;

  case 42: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 694 "skylang.y"
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
#line 2820 "skylang.tab.c"
    break;

  case 43: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement  */
#line 724 "skylang.y"
                                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	 }
#line 2832 "skylang.tab.c"
    break;

  case 44: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement ELSE statement  */
#line 731 "skylang.y"
                                                                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
		}
	 }
#line 2845 "skylang.tab.c"
    break;

  case 45: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 740 "skylang.y"
                                                                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	 }
#line 2857 "skylang.tab.c"
    break;

  case 46: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM ELSE CHAVES_INI statement_list CHAVES_FIM  */
#line 747 "skylang.y"
                                                                                                                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-5].tree);
			(yyval.tree) -> leaf3 = (yyvsp[-1].tree);
		}
	 }
#line 2870 "skylang.tab.c"
    break;

  case 47: /* exp: NEGATION exp  */
#line 760 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	 }
#line 2882 "skylang.tab.c"
    break;

  case 48: /* exp: setExp  */
#line 768 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	 }
#line 2894 "skylang.tab.c"
    break;

  case 49: /* exp: aritExp  */
#line 775 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> result;
		}
	 }
#line 2907 "skylang.tab.c"
    break;

  case 50: /* exp: relExp  */
#line 783 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	 }
#line 2919 "skylang.tab.c"
    break;

  case 51: /* exp: terminal  */
#line 790 "skylang.y"
                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> value_tac;
		}
	 }
#line 2932 "skylang.tab.c"
    break;

  case 52: /* exp: assignmentExp  */
#line 799 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	}
#line 2944 "skylang.tab.c"
    break;

  case 53: /* assignmentExp: terminal ASSIGN exp  */
#line 809 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("assigmentExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			if (check_set_type((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type)==0){
				(yyval.tree) -> type = (yyvsp[-2].tree) -> type;
				(yyval.tree) -> conversao = check_conversao((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type);
			}
			snprintf(codigo_tac,1100,"mov %s, %s", (yyvsp[-2].tree)->value_tac,(yyvsp[0].tree)->value_tac);
			(yyval.tree) -> linha_tac = strdup(codigo_tac);
			adiciona_linha_tac(tac_completo,(yyval.tree)->linha_tac);
		}
	}
#line 2964 "skylang.tab.c"
    break;

  case 54: /* assignmentExp: terminal ASSIGN CONST  */
#line 824 "skylang.y"
                               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("assigmentExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			if ((yyvsp[-2].tree)->type != 3)
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: ID com tipo incompativel com constante EMPTY\n", num_linha_1,posicao_linha_1);
		}
	}
#line 2979 "skylang.tab.c"
    break;

  case 55: /* setExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 837 "skylang.y"
                                                                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 2991 "skylang.tab.c"
    break;

  case 56: /* setExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 844 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 3003 "skylang.tab.c"
    break;

  case 57: /* setExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 851 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 3015 "skylang.tab.c"
    break;

  case 58: /* terms_set: aritSetExp  */
#line 861 "skylang.y"
                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terms_set");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 3026 "skylang.tab.c"
    break;

  case 59: /* aritSetExp: ID  */
#line 870 "skylang.y"
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
#line 3049 "skylang.tab.c"
    break;

  case 60: /* aritSetExp: FLOAT  */
#line 888 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal FLOAT");
		}
		 
	 }
#line 3060 "skylang.tab.c"
    break;

  case 61: /* aritSetExp: INTEGER  */
#line 894 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal INTEGER");
		}
		 
	 }
#line 3071 "skylang.tab.c"
    break;

  case 62: /* aritSetExp: PARENTESES_INI EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM PARENTESES_FIM  */
#line 900 "skylang.y"
                                                                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
		}
	}
#line 3083 "skylang.tab.c"
    break;

  case 63: /* aritExp: terminal OP exp  */
#line 922 "skylang.y"
                        {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			//$$ -> value_tac = char_reg;
			if (check_set_type((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type)==0){
				(yyval.tree) -> type = (yyvsp[-2].tree) -> type;
				(yyval.tree) -> conversao = check_conversao((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type);
			}
			snprintf(codigo_tac,1100,"%s, $%d, %s, %s",(yyvsp[-1].tree) -> value_tac, registrador_atual, (yyvsp[-2].tree) -> value_tac,(yyvsp[0].tree) -> value_tac);
			//printf("\n%s",codigo_tac);
			snprintf(char_reg,999,"$%d",registrador_atual);
			(yyval.tree) -> result = strdup(char_reg);
			registrador_atual ++;
			(yyval.tree) -> linha_tac = strdup(codigo_tac);
			(yyval.tree) -> printa_tac = 1;
			adiciona_linha_tac(tac_completo,(yyval.tree) -> linha_tac);
		} 
	 }
#line 3109 "skylang.tab.c"
    break;

  case 64: /* relExp: terminal rel exp  */
#line 945 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("relExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			check_set_type((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type);
		}
	 }
#line 3123 "skylang.tab.c"
    break;

  case 65: /* rel: CGE  */
#line 957 "skylang.y"
            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel CGE");
		}
	 }
#line 3133 "skylang.tab.c"
    break;

  case 66: /* rel: CGT  */
#line 962 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 3143 "skylang.tab.c"
    break;

  case 67: /* rel: CNE  */
#line 967 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 3153 "skylang.tab.c"
    break;

  case 68: /* rel: CLT  */
#line 972 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 3163 "skylang.tab.c"
    break;

  case 69: /* rel: AND  */
#line 977 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 3173 "skylang.tab.c"
    break;

  case 70: /* rel: CLE  */
#line 982 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel");
		}
	 }
#line 3183 "skylang.tab.c"
    break;

  case 71: /* rel: CEQ  */
#line 987 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("rel CEQ");
		}
	}
#line 3193 "skylang.tab.c"
    break;

  case 72: /* terminal: ID  */
#line 1006 "skylang.y"
           {
		if(passagem == 1){
			int_reg  = get_id_reg((yyvsp[0].str),escopoAtual);
			snprintf(char_reg, 999, "$%d",int_reg );
			(yyval.tree) = add_tree_node("terminal ID");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> type = translate_type(searchVarType((yyvsp[0].str),escopoAtual));
			(yyval.tree) -> value_tac = strdup(char_reg);
			(yyval.tree) -> value = (yyvsp[0].str);
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
#line 3222 "skylang.tab.c"
    break;

  case 73: /* terminal: FLOAT  */
#line 1030 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal FLOAT");
			(yyval.tree) -> type = 2;
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
		 
	 }
#line 3237 "skylang.tab.c"
    break;

  case 74: /* terminal: INTEGER  */
#line 1040 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal INTEGER");
			(yyval.tree) -> type = 1;
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
		 
	 }
#line 3252 "skylang.tab.c"
    break;

  case 75: /* terminal: PARENTESES_INI exp PARENTESES_FIM  */
#line 1051 "skylang.y"
                                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal EXP");
			(yyval.tree)->leaf1 =(yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[-1].tree) -> value_tac;
		}
	}
#line 3265 "skylang.tab.c"
    break;

  case 76: /* ASSIGN: EQUALS  */
#line 1064 "skylang.y"
       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" =");
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3276 "skylang.tab.c"
    break;

  case 77: /* OP: MULT  */
#line 1074 "skylang.y"
             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" *");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "mult";
		}
	 }
#line 3288 "skylang.tab.c"
    break;

  case 78: /* OP: PLUS  */
#line 1081 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" +");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "add";
		}
	 }
#line 3300 "skylang.tab.c"
    break;

  case 79: /* OP: MINUS  */
#line 1088 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" -");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "sub";
		}
	 }
#line 3312 "skylang.tab.c"
    break;

  case 80: /* OP: DIV  */
#line 1095 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" /");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "div";
		}
	 }
#line 3324 "skylang.tab.c"
    break;

  case 81: /* CONST: EMPTY  */
#line 1106 "skylang.y"
     {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("EMPTY");
			(yyval.tree) -> type = 3;
		}
}
#line 3335 "skylang.tab.c"
    break;

  case 82: /* CONST: CHAR  */
#line 1113 "skylang.y"
     {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("CHAR");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
}
#line 3346 "skylang.tab.c"
    break;

  case 83: /* CONST: STRING  */
#line 1120 "skylang.y"
       {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("STRING");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
}
#line 3357 "skylang.tab.c"
    break;


#line 3361 "skylang.tab.c"

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

#line 1129 "skylang.y"


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
	printf("\n=================== PRIMEIRA PASSAGEM (TS, ARVORE e erros de Redeclaracao ) ====================\n\n");
    yyparse();
    //yylex();
	fclose(yyin);
	printf("\n");
	printf("\n---------> ARVORE SINTATICA ABSTRATA ANOTADA: <---------\n");
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
		printf("\n--> ERRO: Redeclaracao de FUNCAO (checar inicio da primeira passagem para mais detalhes)\n");
	}
	if(flag_redeclaracao_variavel==1){
		printf("\n--> ERRO: Redeclaracao de VARIAVEL (checar inicio da primeira passagem para mais detalhes)\n");
	}
	printf("\n==================== TAC =====================\n\n");
	printf(".table\n.code\n");
	printa_linha_tac(tac_completo,elt);
	cria_arquivo_tac(tac_completo,elt);
    yylex_destroy();
	free_tree(tree);
	//free_TS(hashed_symbol_table);
    return 0;
}
