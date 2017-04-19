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

    printf("start append:\n");
    append(strings, "edony");
    printf("%s-->\n", strings->str->pstr);
    append(strings, "hello");
    printf("%s-->%s\n", strings->str->pstr, strings->next->str->pstr);
    append(strings, "string");
    printf("%s-->%s-->%s\n", strings->str->pstr,
            strings->next->str->pstr, strings->next->next->str->pstr);
    printf("finish append.\n");

    join("::", strings);

    STRLIST *tmp = strings;
    while (tmp) {
        printf("%s\n", tmp->str->pstr);
        tmp = tmp->next;
    }
    emstring *string = splitem(-1, strings);
    printf("end: %s\n", string->pstr);
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
