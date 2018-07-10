#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operations.h"
#include "helpers.h"
#include "races.h"
#include "runners.h"

/* 
 * Function:    ops_getVersion
 * Description: Gets the library version
 * Arguments:   ---
 * Returns:     The library version
 */
int ops_getVersion()
{
	return RACEMGR_LIB_VERSION;
}


/* 
 * Function:    ops_createRace
 * Description: Creates a new race and saves the information
 * Arguments:   race: Contains the information to create the new race
 * Returns:     The error message when creating the race.
 */
raceError ops_createRace(tRace * race)
{
	raceError err;
	
	// Create the race
	err = races_addNewRace(race);
	
	return err;
}	

/*
 * Function:    ops_saveRacesInformation
 * Description: Saves the races list into a file, so the information can be retrieved at any time
 * Arguments:   firstRace: Pointer to the first race of the list, so the can navigate through the list.
 * Returns:     ---
 */ 
void ops_saveRacesInformation(tRace * firstRace)
{
	FILE * outputFile;
	tRace * currentRace;
	
	if (strcmp(firstRace->name, "") ==0)
	{
		return;
	}
	
	outputFile = fopen(OPS_RACES_FILE, "w");
	if (outputFile == NULL)
	{
		return;
	}
	
	currentRace = firstRace;
	ops_saveRace(outputFile, currentRace);
	while (currentRace->nextRace != NULL)
	{
		currentRace = currentRace->nextRace;
		ops_saveRace(outputFile, currentRace);
	}
	
	fclose(outputFile);
}


/*
 * Function:    ops_saveRace
 * Description: Appends the current race information into a races file.
 * Arguments:   outputFile: Pointer to the file where to store the information
 *    			race: Pointer to the race to save its information.
 * Returns:     ---
 */ 
void ops_saveRace(FILE * outputFile, tRace * race)
{
	fprintf(outputFile, "%s\n", race->name);
	fprintf(outputFile, "%s\n", race->province);
	fprintf(outputFile, "%s\n", race->location);
	fprintf(outputFile, "%d\n", race->distance);
	fprintf(outputFile, "%04d/%02d/%02d %02d:%02d\n", race->dateTime.year, 
													  race->dateTime.month, 
													  race->dateTime.day, 
													  race->dateTime.hour, 
													  race->dateTime.minute);
													  
	// We put a 0 if there are no more pending races or a 1 to indicate there are more races onwards
	if (race->nextRace == NULL)
	{
		fprintf(outputFile, "0\n");
	}
	else
	{
		fprintf(outputFile, "1\n");
	}
}


/*
 * Function:    ops_loadRacesInformation
 * Description: Retrieves the information of the races previously stored on the file
 * Arguments:   firstRace: Pointer to the first race of the list.
 * Returns:     ---
 */ 
void ops_loadRacesInformation(tRace * firstRace)
{
	FILE * inputFile;
	tRace * currentRace;
	tRace * newRace;
	int pendingItems;
	
	inputFile = fopen(OPS_RACES_FILE, "r");
	if (inputFile == NULL)
	{
		return;
	}
	
	currentRace = firstRace;
	pendingItems = ops_loadRace(inputFile, currentRace);
	
	while (pendingItems > 0)
	{
		newRace = (tRace *)malloc(sizeof(tRace));
		races_initializeRaceStruct(newRace);
		currentRace->nextRace = newRace;
		currentRace = currentRace->nextRace;
	
		pendingItems = ops_loadRace(inputFile, currentRace);
	}
	
	fclose(inputFile);
}


/*
 * Function:    ops_loadRace
 * Description: Loads the information of an individual race
 * Arguments:   input: Pointer to the file where the information is stored
 *    			race: Pointer to the race to load its information.
 * Returns:     Are there more items pending to be read? A 1 indicates that yes
 * 				there are more items pending, while a 0 indicates we have already
 * 				got the end of the list.
 */ 
int ops_loadRace(FILE * inputFile, tRace * race)
{
	int retValue;
	char * auxString;
	
	auxString = helpers_scanFromFile(inputFile, MAX_NAME_LENGTH);
	strcpy(race->name, auxString);
	free(auxString);
		
	auxString = helpers_scanFromFile(inputFile, MAX_LOCATION_LENGTH);
	strcpy(race->province, auxString);
	free(auxString);
		
	auxString = helpers_scanFromFile(inputFile, MAX_LOCATION_LENGTH);
	strcpy(race->location, auxString);
	free(auxString);
		
	fscanf(inputFile, "%d\n", &race->distance);
		
	fscanf(inputFile, "%04d/%02d/%02d %02d:%02d\n", &race->dateTime.year, 
															   &race->dateTime.month, 
															   &race->dateTime.day, 
															   &race->dateTime.hour, 
															   &race->dateTime.minute);

	fscanf(inputFile, "%d\n", &retValue);
	
	return retValue;
}


