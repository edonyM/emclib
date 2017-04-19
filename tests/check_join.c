#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <include/emstr.h>
#include "testsuite.h"

START_TEST(test_join) {
    STRLIST *strings = (STRLIST*)malloc(sizeof(STRLIST));
    strings->next = NULL;
    strings->str = NULL;

    append(strings, "edony");
    append(strings, "hello");
    append(strings, "string");

    join("::", strings);

    emstring *string = splitem(-1, strings);
    ck_assert(strcmp(string->pstr, "edony::hello::string") == 0);

}
END_TEST

Suite * join_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("join");
    /* Core test case */
    tc_core = tcase_create("Core");

    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, test_join);

    return s;
}
