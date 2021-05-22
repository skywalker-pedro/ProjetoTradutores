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
  YYSYMBOL_CLE = 4,                        /* CLE  */
  YYSYMBOL_CLT = 5,                        /* CLT  */
  YYSYMBOL_CNE = 6,                        /* CNE  */
  YYSYMBOL_CGT = 7,                        /* CGT  */
  YYSYMBOL_AND = 8,                        /* AND  */
  YYSYMBOL_CEQ = 9,                        /* CEQ  */
  YYSYMBOL_CGE = 10,                       /* CGE  */
  YYSYMBOL_ID = 11,                        /* ID  */
  YYSYMBOL_INTEGER = 12,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 13,                     /* FLOAT  */
  YYSYMBOL_CHAR = 14,                      /* CHAR  */
  YYSYMBOL_STRING = 15,                    /* STRING  */
  YYSYMBOL_EMPTY = 16,                     /* EMPTY  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_WRITE = 21,                     /* WRITE  */
  YYSYMBOL_WRITELN = 22,                   /* WRITELN  */
  YYSYMBOL_READ = 23,                      /* READ  */
  YYSYMBOL_EXISTS = 24,                    /* EXISTS  */
  YYSYMBOL_ADD = 25,                       /* ADD  */
  YYSYMBOL_REMOVE = 26,                    /* REMOVE  */
  YYSYMBOL_FOR = 27,                       /* FOR  */
  YYSYMBOL_FORALL = 28,                    /* FORALL  */
  YYSYMBOL_IN = 29,                        /* IN  */
  YYSYMBOL_IS_IN = 30,                     /* IS_IN  */
  YYSYMBOL_IS_SET = 31,                    /* IS_SET  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_NEGATION = 33,                  /* NEGATION  */
  YYSYMBOL_EQUALS = 34,                    /* EQUALS  */
  YYSYMBOL_APOST = 35,                     /* APOST  */
  YYSYMBOL_CHAVES_INI = 36,                /* CHAVES_INI  */
  YYSYMBOL_CHAVES_FIM = 37,                /* CHAVES_FIM  */
  YYSYMBOL_PARENTESES_INI = 38,            /* PARENTESES_INI  */
  YYSYMBOL_PARENTESES_FIM = 39,            /* PARENTESES_FIM  */
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
#define YYLAST   2292

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
       0,   275,   275,   286,   293,   302,   308,   317,   337,   348,
     348,   395,   403,   410,   416,   430,   441,   457,   462,   472,
     479,   486,   492,   498,   504,   510,   517,   528,   538,   547,
     561,   579,   587,   594,   601,   608,   622,   633,   643,   654,
     664,   679,   706,   736,   744,   754,   762,   776,   784,   791,
     799,   806,   815,   825,   840,   853,   860,   867,   877,   886,
     904,   910,   916,   938,   961,   973,   981,   989,   997,  1005,
    1013,  1021,  1043,  1067,  1077,  1088,  1101,  1111,  1118,  1125,
    1132,  1143,  1151,  1160
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
  "\"end of file\"", "error", "\"invalid token\"", "TYPE", "CLE", "CLT",
  "CNE", "CGT", "AND", "CEQ", "CGE", "ID", "INTEGER", "FLOAT", "CHAR",
  "STRING", "EMPTY", "RETURN", "IF", "ELSE", "WHILE", "WRITE", "WRITELN",
  "READ", "EXISTS", "ADD", "REMOVE", "FOR", "FORALL", "IN", "IS_IN",
  "IS_SET", "OR", "NEGATION", "EQUALS", "APOST", "CHAVES_INI",
  "CHAVES_FIM", "PARENTESES_INI", "PARENTESES_FIM", "SEMICOLON", "COLON",
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
      36,     7,    -2,    13,    67,    78,    83,    98,    31,   -77,
     123,     2,   127,     3,     9,   -25,   -18,    16,    34,   -10,
       3,  1110,     1,   -12,  1138,   132,    18,   289,   339,   351,
    2148,    42,    57,    58,    69,    70,    73,    77,    82,    87,
    2148,  2158,  1166,  1194,  1222,    76,    96,   113,  1250,  1278,
     114,   115,   116,   128,   133,   358,   135,     5,   400,   136,
    2158,  2118,  2118,    45,    50,    50,    50,  2148,    63,   141,
       6,  1306,  1334,  1362,  1390,  2176,  2182,  2186,  2192,  2210,
    2216,  2220,  2124,  2226,  2244,  2250,  2254,  2148,  2152,  2148,
      51,   143,    46,    65,  1418,   146,   147,   156,   158,   162,
     170,   171,   173,   174,   189,   199,   204,   148,   209,   212,
     213,   220,   210,   223,   407,   215,   216,   217,   218,   219,
       5,  1446,   227,   236,   237,   238,   239,   242,    53,    53,
      53,  2148,   271,   214,  1110,   522,    50,   245,   247,   248,
     250,   249,  1474,  2062,   273,   264,   265,   269,  2158,  1502,
     550,  1530,    53,   272,  1110,  1558,   274,   275,  1586,  1614,
    1110,   276,  1110,  1642,  1670,  1698,   284,  1726,  1754,  1782,
    1810,   414,   421,   463,   278,   280,   281,  2158,  2158,   282,
     283,   285,   286,   470,  1838,    90,   102,   103,  2158,   288,
     290,   295,   578,   309,  2148,   298,   299,   300,   606,   634,
     310,   311,   312,   662,   690,   313,   287,   330,   331,   347,
     333,    50,    50,    50,   335,   336,  2158,  2118,  2158,   337,
     338,   340,  2158,  2148,   366,   718,   746,   774,   802,   348,
     359,   360,   361,   477,   393,   394,   396,   397,   106,   830,
     858,   398,   357,   370,    50,    53,    53,    53,  1866,  2148,
     376,   409,   415,   422,   423,  1110,   886,   399,   449,    53,
     450,   451,   452,  1894,  2090,  2158,  1922,   453,   914,   942,
     454,  1110,   970,   455,   410,  1950,  1978,   456,  1110,  1110,
     998,  1026,  2006,  2034,  1054,  1082
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
     -77,   -77,   -77,   492,     0,   -77,   -77,   -77,   478,   -77,
     -77,   -57,   -49,   -32,    -4,   -77,   379,   -77,    -3,    17,
      25,    37,   -29,   -26,   -14,    95,   -76,   -11,    52,   317,
     -38,   318,   320,   -60
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
      -8,    69,    70,     9,    19,   179,   185,   186,   187,    93,
      18,   -11,   183,   183,   183,    25,    21,   180,   117,    56,
     181,    95,    99,   101,   179,   179,   179,     1,   112,     2,
     -12,    -9,   -14,   188,   -34,   114,   180,   180,   180,   181,
     181,   181,   210,   210,   210,   -13,   103,    20,   115,   116,
     118,   104,   105,   106,   206,   207,   208,    -2,     1,    11,
       2,    12,   135,   -15,   113,   -15,   210,   142,    -4,    -4,
      60,    -4,    93,    -5,    -5,   -33,    -5,   120,   107,   199,
     119,   209,   205,   182,   151,    61,    62,   159,    -6,    -6,
     155,    -6,   140,   165,   -35,   167,   -35,    63,    64,   163,
     183,    65,   182,   182,   182,    66,    71,   200,   201,   153,
      67,   198,   179,    -3,    -3,    68,    -3,    -7,    -7,   -72,
      -7,   -72,   -10,   -10,   180,   -10,    72,   181,   202,   183,
     183,   -74,   -73,   -74,   -73,   -75,   203,   -75,   214,   215,
     183,   179,   179,    73,    74,   -52,   -48,   236,   204,   219,
     110,   111,   179,   180,   180,   221,   181,   181,   -49,   210,
     210,   210,   127,   -50,   180,   184,    94,   181,   183,   183,
     183,   -47,   -31,   210,   183,   121,   -82,   234,   235,   237,
     179,   179,   179,   241,   242,   -83,   179,   -81,   263,   256,
     182,   122,   180,   180,   180,   181,   181,   181,   180,   123,
     124,   181,   125,   126,   276,   269,   199,   272,   -59,   205,
     257,   282,   283,   137,   138,   139,   280,   183,   -61,   182,
     182,   144,   199,   -60,   199,   205,   270,   205,   128,   179,
     182,   -58,   129,   199,   200,   201,   205,   157,   198,   130,
     131,   180,   132,   -32,   181,   -64,   -53,   -54,   -63,   -30,
     200,   201,   200,   201,   198,   202,   198,   -38,   182,   182,
     182,   200,   201,   203,   182,   198,   -37,   -40,   -39,   -36,
     136,   202,   141,   202,   145,   204,   146,   147,   149,   203,
     148,   203,   202,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     203,   204,   152,   204,   -57,   -55,   230,   231,   232,   -56,
     160,   158,   204,   -62,   161,   166,   211,   182,   212,   213,
     220,   -52,   -48,   -72,   -49,   -50,   -59,    57,   -82,   -72,
     -83,   -72,   -72,   -72,   -72,   -81,   222,   223,   224,   251,
     252,   253,   254,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     225,   226,   227,   228,   267,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,    75,    76,    77,    78,    79,    80,    81,   -61,
     -60,   229,   -58,   -74,   -47,   233,   238,   243,   239,   -74,
     240,   -74,   -74,   -74,   -74,   -73,   244,   258,   245,   246,
     247,   -73,    82,   -73,   -73,   -73,   -73,   249,   -51,   250,
      83,    84,    85,    86,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -64,   -53,   -72,   -54,   -63,   248,   259,   265,
     -72,   -75,   -72,   -72,   -72,   -72,   278,   -75,   -72,   -75,
     -75,   -75,   -75,   -72,   260,   -74,   -72,   -72,   -72,   -72,
     -74,   261,   262,   -74,   -74,   -74,   -74,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,    75,    76,    77,    78,    79,    80,
      81,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   266,   -57,
     -55,   -56,   273,   275,   277,   -62,    10,   -73,    22,   133,
     216,   217,   -73,   218,    82,   -73,   -73,   -73,   -73,   -51,
       0,   -75,    83,    84,    85,    86,   -75,     0,     0,   -75,
     -75,   -75,   -75,   -43,     0,   -43,     0,     0,     0,     0,
       0,     0,     0,   -43,   -43,   -43,     0,     0,     0,   -43,
     -43,   143,     0,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -45,     0,   -45,     0,   -43,     0,     0,     0,   -43,
     -43,   -45,   -45,   -45,     0,     0,     0,   -45,   -45,   156,
       0,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,    -8,
       0,    -8,     0,   -45,     0,     0,     0,   -45,   -45,    -8,
      -8,    -8,     0,     0,     0,    -8,    -8,    -8,     0,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,   -19,     0,   -19,
       0,    -8,     0,     0,     0,    -8,    -8,   -19,   -19,   -19,
       0,     0,     0,   -19,   -19,   -19,     0,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -27,     0,   -27,     0,   -19,
       0,     0,     0,   -19,   -19,   -27,   -27,   -27,     0,     0,
       0,   -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -22,     0,   -22,     0,   -27,     0,     0,
       0,   -27,   -27,   -22,   -22,   -22,     0,     0,     0,   -22,
     -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -21,     0,   -21,     0,   -22,     0,     0,     0,   -22,
     -22,   -21,   -21,   -21,     0,     0,     0,   -21,   -21,   -21,
       0,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -25,
       0,   -25,     0,   -21,     0,     0,     0,   -21,   -21,   -25,
     -25,   -25,     0,     0,     0,   -25,   -25,   -25,     0,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -24,     0,   -24,
       0,   -25,     0,     0,     0,   -25,   -25,   -24,   -24,   -24,
       0,     0,     0,   -24,   -24,   -24,     0,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -23,     0,   -23,     0,   -24,
       0,     0,     0,   -24,   -24,   -23,   -23,   -23,     0,     0,
       0,   -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -20,     0,   -20,     0,   -23,     0,     0,
       0,   -23,   -23,   -20,   -20,   -20,     0,     0,     0,   -20,
     -20,   -20,     0,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,    -7,     0,    -7,     0,   -20,     0,     0,     0,   -20,
     -20,    -7,    -7,    -7,     0,     0,     0,    -7,    -7,    -7,
       0,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,   -26,
       0,   -26,     0,    -7,     0,     0,     0,    -7,    -7,   -26,
     -26,   -26,     0,     0,     0,   -26,   -26,   -26,     0,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   -43,     0,   -43,
       0,   -26,     0,     0,     0,   -26,   -26,   -43,   -43,   -43,
       0,     0,     0,   -43,   -43,   264,     0,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -45,     0,   -45,     0,   -43,
       0,     0,     0,   -43,   -43,   -45,   -45,   -45,     0,     0,
       0,   -45,   -45,   274,     0,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -44,     0,   -44,     0,   -45,     0,     0,
       0,   -45,   -45,   -44,   -44,   -44,     0,     0,     0,   -44,
     -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -41,     0,   -41,     0,   -44,     0,     0,     0,   -44,
     -44,   -41,   -41,   -41,     0,     0,     0,   -41,   -41,   -41,
       0,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -29,
       0,   -29,     0,   -41,     0,     0,     0,   -41,   -41,   -29,
     -29,   -29,     0,     0,     0,   -29,   -29,   -29,     0,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -42,     0,   -42,
       0,   -29,     0,     0,     0,   -29,   -29,   -42,   -42,   -42,
       0,     0,     0,   -42,   -42,   -42,     0,   -42,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -46,     0,   -46,     0,   -42,
       0,     0,     0,   -42,   -42,   -46,   -46,   -46,     0,     0,
       0,   -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -28,     0,   -28,     0,   -46,     0,     0,
       0,   -46,   -46,   -28,   -28,   -28,     0,     0,     0,   -28,
     -28,   -28,     0,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -18,     0,   -18,     0,   -28,     0,     0,     0,   -28,
     -28,   -18,   -18,   -18,     0,     0,     0,   -18,   -18,     0,
       0,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   170,
       0,    26,     0,   -18,     0,     0,     0,   -18,   -18,    27,
      28,    29,     0,     0,     0,    30,    31,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,   -19,     0,   -19,
       0,    40,     0,     0,     0,   -16,    41,   -19,   -19,   -19,
       0,     0,     0,   -19,   -19,     0,     0,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -17,     0,   -17,     0,   -19,
       0,     0,     0,   -19,   -19,   -17,   -17,   -17,     0,     0,
       0,   -17,   -17,     0,     0,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -27,     0,   -27,     0,   -17,     0,     0,
       0,   -17,   -17,   -27,   -27,   -27,     0,     0,     0,   -27,
     -27,     0,     0,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -22,     0,   -22,     0,   -27,     0,     0,     0,   -27,
     -27,   -22,   -22,   -22,     0,     0,     0,   -22,   -22,     0,
       0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -21,
       0,   -21,     0,   -22,     0,     0,     0,   -22,   -22,   -21,
     -21,   -21,     0,     0,     0,   -21,   -21,     0,     0,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -25,     0,   -25,
       0,   -21,     0,     0,     0,   -21,   -21,   -25,   -25,   -25,
       0,     0,     0,   -25,   -25,     0,     0,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -24,     0,   -24,     0,   -25,
       0,     0,     0,   -25,   -25,   -24,   -24,   -24,     0,     0,
       0,   -24,   -24,     0,     0,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -23,     0,   -23,     0,   -24,     0,     0,
       0,   -24,   -24,   -23,   -23,   -23,     0,     0,     0,   -23,
     -23,     0,     0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -20,     0,   -20,     0,   -23,     0,     0,     0,   -23,
     -23,   -20,   -20,   -20,     0,     0,     0,   -20,   -20,     0,
       0,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -26,
       0,   -26,     0,   -20,     0,     0,     0,   -20,   -20,   -26,
     -26,   -26,     0,     0,     0,   -26,   -26,     0,     0,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,   192,     0,   193,
       0,   -26,     0,     0,     0,   -26,   -26,    27,    28,    29,
       0,     0,     0,   194,   195,     0,     0,    32,    33,    34,
      35,    36,    37,   196,   197,   170,     0,    26,     0,    40,
       0,     0,   134,     0,    41,    27,    28,    29,     0,     0,
       0,    30,    31,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,   170,     0,    26,     0,    40,     0,     0,
       0,   150,    41,    27,    28,    29,     0,     0,     0,    30,
      31,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,   -44,     0,   -44,     0,    40,     0,     0,   154,     0,
      41,   -44,   -44,   -44,     0,     0,     0,   -44,   -44,     0,
       0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -41,
       0,   -41,     0,   -44,     0,     0,     0,   -44,   -44,   -41,
     -41,   -41,     0,     0,     0,   -41,   -41,     0,     0,   -41,
     -41,   -41,   -41,   -41,   -41,   -41,   -41,   170,     0,    26,
       0,   -41,     0,     0,     0,   -41,   -41,    27,    28,    29,
       0,     0,     0,    30,    31,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,   170,     0,    26,     0,    40,
       0,     0,   162,     0,    41,    27,    28,    29,     0,     0,
       0,    30,    31,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,   -29,     0,   -29,     0,    40,     0,     0,
       0,   164,    41,   -29,   -29,   -29,     0,     0,     0,   -29,
     -29,     0,     0,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,   -42,     0,   -42,     0,   -29,     0,     0,     0,   -29,
     -29,   -42,   -42,   -42,     0,     0,     0,   -42,   -42,     0,
       0,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   170,
       0,    26,     0,   -42,     0,     0,     0,   -42,   -42,    27,
      28,    29,     0,     0,     0,    30,    31,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,   170,     0,    26,
       0,    40,     0,     0,     0,   168,    41,    27,    28,    29,
       0,     0,     0,    30,    31,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,   -46,     0,   -46,     0,    40,
       0,     0,     0,   169,    41,   -46,   -46,   -46,     0,     0,
       0,   -46,   -46,     0,     0,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -28,     0,   -28,     0,   -46,     0,     0,
       0,   -46,   -46,   -28,   -28,   -28,     0,     0,     0,   -28,
     -28,     0,     0,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,    -8,     0,    -8,     0,   -28,     0,     0,     0,   -28,
     -28,    -8,    -8,    -8,     0,     0,     0,    -8,    -8,     0,
       0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -7,
       0,    -7,     0,    -8,     0,     0,     0,    -8,    -8,    -7,
      -7,    -7,     0,     0,     0,    -7,    -7,     0,     0,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,   192,     0,   193,
       0,    -7,     0,     0,     0,    -7,    -7,    27,    28,    29,
       0,     0,     0,   194,   195,     0,     0,    32,    33,    34,
      35,    36,    37,   196,   197,   170,     0,    26,     0,    40,
       0,     0,   255,     0,    41,    27,    28,    29,     0,     0,
       0,    30,    31,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,   192,     0,   193,     0,    40,     0,     0,
       0,   268,    41,    27,    28,    29,     0,     0,     0,   194,
     195,     0,     0,    32,    33,    34,    35,    36,    37,   196,
     197,   192,     0,   193,     0,    40,     0,     0,   271,     0,
      41,    27,    28,    29,     0,     0,     0,   194,   195,     0,
       0,    32,    33,    34,    35,    36,    37,   196,   197,   170,
       0,    26,     0,    40,     0,     0,   279,     0,    41,    27,
      28,    29,     0,     0,     0,    30,    31,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,   170,     0,    26,
       0,    40,     0,     0,     0,   281,    41,    27,    28,    29,
       0,     0,     0,    30,    31,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,   170,     0,    26,     0,    40,
       0,     0,     0,   284,    41,    27,    28,    29,     0,     0,
       0,    30,    31,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,   170,     0,    26,     0,    40,     0,     0,
       0,   285,    41,    27,    28,    29,     0,     0,     0,    30,
      31,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,   192,     0,   193,     0,    40,     0,     0,     0,     0,
      41,    27,    28,    29,     0,     0,     0,   194,   195,     0,
       0,    32,    33,    34,    35,    36,    37,   196,   197,     0,
       0,     0,     0,    40,     0,     0,     0,     0,    41,   171,
     172,   173,    96,    97,    98,   -76,   -76,   -76,   -76,   -76,
     -76,     0,   174,   175,   176,     0,     0,     0,   -76,   -76,
     -76,   177,     0,     0,     0,     0,   178,   -76,     0,    58,
      28,    29,   -76,    58,    28,    29,   189,   190,   191,   171,
     172,   173,    35,    36,    37,     0,    35,    36,    37,     0,
       0,    40,   174,   175,   176,    40,    41,   -70,   -70,   -70,
      41,   177,     0,   -68,   -68,   -68,   178,   -67,   -67,   -67,
     -70,   -70,   -70,   -66,   -66,   -66,   -68,   -68,   -68,   -70,
     -67,   -67,   -67,     0,   -70,   -68,   -66,   -66,   -66,   -67,
     -68,   -69,   -69,   -69,   -67,   -66,     0,   -71,   -71,   -71,
     -66,   -65,   -65,   -65,   -69,   -69,   -69,   -78,   -78,   -78,
     -71,   -71,   -71,   -69,   -65,   -65,   -65,     0,   -69,   -71,
     -78,   -78,   -78,   -65,   -71,   -79,   -79,   -79,   -65,   -78,
       0,   -77,   -77,   -77,   -78,   -80,   -80,   -80,   -79,   -79,
     -79,     0,     0,     0,   -77,   -77,   -77,   -79,   -80,   -80,
     -80,     0,   -79,   -77,     0,     0,     0,   -80,   -77,     0,
       0,     0,   -80
};

