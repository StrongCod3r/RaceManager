/*
 * File:        tests.c
 * Description: Contains the tests of the operations implemented in the main application
 */
 
#include <stdlib.h>
#include <string.h>
 
#include "mgrMain.h"
#include "mgrMenu.h"
#include "mgrTests.h"
#include "races.h"

#include "testLib.h"

/* if the Pre-Processor variable TESTS is defined, we will execute the tests instead. */
#ifdef TESTS 

/* 
 * Function:    main
 * Description: Tests entry method
 * Arguments:   ---
 * Returns:     0 always.
 */
int main(int argc, char **argv)
{
	/* Initialize the counters */
	testLib_okTests = 0;
	testLib_failTests = 0;
	testLib_totalTests = 0;
	
	/* Execute the tests */
	mgrTests_executeTests();
	
	/* Dump the results */
	testLib_printResult();
	
	return 0;
}

/* 
 * Function: 	mgrTests_executeTests
 * Description: Here we add the list of tests that will be executed.
 * Arguments: 	---
 * Returns: 	---
 */
void mgrTests_executeTests()
{
	mgrTests_newRaceTest();
	mgrTests_addNewRaceTest();
	mgrTests_getLastRaceTest();
	mgrTests_getRaceTest();
	mgrTests_checkNameTest();
	mgrTests_checkProvinceTest();
	mgrTests_checkLocationTest();
	mgrTests_checkDistanceTest();
	mgrTests_checkDateTimeTest();
}

/* 
 * Function: 	mgrTests_newRaceTest
 * Description: A test for mgrMenu_newRace() operation
 * Arguments: 	---
 * Returns: 	---
 */
void mgrTests_newRaceTest()
{
	tRace * actual;
	
	strcpy(opsTest_text, "Barcelona");
	opsTest_int = 2000;
	
	opsTest_year = 2016;
	opsTest_month = 2;
	opsTest_day = 27;
	opsTest_hour = 17;
	opsTest_minute = 00;
	
	// We create a valid race and check that all the fields have been correctly filled.
	actual = mgrMenu_newRace();
	
	testLib_stringEqual("Barcelona", actual->name, "New race test");
	testLib_stringEqual("Barcelona", actual->province, "New race test");
	testLib_stringEqual("Barcelona", actual->location, "New race test");
	testLib_intEqual(2000, actual->distance, "New race test");
	testLib_intEqual(2016, actual->dateTime.year, "New race test");
	testLib_intEqual(2, actual->dateTime.month, "New race test");
	testLib_intEqual(27, actual->dateTime.day, "New race test");
	testLib_intEqual(17, actual->dateTime.hour, "New race test");
	testLib_intEqual(00, actual->dateTime.minute, "New race test");
	
	free(actual);
}

/* 
 * Function: 	mgrTests_addNewRaceTest
 * Description: A test for races_addNewRace() operation
 * Arguments: 	---
 * Returns: 	---
 */
void mgrTests_addNewRaceTest()
{
	tRace * race, * race2, * race3, * race4;
	raceError actual;
	
	races_firstRace = (tRace *)malloc(sizeof(tRace));
	races_initializeRaceStruct(races_firstRace);
	
	strcpy(opsTest_text, "Barcelona");
	opsTest_int = 2000;
	opsTest_year = 2016;
	opsTest_month = 2;
	opsTest_day = 27;
	opsTest_hour = 17;
	opsTest_minute = 00;
	
	// The very first time, everything should be OK.
	race = mgrMenu_newRace();
	actual = races_addNewRace(race);
	testLib_intEqual(RACE_NOERR, actual, "Add new race test");
	
	// If we add again the same race, an already exists error should appear.
	race2 = mgrMenu_newRace();
	actual = races_addNewRace(race2);
	testLib_intEqual(RACE_ALREADY_EXISTS, actual, "Add new race test");
	
	// The distance is invalid.
	strcpy(opsTest_text, "Tarragona");
	opsTest_int = 100;
	race3 = mgrMenu_newRace();
	actual = races_addNewRace(race3);
	testLib_intEqual(INVALID_DISTANCE, actual, "Add new race test");
	
	// Not a valid month
	opsTest_int = 2000;
	opsTest_month = 13;
	race4 = mgrMenu_newRace();
	actual = races_addNewRace(race4);
	testLib_intEqual(INVALID_DATETIME, actual, "Add new race test");
	
	free(race4);
	free(race3);
	free(race2);
	free(race);
	free(races_firstRace);
}

