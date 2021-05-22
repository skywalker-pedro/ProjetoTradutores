%define parse.error verbose
%debug
%define lr.type canonical-lr
%{

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

%}

%union 
{
	char *str;
	struct node* tree;
};

%token <str> TYPE CLE CLT CNE CGT AND CEQ CGE 
%token <str> ID INTEGER FLOAT CHAR STRING EMPTY
%token RETURN IF ELSE WHILE WRITE WRITELN READ EXISTS ADD REMOVE FOR FORALL IN IS_IN IS_SET OR 
%token NEGATION EQUALS
%token APOST
%token CHAVES_INI CHAVES_FIM PARENTESES_INI PARENTESES_FIM SEMICOLON COLON

%left PLUS MINUS MULT DIV

%type<tree> programa  declarationList declaration variable_declaration func_declaration params params_list param codeBlock assignmentExp statement_list
%type<tree> statement callFuncStatement call_params call_params_list call_param inputStatement outPutStatement forAllStatement //forRel
%type<tree> OP ASSIGN ifStatement exp setExp terms_set aritSetExp relExp rel terminal aritExp forStatement CONST//forExp expTerminal

%nonassoc THEN
%nonassoc ELSE

%%  

/*rule section*/

programa:
	declarationList {
		//printf("\nESCOPO ATUAL: %s\n",escopoAtual);
		if(passagem == 1){
			$$ = add_tree_node("programa");
			$$ -> leaf1 = $1;
			tree = $$;
		}
	}
;

declarationList: 
	declarationList declaration {
		if(passagem == 1){
			$$ = add_tree_node("declarationList");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $2;
		}
	}
	| declaration {
		if(passagem == 1){
			$$ = add_tree_node("declarationList");
			$$ -> leaf1 = $1;
		}
	}

;
declaration:
	variable_declaration{
		if(passagem == 1){
			$$ = add_tree_node("declaration");
			$$ -> leaf1 = $1;
		}
	}
	| func_declaration{
		if(passagem == 1){
			$$ = add_tree_node("declaration");
			$$ -> leaf1 = $1;
		}
	}
;

variable_declaration:
	TYPE ID SEMICOLON { 
						if(passagem == 1){
							
							existe_simbolo = searchSymbol($2);
							if(existe_simbolo == 1){
								escopo_correto = searchScope($2,escopoAtual);
								if(escopo_correto == 1){
									flag_redeclaracao_variavel =1;
									printf("\n--> ERRO SEMANTICO: redeclaracao da VARIAVEL -> %s <- na linha %d",$2,num_linha_1-1);
								}
							}
 							insert_symbol(symbol_ID, $2,"VARIAVEL",$1, escopoAtual,registrador_atual);
							registrador_atual = registrador_atual +1;
							symbol_ID = symbol_ID +1;
							//printf("\nAQUI %s\n",$2);
							$$ = add_tree_node("variable_declaration");
				
						}

	}
	|error {
		if(passagem == 1){
			//erro_count = erro_count +1;
			$$ = add_tree_node("Erro Sintatico");
			yyerror(yymsg);
		}
	}

;

