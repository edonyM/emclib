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
 * CRITICAL 50
 * ERROR    40
 * WARNING  30
 * INFO     20
 * DEBUG    10
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

#define PRINTFILE(format, ...) \
        fprintf(stdout, "[%s %s] %s(line %d, %s): " format, \
                __DATE__, __TIME__, __FILENAME__, \
                __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define DEBUG(func, format, ...) \
        time(&CURTIME); \
        struct tm *lcl_tm=localtime(&CURTIME); \
        fprintf(stdout, "[%d-%d-%d %d:%d:%d] <INFO> %s(line %d, %s): " format, \
                lcl_tm->tm_year+1900, lcl_tm->tm_mon, lcl_tm->tm_mday, \
                lcl_tm->tm_hour, lcl_tm->tm_min,lcl_tm->tm_sec, \
                __FILENAME__, __LINE__, func, ##__VA_ARGS__)

#define INFO(format, ...) \
        fprintf(stdout, "[%s %s] <INFO> %s(line %d, %s): " format, \
                __DATE__, __TIME__, __FILENAME__, \
                __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define WARNING(format, ...) \
        fprintf(stdout, "[%s %s] <WARNING> %s(line %d, %s): " format, \
                __DATE__, __TIME__, __FILENAME__, \
                __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define ERROR(format, ...) \
        fprintf(stdout, "[%s %s] <ERROR> %s(line %d, %s): " format, \
                __DATE__, __TIME__, __FILENAME__, \
                __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define CRITICAL(format, ...) \
        fprintf(stdout, "[%s %s] <ERROR> %s(line %d, %s): " format, \
                __DATE__, __TIME__, __FILENAME__, \
                __LINE__, __FUNCTION__, ##__VA_ARGS__)
/*
#define ERR(format, ...) fprintf(stderr, "SRC_LINE=%d " format, __LINE__, ##__VA_ARGS__)
*/

void print_info(int level, const char *func, const char *fmt, ...)
{
	if (level == DEBUG)
	{
		char aMsgBuffer[MAX_LOG_LEN]={0};
		va_list argptr;

		va_start (argptr, fmt);
		(void)vsnprintf(aMsgBuffer, sizeof(aMsgBuffer) - 1, fmt, argptr);
		va_end (argptr);
		aMsgBuffer[sizeof(aMsgBuffer)-1] = '\0';
		DEBUG(func, "%s", aMsgBuffer);
	}
}

#define logging(level, fmt, ...) (print_info(level, __FUNCTION__, fmt, ##__VA_ARGS__))

void test(int d) {
    print_info(DEBUG, __FUNCTION__, "I'm OK, %d\n", d);
    logging(DEBUG, "I'm test, %d\n", d+111);
}

int main() {
    INFO("I'm %d\n", 12);
    int level = DEBUG;

    sleep(10);
    print_info(level, __FUNCTION__, "I'm edony %d\n", 111);
    test(128);
    sleep(5);
    logging(level, "EDONY is %d\n", 1024);
}