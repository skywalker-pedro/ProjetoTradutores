#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"


typedef struct hash_table {
    int id;
    char * type; //if it is a variable, or function    
    char * varType; //if it is int, set , elem or float
    char *name;
    char* escopo;
    int registrador;
    int num_params;
    UT_hash_handle hh; 
}Hash_table;

Hash_table *hashed_symbol_table = NULL;

void insert_symbol(int id,char * name, char*type,char*varType,char* escopo,int registrador,int nr_parametros) {
    Hash_table * s;
    HASH_FIND_INT(hashed_symbol_table,&id,s);
    if(s==NULL){
        s = (Hash_table*)malloc(sizeof(Hash_table)); 
        s -> id = id;
        s -> type = type;
        s -> name = name;
        s -> varType = varType;
        s -> escopo = escopo;
        s -> registrador = registrador;
        s -> num_params = nr_parametros;
        HASH_ADD_INT( hashed_symbol_table, id, s );
    }
}

void free_TS(Hash_table * ts){
    Hash_table* aux = ts;
    while(aux!=NULL){
        aux = ts -> hh.next;
        free(ts);
        ts = aux;
    }
}