/* 
 * Function: 	mgrTests_getLastRaceTest
 * Description: A test for races_getLastRace() operation
 * Arguments: 	---
 * Returns: 	---
 */
void mgrTests_getLastRaceTest()
{
	tRace * race, * race2;
	tRace * actual;
	
	races_firstRace = (tRace *)malloc(sizeof(tRace));
	races_initializeRaceStruct(races_firstRace);
	
	strcpy(opsTest_text, "Barcelona");
	opsTest_int = 2000;
	opsTest_year = 2016;
	opsTest_month = 2;
	opsTest_day = 27;
	opsTest_hour = 17;
	opsTest_minute = 00;
	
	// We introduce 2 races and check the operation works fine in both cases.
	race = mgrMenu_newRace();
	races_addNewRace(race);
	actual = races_getLastRace();
	testLib_pointerEqual(race, actual, "Get Last Race");
	
	strcpy(opsTest_text, "Tarragona");
	race2 = mgrMenu_newRace();
	races_addNewRace(race2);
	actual = races_getLastRace();
	testLib_pointerEqual(race2, actual, "Get Last Race");
	
	free(race2);
	free(race);
	free(races_firstRace);
}

/* 
 * Function: 	mgrTests_getRaceTest
 * Description: A test for races_getRace() operation
 * Arguments: 	---
 * Returns: 	---
 */
void mgrTests_getRaceTest()
{
	tRace * race, * race2;
	tRace * actual;
	
	races_firstRace = (tRace *)malloc(sizeof(tRace));
	races_initializeRaceStruct(races_firstRace);
	
	strcpy(opsTest_text, "Barcelona");
	opsTest_int = 2000;
	opsTest_year = 2016;
	opsTest_month = 2;
	opsTest_day = 27;
	opsTest_hour = 17;
	opsTest_minute = 00;
	
	// We add 2 races, and the operation should work fine in both cases.
	race = mgrMenu_newRace();
	races_addNewRace(race);
	
	strcpy(opsTest_text, "Tarragona");
	race2 = mgrMenu_newRace();
	races_addNewRace(race2);
	
	actual = races_getRace(0);
	testLib_pointerEqual(race, actual, "Get race");
	
	actual = races_getRace(1);
	testLib_pointerEqual(race2, actual, "Get race");
	
	free(race2);
	free(race);
	free(races_firstRace);
}

/* 
 * Function: 	mgrTests_checkNameTest
 * Description: A test for races_checkName() operation
 * Arguments: 	---
 * Returns: 	---
 */
void mgrTests_checkNameTest()
{
	tRace * race;
	raceError actual;
	
	races_firstRace = (tRace *)malloc(sizeof(tRace));
	races_initializeRaceStruct(races_firstRace);
	
	// Test the operation with an invalid name
	actual = races_checkName("pp");
	testLib_intEqual(INVALID_NAME, actual, "Check Name");
	
	// In this case everything should work OK
	actual = races_checkName("TestName");
	testLib_intEqual(RACE_NOERR, actual, "Check Name");
	
	races_firstRace = (tRace *)malloc(sizeof(tRace));
	races_initializeRaceStruct(races_firstRace);
	
	strcpy(opsTest_text, "Barcelona");
	opsTest_int = 2000;
	opsTest_year = 2016;
	opsTest_month = 2;
	opsTest_day = 27;
	opsTest_hour = 17;
	opsTest_minute = 00;
	
	race = mgrMenu_newRace();
	races_addNewRace(race);

	// Verify it checks the race is already stored in the database.
	actual = races_checkName("Barcelona");
	testLib_intEqual(RACE_ALREADY_EXISTS, actual, "Check Name");	
	
	free(race);
	free(races_firstRace);
}

