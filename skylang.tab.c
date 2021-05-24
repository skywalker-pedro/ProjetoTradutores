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
char * func_call_atual;
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

//Check if parameters in function call are correct
int searchFunctionVariable_2(char*symbol,char*symbol_scope,int posicao,char*escopo_atual){
	Hash_table* aux = hashed_symbol_table;
	int retorno = 0;
	int i=0;
	char * tipo_variavel;
	tipo_variavel = searchVarType(symbol,escopoAtual);
	//printf("\nTIPO DA VAR: %s", tipo_variavel);
    while(aux!=NULL){
		//strcmp retorna 0 caso as strings sejam iguais
        if (strcmp(aux->type,"PARAMETRO_FUNCAO")==0){
			//printf("\nAQUIII PARAM FUNC: %s", aux->type);
			if (strcmp(aux-> escopo,symbol_scope)==0){
				//printf("\nESCOPO: %s e %s", aux->escopo,symbol_scope);
				//printf("\nposicao vs i: %d e %d", posicao,i);
				if(posicao == i){
					if(strcmp(tipo_variavel,aux->varType)==0)
						retorno = 1;
				}
				i++;
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


#line 372 "skylang.tab.c"

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
  YYSYMBOL_61_2 = 61,                      /* $@2  */
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
#define YYLAST   2445

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  321

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
       0,   331,   331,   342,   349,   358,   364,   373,   395,   406,
     406,   455,   463,   470,   476,   490,   502,   518,   523,   533,
     540,   547,   553,   559,   566,   572,   579,   592,   602,   612,
     627,   627,   651,   659,   666,   673,   680,   696,   717,   727,
     737,   745,   759,   787,   818,   838,   848,   856,   870,   879,
     886,   895,   905,   914,   925,   956,   972,   980,   989,   994,
    1005,  1014,  1032,  1038,  1044,  1052,  1060,  1082,  1119,  1186,
    1195,  1204,  1213,  1222,  1231,  1239,  1261,  1285,  1295,  1306,
    1319,  1329,  1336,  1343,  1350,  1361,  1369,  1378
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
  "statement", "forStatement", "callFuncStatement", "$@2", "call_params",
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

#define YYPACT_NINF (-107)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-88)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      56,    15,    -9,     3,    77,    81,    88,    94,    53,  -107,
     102,     4,   106,     5,    -5,   -28,   -27,    82,    83,   -15,
       5,  1179,    -7,    -1,  1207,   112,    29,   338,   345,   352,
    2222,     7,     8,    21,    26,    27,    31,    64,    74,    79,
      80,  2222,  2244,  1235,  1263,  1291,    54,    87,    91,  1319,
    1347,   101,   109,   110,   111,   113,   430,   119,   114,   437,
     120,  2244,   386,   386,    10,    41,    41,    41,  2222,   135,
     151,   124,   128,  1375,  1403,  1431,  1459,  2253,  2275,  2284,
    2306,  2315,  2337,  2346,  2186,  2368,  2377,  2399,  2408,  2222,
    2213,  2222,    38,  1487,   132,   134,   138,   139,   142,   143,
     145,   146,   149,   159,   160,   161,   155,   157,   162,   167,
     168,   172,   190,   187,   194,   189,   478,   195,   196,   197,
     198,   200,   204,    89,    93,  1515,   213,   219,   220,   221,
     222,    41,    41,    41,    61,    61,    61,  2222,   217,   223,
     225,    38,  1179,   591,   214,   236,   237,   231,   235,   242,
     245,   243,   249,  1543,  2131,    61,    61,    61,   250,   252,
     255,  2244,  1571,   619,  1599,   257,   259,   260,   264,  1179,
    1627,   239,   281,   287,   288,  1655,  1683,  1179,  1179,  1711,
    1739,  1767,  1795,  1823,  1851,  1879,   485,   492,   499,   284,
     285,   286,   289,  2244,  2244,   296,   297,   298,   325,   540,
    1907,   326,   327,   328,  2244,   329,   330,   331,    97,   103,
     104,  2244,   647,   316,  2222,   335,   336,   337,   675,   703,
     344,   351,   364,   731,   759,   365,   367,   371,   375,   339,
     377,   378,   379,    41,    41,    41,   356,   381,   382,  2244,
     386,  2244,   383,   384,   385,   390,  2244,  2222,   414,   787,
     815,   843,   871,    41,    41,    41,   401,   402,   403,   395,
     547,   413,   415,   416,   420,   424,   107,   899,   927,   426,
     436,   423,   448,   481,   483,    61,    61,    61,   427,  1935,
    2222,   502,    61,    61,    61,   476,   477,   486,  1179,   955,
     500,   493,   520,   521,   522,   523,   524,   525,  1963,  2159,
    2244,  1991,   526,   527,   528,   983,  1011,   529,  1179,  1039,
     503,  2019,  2047,  1179,  1179,  1067,  1095,  2075,  2103,  1123,
    1151
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
       0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,  -107,   229,     0,  -107,  -107,  -107,   496,  -107,
    -107,   -59,  -106,   -79,   -55,  -107,  -107,   428,  -107,   -54,
     -11,    13,    14,   -29,   -33,   -25,   173,   184,    37,    92,
     369,   -37,   372,   373,   -49
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    43,     7,    13,    15,    16,    17,
      23,    24,    44,    45,    46,    58,   121,   122,   123,    47,
      48,    49,    50,    51,    52,    53,   109,   110,    54,    55,
      89,    56,    90,    91,    99
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    60,     8,     9,     6,   199,    18,    -9,    14,   195,
      19,   -11,    71,    72,   101,    -8,    -8,   196,    -8,   143,
      21,   201,   202,   203,   199,   199,   199,   102,   195,   195,
     195,   -12,    94,    98,   100,    25,   196,   196,   196,   113,
      57,   119,    -9,   -14,    61,    62,   219,   204,   164,   208,
     209,   210,   103,   104,   105,   124,   170,     1,    63,     2,
     117,   118,   120,    64,    65,   106,   107,   108,    66,   179,
     220,   221,   226,   227,   228,   211,   -35,    -2,     1,   197,
       2,    -4,    -4,   153,    -4,   229,   230,   231,    -5,    -5,
      11,    -5,    12,    73,    -6,    -6,   225,    -6,   197,   197,
     197,    67,    -3,    -3,   124,    -3,    -7,    -7,   150,    -7,
     176,    68,   -10,   -10,   222,   -10,    69,    70,   181,   182,
     -13,   -15,    20,   -15,   199,   218,    74,   -34,   195,   141,
      75,   -36,   168,   -36,   198,   -76,   196,   -76,   223,   224,
      76,   -78,   -77,   -78,   -77,   -79,   114,   -79,   -53,   -49,
     -50,    92,   -51,   198,   198,   198,   199,   199,   200,    93,
     195,   195,   115,   -48,   237,   238,   116,   199,   196,   196,
     125,   195,   -86,   289,   199,   242,   -87,   -85,   195,   196,
     126,   127,   243,   128,   129,   245,   196,   130,   -61,   -63,
     -62,   263,   131,   306,   132,   309,   134,   -60,   197,   133,
     219,   135,   199,   199,   199,   315,   195,   195,   195,   199,
     261,   262,   264,   195,   196,   196,   196,   269,   270,   136,
     219,   196,   219,   138,   220,   221,   137,   139,   151,   298,
     197,   197,   219,    10,   -68,   -54,   -55,   -67,   140,   111,
     112,   197,   -32,   155,   220,   221,   220,   221,   197,   312,
     225,   290,   -39,   198,   317,   318,   220,   221,   -38,   -41,
     -40,   -37,   -58,   199,   -31,   156,   157,   195,   222,   158,
     225,   307,   225,   159,   177,   196,   197,   197,   197,   218,
     160,   162,   225,   197,   161,   198,   198,   -33,   222,   -59,
     222,   -56,   223,   224,   -57,   172,   198,   173,   174,   218,
     222,   218,   175,   198,   144,   145,   146,   147,   148,   149,
     -64,   218,   223,   224,   223,   224,   -65,   -66,   232,   232,
     232,   233,   234,   235,   223,   224,   236,   244,   165,   166,
     167,   198,   198,   198,   -53,   -49,   -50,   197,   198,   232,
     232,   232,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -51,   -76,   -78,   -77,   259,   -86,   -87,
     -85,   -76,   246,   247,   248,   -30,   253,   -76,   -78,   -76,
     -76,   -76,   -76,   249,   -78,   -77,   -78,   -78,   -78,   -78,
     250,   -77,   198,   -77,   -77,   -77,   -77,   186,   187,   188,
      95,    96,    97,   251,   252,   -61,   256,   257,   258,   -63,
     189,   190,   191,   -62,   254,   255,   192,   -60,   193,   -48,
     260,   265,   266,   194,   267,   271,   272,   273,   274,   268,
     275,   276,   277,   278,    77,    78,    79,    80,    81,    82,
      83,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   285,   286,
     287,   -68,   281,   -54,   -55,   292,   293,   294,   -67,   232,
     232,   232,   -79,    84,   279,   -58,   232,   232,   232,   -52,
     -76,    85,    86,    87,    88,   280,   -76,   282,   -76,   -76,
     -76,   -76,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     283,   -79,   284,   291,   295,   296,    22,   -79,   -76,   -79,
     -79,   -79,   -79,   -76,   297,   -78,   -76,   -76,   -76,   -76,
     -78,   301,   -77,   -78,   -78,   -78,   -78,   -77,   313,   300,
     -77,   -77,   -77,   -77,    77,    78,    79,    80,    81,    82,
      83,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   302,   303,
     304,   -59,   -56,   -57,   -64,   -65,   -66,   311,   239,   152,
       0,   240,   241,    84,     0,     0,     0,     0,   -52,     0,
     -79,    85,    86,    87,    88,   -79,     0,     0,   -79,   -79,
     -79,   -79,   -44,     0,   -44,     0,     0,     0,     0,     0,
       0,     0,   -44,   -44,   -44,     0,     0,     0,   -44,   -44,
     154,     0,   -44,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -46,   -44,   -46,   -44,     0,     0,     0,   -44,   -44,     0,
     -46,   -46,   -46,     0,     0,     0,   -46,   -46,   171,     0,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,    -8,   -46,
      -8,   -46,     0,     0,     0,   -46,   -46,     0,    -8,    -8,
      -8,     0,     0,     0,    -8,    -8,    -8,     0,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,   -19,    -8,   -19,    -8,
       0,     0,     0,    -8,    -8,     0,   -19,   -19,   -19,     0,
       0,     0,   -19,   -19,   -19,     0,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -27,   -19,   -27,   -19,     0,     0,
       0,   -19,   -19,     0,   -27,   -27,   -27,     0,     0,     0,
     -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -22,   -27,   -22,   -27,     0,     0,     0,   -27,
     -27,     0,   -22,   -22,   -22,     0,     0,     0,   -22,   -22,
     -22,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -21,   -22,   -21,   -22,     0,     0,     0,   -22,   -22,     0,
     -21,   -21,   -21,     0,     0,     0,   -21,   -21,   -21,     0,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -25,   -21,
     -25,   -21,     0,     0,     0,   -21,   -21,     0,   -25,   -25,
     -25,     0,     0,     0,   -25,   -25,   -25,     0,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,   -24,   -25,   -24,   -25,
       0,     0,     0,   -25,   -25,     0,   -24,   -24,   -24,     0,
       0,     0,   -24,   -24,   -24,     0,   -24,   -24,   -24,   -24,
     -24,   -24,   -24,   -24,   -23,   -24,   -23,   -24,     0,     0,
       0,   -24,   -24,     0,   -23,   -23,   -23,     0,     0,     0,
     -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -20,   -23,   -20,   -23,     0,     0,     0,   -23,
     -23,     0,   -20,   -20,   -20,     0,     0,     0,   -20,   -20,
     -20,     0,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
      -7,   -20,    -7,   -20,     0,     0,     0,   -20,   -20,     0,
      -7,    -7,    -7,     0,     0,     0,    -7,    -7,    -7,     0,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,   -26,    -7,
     -26,    -7,     0,     0,     0,    -7,    -7,     0,   -26,   -26,
     -26,     0,     0,     0,   -26,   -26,   -26,     0,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   -44,   -26,   -44,   -26,
       0,     0,     0,   -26,   -26,     0,   -44,   -44,   -44,     0,
       0,     0,   -44,   -44,   299,     0,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -46,   -44,   -46,   -44,     0,     0,
       0,   -44,   -44,     0,   -46,   -46,   -46,     0,     0,     0,
     -46,   -46,   310,     0,   -46,   -46,   -46,   -46,   -46,   -46,
     -46,   -46,   -45,   -46,   -45,   -46,     0,     0,     0,   -46,
     -46,     0,   -45,   -45,   -45,     0,     0,     0,   -45,   -45,
     -45,     0,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -42,   -45,   -42,   -45,     0,     0,     0,   -45,   -45,     0,
     -42,   -42,   -42,     0,     0,     0,   -42,   -42,   -42,     0,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -29,   -42,
     -29,   -42,     0,     0,     0,   -42,   -42,     0,   -29,   -29,
     -29,     0,     0,     0,   -29,   -29,   -29,     0,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,   -43,   -29,   -43,   -29,
       0,     0,     0,   -29,   -29,     0,   -43,   -43,   -43,     0,
       0,     0,   -43,   -43,   -43,     0,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -47,   -43,   -47,   -43,     0,     0,
       0,   -43,   -43,     0,   -47,   -47,   -47,     0,     0,     0,
     -47,   -47,   -47,     0,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -28,   -47,   -28,   -47,     0,     0,     0,   -47,
     -47,     0,   -28,   -28,   -28,     0,     0,     0,   -28,   -28,
     -28,     0,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -18,   -28,   -18,   -28,     0,     0,     0,   -28,   -28,     0,
     -18,   -18,   -18,     0,     0,     0,   -18,   -18,     0,     0,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,   -18,   185,   -18,
      26,   -18,     0,     0,     0,   -18,   -18,     0,    27,    28,
      29,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,   -19,    40,   -19,    41,
       0,     0,     0,   -16,    42,     0,   -19,   -19,   -19,     0,
       0,     0,   -19,   -19,     0,     0,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -17,   -19,   -17,   -19,     0,     0,
       0,   -19,   -19,     0,   -17,   -17,   -17,     0,     0,     0,
     -17,   -17,     0,     0,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -27,   -17,   -27,   -17,     0,     0,     0,   -17,
     -17,     0,   -27,   -27,   -27,     0,     0,     0,   -27,   -27,
       0,     0,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -22,   -27,   -22,   -27,     0,     0,     0,   -27,   -27,     0,
     -22,   -22,   -22,     0,     0,     0,   -22,   -22,     0,     0,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -21,   -22,
     -21,   -22,     0,     0,     0,   -22,   -22,     0,   -21,   -21,
     -21,     0,     0,     0,   -21,   -21,     0,     0,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -25,   -21,   -25,   -21,
       0,     0,     0,   -21,   -21,     0,   -25,   -25,   -25,     0,
       0,     0,   -25,   -25,     0,     0,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,   -25,   -24,   -25,   -24,   -25,     0,     0,
       0,   -25,   -25,     0,   -24,   -24,   -24,     0,     0,     0,
     -24,   -24,     0,     0,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,   -24,   -23,   -24,   -23,   -24,     0,     0,     0,   -24,
     -24,     0,   -23,   -23,   -23,     0,     0,     0,   -23,   -23,
       0,     0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,
     -20,   -23,   -20,   -23,     0,     0,     0,   -23,   -23,     0,
     -20,   -20,   -20,     0,     0,     0,   -20,   -20,     0,     0,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -26,   -20,
     -26,   -20,     0,     0,     0,   -20,   -20,     0,   -26,   -26,
     -26,     0,     0,     0,   -26,   -26,     0,     0,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,   212,   -26,   213,   -26,
       0,     0,     0,   -26,   -26,     0,    27,    28,    29,     0,
       0,     0,   214,   215,     0,     0,    32,    33,    34,    35,
      36,    37,   216,   217,   185,    40,    26,    41,     0,     0,
     142,     0,    42,     0,    27,    28,    29,     0,     0,     0,
      30,    31,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,   185,    40,    26,    41,     0,     0,     0,   163,
      42,     0,    27,    28,    29,     0,     0,     0,    30,    31,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
     -45,    40,   -45,    41,     0,     0,   169,     0,    42,     0,
     -45,   -45,   -45,     0,     0,     0,   -45,   -45,     0,     0,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -42,   -45,
     -42,   -45,     0,     0,     0,   -45,   -45,     0,   -42,   -42,
     -42,     0,     0,     0,   -42,   -42,     0,     0,   -42,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   185,   -42,    26,   -42,
       0,     0,     0,   -42,   -42,     0,    27,    28,    29,     0,
       0,     0,    30,    31,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,   185,    40,    26,    41,     0,     0,
     178,     0,    42,     0,    27,    28,    29,     0,     0,     0,
      30,    31,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,   -29,    40,   -29,    41,     0,     0,     0,   180,
      42,     0,   -29,   -29,   -29,     0,     0,     0,   -29,   -29,
       0,     0,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -43,   -29,   -43,   -29,     0,     0,     0,   -29,   -29,     0,
     -43,   -43,   -43,     0,     0,     0,   -43,   -43,     0,     0,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   185,   -43,
      26,   -43,     0,     0,     0,   -43,   -43,     0,    27,    28,
      29,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,   185,    40,    26,    41,
       0,     0,     0,   183,    42,     0,    27,    28,    29,     0,
       0,     0,    30,    31,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,   -47,    40,   -47,    41,     0,     0,
       0,   184,    42,     0,   -47,   -47,   -47,     0,     0,     0,
     -47,   -47,     0,     0,   -47,   -47,   -47,   -47,   -47,   -47,
     -47,   -47,   -28,   -47,   -28,   -47,     0,     0,     0,   -47,
     -47,     0,   -28,   -28,   -28,     0,     0,     0,   -28,   -28,
       0,     0,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
      -8,   -28,    -8,   -28,     0,     0,     0,   -28,   -28,     0,
      -8,    -8,    -8,     0,     0,     0,    -8,    -8,     0,     0,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -7,    -8,
      -7,    -8,     0,     0,     0,    -8,    -8,     0,    -7,    -7,
      -7,     0,     0,     0,    -7,    -7,     0,     0,    -7,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,   212,    -7,   213,    -7,
       0,     0,     0,    -7,    -7,     0,    27,    28,    29,     0,
       0,     0,   214,   215,     0,     0,    32,    33,    34,    35,
      36,    37,   216,   217,   185,    40,    26,    41,     0,     0,
     288,     0,    42,     0,    27,    28,    29,     0,     0,     0,
      30,    31,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,   212,    40,   213,    41,     0,     0,     0,   305,
      42,     0,    27,    28,    29,     0,     0,     0,   214,   215,
       0,     0,    32,    33,    34,    35,    36,    37,   216,   217,
     212,    40,   213,    41,     0,     0,   308,     0,    42,     0,
      27,    28,    29,     0,     0,     0,   214,   215,     0,     0,
      32,    33,    34,    35,    36,    37,   216,   217,   185,    40,
      26,    41,     0,     0,   314,     0,    42,     0,    27,    28,
      29,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,   185,    40,    26,    41,
       0,     0,     0,   316,    42,     0,    27,    28,    29,     0,
       0,     0,    30,    31,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,   185,    40,    26,    41,     0,     0,
       0,   319,    42,     0,    27,    28,    29,     0,     0,     0,
      30,    31,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,   185,    40,    26,    41,     0,     0,     0,   320,
      42,     0,    27,    28,    29,     0,     0,     0,    30,    31,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
     212,    40,   213,    41,     0,     0,     0,     0,    42,     0,
      27,    28,    29,     0,     0,     0,   214,   215,     0,     0,
      32,    33,    34,    35,    36,    37,   216,   217,     0,    40,
       0,    41,     0,     0,     0,     0,    42,   -80,   -80,   -80,
     -80,   -80,   -80,     0,     0,     0,     0,     0,     0,     0,
     -80,   -80,   -80,     0,     0,     0,   -80,     0,   -80,     0,
       0,     0,     0,   -80,    59,    28,    29,   205,   206,   207,
       0,     0,     0,    59,    28,    29,     0,    35,    36,    37,
       0,     0,     0,    40,     0,    41,    35,    36,    37,     0,
      42,     0,    40,     0,    41,   186,   187,   188,     0,    42,
       0,     0,     0,     0,   -74,   -74,   -74,     0,   189,   190,
     191,     0,     0,     0,   192,     0,   193,   -74,   -74,   -74,
       0,   194,     0,   -74,     0,   -74,   -72,   -72,   -72,     0,
     -74,     0,     0,     0,     0,   -71,   -71,   -71,     0,   -72,
     -72,   -72,     0,     0,     0,   -72,     0,   -72,   -71,   -71,
     -71,     0,   -72,     0,   -71,     0,   -71,   -70,   -70,   -70,
       0,   -71,     0,     0,     0,     0,   -73,   -73,   -73,     0,
     -70,   -70,   -70,     0,     0,     0,   -70,     0,   -70,   -73,
     -73,   -73,     0,   -70,     0,   -73,     0,   -73,   -75,   -75,
     -75,     0,   -73,     0,     0,     0,     0,   -69,   -69,   -69,
       0,   -75,   -75,   -75,     0,     0,     0,   -75,     0,   -75,
     -69,   -69,   -69,     0,   -75,     0,   -69,     0,   -69,   -82,
     -82,   -82,     0,   -69,     0,     0,     0,     0,   -83,   -83,
     -83,     0,   -82,   -82,   -82,     0,     0,     0,   -82,     0,
     -82,   -83,   -83,   -83,     0,   -82,     0,   -83,     0,   -83,
     -81,   -81,   -81,     0,   -83,     0,     0,     0,     0,   -84,
     -84,   -84,     0,   -81,   -81,   -81,     0,     0,     0,   -81,
       0,   -81,   -84,   -84,   -84,     0,   -81,     0,   -84,     0,
     -84,     0,     0,     0,     0,   -84
};

static const yytype_int16 yycheck[] =
{
       0,    30,    11,     0,     4,    42,    11,     3,     3,    42,
      38,    38,    41,    42,    63,     0,     1,    42,     3,   125,
      35,    11,    12,    13,    61,    62,    63,    64,    61,    62,
      63,    38,    61,    62,    63,    36,    61,    62,    63,    68,
      11,    90,    38,    38,    37,    37,   125,    37,   154,    11,
      12,    13,    11,    12,    13,    92,   162,     1,    37,     3,
      89,    90,    91,    37,    37,    24,    25,    26,    37,   175,
     125,   125,    11,    12,    13,    37,    38,     0,     1,    42,
       3,     0,     1,   142,     3,    24,    25,    26,     0,     1,
      37,     3,    39,    39,     0,     1,   125,     3,    61,    62,
      63,    37,     0,     1,   141,     3,     0,     1,   137,     3,
     169,    37,     0,     1,   125,     3,    37,    37,   177,   178,
      38,    38,    40,    40,   161,   125,    39,    38,   161,    40,
      39,    38,   161,    40,    42,    38,   161,    40,   125,   125,
      39,    38,    38,    40,    40,    38,    11,    40,    39,    39,
      39,    37,    39,    61,    62,    63,   193,   194,    39,    39,
     193,   194,    11,    39,   193,   194,    38,   204,   193,   194,
      38,   204,    38,   279,   211,   204,    38,    38,   211,   204,
      38,    38,   211,    38,    38,   214,   211,    38,    29,    29,
      29,   240,    37,   299,    37,   301,    29,    29,   161,    37,
     279,    29,   239,   240,   241,   311,   239,   240,   241,   246,
     239,   240,   241,   246,   239,   240,   241,   246,   247,    29,
     299,   246,   301,    29,   279,   279,    39,    38,    11,   288,
     193,   194,   311,     4,    39,    39,    39,    39,    38,    66,
      67,   204,    38,    29,   299,   299,   301,   301,   211,   308,
     279,   280,    39,   161,   313,   314,   311,   311,    39,    39,
      39,    39,    39,   300,    39,    29,    29,   300,   279,    38,
     299,   300,   301,    38,    35,   300,   239,   240,   241,   279,
      38,    38,   311,   246,    39,   193,   194,    38,   299,    39,
     301,    39,   279,   279,    39,    38,   204,    38,    38,   299,
     311,   301,    38,   211,   131,   132,   133,   134,   135,   136,
      29,   311,   299,   299,   301,   301,    29,    29,   134,   135,
     136,    37,    37,    37,   311,   311,    37,    11,   155,   156,
     157,   239,   240,   241,    38,    38,    38,   300,   246,   155,
     156,   157,     4,     5,     6,     7,     8,     9,    10,     4,
       5,     6,     7,     8,     9,    10,     4,     5,     6,     7,
       8,     9,    10,    38,    38,    38,    38,    11,    39,    39,
      39,    33,    37,    37,    37,    37,    37,    39,    33,    41,
      42,    43,    44,    39,    39,    33,    41,    42,    43,    44,
      39,    39,   300,    41,    42,    43,    44,    11,    12,    13,
      14,    15,    16,    39,    39,    38,   233,   234,   235,    38,
      24,    25,    26,    38,    37,    37,    30,    38,    32,    38,
      38,    38,    38,    37,    39,    11,   253,   254,   255,    39,
      29,    29,    29,    38,     4,     5,     6,     7,     8,     9,
      10,     4,     5,     6,     7,     8,     9,    10,   275,   276,
     277,    38,    29,    38,    38,   282,   283,   284,    38,   275,
     276,   277,    38,    33,    38,    38,   282,   283,   284,    39,
      33,    41,    42,    43,    44,    39,    39,    29,    41,    42,
      43,    44,     4,     5,     6,     7,     8,     9,    10,     4,
       5,     6,     7,     8,     9,    10,     4,     5,     6,     7,
       8,     9,    10,     4,     5,     6,     7,     8,     9,    10,
      29,    33,    29,    11,    38,    38,    20,    39,    33,    41,
      42,    43,    44,    38,    38,    33,    41,    42,    43,    44,
      38,    38,    33,    41,    42,    43,    44,    38,    35,    39,
      41,    42,    43,    44,     4,     5,     6,     7,     8,     9,
      10,     4,     5,     6,     7,     8,     9,    10,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,   199,   141,
      -1,   199,   199,    33,    -1,    -1,    -1,    -1,    38,    -1,
      33,    41,    42,    43,    44,    38,    -1,    -1,    41,    42,
      43,    44,     1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
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
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
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
       3,    32,    -1,    -1,    -1,    36,    37,    -1,    11,    12,
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
       1,    30,     3,    32,    -1,    -1,    35,    -1,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,     1,    30,
       3,    32,    -1,    -1,    -1,    36,    37,    -1,    11,    12,
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
      35,    -1,    37,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,     1,    30,     3,    32,    -1,    -1,    -1,    36,
      37,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
       1,    30,     3,    32,    -1,    -1,    35,    -1,    37,    -1,
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
       1,    30,     3,    32,    -1,    -1,    -1,    -1,    37,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    32,    -1,    -1,    -1,    -1,    37,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    32,    -1,
      -1,    -1,    -1,    37,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    11,    12,    13,    -1,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    32,    24,    25,    26,    -1,
      37,    -1,    30,    -1,    32,    11,    12,    13,    -1,    37,
      -1,    -1,    -1,    -1,    11,    12,    13,    -1,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    32,    24,    25,    26,
      -1,    37,    -1,    30,    -1,    32,    11,    12,    13,    -1,
      37,    -1,    -1,    -1,    -1,    11,    12,    13,    -1,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    32,    24,    25,
      26,    -1,    37,    -1,    30,    -1,    32,    11,    12,    13,
      -1,    37,    -1,    -1,    -1,    -1,    11,    12,    13,    -1,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    32,    24,
      25,    26,    -1,    37,    -1,    30,    -1,    32,    11,    12,
      13,    -1,    37,    -1,    -1,    -1,    -1,    11,    12,    13,
      -1,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    32,
      24,    25,    26,    -1,    37,    -1,    30,    -1,    32,    11,
      12,    13,    -1,    37,    -1,    -1,    -1,    -1,    11,    12,
      13,    -1,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      32,    24,    25,    26,    -1,    37,    -1,    30,    -1,    32,
      11,    12,    13,    -1,    37,    -1,    -1,    -1,    -1,    11,
      12,    13,    -1,    24,    25,    26,    -1,    -1,    -1,    30,
      -1,    32,    24,    25,    26,    -1,    37,    -1,    30,    -1,
      32,    -1,    -1,    -1,    -1,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    47,    48,    49,    50,    51,    11,     0,
      49,    37,    39,    52,     3,    53,    54,    55,    11,    38,
      40,    35,    54,    56,    57,    36,     3,    11,    12,    13,
      17,    18,    21,    22,    23,    24,    25,    26,    27,    28,
      30,    32,    37,    50,    58,    59,    60,    65,    66,    67,
      68,    69,    70,    71,    74,    75,    77,    11,    61,    11,
      69,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    69,    69,    39,    39,    39,    39,     4,     5,     6,
       7,     8,     9,    10,    33,    41,    42,    43,    44,    76,
      78,    79,    37,    39,    69,    14,    15,    16,    69,    80,
      69,    80,    77,    11,    12,    13,    24,    25,    26,    72,
      73,    72,    72,    69,    11,    11,    38,    69,    69,    80,
      69,    62,    63,    64,    77,    38,    38,    38,    38,    38,
      38,    37,    37,    37,    29,    29,    29,    39,    29,    38,
      38,    40,    35,    58,    72,    72,    72,    72,    72,    72,
      69,    11,    63,    57,    19,    29,    29,    29,    38,    38,
      38,    39,    38,    36,    58,    72,    72,    72,    69,    35,
      58,    19,    38,    38,    38,    38,    57,    35,    35,    58,
      36,    57,    57,    36,    36,     1,    11,    12,    13,    24,
      25,    26,    30,    32,    37,    70,    71,    74,    75,    77,
      39,    11,    12,    13,    37,    14,    15,    16,    11,    12,
      13,    37,     1,     3,    17,    18,    27,    28,    50,    59,
      60,    65,    66,    67,    68,    69,    11,    12,    13,    24,
      25,    26,    73,    37,    37,    37,    37,    69,    69,    76,
      78,    79,    69,    69,    11,    69,    37,    37,    37,    39,
      39,    39,    39,    37,    37,    37,    72,    72,    72,    11,
      38,    69,    69,    80,    69,    38,    38,    39,    39,    69,
      69,    11,    72,    72,    72,    29,    29,    29,    38,    38,
      39,    29,    29,    29,    29,    72,    72,    72,    35,    58,
      69,    11,    72,    72,    72,    38,    38,    38,    57,    19,
      39,    38,    38,    38,    38,    36,    58,    69,    35,    58,
      19,    38,    57,    35,    35,    58,    36,    57,    57,    36,
      36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    52,
      51,    53,    54,    54,    54,    55,    56,    57,    57,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      61,    60,    62,    63,    63,    63,    64,    65,    66,    66,
      66,    66,    67,    67,    68,    68,    68,    68,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    71,    71,    71,
      72,    73,    73,    73,    73,    73,    73,    74,    75,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    77,
      78,    79,    79,    79,    79,    80,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     1,     0,
       9,     1,     3,     1,     0,     2,     1,     2,     0,     1,
       2,     1,     1,     2,     2,     2,     3,     1,    11,     9,
       0,     5,     1,     3,     1,     0,     1,     4,     4,     4,
       4,     4,     7,     9,     5,     7,     7,    11,     2,     1,
       1,     1,     1,     1,     3,     3,     6,     6,     4,     6,
       1,     1,     1,     1,     6,     6,     6,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1
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
#line 331 "skylang.y"
                        {
		//printf("\nESCOPO ATUAL: %s\n",escopoAtual);
		if(passagem == 1){
			(yyval.tree) = add_tree_node("programa");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			tree = (yyval.tree);
		}
	}
#line 2332 "skylang.tab.c"
    break;

  case 3: /* declarationList: declarationList declaration  */
#line 342 "skylang.y"
                                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2344 "skylang.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 349 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2355 "skylang.tab.c"
    break;

  case 5: /* declaration: variable_declaration  */
#line 358 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2366 "skylang.tab.c"
    break;

  case 6: /* declaration: func_declaration  */
#line 364 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2377 "skylang.tab.c"
    break;

  case 7: /* variable_declaration: TYPE ID SEMICOLON  */
#line 373 "skylang.y"
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
#line 2404 "skylang.tab.c"
    break;

  case 8: /* variable_declaration: error  */
#line 395 "skylang.y"
               {
		if(passagem == 1){
			//erro_count = erro_count +1;
			(yyval.tree) = add_tree_node("Erro Sintatico");
			yyerror(yymsg);
		}
	}
#line 2416 "skylang.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 406 "skylang.y"
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
#line 2435 "skylang.tab.c"
    break;

  case 10: /* func_declaration: TYPE ID PARENTESES_INI $@1 params PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  */
#line 419 "skylang.y"
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
#line 2473 "skylang.tab.c"
    break;

  case 11: /* params: params_list  */
#line 455 "skylang.y"
                    { 
				if(passagem == 1){
					(yyval.tree) = add_tree_node("params");
		 			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
				}
	}
#line 2484 "skylang.tab.c"
    break;

  case 12: /* params_list: param COLON params_list  */
#line 463 "skylang.y"
                                {
							if(passagem == 1){ 
								(yyval.tree) = add_tree_node("params_list");
		 						(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
							  	(yyval.tree) -> leaf2 = (yyvsp[0].tree);
							}
	}
#line 2496 "skylang.tab.c"
    break;

  case 13: /* params_list: param  */
#line 470 "skylang.y"
               { 
			if(passagem == 1){
				(yyval.tree) = add_tree_node("params_list");
		 	 	(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			}
	}
#line 2507 "skylang.tab.c"
    break;

  case 14: /* params_list: %empty  */
#line 476 "skylang.y"
         { 
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	}
#line 2517 "skylang.tab.c"
    break;

  case 15: /* param: TYPE ID  */
#line 490 "skylang.y"
                { 
				if(passagem == 1){
				
					insert_symbol(symbol_ID, (yyvsp[0].str),"PARAMETRO_FUNCAO",(yyvsp[-1].str),escopoAtual,-1,conta_parametros);
					//registrador_atual = registrador_atual +1;
		    		symbol_ID = symbol_ID +1;
			 		(yyval.tree) = add_tree_node("param");
					conta_parametros = conta_parametros + 1;
				}
	}
#line 2532 "skylang.tab.c"
    break;

  case 16: /* codeBlock: statement_list  */
#line 502 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CodeBlock");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2543 "skylang.tab.c"
    break;

  case 17: /* statement_list: statement_list statement  */
#line 518 "skylang.y"
                                 {
			(yyval.tree) = add_tree_node("Statement_list");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
#line 2553 "skylang.tab.c"
    break;

  case 18: /* statement_list: %empty  */
#line 523 "skylang.y"
          {	
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Statement_list VAZIO");
		}
		 
	}
#line 2564 "skylang.tab.c"
    break;

  case 19: /* statement: variable_declaration  */
#line 533 "skylang.y"
                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2575 "skylang.tab.c"
    break;

  case 20: /* statement: exp SEMICOLON  */
#line 540 "skylang.y"
                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
		}
	 }
#line 2587 "skylang.tab.c"
    break;

  case 21: /* statement: ifStatement  */
#line 547 "skylang.y"
                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2598 "skylang.tab.c"
    break;

  case 22: /* statement: forAllStatement  */
#line 553 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2609 "skylang.tab.c"
    break;

  case 23: /* statement: outPutStatement SEMICOLON  */
#line 559 "skylang.y"
                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> linha_tac = (yyvsp[-1].tree) -> linha_tac;
		}
	 }
#line 2621 "skylang.tab.c"
    break;

  case 24: /* statement: inputStatement SEMICOLON  */
#line 566 "skylang.y"
                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2632 "skylang.tab.c"
    break;

  case 25: /* statement: callFuncStatement SEMICOLON  */
#line 572 "skylang.y"
                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2643 "skylang.tab.c"
    break;

  case 26: /* statement: RETURN exp SEMICOLON  */
#line 579 "skylang.y"
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
#line 2660 "skylang.tab.c"
    break;

  case 27: /* statement: forStatement  */
#line 592 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forStatement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2671 "skylang.tab.c"
    break;

  case 28: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 602 "skylang.y"
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
#line 2686 "skylang.tab.c"
    break;

  case 29: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM statement  */
#line 612 "skylang.y"
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
#line 2701 "skylang.tab.c"
    break;

  case 30: /* $@2: %empty  */
#line 627 "skylang.y"
           {func_call_atual = strdup((yyvsp[0].str));}
#line 2707 "skylang.tab.c"
    break;

  case 31: /* callFuncStatement: ID $@2 PARENTESES_INI call_params PARENTESES_FIM  */
#line 627 "skylang.y"
                                                                                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallFunStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
			if (check_num_params((yyvsp[-4].str),(yyvsp[-4].str))!= conta_parametros_2){
				snprintf(erro_atual,1100,"--> ERRO SEMANTICO: Numero de argumentos incorretos para a chamada de funcao na linha %d, coluna %d",num_linha_1,posicao_linha_1);
				adiciona_linha_erro(erros_semanticos,strdup(erro_atual));
			}
			conta_parametros_2 = 0;
		}

		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[-4].str));
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Funcao nao declarada\n", num_linha,posicao_linha);
			}
		}

	}
