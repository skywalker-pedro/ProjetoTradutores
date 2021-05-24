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
extern tac_lines * elt_1;
extern erros * elt_erros;
extern erros* erros_semanticos;
int symbol_ID = 0;
treeNode* tree = NULL;

/////////////////////////////////// Variaveis de controle de escopo, declaracao e checagem de tipos
int existe_simbolo;
int existe_main = 0;
int flag_redeclaracao_funcao;
int flag_redeclaracao_variavel;
int registrador_atual = 0;
char* tipo_funcao_atual;
int conta_parametros = 0;
int conta_parametros_2 = 0;

//int erro_count = 0;
int aux=1;
int escopo_correto;
int argumento_func;
char char_reg[999];
int int_reg;
char codigo_tac[1100];
char erro_atual[1500];
int contador_if;
//////////////////////////////////
char * escopoAtual = "Global";
/* Print TS Function*/
void printTS(){
	Hash_table* aux = hashed_symbol_table;
    while(aux!=NULL){
        printf("\n Id simbolo: %d | Nome simbolo: %s | Tipo simbolo: %s %s | Escopo: %s |",aux->id,aux->name,aux->type,aux->varType, aux -> escopo);
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
		snprintf(erro_atual,1100,"--> ERRO SEMANTICO LINHA %d, coluna %d: Operacao nao permitida para o tipo SET ",num_linha_1,posicao_linha_1);
		adiciona_linha_erro(erros_semanticos,strdup(erro_atual));
		//printf("\n--> ERRO SEMANTICO LINHA %d, coluna %d: Operacao nao permitida para o tipo SET ",num_linha_1,posicao_linha_1);
		return 1;
	}else{
		return 0;
	}
}

