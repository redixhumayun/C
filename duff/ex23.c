#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int normal_copy(char *from, char *to, int count) {
    int i = 0;

    for(i = 0; i < count; i++) {
        to[i] = from[i];
    }

    return i;
}

int duffs_device(char *from, char *to, int count) {
    {
        int n = (count + 7) / 8;

        switch(count % 8) {
            case 0: do { *to++ = *from++;
                        case 7: *to++ = *from++;
                        case 6: *to++ = *from++;
                        case 5: *to++ = *from++;
                        case 4: *to++ = *from++;
                        case 3: *to++ = *from++;
                        case 2: *to++ = *from++;
                        case 1: *to++ = *from++;
            } while(--n > 0);
        }
    }
    *to--;
    printf("The to string is: %s\n", to);
    return count;
}

int valid_copy(char *data, char expects, int count) {
    int i = 0;
    for(i = 0; i < count; i++) {
        if(data[i] != expects) {
            printf("[%d] %c != %c", i, data[i], expects);
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    char from[1000] = { 'a' };
    char to[1000] = { 'c' };
    int rc = 0;

    memset(from, 'x', 1000);
    memset(to, 'y', 1000);
    
    rc = normal_copy(from, to, 1000);
    printf("Normal copy rc: %d\n", rc);

    memset(to, 'y', 1000);

    rc= duffs_device(from, to, 1000);
    printf("Duffs device rc: %d\n", rc);

    memset(to, 'y', 1000);

    return 0;
}