#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <include/emstr.h>
#include "testsuite.h"

START_TEST(test_split) {
    char str[16] = "a/bc:123:cr/tdd";
    char delim[3] = {':', '/', '\0'};
    STRLIST *result = (STRLIST*)malloc(sizeof(STRLIST));
    result->str = NULL;
    result->next = NULL;
    int count = split(str, delim, result);
    ck_assert(strcmp(splitem(0, result)->pstr, "a") == 0);
    ck_assert_msg(strcmp(splitem(1, result)->pstr, "bc") == 0,
                  "Was expecting a currency of USD, but found %s", splitem(0,result)->pstr);
    destroy(result);
}
END_TEST

Suite * split_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("split");
    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_split);
    suite_add_tcase(s, tc_core);

    return s;
}
