#include <stdlib.h>
#include <stdio.h>
#include "utlist.h"

/*

TYPES:

0 = nao definido ainda
1 = int
2 = float
3 = set
4 = elem 

*/

/*
Politica de conversao de tipo

0 = não teve conversao
1 = intToFLoat
2 = floatToInt
3 = elemToInt
4 = IntToElem
5 = elemToFloat
6 = floatToElem
*/

//int current_node_ident = 0;
/* Tree Node*/

typedef struct tac { 
    //char * node_type;
    char * line;
    struct tac * next;
}tac_lines;

int namecmp(tac_lines *a, tac_lines *b) {
    return strcmp(a->line,b->line);
}

void print_tac(tac_lines*tac){
    tac_lines * aux = tac;
    printf("\nTAC:\n");
    while(aux->next!=NULL){
        printf("\n%s",aux->line);
        aux = aux -> next;
    }
    printf("\n");
}

tac_lines * tac_completo = NULL;
tac_lines * elt;
 
void adiciona_linha_tac(tac_lines*tac,char* linha){
tac_lines* nodo=(tac_lines*)malloc(sizeof(tac_lines));
    nodo->line = linha;
    LL_APPEND(tac_completo, nodo);

}

void substitui_linha_tac(char*delete, char*adiciona){
tac_lines* add=(tac_lines*)malloc(sizeof(tac_lines));
tac_lines* del=(tac_lines*)malloc(sizeof(tac_lines));
tac_lines * elt;

    add -> line = adiciona;
    del -> line = delete;

    LL_SEARCH(tac_completo,elt,del,namecmp);
    LL_REPLACE_ELEM(tac_completo,elt,add);
}

void printa_linha_tac(tac_lines*tac,tac_lines* elt){
    printf("\n");
    LL_FOREACH(tac,elt) printf("%s\n", elt -> line);

}

void cria_arquivo_tac(tac_lines*tac,tac_lines*elt){
    
   FILE*fp = fopen("skylang.tac", "w");
   fprintf(fp, ".table\n");
   fprintf(fp, ".code\n");
   LL_FOREACH(tac,elt)
       fprintf(fp,"%s\n", elt -> line);
   fclose(fp);

}

void free_tac_lines(struct tac * tac){
    tac_lines * aux;
    aux = tac;
    while(aux->next!=NULL){
        aux = tac->next;
        free(tac);
        tac = aux;
    }
}