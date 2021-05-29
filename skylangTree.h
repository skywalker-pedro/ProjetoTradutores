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

typedef struct node { 
    //char * node_type;
    char * node_name;
    int flag_print;
    int printa_tac;
    int type;
    int conversao;
    char * value_tac;
    char* value;
    char* linha_tac;
    char*result;
    struct node * leaf1;
    struct node * leaf2;
    struct node * leaf3;
    struct node * leaf4;
    struct node * leaf5;
}treeNode;

/*add a tree node to the tree*/
treeNode*add_tree_node(char*name){
    treeNode * node = (treeNode*)malloc(sizeof(treeNode));
    node -> flag_print = 0;
    node -> node_name = name;
    node -> printa_tac =0;
    node -> type = 0;
    node -> value = NULL;
    node -> result = NULL;
    node -> value_tac = NULL;
    node -> linha_tac = NULL;
    node -> conversao = 0;
    node -> leaf1 = NULL;
    node -> leaf2 = NULL;    
    node -> leaf3 = NULL;    
    node -> leaf4 = NULL;    
    node -> leaf5 = NULL;    
    return node;
}


/*Politica de conversao de tipo
0 = não teve conversao
1 = intToFLoat
2 = floatToInt
3 = elemToInt
4 = IntToElem
5 = elemToFloat
6 = floatToElem
TYPES:
0 = nao definido ainda
1 = int
2 = float
3 = set
4 = elem */

void print_tree(int conta_identacao,struct node * node){

int i;
   
    if(node==NULL){
        return;
    }
    if (conta_identacao == 0) {
        if(node->flag_print != 0)
            printf("\n%s",node->node_name);
    }else{
        if(node->flag_print != 0) 
           printf("\n");
        for(i=0;i<conta_identacao+1;i++){
            if(node->flag_print != 0)  
                printf("->");
        }
        if(node->flag_print != 0)
            printf("%s",node->node_name);
        if((node->flag_print != 0) || (node->conversao != 0)){
            printf("\n");
            for(i=0;i<conta_identacao+1;i++){
                printf(" ");
            }
            if (node->type == 1)
                printf("-> INT"); 
            if (node->type == 2)
                printf("-> FLOAT");
            if (node->type == 3)
                printf("-> SET");
            if (node->type == 4)
                printf("-> ELEM");
            if(node->value != NULL)
                printf("  %s",node->value);

            if (node->conversao == 1)
                printf("\n -> Conversao intToFLoat"); 
            if (node->conversao == 2)
                printf("-> Conversao floatToInt");
            if (node->conversao == 3)
                printf("-> Conversao elemToInt");
            if (node->conversao == 4)
                printf("-> Conversao intToElem");
            if (node->conversao == 5)
                printf("-> Conversao elemToFloat");
            if (node->conversao == 6)
                printf("-> Conversao floatToElem");

        }
    }
    if(node->leaf1!=NULL){
        conta_identacao = conta_identacao + 1;
        print_tree(conta_identacao,node->leaf1);
    };
    if(node->leaf2!=NULL){
        conta_identacao = conta_identacao + 1;
        print_tree(conta_identacao,node->leaf2);
    };
    if(node->leaf3!=NULL){
        conta_identacao = conta_identacao + 1;
        print_tree(conta_identacao,node->leaf3);
    };
    if(node->leaf4!=NULL){
        conta_identacao = conta_identacao + 1;
        print_tree(conta_identacao,node->leaf4);
    };
    if(node->leaf5!=NULL){
        conta_identacao = conta_identacao + 1;
        print_tree(conta_identacao,node->leaf5);
    };
    //printf("\nNada\n");
}

void print_tac_tree(struct node * node){

    if(node==NULL){
        return;
    }
    if(node->linha_tac!=NULL){
        printf("%s",node->linha_tac);
        printf("\n");
    }
    if(node->leaf1!=NULL){
       print_tac_tree(node->leaf1);
    }
    if(node->leaf2!=NULL){
       print_tac_tree(node->leaf2);
    }
    if(node->leaf3!=NULL){
       print_tac_tree(node->leaf3);
    }
    if(node->leaf4!=NULL){
       print_tac_tree(node->leaf4);
    }
    if(node->leaf5!=NULL){
       print_tac_tree(node->leaf5);
    }
    //printf("\nNada\n");
}


void free_tree(struct node * node){

    if(node==NULL){
        return;
    }
    //printf("\nNode desalocado\n");
    if(node->leaf1!=NULL){
        free_tree(node->leaf1);
    };
    if(node->leaf2!=NULL){
        free_tree(node->leaf2);
    };
    if(node->leaf3!=NULL){
        free_tree(node->leaf3);
    };
    if(node->leaf4!=NULL){
        free_tree(node->leaf4);
    };
    if(node->leaf5!=NULL){
        free_tree(node->leaf5);
    };
    free(node);
}