static const yytype_int16 yycheck[] =
{
       0,    30,    62,    41,     4,     3,     3,     0,     1,    11,
       3,    40,    41,     0,    39,    41,    11,    12,    13,    57,
      11,    39,    60,    61,    62,    37,    36,    41,    88,    11,
      41,    60,    61,    62,    60,    61,    62,     1,    67,     3,
      39,    39,    39,    38,    39,    39,    60,    61,    62,    60,
      61,    62,   128,   129,   130,    39,    11,    41,    87,    88,
      89,    11,    12,    13,    11,    12,    13,     0,     1,    38,
       3,    40,   121,    39,    11,    41,   152,   134,     0,     1,
      38,     3,   120,     0,     1,    39,     3,    41,    38,   121,
      39,    38,   121,    41,   143,    38,    38,   154,     0,     1,
     149,     3,   131,   160,    39,   162,    41,    38,    38,   158,
     148,    38,    60,    61,    62,    38,    40,   121,   121,   148,
      38,   121,   148,     0,     1,    38,     3,     0,     1,    39,
       3,    41,     0,     1,   148,     3,    40,   148,   121,   177,
     178,    39,    39,    41,    41,    39,   121,    41,   177,   178,
     188,   177,   178,    40,    40,    40,    40,   217,   121,   188,
      65,    66,   188,   177,   178,   194,   177,   178,    40,   245,
     246,   247,    24,    40,   188,    40,    40,   188,   216,   217,
     218,    40,    39,   259,   222,    39,    39,   216,   217,   218,
     216,   217,   218,   222,   223,    39,   222,    39,   255,   248,
     148,    39,   216,   217,   218,   216,   217,   218,   222,    39,
      39,   222,    39,    39,   271,   264,   248,   266,    29,   248,
     249,   278,   279,   128,   129,   130,   275,   265,    29,   177,
     178,   136,   264,    29,   266,   264,   265,   266,    29,   265,
     188,    29,    29,   275,   248,   248,   275,   152,   248,    29,
      40,   265,    29,    39,   265,    40,    40,    40,    40,    40,
     264,   264,   266,   266,   264,   248,   266,    40,   216,   217,
     218,   275,   275,   248,   222,   275,    40,    40,    40,    40,
      38,   264,    11,   266,    39,   248,    39,    39,    39,   264,
      40,   266,   275,     4,     5,     6,     7,     8,     9,    10,
     275,   264,    29,   266,    40,    40,   211,   212,   213,    40,
      36,    39,   275,    29,    39,    39,    38,   265,    38,    38,
      11,    39,    39,    34,    39,    39,    39,    38,    40,    40,
      40,    42,    43,    44,    45,    40,    38,    38,    38,   244,
     245,   246,   247,     4,     5,     6,     7,     8,     9,    10,
      40,    40,    40,    40,   259,     4,     5,     6,     7,     8,
       9,    10,     4,     5,     6,     7,     8,     9,    10,    39,
      39,    24,    39,    34,    39,    39,    39,    11,    40,    40,
      40,    42,    43,    44,    45,    34,    38,    11,    29,    29,
      29,    40,    34,    42,    43,    44,    45,    40,    40,    29,
      42,    43,    44,    45,     4,     5,     6,     7,     8,     9,
      10,     4,     5,     6,     7,     8,     9,    10,     4,     5,
       6,     7,     8,     9,    10,     4,     5,     6,     7,     8,
       9,    10,    39,    39,    34,    39,    39,    39,    29,    40,
      40,    34,    42,    43,    44,    45,    36,    40,    34,    42,
      43,    44,    45,    39,    39,    34,    42,    43,    44,    45,
      39,    39,    39,    42,    43,    44,    45,     4,     5,     6,
       7,     8,     9,    10,     4,     5,     6,     7,     8,     9,
      10,     4,     5,     6,     7,     8,     9,    10,    39,    39,
      39,    39,    39,    39,    39,    39,     4,    34,    20,   120,
     183,   183,    39,   183,    34,    42,    43,    44,    45,    39,
      -1,    34,    42,    43,    44,    45,    39,    -1,    -1,    42,
      43,    44,    45,     1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    -1,    37,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    37,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    -1,    37,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    -1,    37,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    37,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    -1,    37,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    -1,    37,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    37,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    -1,    37,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    -1,    37,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    37,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    -1,    37,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    -1,    37,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    37,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    -1,    37,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    -1,    37,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    37,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    -1,    37,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    -1,    37,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    37,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    36,    -1,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    36,    -1,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    37,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    36,    -1,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    -1,    37,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    37,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    -1,    37,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    -1,    37,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    -1,    37,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    36,    -1,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    36,    -1,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,     1,
      -1,     3,    -1,    33,    -1,    -1,    36,    -1,    38,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,     1,    -1,     3,
      -1,    33,    -1,    -1,    -1,    37,    38,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,     1,    -1,     3,    -1,    33,
      -1,    -1,    -1,    37,    38,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,     1,    -1,     3,    -1,    33,    -1,    -1,
      -1,    37,    38,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,     1,    -1,     3,    -1,    33,    -1,    -1,    -1,    -1,
      38,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    38,    11,
      12,    13,    14,    15,    16,    11,    12,    13,    14,    15,
      16,    -1,    24,    25,    26,    -1,    -1,    -1,    24,    25,
      26,    33,    -1,    -1,    -1,    -1,    38,    33,    -1,    11,
      12,    13,    38,    11,    12,    13,    14,    15,    16,    11,
      12,    13,    24,    25,    26,    -1,    24,    25,    26,    -1,
      -1,    33,    24,    25,    26,    33,    38,    11,    12,    13,
      38,    33,    -1,    11,    12,    13,    38,    11,    12,    13,
      24,    25,    26,    11,    12,    13,    24,    25,    26,    33,
      24,    25,    26,    -1,    38,    33,    24,    25,    26,    33,
      38,    11,    12,    13,    38,    33,    -1,    11,    12,    13,
      38,    11,    12,    13,    24,    25,    26,    11,    12,    13,
      24,    25,    26,    33,    24,    25,    26,    -1,    38,    33,
      24,    25,    26,    33,    38,    11,    12,    13,    38,    33,
      -1,    11,    12,    13,    38,    11,    12,    13,    24,    25,
      26,    -1,    -1,    -1,    24,    25,    26,    33,    24,    25,
      26,    -1,    38,    33,    -1,    -1,    -1,    33,    38,    -1,
      -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    48,    49,    50,    51,    52,    11,     0,
      50,    38,    40,    53,     3,    54,    55,    56,    11,    39,
      41,    36,    55,    57,    58,    37,     3,    11,    12,    13,
      17,    18,    21,    22,    23,    24,    25,    26,    27,    28,
      33,    38,    51,    59,    60,    61,    65,    66,    67,    68,
      69,    70,    71,    74,    75,    77,    11,    38,    11,    69,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    69,
      69,    40,    40,    40,    40,     4,     5,     6,     7,     8,
       9,    10,    34,    42,    43,    44,    45,    76,    78,    79,
      62,    63,    64,    77,    40,    69,    14,    15,    16,    69,
      80,    69,    80,    11,    11,    12,    13,    38,    72,    73,
      72,    72,    69,    11,    39,    69,    69,    80,    69,    39,
      41,    39,    39,    39,    39,    39,    39,    24,    29,    29,
      29,    40,    29,    63,    36,    59,    38,    72,    72,    72,
      69,    11,    58,    19,    72,    39,    39,    39,    40,    39,
      37,    59,    29,    69,    36,    59,    19,    72,    39,    58,
      36,    39,    36,    59,    37,    58,    39,    58,    37,    37,
       1,    11,    12,    13,    24,    25,    26,    33,    38,    70,
      71,    74,    75,    77,    40,    11,    12,    13,    38,    14,
      15,    16,     1,     3,    17,    18,    27,    28,    51,    60,
      61,    65,    66,    67,    68,    69,    11,    12,    13,    38,
      73,    38,    38,    38,    69,    69,    76,    78,    79,    69,
      11,    69,    38,    38,    38,    40,    40,    40,    40,    24,
      72,    72,    72,    39,    69,    69,    80,    69,    39,    40,
      40,    69,    69,    11,    38,    29,    29,    29,    39,    40,
      29,    72,    72,    72,    72,    36,    59,    69,    11,    29,
      39,    39,    39,    58,    19,    40,    39,    72,    37,    59,
      69,    36,    59,    39,    19,    39,    58,    39,    36,    36,
      59,    37,    58,    58,    37,    37
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
#line 275 "skylang.y"
                        {
		//printf("\nESCOPO ATUAL: %s\n",escopoAtual);
		if(passagem == 1){
			(yyval.tree) = add_tree_node("programa");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			tree = (yyval.tree);
		}
	}
#line 2233 "skylang.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 286 "skylang.y"
                                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2245 "skylang.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 293 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2256 "skylang.tab.c"
    break;

  case 5: /* declaration: variable_declaration  */
#line 302 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2267 "skylang.tab.c"
    break;

  case 6: /* declaration: func_declaration  */
#line 308 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2278 "skylang.tab.c"
    break;

  case 7: /* variable_declaration: TYPE ID SEMICOLON  */
#line 317 "skylang.y"
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
#line 2303 "skylang.tab.c"
    break;

  case 8: /* variable_declaration: error  */
#line 337 "skylang.y"
               {
		if(passagem == 1){
			//erro_count = erro_count +1;
			(yyval.tree) = add_tree_node("Erro Sintatico");
			yyerror(yymsg);
		}
	}
#line 2315 "skylang.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 348 "skylang.y"
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
#line 2333 "skylang.tab.c"
    break;

  case 10: /* func_declaration: TYPE ID PARENTESES_INI $@1 params PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 360 "skylang.y"
                                                                                                                { 
																					if(passagem == 1){
											
																						insert_symbol(symbol_ID, (yyvsp[-7].str),"FUNCAO",(yyvsp[-8].str),escopoAtual,-1);
																						//registrador_atual = registrador_atual +1;
																						symbol_ID = symbol_ID +1 ;																	
																						(yyval.tree) = add_tree_node("func_declaration");																		
																						(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
																						(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
																						(yyval.tree) -> value = (yyvsp[-7].str);
																						(yyval.tree) -> type = translate_type((yyvsp[-8].str));
																						(yyval.tree) -> flag_print =1;
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
#line 2370 "skylang.tab.c"
    break;

  case 11: /* params: params_list  */
#line 395 "skylang.y"
                    { 
				if(passagem == 1){
					(yyval.tree) = add_tree_node("params");
		 			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
				}
	}
#line 2381 "skylang.tab.c"
    break;

  case 12: /* params_list: param COLON params_list  */
#line 403 "skylang.y"
                                {
							if(passagem == 1){ 
								(yyval.tree) = add_tree_node("params_list");
		 						(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
							  	(yyval.tree) -> leaf2 = (yyvsp[0].tree);
							}
	}
#line 2393 "skylang.tab.c"
    break;

  case 13: /* params_list: param  */
#line 410 "skylang.y"
               { 
			if(passagem == 1){
				(yyval.tree) = add_tree_node("params_list");
		 	 	(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			}
	}
#line 2404 "skylang.tab.c"
    break;

  case 14: /* params_list: %empty  */
#line 416 "skylang.y"
         { 
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	}
#line 2414 "skylang.tab.c"
    break;

  case 15: /* param: TYPE ID  */
#line 430 "skylang.y"
                { 
				if(passagem == 1){
				
					insert_symbol(symbol_ID, (yyvsp[0].str),"PARAMETRO_FUNCAO",(yyvsp[-1].str),escopoAtual,-1);
					//registrador_atual = registrador_atual +1;
		    		symbol_ID = symbol_ID +1;
			 		(yyval.tree) = add_tree_node("param");
				}
	}
#line 2428 "skylang.tab.c"
    break;

  case 16: /* codeBlock: statement_list  */
#line 441 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CodeBlock");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2439 "skylang.tab.c"
    break;

  case 17: /* statement_list: statement_list statement  */
#line 457 "skylang.y"
                                 {
			(yyval.tree) = add_tree_node("Statement_list");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
#line 2449 "skylang.tab.c"
    break;

  case 18: /* statement_list: %empty  */
#line 462 "skylang.y"
          {	
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Statement_list VAZIO");
		}
		 
	}
#line 2460 "skylang.tab.c"
    break;

  case 19: /* statement: variable_declaration  */
#line 472 "skylang.y"
                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2471 "skylang.tab.c"
    break;

  case 20: /* statement: exp SEMICOLON  */
#line 479 "skylang.y"
                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
		}
	 }
#line 2483 "skylang.tab.c"
    break;

  case 21: /* statement: ifStatement  */
#line 486 "skylang.y"
                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2494 "skylang.tab.c"
    break;

  case 22: /* statement: forAllStatement  */
#line 492 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2505 "skylang.tab.c"
    break;

  case 23: /* statement: outPutStatement SEMICOLON  */
#line 498 "skylang.y"
                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2516 "skylang.tab.c"
    break;

  case 24: /* statement: inputStatement SEMICOLON  */
#line 504 "skylang.y"
                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2527 "skylang.tab.c"
    break;

  case 25: /* statement: callFuncStatement SEMICOLON  */
#line 510 "skylang.y"
                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2538 "skylang.tab.c"
    break;

  case 26: /* statement: RETURN exp SEMICOLON  */
#line 517 "skylang.y"
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
#line 2553 "skylang.tab.c"
    break;

  case 27: /* statement: forStatement  */
#line 528 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forStatement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2564 "skylang.tab.c"
    break;

  case 28: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 538 "skylang.y"
                                                                                                              {
			if(passagem == 1){
				(yyval.tree) = add_tree_node("ForStatement");
				(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
				(yyval.tree) -> leaf2 = (yyvsp[-6].tree);
				(yyval.tree) -> leaf3 = (yyvsp[-4].tree);
				(yyval.tree) -> leaf4 = (yyvsp[-1].tree);
			}
	}
#line 2578 "skylang.tab.c"
    break;

  case 29: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM statement  */
#line 547 "skylang.y"
                                                                             {
			if(passagem == 1){
				(yyval.tree) = add_tree_node("ForStatement");
				(yyval.tree) -> leaf1 = (yyvsp[-6].tree);
				(yyval.tree) -> leaf2 = (yyvsp[-4].tree);
				(yyval.tree) -> leaf3 = (yyvsp[-2].tree);
				(yyval.tree) -> leaf4 = (yyvsp[0].tree);
			}
	}
#line 2592 "skylang.tab.c"
    break;

  case 30: /* callFuncStatement: ID PARENTESES_INI call_params PARENTESES_FIM  */
#line 561 "skylang.y"
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
#line 2611 "skylang.tab.c"
    break;

  case 31: /* call_params: call_params_list  */
#line 579 "skylang.y"
                        {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallParams");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2622 "skylang.tab.c"
    break;

  case 32: /* call_params_list: call_param COLON call_params_list  */
#line 587 "skylang.y"
                                          {
		if(passagem == 1){ 
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2634 "skylang.tab.c"
    break;

  case 33: /* call_params_list: call_param  */
#line 594 "skylang.y"
                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}

	}
#line 2646 "skylang.tab.c"
    break;

  case 34: /* call_params_list: %empty  */
#line 601 "skylang.y"
         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	 }
#line 2656 "skylang.tab.c"
    break;

  case 35: /* call_param: terminal  */
#line 608 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_param terminal");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}

		if(passagem == 2){
			
		}
	}
#line 2671 "skylang.tab.c"
    break;

  case 36: /* inputStatement: READ PARENTESES_INI ID PARENTESES_FIM  */
#line 622 "skylang.y"
                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("read ID");	 
			(yyval.tree) -> flag_print = 1;
			//$$ -> leaf1 = $3;
		}
	}
