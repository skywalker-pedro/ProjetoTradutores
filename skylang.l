%option noinput
%option nounput
%option noyywrap
%{

#include <stdlib.h>
#include <stdio.h>
#include "skylang.tab.h"

int num_linha = 1;
int posicao_linha = 0;
int num_linha_1 = 1;
int posicao_linha_1 = 0;
int passagem;

void LexicalError(){
	printf("\n--> ERRO LEXICO: Lexema %s nao reconhecido na linha %d, coluna %d",yytext,num_linha,posicao_linha);
}

%}

string \"(\\.|[^"\\])*\"
char (\'(.|\\a|\\b|\\f|\\n|\\r|\\t|\\v|\\x|\\\\|\\\'|\\\"|\\\?)\')
new_line  \n
tabulacao	\t
espaco " "
letter [a-zA-Z]
digit [0-9]
integer -?{digit}+
float_ -?{digit}*[.]{digit}+
id   {letter}+({letter}|{digit}|_|-)*

sub  [-]
mult  "*"
plus "+"
remove "remove"
exists "exists"
add "add"
div  "/"
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
		//printf("Token valido exists: -> %s\n",yytext);
		if(passagem == 2){
			posicao_linha += yyleng;
		}
		if(passagem == 1){
			posicao_linha_1 += yyleng;
		}
		//yylval.str = (char *) strdup(yytext);
		return EXISTS;

}

{remove} {
		//printf("Token valido remove: -> %s\n",yytext);
		if(passagem == 2){
			posicao_linha += yyleng;
		}
		if(passagem == 1){
			posicao_linha_1 += yyleng;
		}
		//yylval.str = (char *) strdup(yytext);
		return REMOVE;

}

{in} {

		//printf("Token valido IN: -> %s\n",yytext);
		if(passagem == 2){
			posicao_linha += yyleng;
		}
		if(passagem == 1){
			posicao_linha_1 += yyleng;
		}
		//yylval.str = (char *) strdup(yytext);
		return IN;


}

{empty}	{

			//printf("Token valido EMPTY: -> %s\n",yytext);
			if(passagem == 2){
			posicao_linha += yyleng;
			}
			if(passagem == 1){
			posicao_linha_1 += yyleng;
			}
			//yylval.str = (char *) strdup(yytext);
			return EMPTY;

}

{negation}		{
    		//printf("Token valido negation: -> %s\n", yytext);
    		if(passagem == 2){
			posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			//yylval.str = (char *) strdup(yytext);
			return NEGATION;
   
}

"]"		{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
			posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
   
}

"["		{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
}

"&"		{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
   
}

{colon}		{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return COLON;
   
}

"\""		{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
   
}

"\\"		{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
   
}

{read}	{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return READ;
   
}

{writeLn}	{
    		 //printf("Token valido: -> %s\n", yytext);
			//yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return WRITELN;

   
}

{write}	{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return WRITE;
}

{add}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return ADD;
}

{espaco}	{
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
   
}

{forall}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return FORALL;
}

{cgt}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return CGT;
   
}


{for}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return FOR;
   
}

{else}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return ELSE;
   
}

{if}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
   			if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return IF;
			
}

{type}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
   			if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return TYPE;
}

{is_set}	{
    		//printf("Token valido: -> %s\n", yytext);
			//yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return IS_SET;
   
   
}


{return}	{
    		 //printf("Token valido: -> %s\n", yytext);
			// yylval.str = (char *) strdup(yytext);
   			if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return RETURN;
}

{tabulacao}	{
    		 printf(" ");
			 if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
}	

{new_line}	{
    		if(passagem==2){
				num_linha += 1;
				posicao_linha = 0;
			}
			if(passagem == 1){
				num_linha_1 += 1;
				posicao_linha_1 =0;
			}
}

{sub}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return MINUS;
   
}

{integer}	{
    		//printf("Token valido INTEIRO: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return INTEGER;
}

{float_}	{
    		//printf("Token valido FLOAT: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return FLOAT;
}

{id}	{
    		//printf("Token valido ID: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return ID;
   
}

{char}	{
    		//printf("Token valido CHAR: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return CHAR;
   
}

{string}	{
    		//printf("Token valido STRING: -> %s\n", yytext);
			 yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return STRING;
}


{div}	{
    		 //printf("Token valido: -> %s\n", yytext);
			// yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return DIV;
   
   
}

{mult}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return MULT;
   
   
}

{plus}	{
    		 //printf("Token valido: -> %s\n", yytext);
			//yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return PLUS;
   
   
}

{cge}	{
    		//printf("Token valido eq or greater: -> %s\n", yytext);
			//yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return CGE;
   
}

{ceq}	{
    		 //printf("Token valido equals: -> %s\n", yytext);
			//yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return CEQ;
   
}



{equals}	{
    		 //printf("Token valido assign: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return EQUALS;
   
}

{or}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return OR;
   
}

{and}	{
    		 //printf("Token valido: -> %s\n", yytext);
			// yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return AND;
   
}


{cle}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return CLE;
   
}


{cne}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return CNE;
   
}

{clt}	{
    		 //printf("Token valido: -> %s\n", yytext);
			// yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return CLT;
   
}


{parenteses_ini}	{
    		 //printf("Token valido parenteses ini: -> %s\n", yytext);
			// yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return PARENTESES_INI;
   
}

{parenteses_fim}	{
    		 //printf("Token valido parenteses fim: -> %s\n", yytext);
			// yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return PARENTESES_FIM;
   
}

{chaves_ini}	{
    		 //printf("Token valido chaves ini: -> %s\n", yytext);
			// yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return CHAVES_INI;

   
}

{chaves_fim}	{
    		 //printf("Token valido chaves fim: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return CHAVES_FIM;
   
}

{semicolon}	{
    		 //printf("Token valido: -> %s\n", yytext);
			 //yylval.str = (char *) strdup(yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return SEMICOLON;
   
}

"_"	{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
   
}

"."	{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return '.';
   
}

":"		{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return ':';

}

"%"		{
    		 //printf("Token valido: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
   
}

"'"	{
    		 //printf("Token valido apost: -> %s\n", yytext);
    		if(passagem == 2){
				posicao_linha += yyleng;
			}
			if(passagem == 1){
				posicao_linha_1 += yyleng;
			}
			return APOST;
   
}


. { 
	if(passagem == 2){
		posicao_linha += yyleng;
		LexicalError();
	}
	if(passagem == 1){
		posicao_linha_1 += yyleng;
	}
}


%%