int check_num_params(char*symbol,char*symbol_scope){
	Hash_table* aux = hashed_symbol_table;
	int temp = -1;
    while(aux!=NULL){
		//strcmp retorna 0 caso as strings sejam iguais
        if (strcmp(aux->name,symbol)==0){
			if (strcmp(aux->escopo,symbol_scope)==0){
				return aux -> num_params;
			}
		}
        aux = aux -> hh.next;
    }
	return temp;
	//free(aux);
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


#line 339 "skylang.tab.c"

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
  YYSYMBOL_IS_SET = 30,                    /* IS_SET  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_NEGATION = 32,                  /* NEGATION  */
  YYSYMBOL_EQUALS = 33,                    /* EQUALS  */
  YYSYMBOL_APOST = 34,                     /* APOST  */
  YYSYMBOL_CHAVES_INI = 35,                /* CHAVES_INI  */
  YYSYMBOL_CHAVES_FIM = 36,                /* CHAVES_FIM  */
  YYSYMBOL_PARENTESES_INI = 37,            /* PARENTESES_INI  */
  YYSYMBOL_PARENTESES_FIM = 38,            /* PARENTESES_FIM  */
  YYSYMBOL_SEMICOLON = 39,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 40,                     /* COLON  */
  YYSYMBOL_PLUS = 41,                      /* PLUS  */
  YYSYMBOL_MINUS = 42,                     /* MINUS  */
  YYSYMBOL_MULT = 43,                      /* MULT  */
  YYSYMBOL_DIV = 44,                       /* DIV  */
  YYSYMBOL_THEN = 45,                      /* THEN  */
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
  YYSYMBOL_statement_list = 57,            /* statement_list  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_forStatement = 59,              /* forStatement  */
  YYSYMBOL_callFuncStatement = 60,         /* callFuncStatement  */
  YYSYMBOL_call_params = 61,               /* call_params  */
  YYSYMBOL_call_params_list = 62,          /* call_params_list  */
  YYSYMBOL_call_param = 63,                /* call_param  */
  YYSYMBOL_inputStatement = 64,            /* inputStatement  */
  YYSYMBOL_outPutStatement = 65,           /* outPutStatement  */
  YYSYMBOL_forAllStatement = 66,           /* forAllStatement  */
  YYSYMBOL_ifStatement = 67,               /* ifStatement  */
  YYSYMBOL_exp = 68,                       /* exp  */
  YYSYMBOL_assignmentExp = 69,             /* assignmentExp  */
  YYSYMBOL_setExp = 70,                    /* setExp  */
  YYSYMBOL_terms_set = 71,                 /* terms_set  */
  YYSYMBOL_aritSetExp = 72,                /* aritSetExp  */
  YYSYMBOL_aritExp = 73,                   /* aritExp  */
  YYSYMBOL_relExp = 74,                    /* relExp  */
  YYSYMBOL_rel = 75,                       /* rel  */
  YYSYMBOL_terminal = 76,                  /* terminal  */
  YYSYMBOL_ASSIGN = 77,                    /* ASSIGN  */
  YYSYMBOL_OP = 78,                        /* OP  */
  YYSYMBOL_CONST = 79                      /* CONST  */
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
#define YYLAST   2410

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  314

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
       0,   298,   298,   309,   316,   325,   331,   340,   362,   373,
     373,   422,   430,   437,   443,   457,   469,   485,   490,   500,
     507,   514,   520,   526,   533,   539,   546,   559,   569,   579,
     594,   618,   626,   633,   640,   647,   665,   677,   687,   697,
     705,   719,   747,   778,   798,   808,   816,   830,   839,   846,
     855,   865,   874,   885,   901,   917,   925,   934,   939,   950,
     959,   977,   983,   989,   997,  1005,  1027,  1050,  1089,  1098,
    1107,  1116,  1125,  1134,  1142,  1164,  1188,  1198,  1209,  1222,
    1232,  1239,  1246,  1253,  1264,  1272,  1281
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
  "READ", "EXISTS", "ADD", "REMOVE", "FOR", "FORALL", "IN", "IS_SET", "OR",
  "NEGATION", "EQUALS", "APOST", "CHAVES_INI", "CHAVES_FIM",
  "PARENTESES_INI", "PARENTESES_FIM", "SEMICOLON", "COLON", "PLUS",
  "MINUS", "MULT", "DIV", "THEN", "$accept", "programa", "declarationList",
  "declaration", "variable_declaration", "func_declaration", "$@1",
  "params", "params_list", "param", "codeBlock", "statement_list",
  "statement", "forStatement", "callFuncStatement", "call_params",
  "call_params_list", "call_param", "inputStatement", "outPutStatement",
  "forAllStatement", "ifStatement", "exp", "assignmentExp", "setExp",
  "terms_set", "aritSetExp", "aritExp", "relExp", "rel", "terminal",
  "ASSIGN", "OP", "CONST", YY_NULLPTR
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

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    14,    -9,    19,    65,    82,    89,    93,   -21,  -116,
      98,     6,   116,     7,    -4,   -18,   -15,    -3,    62,    -8,
       7,  1153,   -10,     4,  1181,   138,    25,   334,    71,   341,
     382,    16,    17,    47,    50,    54,    58,    74,    81,   106,
     111,   382,  2196,  1209,  1237,  1265,    64,    91,   120,  1293,
    1321,   137,   139,   145,   146,   147,   348,   148,    36,   392,
     151,  2196,   121,   121,   150,    45,    45,    45,   382,   159,
     180,   156,   158,  1349,  1377,  1405,  1433,  2218,  2227,  2249,
    2258,  2280,  2289,  2311,  2160,  2320,  2342,  2351,  2373,   382,
    2187,   382,   162,   163,    84,   104,  1461,   164,   170,   171,
     172,   179,   181,   183,   184,   189,   199,   201,   202,   195,
     197,   209,   210,   219,   220,   222,   213,   224,   216,   452,
     218,   221,   223,   229,   231,    36,  1489,   235,   237,   238,
     242,   244,    45,    45,    45,   404,   404,   404,   382,   250,
     246,   217,  1153,   565,   261,   266,   268,   267,   279,   281,
     282,   284,  1517,  2105,   404,   404,   404,   285,   286,   287,
    2196,  1545,   593,  1573,   289,   297,   298,   322,  1153,  1601,
     288,   291,   332,   333,  1629,  1657,  1153,  1153,  1685,  1713,
    1741,  1769,  1797,  1825,  1853,   459,   466,   473,   326,   327,
     328,   329,  2196,  2196,   330,   331,   350,   371,   514,  1881,
     114,   122,   127,  2196,   340,   347,   372,   621,   359,   382,
     335,   373,   376,   649,   677,   379,   381,   387,   705,   733,
     388,   383,   394,   399,   401,   402,   403,   411,    45,    45,
      45,   430,   446,   448,  2196,   121,  2196,   449,   450,   451,
    2196,   382,   431,   761,   789,   817,   845,    45,    45,    45,
     469,   476,   483,   475,   521,   494,   495,   496,   497,   131,
     873,   901,   498,   499,   508,   510,   511,   512,   404,   404,
     404,   504,  1909,   382,   477,   404,   404,   404,   505,   506,
     507,  1153,   929,   509,   513,   515,   522,   523,   529,   531,
     532,  1937,  2133,  2196,  1965,   533,   534,   535,   957,   985,
     536,  1153,  1013,   540,  1993,  2021,  1153,  1153,  1041,  1069,
    2049,  2077,  1097,  1125
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
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,   542,     0,  -116,  -116,  -116,   530,  -116,
    -116,  -113,  -115,   -59,   -54,  -116,   424,  -116,    -6,    -5,
      -1,    24,   -29,   -20,   -11,   175,   178,    44,    66,   400,
     -37,   405,   409,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    43,     7,    13,    15,    16,    17,
      23,    24,    44,    45,    46,    92,    93,    94,    47,    48,
      49,    50,    51,    52,    53,   112,   113,    54,    55,    89,
      56,    90,    91,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    60,     8,   104,     6,   198,     1,    18,     2,    -9,
      14,   143,    71,    72,    -8,    -8,    11,    -8,    12,     9,
      19,    95,   194,   -11,   198,   198,   198,    21,   -12,   152,
     122,   195,    97,   101,   103,   -13,    57,    20,   163,   116,
      25,   194,   194,   194,    -9,   -14,   169,   200,   201,   202,
     195,   195,   195,    61,    62,   175,   106,   107,   108,   178,
     120,   121,   123,   180,   181,    -2,     1,   214,     2,   109,
     110,   111,   215,   203,   -34,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,    -4,    -4,    63,    -4,   196,    64,    95,    -5,
      -5,    65,    -5,    -6,    -6,    66,    -6,   220,    -3,    -3,
     -15,    -3,   -15,    73,   -77,   196,   196,   196,   197,   150,
     -77,    67,   -77,   -77,   -77,   -77,    -7,    -7,    68,    -7,
     216,   217,   -33,   198,   125,   218,   213,   197,   197,   197,
      74,   167,   185,   186,   187,    98,    99,   100,   -10,   -10,
     194,   -10,   -35,    69,   -35,   188,   189,   190,    70,   195,
     219,   191,   -75,   192,   -75,   198,   198,   282,   193,    75,
     -77,   105,   -77,   232,   233,   -76,   198,   -76,   291,   -78,
     117,   -78,   194,   194,   237,   257,    76,   299,   -52,   302,
     239,   195,   195,   194,   -48,   -49,   -50,   199,   305,   308,
      96,   118,   195,   310,   311,   -47,   119,   198,   198,   198,
     124,   -31,   126,   198,   196,   255,   256,   258,   -85,   -86,
     -84,   262,   263,   214,   194,   194,   194,   127,   215,   128,
     194,   129,   130,   195,   195,   195,   197,   131,   -60,   195,
     -62,   -61,   132,   214,   133,   214,   196,   196,   215,   135,
     215,   114,   115,   220,   283,   214,   134,   196,   -59,   136,
     215,   137,   138,   139,   140,   -32,   198,   -67,   197,   197,
     -53,   151,   -54,   220,   300,   220,   216,   217,   -66,   197,
     -30,   218,   213,   194,   -38,   220,   -37,   -40,   196,   196,
     196,   -39,   195,   -36,   196,   -57,   216,   217,   216,   217,
     154,   218,   213,   218,   213,   155,   219,   156,   216,   217,
     197,   197,   197,   218,   213,   157,   197,   144,   145,   146,
     147,   148,   149,   227,   227,   227,   219,   158,   219,   159,
     -63,   160,   161,   176,   -58,   -55,   -56,   171,   219,   164,
     165,   166,   227,   227,   227,   172,   173,   196,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,    77,    78,    79,    80,    81,    82,    83,   197,
     174,   -64,   -65,   228,   229,   230,   231,   -75,   -52,   -48,
     238,    58,   240,   -75,   -76,   -75,   -75,   -75,   -75,   -85,
     -76,    84,   -76,   -76,   -76,   -76,   -86,   -51,   -49,    85,
      86,    87,    88,    59,    28,    29,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   250,   251,   252,    35,    36,    37,   -50,
     241,   -84,    40,   242,    41,   221,   222,   223,   243,    42,
     244,   -60,   265,   266,   267,   -75,   245,   246,   224,   225,
     226,   -75,   -62,   -75,   -75,   -75,   -75,   -61,   247,   248,
     249,   253,   264,   278,   279,   280,   227,   227,   227,   -59,
     285,   286,   287,   227,   227,   227,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -47,   -78,   254,   259,   284,   260,
     261,   -78,   -75,   -78,   -78,   -78,   -78,   -75,   268,   -77,
     -75,   -75,   -75,   -75,   -77,   269,   -76,   -77,   -77,   -77,
     -77,   -76,   270,   271,   -76,   -76,   -76,   -76,    77,    78,
      79,    80,    81,    82,    83,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -67,   -53,   -54,   -66,   272,   274,   273,   275,
     276,   277,   -57,   288,   289,   290,    10,    84,   293,   141,
      22,   294,   -51,   295,   -78,    85,    86,    87,    88,   -78,
     296,   297,   -78,   -78,   -78,   -78,   -43,   -58,   -43,   -55,
     -56,   -63,   -64,   -65,   304,   306,   -43,   -43,   -43,     0,
       0,     0,   -43,   -43,   153,     0,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -45,   -43,   -45,   -43,   234,     0,
       0,   -43,   -43,   235,   -45,   -45,   -45,   236,     0,     0,
     -45,   -45,   170,     0,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,    -8,   -45,    -8,   -45,     0,     0,     0,   -45,
     -45,     0,    -8,    -8,    -8,     0,     0,     0,    -8,    -8,
      -8,     0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
     -19,    -8,   -19,    -8,     0,     0,     0,    -8,    -8,     0,
     -19,   -19,   -19,     0,     0,     0,   -19,   -19,   -19,     0,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -27,   -19,
     -27,   -19,     0,     0,     0,   -19,   -19,     0,   -27,   -27,
     -27,     0,     0,     0,   -27,   -27,   -27,     0,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,   -22,   -27,   -22,   -27,
       0,     0,     0,   -27,   -27,     0,   -22,   -22,   -22,     0,
       0,     0,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -21,   -22,   -21,   -22,     0,     0,
       0,   -22,   -22,     0,   -21,   -21,   -21,     0,     0,     0,
     -21,   -21,   -21,     0,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -25,   -21,   -25,   -21,     0,     0,     0,   -21,
     -21,     0,   -25,   -25,   -25,     0,     0,     0,   -25,   -25,
     -25,     0,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -24,   -25,   -24,   -25,     0,     0,     0,   -25,   -25,     0,
     -24,   -24,   -24,     0,     0,     0,   -24,   -24,   -24,     0,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -23,   -24,
     -23,   -24,     0,     0,     0,   -24,   -24,     0,   -23,   -23,
     -23,     0,     0,     0,   -23,   -23,   -23,     0,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,   -20,   -23,   -20,   -23,
       0,     0,     0,   -23,   -23,     0,   -20,   -20,   -20,     0,
       0,     0,   -20,   -20,   -20,     0,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,    -7,   -20,    -7,   -20,     0,     0,
       0,   -20,   -20,     0,    -7,    -7,    -7,     0,     0,     0,
      -7,    -7,    -7,     0,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,   -26,    -7,   -26,    -7,     0,     0,     0,    -7,
      -7,     0,   -26,   -26,   -26,     0,     0,     0,   -26,   -26,
     -26,     0,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     -43,   -26,   -43,   -26,     0,     0,     0,   -26,   -26,     0,
     -43,   -43,   -43,     0,     0,     0,   -43,   -43,   292,     0,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -45,   -43,
     -45,   -43,     0,     0,     0,   -43,   -43,     0,   -45,   -45,
     -45,     0,     0,     0,   -45,   -45,   303,     0,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -44,   -45,   -44,   -45,
       0,     0,     0,   -45,   -45,     0,   -44,   -44,   -44,     0,
       0,     0,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -41,   -44,   -41,   -44,     0,     0,
       0,   -44,   -44,     0,   -41,   -41,   -41,     0,     0,     0,
     -41,   -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,   -29,   -41,   -29,   -41,     0,     0,     0,   -41,
     -41,     0,   -29,   -29,   -29,     0,     0,     0,   -29,   -29,
     -29,     0,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -42,   -29,   -42,   -29,     0,     0,     0,   -29,   -29,     0,
     -42,   -42,   -42,     0,     0,     0,   -42,   -42,   -42,     0,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -46,   -42,
     -46,   -42,     0,     0,     0,   -42,   -42,     0,   -46,   -46,
     -46,     0,     0,     0,   -46,   -46,   -46,     0,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -28,   -46,   -28,   -46,
       0,     0,     0,   -46,   -46,     0,   -28,   -28,   -28,     0,
       0,     0,   -28,   -28,   -28,     0,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -18,   -28,   -18,   -28,     0,     0,
       0,   -28,   -28,     0,   -18,   -18,   -18,     0,     0,     0,
     -18,   -18,     0,     0,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   184,   -18,    26,   -18,     0,     0,     0,   -18,
     -18,     0,    27,    28,    29,     0,     0,     0,    30,    31,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
     -19,    40,   -19,    41,     0,     0,     0,   -16,    42,     0,
     -19,   -19,   -19,     0,     0,     0,   -19,   -19,     0,     0,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -17,   -19,
     -17,   -19,     0,     0,     0,   -19,   -19,     0,   -17,   -17,
     -17,     0,     0,     0,   -17,   -17,     0,     0,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -27,   -17,   -27,   -17,
       0,     0,     0,   -17,   -17,     0,   -27,   -27,   -27,     0,
       0,     0,   -27,   -27,     0,     0,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -22,   -27,   -22,   -27,     0,     0,
       0,   -27,   -27,     0,   -22,   -22,   -22,     0,     0,     0,
     -22,   -22,     0,     0,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -21,   -22,   -21,   -22,     0,     0,     0,   -22,
     -22,     0,   -21,   -21,   -21,     0,     0,     0,   -21,   -21,
       0,     0,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -25,   -21,   -25,   -21,     0,     0,     0,   -21,   -21,     0,
     -25,   -25,   -25,     0,     0,     0,   -25,   -25,     0,     0,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -24,   -25,
     -24,   -25,     0,     0,     0,   -25,   -25,     0,   -24,   -24,
     -24,     0,     0,     0,   -24,   -24,     0,     0,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -23,   -24,   -23,   -24,
       0,     0,     0,   -24,   -24,     0,   -23,   -23,   -23,     0,
       0,     0,   -23,   -23,     0,     0,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,   -23,   -20,   -23,   -20,   -23,     0,     0,
       0,   -23,   -23,     0,   -20,   -20,   -20,     0,     0,     0,
     -20,   -20,     0,     0,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -26,   -20,   -26,   -20,     0,     0,     0,   -20,
     -20,     0,   -26,   -26,   -26,     0,     0,     0,   -26,   -26,
       0,     0,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
     207,   -26,   208,   -26,     0,     0,     0,   -26,   -26,     0,
      27,    28,    29,     0,     0,     0,   209,   210,     0,     0,
      32,    33,    34,    35,    36,    37,   211,   212,   184,    40,
      26,    41,     0,     0,   142,     0,    42,     0,    27,    28,
      29,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,   184,    40,    26,    41,
       0,     0,     0,   162,    42,     0,    27,    28,    29,     0,
       0,     0,    30,    31,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,   -44,    40,   -44,    41,     0,     0,
     168,     0,    42,     0,   -44,   -44,   -44,     0,     0,     0,
     -44,   -44,     0,     0,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -41,   -44,   -41,   -44,     0,     0,     0,   -44,
     -44,     0,   -41,   -41,   -41,     0,     0,     0,   -41,   -41,
       0,     0,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     184,   -41,    26,   -41,     0,     0,     0,   -41,   -41,     0,
      27,    28,    29,     0,     0,     0,    30,    31,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,   184,    40,
      26,    41,     0,     0,   177,     0,    42,     0,    27,    28,
      29,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,   -29,    40,   -29,    41,
       0,     0,     0,   179,    42,     0,   -29,   -29,   -29,     0,
       0,     0,   -29,   -29,     0,     0,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -42,   -29,   -42,   -29,     0,     0,
       0,   -29,   -29,     0,   -42,   -42,   -42,     0,     0,     0,
     -42,   -42,     0,     0,   -42,   -42,   -42,   -42,   -42,   -42,
     -42,   -42,   184,   -42,    26,   -42,     0,     0,     0,   -42,
     -42,     0,    27,    28,    29,     0,     0,     0,    30,    31,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
     184,    40,    26,    41,     0,     0,     0,   182,    42,     0,
      27,    28,    29,     0,     0,     0,    30,    31,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,   -46,    40,
     -46,    41,     0,     0,     0,   183,    42,     0,   -46,   -46,
     -46,     0,     0,     0,   -46,   -46,     0,     0,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,   -28,   -46,   -28,   -46,
       0,     0,     0,   -46,   -46,     0,   -28,   -28,   -28,     0,
       0,     0,   -28,   -28,     0,     0,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,    -8,   -28,    -8,   -28,     0,     0,
       0,   -28,   -28,     0,    -8,    -8,    -8,     0,     0,     0,
      -8,    -8,     0,     0,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -7,    -8,    -7,    -8,     0,     0,     0,    -8,
      -8,     0,    -7,    -7,    -7,     0,     0,     0,    -7,    -7,
       0,     0,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
     207,    -7,   208,    -7,     0,     0,     0,    -7,    -7,     0,
      27,    28,    29,     0,     0,     0,   209,   210,     0,     0,
      32,    33,    34,    35,    36,    37,   211,   212,   184,    40,
      26,    41,     0,     0,   281,     0,    42,     0,    27,    28,
      29,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,   207,    40,   208,    41,
       0,     0,     0,   298,    42,     0,    27,    28,    29,     0,
       0,     0,   209,   210,     0,     0,    32,    33,    34,    35,
      36,    37,   211,   212,   207,    40,   208,    41,     0,     0,
     301,     0,    42,     0,    27,    28,    29,     0,     0,     0,
     209,   210,     0,     0,    32,    33,    34,    35,    36,    37,
     211,   212,   184,    40,    26,    41,     0,     0,   307,     0,
      42,     0,    27,    28,    29,     0,     0,     0,    30,    31,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
     184,    40,    26,    41,     0,     0,     0,   309,    42,     0,
      27,    28,    29,     0,     0,     0,    30,    31,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,   184,    40,
      26,    41,     0,     0,     0,   312,    42,     0,    27,    28,
      29,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,   184,    40,    26,    41,
       0,     0,     0,   313,    42,     0,    27,    28,    29,     0,
       0,     0,    30,    31,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,   207,    40,   208,    41,     0,     0,
       0,     0,    42,     0,    27,    28,    29,     0,     0,     0,
     209,   210,     0,     0,    32,    33,    34,    35,    36,    37,
     211,   212,     0,    40,     0,    41,     0,     0,     0,     0,
      42,   -79,   -79,   -79,   -79,   -79,   -79,     0,     0,     0,
       0,     0,     0,     0,   -79,   -79,   -79,     0,     0,     0,
     -79,     0,   -79,     0,     0,     0,     0,   -79,    59,    28,
      29,   204,   205,   206,     0,     0,     0,   185,   186,   187,
       0,    35,    36,    37,     0,     0,     0,    40,     0,    41,
     188,   189,   190,     0,    42,     0,   191,     0,   192,   -73,
     -73,   -73,     0,   193,     0,     0,     0,     0,   -71,   -71,
     -71,     0,   -73,   -73,   -73,     0,     0,     0,   -73,     0,
     -73,   -71,   -71,   -71,     0,   -73,     0,   -71,     0,   -71,
     -70,   -70,   -70,     0,   -71,     0,     0,     0,     0,   -69,
     -69,   -69,     0,   -70,   -70,   -70,     0,     0,     0,   -70,
       0,   -70,   -69,   -69,   -69,     0,   -70,     0,   -69,     0,
     -69,   -72,   -72,   -72,     0,   -69,     0,     0,     0,     0,
     -74,   -74,   -74,     0,   -72,   -72,   -72,     0,     0,     0,
     -72,     0,   -72,   -74,   -74,   -74,     0,   -72,     0,   -74,
       0,   -74,   -68,   -68,   -68,     0,   -74,     0,     0,     0,
       0,   -81,   -81,   -81,     0,   -68,   -68,   -68,     0,     0,
       0,   -68,     0,   -68,   -81,   -81,   -81,     0,   -68,     0,
     -81,     0,   -81,   -82,   -82,   -82,     0,   -81,     0,     0,
       0,     0,   -80,   -80,   -80,     0,   -82,   -82,   -82,     0,
       0,     0,   -82,     0,   -82,   -80,   -80,   -80,     0,   -82,
       0,   -80,     0,   -80,   -83,   -83,   -83,     0,   -80,     0,
       0,     0,     0,     0,     0,     0,     0,   -83,   -83,   -83,
       0,     0,     0,   -83,     0,   -83,     0,     0,     0,     0,
     -83
};