#line 2732 "skylang.tab.c"
    break;

  case 32: /* call_params: call_params_list  */
#line 651 "skylang.y"
                        {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallParams");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2743 "skylang.tab.c"
    break;

  case 33: /* call_params_list: call_param COLON call_params_list  */
#line 659 "skylang.y"
                                          {
		if(passagem == 1){ 
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2755 "skylang.tab.c"
    break;

  case 34: /* call_params_list: call_param  */
#line 666 "skylang.y"
                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}

	}
#line 2767 "skylang.tab.c"
    break;

  case 35: /* call_params_list: %empty  */
#line 673 "skylang.y"
         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	 }
#line 2777 "skylang.tab.c"
    break;

  case 36: /* call_param: terminal  */
#line 680 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_param terminal");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			//printf("\n\nAQUII: %s   %s",$1->value,func_call_atual);
			if(searchFunctionVariable_2((yyvsp[0].tree)->value,func_call_atual,conta_parametros_2,escopoAtual)==0){
				snprintf(erro_atual,1100,"--> ERRO SEMANTICO: Argumento %d do tipo errado na chamada de funcao da linha %d, coluna %d",conta_parametros_2+1,num_linha_1,posicao_linha_1);
				adiciona_linha_erro(erros_semanticos,strdup(erro_atual));
			}
			conta_parametros_2 = conta_parametros_2 + 1;
		}
	}