#line 2683 "skylang.tab.c"
    break;

  case 37: /* outPutStatement: WRITE PARENTESES_INI CONST PARENTESES_FIM  */
#line 633 "skylang.y"
                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("write");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			//$$ -> leaf1 = $3;
		}
	 }
#line 2696 "skylang.tab.c"
    break;

  case 38: /* outPutStatement: WRITE PARENTESES_INI exp PARENTESES_FIM  */
#line 643 "skylang.y"
                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("write");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			snprintf(codigo_tac,1100,"print %s", (yyvsp[-1].tree) -> value_tac);
			(yyval.tree) -> linha_tac = strdup(codigo_tac);
			adiciona_linha_tac(tac_completo,(yyval.tree) -> linha_tac);
			//$$ -> leaf1 = $3;
		}
	 }
#line 2712 "skylang.tab.c"
    break;

  case 39: /* outPutStatement: WRITELN PARENTESES_INI CONST PARENTESES_FIM  */
#line 654 "skylang.y"
                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("writeln");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
			//$$ -> leaf1 = $3;
		}
	 }
#line 2725 "skylang.tab.c"
    break;

  case 40: /* outPutStatement: WRITELN PARENTESES_INI exp PARENTESES_FIM  */
#line 664 "skylang.y"
                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("writeln");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			snprintf(codigo_tac,1100,"println %s", (yyvsp[-1].tree) -> value_tac);
			(yyval.tree) -> linha_tac = strdup(codigo_tac);
			adiciona_linha_tac(tac_completo,(yyval.tree) -> linha_tac);
			//$$ -> leaf1 = $3;
		}
	 }