/*
 * Function:    ops_saveSubscription
 * Description: Appends a new register into the users' file whenever he subscribes into a race.
 * Arguments:   race: The race the user is registering to.
 * 				runner: The runner struct with the information to save
 * Returns:     ---
 */ 
void ops_saveSubscription(tRace * race, tRunner * runner)
{
	FILE * outputFile;

	if (strcmp(race->name, "") ==0)
	{
		return;
	}
	
	outputFile = fopen(OPS_RUNNERS_FILE, "a");
	if (outputFile == NULL)
	{
		return;
	}
	
	fprintf(outputFile, "%s;%s;%s;%s;%d;%s\n", race->name,
											   runner->name,
											   runner->surname,
											   runner->nationality,
											   runner->age,
											   runner->dni);
	
	fclose(outputFile);
}


/*
 * Function:    ops_loadRunnersList
 * Description: Provides the list of runners that are currently registered to a race.
 * Arguments:   race: The race we want to retrieve the list of subscribed runners.
 * Returns:     Pointer to the first subscribed runner. The runner struct has a pointer to
 * 				next runners so the list can be followed.
 */ 
tRunner * ops_loadRunnersList(tRace * race)
{
	FILE * inputFile;
	tRunner * retValue; 
	tRunner * currentRunner;
	tRunner * parsedRunner;
	char * raceName;
	int endOfFile;
	
	raceName = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
	
	retValue = NULL;
	currentRunner = NULL;
	endOfFile = 1;
	
	inputFile = fopen(OPS_RUNNERS_FILE, "r");
	if (inputFile == NULL)
	{
		return NULL;
	}
	
	// For every register in the file, check if it matches with the race.
	// If so, append it to the list. Discard it otherwise.
	while (endOfFile != EOF)
	{
		parsedRunner = (tRunner *)malloc(sizeof(tRunner));
		parsedRunner->nextRunner = NULL;
		memset(raceName, 0, MAX_NAME_LENGTH);
		memset(parsedRunner->name, 0, MAX_NAME_LENGTH);
		memset(parsedRunner->surname, 0, MAX_NAME_LENGTH);
		memset(parsedRunner->nationality, 0, MAX_LOCATION_LENGTH);
		memset(parsedRunner->dni, 0, MAX_DNI_LENGTH);
		
		endOfFile = fscanf(inputFile, "%[^;];%[^;];%[^;];%[^;];%d;%s\n", raceName,
																	     parsedRunner->name,
																	     parsedRunner->surname,
																	     parsedRunner->nationality,
																	     &parsedRunner->age,
																	     parsedRunner->dni);
															 
		if (strcmp(raceName, race->name) == 0)
		{
			// This is the race we are looking for, append the runner to the list
			if (retValue == NULL)
			{
				retValue = parsedRunner;
				currentRunner = parsedRunner;
			}
			else
			{
				currentRunner->nextRunner = parsedRunner;
				currentRunner = currentRunner->nextRunner;
			}
		}
		else
		{
			// This runner is not subscribed to the race we are looking for, so discard it.
			free(parsedRunner);
		}
	}

	
	fclose(inputFile);
	
	return retValue;
}


/*
 * Function:    ops_isRunnerInRace
 * Description: Checks if a runner is already registered to a race.
 * Arguments:   race: The race we want to check.
 * 				dni: The runner identifier to search.
 * Returns:     1 indicates that the runner is in the list of subscribed runners of the race.
 * 				0 indicates it is not subscribed yet.
 */ 
int ops_isRunnerInRace(tRace * race, char * dni)
{
	tRunner * currentRunner;
	tRunner * runnersList;
	
	runnersList = ops_loadRunnersList(race);
	currentRunner = runnersList;
	
	while (currentRunner != NULL)
	{
		if (strcmp(currentRunner->dni, dni) == 0)
		{
			// We found it. Return 1
			runners_freeRunnerList(runnersList);
			return 1;
		}
		currentRunner = currentRunner->nextRunner;
	}
	
	runners_freeRunnerList(runnersList);
	return 0;
}