#line 2794 "skylang.tab.c"
    break;

  case 37: /* inputStatement: READ PARENTESES_INI terminal PARENTESES_FIM  */
#line 696 "skylang.y"
                                                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("read Statement");	 
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> type = translate_type(searchVarType((yyvsp[-1].tree)->value,escopoAtual));
			if((yyval.tree) -> type == 1){
				snprintf(codigo_tac,1100,"scani %s",(yyvsp[-1].tree)->value_tac);
				adiciona_linha_tac(tac_completo,strdup(codigo_tac));
				//registrador_atual ++;
			}
			if((yyval.tree) -> type == 2){
				snprintf(codigo_tac,1100,"scanf %s",(yyvsp[-1].tree)->value_tac);
				adiciona_linha_tac(tac_completo,strdup(codigo_tac));
				//registrador_atual ++;
			}
		}
	}
#line 2816 "skylang.tab.c"
    break;

  case 38: /* outPutStatement: WRITE PARENTESES_INI CONST PARENTESES_FIM  */
#line 717 "skylang.y"
                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("write");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2829 "skylang.tab.c"
    break;

  case 39: /* outPutStatement: WRITE PARENTESES_INI exp PARENTESES_FIM  */
#line 727 "skylang.y"
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
#line 2844 "skylang.tab.c"
    break;

  case 40: /* outPutStatement: WRITELN PARENTESES_INI CONST PARENTESES_FIM  */
