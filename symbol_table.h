#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"
#include <string.h>

typedef struct hash_table {
    int id;
    char * type; //if it is a variable, or function    
    char * varType;      //if it is int, set or elem  
    char *name;
    UT_hash_handle hh; 
}Hash_table;

Hash_table *hashed_symbol_table = NULL;

void insert_symbol(int id,char * name, char*type,char*varType) {
    Hash_table * s;
    HASH_FIND_INT(hashed_symbol_table,&id,s);
    if(s==NULL){
        s = (Hash_table*)malloc(sizeof(Hash_table)); 
        s -> id = id;
        s -> type = type;
        s -> name = name;
        s -> varType = varType;
        HASH_ADD_INT( hashed_symbol_table, id, s );
    }
}