/*
 * Function:    ops_loadTimesList
 * Description: Provides the list of runners that has ran a race with their time
 * Arguments:   race: The race we want to retrieve the list of runners with their times.
 * Returns:     Pointer to the first runner struct. The runner struct has a pointer to
 * 				next runners so the list can be followed.
 */ 
tRunner * ops_loadTimesList(tRace * race)
{
	tRunner * retValue;
	
	///
	/// EX.4.1: Implement the function that loads the runners registered in a race and gets its time.
	///
    
    retValue = ops_loadRunnersList(race);
    tRunner *auxRunner = retValue;
    
    while (auxRunner != NULL)
    {
        // Load runner time
        ops_getRunnerTime(race, auxRunner);
        
        // Next node
        auxRunner = auxRunner->nextRunner;
    }

	/// END OF EXERCISE 4.1
	
	return retValue;
}


/*
 * Function:    ops_getRunnerTime
 * Description: Fills the time information into a runner struct.
 * Arguments:   race: The race the runner has ran.
 * 				runner: The runner that has ran the race.
 * Returns:     ---
 */ 
void ops_getRunnerTime(tRace * race, tRunner * runner)
{
	FILE * inputFile;
	char * raceName;
	char * dni;
	tTime timeRunner;
	int endOfFile;
	
	raceName = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
	dni = (char *)malloc(MAX_DNI_LENGTH * sizeof(char));
	
	endOfFile = 1;
	
	inputFile = fopen(OPS_TIMES_FILE, "r");
	if (inputFile == NULL)
	{
		return;
	}
	
	runner->timeRunner.hours = 0;
	runner->timeRunner.minutes = 0;
	runner->timeRunner.seconds = 0;
	
	// For every register in the file, check if it matches with the race and runner.
	// If so, fill the time information.
	while (endOfFile != EOF)
	{
		endOfFile = fscanf(inputFile, "%[^;];%[^;];%d;%d;%d\n", raceName,
															    dni,
																&timeRunner.hours, 
																&timeRunner.minutes,
																&timeRunner.seconds);
																	     
		if ((strcmp(raceName, race->name) == 0) &&
			(strcmp(dni, runner->dni) == 0))
		{
			// This is the race and runner we are looking for
			runner->timeRunner.hours = timeRunner.hours;
			runner->timeRunner.minutes = timeRunner.minutes;
			runner->timeRunner.seconds = timeRunner.seconds;
		}
	}

	fclose(inputFile);
}

/*
 * Function:    ops_sortListByTime
 * Description: Sorts the runners list by registered time. The runner that has ran the race in less time is first.
 * Arguments:   runnersList: The original unsorted list.
 * Returns:     Pointer to the fastest runner. The runner struct has a pointer to
 * 				next runners so the list can be followed.
 */ 
tRunner * ops_sortListByTime(tRunner * runnersList)
{
	tRunner * retValue;
	
	///
	/// EX.4.2: Implement the function that sorts the runners from minimum time to maximum.
	///

    // Return the time in seconds
    int getTotalSeconds(tTime t)
    {
        return ((t.hours * 60 * 60) + (t.minutes * 60) + t.seconds);
    }

    //------- Selection algorithm ---------
    
    tRunner *swap = (tRunner*)malloc(sizeof(tRunner));
    tRunner *minimo = NULL;
    tRunner *auxRunner1 = runnersList;

    while (auxRunner1 != NULL)
    {
        minimo = auxRunner1;
        tRunner *auxRunner2 = auxRunner1->nextRunner;

        while (auxRunner2 != NULL)
        {
            if (getTotalSeconds(minimo->timeRunner) == 0)
                minimo = auxRunner2;
            else
            {
                if (getTotalSeconds(minimo->timeRunner)  > getTotalSeconds(auxRunner2->timeRunner) && getTotalSeconds(auxRunner2->timeRunner) != 0)
                   minimo = auxRunner2;

            }

            auxRunner2 = auxRunner2->nextRunner;
        }
        
        if (auxRunner1 != minimo)
        {
            // Exchange node addresses
            tRunner *aux = minimo->nextRunner;
            minimo->nextRunner = auxRunner1->nextRunner;
            auxRunner1->nextRunner = aux;
            
            // Data exchange memory nodes
            memcpy(swap, minimo, sizeof(tRunner));
            memcpy(minimo, auxRunner1, sizeof(tRunner));
            memcpy(auxRunner1, swap, sizeof(tRunner));
        }

        auxRunner1 = auxRunner1->nextRunner;
    }
    

    free(swap);
    retValue = runnersList;

	/// END OF EXERCISE 4.2
	
	return retValue;
}
