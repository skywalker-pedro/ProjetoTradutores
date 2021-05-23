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


#line 316 "skylang.tab.c"

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
#define YYLAST   2407

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  294

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
     349,   396,   404,   411,   417,   431,   442,   458,   463,   473,
     480,   487,   493,   499,   506,   512,   519,   530,   540,   550,
     565,   584,   592,   599,   606,   613,   627,   639,   649,   659,
     668,   682,   710,   741,   761,   771,   779,   793,   802,   809,
     817,   827,   836,   846,   861,   874,   882,   891,   896,   907,
     916,   934,   940,   946,   968,   991,  1030,  1039,  1048,  1057,
    1066,  1075,  1083,  1105,  1129,  1139,  1150,  1163,  1173,  1180,
    1187,  1194,  1205,  1213,  1222
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

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-85)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,    14,    -5,     3,    97,   126,   130,   137,    -3,  -123,
     246,     5,   258,     7,     8,   -32,   -28,     6,    46,   -16,
       7,  1158,    -9,   -14,  1187,   270,    29,    68,   295,   337,
      58,    11,    18,    42,    50,    65,    66,    76,    79,    83,
      84,    58,  2197,  1216,  1245,  1274,    13,    39,    85,  1303,
    1332,    95,    99,   115,   144,   148,   352,   150,    16,   394,
     152,  2197,   516,   516,   132,    52,    52,    52,    58,   166,
     186,   161,   120,  1361,  1390,  1419,  1448,  2225,  2253,  2257,
    2281,  2285,  2309,  2313,  2201,  2337,  2341,  2365,  2369,    58,
    2229,    58,   171,   175,    53,   103,  1477,   176,   177,   182,
     184,   187,   192,   196,   198,   199,   213,   222,   223,   181,
     226,   234,   236,   238,   185,   248,   243,   409,   252,   253,
     254,   256,   266,    16,  1506,   268,   269,   271,   272,   276,
     250,    55,    55,    55,    58,   287,   280,   282,  1158,   549,
      52,   283,   288,   289,   286,   292,  1535,  2144,   281,   293,
     296,   308,  2197,  1564,   578,  1593,    55,   310,  1158,  1622,
     314,   312,  1651,  1680,  1158,   324,  1158,  1709,  1738,  1767,
     303,  1796,  1825,  1854,  1883,   451,   458,   465,   326,   327,
     328,   329,  2197,  2197,   330,   331,   333,   334,   472,  1912,
     108,   119,   135,  2197,   335,   336,   338,   607,   363,    58,
     345,   346,   347,   636,   665,   348,   349,   350,   694,   723,
     351,   354,   366,   367,   383,   369,    52,    52,    52,   376,
     370,   381,  2197,   516,  2197,   382,   384,   386,  2197,    58,
     411,   752,   781,   810,   839,   385,   398,   400,   401,   392,
     514,   393,   396,   402,   403,   142,   868,   897,   405,   406,
     404,    52,    55,    55,    55,   408,  1941,    58,   429,   416,
     444,   445,   447,  1158,   926,   410,   448,    55,   449,   450,
     452,  1970,  2173,  2197,  1999,   459,   955,   984,   466,  1158,
    1013,   473,   412,  2028,  2057,   474,  1158,  1158,  1042,  1071,
    2086,  2115,  1100,  1129
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
       0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,   521,     0,  -123,  -123,  -123,   506,  -123,
    -123,   -57,     4,  -122,   -76,  -123,   413,  -123,    -8,    12,
      41,    51,   -29,   -20,   -11,   101,   158,    -4,    57,   355,
     -37,   356,   357,   -54
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    43,     7,    13,    15,    16,    17,
      23,    24,    44,    45,    46,    92,    93,    94,    47,    48,
      49,    50,    51,    52,    53,   110,   111,    54,    55,    89,
      56,    90,    91,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       6,    60,   204,     9,     6,   188,     8,    19,    -9,   104,
      14,   -11,    71,    72,    -8,    -8,     1,    -8,     2,    18,
      21,    95,   184,    25,   188,   188,   188,   190,   191,   192,
     -12,   185,    97,   101,   103,    11,   120,    12,   186,   114,
      57,   184,   184,   184,    -9,   -13,   -14,    20,   205,    61,
     185,   185,   185,    73,   193,   -34,    62,   186,   186,   186,
     118,   119,   121,   106,   107,   108,   211,   212,   213,    59,
      28,    29,   -73,   -73,   -73,   -73,   -73,   -73,   -73,    74,
      63,   146,    35,    36,    37,   -15,    95,   -15,    64,    40,
     109,    41,   -33,   214,   123,   210,    42,    -2,     1,   187,
       2,   163,   -73,    65,    66,   144,    58,   169,   -73,   171,
     -73,   -73,   -73,   -73,    67,   188,   206,    68,   187,   187,
     187,    69,    70,   157,   203,    75,    -4,    -4,   139,    -4,
      -5,    -5,   184,    -5,   204,    76,   207,    -6,    -6,   -52,
      -6,   185,   -35,   105,   -35,   188,   188,   -73,   186,   -73,
     204,   155,   204,   220,   221,   -48,   188,   159,   -75,   117,
     -75,   204,   184,   184,   225,   208,   167,   112,   113,   243,
     227,   185,   185,   184,   -74,   209,   -74,   115,   186,   186,
     205,   -76,   185,   -76,   -49,   188,   188,   188,   -50,   186,
     189,   188,    96,   241,   242,   244,   205,   116,   205,   248,
     249,   -47,   184,   184,   184,   130,   271,   205,   184,   187,
     122,   185,   185,   185,   -31,   124,   -83,   185,   186,   186,
     186,   -84,   284,   -82,   186,   134,   125,   210,   265,   290,
     291,   126,   141,   142,   143,   127,   188,   128,   129,   187,
     187,   148,   -60,   210,   278,   210,    -3,    -3,   206,    -3,
     187,   -62,   -61,   184,   210,   131,   203,   161,    -7,    -7,
     264,    -7,   185,   -59,   206,   132,   206,   133,   207,   186,
     -10,   -10,   203,   -10,   203,   206,   277,   135,   280,   187,
     187,   187,   136,   203,   207,   187,   207,   288,   140,   215,
     215,   215,   -65,   -53,   -54,   207,   -64,   208,   145,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -30,   209,   -38,   -37,
     156,   -40,   -39,   208,   215,   208,   -36,   236,   237,   238,
     -57,   -32,   149,   209,   208,   209,   152,   150,   151,   -75,
     187,   153,   -63,   -58,   209,   -75,   -55,   -75,   -75,   -75,
     -75,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -56,   162,
     164,   165,   259,   260,   261,   262,    77,    78,    79,    80,
      81,    82,    83,   170,   216,   217,   218,   219,   275,   -52,
     -48,   -74,   -49,   -50,   226,   -83,   -84,   -74,   -82,   -74,
     -74,   -74,   -74,   228,   229,   230,    84,   239,   231,   232,
     233,   234,   -51,   -60,    85,    86,    87,    88,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -62,   -61,   235,   -59,   -47,
     215,   215,   215,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     240,   245,   250,   251,   246,   215,   247,   252,   -73,   253,
     254,   255,   -65,   258,   -73,   -53,   -73,   -73,   -73,   -73,
     266,   -54,   -64,   -76,   256,   267,   257,   -57,   286,   -76,
     273,   -76,   -76,   -76,   -76,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,    77,    78,    79,    80,
      81,    82,    83,   268,   269,   -73,   270,   274,   -58,   -55,
     -73,   -56,   -75,   -73,   -73,   -73,   -73,   -75,   281,   -74,
     -75,   -75,   -75,   -75,   -74,   283,    84,   -74,   -74,   -74,
     -74,   -51,   285,   -63,    85,    86,    87,    88,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,    10,    22,   175,   176,   177,
      98,    99,   100,     0,     0,     0,   137,     0,     0,     0,
     178,   179,   180,   222,   223,   224,     0,   181,   -76,   182,
     -43,     0,   -43,   -76,   183,     0,   -76,   -76,   -76,   -76,
     -43,   -43,   -43,     0,     0,     0,   -43,   -43,   147,     0,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,     0,   -45,
     -43,   -45,   -43,     0,     0,     0,   -43,   -43,     0,   -45,
     -45,   -45,     0,     0,     0,   -45,   -45,   160,     0,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,     0,    -8,   -45,
      -8,   -45,     0,     0,     0,   -45,   -45,     0,    -8,    -8,
      -8,     0,     0,     0,    -8,    -8,    -8,     0,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,     0,   -19,    -8,   -19,
      -8,     0,     0,     0,    -8,    -8,     0,   -19,   -19,   -19,
       0,     0,     0,   -19,   -19,   -19,     0,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,     0,   -27,   -19,   -27,   -19,
       0,     0,     0,   -19,   -19,     0,   -27,   -27,   -27,     0,
       0,     0,   -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,     0,   -22,   -27,   -22,   -27,     0,
       0,     0,   -27,   -27,     0,   -22,   -22,   -22,     0,     0,
       0,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,     0,   -21,   -22,   -21,   -22,     0,     0,
       0,   -22,   -22,     0,   -21,   -21,   -21,     0,     0,     0,
     -21,   -21,   -21,     0,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,     0,   -25,   -21,   -25,   -21,     0,     0,     0,
     -21,   -21,     0,   -25,   -25,   -25,     0,     0,     0,   -25,
     -25,   -25,     0,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,     0,   -24,   -25,   -24,   -25,     0,     0,     0,   -25,
     -25,     0,   -24,   -24,   -24,     0,     0,     0,   -24,   -24,
     -24,     0,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
       0,   -23,   -24,   -23,   -24,     0,     0,     0,   -24,   -24,
       0,   -23,   -23,   -23,     0,     0,     0,   -23,   -23,   -23,
       0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,
     -20,   -23,   -20,   -23,     0,     0,     0,   -23,   -23,     0,
     -20,   -20,   -20,     0,     0,     0,   -20,   -20,   -20,     0,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,     0,    -7,
     -20,    -7,   -20,     0,     0,     0,   -20,   -20,     0,    -7,
      -7,    -7,     0,     0,     0,    -7,    -7,    -7,     0,    -7,
      -7,    -7,    -7,    -7,    -7,    -7,    -7,     0,   -26,    -7,
     -26,    -7,     0,     0,     0,    -7,    -7,     0,   -26,   -26,
     -26,     0,     0,     0,   -26,   -26,   -26,     0,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,     0,   -43,   -26,   -43,
     -26,     0,     0,     0,   -26,   -26,     0,   -43,   -43,   -43,
       0,     0,     0,   -43,   -43,   272,     0,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,     0,   -45,   -43,   -45,   -43,
       0,     0,     0,   -43,   -43,     0,   -45,   -45,   -45,     0,
       0,     0,   -45,   -45,   282,     0,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,     0,   -44,   -45,   -44,   -45,     0,
       0,     0,   -45,   -45,     0,   -44,   -44,   -44,     0,     0,
       0,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,     0,   -41,   -44,   -41,   -44,     0,     0,
       0,   -44,   -44,     0,   -41,   -41,   -41,     0,     0,     0,
     -41,   -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,   -41,     0,   -29,   -41,   -29,   -41,     0,     0,     0,
     -41,   -41,     0,   -29,   -29,   -29,     0,     0,     0,   -29,
     -29,   -29,     0,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,     0,   -42,   -29,   -42,   -29,     0,     0,     0,   -29,
     -29,     0,   -42,   -42,   -42,     0,     0,     0,   -42,   -42,
     -42,     0,   -42,   -42,   -42,   -42,   -42,   -42,   -42,   -42,
       0,   -46,   -42,   -46,   -42,     0,     0,     0,   -42,   -42,
       0,   -46,   -46,   -46,     0,     0,     0,   -46,   -46,   -46,
       0,   -46,   -46,   -46,   -46,   -46,   -46,   -46,   -46,     0,
     -28,   -46,   -28,   -46,     0,     0,     0,   -46,   -46,     0,
     -28,   -28,   -28,     0,     0,     0,   -28,   -28,   -28,     0,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -18,
     -28,   -18,   -28,     0,     0,     0,   -28,   -28,     0,   -18,
     -18,   -18,     0,     0,     0,   -18,   -18,     0,     0,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,     0,   174,   -18,
      26,   -18,     0,     0,     0,   -18,   -18,     0,    27,    28,
      29,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,     0,   -19,    40,   -19,
      41,     0,     0,     0,   -16,    42,     0,   -19,   -19,   -19,
       0,     0,     0,   -19,   -19,     0,     0,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,     0,   -17,   -19,   -17,   -19,
       0,     0,     0,   -19,   -19,     0,   -17,   -17,   -17,     0,
       0,     0,   -17,   -17,     0,     0,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,     0,   -27,   -17,   -27,   -17,     0,
       0,     0,   -17,   -17,     0,   -27,   -27,   -27,     0,     0,
       0,   -27,   -27,     0,     0,   -27,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,     0,   -22,   -27,   -22,   -27,     0,     0,
       0,   -27,   -27,     0,   -22,   -22,   -22,     0,     0,     0,
     -22,   -22,     0,     0,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,     0,   -21,   -22,   -21,   -22,     0,     0,     0,
     -22,   -22,     0,   -21,   -21,   -21,     0,     0,     0,   -21,
     -21,     0,     0,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,     0,   -25,   -21,   -25,   -21,     0,     0,     0,   -21,
     -21,     0,   -25,   -25,   -25,     0,     0,     0,   -25,   -25,
       0,     0,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
       0,   -24,   -25,   -24,   -25,     0,     0,     0,   -25,   -25,
       0,   -24,   -24,   -24,     0,     0,     0,   -24,   -24,     0,
       0,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,
     -23,   -24,   -23,   -24,     0,     0,     0,   -24,   -24,     0,
     -23,   -23,   -23,     0,     0,     0,   -23,   -23,     0,     0,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -20,
     -23,   -20,   -23,     0,     0,     0,   -23,   -23,     0,   -20,
     -20,   -20,     0,     0,     0,   -20,   -20,     0,     0,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,     0,   -26,   -20,
     -26,   -20,     0,     0,     0,   -20,   -20,     0,   -26,   -26,
     -26,     0,     0,     0,   -26,   -26,     0,     0,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,     0,   197,   -26,   198,
     -26,     0,     0,     0,   -26,   -26,     0,    27,    28,    29,
       0,     0,     0,   199,   200,     0,     0,    32,    33,    34,
      35,    36,    37,   201,   202,     0,   174,    40,    26,    41,
       0,     0,   138,     0,    42,     0,    27,    28,    29,     0,
       0,     0,    30,    31,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,     0,   174,    40,    26,    41,     0,
       0,     0,   154,    42,     0,    27,    28,    29,     0,     0,
       0,    30,    31,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,     0,   -44,    40,   -44,    41,     0,     0,
     158,     0,    42,     0,   -44,   -44,   -44,     0,     0,     0,
     -44,   -44,     0,     0,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,     0,   -41,   -44,   -41,   -44,     0,     0,     0,
     -44,   -44,     0,   -41,   -41,   -41,     0,     0,     0,   -41,
     -41,     0,     0,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     -41,     0,   174,   -41,    26,   -41,     0,     0,     0,   -41,
     -41,     0,    27,    28,    29,     0,     0,     0,    30,    31,
       0,     0,    32,    33,    34,    35,    36,    37,    38,    39,
       0,   174,    40,    26,    41,     0,     0,   166,     0,    42,
       0,    27,    28,    29,     0,     0,     0,    30,    31,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,     0,
     -29,    40,   -29,    41,     0,     0,     0,   168,    42,     0,
     -29,   -29,   -29,     0,     0,     0,   -29,   -29,     0,     0,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -42,
     -29,   -42,   -29,     0,     0,     0,   -29,   -29,     0,   -42,
     -42,   -42,     0,     0,     0,   -42,   -42,     0,     0,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,     0,   174,   -42,
      26,   -42,     0,     0,     0,   -42,   -42,     0,    27,    28,
      29,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,     0,   174,    40,    26,
      41,     0,     0,     0,   172,    42,     0,    27,    28,    29,
       0,     0,     0,    30,    31,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,     0,   -46,    40,   -46,    41,
       0,     0,     0,   173,    42,     0,   -46,   -46,   -46,     0,
       0,     0,   -46,   -46,     0,     0,   -46,   -46,   -46,   -46,
     -46,   -46,   -46,   -46,     0,   -28,   -46,   -28,   -46,     0,
       0,     0,   -46,   -46,     0,   -28,   -28,   -28,     0,     0,
       0,   -28,   -28,     0,     0,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,     0,    -8,   -28,    -8,   -28,     0,     0,
       0,   -28,   -28,     0,    -8,    -8,    -8,     0,     0,     0,
      -8,    -8,     0,     0,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,     0,    -7,    -8,    -7,    -8,     0,     0,     0,
      -8,    -8,     0,    -7,    -7,    -7,     0,     0,     0,    -7,
      -7,     0,     0,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,     0,   197,    -7,   198,    -7,     0,     0,     0,    -7,
      -7,     0,    27,    28,    29,     0,     0,     0,   199,   200,
       0,     0,    32,    33,    34,    35,    36,    37,   201,   202,
       0,   174,    40,    26,    41,     0,     0,   263,     0,    42,
       0,    27,    28,    29,     0,     0,     0,    30,    31,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,     0,
     197,    40,   198,    41,     0,     0,     0,   276,    42,     0,
      27,    28,    29,     0,     0,     0,   199,   200,     0,     0,
      32,    33,    34,    35,    36,    37,   201,   202,     0,   197,
      40,   198,    41,     0,     0,   279,     0,    42,     0,    27,
      28,    29,     0,     0,     0,   199,   200,     0,     0,    32,
      33,    34,    35,    36,    37,   201,   202,     0,   174,    40,
      26,    41,     0,     0,   287,     0,    42,     0,    27,    28,
      29,     0,     0,     0,    30,    31,     0,     0,    32,    33,
      34,    35,    36,    37,    38,    39,     0,   174,    40,    26,
      41,     0,     0,     0,   289,    42,     0,    27,    28,    29,
       0,     0,     0,    30,    31,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,     0,   174,    40,    26,    41,
       0,     0,     0,   292,    42,     0,    27,    28,    29,     0,
       0,     0,    30,    31,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,     0,   174,    40,    26,    41,     0,
       0,     0,   293,    42,     0,    27,    28,    29,     0,     0,
       0,    30,    31,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,     0,   197,    40,   198,    41,     0,     0,
       0,     0,    42,     0,    27,    28,    29,     0,     0,     0,
     199,   200,     0,     0,    32,    33,    34,    35,    36,    37,
     201,   202,     0,     0,    40,     0,    41,     0,   175,   176,
     177,    42,   -77,   -77,   -77,   -77,   -77,   -77,     0,     0,
       0,   178,   179,   180,     0,   -77,   -77,   -77,   181,     0,
     182,     0,   -77,     0,   -77,   183,   -71,   -71,   -71,   -77,
      59,    28,    29,   194,   195,   196,     0,     0,     0,   -71,
     -71,   -71,     0,    35,    36,    37,   -71,     0,   -71,     0,
      40,     0,    41,   -71,   -69,   -69,   -69,    42,   -68,   -68,
     -68,     0,     0,     0,     0,     0,     0,   -69,   -69,   -69,
       0,   -68,   -68,   -68,   -69,     0,   -69,     0,   -68,     0,
     -68,   -69,   -67,   -67,   -67,   -68,   -70,   -70,   -70,     0,
       0,     0,     0,     0,     0,   -67,   -67,   -67,     0,   -70,
     -70,   -70,   -67,     0,   -67,     0,   -70,     0,   -70,   -67,
     -72,   -72,   -72,   -70,   -66,   -66,   -66,     0,     0,     0,
       0,     0,     0,   -72,   -72,   -72,     0,   -66,   -66,   -66,
     -72,     0,   -72,     0,   -66,     0,   -66,   -72,   -79,   -79,
     -79,   -66,   -80,   -80,   -80,     0,     0,     0,     0,     0,
       0,   -79,   -79,   -79,     0,   -80,   -80,   -80,   -79,     0,
     -79,     0,   -80,     0,   -80,   -79,   -78,   -78,   -78,   -80,
     -81,   -81,   -81,     0,     0,     0,     0,     0,     0,   -78,
     -78,   -78,     0,   -81,   -81,   -81,   -78,     0,   -78,     0,
     -81,     0,   -81,   -78,     0,     0,     0,   -81
};