func_declaration:
	TYPE ID PARENTESES_INI {escopoAtual = $2;
							if(passagem == 1){
								existe_simbolo = searchSymbol($2);
								if(existe_simbolo == 1){
									printf("\n--> ERRO SEMANTICO: redeclaracao da FUNCAO -> %s <- na linha %d",$2,num_linha_1);
									flag_redeclaracao_funcao = 1;
								}
								snprintf(char_reg,999,"%s:",$2);
								adiciona_linha_tac(tac_completo,strdup(char_reg));
								tipo_funcao_atual = $1;
								
							}
							} params PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM { 
																					if(passagem == 1){
											
																						insert_symbol(symbol_ID, $2,"FUNCAO",$1,escopoAtual,-1);
																						//registrador_atual = registrador_atual +1;
																						symbol_ID = symbol_ID +1 ;																	
																						$$ = add_tree_node("func_declaration");																		
																						$$ -> leaf1 = $5;
																						$$ -> leaf2 = $8;
																						$$ -> value = $2;
																						$$ -> type = translate_type($1);
																						$$ -> flag_print =1;
																						snprintf(codigo_tac,1100,"%s:",$2);
																						$$->linha_tac = strdup(codigo_tac);
																						
																	
																					}
																					if(passagem ==2 ){
																						aux = strcmp($2,"main");
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
;

params:
	params_list { 
				if(passagem == 1){
					$$ = add_tree_node("params");
		 			$$ -> leaf1 = $1;
				}
	}
;
params_list:
	param COLON params_list {
							if(passagem == 1){ 
								$$ = add_tree_node("params_list");
		 						$$ -> leaf1 = $1;
							  	$$ -> leaf2 = $3;
							}
	}
	|param { 
			if(passagem == 1){
				$$ = add_tree_node("params_list");
		 	 	$$ -> leaf1 = $1;
			}
	}
	|{ 
		if(passagem == 1){
			$$ = add_tree_node("Vazio");
		}
	}
	/*| error {
		if(passagem == 1){
			erro_count = erro_count +1;
			add_tree_node("Erro Sintatico");
			yyerror(yymsg);
		}
	}*/
;
param:
	TYPE ID { 
				if(passagem == 1){
				
					insert_symbol(symbol_ID, $2,"PARAMETRO_FUNCAO",$1,escopoAtual,-1);
					//registrador_atual = registrador_atual +1;
		    		symbol_ID = symbol_ID +1;
			 		$$ = add_tree_node("param");
				}
	}
;
codeBlock:
	statement_list{
		if(passagem == 1){
			$$ = add_tree_node("CodeBlock");
			$$ -> leaf1 = $1;
		}
	}

	/*| error {
		if(passagem == 1){
			erro_count = erro_count +1;
			add_tree_node("Erro Sintatico");
			yyerror(yymsg);
		}
	}*/
;
statement_list:
	statement_list statement {
			$$ = add_tree_node("Statement_list");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $2;
		}
	| {	
		if(passagem == 1){
			$$ = add_tree_node("Statement_list VAZIO");
		}
		 
	}
;

statement:
	
	variable_declaration {
		if(passagem == 1){
			$$ = add_tree_node("statement");
			$$ -> leaf1 = $1;
		}
	 }
	
	|exp SEMICOLON {
		if(passagem == 1){
			$$ = add_tree_node("statement");
			$$ -> leaf1 = $1;
			$$ -> type = $1 -> type;
		}
	 }
	|ifStatement {
		if(passagem == 1){
			$$ = add_tree_node("statement");
			$$ -> leaf1 = $1;
		}
	 }
	|forAllStatement {
		if(passagem == 1){
			$$ = add_tree_node("statement");
			$$ -> leaf1 = $1;
		}
	 }
	|outPutStatement SEMICOLON {
		if(passagem == 1){
			$$ = add_tree_node("statement");
			$$ -> leaf1 = $1;
		}
	 }
	|inputStatement SEMICOLON {
		if(passagem == 1){
			$$ = add_tree_node("statement");
			$$ -> leaf1 = $1;
		}
	 }
	|callFuncStatement SEMICOLON {
		if(passagem == 1){
			$$ = add_tree_node("statement");
			$$ -> leaf1 = $1;
		}
	 }

    |RETURN exp SEMICOLON {
		if(passagem == 1){
			$$ = add_tree_node("RETURN");
			$$ -> leaf1 = $2;
			$$ -> type = $2 -> type;
			$$ -> flag_print = 1;
			if($$ -> type != translate_type(tipo_funcao_atual))
				printf("\n--> ERRO SEMANTICO: Tipo do retorno da funcao -> %s <- incorreto na linha %d",escopoAtual,num_linha_1);
		}
	 }

	|forStatement {
		if(passagem == 1){
			$$ = add_tree_node("forStatement");
			$$ -> leaf1 = $1;
		}
	}

;

forStatement:
	FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM{
			if(passagem == 1){
				$$ = add_tree_node("ForStatement");
				$$ -> leaf1 = $3;
				$$ -> leaf2 = $5;
				$$ -> leaf3 = $7;
				$$ -> leaf4 = $10;
			}
	}
| FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM statement{
			if(passagem == 1){
				$$ = add_tree_node("ForStatement");
				$$ -> leaf1 = $3;
				$$ -> leaf2 = $5;
				$$ -> leaf3 = $7;
				$$ -> leaf4 = $9;
			}
	}
;


callFuncStatement:

	ID PARENTESES_INI call_params PARENTESES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("CallFunStatement");
			$$ -> leaf1 = $3;
		}

		if(passagem == 2){
			existe_simbolo = searchSymbol($1);
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Funcao nao declarada\n", num_linha,posicao_linha);
			}
		}

	}

;

call_params:
	call_params_list{
		if(passagem == 1){
			$$ = add_tree_node("CallParams");
			$$ -> leaf1 = $1;
		}
	}
