#ifndef _SPLIT_H_
#define _SPLIT_H_

typedef struct node{
    struct node *next;
    char *pstr;
    size_t len;
}STRLIST;

int split(char *str, const char *delim, STRLIST *str_list);
char *splitem(int idx, STRLIST *str_list);

#endif