static const yytype_int16 yycheck[] =
{
       0,    30,   124,     0,     4,    42,    11,    39,     3,    63,
       3,    39,    41,    42,     0,     1,     1,     3,     3,    11,
      36,    58,    42,    37,    61,    62,    63,    11,    12,    13,
      39,    42,    61,    62,    63,    38,    90,    40,    42,    68,
      11,    61,    62,    63,    39,    39,    39,    41,   124,    38,
      61,    62,    63,    40,    38,    39,    38,    61,    62,    63,
      89,    90,    91,    11,    12,    13,    11,    12,    13,    11,
      12,    13,     4,     5,     6,     7,     8,     9,    10,    40,
      38,   138,    24,    25,    26,    39,   123,    41,    38,    31,
      38,    33,    39,    38,    41,   124,    38,     0,     1,    42,
       3,   158,    34,    38,    38,   134,    38,   164,    40,   166,
      42,    43,    44,    45,    38,   152,   124,    38,    61,    62,
      63,    38,    38,   152,   124,    40,     0,     1,   124,     3,
       0,     1,   152,     3,   256,    40,   124,     0,     1,    40,
       3,   152,    39,    11,    41,   182,   183,    39,   152,    41,
     272,   147,   274,   182,   183,    40,   193,   153,    39,    39,
      41,   283,   182,   183,   193,   124,   162,    66,    67,   223,
     199,   182,   183,   193,    39,   124,    41,    11,   182,   183,
     256,    39,   193,    41,    40,   222,   223,   224,    40,   193,
      40,   228,    40,   222,   223,   224,   272,    11,   274,   228,
     229,    40,   222,   223,   224,    24,   263,   283,   228,   152,
      39,   222,   223,   224,    39,    39,    39,   228,   222,   223,
     224,    39,   279,    39,   228,    40,    39,   256,   257,   286,
     287,    39,   131,   132,   133,    39,   273,    39,    39,   182,
     183,   140,    29,   272,   273,   274,     0,     1,   256,     3,
     193,    29,    29,   273,   283,    29,   256,   156,     0,     1,
     256,     3,   273,    29,   272,    29,   274,    29,   256,   273,
       0,     1,   272,     3,   274,   283,   272,    29,   274,   222,
     223,   224,    39,   283,   272,   228,   274,   283,    38,   131,
     132,   133,    40,    40,    40,   283,    40,   256,    11,     4,
       5,     6,     7,     8,     9,    10,    40,   256,    40,    40,
      29,    40,    40,   272,   156,   274,    40,   216,   217,   218,
      40,    39,    39,   272,   283,   274,    40,    39,    39,    34,
     273,    39,    29,    40,   283,    40,    40,    42,    43,    44,
      45,     4,     5,     6,     7,     8,     9,    10,    40,    39,
      36,    39,   251,   252,   253,   254,     4,     5,     6,     7,
       8,     9,    10,    39,    38,    38,    38,    38,   267,    39,
      39,    34,    39,    39,    11,    40,    40,    40,    40,    42,
      43,    44,    45,    38,    38,    38,    34,    11,    40,    40,
      40,    40,    40,    39,    42,    43,    44,    45,     4,     5,
       6,     7,     8,     9,    10,    39,    39,    24,    39,    39,
     252,   253,   254,     4,     5,     6,     7,     8,     9,    10,
      39,    39,    11,    38,    40,   267,    40,    29,    34,    29,
      29,    39,    39,    29,    40,    39,    42,    43,    44,    45,
      11,    39,    39,    34,    39,    29,    40,    39,    36,    40,
      40,    42,    43,    44,    45,     4,     5,     6,     7,     8,
       9,    10,     4,     5,     6,     7,     8,     9,    10,     4,
       5,     6,     7,     8,     9,    10,     4,     5,     6,     7,
       8,     9,    10,    39,    39,    34,    39,    39,    39,    39,
      39,    39,    34,    42,    43,    44,    45,    39,    39,    34,
      42,    43,    44,    45,    39,    39,    34,    42,    43,    44,
      45,    39,    39,    39,    42,    43,    44,    45,     4,     5,
       6,     7,     8,     9,    10,     4,    20,    11,    12,    13,
      14,    15,    16,    -1,    -1,    -1,   123,    -1,    -1,    -1,
      24,    25,    26,   188,   188,   188,    -1,    31,    34,    33,
       1,    -1,     3,    39,    38,    -1,    42,    43,    44,    45,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,     1,
      31,     3,    33,    -1,    -1,    -1,    37,    38,    -1,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,     1,    31,
       3,    33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,     1,    31,     3,
      33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,     1,    31,     3,    33,
      -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,     1,    31,     3,    33,    -1,
      -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,     1,    31,     3,    33,    -1,    -1,
      -1,    37,    38,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,     1,    31,     3,    33,    -1,    -1,    -1,
      37,    38,    -1,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,     1,    31,     3,    33,    -1,    -1,    -1,    37,
      38,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,     1,    31,     3,    33,    -1,    -1,    -1,    37,    38,
      -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
       1,    31,     3,    33,    -1,    -1,    -1,    37,    38,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,     1,
      31,     3,    33,    -1,    -1,    -1,    37,    38,    -1,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,     1,    31,
       3,    33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,     1,    31,     3,
      33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,     1,    31,     3,    33,
      -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,     1,    31,     3,    33,    -1,
      -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,     1,    31,     3,    33,    -1,    -1,
      -1,    37,    38,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,     1,    31,     3,    33,    -1,    -1,    -1,
      37,    38,    -1,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,     1,    31,     3,    33,    -1,    -1,    -1,    37,
      38,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,     1,    31,     3,    33,    -1,    -1,    -1,    37,    38,
      -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
       1,    31,     3,    33,    -1,    -1,    -1,    37,    38,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,     1,
      31,     3,    33,    -1,    -1,    -1,    37,    38,    -1,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,     1,    31,
       3,    33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,     1,    31,     3,
      33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,     1,    31,     3,    33,
      -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,     1,    31,     3,    33,    -1,
      -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,     1,    31,     3,    33,    -1,    -1,
      -1,    37,    38,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,     1,    31,     3,    33,    -1,    -1,    -1,
      37,    38,    -1,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,     1,    31,     3,    33,    -1,    -1,    -1,    37,
      38,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,     1,    31,     3,    33,    -1,    -1,    -1,    37,    38,
      -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
       1,    31,     3,    33,    -1,    -1,    -1,    37,    38,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,     1,
      31,     3,    33,    -1,    -1,    -1,    37,    38,    -1,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,     1,    31,
       3,    33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,     1,    31,     3,
      33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,     1,    31,     3,    33,
      -1,    -1,    36,    -1,    38,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,     1,    31,     3,    33,    -1,
      -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,     1,    31,     3,    33,    -1,    -1,
      36,    -1,    38,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,     1,    31,     3,    33,    -1,    -1,    -1,
      37,    38,    -1,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,     1,    31,     3,    33,    -1,    -1,    -1,    37,
      38,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,     1,    31,     3,    33,    -1,    -1,    36,    -1,    38,
      -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
       1,    31,     3,    33,    -1,    -1,    -1,    37,    38,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,     1,
      31,     3,    33,    -1,    -1,    -1,    37,    38,    -1,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,     1,    31,
       3,    33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,     1,    31,     3,
      33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,     1,    31,     3,    33,
      -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,     1,    31,     3,    33,    -1,
      -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,     1,    31,     3,    33,    -1,    -1,
      -1,    37,    38,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,     1,    31,     3,    33,    -1,    -1,    -1,
      37,    38,    -1,    11,    12,    13,    -1,    -1,    -1,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,     1,    31,     3,    33,    -1,    -1,    -1,    37,
      38,    -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,     1,    31,     3,    33,    -1,    -1,    36,    -1,    38,
      -1,    11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
       1,    31,     3,    33,    -1,    -1,    -1,    37,    38,    -1,
      11,    12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,     1,
      31,     3,    33,    -1,    -1,    36,    -1,    38,    -1,    11,
      12,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,     1,    31,
       3,    33,    -1,    -1,    36,    -1,    38,    -1,    11,    12,
      13,    -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,     1,    31,     3,
      33,    -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,
      -1,    -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,     1,    31,     3,    33,
      -1,    -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,
      -1,    -1,    17,    18,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,     1,    31,     3,    33,    -1,
      -1,    -1,    37,    38,    -1,    11,    12,    13,    -1,    -1,
      -1,    17,    18,    -1,    -1,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,     1,    31,     3,    33,    -1,    -1,
      -1,    -1,    38,    -1,    11,    12,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    31,    -1,    33,    -1,    11,    12,
      13,    38,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    24,    25,    26,    -1,    24,    25,    26,    31,    -1,
      33,    -1,    31,    -1,    33,    38,    11,    12,    13,    38,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,    24,
      25,    26,    -1,    24,    25,    26,    31,    -1,    33,    -1,
      31,    -1,    33,    38,    11,    12,    13,    38,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      -1,    24,    25,    26,    31,    -1,    33,    -1,    31,    -1,
      33,    38,    11,    12,    13,    38,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,    24,
      25,    26,    31,    -1,    33,    -1,    31,    -1,    33,    38,
      11,    12,    13,    38,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    -1,    24,    25,    26,
      31,    -1,    33,    -1,    31,    -1,    33,    38,    11,    12,
      13,    38,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    -1,    24,    25,    26,    31,    -1,
      33,    -1,    31,    -1,    33,    38,    11,    12,    13,    38,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    -1,    24,    25,    26,    31,    -1,    33,    -1,
      31,    -1,    33,    38,    -1,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    48,    49,    50,    51,    52,    11,     0,
      50,    38,    40,    53,     3,    54,    55,    56,    11,    39,
      41,    36,    55,    57,    58,    37,     3,    11,    12,    13,
      17,    18,    21,    22,    23,    24,    25,    26,    27,    28,
      31,    33,    38,    51,    59,    60,    61,    65,    66,    67,
      68,    69,    70,    71,    74,    75,    77,    11,    38,    11,
      69,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    69,    69,    40,    40,    40,    40,     4,     5,     6,
       7,     8,     9,    10,    34,    42,    43,    44,    45,    76,
      78,    79,    62,    63,    64,    77,    40,    69,    14,    15,
      16,    69,    80,    69,    80,    11,    11,    12,    13,    38,
      72,    73,    72,    72,    69,    11,    11,    39,    69,    69,
      80,    69,    39,    41,    39,    39,    39,    39,    39,    39,
      24,    29,    29,    29,    40,    29,    39,    63,    36,    59,
      38,    72,    72,    72,    69,    11,    58,    19,    72,    39,
      39,    39,    40,    39,    37,    59,    29,    69,    36,    59,
      19,    72,    39,    58,    36,    39,    36,    59,    37,    58,
      39,    58,    37,    37,     1,    11,    12,    13,    24,    25,
      26,    31,    33,    38,    70,    71,    74,    75,    77,    40,
      11,    12,    13,    38,    14,    15,    16,     1,     3,    17,
      18,    27,    28,    51,    60,    61,    65,    66,    67,    68,
      69,    11,    12,    13,    38,    73,    38,    38,    38,    38,
      69,    69,    76,    78,    79,    69,    11,    69,    38,    38,
      38,    40,    40,    40,    40,    24,    72,    72,    72,    11,
      39,    69,    69,    80,    69,    39,    40,    40,    69,    69,
      11,    38,    29,    29,    29,    39,    39,    40,    29,    72,
      72,    72,    72,    36,    59,    69,    11,    29,    39,    39,
      39,    58,    19,    40,    39,    72,    37,    59,    69,    36,
      59,    39,    19,    39,    58,    39,    36,    36,    59,    37,
      58,    58,    37,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    51,    51,    53,
      52,    54,    55,    55,    55,    56,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      61,    62,    63,    63,    63,    64,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    71,    71,    71,    71,    72,
      73,    73,    73,    73,    74,    75,    76,    76,    76,    76,
      76,    76,    76,    77,    77,    77,    77,    78,    79,    79,
      79,    79,    80,    80,    80
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
       1,     1,     1,     8,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 2259 "skylang.tab.c"
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
#line 2271 "skylang.tab.c"
    break;

  case 4: /* declarationList: declaration  */
#line 294 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declarationList");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2282 "skylang.tab.c"
    break;

  case 5: /* declaration: variable_declaration  */
#line 303 "skylang.y"
                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2293 "skylang.tab.c"
    break;

  case 6: /* declaration: func_declaration  */
#line 309 "skylang.y"
                          {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("declaration");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2304 "skylang.tab.c"
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
#line 2329 "skylang.tab.c"
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
#line 2341 "skylang.tab.c"
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
#line 2359 "skylang.tab.c"
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
#line 2396 "skylang.tab.c"
    break;

  case 11: /* params: params_list  */
#line 396 "skylang.y"
                    { 
				if(passagem == 1){
					(yyval.tree) = add_tree_node("params");
		 			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
				}
	}
#line 2407 "skylang.tab.c"
    break;

  case 12: /* params_list: param COLON params_list  */
#line 404 "skylang.y"
                                {
							if(passagem == 1){ 
								(yyval.tree) = add_tree_node("params_list");
		 						(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
							  	(yyval.tree) -> leaf2 = (yyvsp[0].tree);
							}
	}
#line 2419 "skylang.tab.c"
    break;

  case 13: /* params_list: param  */
#line 411 "skylang.y"
               { 
			if(passagem == 1){
				(yyval.tree) = add_tree_node("params_list");
		 	 	(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			}
	}
#line 2430 "skylang.tab.c"
    break;

  case 14: /* params_list: %empty  */
#line 417 "skylang.y"
         { 
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	}
#line 2440 "skylang.tab.c"
    break;

  case 15: /* param: TYPE ID  */
#line 431 "skylang.y"
                { 
				if(passagem == 1){
				
					insert_symbol(symbol_ID, (yyvsp[0].str),"PARAMETRO_FUNCAO",(yyvsp[-1].str),escopoAtual,-1);
					//registrador_atual = registrador_atual +1;
		    		symbol_ID = symbol_ID +1;
			 		(yyval.tree) = add_tree_node("param");
				}
	}
#line 2454 "skylang.tab.c"
    break;

  case 16: /* codeBlock: statement_list  */
#line 442 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CodeBlock");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2465 "skylang.tab.c"
    break;

  case 17: /* statement_list: statement_list statement  */
#line 458 "skylang.y"
                                 {
			(yyval.tree) = add_tree_node("Statement_list");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
#line 2475 "skylang.tab.c"
    break;

  case 18: /* statement_list: %empty  */
#line 463 "skylang.y"
          {	
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Statement_list VAZIO");
		}
		 
	}
#line 2486 "skylang.tab.c"
    break;

  case 19: /* statement: variable_declaration  */
#line 473 "skylang.y"
                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2497 "skylang.tab.c"
    break;

  case 20: /* statement: exp SEMICOLON  */
#line 480 "skylang.y"
                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
		}
	 }
#line 2509 "skylang.tab.c"
    break;

  case 21: /* statement: ifStatement  */
#line 487 "skylang.y"
                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2520 "skylang.tab.c"
    break;

  case 22: /* statement: forAllStatement  */
#line 493 "skylang.y"
                         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	 }
#line 2531 "skylang.tab.c"
    break;

  case 23: /* statement: outPutStatement SEMICOLON  */
#line 499 "skylang.y"
                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> linha_tac = (yyvsp[-1].tree) -> linha_tac;
		}
	 }