;
call_params_list:
	 call_param COLON call_params_list{
		if(passagem == 1){ 
			$$ = add_tree_node("call_params_list");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $3;
		}
	}
	|call_param {
		if(passagem == 1){
			$$ = add_tree_node("call_params_list");
			$$ -> leaf1 = $1;
		}

	}
	|{
		if(passagem == 1){
			$$ = add_tree_node("Vazio");
		}
	 }
;
call_param:
	terminal {
		if(passagem == 1){
			$$ = add_tree_node("call_param terminal");
			$$ -> leaf1 = $1;
		}

		if(passagem == 2){
			
		}
	}
;

inputStatement:

	READ PARENTESES_INI ID PARENTESES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("read ID");	 
			$$ -> flag_print = 1;
			//$$ -> leaf1 = $3;
		}
	}

;

outPutStatement:
	WRITE PARENTESES_INI CONST PARENTESES_FIM  {
		if(passagem == 1){
			$$ = add_tree_node("write");
			$$ -> flag_print = 1;
			$$ -> leaf1 = $3;
			//$$ -> leaf1 = $3;
		}
	 }


	|WRITE PARENTESES_INI exp PARENTESES_FIM  {
		if(passagem == 1){
			$$ = add_tree_node("write");
			$$ -> flag_print = 1;
			$$ -> leaf1 = $3;
			snprintf(codigo_tac,1100,"print %s", $3 -> value_tac);
			$$ -> linha_tac = strdup(codigo_tac);
			adiciona_linha_tac(tac_completo,$$ -> linha_tac);
			//$$ -> leaf1 = $3;
		}
	 }
	|WRITELN PARENTESES_INI CONST PARENTESES_FIM  {
		if(passagem == 1){
			$$ = add_tree_node("writeln");
			$$ -> leaf1 = $3;
			$$ -> flag_print = 1;
			//$$ -> leaf1 = $3;
		}
	 }


	 |WRITELN PARENTESES_INI exp PARENTESES_FIM  {
		if(passagem == 1){
			$$ = add_tree_node("writeln");
			$$ -> flag_print = 1;
			$$ -> leaf1 = $3;
			snprintf(codigo_tac,1100,"println %s", $3 -> value_tac);
			$$ -> linha_tac = strdup(codigo_tac);
			adiciona_linha_tac(tac_completo,$$ -> linha_tac);
			//$$ -> leaf1 = $3;
		}
	 }
;

forAllStatement:
	
	FORALL PARENTESES_INI ID IN ID PARENTESES_FIM statement {
		if(passagem == 1){
			$$ = add_tree_node("forAllStatement");
			$$ -> leaf1 = $7;
		}
		if(passagem == 2){
			existe_simbolo = searchSymbol($3);
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope($3,escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
			existe_simbolo = searchSymbol($5);
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope($3,escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
		}
	 }

	| FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM{
		if(passagem == 1){
			$$ = add_tree_node("forAllStatement");
			$$ -> leaf1 = $8;
		}
		if(passagem == 2){
			existe_simbolo = searchSymbol($3);
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope($3,escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
			existe_simbolo = searchSymbol($5);
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope($3,escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
		}
	 }
;

ifStatement:

	IF PARENTESES_INI exp PARENTESES_FIM statement %prec THEN {
		if(passagem == 1){
			$$ = add_tree_node("ifStatement");
			$$ -> leaf1 = $3;
			$$ -> leaf2 = $5;
			$$ -> flag_print = 1;
		}
	 }
	|IF PARENTESES_INI exp PARENTESES_FIM statement ELSE statement {
		if(passagem == 1){
			$$ = add_tree_node("ifElseStatement");
			$$ -> leaf1 = $3;
			$$ -> leaf2 = $5;
			$$ -> leaf3 = $7;
			$$ -> flag_print = 1;
		}
	 }

	|IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM %prec THEN {
		if(passagem == 1){
			$$ = add_tree_node("ifStatement");
			$$ -> leaf1 = $3;
			$$ -> leaf2 = $6;
			$$ -> flag_print = 1;
		}
	 }
	|IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI statement_list CHAVES_FIM ELSE CHAVES_INI statement_list CHAVES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("ifElseStatement");
			$$ -> leaf1 = $3;
			$$ -> leaf2 = $6;
			$$ -> leaf3 = $10;
			$$ -> flag_print = 1;
		}
	 }
;

exp:


	NEGATION exp  {
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $2;
			$$ -> type = $2 -> type;
		}
	 }

	|setExp  {
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $1;
			$$ -> type = $1 -> type;
		}
	 }
	|aritExp {
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $1;
			$$ -> type = $1 -> type;
			$$ -> value_tac = $1 -> result;
		}
	 }
	|relExp {
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $1;
			$$ -> type = $1 -> type;
		}
	 }
	|terminal {
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $1;
			$$ -> type = $1 -> type;
			$$ -> value_tac = $1 -> value_tac;
		}
	 }

	|assignmentExp{
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $1;
			$$ -> type = $1 -> type;
		}
	}
