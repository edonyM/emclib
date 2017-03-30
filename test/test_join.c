#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <include/emstr.h>

int main(int argc, char *argv[]) {
    STRLIST *strings = (STRLIST*)malloc(sizeof(STRLIST));
    strings->next = NULL;
    strings->str = NULL;

    printf("start append:\n");
    append(strings, "edony");
    printf("%s-->", strings->str->pstr);
    append(strings, "hello");
    printf("%s-->", strings->next->str->pstr);
    append(strings, "string");
    printf("%s-->", strings->next->next->str->pstr);

    join(",", strings);

    STRLIST *tmp = strings;
    while (tmp) {
        printf("%s\n", strings->str->pstr);
    }

    return 0;
}