#line 2543 "skylang.tab.c"
    break;

  case 24: /* statement: inputStatement SEMICOLON  */
#line 506 "skylang.y"
                                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2554 "skylang.tab.c"
    break;

  case 25: /* statement: callFuncStatement SEMICOLON  */
#line 512 "skylang.y"
                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("statement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
		}
	 }
#line 2565 "skylang.tab.c"
    break;

  case 26: /* statement: RETURN exp SEMICOLON  */
#line 519 "skylang.y"
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
#line 530 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("forStatement");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2591 "skylang.tab.c"
    break;

  case 28: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 540 "skylang.y"
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
#line 2606 "skylang.tab.c"
    break;

  case 29: /* forStatement: FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM statement  */
#line 550 "skylang.y"
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
#line 2621 "skylang.tab.c"
    break;

  case 30: /* callFuncStatement: ID PARENTESES_INI call_params PARENTESES_FIM  */
#line 565 "skylang.y"
                                                     {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallFunStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}

		if(passagem == 2){
			existe_simbolo = searchSymbol((yyvsp[-3].str));
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Funcao nao declarada\n", num_linha,posicao_linha);
			}
		}

	}
#line 2641 "skylang.tab.c"
    break;

  case 31: /* call_params: call_params_list  */
#line 584 "skylang.y"
                        {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("CallParams");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 2652 "skylang.tab.c"
    break;

  case 32: /* call_params_list: call_param COLON call_params_list  */
#line 592 "skylang.y"
                                          {
		if(passagem == 1){ 
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf2 = (yyvsp[0].tree);
		}
	}
#line 2664 "skylang.tab.c"
    break;

  case 33: /* call_params_list: call_param  */
#line 599 "skylang.y"
                    {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_params_list");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}

	}
#line 2676 "skylang.tab.c"
    break;

  case 34: /* call_params_list: %empty  */
#line 606 "skylang.y"
         {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Vazio");
		}
	 }
