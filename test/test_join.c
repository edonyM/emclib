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

    return 0;
}
