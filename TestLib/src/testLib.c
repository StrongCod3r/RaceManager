/*
 * File:        testLib.c
 * Description: This library provides functionality to compare the actual returned values of the function
 * 				with the expected ones.
 */
#include "testLib.h"
#include <stdio.h>
#include <string.h>

/*
 * Function: 	testLib_intEqual
 * Description: Compares two integer values
 * Arguments: 	expected: The expected value to compare
 * 				actual: The actual retrieved value.
 * 				message: A short identifier of the test to execute.
 * Returns: 	---
 */
void testLib_intEqual(int expected, int actual, char * message)
{
	testLib_totalTests++;
	
	if (expected == actual)
	{
		testLib_okTests++;
		printf("%03d - %s --> OK\n", testLib_totalTests, message);
	}
	else
	{
		testLib_failTests++;
		printf("%03d - %s --> FAIL. Expected: '%d', Received: '%d'\n", testLib_totalTests, message, expected, actual);
	}
}

/*
 * Function: 	testLib_doubleEqual
 * Description: Compares two floating values
 * Arguments: 	expected: The expected value to compare
 * 				actual: The actual retrieved value.
 * 				message: A short identifier of the test to execute.
 * Returns: 	---
 */
void testLib_doubleEqual(double expected, double actual, char * message)
{
	testLib_totalTests++;
	
	if (expected == actual)
	{
		testLib_okTests++;
		printf("%03d - %s --> OK\n", testLib_totalTests, message);
	}
	else
	{
		testLib_failTests++;
		printf("%03d - %s --> FAIL. Expected: '%f', Received: '%f'\n", testLib_totalTests, message, expected, actual);
	}
}

/*
 * Function: 	testLib_stringEqual
 * Description: Compares two string values
 * Arguments: 	expected: The expected value to compare
 * 				actual: The actual retrieved value.
 * 				message: A short identifier of the test to execute.
 * Returns: 	---
 */
void testLib_stringEqual(char * expected, char * actual, char * message)
{
	testLib_totalTests++;
	
	
	if (!strcmp(expected, actual))
	{
		testLib_okTests++;
		printf("%03d - %s --> OK\n", testLib_totalTests, message);
	}
	else
	{
		testLib_failTests++;
		printf("%03d - %s --> FAIL. Expected: '%s', Received: '%s'\n", testLib_totalTests, message, expected, actual);
	}
}

/*
 * Function: 	testLib_pointerEqual
 * Description: Compares two pointer values
 * Arguments: 	expected: The expected value to compare
 * 				actual: The actual retrieved value.
 * 				message: A short identifier of the test to execute.
 * Returns: 	---
 */
void testLib_pointerEqual(void * expected, void * actual, char * message)
{
	testLib_totalTests++;
	
	if (expected == actual)
	{
		testLib_okTests++;
		printf("%03d - %s --> OK\n", testLib_totalTests, message);
	}
	else
	{
		testLib_failTests++;
		printf("%03d - %s --> FAIL. Pointers are different\n", testLib_totalTests, message);
	}
}

/*
 * Function: 	testLib_printResult
 * Description: Dumps the final summary of all the executed tests, how many of them passed and how many failed.
 * Arguments: 	---
 * Returns: 	---
 */
void testLib_printResult()
{
	
	printf("\n");
	printf("=================================================\n");
	printf("====            TESTS SUMMARY                ====\n");
	printf("=================================================\n");	
	printf("\n");
	printf("Executed: %d\n", testLib_totalTests);
	printf("OK:       %d\n", testLib_okTests);
	printf("Failed:   %d\n", testLib_failTests);
	printf("\n");
	
	printf("Press any key to continue\n");
	getchar();
}