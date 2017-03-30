#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <include/emstr.h>

#if defined(_WIN32) || defined(_WIN64)
/* Windows */
#define strtok_r strtok_s
#endif

int append(STRLIST *str_list, char *instr) {
    printf("%s\n", instr);
    if ((!str_list) || (!instr)) return -1;

    emstring *string = (emstring*)malloc(sizeof(emstring));
    if (!string) return -1;
    string->len = strlen(instr);
    string->pstr = (char *)malloc(string->len + 1);
    if (!string->pstr) return -1;
    strncpy(string->pstr, instr, string->len);

    if ((!str_list->str) && (!str_list->next)) {
        str_list->str = string;
    } else {
        STRLIST *node = (STRLIST*)malloc(sizeof(STRLIST));
        if (!node) return -1;
        node->str = string;
        node->next = NULL;
        // insert the new node
        STRLIST *tmp = str_list;
        while (tmp->next) tmp = tmp->next;
        tmp->next = node;
    }

    return 0;
}

int destroy(STRLIST *str_list) {
    if (!str_list) return -1;
    STRLIST *tmp = NULL;
    while (str_list) {
        free(str_list->str->pstr);
        str_list->str->pstr = NULL;
        free(str_list->str);
        str_list->str = NULL;
        tmp = str_list->next;
        free(str_list);
        str_list = tmp;
    }
    return 0;
}


int split(char *str, const char *delim, STRLIST *str_list) {
    if ((str == NULL) || (delim == NULL)) return ERR;

    size_t len_delim = strlen(delim);
    if (len_delim <= 0) return ERR;

    size_t len_str = strlen(str);
    if (len_str <= 0) return ERR;

    char *str_cpy = str;
    char *saveptr = NULL;
    char *str_tmp = NULL;
    //STRLIST *tmp = NULL;
    //STRLIST *tail = str_list;
    int counter = 0;

    str_tmp = strtok_r(str_cpy, delim, &saveptr);

    // new splitted node
    append(str_list, str_tmp);

    while (str_tmp) {
        // count the splitted node
        counter++;
        str_tmp = strtok_r(NULL, delim, &saveptr);
        if (str_tmp) {
             // new splitted node
             append(str_list, str_tmp);
        }
    }

    return counter;
}

emstring *splitem(int idx, STRLIST *str_list) {
    if (str_list == NULL) return NULL;

    int counter = 0;
    STRLIST *tmp = str_list;
    while (tmp) {
        counter++;
        tmp = tmp->next;
    }
    if (idx > (counter-1) || idx < (0-counter)) return NULL;
    int index = idx;
    if (idx < 0) {
        index = counter + idx;
    }

    tmp = str_list;
    for (int i=0; i < index; ++i) {
        tmp = tmp->next;
    }
    return tmp->str;
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