#line 2741 "skylang.tab.c"
    break;

  case 41: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM statement  */
#line 679 "skylang.y"
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
#line 2772 "skylang.tab.c"
    break;

  case 42: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 706 "skylang.y"
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
#line 2803 "skylang.tab.c"
    break;

  case 43: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement  */
#line 736 "skylang.y"
                                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2816 "skylang.tab.c"
    break;

  case 44: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement ELSE statement  */
#line 744 "skylang.y"
                                                                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2830 "skylang.tab.c"
    break;

  case 45: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 754 "skylang.y"
                                                                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2843 "skylang.tab.c"
    break;

  case 46: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM ELSE CHAVES_INI statement_list CHAVES_FIM  */
#line 762 "skylang.y"
                                                                                                                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-5].tree);
			(yyval.tree) -> leaf3 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2857 "skylang.tab.c"
    break;

  case 47: /* exp: NEGATION exp  */
#line 776 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	 }
#line 2869 "skylang.tab.c"
    break;

  case 48: /* exp: setExp  */
#line 784 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	 }
#line 2881 "skylang.tab.c"
    break;

  case 49: /* exp: aritExp  */
#line 791 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> result;
		}
	 }
#line 2894 "skylang.tab.c"
    break;

  case 50: /* exp: relExp  */
