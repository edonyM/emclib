#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <include/color.h>
#include "testsuite.h"

START_TEST(test_colorprint) {
    char *str = "colorprint test\n";
    cprintf("green", str);
}
END_TEST

Suite * colorprint_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("colorprint");
    /* Core test case */
    tc_core = tcase_create("Core");

    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, test_colorprint);

    return s;
}