#line 737 "skylang.y"
                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("writeln");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2856 "skylang.tab.c"
    break;

  case 41: /* outPutStatement: WRITELN PARENTESES_INI exp PARENTESES_FIM  */
#line 745 "skylang.y"
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
#line 2871 "skylang.tab.c"
    break;

  case 42: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM statement  */
#line 759 "skylang.y"
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
#line 2903 "skylang.tab.c"
    break;

  case 43: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 787 "skylang.y"
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
#line 2935 "skylang.tab.c"
    break;

  case 44: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement  */
#line 818 "skylang.y"
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
#line 2960 "skylang.tab.c"
    break;

  case 45: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement ELSE statement  */
#line 838 "skylang.y"
                                                                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2974 "skylang.tab.c"
    break;

  case 46: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 848 "skylang.y"
                                                                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2987 "skylang.tab.c"
    break;

  case 47: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM ELSE CHAVES_INI statement_list CHAVES_FIM  */
#line 856 "skylang.y"
                                                                                                                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-5].tree);
			(yyval.tree) -> leaf3 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3001 "skylang.tab.c"
    break;

  case 48: /* exp: NEGATION exp  */
#line 870 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Not");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3014 "skylang.tab.c"
    break;

  case 49: /* exp: setExp  */
#line 879 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	 }
#line 3026 "skylang.tab.c"
    break;

  case 50: /* exp: aritExp  */
