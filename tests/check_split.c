#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <include/emstr.h>
#include "testsuite.h"

START_TEST(test_split) {
    //Money *m;

    //m = money_create(5, "USD");
    //ck_assert_int_eq(money_amount(m), 5);
    //ck_assert_str_eq(money_currency(m), "USD");
    //money_free(m);
    char str[16] = "a/bc:123:cr/tdd";
    char delim[3] = {':', '/', '\0'};
    STRLIST *result = (STRLIST*)malloc(sizeof(STRLIST));
    result->str = NULL;
    result->next = NULL;
    int count = split(str, delim, result);
    ck_assert(strcmp(splitem(0, result)->pstr, "a") == 0);
    ck_assert_msg(strcmp(splitem(1, result)->pstr, "bc") == 0,
                  "Was expecting a currency of USD, but found %s", splitem(0,result)->pstr);
    printf("%d\n", count);
    STRLIST *tmp = result;
    while(count > 0) {
        printf("--->%s\n", tmp->str->pstr);
        tmp = tmp->next;
        count--;
    }
    printf("splitem test\n");
    for (int i=0; i < 5; ++i) {
        printf("===> %s\n", splitem(i, result)->pstr);
    }
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

    suite_add_tcase(s, tc_core);
    tcase_add_test(tc_core, test_split);

    return s;
}