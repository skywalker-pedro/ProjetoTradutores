#include <stdlib.h>
#include <stdio.h>


/* Tree Node*/

typedef struct node { 
    char * node_type;
    char * node_name;
    struct node * leaf1;
    struct node * leaf2;
    struct node * leaf3;
    struct node * leaf4;
    struct node * leaf5;
}treeNode;

/*initialize an empty tree*/

treeNode *initialize_tree(){
    treeNode * node = (treeNode*)malloc(sizeof(treeNode));
    node -> node_type =NULL;
    node -> node_name = NULL;
    node -> leaf1 = NULL;
    node -> leaf2 = NULL;    
    node -> leaf3 = NULL;    
    node -> leaf4 = NULL;    
    node -> leaf5 = NULL;    
    return node;
}

/*add a tree node to the tree*/
treeNode*add_tree_node(char*name){
    treeNode * node = (treeNode*)malloc(sizeof(treeNode));
    node -> node_name = name;
    node -> leaf1 = NULL;
    node -> leaf2 = NULL;    
    node -> leaf3 = NULL;    
    node -> leaf4 = NULL;    
    node -> leaf5 = NULL;    
    return node;
}


void print_tree(struct node * node){
    if(node==NULL){
        printf("\nArvore Vazia");
        return;
    }

    printf("\n%s",node->node_name);
    
    if (node -> leaf1 != NULL){
        print_tree(node->leaf1);
    }
    if (node -> leaf2 != NULL){
        print_tree(node->leaf2);
    }
    if (node -> leaf3 != NULL){
        print_tree(node->leaf3);
    }
    if (node -> leaf4 != NULL){
        print_tree(node->leaf4);
    }
    if (node -> leaf5 != NULL){
        print_tree(node->leaf5);
    }
  

    //printf("\nNada\n");
}