;

assignmentExp:
	terminal ASSIGN exp {
		if(passagem == 1){
			$$ = add_tree_node("assigmentExp");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $2;
			$$ -> leaf3 = $3;
			if (check_set_type($1->type,$3->type)==0){
				$$ -> type = $1 -> type;
				$$ -> conversao = check_conversao($1->type,$3->type);
			}
			snprintf(codigo_tac,1100,"mov %s, %s", $1->value_tac,$3->value_tac);
			$$ -> linha_tac = strdup(codigo_tac);
			adiciona_linha_tac(tac_completo,$$->linha_tac);
		}
	}
	|terminal ASSIGN CONST {
		if(passagem == 1){
			$$ = add_tree_node("assigmentExp");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $2;
			$$ -> leaf3 = $3;
			if ($1->type != 3)
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: ID com tipo incompativel com constante EMPTY\n", num_linha_1,posicao_linha_1);
		}
	}
;
	 
setExp:
	ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("setExp");
			$$ -> leaf1 = $3;
			$$ -> leaf2 = $5;
		}
	}
	| REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("setExp");
			$$ -> leaf1 = $3;
			$$ -> leaf2 = $5;
		}
	}
	| EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("setExp");
			$$ -> leaf1 = $3;
			$$ -> leaf2 = $5;
		}
	}
;

terms_set:
	aritSetExp {
		if(passagem == 1){
			$$ = add_tree_node("terms_set");
			$$ -> leaf1 = $1;
		}
	}
;

aritSetExp:
	ID {
		if(passagem == 1){
			$$ = add_tree_node("terminal ID");
		}
		 
		if(passagem == 2){
			existe_simbolo = searchSymbol($1);
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
			}else{
				escopo_correto = searchScope($1,escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
		}

	}
	|FLOAT {
		if(passagem == 1){
			$$ = add_tree_node("terminal FLOAT");
		}
		 
	 }
	|INTEGER {
		if(passagem == 1){
			$$ = add_tree_node("terminal INTEGER");
		}
		 
	 }
	|PARENTESES_INI EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM PARENTESES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("aritSetExp"); 
			$$ -> leaf1 = $4;
			$$ -> leaf2 = $6;
		}
	}

;

/*
Politica de conversao de tipo
0 = não teve conversao
1 = intToFLoat
2 = floatToInt
3 = elemToInt
4 = IntToElem
5 = elemToFloat
6 = floatToElem
*/

aritExp:
	terminal OP exp {
		if(passagem == 1){
			$$ = add_tree_node("aritExp");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $2;
			$$ -> leaf3 = $3;
			//$$ -> value_tac = char_reg;
			if (check_set_type($1->type,$3->type)==0){
				$$ -> type = $1 -> type;
				$$ -> conversao = check_conversao($1->type,$3->type);
			}
			snprintf(codigo_tac,1100,"%s $%d, %s, %s",$2 -> value_tac, registrador_atual, $1 -> value_tac,$3 -> value_tac);
			//printf("\n%s",codigo_tac);
			snprintf(char_reg,999,"$%d",registrador_atual);
			$$ -> result = strdup(char_reg);
			registrador_atual ++;
			$$ -> linha_tac = strdup(codigo_tac);
			$$ -> printa_tac = 1;
			adiciona_linha_tac(tac_completo,$$ -> linha_tac);
		} 
	 }
;
relExp:
	terminal rel exp {
		if(passagem == 1){
			$$ = add_tree_node("relExp");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $2;
			$$ -> leaf3 = $3;
			check_set_type($1->type,$3->type);
		}
	 }
;

