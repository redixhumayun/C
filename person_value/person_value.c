#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Person {
    char *name;
    int age;
    int weight;
    int height;
};

struct Person createPerson(char *name, int age, int weight, int height) {
    struct Person person;
    person.name = name;
    person.age = age;
    person.weight = weight;
    person.height = height;

    return person;
}

void printPerson(struct Person person) {
    printf("Name: %s\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Weight: %d\n", person.weight);
    printf("Height: %d\n", person.height);
}

void printPersonUsingPointer(struct Person *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Weight: %d\n", person->weight);
}

int main(int argc, char *argv[]){
    struct Person person1 = createPerson("Zaid", 21, 25, 252);
    printPerson(person1);

    struct Person *personPointer = &person1;
    printf("**************");
    printf("Pointer: %p\n", personPointer);
    printPersonUsingPointer(personPointer);
    return 0;
}