#line 2686 "skylang.tab.c"
    break;

  case 35: /* call_param: terminal  */
#line 613 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("call_param terminal");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}

		if(passagem == 2){
			
		}
	}
#line 2701 "skylang.tab.c"
    break;

  case 36: /* inputStatement: READ PARENTESES_INI ID PARENTESES_FIM  */
#line 627 "skylang.y"
                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("read Statement");	 
			(yyval.tree) -> flag_print = 1;
			//$$ -> leaf1 = $3;
			(yyval.tree) -> flag_print = 1;
		}
	}
#line 2714 "skylang.tab.c"
    break;

  case 37: /* outPutStatement: WRITE PARENTESES_INI CONST PARENTESES_FIM  */
#line 639 "skylang.y"
                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("write");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2727 "skylang.tab.c"
    break;

  case 38: /* outPutStatement: WRITE PARENTESES_INI exp PARENTESES_FIM  */
#line 649 "skylang.y"
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
#line 2742 "skylang.tab.c"
    break;

  case 39: /* outPutStatement: WRITELN PARENTESES_INI CONST PARENTESES_FIM  */
#line 659 "skylang.y"
                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("writeln");
			(yyval.tree) -> leaf1 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2754 "skylang.tab.c"
    break;

  case 40: /* outPutStatement: WRITELN PARENTESES_INI exp PARENTESES_FIM  */
