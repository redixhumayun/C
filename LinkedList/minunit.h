#ifndef _MINUNIT_H_
#define _MINUNIT_H_

#define mu_assert(message, test) do { if(!(test)) return message; } while(0)
#define mu_run_test(test, args) do { char *message = test(args); tests_run++; \
                                if(message) return message; } while(0)
                                
extern int tests_run;

#endif