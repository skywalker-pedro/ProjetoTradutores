%define parse.error verbose
%debug
%define lr.type canonical-lr
%{

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
%token CHAR STRING NEGATION
%token APOST
%token CHAVES_INI CHAVES_FIM PARENTESES_INI PARENTESES_FIM EMPTY SEMICOLON EQUALS COLON
%type<tree> programa  declarationList declaration variable_declaration func_declaration params params_list param codeBlock
%type<tree> statement callFuncStatement call_params call_params_list call_param inputStatement outPutStatement forAllStatement
%type<tree> ifStatement variable_assignment exp setExp terms_set aritSetExp relExp rel terminal aritExp
%%  

/*rule section*/

programa:
	declarationList {
		$$ = add_tree_node("programa");
		$$ -> leaf1 = $1;
		tree = $$;
	}
;

declarationList: 
	declarationList declaration {
		$$ = add_tree_node("declarationList");
		$$ -> leaf1 = $1;
		$$ -> leaf2 = $2;
	}
	| declaration {
		$$ = add_tree_node("declarationList");
		$$ -> leaf1 = $1;
	}
;
declaration:
	variable_declaration{
		$$ = add_tree_node("declaration");
		$$ -> leaf1 = $1;
	}
	| func_declaration{
		$$ = add_tree_node("declaration");
		$$ -> leaf1 = $1;
	}
;

variable_declaration:
	TYPE ID SEMICOLON { insert_symbol(symbol_ID, $2,"VARIAVEL",$1 );
						symbol_ID = symbol_ID +1;
						//printf("\nAQUI %s\n",$2);
						$$ = add_tree_node("variable_declaration - Type ID");
						 
	}
;

func_declaration:
	TYPE ID PARENTESES_INI params PARENTESES_FIM CHAVES_INI codeBlock  CHAVES_FIM { insert_symbol(symbol_ID, $2,"FUNCAO",$1 );
																					symbol_ID = symbol_ID +1 ;																	
																					$$ = add_tree_node("func_declaration");																		
																					$$ -> leaf1 = $4;
																					$$ -> leaf2 = $7;
	}
;

params:
	params_list { $$ = add_tree_node("params");
		 		  $$ -> leaf1 = $1;
	}
;
params_list:
	param COLON params_list { $$ = add_tree_node("params_list_n");
		 					  $$ -> leaf1 = $1;
							  $$ -> leaf2 = $3;
	}
	|param { $$ = add_tree_node("params_lis_1");
		 	 $$ -> leaf1 = $1;
	}
	|{ $$ = add_tree_node("Vazio");
	}
;
param:
	TYPE ID { insert_symbol(symbol_ID, $2,"PARAMETRO_FUNCAO",$1 );
		      symbol_ID = symbol_ID +1;
			  $$ = add_tree_node("param - TYPE ID");
	}
;
codeBlock:
	codeBlock statement{
		$$ = add_tree_node("codeBlock");
		$$ -> leaf1 = $1;
		$$ -> leaf2 = $2;
	}
	| {
		$$ = add_tree_node("codeBlock VAZIO");
		 
	}
;

statement:
	
	variable_declaration {
		$$ = add_tree_node("statement");
		$$ -> leaf1 = $1;
	 }
	|variable_assignment SEMICOLON {
		$$ = add_tree_node("statement");
		$$ -> leaf1 = $1;
	 }
	|exp SEMICOLON {
		$$ = add_tree_node("statement");
		$$ -> leaf1 = $1;
	 }
	|ifStatement {
		$$ = add_tree_node("statement");
		$$ -> leaf1 = $1;
	 }
	|forAllStatement {
		$$ = add_tree_node("statement");
		$$ -> leaf1 = $1;
	 }
	|outPutStatement SEMICOLON {
		$$ = add_tree_node("statement");
		$$ -> leaf1 = $1;
	 }
	|inputStatement SEMICOLON {
		$$ = add_tree_node("statement");
		$$ -> leaf1 = $1;
	 }
	|callFuncStatement SEMICOLON {
		$$ = add_tree_node("statement");
		$$ -> leaf1 = $1;
	 }
	|RETURN exp SEMICOLON {
		$$ = add_tree_node("RETURN statement");
		$$ -> leaf1 = $2;

	 }
	
;

callFuncStatement:

	ID PARENTESES_INI call_params PARENTESES_FIM {
		$$ = add_tree_node("CallFunStatement");
		$$ -> leaf1 = $3;
	}

;

call_params:
	call_params_list{
		$$ = add_tree_node("CallParams");
		$$ -> leaf1 = $1;
	}
;
call_params_list:
	 call_param COLON call_params_list{
		$$ = add_tree_node("call_params_list");
		$$ -> leaf1 = $1;
		$$ -> leaf1 = $3;
	}
	|call_param {
		$$ = add_tree_node("call_params_list");
		$$ -> leaf1 = $1;
	}
	|{
		$$ = add_tree_node("Vazio");
	 }
;
call_param:
	terminal {
		$$ = add_tree_node("call_param");
		$$ -> leaf1 = $1;
	}
;

inputStatement:

	READ PARENTESES_INI STRING PARENTESES_FIM {
		$$ = add_tree_node("inputStatement");	 
		//$$ -> leaf1 = $3;
	}

;

outPutStatement:
	WRITE PARENTESES_INI STRING PARENTESES_FIM  {
		$$ = add_tree_node("outPutStatement");
		//$$ -> leaf1 = $3;
	 }
	|WRITELN PARENTESES_INI STRING PARENTESES_FIM  {
		$$ = add_tree_node("outPutStatement");
		//$$ -> leaf1 = $3;
	 }
;

forAllStatement:
	
	FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM {
		$$ = add_tree_node("forAllStatement");
		$$ -> leaf1 = $8;
	 }
;

ifStatement:

	IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM  {
		$$ = add_tree_node("ifStatement");
		$$ -> leaf1 = $3;
		$$ -> leaf2 = $6;
	 }
	|IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM ELSE CHAVES_INI codeBlock CHAVES_FIM {
		$$ = add_tree_node("ifElseStatement");
		$$ -> leaf1 = $3;
		$$ -> leaf2 = $6;
		$$ -> leaf3 = $10;
	 }
;

variable_assignment:
	ID EQUALS exp {
		$$ = add_tree_node("var_assign");
		$$ -> leaf1 = $3;
	 }
;

exp:
	setExp  {
		$$ = add_tree_node("exp");
		$$ -> leaf1 = $1;
	 }
	|aritExp {
		$$ = add_tree_node("exp");
		$$ -> leaf1 = $1;
	 }
	|relExp {
		$$ = add_tree_node("exp");
		$$ -> leaf1 = $1;
	 }
	|terminal {
		$$ = add_tree_node("exp");
		$$ -> leaf1 = $1;
	 }
;

setExp:
	ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM {
		$$ = add_tree_node("setExp");
		$$ -> leaf1 = $3;
		$$ -> leaf2 = $5;
	}
	| REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM {
		$$ = add_tree_node("setExp");
		$$ -> leaf1 = $3;
		$$ -> leaf2 = $5;
	}
	| EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM {
		$$ = add_tree_node("setExp");
		$$ -> leaf1 = $3;
		$$ -> leaf2 = $5;
	}
;

terms_set:
	aritSetExp {
		$$ = add_tree_node("terms_set");
		$$ -> leaf1 = $1;
	}
;

aritSetExp:
	terminal {
		$$ = add_tree_node("aritSetExp");
		$$ -> leaf1 = $1;
	}
	|PARENTESES_INI EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM PARENTESES_FIM {
		$$ = add_tree_node("aritSetExp");
		 
		$$ -> leaf1 = $4;
		$$ -> leaf2 = $6;
	}

;

aritExp:
	terminal '*' exp {
		$$ = add_tree_node("aritExp");
		 
		$$ -> leaf1 = $1;
		$$ -> leaf2 = $3;
	 }
	|terminal '+' exp {
		$$ = add_tree_node("aritExp");
		 
		$$ -> leaf1 = $1;
		$$ -> leaf2 = $3;
	 }
	|terminal '-' exp {
		$$ = add_tree_node("aritExp");
		$$ -> leaf1 = $1;
		$$ -> leaf2 = $3;
	 }
	|terminal '/' exp {
		$$ = add_tree_node("aritExp");
		$$ -> leaf1 = $1;
		$$ -> leaf2 = $3;
	 }
;
relExp:
	terminal rel exp {
		$$ = add_tree_node("relExp");
		$$ -> leaf1 = $1;
		$$ -> leaf2 = $2;
		$$ -> leaf3 = $3;
	 }
;

rel:
	CGE {
		$$ = add_tree_node("rel CGE");
		$$ -> leaf1 = $1;
	 }
	| CGT {
		$$ = add_tree_node("rel");
		$$ -> leaf1 = $1;
	 }
	| CNE {
		$$ = add_tree_node("rel");
		$$ -> leaf1 = $1;
	 }
	| CLT {
		$$ = add_tree_node("rel");
		$$ -> leaf1 = $1;
	 }
	| AND {
		$$ = add_tree_node("rel");
		$$ -> leaf1 = $1;
	 }
	| CLE {
		$$ = add_tree_node("rel");
		$$ -> leaf1 = $1;
	 }
	| CEQ {
		$$ = add_tree_node("rel");
		$$ -> leaf1 = $1;
	 }
;

terminal:
	ID {
		$$ = add_tree_node("terminal ID");
		 
	 }
	|FLOAT {
		$$ = add_tree_node("terminal FLOAT");
		 
	 }
	|INTEGER {
		$$ = add_tree_node("terminal INTEGER");
		 
	 }
;

%%

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
	//yyin=fopen(fname,"r+");
	//yyparse();
	//fclose(yyin);
    yylex_destroy();
    return 0;
}