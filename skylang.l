%{

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

type "int"|"float"|"char"|"set"|"elem"
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
writeIn "writeIn"
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
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"["		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"&"		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

","		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"\""		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"\\"		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{read}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{writeIn}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{write}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{add}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{espaco}	{
    		posicao_linha += 1;
   
}

{forall}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{plus}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{cgt}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}


{for}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{else}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{while}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += 1;
}

{if}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += 1;
}

{is_in}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += 1;
}

{type}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += 1;
}


{return}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += 1;
}

{tabulacao}	{
    		printf(" ");
}	

{new_line}	{
    		num_linha += 1;
    		posicao_linha = 0;
   
}

{letter}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{digit}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;  
}

{id}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{sub}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}


{div}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}


{equals}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{or}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{and}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}


{cle}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{ceq}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{cne}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{clt}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

{is_set}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"("	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

")"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"{"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"}"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

";"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"_"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"."	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

":"		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"%"		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"'"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}


. { 
	posicao_linha += 1;
    LexicalError();
}


%%

int yywrap(){
	return 1;
}


int main(){
char fname[100];
    printf("\nDigite o nome do arquivo a ser analisado:\n-> ");
    scanf("%s",fname);
    yyin=fopen(fname,"r+");
    yylex();
    return 0;
}