#line 799 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	 }
#line 2906 "skylang.tab.c"
    break;

  case 51: /* exp: terminal  */
#line 806 "skylang.y"
                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> value_tac;
		}
	 }
#line 2919 "skylang.tab.c"
    break;

  case 52: /* exp: assignmentExp  */
#line 815 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	}
#line 2931 "skylang.tab.c"
    break;

  case 53: /* assignmentExp: terminal ASSIGN exp  */
#line 825 "skylang.y"
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
#line 2951 "skylang.tab.c"
    break;

  case 54: /* assignmentExp: terminal ASSIGN CONST  */
#line 840 "skylang.y"
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
#line 2966 "skylang.tab.c"
    break;

  case 55: /* setExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 853 "skylang.y"
                                                                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 2978 "skylang.tab.c"
    break;

  case 56: /* setExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 860 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 2990 "skylang.tab.c"
    break;

  case 57: /* setExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 867 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 3002 "skylang.tab.c"
    break;

  case 58: /* terms_set: aritSetExp  */
#line 877 "skylang.y"
                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terms_set");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 3013 "skylang.tab.c"
    break;

  case 59: /* aritSetExp: ID  */
#line 886 "skylang.y"
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
#line 3036 "skylang.tab.c"
    break;

  case 60: /* aritSetExp: FLOAT  */
