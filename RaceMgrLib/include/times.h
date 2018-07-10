#ifndef _TIMES_H_
#define _TIMES_H_

#include "races.h"
#include "runners.h"

typedef enum
{
	TIME_NOERR,
	INVALID_TIME
} timeError;



// Updates the time for a runner and a race
void times_updateTime(tRace * race, tRunner * runner, tTime timeRunner);

// Checks the introduced time is OK.
timeError times_checkTime(tTime runnerTime);

// Transforms the error value enumerate into a string
char * times_errMsg(timeError err);

#endif