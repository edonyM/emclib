#ifndef _LOGGING_H
#define _LOGGING_H

#include <stdio.h>
#include <time.h>

/*
 * Level    Numeric value
 * CRITICAL 50
 * ERROR    40
 * WARNING  30
 * INFO     20
 * DEBUG    10
 * NOTSET   0
 */
enum LEVEL{NOTSET=0, DEBUG, INFO, WARNING, ERROR, CRITICAL};

time_t CURTIME;
struct tm *CURTIME_tm;

FILE *LOGFILE = NULL;

struct log_cfg {
    unsigned int level;     // log level(e.g. enum LEVEL)
    unsigned int log2file;  // log into file(0 for no, 1 for yes)
    const char *filename;   // if log2file flag set, filename is needed
}LOGCFG={INFO, 0, NULL};
void set_level(unsigned int level, struct log_cfg *LOGCFG);
unsigned int get_level(struct log_cfg *LOGCFG);
void set_logfile(char *filename);
const char* get_logfile(struct log_cfg *logcfg);
#endif