#line 886 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> result;
			//$$ -> conversao = $1 -> conversao;
		}
	 }
#line 3040 "skylang.tab.c"
    break;

  case 51: /* exp: relExp  */
#line 895 "skylang.y"
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
#line 3055 "skylang.tab.c"
    break;

  case 52: /* exp: terminal  */
#line 905 "skylang.y"
                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> value_tac;
		}
	 }
#line 3068 "skylang.tab.c"
    break;

  case 53: /* exp: assignmentExp  */
#line 914 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			//$$ -> conversao = $1 -> conversao;
		}
	}
#line 3081 "skylang.tab.c"
    break;

  case 54: /* assignmentExp: terminal ASSIGN exp  */
#line 925 "skylang.y"
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
				if((yyval.tree) -> conversao == 2){
					snprintf(codigo_tac,1100,"fltoint $%d, %s",registrador_atual,(yyvsp[0].tree) -> value_tac);
					adiciona_linha_tac(tac_completo,strdup(codigo_tac));
					snprintf(char_reg,999,"$%d",registrador_atual);
					(yyvsp[0].tree) -> value_tac = strdup(char_reg);
					registrador_atual ++;
				}
				if((yyval.tree) -> conversao == 1){
					snprintf(codigo_tac,1100,"inttofl $%d, %s",registrador_atual,(yyvsp[0].tree) -> value_tac);
					adiciona_linha_tac(tac_completo,strdup(codigo_tac));
					snprintf(char_reg,999,"$%d",registrador_atual);
					(yyvsp[0].tree) -> value_tac = strdup(char_reg);
					registrador_atual ++;
				}
				
			}
			snprintf(codigo_tac,1100,"mov %s, %s", (yyvsp[-2].tree)->value_tac,(yyvsp[0].tree)->value_tac);
			(yyval.tree) -> linha_tac = strdup(codigo_tac);
			adiciona_linha_tac(tac_completo,(yyval.tree)->linha_tac);
		}
	}
