#include <stdlib.h>
#include <stdio.h>

//int current_node_ident = 0;
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

   /* if(node==NULL){
        current_node_ident = 0;
        printf("\n");
        return;
    }else{
        current_node_ident ++;
    }
    
    for(i=0;i<current_node_ident;i++){
        printf("->");
    }*/

    if(node==NULL){
        return;
    }

    printf("\n%s",node->node_name);
    print_tree(node->leaf1);
    print_tree(node->leaf2);
    print_tree(node->leaf3);
    print_tree(node->leaf4);
    print_tree(node->leaf5);
    
    //printf("\nNada\n");
}