static const yytype_int16 yycheck[] =
{
       0,    30,    11,    63,     4,    42,     1,    11,     3,     3,
       3,   126,    41,    42,     0,     1,    37,     3,    39,     0,
      38,    58,    42,    38,    61,    62,    63,    35,    38,   142,
      90,    42,    61,    62,    63,    38,    11,    40,   153,    68,
      36,    61,    62,    63,    38,    38,   161,    11,    12,    13,
      61,    62,    63,    37,    37,   168,    11,    12,    13,   174,
      89,    90,    91,   176,   177,     0,     1,   126,     3,    24,
      25,    26,   126,    37,    38,     4,     5,     6,     7,     8,
       9,    10,     0,     1,    37,     3,    42,    37,   125,     0,
       1,    37,     3,     0,     1,    37,     3,   126,     0,     1,
      38,     3,    40,    39,    33,    61,    62,    63,    42,   138,
      39,    37,    41,    42,    43,    44,     0,     1,    37,     3,
     126,   126,    38,   160,    40,   126,   126,    61,    62,    63,
      39,   160,    11,    12,    13,    14,    15,    16,     0,     1,
     160,     3,    38,    37,    40,    24,    25,    26,    37,   160,
     126,    30,    38,    32,    40,   192,   193,   272,    37,    39,
      38,    11,    40,   192,   193,    38,   203,    40,   281,    38,
      11,    40,   192,   193,   203,   235,    39,   292,    39,   294,
     209,   192,   193,   203,    39,    39,    39,    39,   301,   304,
      39,    11,   203,   306,   307,    39,    38,   234,   235,   236,
      38,    38,    38,   240,   160,   234,   235,   236,    38,    38,
      38,   240,   241,   272,   234,   235,   236,    38,   272,    38,
     240,    38,    38,   234,   235,   236,   160,    38,    29,   240,
      29,    29,    37,   292,    37,   294,   192,   193,   292,    29,
     294,    66,    67,   272,   273,   304,    37,   203,    29,    29,
     304,    29,    39,    29,    38,    38,   293,    39,   192,   193,
      39,    11,    39,   292,   293,   294,   272,   272,    39,   203,
      39,   272,   272,   293,    39,   304,    39,    39,   234,   235,
     236,    39,   293,    39,   240,    39,   292,   292,   294,   294,
      29,   292,   292,   294,   294,    29,   272,    29,   304,   304,
     234,   235,   236,   304,   304,    38,   240,   132,   133,   134,
     135,   136,   137,   135,   136,   137,   292,    38,   294,    38,
      29,    39,    38,    35,    39,    39,    39,    38,   304,   154,
     155,   156,   154,   155,   156,    38,    38,   293,     4,     5,
       6,     7,     8,     9,    10,     4,     5,     6,     7,     8,
       9,    10,     4,     5,     6,     7,     8,     9,    10,   293,
      38,    29,    29,    37,    37,    37,    37,    33,    38,    38,
      11,    37,    37,    39,    33,    41,    42,    43,    44,    39,
      39,    33,    41,    42,    43,    44,    39,    39,    38,    41,
      42,    43,    44,    11,    12,    13,     4,     5,     6,     7,
       8,     9,    10,   228,   229,   230,    24,    25,    26,    38,
      37,    39,    30,    37,    32,    11,    12,    13,    39,    37,
      39,    38,   247,   248,   249,    33,    39,    39,    24,    25,
      26,    39,    38,    41,    42,    43,    44,    38,    37,    37,
      37,    11,    11,   268,   269,   270,   268,   269,   270,    38,
     275,   276,   277,   275,   276,   277,     4,     5,     6,     7,
       8,     9,    10,     4,     5,     6,     7,     8,     9,    10,
       4,     5,     6,     7,     8,     9,    10,     4,     5,     6,
       7,     8,     9,    10,    38,    33,    38,    38,    11,    39,
      39,    39,    33,    41,    42,    43,    44,    38,    29,    33,
      41,    42,    43,    44,    38,    29,    33,    41,    42,    43,
      44,    38,    29,    38,    41,    42,    43,    44,     4,     5,
       6,     7,     8,     9,    10,     4,     5,     6,     7,     8,
       9,    10,    38,    38,    38,    38,    38,    29,    39,    29,
      29,    29,    38,    38,    38,    38,     4,    33,    39,   125,
      20,    38,    38,    38,    33,    41,    42,    43,    44,    38,
      38,    38,    41,    42,    43,    44,     1,    38,     3,    38,
      38,    38,    38,    38,    38,    35,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,   198,    -1,
      -1,    36,    37,   198,    11,    12,    13,   198,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    -1,    36,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      -1,    36,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    -1,    36,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      -1,    36,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    -1,    36,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      -1,    36,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    -1,    36,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      -1,    36,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    -1,    36,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      -1,    36,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    -1,    36,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      -1,    36,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    35,    -1,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      35,    -1,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    35,    -1,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      -1,    36,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    -1,    36,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      -1,    36,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    35,    -1,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      35,    -1,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    35,    -1,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    -1,    36,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    -1,    36,    37,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,     1,    30,     3,    32,
      -1,    -1,    -1,    36,    37,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,     1,    30,     3,    32,    -1,    -1,
      -1,    -1,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    32,    -1,    -1,    -1,    -1,    37,    11,    12,
      13,    14,    15,    16,    -1,    -1,    -1,    11,    12,    13,
      -1,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    32,
      24,    25,    26,    -1,    37,    -1,    30,    -1,    32,    11,
      12,    13,    -1,    37,    -1,    -1,    -1,    -1,    11,    12,
      13,    -1,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      32,    24,    25,    26,    -1,    37,    -1,    30,    -1,    32,
      11,    12,    13,    -1,    37,    -1,    -1,    -1,    -1,    11,
      12,    13,    -1,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    32,    24,    25,    26,    -1,    37,    -1,    30,    -1,
      32,    11,    12,    13,    -1,    37,    -1,    -1,    -1,    -1,
      11,    12,    13,    -1,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    32,    24,    25,    26,    -1,    37,    -1,    30,
      -1,    32,    11,    12,    13,    -1,    37,    -1,    -1,    -1,
      -1,    11,    12,    13,    -1,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    32,    24,    25,    26,    -1,    37,    -1,
      30,    -1,    32,    11,    12,    13,    -1,    37,    -1,    -1,
      -1,    -1,    11,    12,    13,    -1,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    32,    24,    25,    26,    -1,    37,
      -1,    30,    -1,    32,    11,    12,    13,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    32,    -1,    -1,    -1,    -1,
      37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    47,    48,    49,    50,    51,    11,     0,
      49,    37,    39,    52,     3,    53,    54,    55,    11,    38,
      40,    35,    54,    56,    57,    36,     3,    11,    12,    13,
      17,    18,    21,    22,    23,    24,    25,    26,    27,    28,
      30,    32,    37,    50,    58,    59,    60,    64,    65,    66,
      67,    68,    69,    70,    73,    74,    76,    11,    37,    11,
      68,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    68,    68,    39,    39,    39,    39,     4,     5,     6,
       7,     8,     9,    10,    33,    41,    42,    43,    44,    75,
      77,    78,    61,    62,    63,    76,    39,    68,    14,    15,
      16,    68,    79,    68,    79,    11,    11,    12,    13,    24,
      25,    26,    71,    72,    71,    71,    68,    11,    11,    38,
      68,    68,    79,    68,    38,    40,    38,    38,    38,    38,
      38,    38,    37,    37,    37,    29,    29,    29,    39,    29,
      38,    62,    35,    58,    71,    71,    71,    71,    71,    71,
      68,    11,    57,    19,    29,    29,    29,    38,    38,    38,
      39,    38,    36,    58,    71,    71,    71,    68,    35,    58,
      19,    38,    38,    38,    38,    57,    35,    35,    58,    36,
      57,    57,    36,    36,     1,    11,    12,    13,    24,    25,
      26,    30,    32,    37,    69,    70,    73,    74,    76,    39,
      11,    12,    13,    37,    14,    15,    16,     1,     3,    17,
      18,    27,    28,    50,    59,    60,    64,    65,    66,    67,
      68,    11,    12,    13,    24,    25,    26,    72,    37,    37,
      37,    37,    68,    68,    75,    77,    78,    68,    11,    68,
      37,    37,    37,    39,    39,    39,    39,    37,    37,    37,
      71,    71,    71,    11,    38,    68,    68,    79,    68,    38,
      39,    39,    68,    68,    11,    71,    71,    71,    29,    29,
      29,    38,    38,    39,    29,    29,    29,    29,    71,    71,
      71,    35,    58,    68,    11,    71,    71,    71,    38,    38,
      38,    57,    19,    39,    38,    38,    38,    38,    36,    58,
      68,    35,    58,    19,    38,    57,    35,    35,    58,    36,
      57,    57,    36,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    52,
      51,    53,    54,    54,    54,    55,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      60,    61,    62,    62,    62,    63,    64,    65,    65,    65,
      65,    66,    66,    67,    67,    67,    67,    68,    68,    68,
      68,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      72,    72,    72,    72,    72,    72,    73,    74,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    76,    77,
      78,    78,    78,    78,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     1,     0,
       9,     1,     3,     1,     0,     2,     1,     2,     0,     1,
       2,     1,     1,     2,     2,     2,     3,     1,    11,     9,
       4,     1,     3,     1,     0,     1,     4,     4,     4,     4,
       4,     7,     9,     5,     7,     7,    11,     2,     1,     1,
       1,     1,     1,     3,     3,     6,     6,     4,     6,     1,
       1,     1,     1,     6,     6,     6,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 298 "skylang.y"
                        {
		//printf("\nESCOPO ATUAL: %s\n",escopoAtual);
		if(passagem == 1){
			(yyval.tree) = add_tree_node("programa");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			tree = (yyval.tree);
		}
	}
#line 2289 "skylang.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 309 "skylang.y"
                                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2301 "skylang.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 316 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2312 "skylang.tab.c"
    break;

  case 5: /* declaration: variable_declaration  */
#line 325 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2323 "skylang.tab.c"
    break;

  case 6: /* declaration: func_declaration  */
#line 331 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2334 "skylang.tab.c"
    break;

  case 7: /* variable_declaration: TYPE ID SEMICOLON  */
#line 340 "skylang.y"
                          { 
						if(passagem == 1){
							
							existe_simbolo = searchSymbol((yyvsp[-1].str));
							if(existe_simbolo == 1){
								escopo_correto = searchScope((yyvsp[-1].str),escopoAtual);
								if(escopo_correto == 1){
									flag_redeclaracao_variavel =1;
									//printf("\n--> ERRO SEMANTICO: redeclaracao da VARIAVEL -> %s <- na linha %d",$2,num_linha_1-1);
									snprintf(erro_atual,1100,"--> ERRO SEMANTICO: redeclaracao da VARIAVEL -> %s <- na linha %d",(yyvsp[-1].str),num_linha_1-1);
									adiciona_linha_erro(erros_semanticos,strdup(erro_atual));
								}
							}
 							insert_symbol(symbol_ID, (yyvsp[-1].str),"VARIAVEL",(yyvsp[-2].str), escopoAtual,registrador_atual,conta_parametros);
							registrador_atual = registrador_atual +1;
							symbol_ID = symbol_ID +1;
							//printf("\nAQUI %s\n",$2);
							(yyval.tree) = add_tree_node("variable_declaration");
				
						}

	}
#line 2361 "skylang.tab.c"
    break;

  case 8: /* variable_declaration: error  */
#line 362 "skylang.y"
               {
		if(passagem == 1){
			//erro_count = erro_count +1;
			(yyval.tree) = add_tree_node("Erro Sintatico");
			yyerror(yymsg);
		}
	}
#line 2373 "skylang.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 373 "skylang.y"
                               {escopoAtual = (yyvsp[-1].str);
							if(passagem == 1){
								existe_simbolo = searchSymbol((yyvsp[-1].str));
								if(existe_simbolo == 1){
									snprintf(erro_atual,1100,"--> ERRO SEMANTICO: redeclaracao da FUNCAO -> %s <- na linha %d",(yyvsp[-1].str),num_linha_1);
									adiciona_linha_erro(erros_semanticos,strdup(erro_atual));
									flag_redeclaracao_funcao = 1;
								}
								snprintf(char_reg,999,"%s:",(yyvsp[-1].str));
								adiciona_linha_tac(tac_completo,strdup(char_reg));
								tipo_funcao_atual = (yyvsp[-2].str);
								
							}
							}
#line 2392 "skylang.tab.c"
    break;

  case 10: /* func_declaration: TYPE ID PARENTESES_INI $@1 params PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 386 "skylang.y"
                                                                                                                { 
																					if(passagem == 1){
											
																						insert_symbol(symbol_ID, (yyvsp[-7].str),"FUNCAO",(yyvsp[-8].str),escopoAtual,-1,conta_parametros);
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
																					
																						conta_parametros = 0;
																	
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
#line 2430 "skylang.tab.c"
    break;

  case 11: /* params: params_list  */
#line 422 "skylang.y"
                    { 
				if(passagem == 1){
					(yyval.tree) = add_tree_node("params");
		 			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
				}
	}
#line 2441 "skylang.tab.c"
    break;

  case 12: /* params_list: param COLON params_list  */
#line 430 "skylang.y"
                                {
							if(passagem == 1){ 
								(yyval.tree) = add_tree_node("params_list");
		 						(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
							  	(yyval.tree) -> leaf2 = (yyvsp[0].tree);
							}
	}
#line 2453 "skylang.tab.c"
    break;

  case 13: /* params_list: param  */
#line 437 "skylang.y"
               { 
			if(passagem == 1){
				(yyval.tree) = add_tree_node("params_list");
		 	 	(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			}
	}
#line 2464 "skylang.tab.c"
    break;

  case 14: /* params_list: %empty  */
#line 443 "skylang.y"
         { 
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	}
#line 2474 "skylang.tab.c"
    break;

  case 15: /* param: TYPE ID  */
#line 457 "skylang.y"
                { 
				if(passagem == 1){
				
					insert_symbol(symbol_ID, (yyvsp[0].str),"PARAMETRO_FUNCAO",(yyvsp[-1].str),escopoAtual,-1,conta_parametros);
					//registrador_atual = registrador_atual +1;
		    		symbol_ID = symbol_ID +1;
			 		(yyval.tree) = add_tree_node("param");
					conta_parametros = conta_parametros + 1;
				}
	}
#line 2489 "skylang.tab.c"
    break;

  case 16: /* codeBlock: statement_list  */
#line 469 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CodeBlock");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2500 "skylang.tab.c"
    break;

  case 17: /* statement_list: statement_list statement  */
#line 485 "skylang.y"
                                 {
			(yyval.tree) = add_tree_node("Statement_list");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
#line 2510 "skylang.tab.c"
    break;

  case 18: /* statement_list: %empty  */
#line 490 "skylang.y"
          {	
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Statement_list VAZIO");
		}
		 
	}
#line 2521 "skylang.tab.c"
    break;

  case 19: /* statement: variable_declaration  */
#line 500 "skylang.y"
                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2532 "skylang.tab.c"
    break;

  case 20: /* statement: exp SEMICOLON  */
#line 507 "skylang.y"
                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
		}
	 }
#line 2544 "skylang.tab.c"
    break;

  case 21: /* statement: ifStatement  */
#line 514 "skylang.y"
                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2555 "skylang.tab.c"
    break;

  case 22: /* statement: forAllStatement  */
#line 520 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2566 "skylang.tab.c"
    break;

  case 23: /* statement: outPutStatement SEMICOLON  */
#line 526 "skylang.y"
                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> linha_tac = (yyvsp[-1].tree) -> linha_tac;
		}
	 }