#line 3117 "skylang.tab.c"
    break;

  case 55: /* assignmentExp: terminal ASSIGN CONST  */
#line 956 "skylang.y"
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
#line 3135 "skylang.tab.c"
    break;

  case 56: /* setExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 972 "skylang.y"
                                                                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	}
#line 3148 "skylang.tab.c"
    break;

  case 57: /* setExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 980 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print =1;
		}
	}
#line 3161 "skylang.tab.c"
    break;

  case 58: /* setExp: IS_SET PARENTESES_INI ID PARENTESES_FIM  */
#line 989 "skylang.y"
                                                 {
		(yyval.tree) = add_tree_node("IS_SET");
		(yyval.tree) -> flag_print =1;
	}
#line 3170 "skylang.tab.c"
    break;

  case 59: /* setExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 994 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print =1;
		}
	}
#line 3183 "skylang.tab.c"
    break;

  case 60: /* terms_set: aritSetExp  */
#line 1005 "skylang.y"
                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terms_set");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 3194 "skylang.tab.c"
    break;

  case 61: /* aritSetExp: ID  */
#line 1014 "skylang.y"
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
#line 3217 "skylang.tab.c"
    break;

  case 62: /* aritSetExp: FLOAT  */
#line 1032 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal FLOAT");
		}
		 
	 }
