#ifndef _hash_table_h
#define _hash_table_h
#include "../DynamicArray/dynamic_array.h"

typedef union Value {
    int i; //integer
    float f; //float
    char s[20]; //char array (string)
} value;

typedef enum {
    num_int, 
    num_float, 
    string
} type;

Array **createHashTable(int);
int createHash(value v, type t);
int hashString(char *);

#endif