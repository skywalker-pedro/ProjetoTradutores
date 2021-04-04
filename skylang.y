%define parse.error verbose
%debug
%define lr.type canonical-lr
%{

#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern void yyerror(const char* msg);
extern int yylex_destroy();
extern FILE *yyin;

%}

%union 
{
	char *type;
	char id;
};

%token<type>TYPE
%token<id>ID
%token RETURN IF ELSE WHILE WRITE WRITELN READ EXISTS ADD REMOVE FOR FORALL IN IS_IN IS_SET
%token CLE CLT CNE CGT AND CEQ CGE
%token LETTER
%token DIGIT
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
	 param ','	params_list
	|param
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
	statement','statements
	|statement
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
	| ID rel exp
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

%%

extern void yyerror(const char* a) {
    printf("ERRO SINTATICO\n");
}


int main(){
char fname[100];
    printf("\nDigite o nome do arquivo a ser analisado:\n-> ");
    scanf("%s",fname);
    yyin=fopen(fname,"r+");
    yyparse();
    fclose(yyin);
    yylex_destroy();
    return 0;
}