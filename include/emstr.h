#ifndef _EMSTR_H_
#define _EMSTR_H_

typedef struct _emstr{
    char *pstr;
    size_t len;
}emstr;

typedef struct node{
    struct node *next;
    char *pstr;
    size_t len;
}STRLIST;

// split string interface
int split(char *str, const char *delim, STRLIST *str_list);
char *splitem(int idx, STRLIST *str_list);

// join string interface
char *join(const char *str, char *delim);
#endif