#line 668 "skylang.y"
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
#line 2769 "skylang.tab.c"
    break;

  case 41: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM statement  */
#line 682 "skylang.y"
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
#line 2801 "skylang.tab.c"
    break;

  case 42: /* forAllStatement: FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 710 "skylang.y"
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
#line 2833 "skylang.tab.c"
    break;

  case 43: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement  */
#line 741 "skylang.y"
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
#line 2858 "skylang.tab.c"
    break;

  case 44: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM statement ELSE statement  */
#line 761 "skylang.y"
                                                                       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
			(yyval.tree) -> leaf3 = (yyvsp[0].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2872 "skylang.tab.c"
    break;

  case 45: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM  */
#line 771 "skylang.y"
                                                                                              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2885 "skylang.tab.c"
    break;

  case 46: /* ifStatement: IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM ELSE CHAVES_INI statement_list CHAVES_FIM  */
#line 779 "skylang.y"
                                                                                                                             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("ifElseStatement");
			(yyval.tree) -> leaf1 = (yyvsp[-8].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-5].tree);
			(yyval.tree) -> leaf3 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2899 "skylang.tab.c"
    break;

  case 47: /* exp: NEGATION exp  */
#line 793 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("Not");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 2912 "skylang.tab.c"
    break;

  case 48: /* exp: setExp  */
