#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Person {
    char *name;
    int age;
    int weight;
    int height;
};

struct Person *createPerson(char *name, int age, int weight, int height) {
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);
    who->name = name;
    who->age = age;
    who->weight = weight;
    who->height = height;

    return who;
}

void destroyPerson(struct Person *who) {
    assert(who != NULL);
    free(who->name);
    free(who);
}

void printPerson(struct Person *who) {
    printf("Name: %s\n", who->name);
    printf("Age: %d\n", who->age);
    printf("Height: %d\n", who->height);
}

int main(int argc, char *argv[]) {
    struct Person *person1 = createPerson("Zaid", 21, 24, 42);
    printf("Memory address: %p\n", person1);
    printPerson(person1);
}