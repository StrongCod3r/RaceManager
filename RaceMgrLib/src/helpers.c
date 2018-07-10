/*
 * File:        helpers.c
 * Description: Contains some auxilliar common functions.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "helpers.h"
#include "operations.h"

#ifdef TESTS
#include "testLib.h"
#endif

/*
 * Function:    helpers_clearScreen
 * Description: Used to clear the output screen
 * Arguments:   ---
 * Returns:     ---
 */
void helpers_clearScreen()
{
#ifndef TESTS	
	// Windows users: please, use system("cls");
	system("cls");
	
	// Linux users: please, comment previous line and use system("clear");
	// system("clear");
#endif	
}

/*
 * Function:    helpers_getOption
 * Description: reads a key input from the user.
 * Arguments:   ---
 * Returns:     The character pressed by the user
 */
char helpers_getOption()
{
#ifndef TESTS	
	char retValue;

	retValue = getchar();
	fflush(stdin);

	return retValue;
#else 
	return opsTest_char;
#endif	
}


/*
 * Function:    helpers_pressAnyKey
 * Description: waits until user presses any key
 * Arguments:   ---
 * Returns:     ---
 */
void helpers_pressAnyKey()
{
	printf("\nPress any key to continue.\n");

#ifndef TESTS	
	getchar();
	fflush(stdin);
#endif
}

/*
 * Function:    helpers_scanText
 * Description: Parses and gets an string manually introduced by the user until it presses the Enter.
 * Arguments:   property: Upon return, the pointer to the captured string
 * 			    maxValue: The maximum string length to parse.
 * Returns:     ---
 */
void helpers_scanText(char * property, int maxValue)
{
#ifndef TESTS	
	int i;
	char c;
	
	i = 0;
	c = getchar();
	while ((i < maxValue - 1) && (c != '\n'))
	{
		// Concatenate the characters until 'Enter' or string maximum length
		property[i] = c;
		i++;
		c = getchar();
	}
	
	fflush(stdin);
#else 
	strcpy(property, opsTest_text);
#endif	
}

/*
 * Function:    helpers_scanInt
 * Description: Parses and gets an integer value manually introduced by the user.
 * Arguments:   retValue: Upon return, the captured integer value
 * Returns:     ---
 */
void helpers_scanInt(int * retValue)
{
#ifndef TESTS	
	scanf("%d", retValue);
	fflush(stdin);
#else 
	*retValue = opsTest_int;
#endif	
}


/*
 * Function:    helpers_scanDateTime
 * Description: Parses and gets a datetime in format yyyy/mm/dd hh:mm
 * Arguments:   retValue: Upon return, the captured datetime
 * Returns:     ---
 */
void helpers_scanDateTime(tDateTime * retValue)
{
#ifndef TESTS	
	scanf("%d/%d/%d %d:%d", &retValue->year, &retValue->month, &retValue->day, &retValue->hour, &retValue->minute);
	fflush(stdin);
#else 
	retValue->year = opsTest_year;
	retValue->month = opsTest_month;
	retValue->day = opsTest_day;
	retValue->hour = opsTest_hour;
	retValue->minute = opsTest_minute;
#endif	
}


/*
 * Function:    helpers_scanTime
 * Description: Parses and gets a time in format hh:mm:ss
 * Arguments:   retValue: Upon return, the captured time
 * Returns:     ---
 */
void helpers_scanTime(tTime * retValue)
{
#ifndef TESTS	
	scanf("%d:%d:%d", &retValue->hours, &retValue->minutes, &retValue->seconds);
	fflush(stdin);
#else 
	retValue->hours = opsTest_hour;
	retValue->minutes = opsTest_minute;
	retValue->seconds = opsTest_second;
#endif	
}

/*
 * Function:    helpers_scanFromFile
 * Description: Parses and gets an string written on a file until finding a new line.
 * Arguments:   inputFile: The file pointer
 * 			    maxValue: The maximum string length to parse.
 * Returns:     The pointer to the captured string
 */
char * helpers_scanFromFile(FILE * inputFile, int maxValue)
{
	int i;
	char c;
	char * retValue;
	
	retValue = (char *)malloc(maxValue);
	memset(retValue, 0, maxValue);
	
	i = 0;
	c = fgetc(inputFile);
	
	while ((i < maxValue - 1) && (c != '\n') && (c != EOF))
	{
		// Concatenate the characters until finding a new line, string maximum length or no more data in the file
		retValue[i] = c;
		i++;
		c = getc(inputFile);
	}
	
	return retValue;
}


/*
 * Function:    helpers_copyFile
 * Description: Copies the content of a file into another file
 * Arguments:   inFile: The file with the contents to copy
 *              outFile: The destination file pointer
 * Returns:     ---
 */
void helpers_copyFile(FILE * inFile, FILE * outFile)
{
	char c;
	
	c = fgetc(inFile);
	while (c != EOF)
	{
		fputc(c, outFile);
		c = fgetc(inFile);
	}
}
