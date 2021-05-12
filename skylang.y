%define parse.error verbose
%debug
%define lr.type canonical-lr
%{

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
int existe_main = 0;
char * redeclaracao_funcao;
int flag_redeclaracao_funcao;
int registrador_atual = 0;
//int erro_count = 0;
int aux=1;
int escopo_correto;
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



%}

%union 
{
	char *str;
	struct node* tree;
};

%token<str>TYPE
%token<str>ID
%token RETURN IF ELSE WHILE WRITE WRITELN READ EXISTS ADD REMOVE FOR FORALL IN IS_IN IS_SET OR 
%token <tree> CLE CLT CNE CGT AND CEQ CGE INTEGER FLOAT
%token CHAR STRING NEGATION EQUALS
%token APOST
%token CHAVES_INI CHAVES_FIM PARENTESES_INI PARENTESES_FIM EMPTY SEMICOLON COLON

%left PLUS MINUS MULT DIV

%type<tree> programa  declarationList declaration variable_declaration func_declaration params params_list param codeBlock assignmentExp
%type<tree> statement callFuncStatement call_params call_params_list call_param inputStatement outPutStatement forAllStatement //forRel
%type<tree> ifStatement exp setExp terms_set aritSetExp relExp rel terminal aritExp forStatement //forExp expTerminal
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

	/*| error {
		if(passagem == 1){
			erro_count = erro_count +1;
			$$ = add_tree_node("Erro Sintatico");
			yyerror(yymsg);
		}
	}*/
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
									redeclaracao_funcao = "\n--> ERRO SEMANTICO: redeclaracao de funcao\n";
									flag_redeclaracao_funcao = 1;
								}
							}
							} params PARENTESES_FIM CHAVES_INI codeBlock  CHAVES_FIM { 
																					if(passagem == 1){
											
																						insert_symbol(symbol_ID, $2,"FUNCAO",$1,escopoAtual,-1);
																						//registrador_atual = registrador_atual +1;
																						symbol_ID = symbol_ID +1 ;																	
																						$$ = add_tree_node("func_declaration");																		
																						$$ -> leaf1 = $5;
																						$$ -> leaf2 = $8;
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
	codeBlock statement{
		if(passagem == 1){
			$$ = add_tree_node("codeBlock");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $2;
		}
	}
	| {	
		if(passagem == 1){
			$$ = add_tree_node("codeBlock VAZIO");
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
			$$ = add_tree_node("RETURN statement");
			$$ -> leaf1 = $2;
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
		FOR PARENTESES_INI exp SEMICOLON exp SEMICOLON exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM{
			if(passagem == 1){
				$$ = add_tree_node("ForStatement");
				$$ -> leaf1 = $3;
				$$ -> leaf2 = $5;
				$$ -> leaf3 = $7;
				$$ -> leaf4 = $10;
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
	}
;

inputStatement:

	READ PARENTESES_INI STRING PARENTESES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("inputStatement");	 
			//$$ -> leaf1 = $3;
		}
	}

;

outPutStatement:
	WRITE PARENTESES_INI STRING PARENTESES_FIM  {
		if(passagem == 1){
			$$ = add_tree_node("outPutStatement");
			//$$ -> leaf1 = $3;
		}
	 }
	|WRITELN PARENTESES_INI STRING PARENTESES_FIM  {
		if(passagem == 1){
			$$ = add_tree_node("outPutStatement");
			//$$ -> leaf1 = $3;
		}
	 }
;

forAllStatement:
	
	FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM {
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

	IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  {
		if(passagem == 1){
			$$ = add_tree_node("ifStatement");
			$$ -> leaf1 = $3;
			$$ -> leaf2 = $6;
		}
	 }
	|IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM ELSE CHAVES_INI codeBlock CHAVES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("ifElseStatement");
			$$ -> leaf1 = $3;
			$$ -> leaf2 = $6;
			$$ -> leaf3 = $10;
		}
	 }
;

exp:
	setExp  {
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $1;
		}
	 }
	|aritExp {
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $1;
		}
	 }
	|relExp {
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $1;
		}
	 }
	|terminal {
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $1;
		}
	 }

	|assignmentExp{
		if(passagem == 1){
			$$ = add_tree_node("exp");
			$$ -> leaf1 = $1;
		}
	}
;

assignmentExp:
	terminal EQUALS exp {
		if(passagem == 1){
			$$ = add_tree_node("assigmentExp");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $3;
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

aritExp:
	terminal MULT exp {
		if(passagem == 1){
			$$ = add_tree_node("aritExp");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $3;
		}
	 }
	|terminal PLUS exp {
		if(passagem == 1){
			$$ = add_tree_node("aritExp");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $3;
		}
	 }
	|terminal MINUS exp {
		if(passagem == 1){
			$$ = add_tree_node("aritExp");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $3;
		}
	 }
	|terminal DIV exp {
		if(passagem == 1){
			$$ = add_tree_node("aritExp");
			$$ -> leaf1 = $1;
			$$ -> leaf2 = $3;
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
		}
	 }
;

rel:
	CGE {
		if(passagem == 1){
			$$ = add_tree_node("rel CGE");
		}
	 }
	| CGT {
		if(passagem == 1){
			$$ = add_tree_node("rel");
		}
	 }
	| CNE {
		if(passagem == 1){
			$$ = add_tree_node("rel");
		}
	 }
	| CLT {
		if(passagem == 1){
			$$ = add_tree_node("rel");
		}
	 }
	| AND {
		if(passagem == 1){
			$$ = add_tree_node("rel");
		}
	 }
	| CLE {
		if(passagem == 1){
			$$ = add_tree_node("rel");
		}
	 }
	| CEQ {
		if(passagem == 1){
			$$ = add_tree_node("rel CEQ");
		}
	}

;

terminal:
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

	| PARENTESES_INI exp PARENTESES_FIM {
		if(passagem == 1){
			$$ = add_tree_node("terminal EXP");
			$$->leaf1 =$2;
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
