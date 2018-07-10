#ifndef _TESTLIB_H_
#define _TESTLIB_H_


char opsTest_text[128];
char opsTest_char;
int opsTest_int;
int opsTest_year;
int opsTest_month;
int opsTest_day;
int opsTest_hour;
int opsTest_minute;
int opsTest_second;

/* The Test Counters */
int testLib_totalTests;
int testLib_okTests;
int testLib_failTests;

void testLib_intEqual(int expected, int actual, char * message);
void testLib_doubleEqual(double expected, double actual, char * message);
void testLib_stringEqual(char * expected, char * actual, char * message);
void testLib_pointerEqual(void * expected, void * actual, char * message);

void testLib_printResult();

#endif