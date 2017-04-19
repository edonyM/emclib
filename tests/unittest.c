#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include "testsuite.h"

Suite * colorprint_suite(void);
Suite * join_suite(void);
Suite * split_suite(void);

int main(int argc, char *argv[])
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    sr = srunner_create(s);
    srunner_add_suite(sr, join_suite());
    srunner_add_suite(sr, split_suite());
    srunner_add_suite(sr, colorprint_suite());

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
