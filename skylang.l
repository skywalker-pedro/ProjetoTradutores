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
	printf("\nERROR: Token %s nao reconhecido na linha %d, posicao %d\n",yytext,num_linha,posicao_linha);
}

%}

str  \"(\\.|[^"\\])*\"
new_line  \n
tabulacao	\t
espaco " "
letter [a-zA-Z]
digit [0-9]
id   {letter}({letter}|{digit})*
num  {digit}+

sub  "-"
mult  "*"
plus "+"
remove "remove"
exists "exists"
add "add"
div  "/"
is_in "in"
is_set "is_set"

type "int"|"float"|"set"|"elem"
equals "="
or "||"
and "&&"

return "return"
if "if"
while "while"
else "else"
for "for"
forall "forall"
write "write"
writeLn "writeLn"
read	"read"

cle "<="
cgt ">"
ceq "=="
cne "!="
clt "<"
cge ">="

empty "EMPTY"


%%

"]"		{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return ']';
   
}

"["		{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '[';
   
}

"&"		{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '&';
   
}

","		{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return ',';
   
}

{read}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return READ;;
   
}

{writeLn}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return WRITELN;
   
}

{write}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return WRITE;
   
}

{add}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return ADD;
   
}

{espaco}	{
    		posicao_linha += 1;
   
}

{forall}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return FORALL;
   
}

{plus}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '+';
}

{cgt}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return CGT;
   
}


{for}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return FOR;
   
}

{else}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return ELSE;
   
}

{while}	{
    		//printf("Token valido: -> %s\n", yytext);
   			posicao_linha += 1;
			return WHILE;
}

{if}	{
    		//printf("Token valido: -> %s\n", yytext);
   			posicao_linha += 1;
			return IF;
}

{is_in}	{
    		//printf("Token valido: -> %s\n", yytext);
   			posicao_linha += 1;
			return IS_IN;
}

{type}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += 1;
			return TYPE;
}


{return}	{
    		//printf("Token valido: -> %s\n", yytext);
   			posicao_linha += 1;
			return RETURN;
}

{tabulacao}	{
    		//printf(" ");
}	

{new_line}	{
    		num_linha += 1;
    		posicao_linha = 0;
   
}

{letter}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return LETTER;
   
}

{digit}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;  
			return DIGIT;
}

{id}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return ID;
   
}

{sub}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '-';
   
}


{div}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '/';
   
}


{equals}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '=';
   
}

{or}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '||';
   
}

{and}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return AND;
   
}


{cle}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return CLE;
}

{ceq}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return CEQ;
   
}

{cne}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return CNE;
   
}

{clt}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return CLT;
   
}

{is_set}	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return IS_SET;
   
}

"("	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '(';
   
}

")"	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '(';
}
"{"	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '{';
}

"}"	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '}';
   
}

";"	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return ';';
   
}

"_"	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"."	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '.';
   
}

":"		{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return ':';

   
}

"%"		{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"'"	{
    		//printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}


. { 
	posicao_linha += 1;
	printf("Token invalido: -> %s\n", yytext);
    LexicalError();
}


%%
