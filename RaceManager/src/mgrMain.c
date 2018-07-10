/*
 * File:        mgrMain.c
 * Description: Contains the main functionality for the application
 */
 
#include <stdio.h>
#include <stdlib.h>

#include "mgrMain.h"
#include "mgrMenu.h"
#include "races.h"
#include "helpers.h"
#include "times.h"

/* if the Pre-Processor variable is not defined, we run the main application executable. */
#ifndef TESTS

/* 
 * Function:    main
 * Description: Application entry method
 * Arguments:   ---
 * Returns:     0 always.
 */
int main(int argc, char **argv)
{
	// Initialize the first entry of the list
	races_firstRace = (tRace *)malloc(sizeof(tRace));
	races_initializeRaceStruct(races_firstRace);
	
	// Load the races information
	ops_loadRacesInformation(races_firstRace);
	
	// Display the main applicaiton menu
	mgrMain_displayMenu();
	return 0;
}

#endif

/* 
 * Function:    mgrMain_displayMenu
 * Description: Displays the Race Manager main menu
 * Arguments:   ---
 * Returns:     ---
 */
void mgrMain_displayMenu()
{
	char option;

	option = mgrMenu_mainMenu();
	
	while (option != '0')
	{
		switch(option)
		{
			case '1':   // Create a new race
				mgrMain_newRace();
				break;
				
			case '2':   // List all races
				mgrMain_listRaces();
				break;
				
			default:
				break;
		}
		option = mgrMenu_mainMenu();
	}
}


/* 
 * Function:    mgrMain_newRace
 * Description: Create a new race
 * Arguments:   ---
 * Returns:     ---
 */
void mgrMain_newRace()
{
	tRace * race;
	raceError err;
	
	// Request values to the user
	race = mgrMenu_newRace();
	err = ops_createRace(race);
	
	// Display the result on screen.
	if (err == RACE_NOERR)
	{
		ops_saveRacesInformation(races_firstRace);
		helpers_clearScreen();
		printf("%s successfully created\n\n", race->name);
		mgrMenu_information(race);
	}
	else
	{
		// Some error ocurred. Display the error.
		free(race);
		printf("\n\n");
		printf("%s\n", races_errMsg(err));
		helpers_pressAnyKey();
	}
}


/* 
 * Function:    mgrMain_listRaces
 * Description: Display all the registered races
 * Arguments:   ---
 * Returns:     ---
 */
void mgrMain_listRaces()
{
	int option;
	int index;
	tRace * race;
	
	option = mgrMenu_listAll();
	
	while (option != 0)
	{
		// Display the extended information of the selected race.
		race = races_getRace(option - 1);
		if (race == NULL)
		{
			printf("\nThe value introduced is not a valid index\n");
			helpers_pressAnyKey();
		}
		else
		{
			index = mgrMenu_information(race);
			if (index == '1')
			{
				// We want to display the subscribed runners in the race.
				mgrMain_listRunners(race);
			}
			else if (index == '2')
			{
				// We want to update runners times.
				mgrMain_updateTimes(race);
			}
		}
		option = mgrMenu_listAll();
	}
}


/* 
 * Function:    mgrMain_listRunners
 * Description: Display the list of runners that are already registered in the race.
 * Arguments:   race: The race to list the runners that already registered.
 * Returns:     ---
 */
void mgrMain_listRunners(tRace * race)
{
	tRunner * currentRunner;
	tRunner * runnersList;
	
	runnersList = ops_loadRunnersList(race);
	currentRunner = runnersList;
	
	helpers_clearScreen();
	printf ("\nRegistered users at %s\n\n", race->name);
	
	while (currentRunner != NULL)
	{
		printf("%s %s (%s)\n", currentRunner->name, currentRunner->surname, currentRunner->nationality);
		
		currentRunner = currentRunner->nextRunner;
	}
	
	runners_freeRunnerList(runnersList);
	
	helpers_pressAnyKey();
}


/* 
 * Function:    mgrMain_updateTimes
 * Description: We want to introduce the time for each runner to complete the race
 * Arguments:   race: The race to update its times.
 * Returns:     ---
 */
void mgrMain_updateTimes(tRace * race)
{
	tRunner * currentRunner;
	tRunner * runnersList;
	tTime runnerTime;
	timeError error;
	
	runnersList = ops_loadRunnersList(race);
	currentRunner = runnersList;
	
	while (currentRunner != NULL)
	{
		helpers_clearScreen();
		printf("\nTime for %s %s (hh:mm:ss):\n", currentRunner->name, currentRunner->surname);
		helpers_scanTime(&runnerTime);
		
		error = times_checkTime(runnerTime);
		
		if (error == TIME_NOERR)
		{
			times_updateTime(race, currentRunner, runnerTime);
		}
		else
		{
			times_errMsg(error);
			helpers_pressAnyKey();
		}
		
		currentRunner = currentRunner->nextRunner;
	}
	
	runners_freeRunnerList(runnersList);
	
	helpers_pressAnyKey();
}