#line 904 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal FLOAT");
		}
		 
	 }
#line 3047 "skylang.tab.c"
    break;

  case 61: /* aritSetExp: INTEGER  */
#line 910 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal INTEGER");
		}
		 
	 }
#line 3058 "skylang.tab.c"
    break;

  case 62: /* aritSetExp: PARENTESES_INI EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM PARENTESES_FIM  */
#line 916 "skylang.y"
                                                                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
		}
	}
#line 3070 "skylang.tab.c"
    break;

  case 63: /* aritExp: terminal OP exp  */
#line 938 "skylang.y"
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
			snprintf(codigo_tac,1100,"%s $%d, %s, %s",(yyvsp[-1].tree) -> value_tac, registrador_atual, (yyvsp[-2].tree) -> value_tac,(yyvsp[0].tree) -> value_tac);
			//printf("\n%s",codigo_tac);
			snprintf(char_reg,999,"$%d",registrador_atual);
			(yyval.tree) -> result = strdup(char_reg);
			registrador_atual ++;
			(yyval.tree) -> linha_tac = strdup(codigo_tac);
			(yyval.tree) -> printa_tac = 1;
			adiciona_linha_tac(tac_completo,(yyval.tree) -> linha_tac);
		} 
	 }
#line 3096 "skylang.tab.c"
    break;

  case 64: /* relExp: terminal rel exp  */
