#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./hash_table.h"
#include "../DynamicArray/dynamic_array.h"

Array **createHashTable(int size) {
    Array **array = malloc(sizeof(Array) * 10);
    if(array == NULL) {
        exit(1);
    }
    int i = 0;
    for(i = 0; i < size; i++) {
        array[i] = createArray(size);
    }
    return array;
}

void insertValue(Array **table, int index, value v, type t) {
    if(index < 0 || index > 10) {
        exit(1);
    }
    switch(t) {
        case num_int:
            push(table[index], (void *)(&(v.i)));
            break;
        case string:
            // void *ptr = &v.s;
            push(table[index], v.s);
            break;
        default:
            break;
    }
}

int hashString(char *str) {
    unsigned int hash = 0;
    int c;

    while ((c = *str++)) {
        hash += c;
    }
    return hash;
}

int createHash(value v, type t) {
    switch(t) {
        case num_int:
            return v.i % 10;
        case string:
            return hashString(v.s) % 10;
        default:
            break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    Array **ptr = createHashTable(10);
    char *names[] = { "Zaid", "Humayun", "Hello", "World", "What", "Are", "You", "Doing" };
    int names_size = 8;
    int i = 0;
    int hashValue = 0;
    for(i = 0; i < names_size; i++) {
        value v = { .s = names[i] };
        hashValue = createHash(v, string);
        insertValue(ptr, hashValue, v, string);
    }
}