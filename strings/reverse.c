#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseWord(char *s, int size) {
    int i = 0;
    for(i = 0; i < size / 2; i++) {
        char temp = s[size - i -1];
        s[size - i - 1] = s[i];
        s[i] = temp;
    }
    return;
}

void reverseString(char *s) {
    int i = 0;
    int size = strlen(s);
    for(i = 0; i < size; i++) {
        int j = i;
        char word[10] = "r";
        while(s[j] != ' ') {
            word[j - i] = s[j];
            j++;
        }
        // printf("Reversing word: %s\n", word);
        int word_size = strlen(word);
        reverseWord(&s[i], word_size);
        i = j;
    }
    return;
}

int main(int argc, char *argv[]) {
    char s[] = "My name is Chris";
    int i = 0;
    int size = strlen(s);
    for(i = 0; i < size / 2; i++) {
        char temp = s[size - i - 1];
        s[size - i -1] = s[i];
        s[i] = temp;
    }
    reverseString(s);
    printf("Returned to main\n");
    printf("String is now: %s\n", s);
    return 0;
}