#line 2578 "skylang.tab.c"
    break;

  case 24: /* statement: inputStatement SEMICOLON  */
#line 533 "skylang.y"
                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2589 "skylang.tab.c"
    break;

  case 25: /* statement: callFuncStatement SEMICOLON  */
#line 539 "skylang.y"
                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2600 "skylang.tab.c"
    break;

  case 26: /* statement: RETURN exp SEMICOLON  */
#line 546 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("RETURN");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
			(yyval.tree) -> flag_print = 1;
			if((yyval.tree) -> type != translate_type(tipo_funcao_atual)){
				snprintf(erro_atual,1100,"--> ERRO SEMANTICO: Tipo do retorno da funcao -> %s <- incorreto na linha %d",escopoAtual,num_linha_1-1);
				adiciona_linha_erro(erros_semanticos,strdup(erro_atual));
			}
		}
	 }
#line 2617 "skylang.tab.c"
    break;

  case 27: /* statement: forStatement  */
#line 559 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forStatement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2628 "skylang.tab.c"
    break;

  case 28: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 569 "skylang.y"
                                                                                                              {
			if(passagem == 1){
				(yyval.tree) = add_tree_node("ForStatement");
				(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
				(yyval.tree) -> leaf2 = (yyvsp[-6].tree);
				(yyval.tree) -> leaf3 = (yyvsp[-4].tree);
				(yyval.tree) -> leaf4 = (yyvsp[-1].tree);
				(yyval.tree) -> flag_print = 1;
			}
	}
#line 2643 "skylang.tab.c"
    break;

  case 29: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM statement  */
#line 579 "skylang.y"
                                                                             {
			if(passagem == 1){
				(yyval.tree) = add_tree_node("ForStatement");
				(yyval.tree) -> leaf1 = (yyvsp[-6].tree);
				(yyval.tree) -> leaf2 = (yyvsp[-4].tree);
				(yyval.tree) -> leaf3 = (yyvsp[-2].tree);
				(yyval.tree) -> leaf4 = (yyvsp[0].tree);
				(yyval.tree) -> flag_print = 1;
			}
	}
#line 2658 "skylang.tab.c"
    break;

  case 30: /* callFuncStatement: ID PARENTESES_INI call_params PARENTESES_FIM  */
#line 594 "skylang.y"
                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallFunStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
			if (check_num_params((yyvsp[-3].str),(yyvsp[-3].str))!= conta_parametros_2){
				snprintf(erro_atual,1100,"--> ERRO SEMANTICO: Numero de argumentos incorretos para a chamada de funcao na linha %d, coluna %d",num_linha_1,posicao_linha_1);
				adiciona_linha_erro(erros_semanticos,strdup(erro_atual));
			}
			conta_parametros_2 = 0;
		}

		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[-3].str));
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Funcao nao declarada\n", num_linha,posicao_linha);
			}
		}

	}
