%option noinput
%option nounput
%option noyywrap
%{

#include <stdlib.h>
#include <stdio.h>
#include "skylang.tab.h"

int num_linha = 1;
int posicao_linha = 0;

void LexicalError(){
	printf("\nERROR: Token %s nao reconhecido na linha %d\n",yytext,num_linha);
}

%}

string \"(\\.|[^"\\])*\"
char (\'([^(\"\')])+\')
new_line  \n
tabulacao	\t
espaco " "
letter [a-zA-Z]
digit [0-9]
integer -?{digit}+
float_ -?{digit}*[.]{digit}+
id   {letter}+({letter}|{digit}|_|-)*

sub  "-"
mult  "*"
plus "+"
remove "remove"
exists "exists"
add "add"
div  "/"
is_in "is_in"
is_set "is_set"
in "in"
type "int"|"float"|"set"|"elem"
equals "="
or "||"
and "&&"
negation "!"


chaves_ini "{"
chaves_fim "}"
parenteses_ini "("
parenteses_fim ")"	
semicolon ";"
colon ","

return "return"
if "if"
while "while"
else "else"
for "for"
forall "forall"
write "write"
writeLn "writeln"
read	"read"

cle "<="
cgt ">"
ceq "=="
cne "!="
clt "<"
cge ">="

empty "EMPTY"


%%

{exists} {
		printf("Token valido exists: -> %s\n",yytext);
		posicao_linha += yyleng;
		yylval.str = (char *) strdup(yytext);
		return EXISTS;

}

{remove} {
		printf("Token valido remove: -> %s\n",yytext);
		posicao_linha += yyleng;
		yylval.str = (char *) strdup(yytext);
		return REMOVE;

}

{in} {

		printf("Token valido IN: -> %s\n",yytext);
		posicao_linha += yyleng;
		yylval.str = (char *) strdup(yytext);
		return IN;


}

{empty}	{

			printf("Token valido EMPTY: -> %s\n",yytext);
			posicao_linha += yyleng;
			yylval.str = (char *) strdup(yytext);
			return EMPTY;

}

{negation}		{
    		printf("Token valido negation: -> %s\n", yytext);
    		posicao_linha += yyleng;
			yylval.str = (char *) strdup(yytext);
			return NEGATION;
   
}

"]"		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
   
}

"["		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
   
}

"&"		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
   
}

{colon}		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
			return COLON;
   
}

"\""		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
   
}

"\\"		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
   
}

{read}	{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
			return READ;
   
}

{writeLn}	{
    		 printf("Token valido: -> %s\n", yytext);
			yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return WRITELN;

   
}

{write}	{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
			return WRITE;
}

{add}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return ADD;
}

{espaco}	{
    		posicao_linha += yyleng;
   
}

{forall}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return FORALL;
}

{plus}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return '+';
}

{cgt}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return CGT;
   
}


{for}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return FOR;
   
}

{else}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return ELSE;
   
}

{if}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
   			posicao_linha += yyleng;
			return IF;
			
}

{type}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
   			posicao_linha += yyleng;
			return TYPE;
}


{is_in}	{
    		printf("Token valido: -> %s\n", yytext);
			yylval.str = (char *) strdup(yytext);
   			posicao_linha += yyleng;
			return IS_IN;
}

{is_set}	{
    		printf("Token valido: -> %s\n", yytext);
			yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return IS_SET;
   
   
}


{return}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
   			posicao_linha += yyleng;
			return RETURN;
}

{tabulacao}	{
    		 printf(" ");
			 posicao_linha += yyleng;
}	

{new_line}	{
    		num_linha += 1;
    		posicao_linha = 0;
   
}

{integer}	{
    		printf("Token valido INTEIRO: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return INTEGER;
}

{float_}	{
    		printf("Token valido FLOAT: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return FLOAT;
}

{id}	{
    		printf("Token valido ID: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return ID;
   
}

{char}	{
    		printf("Token valido CHAR: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return CHAR;
   
}

{string}	{
    		printf("Token valido STRING: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return STRING;
}


{sub}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return '-';
   
}


{div}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return '/';
   
   
}


{cge}	{
    		printf("Token valido eq or greater: -> %s\n", yytext);
			yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return CGE;
   
}

{ceq}	{
    		 printf("Token valido equals: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return CEQ;
   
}



{equals}	{
    		 printf("Token valido assign: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return EQUALS;
   
}

{or}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return OR;
   
}

{and}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return AND;
   
}


{cle}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return CLE;
   
}


{cne}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return CNE;
   
}

{clt}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return CLT;
   
}


{parenteses_ini}	{
    		 printf("Token valido parenteses ini: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return PARENTESES_INI;
   
}

{parenteses_fim}	{
    		 printf("Token valido parenteses fim: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return PARENTESES_FIM;
   
}

{chaves_ini}	{
    		 printf("Token valido chaves ini: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return CHAVES_INI;

   
}

{chaves_fim}	{
    		 printf("Token valido chaves fim: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return CHAVES_FIM;
   
}

{semicolon}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += yyleng;
			return SEMICOLON;
   
}

"_"	{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
   
}

"."	{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
			return '.';
   
}

":"		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
			return ':';

}

"%"		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;
   
}

"'"	{
    		 printf("Token valido apost: -> %s\n", yytext);
    		posicao_linha += yyleng;
			return APOST;
   
}


. { 
	posicao_linha += yyleng;
    LexicalError();
}


%%