/* 
 * Function: 	mgrTests_checkProvinceTest
 * Description: A test for races_checkProvince() operation
 * Arguments: 	---
 * Returns: 	---
 */
void mgrTests_checkProvinceTest()
{
	raceError actual;
	
	// Only a few names can be set.
	actual = races_checkProvince("pp");
	testLib_intEqual(INVALID_PROVINCE, actual, "Check Province");
	
	actual = races_checkProvince("Barcelona");
	testLib_intEqual(RACE_NOERR, actual, "Check Province");
	
	actual = races_checkProvince("Tarragona");
	testLib_intEqual(RACE_NOERR, actual, "Check Province");
	
	actual = races_checkProvince("Lleida");
	testLib_intEqual(RACE_NOERR, actual, "Check Province");
	
	actual = races_checkProvince("Girona");
	testLib_intEqual(RACE_NOERR, actual, "Check Province");
}

/* 
 * Function: 	mgrTests_checkLocationTest
 * Description: A test for races_checkLocation() operation
 * Arguments: 	---
 * Returns: 	---
 */
void mgrTests_checkLocationTest() 
{
	raceError actual;
	
	// Test with an invalid value
	actual = races_checkLocation("pp");
	testLib_intEqual(INVALID_LOCATION, actual, "Check Location");
	
	// Test with a valid value
	actual = races_checkLocation("TestName");
	testLib_intEqual(RACE_NOERR, actual, "Check Location");
}

/* 
 * Function: 	mgrTests_checkDistanceTest
 * Description: A test for races_checkDistance() operation
 * Arguments: 	---
 * Returns: 	---
 */
void mgrTests_checkDistanceTest() 
{
	raceError actual;
	
	// Test with an invalid value
	actual = races_checkDistance(100);
	testLib_intEqual(INVALID_DISTANCE, actual, "Check Distance");
	
	// Test with a valid distance
	actual = races_checkDistance(10000);
	testLib_intEqual(RACE_NOERR, actual, "Check Distance");
}

/* 
 * Function: 	mgrTests_checkDateTimeTest
 * Description: A test for races_checkDateTime() operation
 * Arguments: 	---
 * Returns: 	---
 */
void mgrTests_checkDateTimeTest() 
{
	tDateTime dateTime;
	raceError actual;
	
	dateTime.year = 2016;
	dateTime.month = 02;
	dateTime.day = 30;
	dateTime.hour = 20;
	dateTime.minute = 00;
	
	// February 30th is not a valid date
	actual = races_checkDateTime(dateTime);
	testLib_intEqual(INVALID_DATETIME, actual, "Check DateTime");
	
	// January 30th is a valid date.
	dateTime.month = 1;
	actual = races_checkDateTime(dateTime);
	testLib_intEqual(RACE_NOERR, actual, "Check DateTime");
	
	// We can not use dates before 2016
	dateTime.year = 2010;
	actual = races_checkDateTime(dateTime);
	testLib_intEqual(INVALID_DATETIME, actual, "Check DateTime");
	
	// A day has 24 hours 
	dateTime.year = 2016;
	dateTime.hour = 25;
	actual = races_checkDateTime(dateTime);
	testLib_intEqual(INVALID_DATETIME, actual, "Check DateTime");
	
	// An hour has 60 minutes.
	dateTime.hour = 20;
	dateTime.minute = 65;
	actual = races_checkDateTime(dateTime);
	testLib_intEqual(INVALID_DATETIME, actual, "Check DateTime");
}
#endif