#line 802 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	 }
#line 2924 "skylang.tab.c"
    break;

  case 49: /* exp: aritExp  */
#line 809 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> result;
		}
	 }
#line 2937 "skylang.tab.c"
    break;

  case 50: /* exp: relExp  */
#line 817 "skylang.y"
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
#line 2952 "skylang.tab.c"
    break;

  case 51: /* exp: terminal  */
#line 827 "skylang.y"
                  {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[0].tree) -> value_tac;
		}
	 }
#line 2965 "skylang.tab.c"
    break;

  case 52: /* exp: assignmentExp  */
#line 836 "skylang.y"
                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("exp");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
			(yyval.tree) -> type = (yyvsp[0].tree) -> type;
		}
	}
#line 2977 "skylang.tab.c"
    break;

  case 53: /* assignmentExp: terminal ASSIGN exp  */
#line 846 "skylang.y"
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
#line 2997 "skylang.tab.c"
    break;

  case 54: /* assignmentExp: terminal ASSIGN CONST  */
#line 861 "skylang.y"
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
#line 3012 "skylang.tab.c"
    break;

  case 55: /* setExp: ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 874 "skylang.y"
                                                                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print = 1;
		}
	}
#line 3025 "skylang.tab.c"
    break;

  case 56: /* setExp: REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 882 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print =1;
		}
	}
#line 3038 "skylang.tab.c"
    break;

  case 57: /* setExp: IS_SET PARENTESES_INI ID PARENTESES_FIM  */
