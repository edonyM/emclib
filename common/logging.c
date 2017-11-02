 /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 #        .---.         .-----------
 #       /     \  __  /    ------
 #      / /     \(  )/    -----   (`-')  _ _(`-')              <-. (`-')_
 #     //////    '\/ `   ---      ( OO).-/( (OO ).->     .->      \( OO) )     .->
 #    //// / //  :   : ---      (,------. \    .'_ (`-')----. ,--./ ,--/  ,--.'  ,-.
 #   // /   /  / `\/ '--         |  .---' '`'-..__)( OO).-. ' |   \ |  | (`-')'.'  /
 #  //          //..\\          (|  '--.  |  |  ' |( _) | | | |  . '|  |)(OO \    /
 # ============UU====UU====      |  .--'  |  |  / : \|  |)| | |  |\    |  |  /   /)
 #             '//||\\`          |  `---. |  '-'  /  '  '-' ' |  | \   |  `-/   /`
 #               ''``            `------' `------'    `-----' `--'  `--'    `--'
 # ######################################################################################
 #
 # Author: edony - edonyzpc@gmail.com
 #
 # twitter : @edonyzpc
 #
 # Last modified: 2017-10-30 22:39
 #
 # Filename: logging.c
 #
 # Description: All Rights Are Reserved
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/* LOG LEVEL
 * Level    Numeric value
 * CRITICAL 5
 * ERROR    4
 * WARNING  3
 * INFO     2
 * DEBUG    1
 * NOTSET   0
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>

#include <logging.h>

#define MAX_LOG_LEN 4096
//  general facilities
#if defined(_WIN32) || defined(_WIN64)
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#endif
#ifndef __FILENAME__
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif
#define _PRINT_(f, format, ...) fprintf(f, format, ##__VA_ARGS__)
#define _PRINT_C(format, ...) _PRINT_(stdout, format, ##__VA_ARGS__)
#define _PRINT_E(format, ...) _PRINT_(stderr, format, ##__VA_ARGS__)
#define _PRINT_F(format, ...) _PRINT_(LOGFILE, format, ##__VA_ARGS__)

/* default logging */
// log into stdout
#define _FMT_C(LEVEL, line, func) \
        time(&CURTIME); \
        CURTIME_tm=localtime(&CURTIME); \
        _PRINT_C("[%d-%d-%d %d:%d:%d] <%s> %s(line %d, %s): ", \
                CURTIME_tm->tm_year+1900, CURTIME_tm->tm_mon, CURTIME_tm->tm_mday, \
                CURTIME_tm->tm_hour, CURTIME_tm->tm_min, CURTIME_tm->tm_sec, \
                LEVEL, __FILENAME__, line, func)

#define FMT_C(format, ...) _PRINT_C(format, ##__VA_ARGS__)

// log into file
#define _FMT_F(LEVEL, line, func) \
        time(&CURTIME); \
        CURTIME_tm=localtime(&CURTIME); \
        _PRINT_F("[%d-%d-%d %d:%d:%d] <%s> %s(line %d, %s): ", \
                CURTIME_tm->tm_year+1900, CURTIME_tm->tm_mon, CURTIME_tm->tm_mday, \
                CURTIME_tm->tm_hour, CURTIME_tm->tm_min, CURTIME_tm->tm_sec, \
                LEVEL, __FILENAME__, line, func)

#define FMT_F(format, ...) _PRINT_F(format, ##__VA_ARGS__)

