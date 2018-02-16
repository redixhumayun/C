#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "./hash_table.h"
#include "../DynamicArray/dynamic_array.h"

HashTable *createHashTable(int size) {
    HashTable *ht = malloc(sizeof(HashTable *));
    ht->size = size;
    return ht;
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
            printf("The string is: %s\n", v.s);
            break;
        default:
            break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    int size = 10;
    value v = { .s = "Zaid" };
    HashTable *ht = createHashTable(size);
    int hash = createHash(v, string);
    return 0;
}