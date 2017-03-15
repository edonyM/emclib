#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <include/split.h>

int main(int argc, char *argv[])
{
    char str[15] = "a/bc:123:cr/tdd";
    char delim[3] = {':', '/', '\0'};
    STRLIST *result = (STRLIST*)malloc(sizeof(STRLIST));
    result->pstr = (char*)malloc(strlen(str));
    strncpy(result->pstr, str, strlen(str));
    result->len = strlen(str);
    result->next = NULL;
    int count = split(str, delim, result);
    printf("%d\n", count);
    STRLIST *tmp = result->next;
    while(count > 0) {
        printf("--->%s\n", tmp->pstr);
        tmp = tmp->next;
        count--;
    }
    for (int i=0; i < 5; ++i) {
        printf("===> %s\n", splitem(i, result));
    }
}
