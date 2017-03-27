#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <include/emstr.h>

#define ERR  -1

/*
typedef struct node{
    struct node *next;
    char *pstr;
    size_t len;
}STRLIST;
*/

int split(char *str, const char *delim, STRLIST *str_list) {
    if ((str == NULL) || (delim == NULL)) return ERR;

    size_t len_delim = strlen(delim);
    if (len_delim <= 0) return ERR;

    size_t len_str = strlen(str);
    if (len_str <= 0) return ERR;

    char *str_cpy = str;
    char *saveptr = NULL;
    char *str_tmp = NULL;
    STRLIST *tmp = NULL;
    STRLIST *tail = str_list;
    int counter = 0;

    str_tmp = strtok_r(str_cpy, delim, &saveptr);
    printf("%s\n", str_tmp);

    // new splitted node
    STRLIST *node = (STRLIST*)malloc(sizeof(STRLIST));
    node->pstr = (char*)malloc(strlen(str_tmp));
    strncpy(node->pstr, str_tmp, strlen(str_tmp));
    node->len = strlen(str_tmp);
    node->next = NULL;
    // insert the new node
    tail->next = node;
    tail = node;

    while (str_tmp) {
        // count the splitted node
        counter++;
        str_tmp = strtok_r(NULL, delim, &saveptr);
        if (str_tmp) {
             printf("%s\n", str_tmp);

             // new splitted node
             STRLIST *node1 = (STRLIST*)malloc(sizeof(STRLIST));
             node1->pstr = (char*)malloc(strlen(str_tmp));
             strncpy(node1->pstr, str_tmp, strlen(str_tmp));
             node1->len = strlen(str_tmp);
             node1->next = NULL;
             // insert the new node
             tail->next = node1;
             tail = node1;
        }
    }
    
    return counter;
}

char *splitem(int idx, STRLIST *str_list) {
    if (str_list == NULL) return NULL;

    int counter = 0;
    STRLIST *tmp = str_list;
    while (tmp) {
        counter++;
        tmp = tmp->next;
    }
    if (idx > (counter-1) || idx < 0) return NULL;

    tmp = str_list;
    for (int i=0; i < (idx+1); ++i) {
        tmp = tmp->next;
    }
    return tmp->pstr;
}

/*
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
*/