#line 2683 "skylang.tab.c"
    break;

  case 31: /* call_params: call_params_list  */
#line 618 "skylang.y"
                        {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallParams");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2694 "skylang.tab.c"
    break;

  case 32: /* call_params_list: call_param COLON call_params_list  */
#line 626 "skylang.y"
                                          {
		if(passagem == 1){ 
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2706 "skylang.tab.c"
    break;

  case 33: /* call_params_list: call_param  */
#line 633 "skylang.y"
                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}

	}
#line 2718 "skylang.tab.c"
    break;

  case 34: /* call_params_list: %empty  */
#line 640 "skylang.y"
         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	 }
#line 2728 "skylang.tab.c"
    break;

  case 35: /* call_param: terminal  */
#line 647 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_param terminal");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			conta_parametros_2 = conta_parametros_2 + 1;
		}

		if(passagem == 2){

			/*if(searchFunctionVariable($1->value,char*symbol_scope)==0){
				printf("\n ERRO SEMANTICO: Argumento do tipo errado");
			}*/
		}
	}
#line 2747 "skylang.tab.c"
    break;

  case 36: /* inputStatement: READ PARENTESES_INI ID PARENTESES_FIM  */
#line 665 "skylang.y"
                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("read Statement");	 
			(yyval.tree) -> flag_print = 1;
			//$$ -> leaf1 = $3;
			(yyval.tree) -> flag_print = 1;
		}
	}
