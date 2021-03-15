%define parse.error verbose
%debug
%locations

%{

#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"
extern int yylex();
extern void yyerror(char const* msg)
extern int yylex_destroy(void);

%}

%union 
{
	char type;
	char id;
};

%token<type>TYPE
%token<id>ID
%token RETURN IF ELSE WHILE WRITE WRITELN READ EXISTS ADD REMOVE FOR FORALL IN

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
	TYPE ID
;

func_declaration:
	TYPE ID '('params')' codeBlock
;

params:
	params_list
;
params_list:
	params_list
	| param
;
param:
	TYPE ID
;
codeBlock:
	statements returns
;
returns:
	RETURN exp;
;
statements:
	statements
	| statement
;
statement:
	if_statement
	|while_statement
	|for_statement
	|declaration_statement
	|for_all_statement
	|exists_statement
	|add_statement
	|remove_statement
;
declaration_statement:
	variable_declaration
;
while_statement:
	WHILE '('exp')'codeBlock
;
if_statement:
	IF '('exp')' codeBlock
	| IF '('exp')' codeBlock ELSE codeBlock
;
for_statement:
	FOR '('exp')' codeBlock
;
for_all_statement:
	FORALL '('exp')' codeBlock
	| FORALL '('exp')'	
;
exists_statement:
	EXISTS '('exp')' codeBlock
	| EXISTS '('exp')'
;
add_statement:
	ADD '('exp')' codeBlock
	| ADD '('exp')'
;
remove_statement:
	REMOVE '('exp')' codeBlock
	| REMOVE '('exp')'
;
exp:
	setExp
	|opExp
	|relExp
;
setExp:
	ID IN ID
	| WRITELN IN ID
	| WRITE IN ID
;
opExp:
	ID
	|ID '=' exp
	|ID '*' ID
	|ID '+' ID
	|ID '-' ID
	|ID '/' ID
;
relExp:
	ID rel ID
	| ID rel exp
;
rel:
	'>'
	| '<'
	| '!='
	| '=='
	| '&&'
	| '<='
	| '>='
;
%%

void yyerror(char const* msg){
	printf("Erro sintatico: %s",msg)
}