#line 3228 "skylang.tab.c"
    break;

  case 63: /* aritSetExp: INTEGER  */
#line 1038 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal INTEGER");
		}
		 
	 }
#line 3239 "skylang.tab.c"
    break;

  case 64: /* aritSetExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 1044 "skylang.y"
                                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 3251 "skylang.tab.c"
    break;

  case 65: /* aritSetExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 1052 "skylang.y"
                                                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 3263 "skylang.tab.c"
    break;

  case 66: /* aritSetExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 1060 "skylang.y"
                                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
		}
	}
#line 3275 "skylang.tab.c"
    break;

  case 67: /* aritExp: terminal OP exp  */
#line 1082 "skylang.y"
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
				if((yyval.tree) -> conversao == 2){
					snprintf(codigo_tac,1100,"fltoint $%d, %s",registrador_atual,(yyvsp[0].tree) -> value_tac);
					adiciona_linha_tac(tac_completo,strdup(codigo_tac));
					snprintf(char_reg,999,"$%d",registrador_atual);
					(yyvsp[0].tree) -> value_tac = strdup(char_reg);
					registrador_atual ++;
				}
				if((yyval.tree) -> conversao == 1){
					snprintf(codigo_tac,1100,"inttofl $%d, %s",registrador_atual,(yyvsp[0].tree) -> value_tac);
					adiciona_linha_tac(tac_completo,strdup(codigo_tac));
					snprintf(char_reg,999,"$%d",registrador_atual);
					(yyvsp[0].tree) -> value_tac = strdup(char_reg);
					registrador_atual ++;
				}
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
#line 3315 "skylang.tab.c"
    break;

  case 68: /* relExp: terminal rel exp  */
