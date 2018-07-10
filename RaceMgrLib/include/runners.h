#ifndef _RUNNERS_H_
#define _RUNNERS_H_

#define MAX_DNI_LENGTH 10
#define MIN_AGE 18
#define MAX_AGE 99

#include "races.h"

typedef enum
{
	RUNNER_NOERR,
	RUNNER_ALREADY_REGISTERED,
	INVALID_RUNNER_NAME,
	INVALID_RUNNER_NATIONALITY,
	INVALID_RUNNER_AGE,
	INVALID_RUNNER_DNI
} runnerError;

typedef struct sTime
{
	int hours;
	int minutes;
	int seconds;
} tTime;


typedef struct sRunner
{
	char name[MAX_NAME_LENGTH];
	char surname[MAX_NAME_LENGTH];
	char nationality[MAX_LOCATION_LENGTH];
	int age;
	char dni[MAX_DNI_LENGTH];
	struct sTime timeRunner;
	struct sRunner * nextRunner;
} tRunner;


runnerError runners_checkRunner(tRace * race, tRunner * runner);

char * runners_errMsg(raceError err);

runnerError runners_checkName(char * name);

runnerError runners_checkNationality(char * nationality);

runnerError runners_checkAge(int age);

runnerError runners_checkDni(char * dni);

void runners_freeRunnerList(tRunner * runner);

#endif