#line 961 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("relExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			check_set_type((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type);
		}
	 }
#line 3110 "skylang.tab.c"
    break;

  case 65: /* rel: CGE  */
#line 973 "skylang.y"
            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   >=");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3123 "skylang.tab.c"
    break;

  case 66: /* rel: CGT  */
#line 981 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   >");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3136 "skylang.tab.c"
    break;

  case 67: /* rel: CNE  */
#line 989 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   !=");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3149 "skylang.tab.c"
    break;

  case 68: /* rel: CLT  */
#line 997 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   <");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3162 "skylang.tab.c"
    break;

  case 69: /* rel: AND  */
#line 1005 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   &&");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3175 "skylang.tab.c"
    break;

  case 70: /* rel: CLE  */
#line 1013 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("<=");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3188 "skylang.tab.c"
    break;

  case 71: /* rel: CEQ  */
#line 1021 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("==");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print = 1;
		}
	}
#line 3201 "skylang.tab.c"
    break;

  case 72: /* terminal: ID  */
#line 1043 "skylang.y"
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
#line 3230 "skylang.tab.c"
    break;

  case 73: /* terminal: FLOAT  */
#line 1067 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal CONST");
			(yyval.tree) -> type = 2;
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
		 
	 }
#line 3245 "skylang.tab.c"
    break;

  case 74: /* terminal: INTEGER  */
