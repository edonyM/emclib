#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "color.h"

void redprintf(const char * formated_str) {
    size_t len_formated_str = strlen(formated_str);
    size_t len_output = len_formated_str + strlen(RED) + strlen(NONE) + 1;
    char * output  = (char*)malloc(len_output);

    int n = snprintf(output, len_output, "%s%s%s", RED, formated_str, NONE);

    if (n < 0) {
    printf("ERROR: cannot colorprint\n");
    } else{
    printf("%s\n", output);
    }

    free(output);
}

void greenprintf(const char * formated_str) {
    size_t len_formated_str = strlen(formated_str);
    size_t len_output = len_formated_str + strlen(GREEN) + strlen(NONE) + 1;
    char * output  = (char*)malloc(len_output);

    int n = snprintf(output, len_output, "%s%s%s", GREEN, formated_str, NONE);

    if (n < 0) {
    printf("ERROR: cannot colorprint\n");
    } else{
    printf("%s\n", output);
    }

    free(output);
}

void blueprintf(const char * formated_str) {
    size_t len_formated_str = strlen(formated_str);
    size_t len_output = len_formated_str + strlen(BLUE) + strlen(NONE) + 1;
    char * output  = (char*)malloc(len_output);

    int n = snprintf(output, len_output, "%s%s%s", BLUE, formated_str, NONE);

    if (n < 0) {
    printf("ERROR: cannot colorprint\n");
    } else{
    printf("%s\n", output);
    }

    free(output);
}