rel:
	CGE {
		if(passagem == 1){
			$$ = add_tree_node("   >=");
			$$ -> value_tac = $1;
			$$ -> value = $1;
			$$ -> flag_print = 1;
		}
	 }
	| CGT {
		if(passagem == 1){
			$$ = add_tree_node("   >");
			$$ -> value_tac = $1;
			$$ -> value = $1;
			$$ -> flag_print = 1;
		}
	 }
	| CNE {
		if(passagem == 1){
			$$ = add_tree_node("   !=");
			$$ -> value_tac = $1;
			$$ -> value = $1;
			$$ -> flag_print = 1;
		}
	 }
	| CLT {
		if(passagem == 1){
			$$ = add_tree_node("   <");
			$$ -> value_tac = $1;
			$$ -> value = $1;
			$$ -> flag_print = 1;
		}
	 }
	| AND {
		if(passagem == 1){
			$$ = add_tree_node("   &&");
			$$ -> value_tac = $1;
			$$ -> value = $1;
			$$ -> flag_print = 1;
		}
	 }
	| CLE {
		if(passagem == 1){
			$$ = add_tree_node("<=");
			$$ -> value_tac = $1;
			$$ -> value = $1;
			$$ -> flag_print = 1;
		}
	 }
	| CEQ {
		if(passagem == 1){
			$$ = add_tree_node("==");
			$$ -> value_tac = $1;
			$$ -> value = $1;
			$$ -> flag_print = 1;
		}
	}

;


/*
TYPES:
0 = nao definido ainda
1 = int
2 = float
3 = set
4 = elem 
*/

terminal:
	ID {
		if(passagem == 1){
			int_reg  = get_id_reg($1,escopoAtual);
			snprintf(char_reg, 999, "$%d",int_reg );
			$$ = add_tree_node("terminal ID");
			$$ -> flag_print = 1;
			$$ -> type = translate_type(searchVarType($1,escopoAtual));
			$$ -> value_tac = strdup(char_reg);
			$$ -> value = $1;
		}
		if(passagem == 2){
			existe_simbolo = searchSymbol($1);
			if(existe_simbolo != 1){
				printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel nao declarada\n", num_linha,posicao_linha);
				
			}else{
				escopo_correto = searchScope($1,escopoAtual);
				if(escopo_correto!=1){
					printf("\n--> ERRO SEMANTICO LINHA %d, COLUNA %d: Variavel utilizada no escopo errado\n", num_linha,posicao_linha);
				}
			}
		}
		 
	}
	|FLOAT {
		if(passagem == 1){
			$$ = add_tree_node("terminal CONST");
			$$ -> type = 2;
			$$ -> flag_print = 1;
			$$ -> value = $1;
			$$ -> value_tac = $1;
		}
		 
	 }
	|INTEGER {
		if(passagem == 1){
			$$ = add_tree_node("terminal CONST");
			$$ -> type = 1;
			$$ -> flag_print = 1;
			$$ -> value = $1;
			$$ -> value_tac = $1;
		}
		 
	 }

	| PARENTESES_INI exp PARENTESES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("terminal EXP");
			$$->leaf1 =$2;
			$$ -> type = $2 -> type;
			$$ -> value_tac = $2 -> value_tac;
		}
	}

;

ASSIGN:

EQUALS {
		if(passagem == 1){
			$$ = add_tree_node(" =");
			$$ -> flag_print = 1;
		}
	 }

;

OP:
	MULT {
		if(passagem == 1){
			$$ = add_tree_node(" *");
			$$ -> flag_print = 1;
			$$ -> value_tac = "mul";
		}
	 }
	| PLUS {
		if(passagem == 1){
			$$ = add_tree_node(" +");
			$$ -> flag_print = 1;
			$$ -> value_tac = "add";
		}
	 }
	| MINUS {
		if(passagem == 1){
			$$ = add_tree_node(" -");
			$$ -> flag_print = 1;
			$$ -> value_tac = "sub";
		}
	 }
	| DIV {
		if(passagem == 1){
			$$ = add_tree_node(" /");
			$$ -> flag_print = 1;
			$$ -> value_tac = "div";
		}
	 }
;

CONST:

EMPTY{
	if(passagem == 1){
			$$ = add_tree_node("EMPTY");
			$$ -> type = 3;
			$$ -> value = $1;
		}
}

|CHAR{
	if(passagem == 1){
			$$ = add_tree_node("CHAR");
			$$ -> value_tac = $1;
			$$ -> value = $1;
			$$ -> flag_print=1;
		}
}

|STRING{
	if(passagem == 1){
			$$ = add_tree_node("STRING");
			$$ -> value_tac = $1;
			$$ -> value = $1;
			$$ -> flag_print=1;
		}
}


;
%%

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