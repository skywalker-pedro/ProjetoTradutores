#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

typedef struct  Scope_table {
    int id;
    char *name;
    UT_hash_handle hh; 
}Scope_table;

Scope_table *hashed_scope_table = NULL;

void insert_symbol(int id,char * name, char*type,char*varType) {
    Scope_table * s;
    HASH_FIND_INT(hashed_scope_table,&id,s);
    if(s==NULL){
        s = (Scope_table*)malloc(sizeof(Scope_table)); 
        s -> id = id;
        s -> type = type;
        s -> name = name;
        s -> varType = varType;
        HASH_ADD_INT( hashed_scope_table, id, s );
    }
}
