#ifndef _hash_table_h
#define _hash_table_h
#include "../DynamicArray/dynamic_array.h"

typedef union Value {
    int i; //integer
    char *s; //char array (string)
} value;

typedef enum {
    num_int, 
    string
} type;

Array **createHashTable(int);
int createHash(value v, type t);
int hashString(char *);
void insertValue(Array **, int, value, type);

#endif