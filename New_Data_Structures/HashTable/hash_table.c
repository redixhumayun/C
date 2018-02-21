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
            break;
        case num_float:
            return round(fmod(v.f, 10.0));
            break;
        case string:
            return hashString(&v.s[0]) % 10;
            break;
        default:
            break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    Array **ptr = createHashTable(10);
    int i = 0;
    for(i = 0; i < 10; i++) {
        printf("i: %d capacity: %d\n", i, ptr[i]->capacity);
    }
    return 0;
}