#line 2760 "skylang.tab.c"
    break;

  case 37: /* outPutStatement: WRITE PARENTESES_INI CONST PARENTESES_FIM  */
#line 677 "skylang.y"
                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("write");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2773 "skylang.tab.c"
    break;

  case 38: /* outPutStatement: WRITE PARENTESES_INI exp PARENTESES_FIM  */
#line 687 "skylang.y"
                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("write");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			snprintf(codigo_tac,1100,"print %s", (yyvsp[-1].tree) -> value_tac);
			(yyval.tree) -> linha_tac = strdup(codigo_tac);
			adiciona_linha_tac(tac_completo,(yyval.tree) -> linha_tac);
		}
	 }
#line 2788 "skylang.tab.c"
    break;

  case 39: /* outPutStatement: WRITELN PARENTESES_INI CONST PARENTESES_FIM  */
#line 697 "skylang.y"
                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("writeln");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2800 "skylang.tab.c"
    break;

  case 40: /* outPutStatement: WRITELN PARENTESES_INI exp PARENTESES_FIM  */
#line 705 "skylang.y"
                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("writeln");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			snprintf(codigo_tac,1100,"println %s", (yyvsp[-1].tree) -> value_tac);
			(yyval.tree) -> linha_tac = strdup(codigo_tac);
			adiciona_linha_tac(tac_completo,(yyval.tree) -> linha_tac);
		}
	 }
