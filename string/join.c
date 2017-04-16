#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <include/emstr.h>

int join(const char *str, STRLIST *iter) {
    if (!str || !iter) return ERR;

    size_t sum_len = 0;
    int counter = 0;

    STRLIST *tmp = iter;
    while (tmp) {
        counter++;
        sum_len += tmp->str->len;
        tmp = tmp->next;
    }
    sum_len += (strlen(str) * (counter - 1) + 1);

    char *result = (char*)malloc(sizeof(char) * sum_len);
    tmp = iter;
    int pos = 0;
    while (tmp) {
        int node_str;
        for (node_str=0; node_str < tmp->str->len; node_str++) {
            result[pos++] = tmp->str->pstr[node_str];
        }
        if (tmp->next == NULL) break;
        int str_len;
        for (str_len = 0; str_len < strlen(str); ++str_len) {
            result[pos++] = str[str_len];
        }
        tmp = tmp->next;
    }
    result[pos] = '\0';
    append(iter, result);

    return PASS;
}