#line 891 "skylang.y"
                                                 {
		(yyval.tree) = add_tree_node("IS_SET");
		(yyval.tree) -> flag_print =1;
	}
#line 3047 "skylang.tab.c"
    break;

  case 58: /* setExp: EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM  */
#line 896 "skylang.y"
                                                                      {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("setExp");
			(yyval.tree) -> leaf1 = (yyvsp[-3].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-1].tree);
			(yyval.tree) -> flag_print =1;
		}
	}
#line 3060 "skylang.tab.c"
    break;

  case 59: /* terms_set: aritSetExp  */
#line 907 "skylang.y"
                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terms_set");
			(yyval.tree) -> leaf1 = (yyvsp[0].tree);
		}
	}
#line 3071 "skylang.tab.c"
    break;

  case 60: /* aritSetExp: ID  */
#line 916 "skylang.y"
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
#line 3094 "skylang.tab.c"
    break;

  case 61: /* aritSetExp: FLOAT  */
#line 934 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal FLOAT");
		}
		 
	 }
#line 3105 "skylang.tab.c"
    break;

  case 62: /* aritSetExp: INTEGER  */
#line 940 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal INTEGER");
		}
		 
	 }
#line 3116 "skylang.tab.c"
    break;

  case 63: /* aritSetExp: PARENTESES_INI EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM PARENTESES_FIM  */