#line 2815 "skylang.tab.c"
    break;

  case 41: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM statement  */
#line 719 "skylang.y"
                                                                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forAllStatement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> flag_print = 1;
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
#line 2847 "skylang.tab.c"
    break;

  case 42: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 747 "skylang.y"
                                                                                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forAllStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
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
#line 2879 "skylang.tab.c"
    break;

  case 43: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement  */
#line 778 "skylang.y"
                                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
			(yyval.tree) -> flag_print = 1;
			//////////////////////////////// substituir linha tac da exp ////////////////////////////////////
			snprintf(codigo_tac,1100,"%s\nbrz saida_if_%d, %s",(yyvsp[-2].tree) -> linha_tac,contador_if,(yyvsp[-2].tree) -> result);
			if (strdup(codigo_tac)!= NULL)
				if ((yyvsp[-2].tree)->linha_tac!= NULL)
					substitui_linha_tac((yyvsp[-2].tree) -> linha_tac,strdup(codigo_tac));
			//////////////////////////////// substituir linha tac do statement ////////////////////////////////////
			snprintf(codigo_tac,1100,"%s\nsaida_if_%d:",(yyvsp[0].tree)->linha_tac,contador_if);
			//printf("\nAQUI : %s",strdup(codigo_tac));
			if (strdup(codigo_tac)!= NULL)
				if ((yyvsp[0].tree)->linha_tac!= NULL)
					substitui_linha_tac((yyvsp[0].tree) -> linha_tac,strdup(codigo_tac));
			contador_if = contador_if + 1;
		}
	 }
#line 2904 "skylang.tab.c"
    break;

  case 44: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement ELSE statement  */
#line 798 "skylang.y"
                                                                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2918 "skylang.tab.c"
    break;

  case 45: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 808 "skylang.y"
                                                                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2931 "skylang.tab.c"
    break;

  case 46: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM ELSE CHAVES_INI statement_list CHAVES_FIM  */
#line 816 "skylang.y"
                                                                                                                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-5].tree);
			(yyval.tree) -> leaf3 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2945 "skylang.tab.c"
    break;

  case 47: /* exp: NEGATION exp  */
#line 830 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Not");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2958 "skylang.tab.c"
    break;

  case 48: /* exp: setExp  */
#line 839 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	 }
#line 2970 "skylang.tab.c"
    break;

  case 49: /* exp: aritExp  */
#line 846 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> result;
			//$$ -> conversao = $1 -> conversao;
		}
	 }
#line 2984 "skylang.tab.c"
    break;

  case 50: /* exp: relExp  */
#line 855 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> result;
			(yyval.tree) -> linha_tac = (yyvsp[0].tree) -> linha_tac;
			(yyval.tree) -> result = (yyvsp[0].tree) -> result;
		}
	 }
#line 2999 "skylang.tab.c"
    break;

  case 51: /* exp: terminal  */
#line 865 "skylang.y"
                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> value_tac;
		}
	 }
#line 3012 "skylang.tab.c"
    break;

  case 52: /* exp: assignmentExp  */
#line 874 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			//$$ -> conversao = $1 -> conversao;
		}
	}
#line 3025 "skylang.tab.c"
    break;

  case 53: /* assignmentExp: terminal ASSIGN exp  */
#line 885 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("assigmentExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			if (check_set_type((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type)==0){
				(yyval.tree) -> type = (yyvsp[-2].tree) -> type;
				(yyval.tree) -> conversao = check_conversao((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type);
				//printf("\n CONVERSAO: %d",$$ -> conversao);
			}
			snprintf(codigo_tac,1100,"mov %s, %s", (yyvsp[-2].tree)->value_tac,(yyvsp[0].tree)->value_tac);
			(yyval.tree) -> linha_tac = strdup(codigo_tac);
			adiciona_linha_tac(tac_completo,(yyval.tree)->linha_tac);
		}
	}
#line 3046 "skylang.tab.c"
    break;

  case 54: /* assignmentExp: terminal ASSIGN CONST  */
#line 901 "skylang.y"
                               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("assigmentExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			if ((yyvsp[-2].tree)->type != 3){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: ID com tipo incompativel com constante EMPTY\n", num_linha_1,posicao_linha_1);
				snprintf(erro_atual,1100,"ERRO SEMANTICO LINHA %d, COLUNA %d: ID com tipo incompativel com constante EMPTY\n", num_linha_1,posicao_linha_1);
				adiciona_linha_erro(erros_semanticos,strdup(erro_atual));
			}
		}
	}
#line 3064 "skylang.tab.c"
    break;

  case 55: /* setExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 917 "skylang.y"
                                                                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	}
#line 3077 "skylang.tab.c"
    break;

  case 56: /* setExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 925 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print =1;
		}
	}
#line 3090 "skylang.tab.c"
    break;

  case 57: /* setExp: IS_SET PARENTESES_INI ID PARENTESES_FIM  */
#line 934 "skylang.y"
                                                 {
		(yyval.tree) = add_tree_node("IS_SET");
		(yyval.tree) -> flag_print =1;
	}
#line 3099 "skylang.tab.c"
    break;

  case 58: /* setExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 939 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print =1;
		}
	}
#line 3112 "skylang.tab.c"
    break;

  case 59: /* terms_set: aritSetExp  */
#line 950 "skylang.y"
                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terms_set");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 3123 "skylang.tab.c"
    break;

  case 60: /* aritSetExp: ID  */
#line 959 "skylang.y"
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
#line 3146 "skylang.tab.c"
    break;

  case 61: /* aritSetExp: FLOAT  */
#line 977 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal FLOAT");
		}
		 
	 }