#line 1077 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal CONST");
			(yyval.tree) -> type = 1;
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
		 
	 }
#line 3260 "skylang.tab.c"
    break;

  case 75: /* terminal: PARENTESES_INI exp PARENTESES_FIM  */
#line 1088 "skylang.y"
                                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal EXP");
			(yyval.tree)->leaf1 =(yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[-1].tree) -> value_tac;
		}
	}
#line 3273 "skylang.tab.c"
    break;

  case 76: /* ASSIGN: EQUALS  */
#line 1101 "skylang.y"
       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" =");
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3284 "skylang.tab.c"
    break;

  case 77: /* OP: MULT  */
#line 1111 "skylang.y"
             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" *");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "mul";
		}
	 }
#line 3296 "skylang.tab.c"
    break;

  case 78: /* OP: PLUS  */
#line 1118 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" +");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "add";
		}
	 }
#line 3308 "skylang.tab.c"
    break;

  case 79: /* OP: MINUS  */
#line 1125 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" -");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "sub";
		}
	 }
#line 3320 "skylang.tab.c"
    break;

  case 80: /* OP: DIV  */
#line 1132 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" /");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "div";
		}
	 }
#line 3332 "skylang.tab.c"
    break;

  case 81: /* CONST: EMPTY  */
#line 1143 "skylang.y"
     {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("EMPTY");
			(yyval.tree) -> type = 3;
			(yyval.tree) -> value = (yyvsp[0].str);
		}
}
#line 3344 "skylang.tab.c"
    break;

  case 82: /* CONST: CHAR  */
#line 1151 "skylang.y"
     {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("CHAR");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print=1;
		}
}
#line 3357 "skylang.tab.c"
    break;

  case 83: /* CONST: STRING  */
#line 1160 "skylang.y"
       {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("STRING");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print=1;
		}
}
#line 3370 "skylang.tab.c"
    break;


#line 3374 "skylang.tab.c"

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

#line 1171 "skylang.y"


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
