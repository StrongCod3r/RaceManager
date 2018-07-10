/*
 * File:        vwrMain.c
 * Description: Contains the functionality for the viewer application
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vwrMain.h"
#include "vwrMenu.h"
#include "races.h"
#include "helpers.h"
#include "runners.h"

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
	vwrMain_displayMenu();
	return 0;
}

#endif


/* 
 * Function:    vwrMain_displayMenu
 * Description: Displays the Race Viewer main menu
 * Arguments:   ---
 * Returns:     ---
 */
void vwrMain_displayMenu()
{
	char option;
	int index;
	tRace * race;

	option = vwrMenu_mainMenu();
	
	while (option != '0')
	{
		switch(option)
		{
			case '1':   // List all races
				vwrMain_listRaces();
				break;
				
			case '2':   // Display the list of races a user has registered to.
				index = vwrMenu_filterRaces();
				if (index > 0)
				{
					// If the user wants to know extended information of the race, display it.
					race = races_getRace(index - 1);
					vwrMenu_raceInformation(race);
					helpers_pressAnyKey();
				}
				break;
				
			default:
				break;
		}
		option = vwrMenu_mainMenu();
	}
}


/* 
 * Function:    vwrMain_listRaces
 * Description: Display all the registered races
 * Arguments:   ---
 * Returns:     ---
 */
void vwrMain_listRaces()
{
	int option;
	tRace * race;
	
	option = vwrMenu_listAll();
	
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
			vwrMain_showInfo(race);
		}
		option = vwrMenu_listAll();
	}
}


/* 
 * Function:    vwrMain_showInfo
 * Description: Display extended information of the race.
 * Arguments:   race: The race to display extended information
 * Returns:     ---
 */
void vwrMain_showInfo(tRace * race)
{
	char option;
	
	option = vwrMenu_information(race);
	while (option != '0')
	{
		switch (option)
		{
			case '1': // The user wants to subscribe to that race.
				vwrMain_subscribe(race);
				break;
				
			case '2': // The user wants to list the runners that have previously registered to that race.
				vwrMain_listRunners(race);
				break;
				
			case '3': // The user wants to see the times registered by the users.
				vwrMain_listTimes(race);
				break;
		}
		
		option = vwrMenu_information(race);
	}
}


/* 
 * Function:    vwrMain_subscribe
 * Description: Subscribe to the race
 * Arguments:   race: The race the user wants to subscribe
 * Returns:     ---
 */
void vwrMain_subscribe(tRace * race)
{
	tRunner * runner;
	runnerError err;
	
	runner = vwrMenu_subscribe();
	err = runners_checkRunner(race, runner);
	
	if (err == RUNNER_NOERR)
	{
	   helpers_clearScreen();
	   ops_saveSubscription(race, runner);
	   printf("\n\nThanks %s. You have been subscribed to the %s\n\n", runner->name, race->name);
	}
	else
	{
		// Some error ocurred. Display the error.
		printf("\n\n%s\n", runners_errMsg(err));
	}
				
	free(runner);
	helpers_pressAnyKey();
}

/* 
 * Function:    vwrMain_listRunners
 * Description: Display the list of runners that are already registered in the race.
 * Arguments:   race: The race to list the runners that already registered.
 * Returns:     ---
 */
void vwrMain_listRunners(tRace * race)
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
 * Function:    vwrMain_listTimes
 * Description: Display the times sorted from minimum to maximum for every runner that has ran the race.
 * Arguments:   race: The race to list the times.
 * Returns:     ---
 */
void vwrMain_listTimes(tRace * race)
{
	tRunner * currentRunner;
	tRunner * sortedList;
	tRunner * runnersList;
	int i;
	
	runnersList = ops_loadTimesList(race);
	sortedList = ops_sortListByTime(runnersList);
	currentRunner = sortedList;
	
	helpers_clearScreen();
	printf ("\nTimes for runners at %s\n\n", race->name);
	
	i = 1;
	while (currentRunner != NULL)
	{
		printf("%03d - %02d:%02d:%02d - %s %s (%s)\n", i, 
													   currentRunner->timeRunner.hours,
													   currentRunner->timeRunner.minutes,
													   currentRunner->timeRunner.seconds,
													   currentRunner->name, 
													   currentRunner->surname, 
													   currentRunner->nationality);
		
		currentRunner = currentRunner->nextRunner;
		i++;
	}
	
	runners_freeRunnerList(sortedList);
	
	helpers_pressAnyKey();
}
