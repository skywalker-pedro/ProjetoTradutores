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

str  \"(\\.|[^"\\])*\"
new_line  \n
tabulacao	\t
espaco " "
letter [a-zA-Z]
digit [0-9]
id   {letter}+({letter}|{digit}|_|-)*
num  {digit}+

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


{str}  {
            printf("Token valido string: -> %s\n",yytext);
			yylval.str = (char *) strdup(yytext);
            return STRING;
}

{exists} {
		printf("Token valido exists: -> %s\n",yytext);
		yylval.str = (char *) strdup(yytext);
		return EXISTS;

}

{remove} {
		printf("Token valido remove: -> %s\n",yytext);
		yylval.str = (char *) strdup(yytext);
		return REMOVE;

}

{in} {

		printf("Token valido IN: -> %s\n",yytext);
		yylval.str = (char *) strdup(yytext);
		return IN;


}

{empty}	{

			 printf("Token valido EMPTY: -> %s\n",yytext);
			 yylval.str = (char *) strdup(yytext);
			return EMPTY;

}

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

{colon}		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return COLON;
   
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
			return READ;
   
}

{writeLn}	{
    		 printf("Token valido: -> %s\n", yytext);
			yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return WRITELN;

   
}

{write}	{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return WRITE;
}

{add}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return ADD;
}

{espaco}	{
    		posicao_linha += 1;
   
}

{forall}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return FORALL;
}

{plus}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return '+';
}

{cgt}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return CGT;
   
}


{for}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return FOR;
   
}

{else}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return ELSE;
   
}

{while}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
   			posicao_linha += 1;
			return WHILE;
}

{if}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
   			posicao_linha += 1;
			return IF;
			
}

{type}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
   			posicao_linha += 1;
			return TYPE;
}


{is_in}	{
    		printf("Token valido: -> %s\n", yytext);
			yylval.str = (char *) strdup(yytext);
   			posicao_linha += 1;
			return IS_IN;
}

{is_set}	{
    		printf("Token valido: -> %s\n", yytext);
			yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return IS_SET;
   
   
}


{return}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
   			posicao_linha += 1;
			return RETURN;
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
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return LETTER;
   
}

{digit}	{
    		 printf("Token valido digito: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1; 
			return DIGIT; 
}

{id}	{
    		 printf("Token valido tipo ID: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return ID;
   
}

{sub}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return '-';
   
}


{div}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return '/';
   
   
}


{cge}	{
    		printf("Token valido eq or greater: -> %s\n", yytext);
			yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return CGE;
   
}

{ceq}	{
    		 printf("Token valido equals: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return CEQ;
   
}



{equals}	{
    		 printf("Token valido assign: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return EQUALS;
   
}

{or}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return OR;
   
}

{and}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return AND;
   
}


{cle}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return CLE;
   
}


{cne}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return CNE;
   
}

{clt}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return CLT;
   
}


{parenteses_ini}	{
    		 printf("Token valido parenteses ini: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return PARENTESES_INI;
   
}

{parenteses_fim}	{
    		 printf("Token valido parenteses fim: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return PARENTESES_FIM;
   
}

{chaves_ini}	{
    		 printf("Token valido chaves ini: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return CHAVES_INI;

   
}

{chaves_fim}	{
    		 printf("Token valido chaves fim: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return CHAVES_FIM;
   
}

{semicolon}	{
    		 printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		posicao_linha += 1;
			return SEMICOLON;
   
}

"_"	{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"."	{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return '.';
   
}

":"		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
			return ':';

}

"%"		{
    		 printf("Token valido: -> %s\n", yytext);
    		posicao_linha += 1;
   
}

"'"	{
    		 printf("Token valido apost: -> %s\n", yytext);
    		posicao_linha += 1;
			return APOST;
   
}


. { 
	posicao_linha += 1;
    LexicalError();
}


%%