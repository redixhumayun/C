#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *names[3];
    char name[20];
    int i;
    for(i = 0; i < 3; i++) {
        printf("Enter your name\n");
        scanf("%s", name);
        names[i] = (char *)malloc(strlen(name));
        names[i] = &name;
        // strcpy(names[i], name);
    }
    printf("Printing the names\n");
    for(i = 0; i < 3; i++) {
        printf("%s\n", names[i]);
    }
}