#line 1119 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("relExp");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			if (check_set_type((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type)==0){
				(yyval.tree) -> type = (yyvsp[-2].tree) -> type;
				(yyval.tree) -> conversao = check_conversao((yyvsp[-2].tree)->type,(yyvsp[0].tree)->type);
				if((yyval.tree) -> conversao == 2){
					snprintf(codigo_tac,1100,"fltoint $%d, %s",registrador_atual,(yyvsp[0].tree) -> value_tac);
					adiciona_linha_tac(tac_completo,strdup(codigo_tac));
					snprintf(char_reg,999,"$%d",registrador_atual);
					(yyvsp[0].tree) -> value_tac = strdup(char_reg);
					registrador_atual ++;
				}
				if((yyval.tree) -> conversao == 1){
					snprintf(codigo_tac,1100,"inttofl $%d, %s",registrador_atual,(yyvsp[0].tree) -> value_tac);
					adiciona_linha_tac(tac_completo,strdup(codigo_tac));
					snprintf(char_reg,999,"$%d",registrador_atual);
					(yyvsp[0].tree) -> value_tac = strdup(char_reg);
					registrador_atual ++;
				}
			}
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
			if(strcmp((yyvsp[-1].tree)->value_tac, ">")==0){
				
				snprintf(codigo_tac,1100,"sleq $%d, %s, %s",registrador_atual, (yyvsp[-2].tree)->value_tac,(yyvsp[0].tree)->value_tac);
				adiciona_linha_tac(tac_completo,strdup(codigo_tac));
				snprintf(codigo_tac,1100,"not $%d, $%d",registrador_atual,registrador_atual);
				snprintf(char_reg,999,"$%d",registrador_atual);
				(yyval.tree) -> result = strdup(char_reg);
				registrador_atual ++;
				(yyval.tree) -> linha_tac = strdup(codigo_tac);
				adiciona_linha_tac(tac_completo,(yyval.tree) -> linha_tac);
			}
		}
	 }
#line 3384 "skylang.tab.c"
    break;

  case 69: /* rel: CGE  */
#line 1186 "skylang.y"
            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   >=");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = ">=";
			(yyval.tree) -> value = ">=";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3398 "skylang.tab.c"
    break;

  case 70: /* rel: CGT  */
#line 1195 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   >");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = ">";
			(yyval.tree) -> value = ">";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3412 "skylang.tab.c"
    break;

  case 71: /* rel: CNE  */
#line 1204 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   !=");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = "!=";
			(yyval.tree) -> value = "!=";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3426 "skylang.tab.c"
    break;

  case 72: /* rel: CLT  */
#line 1213 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   <");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = "<";
			(yyval.tree) -> value = "<";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3440 "skylang.tab.c"
    break;

  case 73: /* rel: AND  */
#line 1222 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   &&");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = "&&";
			(yyval.tree) -> value = "&&";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3454 "skylang.tab.c"
    break;

  case 74: /* rel: CLE  */
#line 1231 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   <=");
			(yyval.tree) -> value_tac = "<=";
			(yyval.tree) -> value = "<=";
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3467 "skylang.tab.c"
    break;

  case 75: /* rel: CEQ  */
#line 1239 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("  ==");
			(yyval.tree) -> value_tac = "==";
			(yyval.tree) -> value = "==";
			(yyval.tree) -> flag_print = 1;
		}
	}
#line 3480 "skylang.tab.c"
    break;

  case 76: /* terminal: ID  */
#line 1261 "skylang.y"
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
#line 3509 "skylang.tab.c"
    break;

  case 77: /* terminal: FLOAT  */
#line 1285 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal CONST");
			(yyval.tree) -> type = 2;
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
		 
	 }
#line 3524 "skylang.tab.c"
    break;

  case 78: /* terminal: INTEGER  */
#line 1295 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal CONST");
			(yyval.tree) -> type = 1;
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
		 
	 }
#line 3539 "skylang.tab.c"
    break;

  case 79: /* terminal: PARENTESES_INI exp PARENTESES_FIM  */
#line 1306 "skylang.y"
                                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal EXP");
			(yyval.tree)->leaf1 =(yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[-1].tree) -> value_tac;
		}
	}
#line 3552 "skylang.tab.c"
    break;

  case 80: /* ASSIGN: EQUALS  */
#line 1319 "skylang.y"
       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" =");
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3563 "skylang.tab.c"
    break;

  case 81: /* OP: MULT  */
#line 1329 "skylang.y"
             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" *");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "mul";
		}
	 }
#line 3575 "skylang.tab.c"
    break;

  case 82: /* OP: PLUS  */
#line 1336 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" +");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "add";
		}
	 }
#line 3587 "skylang.tab.c"
    break;

  case 83: /* OP: MINUS  */
#line 1343 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" -");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "sub";
		}
	 }
#line 3599 "skylang.tab.c"
    break;

  case 84: /* OP: DIV  */
#line 1350 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" /");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "div";
		}
	 }
#line 3611 "skylang.tab.c"
    break;

  case 85: /* CONST: EMPTY  */
#line 1361 "skylang.y"
     {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("EMPTY");
			(yyval.tree) -> type = 3;
			(yyval.tree) -> value = (yyvsp[0].str);
		}
}
#line 3623 "skylang.tab.c"
    break;

  case 86: /* CONST: CHAR  */
#line 1369 "skylang.y"
     {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("CHAR");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print=1;
		}
}
#line 3636 "skylang.tab.c"
    break;

  case 87: /* CONST: STRING  */
#line 1378 "skylang.y"
       {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("STRING");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print=1;
		}
}
#line 3649 "skylang.tab.c"
    break;


#line 3653 "skylang.tab.c"

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

#line 1389 "skylang.y"


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
