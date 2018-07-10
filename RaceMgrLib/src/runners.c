 /*
  * File:        runners.c
  * Description: Contains the operations that manage the runners
  */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "runners.h"
#include "operations.h"

/*
 * Function:    runners_checkRunner
 * Description: Verifies the introduced information is valid
 * Arguments:   name: The race the user is registering to
 * 				runner: The runner information
 * Returns:     The error message
 */ 
runnerError runners_checkRunner(tRace * race, tRunner * runner)
{
	runnerError error;

	error = RUNNER_NOERR;
	
	// Is the name valid?
	error = runners_checkName(runner->name);
	if (error != RUNNER_NOERR)
	{
		return error;
	}
	
	// Is the surname valid?
	error = runners_checkName(runner->surname);
	if (error != RUNNER_NOERR)
	{
		return error;
	}

	// Is the nationality valid?
	error = runners_checkNationality(runner->nationality);
	if (error != RUNNER_NOERR)
	{
		return error;
	}

	// Is the age valid?
	error = runners_checkAge(runner->age);
	if (error != RUNNER_NOERR)
	{
		return error;
	}
	
	// Is the distance correct?
	error = runners_checkDni(runner->dni);
	if (error != RUNNER_NOERR)
	{
		return error;
	}
	
	// Is the runner already registered in the race?
	if (ops_isRunnerInRace(race, runner->dni))
	{
		return RUNNER_ALREADY_REGISTERED;
	}
	return error;
}


/*
 * Function:    runners_errMsg
 * Description: Transforms the error value enumerate into a string
 * Arguments:   The error value
 * Returns:     The string to display to the user
 */ 
char * runners_errMsg(raceError err)
{
	switch(err)
	{
		case INVALID_RUNNER_NAME:
			return "The name is invalid.\n";
			 
		case INVALID_RUNNER_NATIONALITY:
			return "Invalid nationality.\n";
			
		case INVALID_RUNNER_AGE:
			return "Invalid age.\n";
			
		case INVALID_RUNNER_DNI:
			return "Invalid DNI.\n";

		case RUNNER_ALREADY_REGISTERED:
			return "You are already registered in the race.\n";
			
		default:
			return "";
	}
}


/*
 * Function:    runners_checkName
 * Description: Verifies the name is valid
 * Arguments:   name: The runner name
 * Returns:     The error message
 */ 
runnerError runners_checkName(char * name)
{
	if (strlen(name) < 3)
	{
		// It can't be an empty name
		return INVALID_RUNNER_NAME;
	}
	
	return RUNNER_NOERR;
}

/*
 * Function:    runners_checkNationality
 * Description: Verifies the nationality is valid
 * Arguments:   nationality: The runner nationality
 * Returns:     The error message
 */ 
runnerError runners_checkNationality(char * nationality)
{
	if (strlen(nationality) < 3)
	{
		// It can't be an empty name
		return INVALID_RUNNER_NATIONALITY;
	}
	
	return RUNNER_NOERR;
}

/*
 * Function:    runners_checkAge
 * Description: Verifies the age is valid
 * Arguments:   age: The age of the runner
 * Returns:     The error message
 */ 
runnerError runners_checkAge(int age)
{
	
	if ((age < MIN_AGE) || (age > MAX_AGE))
	{
		return INVALID_RUNNER_AGE;
	}
	
	return RUNNER_NOERR;
}


/*
 * Function:    races_checkDni
 * Description: Verifies the Dni is valid
 * Arguments:   name: The runner DNI
 * Returns:     The error message
 */ 
runnerError runners_checkDni(char * dni)
{
	if ((strlen(dni) < 8) || (strlen(dni) > 9))
	{
		return INVALID_RUNNER_DNI;
	}
	
	return RUNNER_NOERR;
}

/*
 * Function:    runners_freeRunnerList
 * Description: Safely frees the memory allocated to a runners list.
 * 				Call it when you don't need the runners list anymore.
 * Arguments:   The first runner in the list
 * Returns:     ---
 */ 
void runners_freeRunnerList(tRunner * runner)
{
	tRunner * currentRunner;
	tRunner * previousRunner;
	
	currentRunner = runner;
	previousRunner = currentRunner;
	
	while (currentRunner != NULL)
	{
		currentRunner = currentRunner->nextRunner;
		free(previousRunner);
		previousRunner = currentRunner;
	}
	
	free(previousRunner);
}