#line 3157 "skylang.tab.c"
    break;

  case 62: /* aritSetExp: INTEGER  */
#line 983 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal INTEGER");
		}
		 
	 }
#line 3168 "skylang.tab.c"
    break;

  case 63: /* aritSetExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 989 "skylang.y"
                                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 3180 "skylang.tab.c"
    break;

  case 64: /* aritSetExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 997 "skylang.y"
                                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 3192 "skylang.tab.c"
    break;

  case 65: /* aritSetExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 1005 "skylang.y"
                                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 3204 "skylang.tab.c"
    break;

  case 66: /* aritExp: terminal OP exp  */
#line 1027 "skylang.y"
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
#line 3230 "skylang.tab.c"
    break;

  case 67: /* relExp: terminal rel exp  */
#line 1050 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("relExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			check_set_type((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type);
			if(strcmp((yyvsp[-1].tree)->value_tac, "==")==0){
				
				snprintf(codigo_tac,1100,"seq $%d, %s, %s",registrador_atual, (yyvsp[-2].tree)->value_tac,(yyvsp[0].tree)->value_tac);
				snprintf(char_reg,999,"$%d",registrador_atual);
				(yyval.tree) -> result = strdup(char_reg);
				registrador_atual ++;
				(yyval.tree) -> linha_tac = strdup(codigo_tac);
				adiciona_linha_tac(tac_completo,(yyval.tree) -> linha_tac);
			}
			if(strcmp((yyvsp[-1].tree)->value_tac, "<=")==0){
				
				snprintf(codigo_tac,1100,"sleq $%d, %s, %s",registrador_atual, (yyvsp[-2].tree)->value_tac,(yyvsp[0].tree)->value_tac);
				snprintf(char_reg,999,"$%d",registrador_atual);
				(yyval.tree) -> result = strdup(char_reg);
				registrador_atual ++;
				(yyval.tree) -> linha_tac = strdup(codigo_tac);
				adiciona_linha_tac(tac_completo,(yyval.tree) -> linha_tac);
			}
			if(strcmp((yyvsp[-1].tree)->value_tac, "<")==0){
				
				snprintf(codigo_tac,1100,"slt $%d, %s, %s",registrador_atual, (yyvsp[-2].tree)->value_tac,(yyvsp[0].tree)->value_tac);
				snprintf(char_reg,999,"$%d",registrador_atual);
				(yyval.tree) -> result = strdup(char_reg);
				registrador_atual ++;
				(yyval.tree) -> linha_tac = strdup(codigo_tac);
				adiciona_linha_tac(tac_completo,(yyval.tree) -> linha_tac);
			}
		}
	 }
#line 3271 "skylang.tab.c"
    break;

  case 68: /* rel: CGE  */
#line 1089 "skylang.y"
            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   >=");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = ">=";
			(yyval.tree) -> value = ">=";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3285 "skylang.tab.c"
    break;

  case 69: /* rel: CGT  */
#line 1098 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   >");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = ">";
			(yyval.tree) -> value = ">";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3299 "skylang.tab.c"
    break;

  case 70: /* rel: CNE  */
#line 1107 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   !=");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = "!=";
			(yyval.tree) -> value = "!=";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3313 "skylang.tab.c"
    break;

  case 71: /* rel: CLT  */
#line 1116 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   <");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = "<";
			(yyval.tree) -> value = "<";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3327 "skylang.tab.c"
    break;

  case 72: /* rel: AND  */
#line 1125 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   &&");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = "&&";
			(yyval.tree) -> value = "&&";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3341 "skylang.tab.c"
    break;

  case 73: /* rel: CLE  */
#line 1134 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   <=");
			(yyval.tree) -> value_tac = "<=";
			(yyval.tree) -> value = "<=";
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3354 "skylang.tab.c"
    break;

  case 74: /* rel: CEQ  */
#line 1142 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("  ==");
			(yyval.tree) -> value_tac = "==";
			(yyval.tree) -> value = "==";
			(yyval.tree) -> flag_print = 1;
		}
	}
#line 3367 "skylang.tab.c"
    break;

  case 75: /* terminal: ID  */
#line 1164 "skylang.y"
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
#line 3396 "skylang.tab.c"
    break;

  case 76: /* terminal: FLOAT  */
#line 1188 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal CONST");
			(yyval.tree) -> type = 2;
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
		 
	 }
#line 3411 "skylang.tab.c"
    break;

  case 77: /* terminal: INTEGER  */
#line 1198 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal CONST");
			(yyval.tree) -> type = 1;
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
		 
	 }
#line 3426 "skylang.tab.c"
    break;

  case 78: /* terminal: PARENTESES_INI exp PARENTESES_FIM  */
#line 1209 "skylang.y"
                                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal EXP");
			(yyval.tree)->leaf1 =(yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[-1].tree) -> value_tac;
		}
	}
#line 3439 "skylang.tab.c"
    break;

  case 79: /* ASSIGN: EQUALS  */
#line 1222 "skylang.y"
       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" =");
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3450 "skylang.tab.c"
    break;

  case 80: /* OP: MULT  */
#line 1232 "skylang.y"
             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" *");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "mul";
		}
	 }
#line 3462 "skylang.tab.c"
    break;

  case 81: /* OP: PLUS  */
#line 1239 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" +");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "add";
		}
	 }
#line 3474 "skylang.tab.c"
    break;

  case 82: /* OP: MINUS  */
#line 1246 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" -");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "sub";
		}
	 }
#line 3486 "skylang.tab.c"
    break;

  case 83: /* OP: DIV  */
#line 1253 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" /");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "div";
		}
	 }
#line 3498 "skylang.tab.c"
    break;

  case 84: /* CONST: EMPTY  */
#line 1264 "skylang.y"
     {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("EMPTY");
			(yyval.tree) -> type = 3;
			(yyval.tree) -> value = (yyvsp[0].str);
		}
}
#line 3510 "skylang.tab.c"
    break;

  case 85: /* CONST: CHAR  */
#line 1272 "skylang.y"
     {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("CHAR");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print=1;
		}
}
#line 3523 "skylang.tab.c"
    break;

  case 86: /* CONST: STRING  */
#line 1281 "skylang.y"
       {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("STRING");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print=1;
		}
}
#line 3536 "skylang.tab.c"
    break;


#line 3540 "skylang.tab.c"

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

#line 1292 "skylang.y"


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
	printf("\n====================================== PRIMEIRA PASSAGEM (TS, ARVORE ANOTADA) ======================================\n\n");
    yyparse();
    //yylex();
	fclose(yyin);
	printf("\n");
	printf("\n------------------------------------> ARVORE SINTATICA ABSTRATA ANOTADA: <------------------------------------\n");
	print_tree(0,tree);
	printf("\n\n-----------------------------------------------> TABELA DE SIMBOLOS <----------------------------------------------\n");
	printTS();
	printf("\n");
	passagem=2;
	yyin=fopen(fname,"r+");
	printf("\n================================= SEGUNDA PASSAGEM (TRATAMENTO DE ERROS) =================================\n\n");
	yyparse();
	fclose(yyin);
	if(existe_main!=1){
		printf("\n--> ERRO: O codigo nao possui uma funcao main()\n");
	}
	printa_erros(erros_semanticos,elt_erros);
	printf("\n=========================== TAC (um arquivo skylang.tac também foi gerado no diretorio atual)===========================\n\n");
	printf(".table\n.code\n");
	//print_tac_tree(tree);
	printa_linha_tac(tac_completo,elt_1);
	cria_arquivo_tac(tac_completo,elt_1);
    yylex_destroy();
	free_tree(tree);
	//free_TS(hashed_symbol_table);
    return 0;
}
