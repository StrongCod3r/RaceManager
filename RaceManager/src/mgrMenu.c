/*
 * File:        mgrMenu.c
 * Description: Contains the user interface functionality for the Race Manager application
 * 				Basically, it implements the different menus that will be displayed on the screen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mgrMenu.h"
#include "operations.h"
#include "races.h"
#include "helpers.h"

/* 
 * Function:    mgrMenu_mainMenu
 * Description: Displays the Race Manager main menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char mgrMenu_mainMenu()
{
	int version;
	char option;
	
	helpers_clearScreen();
	
	version = ops_getVersion();
	
	printf("\nWelcome to the UOC Race Manager application!\n");
	printf("\n------------------------------------\n\n");
	printf("Library version: %d\n\n", version);
	
	printf("Please, select a menu option:\n\n");
	printf("1. Create a new race \n");
    printf("2. List all races \n");
	printf("\n");
	printf("0. Exit\n\n");
	
	option = helpers_getOption();
	
	return option;
}


/* 
 * Function:    mgrMenu_newRace
 * Description: Requests the parameters to add a new race
 * Arguments:   ---
 * Returns:     The race with its information to add into the database.
 */
tRace * mgrMenu_newRace()
{
	char name[MAX_NAME_LENGTH];
	char province[MAX_LOCATION_LENGTH];
	char location[MAX_LOCATION_LENGTH];
	int distance;
	tDateTime dateTime;
	tRace * retValue;
	
	helpers_clearScreen();
	
	printf("\nCreate a new race\n");
	printf("\n-----------------\n\n");
	
	// The parameters we need are the name of the race, the province where it takes place and its concrete location,
	// The total distance of the race in meters and the date and time of the race.
	memset(name, 0, MAX_NAME_LENGTH);
	memset(province, 0, MAX_LOCATION_LENGTH);
	memset(location, 0, MAX_LOCATION_LENGTH);
		
	printf("\nName of the race:        ");
	helpers_scanText(name, MAX_NAME_LENGTH);
	
	printf("\nSelect the province:     ");
	helpers_scanText(province, MAX_LOCATION_LENGTH);
	
	printf("\nLocation:                ");
	helpers_scanText(location, MAX_LOCATION_LENGTH);
	
	printf("\nDistance in meters:      ");
	helpers_scanInt(&distance);
	
	printf("\nDate (yyyy/mm/dd hh:mm): ");
	helpers_scanDateTime(&dateTime);
	
	retValue = (tRace *)malloc(sizeof(tRace));
	races_initializeRaceStruct(retValue);
	strcpy(retValue->name, name);
	strcpy(retValue->province, province);
	strcpy(retValue->location, location);
	retValue->distance = distance;
	retValue->dateTime.year = dateTime.year;
	retValue->dateTime.month = dateTime.month;
	retValue->dateTime.day = dateTime.day;
	retValue->dateTime.hour = dateTime.hour;
	retValue->dateTime.minute = dateTime.minute;
	
	return retValue;
}


/* 
 * Function:    mgrMenu_listAll
 * Description: Displays a list with all the races registered in the database.
 * 				After listing, user can select a race to display its information.
 * Arguments:   ---
 * Returns:     The selected index.
 */
int mgrMenu_listAll()
{
	tRace * currentRace;
	int option;
	int i;
	
	helpers_clearScreen();
	
	printf("\nList of registered races\n");
	printf("\n------------------------\n\n");
	
	currentRace = races_firstRace;
	i = 1;
	
	if (strcmp(currentRace->name, "") ==0)
	{
		printf("\nThere are no races registered yet.\n");
		helpers_pressAnyKey();
		return 0;
	}
	
	printf("%03d - %s\n", i, currentRace->name);
	
	while (currentRace->nextRace != NULL)
	{
		i++;
		currentRace = currentRace->nextRace;
		printf("%03d - %s\n", i, currentRace->name);
	}
	
	printf("\nSelect a race to display its information (0 to return to main menu)\n\n");
	
	scanf("%d", &option);
	fflush(stdin);
	
	return option;
}


/* 
 * Function:    mgrMenu_information
 * Description: It displays the current race information.
 * Arguments:   index: The race database identifier.
 * Returns:     The option of the sub-menu the user has selected.
 */
int mgrMenu_information(tRace * race)
{
	int option;
	
	helpers_clearScreen();
	
	printf("\nRace information:\n");
	printf("\n-----------------\n\n");
	
	if (!strcmp("", race->name))
	{
		// The index is not a valid one. Display the error and exit.
		printf("Race does not exist\n");
	}
	else
	{
		// We found it, display its information
		printf("Name:      %s\n", race->name);
		printf("Province:  %s\n", race->province);
		printf("Location:  %s\n", race->location);
		printf("Distance:  %d\n", race->distance);
		printf("DateTime:  %04d/%02d/%02d %02d:%02d\n", race->dateTime.year, 
														race->dateTime.month, 
														race->dateTime.day, 
														race->dateTime.hour, 
														race->dateTime.minute);
	}

	
	printf("\n\nPlease, select a menu option:\n\n");
	printf("1. List the registered users \n");
	printf("2. Update runners times\n");
	printf("\n");
	printf("0. Exit\n\n");
	
	option = helpers_getOption();
	
	return option;
}


