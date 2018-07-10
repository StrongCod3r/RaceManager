/*
 * File:        times.c
 * Description: Contains the operations that manage the times of the runners in the races.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "times.h" 
#include "operations.h"



/*
 * Function:    times_updateTime
 * Description: Appends a new register into the times' file whenever a new time is introduced for a runner and a race.
 * Arguments:   race: The race the user has ran.
 * 				runner: The runner that has ran the race
 * 				time: The time it has taken to the runner to finish the race.
 * Returns:     ---
 */ 
void times_updateTime(tRace * race, tRunner * runner, tTime runnerTime)
{
	///
	/// EX.2: Implement the method that registers a time for a runner and a race.
	///
	
    FILE *fTime = fopen(OPS_TIMES_FILE, "a");

    if (fTime != NULL)
    {
        // Save the information of the runner
        fprintf(fTime, "%s;", race->name);
        fprintf(fTime, "%s;", runner->dni);
        fprintf(fTime, "%d;%d;%d\n", runnerTime.hours, runnerTime.minutes, runnerTime.seconds);
        
        // Close file
        fclose (fTime);
    }
    
    
	/// END OF EXERCISE 2
}

/*
 * Function:    times_checkTime
 * Description: Checks the introduced time is OK.
 * Arguments:   time: The time it has taken to the runner to finish the race.
 * Returns:     The suitable error code
 */ 
timeError times_checkTime(tTime runnerTime)
{
	timeError retValue;
	
	retValue = TIME_NOERR;
	
	///
	/// EX.3: Validate the introduced time is valid.
	/// 
	
    retValue = INVALID_TIME;
    
    if (runnerTime.hours >= 0 && runnerTime.hours <= 23)
    {
        if(runnerTime.minutes >= 0 && runnerTime.minutes <= 59)
        {
            if(runnerTime.seconds >= 0 && runnerTime.seconds <= 59)
            {
                retValue = TIME_NOERR;
            }
        }
    }
	
	/// END OF EXERCISE 3
	
	return retValue;
}


/*
 * Function:    times_errMsg
 * Description: Transforms the error value enumerate into a string
 * Arguments:   The error value
 * Returns:     The string to display to the user
 */ 
char * times_errMsg(timeError err)
{
	switch(err)
	{
		case TIME_NOERR: 
			return "Time OK!\n";
		
		case INVALID_TIME:
			return "Invalid time.\n";
			
		default:
			return "";
	}
}
