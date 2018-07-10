/*
 * File:        races.c
 * Description: Contains the operations that manage the races
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "races.h" 


/*
 * Function: 	races_getLastRace
 * Description: Gets the latest stored race.
 * Arguments:   ---
 * Returns: 	The pointer to the latest stored race
 */
tRace * races_getLastRace()
{
	tRace * retValue = races_firstRace;
	
	while (retValue->nextRace != NULL)
	{
		retValue = retValue->nextRace;
	}
	return retValue;
}


/*
 * Function: 	races_getRace
 * Description: Gets the race given its index in the list
 * Arguments:   index: The position where the race is stored in the list
 * Returns: 	The pointer to the race in that position
 */
tRace * races_getRace(int index)
{
	tRace * retValue = races_firstRace;
	int i = 0;
	
	while (i < index) 
	{
		if (retValue->nextRace == NULL)
		{
			return NULL;
		}
		retValue = retValue->nextRace;
		i++;
	}
	return retValue;
}


/*
 * Function:    races_initializeRaceStruct
 * Description: Contains common functionality when initializing a new race struct
 * Arguments:   ---
 * Returns:     The race struct ready to be filled
 */
void races_initializeRaceStruct(tRace * race)
{
	memset(race->name, 0, MAX_NAME_LENGTH);
	memset(race->province, 0, MAX_LOCATION_LENGTH);
	memset(race->location, 0, MAX_LOCATION_LENGTH);
	race->distance = 0;
	race->dateTime.year = 0;
	race->dateTime.month = 0;
	race->dateTime.day = 0;
	race->dateTime.hour = 0;
	race->dateTime.minute = 0;
	race->nextRace = NULL;
}

/*
 * Function:    races_addNewRace
 * Description: Creates a new race into the database
 * Arguments:   race: Contains the information with the new race to create
 * Returns:     The error message
 */
raceError races_addNewRace(tRace * race)
{
	raceError error;

	error = RACE_NOERR;
	
	// Is the name valid?
	error = races_checkName(race->name);
	if (error != RACE_NOERR)
	{
		return error;
	}

	// Is the province valid?
	error = races_checkProvince(race->province);
	if (error != RACE_NOERR)
	{
		return error;
	}

	// Is the location valid?
	error = races_checkLocation(race->location);
	if (error != RACE_NOERR)
	{
		return error;
	}
	
	// Is the distance correct?
	error = races_checkDistance(race->distance);
	if (error != RACE_NOERR)
	{
		return error;
	}
	
	// Is the date and time correct?
	error = races_checkDateTime(race->dateTime);
	if (error != RACE_NOERR)
	{
		return error;
	}
	
	// Everything is correct, append it.
	if (!strcmp(races_firstRace->name, ""))
	{
		free(races_firstRace);
	    races_firstRace = race;
	}
	else
	{
		races_getLastRace()->nextRace = race;
	}
	
	return error;
}




/*
 * Function:    races_errMsg
 * Description: Transforms the error value enumerate into a string
 * Arguments:   The error value
 * Returns:     The string to display to the user
 */ 
char * races_errMsg(raceError err)
{
	switch(err)
	{
		case RACE_NOERR: 
			return "Race correctly registered!\n";
			
		case RACE_ALREADY_EXISTS:
			return "Race name already exists in the database.\n";
			 
		case INVALID_PROVINCE:
			return "Invalid province.\n";
			
		case INVALID_LOCATION:
			return "Invalid location.\n";
			
		case INVALID_DISTANCE:
			return "Invalid distance.\n";
			
		case INVALID_NAME:
			return "Invalid race name.\n";
			
		case INVALID_DATETIME:
			return "Invalid date and time.\n";
			
		default:
			return "";
	}
}



/*
 * Function:    races_checkName
 * Description: Verifies the name is valid
 * Arguments:   name: The race name
 * Returns:     The error message
 */ 
raceError races_checkName(char * name)
{
	tRace * currentRace;
	
	currentRace = races_firstRace;
	
	if (strlen(name) < 3)
	{
		// It can't be an empty name
		return INVALID_NAME;
	}
	
	if (!strcmp(name, currentRace->name))
	{
		return RACE_ALREADY_EXISTS;
	}
	
	while (currentRace->nextRace != NULL)
	{
		currentRace = currentRace->nextRace;
		if (!strcmp(name, currentRace->name))
		{
			return RACE_ALREADY_EXISTS;
		}
	}
	
	return RACE_NOERR;
}


/*
 * Function:    races_checkProvince
 * Description: Verifies the province is valid
 * Arguments:   province: The province value
 * Returns:     The error message
 */ 
raceError races_checkProvince(char * province)
{
	char races_validProvinces[NUM_OF_PROVINCES][MAX_LOCATION_LENGTH] = {"Barcelona", "Tarragona", "Lleida", "Girona"};
	
	int i;
	for(i = 0; i < NUM_OF_PROVINCES; i++)
	{
		if (!strcmp(races_validProvinces[i], province))
		{
			return RACE_NOERR;
		}
	}
	
	return INVALID_PROVINCE;
}


/*
 * Function:    races_checkLocation
 * Description: Verifies the location is valid
 * Arguments:   location: The location value
 * Returns:     The error message
 */ 
raceError races_checkLocation(char * location)
{
	if (strlen(location) < 3)
	{
		// It can't be an empty location
		return INVALID_LOCATION;
	}
	
	return RACE_NOERR;
}


/*
 * Function:    races_checkDistance
 * Description: Verifies the distance is valid
 * Arguments:   distance: The distance value
 * Returns:     The error message
 */ 
raceError races_checkDistance(int distance)
{
	if ((distance < MIN_RACE_DISTANCE) || (distance > MAX_RACE_DISTANCE))
	{
		// Distance out of the boundary limits
		return INVALID_DISTANCE;
	}
	
	return RACE_NOERR;
}


/*
 * Function:    races_checkDateTime
 * Description: Verifies the dateTime is valid
 * Arguments:   dateTime: The dateTime value
 * Returns:     The error message
 */ 
raceError races_checkDateTime(tDateTime dateTime)
{
	int days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if ((dateTime.year < MIN_RACE_YEAR) || (dateTime.year > MAX_RACE_YEAR) ||
		(dateTime.month < 1) || (dateTime.month > 12) ||
		(dateTime.day < 1) || (dateTime.day > days[dateTime.month - 1]) ||
		(dateTime.hour < 0) || (dateTime.hour > 23) ||
		(dateTime.minute < 0) || (dateTime.minute > 59))
	{
		// Distance out of the boundary limits
		return INVALID_DATETIME;
	}
	
	
	return RACE_NOERR;
}



