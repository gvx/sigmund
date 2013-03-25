#ifndef SIGMUND_MINUNIT_H
#define SIGMUND_MINUNIT_H

#define MU_TEST(test, message) do { if (!(test)) return message; } while (0)
#define MU_RUN_TEST(test) do { char *message = test(); tests_run++; \
	if (message) return message; } while (0)
extern int tests_run;

#endif
