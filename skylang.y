%define parse.error verbose
%debug
%define lr.type canonical-lr
%{

#include <stdio.h>
#include <stdlib.h>
#include "skylang.h"
#include "symbol_table.h"
extern int yylex();
extern void yyerror(const char* msg);
extern int yylex_destroy();
extern FILE *yyin;
extern Hash_table * hashed_symbol_table;
int symbol_ID = 0;

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
};

%token<str>TYPE
%token<str>ID
%token RETURN IF ELSE WHILE WRITE WRITELN READ EXISTS ADD REMOVE FOR FORALL IN IS_IN IS_SET OR 
%token CLE CLT CNE CGT AND CEQ CGE
%token LETTER STRING
%token DIGIT APOST
%token CHAVES_INI CHAVES_FIM PARENTESES_INI PARENTESES_FIM EMPTY SEMICOLON EQUALS COLON
%%

/*rule section*/

programa:
	declarationList
;

declarationList: 
	declarationList declaration 
	| declaration
;
declaration:
	variable_declaration
	| func_declaration
;

variable_declaration:
	TYPE ID SEMICOLON {insert_symbol(symbol_ID, $2,"VARIAVEL",$1 );
						symbol_ID ++;
						//printf("\nAQUI %s\n",$2);
						}
;

func_declaration:
	TYPE ID PARENTESES_INI params PARENTESES_FIM CHAVES_INI codeBlock  CHAVES_FIM {insert_symbol(symbol_ID, $2,"FUNCAO",$1 );
																					symbol_ID ++;
																					//printf("\nAQUI %s\n",$2);
																					}
;

params:
	params_list
;
params_list:
	 param COLON params_list
	|param
	|
;
param:
	TYPE ID
;
codeBlock:
	codeBlock statement
	|	
;

statement:
	
	variable_declaration
	|variable_assignment SEMICOLON
	|exp SEMICOLON
	|ifStatement
	|forAllStatement
	|outPutStatement SEMICOLON
	|inputStatement SEMICOLON
	|callFuncStatement SEMICOLON
	|RETURN exp SEMICOLON
	
;

callFuncStatement:

	ID PARENTESES_INI call_params PARENTESES_FIM 

;

call_params:
	call_params_list
;
call_params_list:
	 call_param COLON call_params_list
	|call_param
	|
;
call_param:
	terminal
;

inputStatement:

	READ PARENTESES_INI exp PARENTESES_FIM 

;


outPutStatement:
	WRITE PARENTESES_INI exp PARENTESES_FIM
	|WRITELN PARENTESES_INI exp PARENTESES_FIM
;

forAllStatement:
	
	FORALL PARENTESES_INI ID IN ID PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM

;

ifStatement:

	IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM
	|IF PARENTESES_INI exp PARENTESES_FIM CHAVES_INI codeBlock CHAVES_FIM ELSE CHAVES_INI codeBlock CHAVES_FIM

;

variable_assignment:
	ID EQUALS exp

;

exp:
	setExp
	|aritExp
	|relExp
	|terminal
;

setExp:
	ADD PARENTESES_INI terms_set IN terms_set PARENTESES_FIM
	| REMOVE PARENTESES_INI terms_set IN terms_set PARENTESES_FIM 
	| EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM 
;

terms_set:
	aritSetExp
;

aritSetExp:
	terminal
	|PARENTESES_INI EXISTS PARENTESES_INI terms_set IN terms_set PARENTESES_FIM PARENTESES_FIM

	
;

aritExp:
	terminal '*' exp
	|terminal '+' exp
	|terminal '-' exp
	|terminal '/' exp
;
relExp:
	terminal rel exp 
;

rel:
	CGE
	| CGT
	| CNE
	| CLT
	| AND
	| CLE
	| CEQ
;

terminal:
	ID
	|DIGIT
;

%%

extern void yyerror(const char* a) {
    printf("ERRO SINTATICO linha %d\n",num_linha);
	printf("-->%s\n",a);
}


int main(){
char fname[100];
    printf("\nDigite o nome do arquivo a ser analisado:\n-> ");
    scanf("%s",fname);
    yyin=fopen(fname,"r+");
    yyparse();
    //yylex();
	fclose(yyin);
	printf("\n---------> Fim da Analise Sintatica <----------");
	printf("\n---------> Tabela de Simbolos <---------\n");
	printTS();
	printf("\n");
    yylex_destroy();
    return 0;
}