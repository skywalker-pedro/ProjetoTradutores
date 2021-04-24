%option noinput
%option nounput

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
negation "!"

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
    		posicao_linha += yyleng;;
   
}

"["		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{negation}		{
    		printf("Token valido negation: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

"&"		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

","		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

"\""		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

"\\"		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{read}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{writeIn}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{write}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{add}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{espaco}	{
    		posicao_linha += yyleng;;
   
}

{forall}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{plus}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{cgt}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}


{for}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{else}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{while}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += yyleng;;
}

{if}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += yyleng;;
}

{is_in}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += yyleng;;
}

{type}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += yyleng;;
}


{return}	{
    		printf("Token valido: -> %s\n", yytext);
   			posicao_linha += yyleng;;
}

{tabulacao}	{
    		printf(" ");
}	

{new_line}	{
    		num_linha += 1;
    		posicao_linha = 0;
   
}

{integer}	{
    		printf("Token valido Inteiro: -> %s\n", yytext);
    		posicao_linha += yyleng;;  
}

{float_}	{
    		printf("Token valido float_: -> %s\n", yytext);
    		posicao_linha += yyleng;;  
}

{id}	{
    		printf("Token valido ID: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{char}	{
    		printf("Token valido CHAR: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{string}	{
    		printf("Token valido STRING: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{sub}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}


{div}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}


{equals}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{or}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{and}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}


{cle}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{ceq}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{cne}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

{clt}	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

"("	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

")"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

"{"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

"}"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

";"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

"_"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

"."	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

":"		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

"%"		{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}

"'"	{
    		printf("Token valido: -> %s\n", yytext);
    		posicao_linha += yyleng;;
   
}


. { 
	posicao_linha += yyleng;;
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

