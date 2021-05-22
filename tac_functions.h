#include <stdlib.h>
#include <stdio.h>



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


void print_tac(tac_lines*tac){
    tac_lines * aux = tac;
    printf("\nTAC:\n");
    while(aux->next!=NULL){
        printf("\n%s",aux->line);
        aux = aux -> next;
    }
    printf("\n");
}

/*add a tree node to the tree*/
tac_lines* add_tac_line(tac_lines*tac,char*line_t, int pass){
    printf("\nPASSAGEM:%d",pass);
    tac_lines * current = (tac_lines*)malloc(sizeof(tac_lines));
    //printf("\nDENTRO DA %s",line_t);
    current -> line = line_t;
    printf("\nDENTRO TAC ->%s",current -> line);
    current -> next = tac;
    tac=current;

    printf("\n----------------");

    print_tac(tac);

    printf("\n----------------\n");
    return tac;
}




tac_lines * initialize_tac(tac_lines* tac,char*valor){
    tac_lines * current = (tac_lines*)malloc(sizeof(tac_lines));
    current->line = valor;
    current-> next = NULL;
    tac -> next = current;
    return tac;
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