// default logging
#define _LOG_C(level, line, func, format, ...) \
        _FMT_C(level, line, func); \
        _PRINT_C(format, ##__VA_ARGS__)

#define _LOG_F(level, line, func, format, ...) \
        _FMT_F(level, line, func); \
        _PRINT_F(format, ##__VA_ARGS__)

void print_c(int level, int line, const char *func, const char *fmt, ...)
{
    char aMsgBuffer[MAX_LOG_LEN]={0};
    va_list argptr;

    va_start (argptr, fmt);
    (void)vsnprintf(aMsgBuffer, sizeof(aMsgBuffer) - 1, fmt, argptr);
    va_end (argptr);
    aMsgBuffer[sizeof(aMsgBuffer)-1] = '\0';

    char L[9] = {0};
    switch (level) {
        case NOTSET:
            strcpy(L, "ALL");
            //_LOG_C("ALL", line, func, "%s", aMsgBuffer);
            break;
        case DEBUG:
            strcpy(L, "DEBUG");
            //_LOG_C("DEBUG", line, func, "%s", aMsgBuffer);
            break;
        case INFO:
            strcpy(L, "INFO");
            //_LOG_C("INFO", line, func, "%s", aMsgBuffer);
            break;
        case WARNING:
            strcpy(L, "WARNING");
            //_LOG_C("WARNING", line, func, "%s", aMsgBuffer);
            break;
        case ERROR:
            strcpy(L, "ERROR");
            //_LOG_C("ERROR", line, func, "%s", aMsgBuffer);
            break;
        case CRITICAL:
            strcpy(L, "CRITICAL");
            //_LOG_C("CRITICAL", line, func, "%s", aMsgBuffer);
            break;
        default:
            strcpy(L, "ALL");
            _PRINT_C("Log Level Not Set And Log All\n");
    }
    _LOG_C(L, line, func, "%s", aMsgBuffer);
}

void print_f(const char *filename, int level, int line, const char *func, const char *fmt, ...)
{
    if (NULL == filename)
        return;
    if (!LOGFILE)
        LOGFILE = fopen(filename, "a+");
    char aMsgBuffer[MAX_LOG_LEN]={0};
    va_list argptr;

    va_start (argptr, fmt);
    (void)vsnprintf(aMsgBuffer, sizeof(aMsgBuffer) - 1, fmt, argptr);
    va_end (argptr);
    aMsgBuffer[sizeof(aMsgBuffer)-1] = '\0';

    char L[9] = {0};
    switch (level) {
        case NOTSET:
            strcpy(L, "ALL");
            //_LOG_C("ALL", line, func, "%s", aMsgBuffer);
            break;
        case DEBUG:
            strcpy(L, "DEBUG");
            //_LOG_C("DEBUG", line, func, "%s", aMsgBuffer);
            break;
        case INFO:
            strcpy(L, "INFO");
            //_LOG_C("INFO", line, func, "%s", aMsgBuffer);
            break;
        case WARNING:
            strcpy(L, "WARNING");
            //_LOG_C("WARNING", line, func, "%s", aMsgBuffer);
            break;
        case ERROR:
            strcpy(L, "ERROR");
            //_LOG_C("ERROR", line, func, "%s", aMsgBuffer);
            break;
        case CRITICAL:
            strcpy(L, "CRITICAL");
            //_LOG_C("CRITICAL", line, func, "%s", aMsgBuffer);
            break;
        default:
            strcpy(L, "ALL");
            _PRINT_C("Log Level Not Set And Log All\n");
    }
    _LOG_F(L, line, func, "%s", aMsgBuffer);
}

#define log(fmt, ...) print_c(NOTSET, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define debug(fmt, ...) print_c(DEBUG, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define info(fmt, ...) print_c(INFO, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define warning(fmt, ...) print_c(WARNING, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define error(fmt, ...) print_c(ERROR, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define critical(fmt, ...) print_c(CRITICAL, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)

#define flog(filename, fmt, ...) print_f(filename, NOTSET, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define fdebug(filename, fmt, ...) print_f(filename, DEBUG, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define finfo(filename, fmt, ...) print_f(filename, INFO, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define fwarning(filename, fmt, ...) print_f(filename, WARNING, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define ferror(filename, fmt, ...) print_f(filename, ERROR, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)
#define fcritical(filename, fmt, ...) print_f(filename, CRITICAL, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__)


void test(int d) {
    debug("I'm test, %d\n", d+111);
}


int main() {
    test(128);
    sleep(5);
    info("EDONY is %d\n", 1024);
    char *f = "log.txt";
    finfo(f, "writing to file %p\n", f);
}