#ifndef _MINUNIT_H_
#define _MINUNIT_H_

#define mu_assert(message, test) do { if(!(test)) return message; } while(0)
#define mu_run_test(test, args) do { char *message = test(args); tests_run++; \
                                if(message) return message; } while(0)
#define mu_run_test_noargs(test) do { char *message = test(); tests_run++; \
                                if(message) return message; } while(0)

#define RUN_TESTS(name) int main(int argc, char *argv[]) {\
    argc = 1; \
    printf("----- RUNNING: %s", argv[0]);\
    printf("----\nRUNNING: %s\n", argv[0]);\
    char *result = name();\
    if (result != 0) {\
        printf("FAILED: %s\n", result);\
    }\
    else {\
        printf("ALL TESTS PASSED\n");\
    }\
    printf("Tests run: %d\n", tests_run);\
    exit(result != 0);\
}

extern int tests_run;

#endif
