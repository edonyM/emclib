#ifndef _EMSTR_H_
#define _EMSTR_H_

#define ERR  -1

typedef struct _emstr{
    char *pstr;
    size_t len;
}emstring;

typedef struct node{
    struct node *next;
    //char *pstr;
    //size_t len;
    emstring *str;
}STRLIST;

int append(STRLIST *str_list, char *instr);
int destroy(STRLIST *str_list);

// split string interface
int split(char *str, const char *delim, STRLIST *str_list);
emstring *splitem(int idx, STRLIST *str_list);

// join string interface
char *join(const char *str, char *delim);
#endif
