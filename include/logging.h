#ifndef _LOGGING_H
#define _LOGGING_H

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
enum LEVEL{NOTSET, DEBUG=10, INFO=20, WARNING=30, ERROR=40, CRITICAL=50};

time_t CURTIME;

#endif