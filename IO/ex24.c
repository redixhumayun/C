#include <stdio.h>

#define MAX_DATA 100

typedef enum EYE_COLOR {
    BLUE_EYES, GREEN_EYES, BROWN_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Other"
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

int main(int argc, char *argv[]) {
    Person you;
    int i = 0;
    char *in = NULL;

    printf("What's your first name?");
    in = fgets(you.first_name, MAX_DATA-1, stdin);
    if(in == NULL) {
        printf("Failed to read first name");
    }

    printf("What's your last name?");
    in = fgets(you.last_name, MAX_DATA-1, stdin);
    if(in == NULL) {
        printf("Failed to read last name");
    }

    printf("How old are you?");
    int rc = fscanf(stdin, "%d", &you.age);
    if(rc <= 0) {
        printf("You have to enter a number");
    }

    printf("What color are your eyes?");
    for(i = 0; i <= OTHER_EYES; i++ ) {
        printf("(%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
    }
    printf("> ");

    int eyes = -1;
    rc = fscanf(stdin, "%d", &eyes);
    if(rc <= 0) {
        printf("You have to enter a number");
    }
    you.eyes = eyes - 1;

    printf("What is your income?");
    rc = fscanf(stdin, "%f", &you.income);
    
    printf("--------------RESULTS---------------");
    printf("First name is: %s\n", you.first_name);
    printf("Last name is: %s\n", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eye color is: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);
    return 0;
}