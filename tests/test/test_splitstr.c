#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <include/emstr.h>

int main(int argc, char *argv[])
{
    char str[16] = "a/bc:123:cr/tdd";
    char delim[3] = {':', '/', '\0'};
    STRLIST *result = (STRLIST*)malloc(sizeof(STRLIST));
    result->str = NULL;
    result->next = NULL;
    int count = split(str, delim, result);
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
