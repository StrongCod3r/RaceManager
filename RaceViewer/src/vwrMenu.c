/*
 * File:        vwrMenu.c
 * Description: Contains the user interface functionality for the Race Viewer application
 * 				Basically, it implements the different menus that will be displayed on the screen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vwrMenu.h"
#include "operations.h"
#include "races.h"
#include "helpers.h"
#include "runners.h"

/* 
 * Function:    vwrMenu_mainMenu
 * Description: Displays the Race Viewer main menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char vwrMenu_mainMenu()
{
	int version;
	char option;
	
	helpers_clearScreen();
	
	version = ops_getVersion();
	
	printf("\nWelcome to the UOC Race Viewer application!\n");
	printf("\n------------------------------------\n\n");
	printf("Library version: %d\n\n", version);
	
	printf("Please, select a menu option:\n\n");
	printf("1. List all races \n");
	printf("2. View subscribed races\n");
	printf("\n");
	printf("0. Exit\n\n");
	
	option = helpers_getOption();
	
	return option;
}


/* 
 * Function:    vwrMenu_listAll
 * Description: Displays a list with all the races registered in the database.
 * 				After listing, user can select a race to display its information.
 * Arguments:   ---
 * Returns:     The selected index.
 */
int vwrMenu_listAll()
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
 * Function:    vwrMenu_information
 * Description: It displays the current race information.
 * Arguments:   index: The race database identifier.
 * Returns:     The option of the sub-menu the user has selected.
 */
char vwrMenu_information(tRace * race)
{
	char option;
	
	vwrMenu_raceInformation(race);

	printf("\n\nPlease, select a menu option:\n\n");
	printf("1. Subscribe to this race \n");
	printf("2. List the registered users \n");
	printf("3. List the times\n");
	printf("\n");
	printf("0. Exit\n\n");
	
	option = helpers_getOption();
	
	return option;
}

/* 
 * Function:    vwrMenu_raceInformation
 * Description: Sub-method to display the current race information.
 * Arguments:   index: The race database identifier.
 * Returns:     ---
 */
void vwrMenu_raceInformation(tRace * race)
{
	helpers_clearScreen();
	
	printf("\nRace information:\n");
	printf("\n-----------------\n\n");
	
	if (strcmp("", race->name) != 0)
	{
		// Display its information
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
}



/* 
 * Function:    vwrMenu_subscribe
 * Description: Requests the user parameters in order to subscribe to a race
 * Arguments:   ---
 * Returns:     The struct with the runner information to subscribe to a race.
 */
tRunner * vwrMenu_subscribe()
{
	char name[MAX_NAME_LENGTH];
	char surname[MAX_NAME_LENGTH];
	int age;
	char nationality[MAX_LOCATION_LENGTH];
	char dni[MAX_DNI_LENGTH];
	tRunner * retValue;
	
	helpers_clearScreen();
	
	printf("\nCreate a new race\n");
	printf("\n-----------------\n\n");
	
	// The parameters we need are the name of the race, the province where it takes place and its concrete location,
	// The total distance of the race in meters and the date and time of the race.
	memset(name, 0, MAX_NAME_LENGTH);
	memset(surname, 0, MAX_LOCATION_LENGTH);
	memset(nationality, 0, MAX_LOCATION_LENGTH);
	memset(dni, 0, MAX_DNI_LENGTH);
		
	printf("\nName:        ");
	helpers_scanText(name, MAX_NAME_LENGTH);
	
	printf("\nSurname:     ");
	helpers_scanText(surname, MAX_NAME_LENGTH);
	
	printf("\nNationality: ");
	helpers_scanText(nationality, MAX_LOCATION_LENGTH);
	
	printf("\nAge:         ");
	helpers_scanInt(&age);
	
	printf("\nD.N.I.:      ");
	helpers_scanText(dni, MAX_DNI_LENGTH);
	
	retValue = (tRunner *)malloc(sizeof(tRunner));
	strcpy(retValue->name, name);
	strcpy(retValue->surname, surname);
	strcpy(retValue->nationality, nationality);
	strcpy(retValue->dni, dni);
	retValue->age = age;
	retValue->nextRunner = NULL;

	return retValue;
}

/* 
 * Function:    vwrMenu_filterRaces
 * Description: Displays the list of races a user has registered to.
 * Arguments:   ---
 * Returns:     After listing, the user can select one of the races to display its extended information
 */
int vwrMenu_filterRaces()
{
	char dni[MAX_DNI_LENGTH];
	tRace * currentRace;
	int option;
	int i;
	
	memset(dni, 0, MAX_DNI_LENGTH);
	
	helpers_clearScreen();
	printf("\n\nEnter your dni:    ");
	helpers_scanText(dni, MAX_DNI_LENGTH);
	
	helpers_clearScreen();
	
	currentRace = races_firstRace;
	i = 1;
	
	printf("\n\nList of races you subscribed:\n\n");
	if (strcmp(currentRace->name, "") ==0)
	{
		helpers_pressAnyKey();
		return 0;
	}
	
	
	if (ops_isRunnerInRace(currentRace, dni))
	{
		printf("%03d - %s\n", i, currentRace->name);	
	}
	
	
	while (currentRace->nextRace != NULL)
	{
		i++;
		currentRace = currentRace->nextRace;
		if (ops_isRunnerInRace(currentRace, dni))
		{
			printf("%03d - %s\n", i, currentRace->name);	
		}
	}
	printf("\nSelect a race to display its information (0 to return to main menu)\n\n");
	
	scanf("%d", &option);
	fflush(stdin);
	
	return option;

}