#line 946 "skylang.y"
                                                                                                   {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("aritSetExp"); 
			(yyval.tree) -> leaf1 = (yyvsp[-4].tree);
			(yyval.tree) -> leaf2 = (yyvsp[-2].tree);
		}
	}
#line 3128 "skylang.tab.c"
    break;

  case 64: /* aritExp: terminal OP exp  */
#line 968 "skylang.y"
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
#line 3154 "skylang.tab.c"
    break;

  case 65: /* relExp: terminal rel exp  */
#line 991 "skylang.y"
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
#line 3195 "skylang.tab.c"
    break;

  case 66: /* rel: CGE  */
#line 1030 "skylang.y"
            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   >=");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = ">=";
			(yyval.tree) -> value = ">=";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3209 "skylang.tab.c"
    break;

  case 67: /* rel: CGT  */
#line 1039 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   >");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = ">";
			(yyval.tree) -> value = ">";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3223 "skylang.tab.c"
    break;

  case 68: /* rel: CNE  */
#line 1048 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   !=");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = "!=";
			(yyval.tree) -> value = "!=";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3237 "skylang.tab.c"
    break;

  case 69: /* rel: CLT  */
#line 1057 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   <");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = "<";
			(yyval.tree) -> value = "<";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3251 "skylang.tab.c"
    break;

  case 70: /* rel: AND  */
#line 1066 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   &&");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value_tac = "&&";
			(yyval.tree) -> value = "&&";
			(yyval.tree) -> flag_print =1;
		}
	 }
#line 3265 "skylang.tab.c"
    break;

  case 71: /* rel: CLE  */
#line 1075 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("   <=");
			(yyval.tree) -> value_tac = "<=";
			(yyval.tree) -> value = "<=";
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3278 "skylang.tab.c"
    break;

  case 72: /* rel: CEQ  */
#line 1083 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("  ==");
			(yyval.tree) -> value_tac = "==";
			(yyval.tree) -> value = "==";
			(yyval.tree) -> flag_print = 1;
		}
	}
#line 3291 "skylang.tab.c"
    break;

  case 73: /* terminal: ID  */
#line 1105 "skylang.y"
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
#line 3320 "skylang.tab.c"
    break;

  case 74: /* terminal: FLOAT  */
#line 1129 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal CONST");
			(yyval.tree) -> type = 2;
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
		 
	 }
#line 3335 "skylang.tab.c"
    break;

  case 75: /* terminal: INTEGER  */
#line 1139 "skylang.y"
                 {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal CONST");
			(yyval.tree) -> type = 1;
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> value_tac = (yyvsp[0].str);
		}
		 
	 }
#line 3350 "skylang.tab.c"
    break;

  case 76: /* terminal: PARENTESES_INI exp PARENTESES_FIM  */
#line 1150 "skylang.y"
                                            {
		if(passagem == 1){
			(yyval.tree) = add_tree_node("terminal EXP");
			(yyval.tree)->leaf1 =(yyvsp[-1].tree);
			(yyval.tree) -> type = (yyvsp[-1].tree) -> type;
			(yyval.tree) -> value_tac = (yyvsp[-1].tree) -> value_tac;
		}
	}
#line 3363 "skylang.tab.c"
    break;

  case 77: /* ASSIGN: EQUALS  */
#line 1163 "skylang.y"
       {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" =");
			(yyval.tree) -> flag_print = 1;
		}
	 }
#line 3374 "skylang.tab.c"
    break;

  case 78: /* OP: MULT  */
#line 1173 "skylang.y"
             {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" *");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "mul";
		}
	 }
#line 3386 "skylang.tab.c"
    break;

  case 79: /* OP: PLUS  */
#line 1180 "skylang.y"
               {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" +");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "add";
		}
	 }
#line 3398 "skylang.tab.c"
    break;

  case 80: /* OP: MINUS  */
#line 1187 "skylang.y"
                {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" -");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "sub";
		}
	 }
#line 3410 "skylang.tab.c"
    break;

  case 81: /* OP: DIV  */
#line 1194 "skylang.y"
              {
		if(passagem == 1){
			(yyval.tree) = add_tree_node(" /");
			(yyval.tree) -> flag_print = 1;
			(yyval.tree) -> value_tac = "div";
		}
	 }
#line 3422 "skylang.tab.c"
    break;

  case 82: /* CONST: EMPTY  */
#line 1205 "skylang.y"
     {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("EMPTY");
			(yyval.tree) -> type = 3;
			(yyval.tree) -> value = (yyvsp[0].str);
		}
}
#line 3434 "skylang.tab.c"
    break;

  case 83: /* CONST: CHAR  */
#line 1213 "skylang.y"
     {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("CHAR");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print=1;
		}
}
#line 3447 "skylang.tab.c"
    break;

  case 84: /* CONST: STRING  */
#line 1222 "skylang.y"
       {
	if(passagem == 1){
			(yyval.tree) = add_tree_node("STRING");
			(yyval.tree) -> value_tac = (yyvsp[0].str);
			(yyval.tree) -> value = (yyvsp[0].str);
			(yyval.tree) -> flag_print=1;
		}
}
#line 3460 "skylang.tab.c"
    break;


#line 3464 "skylang.tab.c"

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

#line 1233 "skylang.y"


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
	//print_tac_tree(tree);
	printa_linha_tac(tac_completo,elt);
	cria_arquivo_tac(tac_completo,elt);
    yylex_destroy();
	free_tree(tree);
	//free_TS(hashed_symbol_table);
    return 0;
}
