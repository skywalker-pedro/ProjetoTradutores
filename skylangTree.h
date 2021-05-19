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
    int type;
    int conversao;
    struct node * leaf1;
    struct node * leaf2;
    struct node * leaf3;
    struct node * leaf4;
    struct node * leaf5;
}treeNode;

/*add a tree node to the tree*/
treeNode*add_tree_node(char*name){
    treeNode * node = (treeNode*)malloc(sizeof(treeNode));
    node -> node_name = name;
    node -> type = 0;
    node -> conversao = 0;
    node -> leaf1 = NULL;
    node -> leaf2 = NULL;    
    node -> leaf3 = NULL;    
    node -> leaf4 = NULL;    
    node -> leaf5 = NULL;    
    return node;
}

void print_tree(int conta_identacao,struct node * node){

int i;
   
    if(node==NULL){
        return;
    }
    if (conta_identacao == 0) {
        printf("\n%s",node->node_name);
    }else{
        printf("\n");
        for(i=0;i<conta_identacao+1;i++){
            printf("->");
        }
        printf("%s",node->node_name);
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